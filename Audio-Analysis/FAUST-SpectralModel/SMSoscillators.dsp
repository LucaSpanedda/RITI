// Faust standard libraries
import("stdfaust.lib");

// Spectral Modeling Synthesis
// https://en.wikipedia.org/wiki/Spectral_modeling_synthesis


// INSTRUMENT SPECTRE --------------------------------------
// Import lists: Frequencies, Amps, Bandwidth
spectrefreq = component("frequencies.dsp").frequencieslist;
spectreamps = component("amplitudes.dsp").amplitudeslist;
spectreband = component("bandwidths.dsp").bandwidthslist;
// index of the lists
Flist(index) = ba.take(index + 1, spectrefreq);
Alist(index) = ba.take(index + 1, spectreamps);
BWlist(index) = ba.take(index + 1, spectreband);


oscillatorbanks(B, G, S) = par(i, B, ( os.osc(Flist(i) * S) * 
                                                    Alist(i) 
                                            ) * (G)
                                    ):> (+/B);
//process = oscillatorbanks(32, 400, 1) <: _,_;     

// SMS Out
process = oscillatorbanks(128, 10, 1) <: _,_;