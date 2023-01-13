// import faust standard library
import("stdfaust.lib");
// import audible ecosystemics objects library
import("ritilib.lib");
// Import lists: Frequencies, Amps, Bandwidth
import("Cello_D2.lib");


// SYSTEM VARIABLES ----------------------------------------
SystemSpaceVar = meterstoSamps(10);
FilterOrder = 1;
FilterPartials = 32;
Voices = 4;

NonLFreq = hslider("Nonlinearities Frequency", .1, 0., 1, .001) : si.smoo;
NonLAmps = hslider("Nonlinearities Amplitude", 0., 0., 1, .001) : si.smoo;
// process = ( _ <: (BIpolarnonlinearity(NonLFreq, 1, 100, NonLAmps), _) ), 
//     ( _ <: (BIpolarnonlinearity(NonLFreq, 1, 100, NonLAmps), _) );

// Filterbanks Controls
DT1Interpolations = si.smoo( hslider("DT1Interpolations", 0, 0, 1, .001) );
DT2Interpolations = si.smoo( hslider("DT2Interpolations", 0, 0, 1, .001) );
BANDWIDTHf = 10 ^ hslider("BANDWIDTH", 0, -1, 1, .001) : si.smoo;
FREQUENCYf = 16 ^ hslider("FREQUENCY", 0, -1, 1, .001) : si.smoo;

FBf = hslider("Network Feedback / Lorenz Feedback", 10, 0, 10, .001) : si.smoo;
NetworkGlobalFBGain = 10 - FBf;
MicsGain = hslider("MicsGain",0,0,1000,.001) : si.smoo;
FreqShift = hslider("FreqShift",1,0.001,2,.001) : si.smoo;
Bandwidth = hslider("Bandwidth",1,1,10,.001) : si.smoo;
SingleUnitInternalFBGain = hslider("SingleUnitInternalFBGain", 1, 0, 1, .001): si.smoo;
MUf = hslider("mu", .08, 0.01, 1.0, .001);
TANHf = ( hslider("TANH", 1, 1, 100, .001) ) : si.smoo;
DTf = ( hslider("DT", 0.62, 0, 1, .001)) : si.smoo;
SIGMAf = ( hslider("SIGMA", 8.2, 0, 100, .001)) : si.smoo;
RHOf = ( hslider("RHO", 0.010, 0, .1, .001)) : si.smoo;
BETAf = ( hslider("BETA", 0.10, 0, 10, .001)) : si.smoo;

DIRECTEQUATIONSf = ( hslider("DIRECTEQUATIONS", 0, 0, 1, .001)) : si.smoo;
FILTEREDf = 1 - DIRECTEQUATIONSf;

// Spectre BP Filter Banks
BandpassFiltersBank(x) = x <: 
    par(i, FilterPartials, 
        seq(r, FilterOrder, 
            BPSVF( 
                AmplitudesListinterpolate(  (i + 1), DT1Interpolations, DT2Interpolations), 
                BandwidthsListinterpolate(  (i + 1), DT1Interpolations, DT2Interpolations) * BANDWIDTHf, 
                FrequenciesListinterpolate( (i + 1), DT1Interpolations, DT2Interpolations) * FREQUENCYf
            ) 
        )
    ):> (+/FilterPartials) * FILTEREDf + x * DIRECTEQUATIONSf;

lorenz(a,b,c,d) = loop ~ si.bus(3) : par(i, 3, /(TANHf)) :> _/3
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
        dt = DTf;
        beta = BETAf;
        rho = RHOf;
        sigma = SIGMAf;
        loop(x, y, z) = 
        ((a+x + sigma * (y - x) * dt + x_init) : dcblocker(1, 0.995) : saturator(TANHf) : BandpassFiltersBank) * FBf, 
        ((b+y + (rho * x - x * z - y) * dt + y_init) : dcblocker(1, 0.995) : saturator(TANHf) : BandpassFiltersBank) * FBf, 
        ((c+z + (x * y - beta * z) * dt + z_init) : dcblocker(1, 0.995) : saturator(TANHf) : BandpassFiltersBank) * FBf;
    };

Network(NetV, Mic1, Mic2, Mic3, Mic4) = ( loop ~ _ : (si.block(1), si.bus(NetV)) ) : 
    par(i, Voices, _ : normalization(1)) : par(i, Voices, _ * OutputGain * cntrlMicSum)
    with{
        loop(fb) =  par(i,  NetV,
                        ( ((Mic1/NetV) * MicsGain) + ((fb * NetworkGlobalFBGain)@(SystemSpaceVar*(i+1))) <:
                           lorenz)
                    ) <: (si.bus(NetV) :> +/NetV), (si.bus(NetV));

        cntrlMicSum = (1 - ((Mic1, Mic2, Mic3, Mic4) :> _ : peakHoldwDecay(.01, 10) : _ * CntrlMicGain)) :
            limit(1, 0);

        OutputGain =  
            hgroup( "Mixer", 
                hgroup( "Global Output Gain",  
                    ( si.smoo( ba.db2linear( vslider("Global Output Gain [unit:db]", 0, -80, 80, .001) ) ) <:
                        attach(_, VHmetersEnvelope(_) :vbargraph("VMGOG [unit:dB]", -80, 80 ) ) )
                )
            );
        CntrlMicGain =  
            hgroup( "Mixer", 
                hgroup( "Automated Control Gain",  
                    ( si.smoo( ba.db2linear( vslider("Automated Control Gain [unit:db]", -80, -80, 80, .001) ) ) <:
                        attach(_, VHmetersEnvelope(_) :vbargraph("VMACG [unit:dB]", -80, 80 ) ) )
                )
            );
        };
              
process = (_,_) : \(m1,m2).(m1, m2, m1@(meterstoSamps(2.0432)), m2@(meterstoSamps(2.4132))) : Network(Voices);
