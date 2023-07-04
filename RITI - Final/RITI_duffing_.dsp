import("stdfaust.lib");
// Spectrums
Partials = 32;
Flist(0) = component("lists.dsp").C_SUL_TASTO_frequencies;
Alist(0) = component("lists.dsp").C_SUL_TASTO_amplitudes;
Flist(1) = component("lists.dsp").G_SUL_TASTO_frequencies;
Alist(1) = component("lists.dsp").G_SUL_TASTO_amplitudes;
Flist(2) = component("lists.dsp").D_SUL_TASTO_frequencies;
Alist(2) = component("lists.dsp").D_SUL_TASTO_amplitudes;
Flist(3) = component("lists.dsp").A_SUL_TASTO_frequencies;
Alist(3) = component("lists.dsp").A_SUL_TASTO_amplitudes;
PrimesNL = component("lists.dsp").Primes;

vecOp(vectorsList, op) =
    vectorsList : seq(i, vecDim - 1, vecOp2D , vecBus(vecDim - 2 - i))
    with {
        vecBus(0) = par(i, vecLen, 0 : !);
        vecBus(dim) = par(i, dim, si.bus(vecLen));
        vecOp2D = ro.interleave(vecLen, 2) : par(i, vecLen, op);
        vecDim = outputs(vectorsList) / vecLen;
        vecLen = outputs(ba.take(1, vectorsList));
    };

// Allpass Filters Lattice 
// parallel, sequency, min. of distribution, max. of distribution, par offset, allpasses gain
apfLattice(columns, rows, minN, maxN, verticalOffset, g) = APFgrid 
with{
    // (t, g) = give: delay in samples, feedback gain 0-1
    apf(del, g, x) = x : (+ : _ <: @(del  - 1), *(g))~ *(-g) : mem, _ : + : _;
    rangeN = maxN - minN;
    step = rangeN / rows;
    primesNum(i) = ba.take(i, PrimesNL);
    ms2samp(t) = (t / 1000) * ma.SR;
    APFgrid = 
        par(j, columns, 
                seq(i, rows, 
                    apf(primesNum(int(i * step + minN + j * verticalOffset)) : ms2samp, g) 
                )
        );
    };

Network(N) = (netInsx : vecMx : agnt : apfs) ~ si.bus(N)
with{
    // Network
    netInsx = vecOp((si.bus(N) , si.bus(N)), +);
    vecMx = si.bus(N) <: par(i, N, (vecOp((si.bus(N), par(i, N, 1/N)), *) :> _@2000));
    // Duffing
    duffing_oscillator(i, in) = output
    with{
        saturator(lim, x) = lim * ma.tanh(x / (max(lim, ma.EPSILON)));
        dcblocker(zero, pole, x) = x : dcblockerout
            with{
                onezero =  _ <: _, mem : _,* (zero) : -;
                onepole = + ~ * (pole);
                dcblockerout = _ : onezero : onepole;
            };
        t =  si.smoo(vslider("h: Duffing /Frequency",100, 20, 10000, .001)/ma.SR);
        beta = si.smoo(vslider("h: Duffing /Mod",1, 0, 1, .001));
        alpha = 1;
        omega = 1000 ^ si.smoo(vslider("h: Duffing /Rate", 1, -1, 1, .001));
        gain =  10000 ^ si.smoo(vslider("h: Duffing /Gain", 0, -1, 1, .001));
        interact = si.smoo(vslider("h: Duffing /Interactions",0, 0, 1, .001));
        delta = (1 - interact) + (in * interact); 
        T = omega/ma.SR : + ~ _;
        duffing(y, x) = - delta * y - alpha * (x ^ 3) - beta * cos(T) <: _, _;
        filters(x) =    x * gain <: BPBANK(i, Partials, Flist(i), Alist(i)) :> 
                        _ / Partials : saturator(1) : dcblocker(1, .995)
        with {
            BPBANK(i, N, Fl, Al, x) =  ( x <: 
                vecOp( ((Fl : par(i, N, _ * Fshift)), si.bus(N)), BPTPT(Bw) ) : 
                vecOp( ((Al : par(i, N, _)), si.bus(N)), *) :> _ / N 
            ) * bypass + (x * oppositebp) 
            with {
                // filter
                BPTPT(bw, cf, x) = loop ~ si.bus(2) : (! , ! , _)
                with {
                    g = tan(cf * ma.PI * (1.0/ma.SR));
                    Q = cf / max(ma.EPSILON, bw);
                    R = 1.0 / (Q + Q);
                    G = 1.0 / (1.0 + 2.0 * R * g + g * g);
                    loop(s1, s2) = u1 , u2 , bp
                        with {
                            bp = (g * (x - s2) + s1) * G;
                            bp2 = bp + bp;
                            v2 = bp2 * g;
                            u1 = bp2 - s1;
                            u2 = v2 + s2;
                        };
                };
                // controls
                bypass = si.smoo(vslider("h: Duffing / Filtered", 1, 0, 1, .001));
                oppositebp = 1 - bypass;
                Fshift = 16 ^ si.smoo(vslider("h: Duffing / Pitch Shift", 0, -1, 1, .001));
                Bw = 100 ^ si.smoo(vslider("h: Duffing / Q", 0, -1, 1, .001));
            };
    };
    output = (duffing : (_, filters)) ~ si.bus(2) : !, _;
    };
    agnt =  par(i, N, duffing_oscillator(i, _)); 
    apfs =  si.bus(N) <: (
                (   
                    par(i, N, _ * bps) : apfLattice(N, 10, 10, 400, 5, .5)), 
                    par(i, N, _ * (1 - bps))
                ) :> si.bus(N)
    with{
        bps = si.smoo(vslider("h: Duffing / Allpass", 0, 0, 1, .001));
    };
};
process = hgroup("RITI", Network(4));