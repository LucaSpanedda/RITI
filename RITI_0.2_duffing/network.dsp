import("library.lib");
Partials = 32; // BP Filters Partials 
Flist(0) = component("lists.dsp").G_SUL_TASTO_frequencies;
Alist(0) = component("lists.dsp").G_SUL_TASTO_amplitudes;
Flist(1) = component("lists.dsp").G_SUL_PONTE_frequencies;
Alist(1) = component("lists.dsp").G_SUL_PONTE_amplitudes;
Flist(2) = component("lists.dsp").G_MOLTO_SUL_PONTE_frequencies;
Alist(2) = component("lists.dsp").G_MOLTO_SUL_PONTE_amplitudes;
Flist(3) = component("lists.dsp").G_ARMONICI_frequencies;
Alist(3) = component("lists.dsp").G_ARMONICI_amplitudes;
PrimesNL = component("lists.dsp").Primes;

//------------------------------------------------------------- RITI NETWORK ---
Network(N) = (netInsx(N) : vecMx(N) : oscs(N) : apfs(N) : limit(N)) ~ si.bus(N)
with{
    filtersection(i, x) = x * gain <: BPBANK(Partials, Flist(i), Alist(i), shift, 1, bw, bypass) :> _ / 
                        Partials : saturator(1) : LPHPTPT(20, 18000)
        with {
            // controls
            gain = si.smoo(vslider("h: RITI / Gain", 1, 0, 10000, 1));
            bypass = si.smoo(vslider("h: RITI / Filtered", 1, 0, 1, .001));
            shift = 4 ^ si.smoo(vslider("h: RITI / Pitch Shift", 0, -1, 1, .001));
            bw = 100 ^ si.smoo(vslider("h: RITI / Q", 0, -1, 1, .001));
        };
    oscs(N) =  par(i, N, duffing_oscillator(i, _))
    with{
        duffing_oscillator(i, in) = (duffing : (_, filtersection(i))) ~ si.bus(2) : !, _
        with{
            delta(x) = (1 - x) + (in * x); 
            T(x) = x/ma.SR : + ~ _;
            duffing(y, x) = - delta(interact) * y - alpha * (x ^ 3) - beta * cos( T(omega) ) <: _, _
            with{
                beta = si.smoo(vslider("h: RITI / Mod",1, 0, 1, .001));
                alpha = 1;
                omega = si.smoo(vslider("h: RITI / Rate", 1000, 1, 1000, .001));
                interact = si.smoo(vslider("h: RITI / Interactions",0, 0, 1, .001));
            };
        };
    };
    apfs(N) =  si.bus(N) <: ((par(i, N, _ * bps) : apfLattice(N, 10, 10, 400, 5, .5)), 
                par(i, N, _ * (1 - bps))) :> si.bus(N)
    with{
        bps = si.smoo(vslider("h: RITI / Allpass", 0, 0, 1, .001));
    };
    limit(N) = par(i, N, LookaheadLimiter(1, .1, 10));
};

process = hgroup("RITI", Network(4));