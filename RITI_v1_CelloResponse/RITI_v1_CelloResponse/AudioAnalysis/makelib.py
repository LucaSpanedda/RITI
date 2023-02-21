# import libraries
import argparse
import os

parser = argparse.ArgumentParser()
parser.add_argument("listsfile", help="Name of the lists file with the extension")
args = parser.parse_args()

listsfile_no_ext = os.path.splitext(args.listsfile)[0]

with open(args.listsfile) as f:
    frequencies = []
    amplitudes = []
    bandwidths = []
    for line in f:
        if listsfile_no_ext+"_frequencies" in line:
            frequencies = [float(x) for x in f.readline().split(", ")]
        elif listsfile_no_ext+"_amplitudes" in line:
            amplitudes = [float(x) for x in f.readline().split(", ")]
        elif listsfile_no_ext+"_bandwidths" in line:
            bandwidths = float(line.split("=")[1])

# Save the selected frequencies
with open((listsfile_no_ext)+".lib", "w") as f:
    f.write((listsfile_no_ext)+"_frequencies = (\n")
    for i in range(len(frequencies)):
        if i == len(frequencies) - 1:
            f.write(str(frequencies[i]) + "\n ) ; \n \n")
        else:
            f.write(str(frequencies[i]) + ", ")

# Save the scaled amplitudes
    f.write((listsfile_no_ext)+"_amplitudes = (\n")
    for i in range(len(amplitudes)):
        if i == len(amplitudes) - 1:
            f.write(str(amplitudes[i]) + "\n ) ; \n \n")
        else:
            f.write(str(amplitudes[i]) + ", ")

# Save the bin bandwidth
    f.write((listsfile_no_ext) + "_bandwidths = (\n" + format(bandwidths, '.8f') + "\n ) ; \n")
    f.close()  