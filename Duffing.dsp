import("RITIlibrary.lib");

// Constrictions
constraints(partials, program, fshift, q, smooth, g) = atan :
    bpfiltersbank(partials, program, fshift, q, 1) :
    fi.dcblocker : lptpt(smooth) * g;

// duffing oscillator - parameters for chaotic regime
duffing = f ~ si.bus(2)
with {
    // duffing equation (euler)
    f(x, y) = x + (y * dt) + initX,
        y + ((-delta * y - alpha*x - beta * x * x * x + gamma * cos(omega*time)) * dt) + initY;
    // parameters
    dt = 0.01;
    delta = 0.2;      // Damping
    alpha = -1.0;     // Negative linear term (bistable system)
    beta = 1.0;       // Nonlinear term
    gamma = 0.3;      // Forcing amplitude
    omega = 1.0;      // Forcing frequency
    // Time counter
    time = (+(dt) ~ _);
    // Initial conditions
    x0 = 0.1;
    y0 = 0.2;
    initX = x0 - mem(x0);
    initY = y0 - mem(y0);
};
//process = duffing : par(i, 2, _ * 0.5);

// single circuit - semplified duffing oscillator
duffing_semplified(dt, damping, forcing, forcingfreq) =
    ((_, _) <: (_ + _ * dt),
    ((((_, !) <: (_ - (_ * _ * _))) - ((!, _) <: damping * _) + (forcing * cos(forcingfreq * (+ (dt) ~ _)))) * dt + (!, _))) ~ si.bus(2);
//process = duffing_semplified(0.01, 0.2, 0.3, 1.0) : par(i, 2, _ * 0.5);

// semplified modified duffing oscillator - switch between original oscillator and modified version
duffing_switch(mode, dt, damping, forcing, forcingfreq, bpQ, bpFshift, bpSmooth, bpGain, bpProgram) =
    f ~ si.bus(2) : switch2(mode)
with {
    f(x, y) = ((x + (y * dt)), (x + y : constraints(24, bpProgram, bpFshift, bpQ, bpSmooth, 1))) : switch(mode),
    y + (((x - (x * x * x)) - (damping * y) + forcing * cos(forcingfreq * time)) * ((dt, 1) : switch(mode)));
    time = (+ ((dt, (4 / ma.SR)) : switch(mode)) ~ _);
    switch(mode, x, y) = x * (1 - mode) + y * mode;
    switch2(mode, x, y) = (x * (1 - mode), y * (1 - mode)), (x * mode, x * mode) :> par(i, 2, _ * 0.5);
};
//process = (modeGUI, dtVal, GUI(1)) : duffing_switch;

// single circuit - semplified modified duffing oscillator - switch between original oscillator and modified version
duffing_semplified_switch(mode, dt, damping, forcing, forcingfreq, bpQ, bpFshift, bpSmooth, bpGain, bpProgram) =
    ((_, _) <: ((_, _) <: ((_ + (_ * dt)), (_ + _ : constraints(24, bpProgram, bpFshift, bpQ, bpSmooth, 1))) : switch(mode)),
    ((((_, !) <: (_ - (_ * _ * _))) - ((!, _) <: damping * _) + (forcing * cos(forcingfreq * (+ ((dt, (4 / ma.SR)) : switch(mode)) ~ _)))) * ((dt, 1) : switch(mode)) + (!, _))) ~ si.bus(2) : switch2(mode)
with {
    switch(mode, x, y) = x * (1 - mode) + y * mode;
    switch2(mode, x, y) = (x * (1 - mode), y * (1 - mode)), (x * mode, x * mode) :> par(i, 2, _ * 0.5);
};
//process = (modeGUI, dtVal, GUI(1)) : duffing_semplified_switch;

// single circuit - semplified modified duffing oscillator
duffing_semplified_modified(damping, forcing, forcingfreq, bpQ, bpFshift, bpSmooth, bpGain, bpProgram) =
    ((_, _) <: (_ + _ : constraints(24, bpProgram, bpFshift, bpQ, bpSmooth, 1)),
    ((((_, !) <: (_ - (_ * _ * _))) - ((!, _) <: damping * _) + (forcing * cos(forcingfreq * (+ (4 / ma.SR) ~ _)))) + (!, _))) ~ si.bus(2) : (_ * 0.5, !);
//process = GUI(1) : duffing_semplified_modified <: si.bus(2);

// f(x) solved in the real space - single circuit - semplified modified duffing oscillator
duffing_modified_realspace(damping, forcing, forcingfreq, bpQ, bpFshift, bpSmooth, bpGain, bpProgram) = _ :
    ((ro.cross(2) <: (_ + _ : constraints(24, bpProgram, bpFshift, bpQ, bpSmooth, 1)),
    ((((_, !) <: (_ - (_ * _ * _))) - ((!, _) <: damping * _) + (forcing * cos(forcingfreq * (+ (4 / ma.SR) ~ _)))) + (!, _))) : ro.cross(2)) ~ _ : (!, _ * 0.25);
//process = (GUI(1), _) : duffing_modified_realspace <: si.bus(2);

// single circuit - semplified modified duffing oscillator
duffing_riti(damping, forcing, forcingfreq, bpQ, bpFshift, bpSmooth, bpGain, bpProgram, interaction, influence, extMic) =
    ((_, _) <: (_ + _ : constraints(24, bpProgram, bpFshift, bpQ, bpSmooth, bpGain)),
    ((((_, !) <: (_ - (_ * _ * _))) - ((!, _) <: ma.tanh(damping + influence * interaction) * _) + (extMic + forcing * cos((+ (forcingfreq / ma.SR) ~ _)))) + (!, _))) ~ si.bus(2) : (_ * 0.5, !);

// Test
// Graphic User Interface
GUI(i) = dampingGUI, forcingGUI, forcingfreqGUI, bpQGUI, bfFshiftGUI, bpSmoothGUI, bpGainGUI, bpprogramGUI(i), interactionGUI, _, 0
with{
    modeGUI = checkbox("mode");
    dtVal = 0.01;
    dampingGUI = hslider("damping", 0.2, 0, 1.0, 0.001) : si.smoo;
    forcingGUI = hslider("forcing", 0.3, 0, 1.0, 0.001) : si.smoo;
    forcingfreqGUI = hslider("freq", 1.0, 0, 400.0, 0.001) : si.smoo;
    bpQGUI = hslider("Q", 100, 0.1, 400, 0.001) : si.smoo;
    bfFshiftGUI = 8 ^ hslider("F", -0.5, -1, 1.0, 0.001) : si.smoo;
    bpSmoothGUI = 20000 * hslider("smooth", 1, 0.001, 1, 0.001) : si.smoo;
    bpGainGUI = hslider("G", 1, 0, 1, 0.001) : si.smoo;
    bpprogramGUI(i) = hgroup("BP presets", hslider("osc %i[style:knob]", i, 1, 20, 1) - 1);
    interactionGUI = hslider("interaction", 1, 0, 1, 0.001) : si.smoo;
};

single_oscillator = GUI(1) : duffing_riti <: si.bus(2);
coupled_oscillators = par(i, 2, (GUI(i + 1)) : duffing_riti) ~ (par(i, 2, _ @ 1999) : ro.cross(2));
network_oscillators(N) = par(i, N, (GUI(i + 1)) : duffing_riti) ~ (par(i, N, _ @ 1999) : ro.crossNM(N - 1, 1));

//process = single_oscillator;
//process = coupled_oscillators;
process = network_oscillators(8) :> par(i, 2, _ / 4);
