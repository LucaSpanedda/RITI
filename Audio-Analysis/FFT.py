"""import numpy as np
import matplotlib.pyplot as plt
import scipy.fftpack

# Number of samplepoints
N = 128     # considera sempre il risultato / 2
# sample spacing
T = 1.0 / 44100.0
x = np.linspace(0.0, N*T, N)
y = 
yf = scipy.fftpack.fft(y)
xf = np.linspace(0.0, 1.0/(2.0*T), N//2)

print(len(abs(yf)))

fig, ax = plt.subplots()
ax.plot(xf, 2.0/N * np.abs(yf[:N//2]))
plt.show()
"""

import matplotlib.pyplot as plt
from scipy.io import wavfile as wav
from scipy.fftpack import fft
import numpy as np

# import file audio
audiofilein = input("Import wav audio file with extension: ")
rate, data = wav.read(audiofilein)

bins = input("How much Bins for the FFT Analysis: ")
N = int(bins) * 2 # usciranno 200 valori
T = 1.0 / 44100.0
xf = np.linspace(0.0, 1.0/(2.0*T), N//2)

fft_out = fft(data, N)
fft_trunc = []
for n in range(int(len(fft_out)/2)):
    fft_trunc.append(fft_out[n])

amp_out = 2.0/N * np.abs(fft_trunc[:N//2])

amp_out = amp_out[1:]
fft_trunc = fft_trunc[1:]
xf = xf[1:]

nFilters = int(input("How much partials do you want to plot: "))

array2d = []
for n in range(len(amp_out)):
    array2d.append([amp_out[n], xf[n]])

final_amp = []
final_freq = []

ampampa = amp_out.copy()
ampampa.sort()
ampampa = ampampa[::-1]

for i in ampampa:
    for n in range(len(array2d)):
        if (i == array2d[n][0]):
            final_amp.append(array2d[n][0])
            final_freq.append(array2d[n][1])

with open("amplitudes.txt", "w") as f:
    for i in range(nFilters):
        if (i < nFilters-1):
            f.write(str(final_amp[i])+", ")
        else:
            f.write(str(final_amp[i]))
    f.close() 

with open("frequencies.txt", "w") as f:
    for i in range(nFilters):
        if (i < nFilters-1):
            f.write(str(final_freq[i])+", ")
        else:
            f.write(str(final_freq[i]))
    f.close()

bw = (44100 / int(bins)) * 0.5
with open("bandwidth.txt", "w") as f:
    for i in range(nFilters):
        if (i < nFilters-1):
            f.write(str(1)+", ")
        else:
            f.write(str(1))
    f.close()

fig, ax = plt.subplots()
ax.plot(xf, amp_out)
plt.show()