// import faust standard library
import("stdfaust.lib");
// import RITI objects library
import("RITI.lib");


// SYSTEM INTERFACE ----------------------------------------
TGroup(x) = tgroup("Main", x);
    MixerGroup(x) = hgroup("Mixer", x);
        FiltersGroup(x) = hgroup("Bandpass Filters Bank", x);
            TFreqsGroup(x) = tgroup("Bank Voices", x);
            FreqsGroup(i, x) = hgroup("Voice_%i", x);
        FDNGroup(x) = hgroup("Feedback Delay Network", x);
            INDelayGroup(x) = hgroup("Input Delays", x);
            OUTDelayGroup(x) = hgroup("Output Delays", x);
            GainDelayGroup(x) = hgroup("Gains Network", x);
            TDelayGroup(x) = tgroup("Delay Times", x);
        InsOutsGroup(x) = hgroup("Inputs and Outputs", x);
        LorenzFuncGroup(x) = hgroup("Lorenz Equation Parameters", x);
    InspectorsGroup(x) = vgroup("Inspectors", x);

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

Dtf = TGroup((ba.db2linear(MixerGroup(LorenzFuncGroup(vslider("Dt [unit:dB]", 0, -60, 60, .001)))))) : onepoletau(2);
Sigmaf = TGroup((MixerGroup(LorenzFuncGroup(vslider("Sigma", 10, 1, 19, .001))))) : onepoletau(2);
Rhof = TGroup((MixerGroup(LorenzFuncGroup(vslider("Rho", 3.518, 2.8, 53.2, .001))))) : onepoletau(2);
Betaf = TGroup((MixerGroup(LorenzFuncGroup(vslider("Beta", 1.073, 0.2666, 5.066, .001))))) : onepoletau(2);
BPFilterBypassf = TGroup((MixerGroup(FiltersGroup(vslider("BP Bypass", 0, 0, 1, .001))))) : onepoletau(2);
BPFilterDirectf = TGroup((MixerGroup(FiltersGroup(vslider("BP Signal", 1, 0, 1, .001))))) : onepoletau(2);
GlobalBPFrequenciesf(i) = TGroup((16 ^ MixerGroup(FiltersGroup(TFreqsGroup(FreqsGroup(i+1, vslider("Frequency [unit:Hz]", 0, -1, 1, .001))))))) : onepoletau(2);
GlobalBPBWf = TGroup((MixerGroup(FiltersGroup(vslider("Bandwidth [unit:Hz]", 1, 1, 100, .001))))) : onepoletau(2);
ChngList1f(i) = TGroup((MixerGroup(FiltersGroup(TFreqsGroup(FreqsGroup(i+1, nentry("Change List 1", 1, 1, 4, 1)))))));
ChngList2f(i) = TGroup((MixerGroup(FiltersGroup(TFreqsGroup(FreqsGroup(i+1, nentry("Change List 2", 2, 1, 4, 1)))))));
ChngList3f(i) = TGroup((MixerGroup(FiltersGroup(TFreqsGroup(FreqsGroup(i+1, nentry("Change List 3", 3, 1, 4, 1)))))));
ChngList4f(i) = TGroup((MixerGroup(FiltersGroup(TFreqsGroup(FreqsGroup(i+1, nentry("Change List 4", 4, 1, 4, 1)))))));
Interpolations1f(i) = TGroup((MixerGroup(FiltersGroup(TFreqsGroup(FreqsGroup(i+1, vslider("Interpolations A", 0, 0, 1, .001))))))) : onepoletau(2);
Interpolations2f(i) = TGroup((MixerGroup(FiltersGroup(TFreqsGroup(FreqsGroup(i+1, vslider("Interpolations B", 0, 0, 1, .001))))))) : onepoletau(2);
Saturationf = TGroup((MixerGroup(LorenzFuncGroup(vslider("TanH [unit:TanH]", 50, 1, 100, .001))))) : onepoletau(2);
LorenzFeedbackf = TGroup(MixerGroup(LorenzFuncGroup(vslider("Lorenz FB", 1, 0, 1, .001)))) : onepoletau(2);  
OutputGainf = TGroup(((ba.db2linear(MixerGroup(InsOutsGroup(vslider("Master [unit:dB]", -80, -80, 0, .001))))) : \(x).( (x > ba.db2linear(-80)) * x ))) : onepoletau(2);
HPfreqf = TGroup((MixerGroup(InsOutsGroup(vslider("HP frequency [unit:Hz]", 1, 1, 20000, 1))))) : onepoletau(2);
LPfreqf = TGroup((MixerGroup(InsOutsGroup(vslider("LP frequency [unit:Hz]", 20000, 1, 20000, 1))))) : onepoletau(2);
ExternalInputGainf = TGroup(((ba.db2linear(MixerGroup(InsOutsGroup(vslider("Externals [unit:dB]", -80, -80, 80, .001))))) : 
    \(x).( (x > ba.db2linear(-80)) * x ))) : onepoletau(2);


