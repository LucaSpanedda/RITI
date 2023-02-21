# import libraries
import argparse
import os
import numpy as np


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


# create a mask to remove frequencies within 40Hz of each other
to_delete = []

for i in range(len(frequencies)):
    for j in range(i+1, len(frequencies)):
        if abs(frequencies[i] - frequencies[j]) < 40:
            to_delete.append(j)

mask = np.ones(len(frequencies), dtype=bool)
mask[to_delete] = False

# use the mask to filter the frequencies and amplitudes lists
filtered_frequencies = np.array(frequencies)[mask]
filtered_amplitudes = np.array(amplitudes)[mask]

# sort the amplitudes in descending order
sorted_amplitudes = sorted(filtered_amplitudes, reverse=True)

# update the frequencies and bandwidths accordingly
sorted_frequencies = [filtered_frequencies[np.where(filtered_amplitudes == amp)[0][0]] for amp in sorted_amplitudes]

# Use os.path.splitext to split the extension from the root
newfilename = (args.listsfile)
root, ext = os.path.splitext(newfilename)

# number of frequencies 
print("you have in the list", len(filtered_frequencies), "frequencies")


# Save the selected frequencies and amplitudes
with open((listsfile_no_ext)+".txt", "w") as f:
    f.write((listsfile_no_ext)+"_frequencies = \n")
    for i in range(min(len(sorted_frequencies), 32)):
        if i == min(len(sorted_frequencies), 32) - 1:
            f.write(str(sorted_frequencies[i]) + " \n")
        else:
            f.write(str(sorted_frequencies[i]) + ", ")
    
    f.write((listsfile_no_ext)+"_amplitudes = \n")
    for i in range(min(len(sorted_amplitudes), 32)):
        if i == min(len(sorted_amplitudes), 32) - 1:
            f.write(str(sorted_amplitudes[i]) + " \n")
        else:
            f.write(str(sorted_amplitudes[i]) + ", ")

    # Save the bin bandwidth
    f.write((listsfile_no_ext) + "_bandwidths = " + format(bandwidths, '.8f') + "\n")

print("you have in the list", len(filtered_frequencies), "frequencies")

# print the generated .txt file
print("Contents of your data stored in the file: ")
with open((listsfile_no_ext)+".txt", 'r') as f:
    file_contents = f.read()
    print(file_contents)