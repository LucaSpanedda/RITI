//---------------------------`ROOM IS THE INSTRUMENT`--------------------------
import("stdfaust.lib");

// network values
InputsN = 2;
OutputsN = 2;
InitSeed = 1242569812;
FiltersN = 24;
// constants values
PI = ma.PI;
TWOPI = 2.0 * PI;
SR = ma.SR;
EPS = ma.EPSILON;
NY = SR / 2.0;
T = 1.0 / SR;
PIT = PI * T;
TWOPIT = TWOPI * T;
MS2T(t) = (t / 1000) * ma.SR;

// Mapping Functions
info(i, lower, upper) = _ <: _, vbargraph(" %i [style:numerical]", lower, upper) : attach;
mapping(low, high, x) = x * (high - low) + low;
uni2bi(x) = x * 2.0 - 1.0;
bi2uni(x) = x * 0.5 + 0.5;
controlMap(low, high, offset, x) = info(0, low, high, mapping(low, high, bi2uni(ma.tanh(x + offset))));
controlMapexp(exponent, offset, x) = info(0, -exponent, exponent, exponent ^ (ma.tanh(x + offset)));

// Mixer
mixerVoice(v) = hgroup("Channels", hgroup("CH%v", vol : vumeter))
    with{
        vol		= * (vslider("dBg", -40, -80, 20, 0.1) : ba.db2linear : si.smoo);
        vumeter(x) 	= attach(x, envelop(x) : vbargraph("dBv", 0, 1))
		    with { envelop = abs : min(0.99) : max ~ -(1.0 / SR);};
    };
Mixer(N) = par(i, N, mixerVoice(i + 1));

// Reverb (Keith Barr Allpass Loop)
reverb(I, O, N, SEQ, parspace, start, KRT) = si.bus(I) <: 
(InputStage : 
    (ro.interleave(N, N/(N/2)) : par(i, N, si.bus(2) :> _) : 
        par(i, N, 
        seq(k, SEQ, 
            // cleanfunc
            ModAPF
                ( 
                    (primenumbers((k + start) + (i * parspace)) : MS2T), 
                    (primenumbers((k + start) + (i * parspace)) / 100 : MS2T), 
                    (0.5 / primenumbers((k + start) + (i * parspace)) : MS2T)
                ) 
        ) :
        _ * KRT
    )   : ro.crossNM(N - 1, 1)) ~ 
    si.bus(N) :> 
OutputStage), OutGain :> par(i, O, LookaheadLimiter)
with{
    // In / Out - Network
    InputStage = par(i, N, _);
    OutputStage = par(i, O, _);
    OutGain = par(i, O, _ * (1 - KRT));
    // conversion : milliseconds T to samples
    MS2T(t) = (t / 1000) * SR;
    // index of the primes numbers
    primenumbers(index) = ba.take(index , list)
    with{
        list = 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557;
    };
    // DC Blocker Filter
    dcblocker(zero, pole, x) = x : dcblockerout
    with{
        onezero =  _ <: _,mem : _, * (zero) : -;
        onepole = + ~ * (pole);
        dcblockerout = _ : onezero : onepole;
    };
    // function for test prime numbers
    cleanfunc(x, y, z) = _ * (x + y + z) ;
    // AP Coefficents
    COEFF = .65;
    // Modulated Allpass filter
    ModAPF(delsamples, samplesmod, freqmod) = ( + : _ <: 
        delayMod(delsamples, samplesmod, freqmod),
        * (COEFF))~ * (-COEFF) : mem, _ : + : _
        with{
            delayMod(samples, samplesMod, freqMod, x) = delay
            with{
                modulation(f, samples) = ((os.osc(f) + 1) / 2) * samples;
                delay = x : de.fdelay(samples, 
                                samples - modulation(freqMod, samplesMod));
            };
        };
};

