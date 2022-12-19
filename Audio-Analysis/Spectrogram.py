# Python example - Fourier transform using numpy.fft method
# librerie
import pyACA
import numpy as np
from scipy import signal
import matplotlib.pyplot as plt
from scipy.io.wavfile import read


# leggiamo un file audio mono importandolo da terminale
audiofile = input("Enter your file name (without extension):")

# leggiamo un file audio(file audio mono)
[fs, x] = pyACA.ToolReadAudio(audiofile+".wav")

# normalizziamo il file audio(a 0 dB)
x = x/np.max(abs(x))

# How many time points are needed i,e., Sampling Frequency
samples = 44100;
samplingFrequency   = 1 * samples;

# At what intervals time points are sampled
samplingInterval       = 1 / samplingFrequency;
# Begin time period of the signals
beginTime   = 0;
# End time period of the signals
endTime     = 10;

# Time points
time = np.arange(beginTime, endTime, samplingInterval);
#
amplitude = x
# Frequency domain representation
fourierTransform = np.fft.fft(amplitude)/len(amplitude)
# Normalize amplitude
fourierTransform = fourierTransform[range(int(len(amplitude)/2))]
# Exclude sampling frequency

tpCount     = len(amplitude)
values      = np.arange(int(tpCount/2))
timePeriod  = tpCount/samplingFrequency
frequencies = values/timePeriod

# Frequency domain representation
# Create subplot
plt.subplot(1,1,1)
plt.grid()
plt.plot(frequencies, abs(fourierTransform), color='k', alpha=0.8, linewidth=0.8)
plt.xlabel('Frequency')
plt.ylabel('Amplitude')
plt.show()
