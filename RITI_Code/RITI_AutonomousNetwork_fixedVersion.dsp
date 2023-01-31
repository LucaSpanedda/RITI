// import faust standard library
import("stdfaust.lib");
// import RITI objects library
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
RoomInterfaceNetwork(Mic1, Mic2, Mic3, Mic4) = Dtf, Betaf, Rhof, Sigmaf, BPFilterBypassf, GlobalBPFrequenciesf, GlobalBPBWf, Interpolations1f, Interpolations2f, Saturationf, LorenzFeedbackf, NetworkFeedbackf, ExternalInputGainf, OutputGainf, HPfreqf, LPfreqf, MicsOutputf
with { 
    SmoothTf(x) = onepoletau(vslider("h:[0]Mixer/h:Interpolation/Smooth [unit:Sec]", 1, .001, 10, .001), x);
    Dtf = (ba.db2linear(vslider("h:[0]Mixer/h:Lorenz Equation Parameters/Dt [unit:dB]", 0, -60, 60, .001))) : SmoothTf;
    Sigmaf = (vslider("h:[0]Mixer/h:Lorenz Equation Parameters/Sigma", 10, 1, 19, .001)) : SmoothTf;
    Rhof = (vslider("h:[0]Mixer/h:Lorenz Equation Parameters/Rho", 3.518, 2.8, 53.2, .001)) : SmoothTf;
    Betaf = (vslider("h:[0]Mixer/h:Lorenz Equation Parameters/Beta", 1.073, 0.2666, 5.066, .001)) : SmoothTf;
    BPFilterBypassf = (vslider("h:[0]Mixer/h:Bandpass Filters Bank/BP Bypass", 0, 0, 1, .001)) : SmoothTf;
    GlobalBPFrequenciesf = (16 ^ vslider("h:[0]Mixer/h:Bandpass Filters Bank/Frequency [unit:Hz]", 0, -1, 1, .001)) : SmoothTf;
    GlobalBPBWf = (vslider("h:[0]Mixer/h:Bandpass Filters Bank/Bandwidth [unit:Hz]", 1, 1, 100, .001)) : SmoothTf;
    Interpolations1f = (vslider("h:[0]Mixer/h:Bandpass Filters Bank/Interpolations 1", 1, 0, 1, .001)) : SmoothTf;
    Interpolations2f = (vslider("h:[0]Mixer/h:Bandpass Filters Bank/Interpolations 2", 1, 0, 1, .001)) : SmoothTf;
    Saturationf = (vslider("h:[0]Mixer/h:Lorenz Equation Parameters/TanH [unit:TanH]", 50, 1, 100, .001)) : SmoothTf;
    LorenzFeedbackf = vslider("h:[0]Mixer/h:Lorenz Equation Parameters/Lorenz FB", 1, 0, 1, .001) : SmoothTf;  
    NetworkFeedbackf = vslider("h:[0]Mixer/h:Feedback Delay Network/Network FB", 1, 0, 1, .001) : SmoothTf; 
    OutputGainf = ((ba.db2linear(vslider("h:[0]Mixer/h:Input-Output/Master [unit:dB]", -80, -80, 0, .001))) : \(x).( (x > ba.db2linear(-80)) * x )) : SmoothTf;
    HPfreqf = (vslider("h:[0]Mixer/h:Input-Output/HP frequency [unit:Hz]", 1, 1, 20000, 1)) : SmoothTf;
    LPfreqf = (vslider("h:[0]Mixer/h:Input-Output/LP frequency [unit:Hz]", 20000, 1, 20000, 1)) : SmoothTf;
    ExternalInputGainf = ((ba.db2linear(vslider("h:[0]Mixer/h:Input-Output/Externals [unit:dB]", -80, -80, 80, .001))) : \(x).( (x > ba.db2linear(-80)) * x )) : SmoothTf;
    MicsOutputf = (Mic1, Mic2, Mic3, Mic4) :> _ / 4;
};

