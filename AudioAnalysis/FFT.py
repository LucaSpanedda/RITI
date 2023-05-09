# import libraries
import matplotlib.pyplot as plt
from scipy.io import wavfile as wav
from scipy.fftpack import fft
import numpy as np
import argparse

# Print the sample rate and length of the audio file in seconds
print('''
This code take as arguments the: audiofile.wav do an automatic FFT and plot the result
''')

# Parse the command line arguments
parser = argparse.ArgumentParser()
parser.add_argument("audiofilein", help="Name of the audio file with the extension")
args = parser.parse_args()

# Read the audio file
rate, data = wav.read(args.audiofilein)

# Perform the FFT
fft = np.fft.fft(data)

# Get the frequencies and amplitudes
frequencies = np.abs(fft)

# Get the frequencies corresponding to each element in the FFT result
frequencies_axis = np.fft.fftfreq(len(frequencies), d=1/rate)

# Find the halfway point in the frequencies
half_point = len(frequencies) // 2

# Plot the frequencies and amplitudes
plt.plot(frequencies_axis[:half_point], frequencies[:half_point])
plt.show()