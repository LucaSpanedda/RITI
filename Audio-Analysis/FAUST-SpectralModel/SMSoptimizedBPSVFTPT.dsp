// Faust standard libraries
import("stdfaust.lib");

// Spectral Modeling Synthesis
// https://en.wikipedia.org/wiki/Spectral_modeling_synthesis


// INSTRUMENT SPECTRE --------------------------------------
// Import lists: Frequencies, Amps, Bandwidth
spectrefreq = component("frequencies.dsp").frequencieslist;
spectreamps = component("amplitudes.dsp").amplitudeslist;
spectreband = component("bandwidths.dsp").bandwidthslist;
// index of the lists
Flist(index) = ba.take(index, spectrefreq)  * .500 ;
Alist(index) = ba.take(index, spectreamps)  * 1.00 ;
BWlist(index) = ba.take(1, spectreband)     * 1/10 ;
// process = Flist(11), Flist(11), BWlist(11);

//  BP FILTER ----------------------------------------------
// optimized BP from the TPT version of the SVF Filter by Vadim Zavalishin
// reference : (by Will Pirkle)
// http://www.willpirkle.com/Downloads/AN-4VirtualAnalogFilters.2.0.pdf
BPSVF(glin, bw, cf, x) = loop ~ si.bus(2) : (! , ! , _)
    with {
        g = tan(cf * ma.PI * ma.T);
        Q = cf / max(ma.EPSILON, bw);
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
filterbanks(cascade, parallel, x) = 
    x <: par(i, parallel,
                            seq(r, cascade, BPSVF(
                                            Alist(i + 1), 
                                            BWlist(i + 1), 
                                            Flist(i + 1) 
                                            ) 
                                )
            ):> (+/parallel);

// SMS Out
// Import limiter
normalize(treshold, x) = component("limiters.dsp").normalization(treshold, x);
slidertest = si.smoo( ba.db2linear( hslider("Amp [unit:db]", -80, -80, 0, .001) ) );
process =   no.noise * slidertest * 10 : filterbanks(1, 128) <: _,_;