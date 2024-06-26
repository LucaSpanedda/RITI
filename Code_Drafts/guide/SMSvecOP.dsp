// import faust standard library
import("stdfaust.lib");


Ncello = 32;

Fcello = 65.0, 131.0, 196.0, 261.0, 326.0, 392.0, 457.0, 522.0, 588.0, 653.0, 718.0, 784.0, 849.0, 914.0, 979.0, 1045.0, 1110.0, 1175.0, 1241.0, 1306.0, 1371.0, 1502.0, 1567.0, 1632.0, 1698.0, 1763.0, 1828.0, 1894.0, 1959.0, 2024.0, 2089.0, 2351.0;

Acello = 0.04196492, 0.27707616, 1.0, 0.08153769, 0.05522969, 0.01922137, 0.03436227, 0.03067041, 0.01797695, 0.03381146, 0.0550058, 0.02913938, 0.05834666, 0.03480883, 0.01985851, 0.02222397, 0.02735344, 0.00482074, 0.00496045, 0.00848029, 0.01668042, 0.0121161, 0.04640077, 0.02313585, 0.00729633, 0.00722812, 0.01041008, 0.00722225, 0.00592071, 0.01158114, 0.00443968, 0.00282064;

vecOp(vectorsList, op) =
    vectorsList : seq(i, vecDim - 1, vecOp2D , vecBus(vecDim - 2 - i))
    with {
        vecBus(0) = par(i, vecLen, 0 : !);
        vecBus(dim) = par(i, dim, si.bus(vecLen));
        vecOp2D = ro.interleave(vecLen, 2) : par(i, vecLen, op);
        vecDim = outputs(vectorsList) / vecLen;
        vecLen = outputs(ba.take(1, vectorsList));
    };

BPSVF(bw, cf, x) = loop ~ si.bus(2) : (! , ! , _)
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

BPBANK(i, N, Flist, Alist, x) =  
    ( x <: 
        vecOp( ((Flist : par(i, N, _ * Fshift)), si.bus(N)), BPSVF(Bw) ) : 
        vecOp( ((Alist : par(i, N, _ * Ashift)), si.bus(N)), * ) :> _ / N 
    ) * bypass + (x * oppositebp)
    with {
        bypass = vslider("h: Filters Bank %i / Filtered Direct", 1, 0, 1, .001);
        oppositebp = 1 - bypass;
        Fshift = 16  ^ vslider("h: Filters Bank %i / Frequency", 0, -1, 1, .001);
        Ashift = vslider("h: Filters Bank %i / Amplitude", 1, 0, 10, .001);
        Bw = 100 ^ vslider("h: Filters Bank %i / Bandwidth", 0, -1, 1, .001);
    };

process = 
    (no.noise : BPBANK(2, Ncello, Fcello, Acello)), 
    (no.noise : BPBANK(1, Ncello, Fcello, Acello));