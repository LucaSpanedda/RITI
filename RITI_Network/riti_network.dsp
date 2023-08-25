// Import the RITI Library
import("riti_library.lib");

// RITI Network
Network(N) = (netInputs : oscs) ~ fullyConnectedMXDel(N)
             : par(i, N, LookaheadLimiter(.8, .1, 10))
with{
    // Network
    netInputs = vecOp((si.bus(N) , si.bus(N)), +);
    // Duffing Oscillator
    oscs =  par(i, N, duffing_osc(i, _)); 
};

process = vgroup("RITI", Network(4));