import("RITIlibrary.lib");

network(N, global_damping, global_forcing, global_forcing_freq, global_q, global_freq_shift, global_smooth, global_gain, global_interaction, global_rev) = si.bus(2) <: (ro.interleave(N, 2) : par(i, N, si.bus(2) <: ((si.bus(2) : controlMapping(i + 1, global_damping, global_forcing, global_forcing_freq, global_q, global_freq_shift, global_smooth, global_gain, global_interaction)), si.bus(2)) : component("Duffing.dsp").duffing_riti) : reverb(N, N, 8, 2, 5, 10, global_rev) : par(i, N, LookaheadLimiter(0.98))) ~ (par(i, N, _ @ 1999) : ro.crossNM(N - 1, 1));

process = (globalNetworkGUI, ins(2)) : network(8) : outs(8, 2)
with{
    // Mixer
    ins(N) = vgroup("Mixer", hgroup("Channels", hgroup("Master", hgroup("inputs", par(i, N, * (vslider("G", -60, -60, 20, 0.001) : ba.db2linear : si.smoo))))));
    outs(N, O) = vgroup("Mixer", hgroup("Channels", hgroup("Master", hgroup("outputs", par(i, N, * (vslider("G", -60, -60, 20, 0.001) : ba.db2linear : si.smoo : _ * (O / N))))))) :> si.bus(O);
};