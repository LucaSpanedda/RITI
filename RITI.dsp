//---------------------------`ROOM IS THE INSTRUMENT`---------------------------
declare options "[midi:on]";
import("stdfaust.lib");


//- BASIC FUNCTIONS ------------------------------------------------------------

// Constants values
PI = ma.PI;
TWOPI = 2.0 * PI;
SR = ma.SR;
EPS = ma.EPSILON;
NY = SR / 2.0;
T = 1.0 / SR;
PIT = PI * T;
TWOPIT = TWOPI * T;
MS2T(t) = (t / 1000) * SR;
MIN = ma.MIN;
MAX = ma.MAX;

// Selector
selector(sel, x, y) = x * (1 - sel) + y * (sel);

// SAH - Sample and Hold
sah(t, x) = selector(t, _, x) ~ _;

// Sequential operations
seqN(N, OP) = _ <: seq(i, N, (OP <: _, _), si.bus(i + 1)) :
    (_, !, si.bus(N - 1), !);


//- FILTER FREQUENCIES ---------------------------------------------------------

// Spectrum - BP filters values
FrequenciesTable =
waveform{
/* 01 */    97, 156, 186, 200, 243, 318, 333, 383, 435, 453, 495, 500, 598,
            678, 687, 702, 720, 883, 1522, 1747, 1859, 1957, 1965, 2065,
/* 02 */    136, 185, 312, 402, 676, 765, 872, 1016, 1397, 1811, 2252, 2708,
            3180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 03 */    242, 375, 513, 515, 859, 940, 1040, 1300, 1775, 2830, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 04 */    205, 364, 455, 455, 455, 770, 770, 770, 876, 1158, 1310, 1590,
            2062, 2549, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 05 */    141, 222, 298, 298, 298, 298, 552, 758, 1041, 1345, 1578, 1671,
            2000, 2341, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 06 */    68, 97, 170, 248, 391, 449, 531, 589, 658, 711, 879, 771, 807,
            1053, 1200, 1255, 1460, 1478, 1521, 1685, 1666, 1784, 1921, 1954,
/* 07 */    140, 150, 276, 285, 449, 693, 730, 854, 932, 979, 1417, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 08 */    30, 60, 90, 122, 166, 201, 270, 293, 308, 490, 502, 953, 1337,
            1664, 4515, 4686, 5767, 0, 0, 0, 0, 0, 0, 0,
/* 09 */    64, 98, 130, 163, 196, 227, 294, 327, 360, 393, 426, 459, 497,
            526, 560, 594, 628, 664, 696, 732, 801, 908, 980, 1052,
/* 10 */    338, 875, 894, 1050, 1150, 1620, 1662, 1666, 1841, 1852, 2052,
            2243, 2311, 2584, 2842, 2893, 2958, 2980, 3731, 4251, 4516, 4852,
            0, 0,
/* 11 */    386.52, 389.92, 387.6, 392.95, 396.54, 399.91, 408.22, 411.38,
            612.85, 619.66, 624.63, 625.6, 633.9, 633.58, 636.53, 640.57,
            645.58, 648.5, 653.81, 656.25, 657.11, 662.2, 663.31, 665.58,
/* 12 */    1001.79, 1008.32, 1010.39, 1020.54, 1024.12, 1029.16, 1033.89,
            257.87, 260.92, 263.89, 290.34, 290.98, 312.52, 328.6, 332.0,
            332.6, 337.91, 492.14, 498.17, 498.38, 512.71, 515.93, 517.73,
            522.3,
/* 13 */    267.42, 270.95, 273.68, 277.1, 282.19, 281.95, 288.21, 289.19,
            292.58, 297.27, 341.06, 410.82, 413.23, 418.27, 420.77, 423.27,
            426.64, 426.59, 432.89, 431.39, 438.81, 440.5, 439.26, 444.22,
/* 14 */    170.96, 176.6, 176.51, 214.11, 219.5, 222.93, 222.38, 254.64,
            253.16, 255.84, 263.34, 353.19, 355.7, 410.39, 413.21, 416.35,
            419.67, 423.48, 428.06, 429.54, 432.98, 434.75, 435.96, 441.76,
/* 15 */    127.6, 132.89, 136.54, 261.66, 267.77, 270.69, 311.32, 314.69,
            319.62, 397.77, 398.23, 531.74, 630.96, 632.78, 800.53, 942.26,
            944.72, 0, 0, 0, 0, 0, 0, 0,
/* 16 */    262.76, 267.94, 268.35, 313.42, 313.68, 316.51, 332.93, 398.09,
            400.57, 399.27, 527.43, 535.01, 534.75, 625.64, 631.93, 631.57,
            799.6, 798.52, 944.25, 946.75, 946.91, 952.97, 1057.93, 1060.44,
/* 17 */    133.71, 135.24, 233.29, 237.57, 240.5, 265.28, 264.22, 270.11,
            396.8, 403.8, 402.28, 469.33, 471.85, 478.18, 477.63, 592.91,
            599.42, 603.17, 893.37, 952.37, 954.94, 1192.62, 1192.51, 0,
/* 18 */    221.21, 221.64, 223.71, 230.55, 369.35, 373.04, 378.99, 382.3,
            381.67, 445.69, 444.51, 448.88, 450.86, 599.47, 750.24, 755.82,
            755.19, 893.39, 893.03, 898.85, 897.46, 1124.42, 1125.9, 0,
/* 19 */    132.32, 133.33, 260.98, 265.14, 269.87, 313.93, 315.38, 315.4,
            529.38, 530.73, 533.4, 630.93, 631.14, 796.83, 940.4, 944.4,
            949.23, 1064.89, 1255.3, 1254.54, 1258.47, 1262.46, 2117.52, 0,
/* 20 */    309.36, 315.01, 315.25, 318.68, 400.84, 399.22, 599.95, 600.82,
            632.04, 631.61, 635.78, 792.57, 797.03, 801.87, 946.98, 944.77,
            952.91, 952.92, 1194.99, 1262.33, 1259.48, 1262.87, 1266.38,
            1891.06
};


