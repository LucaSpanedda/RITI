// import faust standard library
import("stdfaust.lib");
// import audible ecosystemics objects library
import("RITI.lib");


// SYSTEM VARIABLES ----------------------------------------
DelSecondsMax = 12;
SystemSpaceVarOUT = 2.8713;
SystemSpaceVarIN =  2.3132;
BPFOrder = 1;
BPFilters = 32;
NetworkVoices = 4;
InitDCBlockzero = 1;
InitDCBlockpole = 0.995;
InitX0 = 1.2;
InitY0 = 1.3;
InitZ0 = 1.6;

// SYSTEM CONTROLS ----------------------------------------
RoomInterfaceNetwork(Mic1, Mic2, Mic3, Mic4) = 
hgroup( "RITI Mixer", 
    hgroup( "Lorenz Equation Parameters[0]", Dtf, Betaf, Rhof, Sigmaf), 
    hgroup( "Bandpass Filters Bank [1]", BPFilterBypassf, GlobalBPFrequenciesf, GlobalBPBWf, Interpolations1f, Interpolations2f), 
    hgroup( "Amplificators [2]", Saturationf, LorenzFeedbackf, NetworkFeedbackf),
    hgroup( "Input/Output [3]", ExternalInputGainf, OutputGainf, MicsOutputf)
)
with {
    Dtf = (vslider("Dt", 0.62, 0, 1, .001)) : onepoletau(.5);
    Sigmaf = (vslider("Sigma", 8.2, 0, 100, .001)) : onepoletau(.5);
    Rhof = (vslider("Rho", 0.010, 0, .1, .001)) : onepoletau(.5);
    Betaf = (vslider("Beta", 0.10, 0, 10, .001)) : onepoletau(.5);
    BPFilterBypassf = (vslider("BP Bypass", 0, 0, .1, .001)) : onepoletau(.5);
    GlobalBPFrequenciesf = (16 ^ vslider("Frequency", 0, -1, 1, .001)) : onepoletau(.5);
    GlobalBPBWf = (vslider("Bandwidth", 1, 1, 100, .001)) : onepoletau(.5);
    Interpolations1f = (vslider("Interpolations 1", 1, 0, 1, .001)) : onepoletau(.5);
    Interpolations2f = (vslider("Interpolations 2", 1, 0, 1, .001)) : onepoletau(.5);
    Saturationf = (vslider("Lorenz Tan", 0, 0, 10, .001)) : onepoletau(.5);
    LorenzFeedbackf = (10 ^ vslider("Lorenz FB", 0, -1, 1, .001)) : onepoletau(.5); 
    NetworkFeedbackf = (10 ^ vslider("Network FB", 0, -1, 1, .001)) : onepoletau(.5); 
    OutputGainf = (vslider("Master", 0, 0, 1, .001)) : onepoletau(.5);
    ExternalInputGainf = (vslider("External Sum", 0, 0, 100, .001)) : onepoletau(.5);
    MicsOutputf = (Mic1, Mic2, Mic3, Mic4) :> _ / 4;
};

// MODIFIED LORENZ SYSTEM ----------------------------------------
ModifiedLorenzSystem(x0, y0, z0, dt, beta, rho, sigma, bypassFilter, filterPartials, filterOrder, globalFreq, globalAmps, globalBW, interpolation1, interpolation2, saturation, dcBlockzero, dcBlockpole, internalFeedback, externalInput) = 
externalInput : (ModifiedLorenzEquations ~ si.bus(3) : par(i, 3, /(saturation + 1)) :> _ / 3)
    with {
        x_init = x0-x0';    y_init = y0-y0';    z_init = z0-z0';

        ModifiedLorenzEquations(x, y, z, external) = 
            ( (( x + sigma * (y - x) * dt + x_init) * internalFeedback + external ) : dcblocker(dcBlockzero, dcBlockpole) : saturator(saturation + 1) : 
            BandpassFiltersBank(bypassFilter, filterPartials, filterOrder, globalFreq, globalAmps, globalBW, interpolation1, interpolation2)), 

            ( (( y + (rho * x - x * z - y) * dt + y_init) * internalFeedback + external ) : dcblocker(dcBlockzero, dcBlockpole) : saturator(saturation + 1) : 
            BandpassFiltersBank(bypassFilter, filterPartials, filterOrder, globalFreq, globalAmps, globalBW, interpolation1, interpolation2)), 

            ( (( z + (x * y - beta * z) * dt + z_init) * internalFeedback + external ) : dcblocker(dcBlockzero, dcBlockpole) : saturator(saturation + 1) : 
            BandpassFiltersBank(bypassFilter, filterPartials, filterOrder, globalFreq, globalAmps, globalBW, interpolation1, interpolation2));
    };

// GLOBAL SYSTEM NETWORK ----------------------------------------
GlobalSystemNetwork(dt, beta, rho, sigma, bpFilterBypass, globalBPFrequencies, globalBPBW, interpolations1, interpolations2, saturation, lorenzFeedback,
networkFeedbackGain, externalInputGain, networkOutputGain, micsOutput) = ( loop ~ _ : (si.block(1), si.bus(NetworkVoices)) ) : 
    par( i, NetworkVoices, _ : normalization(1) ) : par( i, NetworkVoices, _ * networkOutputGain )
    with{
        loop(networkFeedback) =  par(i,  NetworkVoices,
                        ( 
                            ((networkFeedback * networkFeedbackGain) + ( micsOutput * externalInputGain )) : timeVaryingDelay(SystemSpaceVarIN * (NetworkVoices - i), 0) : ModifiedLorenzSystem(InitX0, InitY0, InitZ0, dt, beta, rho, sigma, bpFilterBypass, BPFilters, BPFOrder, globalBPFrequencies, 1, globalBPBW, interpolations1, interpolations2, saturation, InitDCBlockzero, InitDCBlockpole, lorenzFeedback) : timeVaryingDelay(SystemSpaceVarOUT * (i + 1), 0) 
                        )
                    ) <: (si.bus(NetworkVoices) :> +/NetworkVoices), (si.bus(NetworkVoices));
        };
           
              
process = si.bus(8) :> si.bus(4) : RoomInterfaceNetwork : GlobalSystemNetwork;