// Faust standard libraries
import("stdfaust.lib");

Ktf = ( hslider("Tangent", 1, 1, 100, .001) ) : si.smoo;
Fbf = ( hslider("Feedback", 1, -1, 1, .001) + 1)/2 : si.smoo;


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
autolorenzL(in, dcfc, l) = 
    ( loop : par(i, 7, _/(Fbf)) ) ~ si.bus(7) : 
    par(i, 7, /(l * 2)): mixer
with {
        // saturator(lim,x) = lim*ma.tanh(x);
        saturator(lim,x) = lim * ma.tanh(x/(max(lim,ma.EPSILON)));
        dcblock(dcfc,x) = fi.highpass(1, dcfc, x);
        loop(x, y, z, sigma, dt, rho, beta) = 
 
            filterbanks(1, 64, saturator(l, dcblock(10,((x+in) + sigma * ((y+in) - (x+in)) * dt))) ) , 
            
            filterbanks(1, 64, saturator(l, dcblock(10,((y+in) + (rho * (x+in) - (x+in) * z - (y+in)) * dt ))) ) ,  
            
            filterbanks(1, 64, saturator(l, dcblock(10,((z+in) + ((x+in) * (y+in) - beta * (z+in)) * dt ))) ) ,   

            (((x+y+z)/3 : ba.ba.peakholder(64))*8.2), 
            (((x+y+z)/3 : ba.ba.peakholder(64))*0.60),
            (((x+y+z)/3 : ba.ba.peakholder(64))*0.001),
            (((x+y+z)/3 : ba.ba.peakholder(64))*0.10);
        mixer(a,b,c,d,e,f,g) = (a+b+c)/3;
    };

autolorenzR(in, dcfc, l) = 
    ( loop : par(i, 7, _/(Fbf)) ) ~ si.bus(7) : 
    par(i, 7, /(l * 2)): mixer
with {
        // saturator(lim,x) = lim * ma.tanh(x);
        saturator(lim,x) = lim*ma.tanh(x/(max(lim,ma.EPSILON)));
        dcblock(dcfc,x) = fi.highpass(1, dcfc, x);
        loop(x, y, z, sigma, dt, rho, beta) = 
 
            filterbanks(1, 64, saturator(l, dcblock(10,((x+in) + sigma * ((y+in) - (x+in)) * dt))) ) , 
            
            filterbanks(1, 64, saturator(l, dcblock(10,((y+in) + (rho * (x+in) - (x+in) * z - (y+in)) * dt ))) ) ,  
            
            filterbanks(1, 64, saturator(l, dcblock(10,((z+in) + ((x+in) * (y+in) - beta * (z+in)) * dt ))) ) ,   

            (((x+y+z)/3 : ba.ba.peakholder(64))*8.0), 
            (((x+y+z)/3 : ba.ba.peakholder(64))*0.62),
            (((x+y+z)/3 : ba.ba.peakholder(64))*0.001),
            (((x+y+z)/3 : ba.ba.peakholder(64))*0.10);
        mixer(a,b,c,d,e,f,g) = (a+b+c)/3;
    };

chain(gainin,gainout) = (_*gainin <: autolorenzL(_,10,Ktf)*gainout), (_*gainin <: autolorenzR(_,10,Ktf)*gainout)@ma.SR;

process = chain(1,1);