// MODIFIED LORENZ SYSTEM ----------------------------------------

ModifiedLorenzSystem(x0, y0, z0, dt, beta, rho, sigma, bypassFilter, directFilter, filterPartials, filterOrder, globalFreq, globalAmps, globalBW, interpolation1, interpolation2, changeList1, changeList2, changeList3, changeList4, saturation, dcBlockzero, dcBlockpole, internalFeedback, i, externalInput) = 
    (
        (
        par(i, 3, _ * internalFeedback) : 
        TGroup(InspectorsGroup(hgroup("Lorenz Feedback", XYZinspect(i)))) : LorenzSystemEquations
        ) : 
            par(i, 3, _ : dcblocker(dcBlockzero, dcBlockpole)) : 
            TGroup(InspectorsGroup(hgroup("DC Blocker", XYZinspect(i)))) : 
                par(i, 3, _ : saturator(saturation)) : 
                TGroup(InspectorsGroup(hgroup("Hyperbolic Tangent", XYZinspect(i)))) : 
                    par(i, 3, _ : BandpassFiltersBank(bypassFilter, directFilter, filterPartials, filterOrder, globalFreq, globalAmps, globalBW, interpolation1, interpolation2, changeList1, changeList2, changeList3, changeList4)) : 
                    TGroup(InspectorsGroup(hgroup("Bandpass Filters", XYZinspect(i))))
    ) ~ si.bus(3) : 
        par(i, 3, / (max(saturation, ma.EPSILON))) :> _ / 3
    with {
        x_init = x0-x0';    y_init = y0-y0';    z_init = z0-z0';
        LorenzSystemEquations(x, y, z) = 
            ((((x + externalInput) + sigma * (y - x) * dt + x_init))), 
            ((((y + externalInput) + (rho * x - x * z - y) * dt + y_init))),  
            ((((z + externalInput) + (x * y - beta * z) * dt + z_init)));
    };


// GLOBAL SYSTEM NETWORK ----------------------------------------

GlobalSystemNetwork(Mic1, Mic2, Mic3, Mic4) = 
    (NetworkLoop ~ _ : (si.block(1), si.bus(NetworkVoices))) : 
            par(i, NetworkVoices, _ : HPTPT(HPfreqf) : LPTPT(LPfreqf) : normalization(1)) : 
                par(i, NetworkVoices, _ * OutputGainf )
    with{    
        NetworkLoop(networkFeedback) =  par(i,  NetworkVoices, 
            (networkFeedback * (TGroup(MixerGroup(FDNGroup(TDelayGroup(GainDelayGroup(vslider("Voice_%i+1[2]", 1, 0, 1, .001))))))) : 
                (timeVaryingDelay(TGroup(MixerGroup(FDNGroup(TDelayGroup(INDelayGroup(vslider("Voice_%i+1[2]  [unit:Sec]", 
                (SystemSpaceVarIN * (NetworkVoices - i)), .001, DelSecondsMax, .001)))))), 0) + (((Mic1,Mic2,Mic3,Mic4) :> _ / 4) * ExternalInputGainf)) : 
                    ModifiedLorenzSystem(InitX0, InitY0, InitZ0, Dtf, Betaf, Rhof, Sigmaf, BPFilterBypassf, BPFilterDirectf, BPFilters, BPFOrder, 
                    GlobalBPFrequenciesf(i), 1, GlobalBPBWf, Interpolations1f(i), Interpolations2f(i), ChngList1f(i), ChngList2f(i), ChngList3f(i), ChngList4f(i), Saturationf, InitDCBlockzero, InitDCBlockpole, LorenzFeedbackf, i)
                            )
                        ) <: 
                        (par( i, NetworkVoices, _ : timeVaryingDelay(TGroup(MixerGroup(FDNGroup(TDelayGroup(OUTDelayGroup(vslider("Voice_%i+1[2]  [unit:Sec]",  SystemSpaceVarOUT * (i + 1), .001, DelSecondsMax, .001)))))) , 0)) :> +/NetworkVoices), (si.bus(NetworkVoices));
    };    


process = si.bus(8) :> si.bus(4) : GlobalSystemNetwork;