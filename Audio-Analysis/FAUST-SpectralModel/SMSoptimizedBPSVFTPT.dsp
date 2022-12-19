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
// 1st Order
process =  no.noise : filterbanks(1, 128, 8, 1, 1) <: _,_;
// 2nd Order
// process =  no.noise : filterbanks(2, 64, 1/6, 1, 1) <: _,_;