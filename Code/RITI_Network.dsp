// import faust standard library
import("stdfaust.lib");
// import audible ecosystemics objects library
import("RITI.lib");


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
RoomInterfaceNetwork(Mic1, Mic2, Mic3, Mic4) = Dtf, Betaf * 10, Rhof * .1, Sigmaf * 100, BPFilterBypassf, GlobalBPFrequenciesf, GlobalBPBWf, Interpolations1f, Interpolations2f, Saturationf * 10, LorenzFeedbackf, NetworkFeedbackf, OutputGainf, Mic1, Mic2, Mic1@(meterstoSamps(2.0432)), Mic2@(meterstoSamps(2.4132))
with {
    Dtf = ( ( ( nonLinearity(NonLinearExponentf, NonLinearPeriodf, (Mic1@ma.SR + Mic3) / 2 ) + 1 ) / 2 ) * NonLinearGainf) + DTGain : 
            hgroup( "Mixer", hgroup( "DT Gain", vmeter(110, 0, 1) ) ) ;
        DTGain =
            hgroup( "Mixer", 
                hgroup( "DT Gain Gain",  
                    ( si.smoo( vslider("DT Gain", 0.62, 0, 1, .001) ) )
                )
            );
    Sigmaf = ( ( ( nonLinearity(NonLinearExponentf, NonLinearPeriodf, (Mic1@ma.SR + Mic3) / 2 ) + 1 ) / 2 ) * NonLinearGainf) + SigmaGain : 
            hgroup( "Mixer", hgroup( "Sigma Gain", vmeter(111, 0, 1) ) ) ;
        SigmaGain =
            hgroup( "Mixer", 
                hgroup( "Sigma Gain",  
                    ( si.smoo( vslider("Sigma Gain", 8.2/100, 0, 1, .001) ) )
                )
            );
    Rhof = ( ( ( nonLinearity(NonLinearExponentf, NonLinearPeriodf, (Mic1@ma.SR + Mic3) / 2 ) + 1 ) / 2 ) * NonLinearGainf) + RhoGain : 
            hgroup( "Mixer", hgroup( "Rho Gain", vmeter(112, 0, 1) ) ) ;
        RhoGain =
            hgroup( "Mixer", 
                hgroup( "Rho Gain",  
                    ( si.smoo( vslider("Rho Gain", .10, 0, 1, .001) ) )
                )
            );
    Betaf = ( ( ( nonLinearity(NonLinearExponentf, NonLinearPeriodf, (Mic1@ma.SR + Mic3) / 2 ) + 1 ) / 2 ) * NonLinearGainf) + BetaGain : 
            hgroup( "Mixer", hgroup( "Beta Gain", vmeter(113, 0, 1) ) ) ;
        BetaGain =
            hgroup( "Mixer", 
                hgroup( "Beta Gain",  
                    ( si.smoo( vslider("Beta Gain", .10/10, 0, 1, .001) ) )
                )
            );
    LorenzFeedbackf = hslider("Lorenz Feedback", 10, 0, 10, .001) : si.smoo;
    NetworkFeedbackf = hslider("Network Feedback", 10, 0, 10, .001) : si.smoo;
    NonLinearExponentf = hslider("NonLinear Signals Exponent", 1, 1, 96, .001) : si.smoo;
    NonLinearPeriodf = 100 ^ hslider("NonLinear Signals Period", 0, -1, 1, .001) : si.smoo;
    NonLinearGainf = hslider("NonLinear Signals Amp", 0, 0, 1, .001) : si.smoo;
    GlobalBPBWf = 10 ^ hslider("Global Bandwidth", 0, -1, 1, .001) : si.smoo;
    GlobalBPFrequenciesf = 16 ^ hslider("Global Frequency", 0, -1, 1, .001) : si.smoo;
    Interpolations1f = Interpolations1Gain : 
            hgroup( "Mixer", hgroup( "Interpolations 1 Gain", vmeter(101, 0, 1) ) ) ;
        Interpolations1Gain =
            hgroup( "Mixer", 
                hgroup( "Interpolations 1 Gain",  
                    ( si.smoo( vslider("Interpolations 1 Gain", 0, 0, 1, .001) ) )
                )
            );
    Interpolations2f = Interpolations2Gain : 
            hgroup( "Mixer", hgroup( "Interpolations 2 Gain", vmeter(102, 0, 1) ) );
        Interpolations2Gain =
            hgroup( "Mixer", 
                hgroup( "Interpolations 2 Gain",  
                    ( si.smoo( vslider("Interpolations 2 Gain", 0, 0, 1, .001) ) )
                )
            );
    BPFilterBypassf = BPFilterBypassGain : 
            hgroup( "Mixer", hgroup( "BP Filter Bypass", vmeter(103, 0, 1) ) );
        BPFilterBypassGain =
            hgroup( "Mixer", 
                hgroup( "BP Filter Bypass",  
                    ( si.smoo( vslider("BP Filter Bypass", 0, 0, 1, .001) ) )
                )
            );
    Saturationf = ( ( ( nonLinearity( NonLinearExponentf, NonLinearPeriodf, (Mic1 + Mic3) / 2 ) + 1 ) / 2 ) * NonLinearGainf) + NonLinearSaturationGain : 
            hgroup( "Mixer", hgroup( "Non Linear Saturation Gain", vmeter(100, 0, 1) ) );
        NonLinearSaturationGain =
            hgroup( "Mixer", 
                hgroup( "Non Linear Saturation Gain",  
                    ( si.smoo( vslider("Non Linear Saturation Gain", 0, 0, 1, .001) ) )
                )
            );
    OutputGainf = ( ( ( nonLinearity( NonLinearExponentf, NonLinearPeriodf, (Mic1 + Mic3) / 2 ) + 1 ) / 2 ) * NonLinearGainf) + NonLinearGlobalOutGain : 
            hgroup( "Mixer", hgroup( "Non Linear Global Output Gain", vmeter(105, 0, 1) ) );
        NonLinearGlobalOutGain =
            hgroup( "Mixer", 
                hgroup( "Non Linear Global Output Gain",  
                    ( si.smoo( vslider("Non Linear Global Output Gain", 0, 0, 1, .001) ) )
                )
            );
};

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
GlobalSystemNetwork(dt, beta, rho, sigma, bpFilterBypass, globalBPFrequencies, globalBPBW, interpolations1, interpolations2, saturation, internalFeedback,
networkFeedback, networkOutputGain, Mic1, Mic2, Mic3, Mic4) = ( loop ~ _ : (si.block(1), si.bus(NetworkVoices)) ) : 
    par( i, NetworkVoices, _ : normalization(1) ) : par( i, NetworkVoices, _ * networkOutputGain )
    with{
        loop(networkFeedback) =  par(i,  NetworkVoices,
                        ( 
                            ModifiedLorenzSystem(InitX0, InitY0, InitZ0, dt, beta, rho, sigma, bpFilterBypass, BPFilters, BPFOrder, globalBPFrequencies, 1, globalBPBW, interpolations1, interpolations2, saturation, InitDCBlockzero, InitDCBlockpole, internalFeedback,
                            ((networkFeedback * networkFeedback)  @ (SystemSpaceVar * (i + 1)))
                            ) 
                        )

                    ) <: (si.bus(NetworkVoices) :> +/NetworkVoices), (si.bus(NetworkVoices));
        };
              
process = RoomInterfaceNetwork : GlobalSystemNetwork;
