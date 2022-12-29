'''
FFT CODE not sorted
'''
import matplotlib.pyplot as plt
from scipy.io import wavfile as wav
from scipy.fftpack import fft
import numpy as np

# import file audio
audiofilein = input("Import wav audio file with extension: ")
rate, data = wav.read(audiofilein)

# Set start and end frequencies for plot
start_freq = int(input("Analysis Start from Hz?: "))
end_freq = int(input("Analysis End at Hz?: "))

bins = input("How much Bins for the FFT Analysis: ")
bins = int(bins) # convert to integer

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

# Get indices of start and end frequencies
start_index = np.argmin(np.abs(xf - start_freq))
end_index = np.argmin(np.abs(xf - end_freq))

# Get amplitudes and frequencies for the specified range
amp_out_range = amp_out[start_index:end_index+1]
xf_range = xf[start_index:end_index+1]

# Normalize amplitudes to range [0, 1]
max_amplitude = max(amp_out_range)
normalized_amp_out_range = [amplitude/max_amplitude for amplitude in amp_out_range]

# Save normalized amplitudes to text file
with open("normalized_amplitudes.txt", "w") as f:
    for i, amplitude in enumerate(normalized_amp_out_range):
        if i == len(normalized_amp_out_range) - 1:
            f.write(str(amplitude))
        else:
            f.write(str(amplitude) + ",")

# Save frequencies to text file
with open("frequencies.txt", "w") as f:
    for i, frequency in enumerate(xf_range):
        if i == len(xf_range) - 1:
            f.write(str(frequency))
        else:
            f.write(str(frequency) + ",")

# Calculate bandwidth of each bin
bandwidth = (end_freq - start_freq) / bins

# Save bandwidth to text file
with open("bandwidth.txt", "w") as f:
    f.write(str(bandwidth))


'''
SORTED files part of the code
'''
# Read in amplitudes, frequencies, and bandwidth
with open("normalized_amplitudes.txt") as f:
    amplitudes = [float(line.strip()) for line in f.read().split(',')]

with open("frequencies.txt") as f:
    frequencies = [float(line.strip()) for line in f.read().split(',')]

with open("bandwidth.txt") as f:
    bandwidth = float(f.read().strip())

# Zip amplitudes and frequencies together
amplitude_frequency_pairs = list(zip(amplitudes, frequencies))

# Sort pairs by amplitudes in descending order
sorted_pairs = sorted(amplitude_frequency_pairs, key=lambda x: x[0], reverse=True)

# Unpack sorted pairs into separate lists
sorted_amplitudes, sorted_frequencies = zip(*sorted_pairs)

# Save sorted amplitudes to text file
with open("sorted_amplitudes.txt", "w") as f:
    for amplitude in sorted_amplitudes:
        f.write(str(amplitude) + "\n")

# Save sorted frequencies to text file
with open("sorted_frequencies.txt", "w") as f:
    for frequency in sorted_frequencies:
        f.write(str(frequency) + "\n")

# Save bandwidth to text file
with open("bandwidth.txt", "w") as f:
    f.write(str(bandwidth))


'''
PLOT the first part of the code, FFT
'''
# plot
fig, ax = plt.subplots()
ax.plot(xf_range, normalized_amp_out_range)
plt.show()