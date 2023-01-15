// import faust standard library
import("stdfaust.lib");
// import audible ecosystemics objects library
import("RITI.lib");


// SYSTEM VARIABLES ----------------------------------------
SystemSpaceVar = 4;
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
    hgroup( "Lorenz Equation Parameters[1]", Dtf, Betaf, Rhof, Sigmaf), 
    hgroup( "Bandpass Filters Bank [2]", BPFilterBypassf, GlobalBPFrequenciesf, GlobalBPBWf, Interpolations1f, Interpolations2f), 
    hgroup( "Amplificators [3]", Saturationf, LorenzFeedbackf, NetworkFeedbackf),
    hgroup( "Output [4]", RescaleOutputf, OutputGainf)
)
with {
    Dtf = si.smoo(vslider("Dt", 0.62, 0, 1, .001));
    Sigmaf = si.smoo(vslider("Sigma", 8.2, 0, 100, .001));
    Rhof = si.smoo(vslider("Rho", 0.010, 0, .1, .001));
    Betaf = si.smoo(vslider("Beta", 0.10, 0, 10, .001));
    BPFilterBypassf = si.smoo(vslider("BP Bypass", 0, 0, 1, .001));
    GlobalBPFrequenciesf = si.smoo(16 ^ vslider("Frequency", 0, -1, 1, .001));
    GlobalBPBWf = si.smoo(vslider("Bandwidth", 1, 1, 100, .001));
    Interpolations1f = si.smoo(vslider("Interpolations 1", 1, 0, 1, .001));
    Interpolations2f = si.smoo(vslider("Interpolations 2", 1, 0, 1, .001));
    Saturationf = si.smoo(vslider("Lorenz Tan", 0, 0, 10, .001));
    LorenzFeedbackf = si.smoo(10 ^ vslider("Lorenz FB", 0, -1, 1, .001)); 
    NetworkFeedbackf = si.smoo(vslider("Network FB", 1, 0, 1, .001));
    OutputGainf = si.smoo(vslider("Master", 0, 0, 1, .001));
    RescaleOutputf = si.smoo(vslider("Rescale", 1, 1, 100, .001));
};

// MODIFIED LORENZ SYSTEM ----------------------------------------
ModifiedLorenzSystem(x0, y0, z0, dt, beta, rho, sigma, bypassFilter, filterPartials, filterOrder, globalFreq, globalAmps, globalBW, interpolation1, interpolation2, saturation, dcBlockzero, dcBlockpole, internalFeedback, externalInput) = 
externalInput : (ModifiedLorenzEquations ~ si.bus(3) : par(i, 3, /(saturation + 1)) :> _ / 3)
    with {
        x_init = x0-x0';    y_init = y0-y0';    z_init = z0-z0';

        ModifiedLorenzEquations(x, y, z, external) = 
            (( (external / 3) + x + sigma * (y - x) * dt + x_init) : dcblocker(dcBlockzero, dcBlockpole) : saturator(saturation + 1) : 
            BandpassFiltersBank(bypassFilter, filterPartials, filterOrder, globalFreq, globalAmps, globalBW, interpolation1, interpolation2)) * internalFeedback, 

            (( (external/ 3) + y + (rho * x - x * z - y) * dt + y_init) : dcblocker(dcBlockzero, dcBlockpole) : saturator(saturation + 1) : 
            BandpassFiltersBank(bypassFilter, filterPartials, filterOrder, globalFreq, globalAmps, globalBW, interpolation1, interpolation2)) * internalFeedback, 

            (( (external / 3) + z + (x * y - beta * z) * dt + z_init) : dcblocker(dcBlockzero, dcBlockpole) : saturator(saturation + 1) : 
            BandpassFiltersBank(bypassFilter, filterPartials, filterOrder, globalFreq, globalAmps, globalBW, interpolation1, interpolation2)) * internalFeedback;
    };

// GLOBAL SYSTEM NETWORK ----------------------------------------
GlobalSystemNetwork(dt, beta, rho, sigma, bpFilterBypass, globalBPFrequencies, globalBPBW, interpolations1, interpolations2, saturation, lorenzFeedback,
networkFeedbackGain, rescaleOutput, networkOutputGain) = ( loop ~ _ : (si.block(1), si.bus(NetworkVoices)) ) : 
    par( i, NetworkVoices, _ / rescaleOutput : normalization(1) ) : par( i, NetworkVoices, _ * networkOutputGain )
    with{
        loop(networkFeedback) =  par(i,  NetworkVoices,
                        ( 
                            ( (networkFeedback * networkFeedbackGain)  @(SystemSpaceVar * (i + 1)) ) : ModifiedLorenzSystem(InitX0, InitY0, InitZ0, dt, beta, rho, sigma, bpFilterBypass, BPFilters, BPFOrder, globalBPFrequencies, 1, globalBPBW, interpolations1, interpolations2, saturation, InitDCBlockzero, InitDCBlockpole, lorenzFeedback) 
                        )

                    ) <: (si.bus(NetworkVoices) :> +/NetworkVoices), (si.bus(NetworkVoices));
        };
              

process = RoomInterfaceNetwork : GlobalSystemNetwork;