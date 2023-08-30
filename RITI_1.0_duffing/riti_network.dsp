// Import the RITI Library
import("riti_library.lib");


// RITI Network
Duffing_Semiautonomous_Network(N) = (netInputs : netAUTOcntrl : oscs) ~ fullyConnectedMXDel(N)
with{ 
    // Network
    netInputs = vecOp((si.bus(N) , si.bus(N)), +);
    netAUTOcntrl = par(i, N, (_ : cntrl(1, 1, 10, 5, i, 1 + (i * 10))));
    cntrl(range, lerpSec, slowrangeSec, fastrangeSec, diffSec, diffPH, x) = 
         x, 
        (x <: 
            par(i, 7, cntrlSigSAH(range, lerpSec, slowrangeSec, fastrangeSec + (i * .1 * diffSec), ph(i + diffPH), i))
        )
    with{
        ph(i) = noise(ba.take(i, Primes)) : triggerSAH;
        triggerSAH(y) = out ~ _
        with{
            ph = vgroup("Controls", button("trigger"));
            trigger = ph > ph';
            iniTrig = 1@512 - 1@513;
            out(x) = trigger : (_ + iniTrig, x, y) : selector;
        };
    };
    oscs =  par(i, N, duffing_autOSC(i));
};
//process = hgroup("RITI", Duffing_Semiautonomous_Network(8)) :> _/4 , _/4;

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
process = hgroup("RITI", Duffing_SingleControls(8)) :> _/4 , _/4;