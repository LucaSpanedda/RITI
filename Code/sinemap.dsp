// import Standard Faust library
import("stdfaust.lib");
sinemap(x0) = (circuit : fi.dcblocker : ma.tanh)~ _
    with {
        circuit(x) =    (xInit-xInit') + mu * 
                        sin(ma.PI * ((x0 * fbAnalg) + (x * fbDigtl)));
        fbDigtl = hslider("fb Digital", 1, .0, 1.0, .001);
        fbAnalg = hslider("fb Analogs", 0, .0, 1.0, .001);
        xInit = .5;
        mu = hslider("s", .8, 0, 10, .001);
    };
process = _ : sinemap <: _,_;