//- FILTERS --------------------------------------------------------------------

// TPT OP Filter
onePoleTPT(cf, x) = loop ~ _ : ! , si.bus(3)
    with {
        g = tan(cf * PI * T);
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
// Smoother
smoocntrl(x) = LPTPT(1, x);

// Bandpass Filters - Pattern Matching : bp(1), bp(2), bp(3), bp(4) ...
bp(i, cf, bw, gf) = bp(i) * LPTPT(100, (cf > 0))
with{
// filterselector - pattern matching
bp(1) = bandpassBiquad(cf, bw, gf);
bp(2) = bptptNormalized(cf, bw, gf);
bp(3) = bptptOptimized(cf, bw, gf);
bp(4) = bpSVFTPT(cf, bw, gf);

// Robert Bristow-Johnson's BP Biquad Filter - Direct Form 1
bandpassBiquad(cf, bw, gf) = biquadFilter
    with {
        biquadFilter =
            _ * gf <: _, (mem  <: (_, mem)) : (_ * a0, _ * a1, _ * a2) :> _ :
            ((_, _) :> _) ~ (_ <: (_, mem) : (_ * - b1, _ * - b2) :> _);
        Fx = max(20, min(20000, LPTPT(10, cf)));
        Qx = max(EPS, min(MAX,  LPTPT(10, bw)));
        K = tan(PI * Fx / SR);
        norm = 1 / (1 + K / Qx + K * K);
        a0 = K / Qx * norm;
        a1 = 0;
        a2 = - a0;
        b1 = 2 * (K * K - 1) * norm;
        b2 = (1 - K / Qx + K * K) * norm;
    };
// Normalized Bandpass SVF TPT
bptptNormalized(cf, bw, gf, x) = loop ~ si.bus(2) : (! , ! , _)
    with {
        Fx = max(20, min(20000, LPTPT(10, cf)));
        Qx = max(EPS, min(MAX,  LPTPT(10, bw)));
        g = tan(Fx * PI * T);
        R = 1.0 / (2.0 * Qx);
        G1 = 1.0 / (1.0 + 2.0 * R * g + g * g);
        G2 = 2.0 * R + g;
        loop(s1, s2) = u1 , u2 , bp * 2.0 * R
            with {
                hp = ((x * gf) - s1 * G2 - s2) * G1;
                v1 = hp * g;
                bp = s1 + v1;
                v2 = bp * g;
                lp = s2 + v2;
                u1 = v1 + bp;
                u2 = v2 + lp;
            };
    };
// Optimized BP from the TPT version of the SVF Filter by Vadim Zavalishin
bptptOptimized(cf, bw, gf, x) = loop ~ si.bus(2) : (! , ! , _)
    with {
        Fx = max(20, min(20000, LPTPT(10, cf)));
        Qx = max(EPS, min(MAX,  LPTPT(10, bw)));
        g = tan(Fx * PI * (1.0 / SR));
        Q = Fx / max(EPS, Qx);
        R = 1.0 / (Q + Q);
        G = 1.0 / (1.0 + 2.0 * R * g + g * g);
        loop(s1, s2) = u1 , u2 , bp
            with {
                bp = (g * ((x * gf) - s2) + s1) * G;
                bp2 = bp + bp;
                v2 = bp2 * g;
                u1 = bp2 - s1;
                u2 = v2 + s2;
            };
    };
// Bandpass TPT with BW
bpSVFTPT(cf, bw, gf, x) = Q , CF , X : SVFTPT : (! , ! , ! , _ , !)
    with {
        CF = max(20, min(20480, LPTPT(10, cf)));
        BW = max(1, min(20480,  LPTPT(10, bw)));
        Q = max(.01, min(100, BW / CF));
        X = x * gf;
        SVFTPT(Q, cf, x) = loop ~ si.bus(2) : (! , ! , _ , _ , _ , _ , _)
        with {
            g = tan(cf * PI * (1.0 / SR));
            R = 1.0 / (2.0 * Q);
            G1 = 1.0 / (1.0 + 2.0 * R * g + g * g);
            G2 = 2.0 * R + g;
            loop(s1, s2) =
                u1 , u2 , lp , hp , bp , bp * 2.0 * R , x - bp * 4.0 * R
                with {
                    hp = (x - s1 * G2 - s2) * G1;
                    v1 = hp * g;
                    bp = s1 + v1;
                    v2 = bp * g;
                    lp = s2 + v2;
                    u1 = v1 + bp;
                    u2 = v2 + lp;
                };
        };
    };
};

// BP filters bank
bpfiltersbank(N, Program, BPType, F, Q, G, S, x) =
    par(i, N, (((FrequenciesTable, int(Program * N)) : (_, _, _ + i) :
    rdtable) * F, Q, G, x) : bp(BPType)) :> _ / N;

// Peak Envelope and Peak Envelope Att Rel
peakenvelope(period, x) = loop ~ _
    with {
        loop(y) = max(abs(x), y * coeff);
        twoPIforT = (2.0 * PI) * (1.0 / SR);
        coeff = exp(-twoPIforT / max(EPS, period));
    };

peakEnvAttRel(att, rel, x) = peakenvelope(rel - att, x) :
    LPTPT(1.0 / max(EPS, att));

// Peakholder
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

// Cascaded onepole smoothers with attack and release times
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

// Lookahead limiter
gainAttenuation(th, att, hold, rel, x) =
    th / (max(th, peakHoldCascade(8, att + hold, x)) :
        smootherCascade(4, att, rel));
LookaheadLimiter(th, x_) = xDelayed * gainAttenuation(th, .01, .1, .1, abs(x_))
    with {
        delay = rint((.01 / 8) * SR) * 8;
        xDelayed = x_ @ delay;
    };

// Lookahead Normalizer
LookaheadNormalizer(threshold, holdSec, decaySec) = _ <: 1 /
    max(MIN, (_ : peakHolder(holdSec) :
        LPTPT(1 / holdSec) : peakenvelope(decaySec))
    ) * _ @ (holdSec * SR);


//- CONTROL SIGNALS ------------------------------------------------------------

// Noise - Linear Congruential Generator - Multiple Outputs
noise(N, initSeed) = ((_ + (initSeed - initSeed') :
    seqN(N, (_ * a + c) % m )) ~ _ : par(i, N, _ / m))
    with{
        a = 18446744073709551557; c = 12345; m = 2 ^ 31;
    };

// Control Signals based on Input Signal (SAH)
ControlSignalPath(N, seed, secMin, secMax) = ((noise(N, seed) :
    par(i, N, randomtrigger)), (LookaheadNormalizer(1.0, 0.1, 10) <: si.bus(N))
    ) : ro.interleave(N, 2) : par(i, N, sah)
with{
    phasor0(f) = (_ <: _ + f, _) ~  _ % SR : (!, _ / SR);
    derivate(x) = x < x';
    pulseTrain(f) = phasor0(f) : derivate;
    dirac = 1 - 1';
    randomtrigger = (_ + dirac, abs * (1 / secMin) +
        (1 / secMax) : sah : pulseTrain) ~ _;
};


//- DELAYS ---------------------------------------------------------------------

// Network Fixed Delays
Del(N) = par(i, N, _ @ (1000 - 1));


//- MAPPING --------------------------------------------------------------------

// Mapping Functions
info(i, lower, upper) = _ <: _, vbargraph("%i [style:numerical]", lower, upper)
    : attach;
mapping(low, high, x) = x * (high - low) + low;
uni2bi(x) = x * 2.0 - 1.0;
bi2uni(x) = x * 0.5 + 0.5;
controlMap(id, low, high, offset, x) = vgroup("Osc",
    info(id + 1, low, high, mapping(low, high, bi2uni(ma.tanh(x + offset))))
);
controlMapExp(id, exponent, offset, x) = vgroup("Osc",
    info(id + 1, -exponent, exponent, exponent ^ (ma.tanh(x + offset)))
);

// Controls Structure
controls(id, sm, bw, bpf, gain, damping, mod, rate) =
vgroup("Mixer", vgroup("Global Control", hgroup("Filters Preset",
    vslider("%id[style: knob] [midi:ctrl 6%id]", id, 0, 19, 1)
))),
    vgroup("Smooth", sm),
hgroup("Status", hgroup("Control Signals",
    vgroup("BW",
        controlMap(id, 30, 100, bw, sah((1 - checkbox("SAH")), _))
    ),
    vgroup("BPF",
        controlMapExp(id, 8, bpf, sah((1 - checkbox("SAH")), _))
    ),
    vgroup("Gain",
        controlMap(id, 0.1, 0.9, gain, sah((1 - checkbox("SAH")), _))
    ),
    vgroup("Damping",
        controlMap(id, -0.999, 0.999, damping, sah((1 - checkbox("SAH")), _))
    ),
    vgroup("Mod",
        controlMap(id, 1, 9, mod, sah((1 - checkbox("SAH")), _))
    ),
    vgroup("Rate",
        controlMap(id, 20, 180, rate, sah((1 - checkbox("SAH")), _))
    )
)),
si.bus(2);


//- GUI - (Graphic User Interface) ---------------------------------------------

// Manual Controls
fixedControls(IN) =
hgroup("Status", vgroup("Clock",
    smoocntrl(
        vslider("MIN [style: knob] [midi:ctrl 101]", 10, 1, 60, 1)
    ),
    smoocntrl(
        vslider("MAX [style: knob] [midi:ctrl 102]", 20, 1, 60, 1)
    )
)),
vgroup("Mixer", vgroup("Global Control",
    hgroup("Oscillators",
    smoocntrl(
        vslider("[8] REVERB [style: knob] [midi:ctrl 16]", 0.2, 0, 1, 0.001)
        ),
    smoocntrl(
        vslider("[2] LIMIT [style: knob] [midi:ctrl 101]", -2, -80, 0, 0.001) :
        ba.db2linear),
    smoocntrl(
        vslider("[10] SMOOTH [style: knob] [midi:ctrl 18]", 1000, 20, 20000, 1)
        ),
    smoocntrl(
        vslider("[4] BW [style: knob] [midi:ctrl 12]", 0, -10, 10, 0.001)
        ),
    smoocntrl(
        vslider("[3] BPF [style: knob] [midi:ctrl 11]", 0, -10, 10, 0.001)
        ),
    smoocntrl(
        vslider("[1] GAIN [style: knob] [midi:ctrl 10]", 0, -10, 10, 0.001)
        ),
    smoocntrl(
        vslider("[5] DAMPING [style: knob] [midi:ctrl 13]", 0, -10, 10, 0.001)
        ),
    smoocntrl(
        vslider("[6] MOD [style: knob] [midi:ctrl 14]", 0, -10, 10, 0.001)
        ),
    smoocntrl(
        vslider("[7] RATE [style: knob] [midi:ctrl 15]", 0, -10, 10, 0.001)
        )
    )
),
    par(id, IN,
        mixerVoiceVM(id + 1) * vgroup("Global Control", hgroup("Oscillators",
        vslider("[9] MICS [style: knob] [midi:ctrl 17]", -80, -80, 0, 0.001) :
        ba.db2linear : smoocntrl))
    )
);

// Mixer
mixerVoiceG(v, dBoffset) =
    vgroup("Mixer", hgroup("Channels", hgroup("%v", vol)))
    with{
        vol =   * (vslider("G [midi:ctrl %v]", -80, -80, -20, 0.001) +
                dBoffset : ba.db2linear : smoocntrl);
    };
mixerVoiceM =
    vgroup("Mixer", hgroup("Channels", hgroup("M", vol)))
    with{
        vol =   * ((vslider("M [midi:ctrl 9]", -80, -80, 20, 0.001) :
                ba.db2linear) <: (_ > ba.db2linear(-80)) * _ : smoocntrl);
    };
mixerVoiceV(v) =
    vgroup("Mixer", hgroup("Channels", hgroup("%v", vumeter)))
    with{
        vumeter(x) = attach(x, envelop(x) : vbargraph("V", 0, 1.0))
		    with { envelop = abs : min(0.99) : max ~ -(1.0 / SR); };
    };
mixerVoiceVM(v) =
    hgroup("Channels", hgroup("M", hgroup("Mic %v", vumeter)))
    with{
        vumeter(x) 	= attach(x, envelop(x) : vbargraph("V", 0, 1.0))
		    with { envelop = abs : min(0.99) : max ~ -(1.0 / SR); };
    };


//- OSCILLATOR - (System Kernel) -----------------------------------------------

duffing(id, filtersN, filterType, preset, smooth, bandwidth,
freqshift, gain, damping, mod, rate, netSig, micSig) =
    osc ~ si.bus(2) : (si.block(2), _)
with{
// Duffing Equation + Bandpass filters bank
osc(duffY, duffX) = dy, duffX0, finalY
    with{
        // finalY = duffX * (gain * 0.01);
        // function for bypass the BP filters bank
        duffXscaled = duffX * gain : mixerVoiceG(id + 1, 80);
        finalY =    bpfiltersbank(filtersN, preset, filterType,
                    freqshift, bandwidth, 1, smooth, duffXscaled);
        dt = (rate / SR : + ~ _ % (60 * rate));
        dy =    (finalY - (finalY * finalY * finalY)) -
                (ma.tanh(damping + netSig) * duffY) + mod * sin(dt + micSig);
        duffX0 = atan(duffY + dy);
    };
};


//- REVERBERATOR ---------------------------------------------------------------

// Reverb (Keith Barr Allpass Loop)
reverb(I, O, N, SEQ, parspace, start, KRT) = si.bus(I) <:
(InputStage :
    (ro.interleave(N, N/(N/2)) : par(i, N, si.bus(2) :> _) :
        par(i, N,
        seq(k, SEQ,
            // cleanfunc
            ModAPF(
                (primenumbers((k + start) + (i * parspace)) : MS2T),
                (primenumbers((k + start) + (i * parspace)) / 100 : MS2T),
                (0.5 / primenumbers((k + start) + (i * parspace)) : MS2T)
            )
        ) :
        _ * KRT
    )   : ro.crossNM(N - 1, 1)) ~
    si.bus(N) :>
OutputStage), OutGain :> par(i, O, _)
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
        list =  2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,
                61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127,
                131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191,
                193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257,
                263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331,
                337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401,
                409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467,
                479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557;
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


//- OUTPUT Functions -----------------------------------------------------------

// SMS filters test
/*
process =   no.noise : bpfiltersbank(24, 1, 1, 1, 1000, 100, 1) <: si.bus(2);
*/

// Duffing single voice test
/*
process =   hgroup("voice_0", ((vslider("preset", 0, 0, 19, 1)),
            smoocntrl(vslider("smooth", 1000, 20, 20000, 1)),
            smoocntrl(vslider("bandwidth", 54, 30, 100, 0.0001)),
            8 ^ smoocntrl(vslider("frequency", 0, -1, 1, 0.0001)),
            1,
            smoocntrl(vslider("damping", 0.3, -0.999, 0.999, 0.0001)),
            smoocntrl(vslider("mod", 4, 0, 10, 0.0001)),
            smoocntrl(vslider("rate", 108, 5, 200, 0.0001)), _ * 0, _) :
            duffing(1, 24, 1)) : _ * 0.5 <: si.bus(2);
*/

// Global Network
Network(IN, N, Nfilters, FilterType, Seed, cntrlMin, cntrlMax, reverbg, limitg,
sm, bw, bpf, gain, damping, mod, rate) = si.bus(IN) <:
(ro.interleave(N, 2) :
    (par(i, N, (si.bus(2) <: ((si.bus(2) :> _ :
        ControlSignalPath(6, Seed * (i + 1), cntrlMin, cntrlMax)), _, _) :
        controls(i, sm, bw, bpf, gain, damping, mod, rate) :
        duffing(i, Nfilters, FilterType)))
    ) :
        reverb(N, N, 8, 2, 5, 10, reverbg) :
        par(k, N, HPTPT(20) : LPTPT(sm) : LookaheadLimiter(0.780))
) ~ (ro.crossNM(N - 1, 1) : Del(N)) :
par(id, N, mixerVoiceM) : par(id, N, mixerVoiceV(id + 1));

// Network output
///*
process =   tgroup("ROOM_IS_THE_INSTRUMENT",
                fixedControls(2) : Network(2, 8, 24, 1, 15021995)
            );
//*/