peakenvelope(period, x) = loop ~ _
    with {
        loop(y) = max(abs(x), y * coeff);
        twoPIforT = (2.0 * PI) * (1.0 / SR);
        coeff = exp(-twoPIforT / max(EPS, period));
    };

peakEnvAttRel(att, rel, x) = peakenvelope(rel - att, x) : 
    LPTPT(1.0 / max(EPS, att));

onePoleTPT(cf, x) = loop ~ _ : ! , si.bus(3)
    with {
        g = tan(cf * PI * ma.T);
        G = g / (1.0 + g);
        loop(s) = u , lp , hp , ap
            with {
            v = (x - s) * G; u = v + lp; lp = v + s; hp = x - lp; ap = lp - hp;
            };
    };
// Lowpass  TPT
LPTPT(cf, x) = onePoleTPT(cf, x) : (_ , ! , !);
// Highpass TPT
HPTPT(cf, x) = onePoleTPT(cf, x) : (! , _ , !);
// Allpass TPT
APTPT(cf, x) = onePoleTPT(cf, x) : (!, !, _);

// Robert Bristow-Johnson's Biquad Filter - Direct Form 1
bandpassBiquad(f, q, g) = biquadFilter
    with{
        biquadFilter = _ * g <: _, (mem  <: (_, mem)) : (_ * a0, _ * a1, _ * a2) :> _ : 
                            ((_, _) :> _) ~ (_ <: (_, mem) : (_ * -b1, _ * -b2) :> _);
        F = max(EPS, min(20000,  f));
        Q = max(EPS, min(ma.MAX, q));
        K = tan(PI * F / SR);
        norm = 1 / (1 + K / Q + K * K);
        a0 = K / Q * norm;
        a1 = 0;
        a2 = -a0;
        b1 = 2 * (K * K - 1) * norm;
        b2 = (1 - K / Q + K * K) * norm;
    };

bandpassFiltersBank(k, bands, globalG, globalBW, globalF, x) = par(i, bands, bandpassBiquad(ba.take(1 + i, fList(k)) * globalF, globalBW, globalG, x)) :> _ / bands
with{
    fList(1) = (65.0, 131.0, 196.0, 261.0, 326.0, 392.0, 457.0, 522.0, 588.0, 653.0, 718.0, 784.0, 849.0, 914.0, 979.0, 1045.0, 1110.0, 1175.0, 1241.0, 1306.0, 1371.0, 1502.0, 1567.0, 1632.0, 1698.0, 1763.0, 1828.0, 1894.0, 1959.0, 2024.0, 2089.0, 2351.0); 
    fList(2) = (97.0, 190.0, 294.0, 370.0, 490.0, 545.0, 588.0, 686.0, 785.0, 882.0, 982.0, 1079.0, 1178.0, 1275.0, 1373.0, 1471.0, 1568.0, 1671.0, 1766.0, 1863.0, 1961.0, 2059.0, 2135.0, 2255.0, 2353.0, 2549.0, 2651.0, 2747.0, 2843.0, 3235.0, 3334.0, 6664.0);
    fList(3) = (62.0, 128.0, 192.0, 253.0, 327.0, 383.0, 465.0, 575.0, 653.0, 731.0, 808.0, 879.0, 980.0, 1051.0, 1106.0, 1253.0, 1307.0, 1406.0, 1472.0, 1568.0, 1633.0, 1740.0, 1860.0, 1960.0, 2027.0, 2096.0, 2287.0, 2613.0, 2940.0, 3267.0, 3593.0, 3922.0);
    fList(4) = (50.0, 130.0, 220.0, 309.0, 368.0, 439.0, 538.0, 659.0, 879.0, 1099.0, 1319.0, 1539.0, 1759.0, 1978.0, 2198.0, 2418.0, 2638.0, 2858.0, 3078.0, 3298.0, 3517.0, 3737.0, 3957.0, 4177.0, 4617.0, 5056.0, 5496.0, 5717.0, 7035.0, 7255.0, 8574.0, 9672.0); 
};
//process = no.noise : bandpassFiltersBank(1, FiltersN, 1, 400, 1) * 40;

