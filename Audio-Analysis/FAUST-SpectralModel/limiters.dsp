// Faust standard libraries
import("stdfaust.lib");

//------------------------------------------------------------------ FILTERS ---
// Zavalishin Onepole TPT Filter
onePoleTPT(cf, x) = loop ~ _ : ! , si.bus(3) // Outs: lp , hp , ap
with {
    g = tan(cf * ma.PI * ma.T);
    G = g / (1.0 + g);
    loop(s) = u , lp , hp , ap
    with {
        v = (x - s) * G; u = v + lp; lp = v + s; hp = x - lp; ap = lp - hp;
    };
};
// Lowpass TPT
LPTPT(cf, x) = onePoleTPT(cf, x) : (_ , ! , !);
// Highpass TPT
HPTPT(cf, x) = onePoleTPT(cf, x) : (! , _ , !);

//---------------------------------------------------------------- FUNCTIONS ---
ms2samp(t) = (t/1000) * ma.SR;
sec2samp(t) = t * ma.SR;
limit(maxl,minl,x) = x : max(minl, min(maxl));
//---------------------------------------------------------------- ANALIZERS ---
peakHolder(holdTime, x) = loop ~ si.bus(2) : ! , _
with {
    loop(timerState, outState) = timer , output
    with {
        isNewPeak = abs(x) >= outState;
        isTimeOut = timerState >= (holdTime * ma.SR - 1);
        bypass = isNewPeak | isTimeOut;
        timer = ba.if(bypass, 0, timerState + 1);
        output = ba.if(bypass, abs(x), outState);
    };
};


// RMS with indipendent attack and release time:
// reference:
// Udo Zölzer - Digital Audio Signal Processing Second Edition
// reference :
// https://fmipa.umri.ac.id/wp-content/uploads/2016/03/
// Udo-Zolzer-digital-audio-signal-processing.9780470997857.40435.pdf
RMS(att,rel,x) = loop ~ _ : sqrt
with {
    loop(y) = (1.0 - coeff) * x * x + coeff * y
    with {
        attCoeff = exp(-2.0 * ma.PI * ma.T / att);
        relCoeff = exp(-2.0 * ma.PI * ma.T / rel);
        coeff = ba.if(abs(x) > y, attCoeff, relCoeff);
    };
};

// Moving Average RMS
movingAverage(seconds, x) = x - (x @ N) : fi.pole(1.0) / N
with {
N = seconds * ma.SR;
};
RMSRectangular(seconds, x) = sqrt(max(0, movingAverage(seconds, x * x)));

// Peak Envelope (envelope follower)
// reference :
// https://www.dariosanfilippo.com/blog/2017/
// lookahead-limiting-in-pure-data/
// reference :
// https://www.cs.princeton.edu/courses/archive/spr05/cos579/DSP/DSP.html
peakenvelope(t,x) = abs(x) <: loop ~ _ * rt60(t)
with{
    loop(y,z) = ( (y,z) : max);
    rt60(t) = 0.001^((1/ma.SR)/t);
};

//------------------------------------------------------- LOOKAHEAD LIMITERS ---
// reference :
// https://www.dariosanfilippo.com/blog/2017/
// lookahead-limiting-in-pure-data/
// reference :
// https://users.iem.at/zmoelnig/publications/limiter/
// Peak normalization
// reference :
// https://www.hackaudio.com/digital-signal-processing/amplitude/peak-normalization/


normalization(treshold, x) = treshold /
    ( x : peakHolder(.1) : LPTPT(500) : peakenvelope(10)) *
      x @ (( 2/1000 ) * ma.SR);
limitation(threshold, x) = 
    ( x : peakHolder(.1) : LPTPT(500) : peakenvelope(10)) : 
    ( threshold / max(ma.EPSILON, _) : min(1.0) ) *
    ( x @ (ms2samp(1)));