// MODIFIED LORENZ SYSTEM ----------------------------------------
ModifiedLorenzSystem(x0, y0, z0, dt, beta, rho, sigma, bypassFilter, filterPartials, filterOrder, globalFreq, globalAmps, globalBW, interpolation1, interpolation2, saturation, dcBlockzero, dcBlockpole, internalFeedback, i, externalInput) = 
    (
        (
        par(i, 3, _ * internalFeedback) : 
        vgroup("[2]Inspectors", hgroup("Lorenz Feedback", XYZinspect(i))) : LorenzSystemEquations
        ) : 
            par(i, 3, _ : dcblocker(dcBlockzero, dcBlockpole)) : 
            vgroup("[2]Inspectors", hgroup("DC Blocker", XYZinspect(i))) : 
                par(i, 3, _ : saturator(saturation)) : 
                vgroup("[2]Inspectors", hgroup("Hyperbolic Tangent", XYZinspect(i))) : 
                    par(i, 3, _ : BandpassFiltersBank(bypassFilter, filterPartials, filterOrder, globalFreq, globalAmps, globalBW, interpolation1, interpolation2)) : 
                    vgroup("[2]Inspectors", hgroup("Bandpass Filters", XYZinspect(i)))
    ) ~ si.bus(3) : 
        par(i, 3, / (max(saturation, ma.EPSILON))) :> _ / 3
    with {
        x_init = x0-x0';    y_init = y0-y0';    z_init = z0-z0';
        LorenzSystemEquations(x, y, z) = 
            (((x + sigma * (y - x) * dt + x_init) + (externalInput))), 
            (((y + (rho * x - x * z - y) * dt + y_init) + (externalInput))),  
            (((z + (x * y - beta * z) * dt + z_init) + (externalInput)));
    };

// GLOBAL SYSTEM NETWORK ----------------------------------------
GlobalSystemNetwork(dt, beta, rho, sigma, bpFilterBypass, globalBPFrequencies, globalBPBW, interpolations1, interpolations2, saturation, lorenzFeedback, networkFeedbackGain, externalInputGain, networkOutputGain, hpfreqGain, lpfreqGain, micsOutput) = 
    (
        (_ * networkFeedbackGain : NetworkLoop) ~ _ : 
            (si.block(1), si.bus(NetworkVoices))
        ) : 
            par(i, NetworkVoices, _ : HPTPT(hpfreqGain) : LPTPT(lpfreqGain) : normalization(1)) : 
                par(i, NetworkVoices, _ * networkOutputGain ) : 
                    par(i, NetworkVoices, _ : vgroup("[2]Inspectors", hgroup("Output Channels",  Vmeter(i+1, 0, 1)))
    )
    with{    
        NetworkLoop(networkFeedback) =  par(i,  NetworkVoices, 
                        (networkFeedback : (timeVaryingDelay(vslider("h:[0]Mixer/h:Feedback Delay Network/h:Input Delays/Voice_%i+1[2]  [unit:Sec]", 
                            (SystemSpaceVarIN * (NetworkVoices - i)), .001, DelSecondsMax, .001), 0) + (micsOutput * externalInputGain)) : 
                                ModifiedLorenzSystem(InitX0, InitY0, InitZ0, dt, beta, rho, sigma, bpFilterBypass, BPFilters, BPFOrder, globalBPFrequencies, 1, globalBPBW, interpolations1, interpolations2, saturation, InitDCBlockzero, InitDCBlockpole, lorenzFeedback, i)
                            )
                        ) <: 
                        (par( i, NetworkVoices, _ : timeVaryingDelay( vslider("h:[0]Mixer/h:Feedback Delay Network/h:Output Delays/Voice_%i+1[2]  [unit:Sec]",  SystemSpaceVarOUT * (i + 1), .001, DelSecondsMax, .001) , 0)) :> +/NetworkVoices), (si.bus(NetworkVoices));
    };    
                              
process = si.bus(8) :> si.bus(4) : RoomInterfaceNetwork : GlobalSystemNetwork;