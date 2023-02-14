# import libraries
import argparse
import os

parser = argparse.ArgumentParser()
parser.add_argument("listsfile", help="Name of the lists file with the extension")
args = parser.parse_args()

listsfile_no_ext = os.path.splitext(args.listsfile)[0]
print(listsfile_no_ext)

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
            bandwidths = [float(x) for x in f.readline().split(", ")]

# sort the amplitudes in descending order
sorted_amplitudes = sorted(amplitudes, reverse=True)

# update the frequencies and bandwidths accordingly
sorted_frequencies = [frequencies[amplitudes.index(amp)] for amp in sorted_amplitudes]
sorted_bandwidths = bandwidths

# print the sorted lists
print("Sorted Frequencies:", sorted_frequencies)
print("Sorted Amplitudes:", sorted_amplitudes)
print("Sorted Bandwidths:", sorted_bandwidths)


# Save the selected frequencies
with open((listsfile_no_ext)+"_sortedamplitudes.txt", "w") as f:
    f.write((listsfile_no_ext)+"_frequencies = \n")
    for i in range(len(sorted_frequencies)):
        if i == len(sorted_frequencies) - 1:
            f.write(str(sorted_frequencies[i]) + " \n")
        else:
            f.write(str(sorted_frequencies[i]) + ", ")

# Save the scaled amplitudes
    f.write((listsfile_no_ext)+"_amplitudes = \n")
    for i in range(len(sorted_amplitudes)):
        if i == len(sorted_amplitudes) - 1:
            f.write(str(sorted_amplitudes[i]) + " \n")
        else:
            f.write(str(sorted_amplitudes[i]) + ", ")

# Save the bin bandwidth
    f.write((listsfile_no_ext)+"_bandwidths = \n" + str(sorted_bandwidths) + " \n")
    f.close()