// import faust standard library
import("stdfaust.lib");
// import RITI objects library
import("RITIlibrary.lib");


// MODIFIED LORENZ SYSTEM ----------------------------------------
ModifiedLorenzSystem(x0, y0, z0, dt, beta, rho, sigma, automodulation1, automodulation2, automodulation3, filterOrder, globalFreq, globalAmps, globalBW, saturation, dcBlockzero, dcBlockpole, internalFeedback, externalGain, finalGain, extFB) = 
    (
        Automodulation : LorenzSystemEquations : 
            par(i, 3, _ : dcblocker(dcBlockzero, dcBlockpole)) : 
                par(i, 3, _ : saturator(saturation))
    ) ~ par(i, 3, _ ) : 
        par(i, 3, / (max(saturation, ma.EPSILON))) :> _ / (3) * finalGain
    with {
        x_init = x0-x0';    
        y_init = y0-y0';    
        z_init = z0-z0';

        LorenzSystemEquations(x, y, z) = 
            (((x + sigma * (y - x) * dt + x_init))), 
            (((y + (rho * x - x * z - y) * dt + y_init))),  
            (((z + (x * y - beta * z) * dt + z_init)));

        Automodulation(x, y, z) = 
            x * ( ((z + 1)/2) : LPTPT(.1) : LPTPT(.1) * automodulation1 : _ + 1 : vmeter(1)) + extFB * internalFeedback, 
            y * ( ((x + 1)/2) : LPTPT(.1) : LPTPT(.1) * automodulation2 : _ + 1 : vmeter(2)) + extFB * internalFeedback,  
            z * ( ((y + 1)/2) : LPTPT(.1) : LPTPT(.1) * automodulation3 : _ + 1 : vmeter(3)) + extFB * internalFeedback;

        vmeter(i, x) = attach(x, envelop(x) : vbargraph("AUTOMOD %i[2]", 0, 20));
        envelop = abs : max ~ -(1.0/ma.SR) : max(0) : _;
    };


// LORENZ SYSTEM SINGLE VOICE ------------------------------------
LorenzSystemVoice(i) =  
    tgroup("Lorenz Systems", 
        hgroup("Lorenz %i", 
            ModifiedLorenzSystem(X, Y,  Z, DT,  BETA, RHO, SIGMA, AUTOMOD1, AUTOMOD2, AUTOMOD3, FILTERORDER, FILTERFREQUENCY, FILTERAMPS, FILTERBANDWIDTH, HYPERBOLICTAN, DCZERO, DCPOLE, LORENZFB, 1, 1)
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

        DT = vslider("h: Lorenz Equation / DT", .001, .001, 0.01, .001);
        BETA = 8/3; // vslider("h: Lorenz Equation / Beta", 1.073, 0.2666, 5.066, .001);
        RHO = 28; // vslider("h: Lorenz Equation / Rho", 3.518, 2.8, 53.2, .001);
        SIGMA = 10; // vslider("h: Lorenz Equation / Sigma", 10, 1, 19, .001);
        HYPERBOLICTAN = vslider("h: Lorenz Equation / TAN-H", 100, 1, 1000, .001); 
        LORENZFB = 100 ^ vslider("h: Lorenz Equation / Internal Lorenz FB", 0, -1, 1, .001);

        AUTOMOD1 = vslider("h: Lorenz Equation / AUTOMOD 1", 0, 0, 10, .001);
        AUTOMOD2 = vslider("h: Lorenz Equation / AUTOMOD 2", 5, 1, 10, .001);
        AUTOMOD3 = vslider("h: Lorenz Equation / AUTOMOD 3", 5, 1, 10, .001);

        FILTERDIRECT = vslider("h: Filters Bank / Filtered Direct", 1, 0, 1, .001);
        FILTERBYPASS = 1 - FILTERDIRECT;
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


// FILTERBANKS LISTS ---------------------------------------------
FiltersList1(i) = ba.take(i, C_SUL_TASTO_amplitudes), ba.take(1, C_SUL_TASTO_bandwidths), ba.take(i, C_SUL_TASTO_frequencies);
FiltersList2(i) = ba.take(i, C_SUL_PONTE_amplitudes), ba.take(1, C_SUL_PONTE_bandwidths), ba.take(i, C_SUL_PONTE_frequencies);
FiltersList3(i) = ba.take(i, C_MOLTO_SUL_PONTE_amplitudes), ba.take(1, C_MOLTO_SUL_PONTE_bandwidths), ba.take(i, C_MOLTO_SUL_PONTE_frequencies);

FILTBANK(N, ampsCntrl, bwdsCntrl, freqsCntrl, inputCntrl) = 
            par(i, N, (_ * ampsCntrl, _ * bwdsCntrl, _ * freqsCntrl, _ * inputCntrl)) : 
                par(i, N, BPSVF) :> _ : _ / N;

EquationstoFBank(N, x) = 
    (   
        par(i, N, FiltersList1(i + 1), x * FILTERDIRECT) : 
            FILTBANK(N, 1, FILTERBANDWIDTH, FILTERFREQUENCY, 1)
                ) + (x * FILTERBYPASS)
    with {
        FILTERDIRECT = vslider("h: Filters Bank / Filtered Direct", 1, 0, 1, .001);
        FILTERBYPASS = 1 - FILTERDIRECT;
        FILTERFREQUENCY = 16 ^ vslider("h: Filters Bank / Frequency [unit:Hz]", 0, -1, 1, .001);
        FILTERBANDWIDTH = vslider("h: Filters Bank / Bandwidth [unit:Hz]", 1, 1, 100, .001);
    };


// OUTPUT PATH ---------------------------------------------------
RITI(N) = par(i, N, (LorenzSystemVoice(i + 1) : EquationstoFBank(32)) ~ _ ) : par(i, N, _ * MASTERGAIN : limitation(1))
    with {
        EXTERNALGAIN = vslider("h: RITI Network / External Gain [unit:lin]", 0, 0, 1, .001);
        MASTERGAIN = hslider("h: RITI Network / Master Gain [unit:lin]", 1, 0, 10, .001);
    };

process = RITI(4);