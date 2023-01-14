// import faust standard library
import("stdfaust.lib");
// import audible ecosystemics objects library
import("ritilib.lib");
// Import lists: Frequencies, Amps, Bandwidth
import("Cello_D2.lib");


// INSTRUMENT SPECTRES --------------------------------------
// index of the lists

// FlistCH1(index) = ba.take(index, Cello1_D2_frequencies) * FREQUENCYf ;
// AlistCH1(index) = ba.take(index, Cello1_D2_amplitudes)  * 1 ;
// QlistCH1(index) = ba.take(1,     Cello1_D2_bandwidths)  * BANDWIDTHf ;

// FlistCH1(index) = ba.take(index, Cello2_D2_frequencies) * FREQUENCYf ;
// AlistCH1(index) = ba.take(index, Cello2_D2_amplitudes)  * 1 ;
// QlistCH1(index) = ba.take(1,     Cello2_D2_bandwidths)  * BANDWIDTHf ;

// FlistCH1(index) = ba.take(index, Cello3_D2_frequencies) * FREQUENCYf ;
// AlistCH1(index) = ba.take(index, Cello3_D2_amplitudes)  * 1 ;
// QlistCH1(index) = ba.take(1,     Cello3_D2_bandwidths)  * BANDWIDTHf ;

// FlistCH1(index) = ba.take(index, Cello4_D2_frequencies) * FREQUENCYf ;
// AlistCH1(index) = ba.take(index, Cello4_D2_amplitudes)  * 1 ;
// QlistCH1(index) = ba.take(1,     Cello4_D2_bandwidths)  * BANDWIDTHf ;

// sliders for control the system
TANHf = ( hslider("TANH", 1, 1, 100, .001) ) : si.smoo;
FBf = 2 ^ hslider("EQ FEEDBACK", 0, -1, 1, .001) : si.smoo;
DTf = ( hslider("DT", 0.62, 0, 10, .001)) : si.smoo;
SIGMAf = ( hslider("SIGMA", 8.2, 0, 100, .001)) : si.smoo;
RHOf = ( hslider("RHO", 0.010, 0, .1, .001)) : si.smoo;
BETAf = ( hslider("BETA", 0.10, 0, 1, .001)) : si.smoo;
BANDWIDTHf = 10 ^ hslider("BANDWIDTH", 0, -1, 1, .001) : si.smoo;
FREQUENCYf = 16 ^ hslider("FREQUENCY", 0, -1, 1, .001) : si.smoo;
//process = BANDWIDTHf;

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
autolorenzL(in) = 
    ( loop : (( si.bus(3) : par(i, 3, _ * FBf) ), si.bus(4)) ) ~ si.bus(7) : 
        par(i, 7, /(TANHf * 2)) : (si.bus(3) :> _ / 3 : normalization(1) ), si.bus(4)
with {
        // saturator(lim,x) = lim*ma.tanh(x);
        saturator(lim,x) = lim * ma.tanh(x/(max(lim,ma.EPSILON)));
        dcblock(dcfc,x) = fi.highpass(1, dcfc, x);
        loop(x, y, z, sigma, dt, rho, beta) = 
 
            filterbank1(1, 32, saturator(TANHf, dcblock(10,((x+in) + sigma * ((y+in) - (x+in)) * dt))) ), 
            
            filterbank1(1, 32, saturator(TANHf, dcblock(10,((y+in) + (rho * (x+in) - (x+in) * z - (y+in)) * dt ))) ),  
            
            filterbank1(1, 32, saturator(TANHf, dcblock(10,((z+in) + ((x+in) * (y+in) - beta * (z+in)) * dt ))) ),   

            (SIGMAf), 
            (DTf),
            (RHOf),
            (BETAf);
    };

autolorenzR(in) = 
    ( loop : (( si.bus(3) : par(i, 3, _ * FBf) ), si.bus(4)) ) ~ si.bus(7) : 
        par(i, 7, /(TANHf * 2)) : (si.bus(3) :> _ / 3 : normalization(1) ), si.bus(4)
with {
        // saturator(lim,x) = lim * ma.tanh(x);
        saturator(lim,x) = lim*ma.tanh(x/(max(lim,ma.EPSILON)));
        dcblock(dcfc,x) = fi.highpass(1, dcfc, x);
        loop(x, y, z, sigma, dt, rho, beta) = 
 
            filterbank1(1, 32, saturator(TANHf, dcblock(10,((x+in) + sigma * ((y+in) - (x+in)) * dt))) ), 
            
            filterbank1(1, 32, saturator(TANHf, dcblock(10,((y+in) + (rho * (x+in) - (x+in) * z - (y+in)) * dt ))) ),  
            
            filterbank1(1, 32, saturator(TANHf, dcblock(10,((z+in) + ((x+in) * (y+in) - beta * (z+in)) * dt ))) ),   

            (SIGMAf), 
            (DTf),
            (RHOf),
            (BETAf);
    };

process = 
        ( autolorenzL(0.12-0.12'), 
          autolorenzR(0.74-0.74') ) :
        \(xyz1, sigma1, dt1, rho1, beta1, xyz2, sigma2, dt2, rho2, beta2).
            (xyz1, xyz2, sigma1, dt1, rho1, beta1, sigma2, dt2, rho2, beta2);
