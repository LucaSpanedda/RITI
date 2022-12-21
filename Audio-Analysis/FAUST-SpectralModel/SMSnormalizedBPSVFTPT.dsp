// Faust standard libraries
import("stdfaust.lib");

// Spectral Modeling Synthesis
// https://en.wikipedia.org/wiki/Spectral_modeling_synthesis


// INSTRUMENT SPECTRE --------------------------------------
// Import lists: Frequencies, Amps, Bandwidth
spectrefreq = component("frequencies.dsp").frequencieslist;
spectreamps = component("normalizedamplitudes.dsp").normalizedamplitudeslist;
spectreband = component("bandwidths.dsp").bandwidthslist;
// index of the lists
Flist(index) = ba.take(index + 1, spectrefreq);
Alist(index) = ba.take(index + 1, spectreamps);
BWlist(index) = ba.take(index + 1, spectreband);


//  BP FILTER ----------------------------------------------
// TPT version of the SVF Filter by Vadim Zavalishin
// reference : (by Will Pirkle)
// http://www.willpirkle.com/Downloads/AN-4VirtualAnalogFilters.2.0.pdf
SVFTPT(K, Q, CF, x) = circuitout : !,!,_,_,_,_,_,_,_,_
    with{
        g = tan(CF * ma.PI / ma.SR);
        R = 1.0 / (2.0 * Q);
        G1 = 1.0 / (1.0 + 2.0 * R * g + g * g);
        G2 = 2.0 * R + g;

        circuit(s1, s2) = u1 , u2 , lp , hp , bp, notch, apf, ubp, peak, bshelf
            with{
                hp = (x - s1 * G2 - s2) * G1;
                v1 = hp * g;
                bp = s1 + v1;
                v2 = bp * g;
                lp = s2 + v2;
                u1 = v1 + bp;
                u2 = v2 + lp;
                notch = x - ((2*R)*bp);
                apf = x - ((4*R)*bp);
                ubp = ((2*R)*bp);
                peak = lp -hp;
                bshelf = x + (((2*K)*R)*bp);
            };
    // choose the output from the SVF Filter (ex. bshelf)
    circuitout = circuit ~ si.bus(2);
    };
// Outs = (lp , hp , bp, notch, apf, ubp, peak, bshelf)
BPSVF(A, BW, CF, x) = SVFTPT(1, Q, CF, XA)   : !,!,!,!,!,_,!,!
    with{
        Q = CF/BW;
        XA = x * A;
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
// process =   no.noise : filterbanks(1, 128, 2000, 1, 1) : 
//             normalize(1) <: _,_;
// 2nd Order
process =   no.noise : filterbanks(2, 64, 40, 1, 1) : 
            normalize(1) <: _,_;