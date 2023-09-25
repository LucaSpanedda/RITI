// Import the RITI Library
import("riti_library.lib");


Duffing_Semiautonomous_Network(N) = 
    (vgroup("Controls", hgroup("Oscillators", CntrlSignals(N, 7, 10, 5, 10))) : 
        hgroup("Inspectors", par(i, N, duffing_autOSC(i)))) ~    
    (vgroup("Controls", Matrixes)) : 
        vgroup("Controls", hgroup("Oscillators", hgroup("Output", Stabilizer(8))));
process = tgroup("RITI", Duffing_Semiautonomous_Network(8) : outputchannels);