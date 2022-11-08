// import Standard Faust library
// https://github.com/grame-cncm/faustlibraries/
import("stdfaust.lib");

larsenmap(w) = \(x).((w * (1-(w : RMSmovingAverage(.1)))) 
                + (s + (w : RMSmovingAverage(.1)*6)) * sin(ma.PI * x) 
                    : dcblocker(1,0.998) : ma.tanh)~_ <: _,_
    with {
        s = .34;
        dcblocker(zero,pole,x) = x <: _,mem : _,*(zero) : - : + ~ *(pole);
        smic(seconds, x) = RMSmovingAverage(seconds, x);
        RMS(att,rel,x) = loop ~ _ : sqrt
            with {
                loop(y) = (1.0 - coeff) * x * x + coeff * y
                    with {
                        attCoeff = exp(-2.0 * ma.PI * ma.T / att);
                        relCoeff = exp(-2.0 * ma.PI * ma.T / rel);
                        coeff = ba.if(abs(x) > y, attCoeff, relCoeff);
                    };
            };
        // Moving Average RMS
        movingAverage(seconds, x) = x - (x @ N) : fi.pole(1.0) / N
            with {
                N = seconds * ma.SR;
            };
        RMSmovingAverage(seconds, x) = sqrt(max(0, movingAverage(seconds, x * x)));
    };

antilarsenmap(w) = \(x).(((w + (s * (1- (w : RMSmovingAverage(.1))) 
                    * sin(ma.PI * x)) : dcblocker(1,0.998) : ma.tanh)))~_ <: _,_
    with {
        s = .8;
        dcblocker(zero,pole,x) = x <: _,mem : _,*(zero) : - : + ~ *(pole);
        smic(seconds, x) = RMSmovingAverage(seconds, x);
        RMS(att,rel,x) = loop ~ _ : sqrt
            with {
                loop(y) = (1.0 - coeff) * x * x + coeff * y
                    with {
                        attCoeff = exp(-2.0 * ma.PI * ma.T / att);
                        relCoeff = exp(-2.0 * ma.PI * ma.T / rel);
                        coeff = ba.if(abs(x) > y, attCoeff, relCoeff);
                    };
            };
        // Moving Average RMS
        movingAverage(seconds, x) = x - (x @ N) : fi.pole(1.0) / N
            with {
                N = seconds * ma.SR;
            };
        RMSmovingAverage(seconds, x) = sqrt(max(0, movingAverage(seconds, x * x)));
    };

process = antilarsenmap, larsenmap;