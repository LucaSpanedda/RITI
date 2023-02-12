// Faust standard libraries
import("stdfaust.lib");
// Import lists: Frequencies, Amps, Bandwidth
import("chunk1ch1D2_Cello.lib");
import("chunk2ch1D2_Cello.lib");
import("chunk3ch1D2_Cello.lib");
import("chunk4ch1D2_Cello.lib");
// import list example:
// chunk_1_ch1_D2_Cello_frequencies
// chunk_2_ch1_D2_Cello_amplitudes
// chunk_4_ch1_D2_Cello_bandwidths

// Spectral Modeling Synthesis
// https://en.wikipedia.org/wiki/Spectral_modeling_synthesis


// INSTRUMENT SPECTRE --------------------------------------
// index of the lists
Flist(index) = ba.take(index, chunk_1_ch1_D2_Cello_frequencies) * 1 ;
Alist(index) = ba.take(index, chunk_1_ch1_D2_Cello_amplitudes)  * 1 ;
BWlist(index) = ba.take(1,    chunk_1_ch1_D2_Cello_bandwidths)  * 1/100 ;
// process = Flist(11), Flist(11), BWlist(11);
Flist2(index) = ba.take(index, chunk_2_ch1_D2_Cello_frequencies) * 1 ;
Alist2(index) = ba.take(index, chunk_2_ch1_D2_Cello_amplitudes)  * 1 ;
BWlist2(index) = ba.take(1,    chunk_2_ch1_D2_Cello_bandwidths)  * 1/100 ;
// process = Flist(11), Flist(11), BWlist(11);
Flist3(index) = ba.take(index, chunk_3_ch1_D2_Cello_frequencies) * 1 ;
Alist3(index) = ba.take(index, chunk_3_ch1_D2_Cello_amplitudes)  * 1 ;
BWlist3(index) = ba.take(1,    chunk_3_ch1_D2_Cello_bandwidths)  * 1/100 ;
// process = Flist(11), Flist(11), BWlist(11);
Flist4(index) = ba.take(index, chunk_4_ch1_D2_Cello_frequencies) * 1 ;
Alist4(index) = ba.take(index, chunk_4_ch1_D2_Cello_amplitudes)  * 1 ;
BWlist4(index) = ba.take(1,    chunk_4_ch1_D2_Cello_bandwidths)  * 1/100 ;
// process = Flist(11), Flist(11), BWlist(11);

linInterpolate(x0, x1, delta) = x0 + delta * (x1-x0);
siglinInterpol(order, x) = x : seq(r, order, interpolate)
with{
    interpolate(y) = y + .5 * (y' - y);
};
//process = os.phasor(1,100) : siglinInterpol(10) <: _,_;
bilinInterpolate(x0, x1, x0b, x1b, dt1, dt2) = 
    linInterpolate(
        linInterpolate(x0, x1, dt1), 
        linInterpolate(x0b, x1b, dt1),
        dt2)
    with{
        linInterpolate(x0, x1, delta) = x0 + delta * (x1-x0);
    };

InterpolatedAlist(i, dt1, dt2) = 
bilinInterpolate(Alist(i + 1), Alist2(i + 1), Alist3(i + 1), Alist4(i + 1), dt1, dt2);
InterpolatedBWlist(i, dt1, dt2) = 
bilinInterpolate(BWlist(i + 1), BWlist2(i + 1), BWlist3(i + 1), BWlist4(i + 1), dt1, dt2); 
InterpolatedFlist(i, dt1, dt2) = 
bilinInterpolate(Flist(i + 1), Flist2(i + 1), Flist3(i + 1), Flist4(i + 1), dt1, dt2);



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
filterbanks(cascade, parallel, dt1, dt2, x) = 
    x <: par(i, parallel,
            seq(r, cascade, BPSVF(
                                    InterpolatedAlist(i, dt1, dt2), 
                                    InterpolatedBWlist(i, dt1, dt2), 
                                    InterpolatedFlist(i, dt1, dt2)
                                    ) 
                    )
        ):> (+/parallel);

// SMS Out

pulsexcit = ba.pulse(hslider("fpulse",10000,100,10000,.01)) : si.smoo * 200;
slidertest = si.smoo( ba.db2linear( hslider("Amp [unit:db]", -80, -80, 0, .001) ) );
Dt1 = si.smoo( hslider("dt1", 0, 0, 1, .001) );
Dt2 = si.smoo( hslider("dt2", 0, 0, 1, .001) );
process =   no.noise * slidertest * 10 : filterbanks(1, 128, Dt1, Dt2) <: _,_;