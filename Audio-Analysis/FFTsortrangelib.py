# import libraries
import matplotlib.pyplot as plt
from scipy.io import wavfile as wav
from scipy.fftpack import fft
import numpy as np
import argparse
import os

# Print the sample rate and length of the audio file in seconds
print('''
This code take as arguments the: 
$audiofile.wav $Minimum frequency in the range and $Maximum frequency in the range $Number of Bins $Number of sorted peaks, 
then do an FFT in the entire spectrum multiplying the desidered number of Bins in the section
that you want to analyze with this bins for the entire spectrum. 
Then after the analysis plot in the result only the elements sorted by amplitudes from the highest peak
''')

# Parse the command line arguments
parser = argparse.ArgumentParser()
parser.add_argument("audiofilein", help="Name of the audio file with the extension")
parser.add_argument("min_frequency", type=int, help="Minimum frequency in the range")
parser.add_argument("max_frequency", type=int, help="Maximum frequency in the range")
parser.add_argument("num_bins", type=int, help="Number of Bins")
parser.add_argument("num_sortedelements", type=int, help="Number of sorted elements")
args = parser.parse_args()

# Read the audio file
rate, data = wav.read(args.audiofilein)
print(f"Sample Rate of the audio file: {rate}")

# calculate the number of bin for your Hz range
resolutionbin = ((20000 / (args.max_frequency - args.min_frequency)) * args.num_bins)
print(f"Number of Bins necessary in the full spectrum for your bin N in your range: {resolutionbin}")

# number of bins used for the fft
numberofbins = int( (resolutionbin / 20000) * rate)

# Perform the FFT with numberofbins bins
fft = np.fft.fft(data, n=(numberofbins))

# Get the frequencies and amplitudes
frequencies = np.abs(fft)

# Get the frequencies corresponding to each element in the FFT result
frequencies_axis = np.fft.fftfreq(len(frequencies), d=1/rate)

# Calculate the bin bandwidth
bin_bandwidth = rate / (numberofbins)

# Select only the elements corresponding to the desired frequency range
selected_indices = (frequencies_axis >= args.min_frequency) & (frequencies_axis <= args.max_frequency)
selected_amplitudes_axis = frequencies[selected_indices]
selected_frequencies_axis = frequencies_axis[selected_indices]

# Normalize the selected amplitudes
normalized_amplitudes = selected_amplitudes_axis / np.max(selected_amplitudes_axis)

# Scale the normalized amplitudes to the desired range (0 to 1 in this example)
scaled_amplitudes = normalized_amplitudes * 1

# Plot the scaled amplitudes
plt.plot(selected_frequencies_axis, scaled_amplitudes)
plt.show()

# Use os.path.splitext to split the extension from the root
newfilename = (args.audiofilein)
root, ext = os.path.splitext(newfilename)

# Sort the amplitudes in descending order
sorted_indices = np.argsort(-scaled_amplitudes)

# Get the highest 1000 amplitudes
highest_amplitudes = scaled_amplitudes[sorted_indices][:args.num_sortedelements]

# Get the corresponding frequencies
highest_frequencies = selected_frequencies_axis[sorted_indices][:args.num_sortedelements]

# Save the selected frequencies
with open((root)+".lib", "w") as f:
    f.write((root)+"_frequencies = (\n")
    for i in range(len(highest_frequencies)):
        if i == len(highest_frequencies) - 1:
            f.write(str(highest_frequencies[i]) + ") ; \n \n")
        else:
            f.write(str(highest_frequencies[i]) + ", ")

# Save the scaled amplitudes
    f.write((root)+"_amplitudes = (\n")
    for i in range(len(highest_amplitudes)):
        if i == len(highest_amplitudes) - 1:
            f.write(str(highest_amplitudes[i]) + ") ; \n \n")
        else:
            f.write(str(highest_amplitudes[i]) + ", ")

# Save the bin bandwidth
    f.write((root)+"_bandwidths = (\n" + str(bin_bandwidth) + "\n) ; \n")