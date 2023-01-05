# import libraries
import matplotlib.pyplot as plt
from scipy.io import wavfile as wav
from scipy.fftpack import fft
import numpy as np
import argparse

# Print the sample rate and length of the audio file in seconds
print('''
This code take as arguments the: 
$audiofile.wav $Minimum frequency in the range and $Maximum frequency in the range, 
then do an automatic FFT and plot in the result only the elements corresponding to the desired frequency range
with a boolean mask to select only the elements desidered
''')

# Parse the command line arguments
parser = argparse.ArgumentParser()
parser.add_argument("audiofilein", help="Name of the audio file with the extension")
parser.add_argument("min_frequency", type=int, help="Minimum frequency in the range")
parser.add_argument("max_frequency", type=int, help="Maximum frequency in the range")
args = parser.parse_args()

# Read the audio file
rate, data = wav.read(args.audiofilein)

# Perform the FFT
fft = np.fft.fft(data)

# Get the frequencies and amplitudes
frequencies = np.abs(fft)

# Get the frequencies corresponding to each element in the FFT result
frequencies_axis = np.fft.fftfreq(len(frequencies), d=1/rate)

# Select only the elements corresponding to the desired frequency range
selected_indices = (frequencies_axis >= args.min_frequency) & (frequencies_axis <= args.max_frequency)
selected_frequencies = frequencies[selected_indices]
selected_frequencies_axis = frequencies_axis[selected_indices]

# Plot the frequencies and amplitudes
plt.plot(selected_frequencies_axis, selected_frequencies)
plt.show()