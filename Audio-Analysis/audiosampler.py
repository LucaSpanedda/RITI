# import libraries
import matplotlib.pyplot as plt
from scipy.io import wavfile as wav
import scipy.io.wavfile
from scipy.fftpack import fft
import numpy as np
import wave
from playsound import playsound
import argparse

# Parse the command line arguments
parser = argparse.ArgumentParser()
parser.add_argument("audiofilein", help="Name of the audio file with the extension")
args = parser.parse_args()

# Read the audio file
rate, data = wav.read(args.audiofilein)

# Print the sample rate and length of the audio file in seconds
print('''
Sample rate:''', rate)
print('''
Length of audio file: {:.4f} seconds
'''.format(len(data)/rate))

# Initialize the chunk counter
chunk_counter = 0

while True:
    # Increment the chunk counter
    chunk_counter += 1

    # Get start and end times for the desired time range from the user
    start_time = float(input("Start time (in seconds): "))
    end_time = float(input("End time (in seconds): "))

    # Calculate start and end indices for the desired time range
    start_indexSec = int(rate * start_time)  # Start index for the start time
    end_indexSec = int(rate * end_time)      # End index for the end time

    # Extract the portion of the audio data that corresponds to the desired time range
    data_subset = data[start_indexSec:end_indexSec]

    # Create a temporary .wav file with the audio data, using the chunk counter in the file name
    scipy.io.wavfile.write('chunk' + str(chunk_counter) + '_' + args.audiofilein, rate, data_subset)

    while True:
        # Play back the temporary .wav file
        playsound('chunk' + str(chunk_counter) + '_' + args.audiofilein)

        # Prompt the user for their choice
        choice = input("Enter 'R' to repeat the playback or 'N' to select a new portion of audio: ")

        # Convert the input string to uppercase
        choice = choice.upper()

        # If the user has entered 'N', break out of the inner loop and select a new portion of audio for the data_subset function
        if choice == 'N':
            break
        # If the user has entered any other key, break out of both loops and exit the program
        else:
            continue
