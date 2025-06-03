# RITI : Room Is The Instrument

RITI: Room Is The Instrument is a piece based on a complex system capable of manifesting emergent and chaotic behaviors, where the acoustic personality of an environment (digital or physical) becomes a case of study for the performance and is reflected in terms of variation in the behavior of the system itself.

The first verison of the piece was conceived during the period of study for the Master's Degree at the Santa Cecilia Conservatory in Rome, 
with the help of the supervisor and correlators: Giuseppe Silvi, Agostino Di Scipio and Dario Sanfilippo.

The system is constructed using solutions of differential equations of chaotic systems (The Lorenz Attractor, The Duffing Oscillator)
used as the engine of sound synthesis, appropriately influenced by filter banks whose function are to simulate through an acoustic modeling approach
certain signals (of musical instruments or other) allowing during the performance the occurrence of modal resonances reminiscent of the behavior of a musical instrument.

The idea for the acronym RITI comes from a famous paper by Agostino Di Scipio, Sound is the interface (SITI), in which he introduced the ability of a system to self-observe itself through its environment.

In the version presented here, the analysis of some cello notes are used to influence the forced Duffing oscillators, 
whose parameters are modified in real time by the performer exploring their transitions between the modal resonances of the instrument and the threshold of chaos.
The system is in a semi-autonomous configuration, meaning that it is capable of autonomy and the action of the performer can potentially affect the behavior of the system during the course of the performance

### compile for Linux with faust2alqt

```
git clone --depth 1 --branch main https://github.com/LucaSpanedda/RITI.git && cd RITI && faust2alqt -double RITI.dsp && ./RITI

```
