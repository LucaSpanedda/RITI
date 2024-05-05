import("stdfaust.lib");

filtersN = 24;

// Frequencies List
freqsList = (97, 156, 186, 200, 243, 318, 333, 383, 435, 453, 495, 500, 598, 678, 687, 702, 720, 883, 1522, 1747, 1859, 1957, 1965, 2065); 

// Robert Bristow-Johnson's Biquad Filter - Direct Form 1
bandpassBiquad(f, q, g) = biquadFilter
    with{
        biquadFilter = _ * g <: _, (mem  <: (_, mem)) : (_ * a0, _ * a1, _ * a2) :> _ : 
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
bandpassFiltersBank(bands, globalG, globalBW, globalF, x) = par(i, bands, bandpassBiquad(ba.take(1 + i, freqsList) * globalF, globalBW, globalG, x)) :> _ / bands;

// Controls
controls = si.smoo(vslider("bandwidth", 54, 1,100, 0.0001)), 8 ^ si.smoo(vslider("frequency", 0, -1, 1, 0.0001)), si.smoo(vslider("smooth", 1, 0, 1, 0.0001)), si.smoo(vslider("gain", 82, 0, 200, 0.0001)), si.smoo(vslider("damping", 0.3, 0, 1, 0.0001)), si.smoo(vslider("mod", 4, 0, 10, 0.0001)), si.smoo(vslider("rate", 108, 5, 200, 0.0001)), _;

// Osc Voice
duffing(bandwidth, freqshift, smooth, gain, damping, mod, rate, ext) = out
with{
// Duffing Equation
osc(duffY, duffX) = dy, duffX0, finalY
    with{
        finalY = bandpassFiltersBank(filtersN, gain, bandwidth, freqshift, duffX);
        dt = (rate / ma.SR : + ~ _ % (60 * rate));
        dy = (finalY - (finalY * finalY * finalY)) - (damping * duffY) + mod * sin(dt);
        duffX0 = atan(duffY + dy);
    };
out = (osc ~ si.bus(2) : (!, !, _ * 0.5));
};

process = hgroup("voice_0", controls : duffing);
