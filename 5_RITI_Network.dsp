// import RITI objects library
import("4_RITI_Library.lib");


// FILTERBANKS LISTS ---------------------------------------------
FiltersList1(i) = ba.take(i, C_SUL_TASTO_amplitudes), ba.take(1, C_SUL_TASTO_bandwidths), ba.take(i, C_SUL_TASTO_frequencies);
FiltersList2(i) = ba.take(i, C_SUL_PONTE_amplitudes), ba.take(1, C_SUL_PONTE_bandwidths), ba.take(i, C_SUL_PONTE_frequencies);
FiltersList3(i) = ba.take(i, C_MOLTO_SUL_PONTE_amplitudes), ba.take(1, C_MOLTO_SUL_PONTE_bandwidths), ba.take(i, C_MOLTO_SUL_PONTE_frequencies);


// MODIFIED LORENZ SYSTEM ----------------------------------------
ModifiedLorenzSystem(x0, y0, z0, dt, beta, rho, sigma, directFilter, bypassFilter, filterPartials, filterOrder, globalFreq, globalAmps, globalBW, saturation, dcBlockzero, dcBlockpole, internalFeedback, externalGain, finalGain, externalInput) = 
    (
        LorenzSystemEquations : 
            par(i, 3, _ : dcblocker(dcBlockzero, dcBlockpole)) : 
                par(i, 3, _ : saturator(saturation)) : EquationstoFBank
    ) ~ par(i, 3, (_ * internalFeedback) + externalInput) : 
        par(i, 3, / (max(saturation, ma.EPSILON))) :> _ / (3) * finalGain
    with {
        x_init = x0-x0';    
        y_init = y0-y0';    
        z_init = z0-z0';

        LorenzSystemEquations(x, y, z) = 
            (((x + sigma * (y - x) * dt + x_init))), 
            (((y + (rho * x - x * z - y) * dt + y_init))),  
            (((z + (x * y - beta * z) * dt + z_init)));
        
        FILTBANK(N, ampsCntrl, bwdsCntrl, freqsCntrl, inputCntrl) = 
            par(i, N, (_ * ampsCntrl, _ * bwdsCntrl, _ * freqsCntrl, _ * inputCntrl)) : 
                par(i, N, BPSVF) :> _ : _ / N;

        EquationstoFBank(x, y, z) = 
            (   
                par(i, filterPartials, FiltersList1(i + 1), x) : 
                    FILTBANK(filterPartials, globalAmps, globalBW, globalFreq, directFilter)
                        ) + (x * bypassFilter), 
            (   
                par(i, filterPartials, FiltersList2(i + 1), y) : 
                    FILTBANK(filterPartials, globalAmps, globalBW, globalFreq, directFilter)
                        ) + (y * bypassFilter), 
            (
                par(i, filterPartials, FiltersList3(i + 1), z) : 
                    FILTBANK(filterPartials, globalAmps, globalBW, globalFreq, directFilter)
                        ) + (z * bypassFilter);  
    };


// LORENZ SYSTEM SINGLE VOICE ------------------------------------
LorenzSystemVoice(i) =  
    tgroup("Lorenz Systems", 
        hgroup("Lorenz %i", 
            ModifiedLorenzSystem(X, Y,  Z, DT,  BETA, RHO, SIGMA, FILTERDIRECT, FILTERBYPASS, FILTERPARTIALS, FILTERORDER, FILTERFREQUENCY, FILTERAMPS, FILTERBANDWIDTH, HYPERBOLICTAN, DCZERO, DCPOLE, LORENZFB, 1, 1)
        )
    )
    with {
        X = 1.2; 
        Y = 1.3; 
        Z = 1.6; 

        FILTERPARTIALS = 32;
        FILTERORDER = 1;
        DCZERO = 1;
        DCPOLE = 0.995;

        DT = vslider("h: Lorenz Equation / Dt [unit:dB]", 0, -60, 60, .001);
        BETA = vslider("h: Lorenz Equation / Beta", 1.073, 0.2666, 5.066, .001);
        RHO = vslider("h: Lorenz Equation / Rho", 3.518, 2.8, 53.2, .001);
        SIGMA = vslider("h: Lorenz Equation / Sigma", 10, 1, 19, .001);
        HYPERBOLICTAN = vslider("h: Lorenz Equation / TanH [unit:TanH]", 1000, 1, 1000, .001); 
        LORENZFB = vslider("h: Lorenz Equation / Internal Lorenz FB", 1, 0, 1, .001);

        FILTERDIRECT = vslider("h: Filters Bank / Filtered Direct", 1, 0, 1, .001);
        FILTERBYPASS = vslider("h: Filters Bank / Filtered Bypass", 0, 0, 1, .001);
        FILTERFREQUENCY = 16 ^ vslider("h: Filters Bank / Frequency [unit:Hz]", 0, -1, 1, .001);
        FILTERAMPS = 1;
        FILTERBANDWIDTH = vslider("h: Filters Bank / Bandwidth [unit:Hz]", 1, 1, 100, .001);
    };


// SYSTEM NETWORK ------------------------------------------------
Network(N) =    
    par(i, N, 
        hgroup("RITI Network", 
            hgroup("Voice %i", 
                (_ *  100000 : limitation(1)) @ 
                    sec2samp(nentry("Delay [unit:sec]", 1 + i, 0, 10, .001))
            )
        )
    ) : (_, si.bus(N-1) : ro.cross1n(N-1));


// OUTPUT PATH ---------------------------------------------------
RITI(N, x) = par(i, N, _ + (x * EXTERNALGAIN) : LorenzSystemVoice(i + 1) ) ~ Network(N) : par(i, N, _ * MASTERGAIN : limitation(1))
    with {
        EXTERNALGAIN = vslider("h: RITI Network / External Gain [unit:lin]", 0, 0, 1, .001);
        MASTERGAIN = vslider("h: RITI Network / Master Gain [unit:lin]", 1, 0, 10, .001);
    };
    
process = RITI(4);