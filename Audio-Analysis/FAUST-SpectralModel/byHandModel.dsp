// Faust standard libraries
import("stdfaust.lib");

// Spectral Modeling Synthesis
// https://en.wikipedia.org/wiki/Spectral_modeling_synthesis


// INSTRUMENT SPECTRE --------------------------------------
// index of the lists
Flist(index) = ba.take(index + 1,  ( 66, 129, 196, 261, 325, 390, 457, 520 ));  
Alist(index) = ba.take(index + 1,  ( .8, 1.2, .50, .60, .30, .20, .04, .18 ));   
BWlist(index) = ba.take(index + 1, ( 10, 8.0, 8.0, 6.0, 6.0, 10., 2.0, 10. ));   
Voices = 8;

//  BP FILTER ----------------------------------------------
// optimized BP from the TPT version of the SVF Filter by Vadim Zavalishin
// reference : (by Will Pirkle)
// http://www.willpirkle.com/Downloads/AN-4VirtualAnalogFilters.2.0.pdf
BPSVF(glin, bw, cf, x) = loop ~ si.bus(2) : (! , ! , _)
    with {
        g = tan(cf * ma.PI * ma.T);
        Q = cf / max(1.0, bw);
        R = 1.0 / (Q + Q);
        G = 1.0 / (1.0 + 2.0 * R * g + g * g);
        loop(s1, s2) = u1 , u2 , bp * glin
            with {
                bp = (g * (x - s2) + s1) * G;
                bp2 = bp + bp;
                v2 = bp2 * g;
                u1 = bp2 - s1;
                u2 = v2 + s2;
            };
    };


// Spectre BP Filter Bank
filterbanks(cascade, parallel, gglob, bwglob, fsglob, x) = 
    x <: par(i, parallel,
                            seq(r, cascade, BPSVF(
                                            Alist(i) * gglob, 
                                            BWlist(i) * bwglob, 
                                            Flist(i) * fsglob
                                            ) 
                                )
            ):> (+/parallel);

// SMS Out
// Import limiter
normalize(treshold, x) = component("limiters.dsp").normalization(treshold, x);
// 1st Order
pulsexcit = ba.pulse(hslider("fpulse",10000,100,10000,.01)) : si.smoo * 200;
noisexcit = no.noise * .1;
process =   (noisexcit : filterbanks(2, Voices, 1, 1, 1))
            <: _,_;
