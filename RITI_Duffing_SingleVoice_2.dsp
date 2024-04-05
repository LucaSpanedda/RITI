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

// GUI
gui = si.smoo(vslider("bandwidth", 30, 1, 50, 0.0001)), si.smoo(vslider("frequency", 0, -1, 1, 0.0001)), si.smoo(vslider("smooth", 1, 0, 1, 0.0001)), si.smoo(vslider("gain", 1, 0, 1, 0.0001)), si.smoo(vslider("damping", 0.3, 0, 1, .001)), si.smoo(vslider("mod", 0, 0, 1, .001)), si.smoo(vslider("rate", 200, 0, 400, 1)), _;

// Duffing Equation
duffing(bandwidth, freqshift, smooth, gain, damping, mod, rate, x) = (yn : (_, filtered)) ~ si.bus(2)
    with{
        filtered = _ * gain <: (BPBank(24, 1, bandwidth, 16 ^ freqshift) <: si.bus(2)), _ : (_, ro.cross(2)) : (atan(_ * 1.0 + _ * 1.0) : fi.lowpass(2, smooth * 9999 + 1, _)), _;
        c0 = max(.0001, min(1,  1 - damping));
        c = (c0 * c0 * c0 + 0.00001) : si.smoo;
        gamma = 1 - mod;
        omega =  rate * 0.00001;
        dt = 0.00001 + abs(no.noise) * 0.00002 + omega: + ~ _;
        yn(y, x) = (x - (x * x * x))' - (c * y) + gamma * sin(dt) <: si.bus(2);
    };
duffingout = duffing : (!, !, _ * .75);
process = hgroup("voice_0", gui : duffingout);
