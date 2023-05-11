import("stdfaust.lib");

// select a point between multiple points
selectN0(N,i) = selectN0X(N, i, selector0)
with {
    // binary selector 0 - 1
    selector(sel, x, y) = ( x * (1 - sel) + y * (sel) );
    selector0(i, j, x, y) = selector((i >= j), x, y);
    selectN0X(N,i,sel) = S(N,0)
        with {
            S(1, offset) = _;
             S(n, offset) = S(left, offset), S(right, offset+left) : sel(i, offset+left)
                with {
                    right = int(n/2);
                    left  = n-right;
                };
        };
};

// interpolate multiple points
lerpMulti(points, ph) = (1.0 - D) * selN0 + D * selN1
    with {
        intPart = int(ph * points);
        D = ph * points - int(ph * points);
        selN0 = selectN0(points, intPart + 0, si.bus(points));
        selN1 = selectN0(points, intPart + 1, si.bus(points));
    };

phasor = hslider("phasor", 0, 0, 1, .001) : si.smoo;
process = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10) <: lerpMulti(10, phasor);