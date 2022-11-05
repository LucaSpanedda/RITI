// Faust standard libraries
import("stdfaust.lib");

// SVFTPT filter function
SVFTPT(K, Q, CF, x) = circuitout : !,!,_,_,_,_,_,_,_,_
    with{
        g = tan(CF * ma.PI / ma.SR);
        R = 1.0 / (2.0 * Q);
        G1 = 1.0 / (1.0 + 2.0 * R * g + g * g);
        G2 = 2.0 * R + g;
        circuit(s1, s2) = u1 , u2 , lp , hp , bp, notch, apf, ubp, peak, bshelf
            with{
                hp = (x - s1 * G2 - s2) * G1;
                v1 = hp * g;
                bp = s1 + v1;
                v2 = bp * g;
                lp = s2 + v2;
                u1 = v1 + bp;
                u2 = v2 + lp;
                notch = x - ((2*R)*bp);
                apf = x - ((4*R)*bp);
                ubp = ((2*R)*bp);
                peak = lp -hp;
                bshelf = x + (((2*K)*R)*bp);
            };
    // choose the output from the SVF Filter (ex. bshelf)
    circuitout = circuit ~ si.bus(2);
    };
// Filters Outs
LPsvf(CF, x) = SVFTPT(0 : ba.db2linear, 0 : ba.db2linear, CF, x) : _,!,!,!,!,!,!,!;
HPsvf(CF, x) = SVFTPT(0 : ba.db2linear, 0 : ba.db2linear, CF, x) : !,_,!,!,!,!,!,!;
BPsvftpt(BW, CF, A, x) = SVFTPT(1, Q, CF, x * A) : !,!,_,!,!,!,!,!
    with{
        Q = CF / BW;
        };

// instances
N = 10;
// list: Frequencies, Amps, Bandwidth
spectrefreq =
                (   65,
                    130,
                    195,
                    260,
                    325,
                    390,
                    455,
                    520,
                    585,
                    650
                );
spectreamps =
                (   .00971,
                    .14095,
                    .06763,
                    .13474,
                    .09476,
                    .01839,
                    .00945,
                    .02246,
                    .00420,
                    .00910
                );
spectreband =
                (   7,
                    22,
                    13,
                    20,
                    14,
                    8,
                    9,
                    10,
                    8,
                    10
                );
// index
Flist(index) = ba.take(index + 1, spectrefreq);
Alist(index) = ba.take(index + 1, spectreamps);
Qlist(index) = ba.take(index + 1, spectreband);

// Bandpass Filter Banks
filterbanks(x) = x  <:  par (i, N,
                                BPsvftpt(Qlist(i), Flist(i), Alist(i)) :
                                BPsvftpt(Qlist(i)/10, Flist(i), Alist(i))
                            ):> +/N;
process = no.noise * 8 : filterbanks <: si.bus(2);
