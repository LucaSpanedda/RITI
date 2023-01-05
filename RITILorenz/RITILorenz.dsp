// import faust standard library
import("stdfaust.lib");
// import audible ecosystemics objects library
import("ritilib.lib");

Ktf = ( hslider("Tangent", 1, 1, 100, .001) ) : si.smoo;
Fbf = ( hslider("Feedback", .990, -.990, 1, .001) + 1)/2 : si.smoo;
Wtf = hslider("Peak Window Seconds", .1, .001, 1, .001) : si.smoo;


// INSTRUMENT SPECTRE --------------------------------------
// Import lists: Frequencies, Amps, Bandwidth
spectrefreq = component("frequencies.dsp").frequencieslist;
spectreamps = component("amplitudes.dsp").amplitudeslist;
spectreband = component("bandwidths.dsp").bandwidthslist;
// index of the lists
Flist(index) = ba.take(index, spectrefreq)  * 1.00 ;
Alist(index) = ba.take(index, spectreamps)  * 1.00 ;
BWlist(index) = ba.take(1, spectreband)     * 1 ;
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
//process =   no.noise * slidertest * 10 : filterbanks(1, 128) <: _,_;

// Autoregulating Lorenz System
autolorenzL(in, dcfc, l, peakS, globalFB) = 
    ( loop : par(i, 7, _ / (globalFB)) ) ~ si.bus(7) : 
        par(i, 7, /(l * 2)) : (si.bus(3) :> _ / 3 : normalization(1) ), si.bus(4)
with {
        // saturator(lim,x) = lim*ma.tanh(x);
        saturator(lim,x) = lim * ma.tanh(x/(max(lim,ma.EPSILON)));
        dcblock(dcfc,x) = fi.highpass(1, dcfc, x);
        loop(x, y, z, sigma, dt, rho, beta) = 
 
            filterbanks(1, 64, saturator(l, dcblock(10,((x+in) + sigma * ((y+in) - (x+in)) * dt))) ) , 
            
            filterbanks(1, 64, saturator(l, dcblock(10,((y+in) + (rho * (x+in) - (x+in) * z - (y+in)) * dt ))) ) ,  
            
            filterbanks(1, 64, saturator(l, dcblock(10,((z+in) + ((x+in) * (y+in) - beta * (z+in)) * dt ))) ) ,   

            ( ( z : peakHolder(peakS) : LPTPT(1) ) * 8.2), 
            ( ( y : peakHolder(peakS) : LPTPT(1) ) * 0.60),
            ( ( x : peakHolder(peakS) : LPTPT(1) ) * 0.001),
            ( ( z : peakHolder(peakS) : LPTPT(1) ) * 0.10);
    };

autolorenzR(in, dcfc, l, peakS, globalFB) = 
    ( loop : par(i, 7, _ / (globalFB)) ) ~ si.bus(7) : 
        par(i, 7, /(l * 2)) : (si.bus(3) :> _ / 3 : normalization(1) ), si.bus(4)
with {
        // saturator(lim,x) = lim * ma.tanh(x);
        saturator(lim,x) = lim*ma.tanh(x/(max(lim,ma.EPSILON)));
        dcblock(dcfc,x) = fi.highpass(1, dcfc, x);
        loop(x, y, z, sigma, dt, rho, beta) = 
 
            filterbanks(1, 64, saturator(l, dcblock(10,((x+in) + sigma * ((y+in) - (x+in)) * dt))) ) , 
            
            filterbanks(1, 64, saturator(l, dcblock(10,((y+in) + (rho * (x+in) - (x+in) * z - (y+in)) * dt ))) ) ,  
            
            filterbanks(1, 64, saturator(l, dcblock(10,((z+in) + ((x+in) * (y+in) - beta * (z+in)) * dt ))) ) ,   

            ( ( z : peakHolder(peakS) : LPTPT(1) ) * 8.0), 
            ( ( y : peakHolder(peakS) : LPTPT(1) ) * 0.62),
            ( ( x : peakHolder(peakS) : LPTPT(1) ) * 0.01),
            ( ( z : peakHolder(peakS) : LPTPT(1) ) * 0.10);
    };

process = _ <:  \(mic1, mic2).
    (
        autolorenzL(mic1, 10, Ktf, Fbf, Wtf), 
        autolorenzR(mic2, 10, Ktf, Fbf, Wtf)
    ) : 
        \(xyz1, sigma1, dt1, rho1, beta1, xyz2, sigma2, dt2, rho2, beta2).
            (xyz1, xyz2, sigma1, dt1, rho1, beta1, sigma2, dt2, rho2, beta2);