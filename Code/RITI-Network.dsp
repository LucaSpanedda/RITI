// Faust standard libraries
import("stdfaust.lib");

// SYSTEM VARIABLES ----------------------------------------
BPFilterOrder = 1;
SystemSpaceVar = 2 * ma.SR;
CaoticEQfbGain = 1000;
NetFBGain = 1;
FreqShift = hslider("fShift",1,0.001,10,.001) : si.smoo;

// FILTERS -------------------------------------------------
// TPT version of the One Pole and SVF Filter by Vadim Zavalishin
// reference : (by Will Pirkle)
// http://www.willpirkle.com/Downloads/AN-4VirtualAnalogFilters.2.0.pdf
// OnePoleTPT filter function
onePoleTPT(cf, x) = loop ~ _ : ! , si.bus(3)
    with {
        g = tan(cf * ma.PI * (1/ma.SR));
        G = g / (1.0 + g);
        loop(s) = u , lp , hp , ap
            with {
                v = (x - s) * G;
                u = v + lp;
                lp = v + s;
                hp = x - lp;
                ap = lp - hp;
            };
    };
LPTPT(cf, x) = onePoleTPT(limit(20000,1.19209e-07,cf), x) : (_ , ! , !);
HPTPT(cf, x) = onePoleTPT(limit(20000,1.19209e-07,cf), x) : (! , _ , !);
// TEST
// process = (-100, no.noise) : HPTPT;

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
// Outs = (lp , hp , bp, notch, apf, ubp, peak, bshelf)
// SVFTPT(K, Q, CF, x) = (Filter-K, Filter-Q, Frequency Cut)
// Filters Bank
LPSVF(Q, CF, x) = SVFTPT(0, Q, 
                            limit(20000,1.19209e-07,CF), x) : _,!,!,!,!,!,!,!;
HPSVF(Q, CF, x) = SVFTPT(0, Q, 
                            limit(20000,1.19209e-07,CF), x) : !,_,!,!,!,!,!,!;
//process = (-1, -10000, no.noise) <: LPSVF, HPSVF;
BPsvftpt(BW, CF, A, x) = SVFTPT(0 : ba.db2linear, ql, cfl, x * A)   : !,!,!,!,!,_,!,!
    with{
        limit(maxl,minl,x) = x : max(minl, min(maxl));
        cfl = limit(20000,1.19209e-07,CF);
        bwl = limit(20000,1.19209e-07,BW);
        ql  = cfl / bwl;
        };

// INSTRUMENT SPECTRE --------------------------------------
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

// Filters bands = B
// Filters in Cascade = O
// Gain for each filters out = G
// Bandpass Filter Banks
filterbanks(O, B, G, S, x) = x <:par(i, B,
                                seq(r, O, BPsvftpt( Qlist(i), 
                                                    Flist(i) * S, 
                                                    Alist(i)
                                                    ) * G
                                    )
                            ):> (+/B);
//process = no.noise : filterbanks(3, 10, 36) <: _,_;

soloBP(O) = seq(r, O, BPsvftpt(  hslider("BW",50,1,20000,.001), 
                    hslider("F",1000,1,20000,.001), 
                    hslider("G",.8,0,1,.001) ) );
//process = no.noise : soloBP(4);

sinemap(S, x0) = ( circuit : tanf(tans) : filterbanks(BPFilterOrder, 10, 1, S) * 
                CaoticEQfbGain ) ~ _ : fi.dcblocker * outGain
            with {
                    circuit(x) =    (xInit-xInit')  + mu *
                        sin(ma.PI * ((x0 * fbAnalg) + (x * fbDigtl)));
                    xInit = .5;
                    fbDigtl =   hslider("fb Digital", 1, .0, 1.0, .001);
                    fbAnalg =   hslider("fb Analogs [unit:dB]", -60, -60, 60.0, .001) : 
                                ba.db2linear;
                    tanf(k,x) = ma.tanh(k * x)/(k * x);
                    mu =        hslider("mu", .8, 0.01, 1.0, .001);
                    tans =      hslider("tahn", 1, 1, 100, .001);
                    outGain =   hslider("outGain [unit:dB]", -60, -60, 60.0, .001) : 
                                ba.db2linear;
                };
//process = _ : fi.dcblocker : sinemap <: _,_;

Network(x) = 
    \(fb1,fb2,fb3,fb4).
        ( 
            (x+((fb2+fb3+fb4)@(SystemSpaceVar*1) *NetFBGain) : 
                sinemap(nonlinearosc(1243,2,4)+1)*FreqShift ), 
            (x+((fb1+fb3+fb4)@(SystemSpaceVar*2) *NetFBGain) : 
                sinemap(nonlinearosc(5913,2,4)+1)*FreqShift ),
            (x+((fb1+fb2+fb4)@(SystemSpaceVar*3) *NetFBGain) : 
                sinemap(nonlinearosc(3943,2,4)+1)*FreqShift ), 
            (x+((fb1+fb2+fb3)@(SystemSpaceVar*4) *NetFBGain) : 
                sinemap(nonlinearosc(9914,2,4)+1)*FreqShift )
        )~ si.bus(4);
process = _ : fi.dcblocker : Network;

// generate a random number from a seed
random(seed) = abs((seed * 1103515245) / 2147483647.0);
// nonlinear Low Frequency oscillator based on arbritary Frequencies 
nonlinearosc(seed,slowFactor,voices) = 
    par(i, voices, sin(( (random(seed + (i * 1000))/ma.SR/slowFactor) : 
                         (+ : \(x).(x-int(x)) ) ~ _) * 2 * ma.PI)
        ) :> +/voices : _ + 1 : _ / 2;
//process =   nonlinearosc(1243,2,4),nonlinearosc(5913,2,4),
            //nonlinearosc(3943,2,4),nonlinearosc(9914,2,4);