/* Peak-holders. */
peakHolder(t, x) = loop ~ si.bus(2) : ! , _
    with {
        loop(timerState, outState) = timer , output
            with {
                isNewPeak = abs(x) >= outState;
                isTimeOut = timerState >= rint(t * SR);
                bypass = isNewPeak | isTimeOut;
                timer = (1.0 - bypass) * (timerState + 1);
                output = bypass * (abs(x) - outState) + outState;
            };
    };
peakHoldCascade(N, holdTime, x) = x : seq(i, N, peakHolder(holdTime / N));

/* Cascaded one-pole smoothers with attack and release times. */
smoother(N, att, rel, x) = loop ~ _
    with {
        loop(fb) = coeff * fb + (1.0 - coeff) * x
            with {
                cutoffCorrection = 1.0 / sqrt(pow(2.0, 1.0 / N) - 1.0);
                coeff = ba.if(x > fb, attCoeff, relCoeff);
                TWOPITC = TWOPIT * cutoffCorrection;
                attCoeff = exp(-TWOPITC / att);
                relCoeff = exp(-TWOPITC / rel);
            };
    };
smootherCascade(N, att, rel, x) = x : seq(i, N, smoother(N, att, rel));

/* Look-ahead limiter. */
gainAttenuation(th, att, hold, rel, x) =
    th / (max(th, peakHoldCascade(8, att + hold, x)) :
        smootherCascade(4, att, rel));

LookaheadLimiter(x_) = xDelayed * gainAttenuation(1.0, .01, .1, .1, abs(x_))
    with {
        delay = rint((.01 / 8) * SR) * 8;
        xDelayed = x_ @ delay;
    };
LookaheadNormalizer(threshold, holdSec, decaySec) = _ <: 1 / max(ma.MIN, (_ : peakHolder(holdSec) : LPTPT(1 / holdSec) : peakenvelope(decaySec))) * _ @ (holdSec * SR); 

seqN(N, OP) = _ <: seq(i, N, (OP <: _, _), si.bus(i + 1)) : (_, !, si.bus(N - 1), !);

