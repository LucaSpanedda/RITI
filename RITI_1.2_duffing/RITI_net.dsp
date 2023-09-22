// Import the RITI Library
import("riti_library.lib");


Duffing_Semiautonomous_Network(N) = 
    (hgroup("Controls", CntrlSignals(N, 7, 10, 5, 10)) : hgroup("Oscillators", par(i, N, duffing_autOSC(i)))) ~    
    fullyConnectedMXDel(N) : hgroup("Controls", Stabilizer(N));
process = tgroup("RITI", Duffing_Semiautonomous_Network(8) : outputchannels);




Duffing_Ecosystemic_Semiautonomous_Network(N) = 
    (vecOp((si.bus(N) , si.bus(N)), +) : vgroup("Controls", CntrlSignals(N, 7, 10, 5, 10)) : 
        vgroup("Oscillators", par(i, N, duffing_autOSC(i)))) ~    
    fullyConnectedMXDel(N) : 
        vgroup("Controls", hgroup("Mixer", par(i, N, _ * si.smoo(hslider("Gain %i [style: knob]", 1, 0, 1, .001)))));
//process = vgroup("RITI", Duffing_Ecosystemic_Semiautonomous_Network(8)) :> _/4 , _/4;

Duffing_NetControls(N) = (netInputs : oscs) ~ fullyConnectedMXDel(N)
with{ 
    // Network
    netInputs = vecOp((si.bus(N) , si.bus(N)), +);
    oscs =  par(i, N, duffing_OSC(i));
};
//process = tgroup("RITI", Duffing_NetControls(8)) :> _/4 , _/4;

Duffing_SingleControls(N) = (netInputs : oscs) ~ fullyConnectedMXDel(N)
with{ 
    // Network
    netInputs = vecOp((si.bus(N) , si.bus(N)), +);
    oscs =  par(i, N, duffing_OSC_global(i));
};
//process = hgroup("RITI", Duffing_SingleControls(8)) :> _/4 , _/4;