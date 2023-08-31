// Import the RITI Library
import("riti_library.lib");

// RITI Network
Duffing_Semiautonomous_Network(N) = 
    (vecOp((si.bus(N) , si.bus(N)), +) : CntrlSignals(N, 7, 10, 5, 10) : 
        vgroup("Oscillators", par(i, N, duffing_autOSC(i)))) ~    
    fullyConnectedMXDel(N) : 
        vgroup("Mixer", par(i, N, _ * si.smoo(hslider("Gain %i", 1, 0, 1, .001))));
process = hgroup("RITI", Duffing_Semiautonomous_Network(8)) :> _/4 , _/4;

// RITI Network
Duffing_NetControls(N) = (netInputs : oscs) ~ fullyConnectedMXDel(N)
with{ 
    // Network
    netInputs = vecOp((si.bus(N) , si.bus(N)), +);
    oscs =  par(i, N, duffing_OSC(i));
};
//process = tgroup("RITI", Duffing_NetControls(8)) :> _/4 , _/4;

// RITI Network
Duffing_SingleControls(N) = (netInputs : oscs) ~ fullyConnectedMXDel(N)
with{ 
    // Network
    netInputs = vecOp((si.bus(N) , si.bus(N)), +);
    oscs =  par(i, N, duffing_OSC_global(i));
};
//process = hgroup("RITI", Duffing_SingleControls(8)) :> _/4 , _/4;