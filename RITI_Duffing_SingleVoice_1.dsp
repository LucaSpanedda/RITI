import("stdfaust.lib");

// Frequencies List
freqsList = (97, 156, 186, 200, 243, 318, 333, 383, 435, 453, 495, 500, 598, 678, 687, 702, 720, 883, 1522, 1747, 1859, 1957, 1965, 2065); 

// Robert Bristow-Johnson's Biquad Filter - Direct Form 1
bandpassBiquad(f, q, g) = biquadFilter : _ * g
    with{
        biquadFilter = _ <: _, (mem  <: (_, mem)) : (_ * a0, _ * a1, _ * a2) :> _ : 
                            ((_, _) :> _) ~ (_ <: (_, mem) : (_ * -b1, _ * -b2) :> _);
        F = max(ma.EPSILON, min(20000,  f));
        Q = max(ma.EPSILON, min(ma.MAX, q));
        K = tan(ma.PI * F / ma.SR);
        norm = 1 / (1 + K / Q + K * K);
        a0 = K / Q * norm;
        a1 = 0;
        a2 = -a0;
        b1 = 2 * (K * K - 1) * norm;
        b2 = (1 - K / Q + K * K) * norm;
    };

// BP filter bank
BPBank(bands, globalG, globalBW, globalF, x) = par(i, bands, bandpassBiquad(ba.take(1 + i, freqsList) * globalF, globalBW, globalG)) :> _;

// Filtered part of the signal - out from the filter - feedback with saturator(filtered + direct)
filtered = _ <: (BPBank(24, 1, bandwidth, freqshift) <: si.bus(2)), _ : (_, ro.cross(2)) : atan(_ + _), _ * gain
    with{
        bw0 = vslider("bandwidth", 0.25, 0, 1, 0.001);
        bandwidth =  (bw0 * bw0 * 200.0 + 0.1) : si.smoo;
        freqshift = 4 ^ vslider("frequency", 0, -1, 1, 0.001) : si.smoo;
        gain = 100 ^ vslider("feedback", 0, -1, 1, 0.001) : si.smoo;
    };

duffing(agents, x) = (yn : (_, agents)) ~ si.bus(2) : (si.block(2), _)
    with{
        c0 = max(.0001, min(1,  1 - vslider("damping", 0.6, 0, 1, .001) + (x + 1) * 0.5));
        c = (c0 * c0 * c0 + 0.00001) : si.smoo;
        gamma = 1 - vslider("mod", 0, 0, 1, .001) : si.smoo;
        omega =  vslider("rate", 400, 1, 1000, .0001) : si.smoo;
        dt = 0.000005 * omega : + ~ _; // omega shifted from sin(dt * omega)
        yn(y, x) = (x - (x * x * x))' - (c * y) + gamma * sin(dt) <: si.bus(2);
    };
process = hgroup("voice_0", duffing(filtered) : co.compressor_mono(12, -12, .001, .1) <: si.bus(2));
//process = par(i, 2, hgroup("voice_%i", duffing(filtered) : co.compressor_mono(12, -12, .001, .1))) ~ (ro.cross(2) : par(i, 2, _@2000));
