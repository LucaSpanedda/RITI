// import faust standard library
import("stdfaust.lib");
// import audible ecosystemics objects library
import("RITI.lib");

// nonLinearSaturation = ( ( ( nonLinearity( ExponentFf, RefPeriodf, (Mic1 + Mic3) / 2 ) + 1 ) / 2 ) * NonLinearSaturationGain) : 
//             hgroup( "Mixer", hgroup( "Non Linear Saturation Gain", vmeter(100, 1, 10) ) );
//         NonLinearSaturationGain =
//             hgroup( "Mixer", 
//                 hgroup( "Non Linear Saturation Gain",  
//                     ( si.smoo( vslider("Non Linear Saturation Gain", 0, 0, 10, .001) ) )
//                 )
//             );

// cntrlMicSum = (1 - (( (Mic1, Mic2, Mic3, Mic4) :> + / 4 ) : peakHoldwDecay(.1, .1, 10) : _ * CntrlMicGain)) :
//             limit(1, 0);
//         CntrlMicGain =  
//             hgroup( "Mixer", 
//                 hgroup( "Automated Control Gain",  
//                     ( si.smoo( ba.db2linear( vslider("Automated Control Gain [unit:db]", -80, -80, 80, .001) ) ) <:
//                         attach(_, VHmetersEnvelope(_) :vbargraph("VMACG [unit:dB]", -80, 80 ) ) )
//                 )
//             );

// SYSTEM VARIABLES ----------------------------------------
SystemSpaceVar = meterstoSamps(10);
BPFOrder = 1;
BPFilters = 32;
NetworkVoices = 4;
InitDCBlockzero = 1;
InitDCBlockpole = 0.995;
InitX0 = 1.2;
InitY0 = 1.3;
InitZ0 = 1.6;

// SYSTEM CONTROLS ----------------------------------------
Dtf = ( hslider("Dt", 0.62, 0, 1, .001)) : si.smoo;
Sigmaf = ( hslider("Sigma", 8.2, 0, 100, .001)) : si.smoo;
Rhof = ( hslider("Rho", 0.010, 0, .1, .001)) : si.smoo;
Betaf = ( hslider("Beta", 0.10, 0, 10, .001)) : si.smoo;
LorenzFeedbackf = hslider("Lorenz Feedback", 10, 0, 10, .001) : si.smoo;
NetworkFeedbackf = hslider("Network Feedback", 10, 0, 10, .001) : si.smoo;
ExponentFf = hslider("NonLinear Signals Exponent", 1, 1, 96, .001) : si.smoo;
RefPeriodf = 100 ^ hslider("NonLinear Signals Period", 0, -1, 1, .001) : si.smoo;
GlobalBPBWf = 10 ^ hslider("Global Bandwidth", 0, -1, 1, .001) : si.smoo;
GlobalBPFrequenciesf = 16 ^ hslider("Global Frequency", 0, -1, 1, .001) : si.smoo;
Interpolations1f = si.smoo( hslider("Interpolations 1", 0, 0, 1, .001) );
Interpolations2f = si.smoo( hslider("Interpolations 2", 0, 0, 1, .001) );
BPFilterBypassf = ( hslider("BP Filter Bypass", 0, 0, 1, .001)) : si.smoo;
Saturationf = ( hslider("Saturation", 0, 0, 1, .001)) : si.smoo;
OutputGainf =  
            hgroup( "Mixer", 
                hgroup( "Global Output Gain",  
                    ( si.smoo( ba.db2linear( vslider("Global Output Gain [unit:db]", 0, -80, 80, .001) ) ) <:
                        attach(_, VHmetersEnvelope(_) :vbargraph("VMGOG [unit:dB]", -80, 80 ) ) )
                )
            );

// MODIFIED LORENZ SYSTEM ----------------------------------------
ModifiedLorenzSystem(x0, y0, z0, dt, beta, rho, sigma, bypassFilter, filterPartials, filterOrder, globalFreq, globalAmps, globalBW, interpolation1, interpolation2, saturation, dcBlockzero, dcBlockpole, internalFeedback, externalInput) = 
ModifiedLorenzEquations ~ si.bus(3) : par(i, 3, /(saturation + 1)) :> _ / 3
    with {
        x_init = x0-x0';    y_init = y0-y0';    z_init = z0-z0';

        ModifiedLorenzEquations(x, y, z) = 
            (( (externalInput / 3) + x + sigma * (y - x) * dt + x_init) : dcblocker(dcBlockzero, dcBlockpole) : saturator(saturation + 1) : 
            BandpassFiltersBank(bypassFilter, filterPartials, filterOrder, globalFreq, globalAmps, globalBW, interpolation1, interpolation2)) * internalFeedback, 

            (( (externalInput / 3) + y + (rho * x - x * z - y) * dt + y_init) : dcblocker(dcBlockzero, dcBlockpole) : saturator(saturation + 1) : 
            BandpassFiltersBank(bypassFilter, filterPartials, filterOrder, globalFreq, globalAmps, globalBW, interpolation1, interpolation2)) * internalFeedback, 

            (( (externalInput / 3) + z + (x * y - beta * z) * dt + z_init) : dcblocker(dcBlockzero, dcBlockpole) : saturator(saturation + 1) : 
            BandpassFiltersBank(bypassFilter, filterPartials, filterOrder, globalFreq, globalAmps, globalBW, interpolation1, interpolation2)) * internalFeedback;
    };

// GLOBAL SYSTEM NETWORK ----------------------------------------
GlobalSystemNetwork(dt, beta, rho, sigma, bpFilterBypass, globalBPFrequencies, globalBPBW, interpolations1, interpolations2, saturation, internalFeedback, networkOutputGain, Mic1, Mic2, Mic3, Mic4) = ( loop ~ _ : (si.block(1), si.bus(NetworkVoices)) ) : 
    par( i, NetworkVoices, _ : normalization(1) ) : par( i, NetworkVoices, _ * networkOutputGain )
    with{
        loop(networkFeedback) =  par(i,  NetworkVoices,
                        ( 
                            ModifiedLorenzSystem(InitX0, InitY0, InitZ0, dt, beta, rho, sigma, bpFilterBypass, BPFilters, BPFOrder, globalBPFrequencies, 1, globalBPBW, interpolations1, interpolations2, saturation, InitDCBlockzero, InitDCBlockpole, internalFeedback,
                            ((networkFeedback * NetworkFeedbackf)  @ (SystemSpaceVar * (i + 1)))
                            ) 
                        )

                    ) <: (si.bus(NetworkVoices) :> +/NetworkVoices), (si.bus(NetworkVoices));
        };
              
process = Dtf, Betaf, Rhof, Sigmaf, BPFilterBypassf, GlobalBPFrequenciesf, GlobalBPBWf, Interpolations1f, Interpolations2f, Saturationf, LorenzFeedbackf, OutputGainf,
( (_,_) : \(m1,m2).(m1, m2, m1@(meterstoSamps(2.0432)), m2@(meterstoSamps(2.4132))) )
: GlobalSystemNetwork;