noise(N, initSeed) = ((_ + (initSeed - initSeed') : seqN(N, (_ * a + c) % m )) ~ _ : par(i, N, _ / m))
    with{
        a = 18446744073709551557; c = 12345; m = 2 ^ 31; 
    };

ControlSignalPath(N, seed, secMin, secMax) = ((noise(N, seed) : par(i, N, randomtrigger)), (LookaheadNormalizer(1.0, 0.1, 10) <: si.bus(N))) : ro.interleave(N, 2) : par(i, N, sah)
with{
    phasor0(f) = (_ <: _ + f, _) ~  _ % SR : (!, _ / SR);
    derivate(x) = x < x';
    pulseTrain(f) = phasor0(f) : derivate;
    dirac = 1 - 1';
    selector(sel, x, y) = x * (1 - sel) + y * (sel);
    sah(t, x) = selector(t, _, x) ~ _;
    randomtrigger = (_ + dirac, abs * (1 / secMin) + (1 / secMax) : sah : pulseTrain) ~ _;
};

Del(N) = par(i, N, _ @ (1000 - 1));

// Controls Structure
controls(bw, bpf, gain, damping, mod, rate) = vgroup("BW", controlMap(4, 100, bw, _)), vgroup("BPF", controlMapexp(8, bpf, _)), vgroup("Gain", controlMap(0.1, 100, gain, _)), vgroup("Damping", controlMap(0, 1, damping, _)), vgroup("Mod", controlMap(1, 9, mod, _)), vgroup("Rate", controlMap(20, 180, rate, _)), bi2uni, _;

// Manual Controls
fixedControls = (vgroup("Mixer", hgroup("Global Control", si.smoo(vslider("REVERB [style: knob]", 0.2, 0, 1, .001)), si.smoo(vslider("BW [style: knob]", 0, -10, 10, 0.001)), si.smoo(vslider("BPF [style: knob]", 0, -10, 10, 0.001)), si.smoo(vslider("GAIN [style: knob]", 0, -10, 10, 0.001)), si.smoo(vslider("DAMPING [style: knob]", 0, -10, 10, 0.001)), si.smoo(vslider("MOD [style: knob]", 0, -10, 10, 0.001)), si.smoo(vslider("RATE [style: knob]", 0, -10, 10, 0.001)))), si.bus(InputsN));

// Osc Voice
duffing(iBPbank, bandwidth, freqshift, gain, damping, mod, rate, netSig, micSig) = out
with{
// Duffing Equation
osc(duffY, duffX) = dy, duffX0, finalY
    with{
        finalY = bandpassFiltersBank(iBPbank, FiltersN, gain, bandwidth, freqshift, duffX);
        dt = (rate / SR : + ~ _ % (60 * rate));
        dy = (finalY - (finalY * finalY * finalY)) - (ma.tanh(damping + netSig) * duffY) + mod * sin(dt + micSig);
        duffX0 = atan(duffY + dy);
    };
out = osc ~ si.bus(2) : (!, !, _);
};

// Global Network
Network(N, reverbg, bw, bpf, gain, damping, mod, rate) = si.bus(InputsN) <: (ro.interleave(N, 2) : vgroup("Oscillators", par(i, N, hgroup("voice %i", si.bus(2) <: ((si.bus(2) :> + : ControlSignalPath(6, InitSeed * (i + 1), 10, 20)), _, _) : controls(bw, bpf, gain, damping, mod, rate) : duffing(i + 1)))) : (reverb(N, 8, 8, 2, 5, 10, reverbg)) : vgroup("Mixer", Mixer(8)) <: (si.bus(8) :> si.bus(4)), si.bus(8)) ~ (ro.crossNM(N - 1, 1) : Del(N)) : (si.block(4), si.bus(8)) :> (si.bus(OutputsN) : par(i, OutputsN, _ / (8 / OutputsN)));
// Out
process = tgroup("RITI", fixedControls : Network(4));

// Single Voice Test
duffing_test(bandwidth, freqshift, smooth, gain, damping, mod, rate, ext) = out
with{
// Duffing Equation
osc(duffY, duffX) = dy, duffX0, finalY
    with{
        bandpassFiltersBank(bands, globalG, globalBW, globalF, x) = par(i, bands, bandpassBiquad(ba.take(1 + i, (97, 156, 186, 200, 243, 318, 333, 383, 435, 453, 495, 500, 598, 678, 687, 702, 720, 883, 1522, 1747, 1859, 1957, 1965, 2065)) * globalF, globalBW, globalG, x)) :> _ / bands;
        finalY = bandpassFiltersBank(FiltersN, gain, bandwidth, freqshift, duffX);
        dt = (rate / SR : + ~ _ % (60 * rate));
        dy = (finalY - (finalY * finalY * finalY)) - (damping * duffY) + mod * sin(dt);
        duffX0 = atan(duffY + dy);
    };
out = (osc ~ si.bus(2) : (!, !, _));
};
//process = hgroup("voice_0", (si.smoo(vslider("bandwidth", 54, 1,100, 0.0001)), 8 ^ si.smoo(vslider("frequency", 0, -1, 1, 0.0001)), si.smoo(vslider("smooth", 1, 0, 1, 0.0001)), si.smoo(vslider("gain", 82, 0, 200, 0.0001)), si.smoo(vslider("damping", 0.3, 0, 1, 0.0001)), si.smoo(vslider("mod", 4, 0, 10, 0.0001)), si.smoo(vslider("rate", 108, 5, 200, 0.0001)), _) : duffing_test);
