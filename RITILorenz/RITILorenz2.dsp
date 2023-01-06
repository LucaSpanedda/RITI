// import faust standard library
import("stdfaust.lib");
// import audible ecosystemics objects library
import("ritilib.lib");
// Import lists: Frequencies, Amps, Bandwidth
import("Cello_D2.lib");
// import list example:
// chunk3_ch1_Cello_D2_frequencies
// chunk3_ch1_Cello_D2_amplitudes
// chunk3_ch1_Cello_D2_bandwidths


// INSTRUMENT SPECTRE --------------------------------------
// index of the lists
FlistCH1(index) = ba.take(index, chunk3_ch1_Cello_D2_frequencies) * 1 ;
AlistCH1(index) = ba.take(index, chunk3_ch1_Cello_D2_amplitudes)  * 1 ;
QlistCH1(index) = ba.take(1,     chunk3_ch1_Cello_D2_bandwidths)  * 1 ;
// process = Flist(11), Flist(11), BWlist(11);

// sliders for control the system
Ktf = ( hslider("Tangent", 1, 1, 100, .001) ) : si.smoo;
Fbf = ( hslider("Feedback", 1, -.990, 1, .001) + 1)/2 : si.smoo;
Wtf = hslider("Peak Window Seconds", .1, .001, 1, .001) : si.smoo;

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

// Spectre BP Filter Banks
filterbank1(cascade, parallel, x) = 
    x <: par(i, parallel,
            seq(r, cascade, 
                BPSVF( AlistCH1(i + 1), QlistCH1(i + 1), FlistCH1(i + 1) ) 
                )
            ):> (+/parallel);


// Autoregulating Lorenz System
autolorenzL(in, dcfc, l, peakS, globalFB) = 
    ( loop : par(i, 7, _ / (globalFB)) ) ~ si.bus(7) : 
        par(i, 7, /(l * 2)) : (si.bus(3) :> _ / 3 : normalization(1) ), si.bus(4)
with {
        // saturator(lim,x) = lim*ma.tanh(x);
        saturator(lim,x) = lim * ma.tanh(x/(max(lim,ma.EPSILON)));
        dcblock(dcfc,x) = fi.highpass(1, dcfc, x);
        loop(x, y, z, sigma, dt, rho, beta) = 
 
            filterbank1(1, 128, saturator(l, dcblock(10,((x+in) + sigma * ((y+in) - (x+in)) * dt))) ) , 
            
            filterbank1(1, 128, saturator(l, dcblock(10,((y+in) + (rho * (x+in) - (x+in) * z - (y+in)) * dt ))) ) ,  
            
            filterbank1(1, 128, saturator(l, dcblock(10,((z+in) + ((x+in) * (y+in) - beta * (z+in)) * dt ))) ) ,   

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
 
            filterbank1(1, 128, saturator(l, dcblock(10,((x+in) + sigma * ((y+in) - (x+in)) * dt))) ) , 
            
            filterbank1(1, 128, saturator(l, dcblock(10,((y+in) + (rho * (x+in) - (x+in) * z - (y+in)) * dt ))) ) ,  
            
            filterbank1(1, 128, saturator(l, dcblock(10,((z+in) + ((x+in) * (y+in) - beta * (z+in)) * dt ))) ) ,   

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