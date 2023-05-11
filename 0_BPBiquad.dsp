import("stdfaust.lib");

BPBiquad(G, Q, CF, X) = y 
    letrec {
        'y = b0 * x + b1 * x' + b2 * x'' - a1 * y - a2 * y';
    where      
        x = X * G;   
        w = 2.0 * ma.PI * CF * ma.T;
        alpha = sin(w) / (2.0 * Q);
        a0 = 1.0 + alpha;
        a1 = (-2.0 * cos(w)) / a0;
        a2 = (1.0 - alpha) / a0;
        b0 = (Q * alpha) / a0;
        b1 = 0;
        b2 = (-Q * alpha) / a0;
    };

process = (no.noise : BPBiquad(.1, 400, 440));