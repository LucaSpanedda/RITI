# import libraries
import matplotlib.pyplot as plt
from scipy.io import wavfile as wav
import scipy.io.wavfile
from scipy.fftpack import fft
import numpy as np
import wave
from playsound import playsound
import argparse

# Print the sample rate and length of the audio file in seconds
print('''
This code take as arguments the: 
$ audiofile.wav , 
then report the information about Sample Rate and Lenght in seconds,
and separate the audio track/channels in the file into
indipendent .wav files.
After this if you choose to continue you can take desidered
audio fragments from the audio ch-1.wav
''')


# Parse the command-line arguments
parser = argparse.ArgumentParser()
parser.add_argument('input_file', help='The input .wav file')
args = parser.parse_args()

# Read the audio data and sample rate from the input .wav file
rate, data = scipy.io.wavfile.read(args.input_file)

# Print the sample rate and length of the audio file in seconds
print('''
Sample rate :''', rate)
print('''
Length of audio file : {:.4f} seconds
'''.format(len(data)/rate))

# Reshape the audio data into a matrix with one column per channel
data = data.reshape(-1, data.shape[1])

# Loop over the channels and export each channel to a separate .wav file
for i in range(data.shape[1]):
    # Extract the audio data for the current channel
    channel_data = data[:, i]

    # Generate the output filename for the current channel
    output_file = f'ch{i+1}_{args.input_file}'

    # Write the audio data and sample rate to a .wav file for the current channel
    scipy.io.wavfile.write(output_file, rate, channel_data)
