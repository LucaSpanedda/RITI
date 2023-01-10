// import faust standard library
import("stdfaust.lib");
// import audible ecosystemics objects library
import("ritilib.lib");
// Import lists: Frequencies, Amps, Bandwidth
import("Cello_D2.lib");


// SYSTEM VARIABLES ----------------------------------------
FilterOrder = 1;
FilterPartials = 32;
Voices = 4;
SystemSpaceVar = 1 * ma.SR;

FBf = hslider("Network Feedback / Lorenz Feedback", 10, 0, 10, .001) : si.smoo;
NetworkGlobalFBGain = 10 - FBf;
ExternalSigGain = hslider("ExternalSigGain",0,0,1000,.001) : si.smoo;
FreqShift = hslider("FreqShift",1,0.001,2,.001) : si.smoo;
Bandwidth = hslider("Bandwidth",1,1,10,.001) : si.smoo;
SingleUnitInternalFBGain = hslider("SingleUnitInternalFBGain", 1, 0, 1, .001): si.smoo;
MUf = hslider("mu", .08, 0.01, 1.0, .001);
OutputGain = hslider("OutputGain",1,0,1,.001) : si.smoo;
TANHf = ( hslider("TANH", 1, 1, 100, .001) ) : si.smoo;
DTf = ( hslider("DT", 0.62, 0, 1, .001)) : si.smoo;
SIGMAf = ( hslider("SIGMA", 8.2, 0, 100, .001)) : si.smoo;
RHOf = ( hslider("RHO", 0.010, 0, .1, .001)) : si.smoo;
BETAf = ( hslider("BETA", 0.10, 0, 10, .001)) : si.smoo;
BANDWIDTHf = 10 ^ hslider("BANDWIDTH", 0, -1, 1, .001) : si.smoo;
FREQUENCYf = 16 ^ hslider("FREQUENCY", 0, -1, 1, .001) : si.smoo;
DIRECTEQUATIONSf = ( hslider("DIRECTEQUATIONS", 0, 0, 1, .001)) : si.smoo;
FILTEREDf = 1 - DIRECTEQUATIONSf;

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
BandpassFiltersBank(x) = x <: 
    par(i, FilterPartials, 
        seq(r, FilterOrder, 
            BPSVF( 
                AmplitudesListinterpolate(i + 1), 
                BandwidthsListinterpolate(i + 1), 
                FrequenciesListinterpolate(i + 1) 
            ) 
        )
    ):> (+/FilterPartials) * FILTEREDf + x * DIRECTEQUATIONSf;

lorenz(a,b,c) = loop ~ si.bus(3) : par(i, 3, /(TANHf)) :> _/3
    with {
        x0 = 1.2;
        y0 = 1.3;
        z0 = 1.6;
        x_init = x0-x0';
        y_init = y0-y0';
        z_init = z0-z0';
        saturator(lim, x) = lim * ma.tanh( x / ( max(lim, ma.EPSILON) ) );
        dcblocker(zero,pole,x) = x : dcblockerout
        with{
            onezero =  _ <: _,mem : _,*(zero) : -;
            onepole = + ~ *(pole);
            dcblockerout = _ : onezero : onepole;
        };
        dt = 1;
        beta = BETAf;
        rho = RHOf;
        sigma = SIGMAf;
        loop(x, y, z) = 
        ((a+x + sigma * (y - x) * dt + x_init) : dcblocker(1, 0.995) : saturator(TANHf) : BandpassFiltersBank) * FBf, 
        ((b+y + (rho * x - x * z - y) * dt + y_init) : dcblocker(1, 0.995) : saturator(TANHf) : BandpassFiltersBank) * FBf, 
        ((c+z + (x * y - beta * z) * dt + z_init) : dcblocker(1, 0.995) : saturator(TANHf) : BandpassFiltersBank) * FBf;
    };

Network(NetV,ExternalSig) = loop ~ _ : (si.block(1), si.bus(NetV))
    with{
        loop(fb) =  par(i,  NetV,
                        ( ((ExternalSig/NetV) * ExternalSigGain) + ((fb * NetworkGlobalFBGain)@(SystemSpaceVar*(i+1))) <:
                           lorenz)
                    ) <: (si.bus(NetV) :> +/NetV), (si.bus(NetV));
        };
        
process = _ : fi.dcblocker : Network(Voices) : par(i, Voices, _ : normalization(1) * OutputGain);
