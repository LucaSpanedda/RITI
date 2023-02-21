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

# sort the amplitudes in descending order
sorted_amplitudes = sorted(amplitudes, reverse=True)

# update the frequencies and bandwidths accordingly
sorted_frequencies = [frequencies[amplitudes.index(amp)] for amp in sorted_amplitudes]
sorted_bandwidths = bandwidths

# Use os.path.splitext to split the extension from the root
newfilename = (args.listsfile)
root, ext = os.path.splitext(newfilename)

# Save the selected frequencies
with open((root)+".txt", "w") as f:
    f.write((root)+"_frequencies = \n")
    for i in range(len(sorted_frequencies)):
        if i == len(sorted_frequencies) - 1:
            f.write(format(sorted_frequencies[i], '.8f') + " \n")
        else:
            f.write(format(sorted_frequencies[i], '.8f') + ", ")

# Save the scaled amplitudes
    f.write((root)+"_amplitudes = \n")
    for i in range(len(sorted_amplitudes)):
        if i == len(sorted_amplitudes) - 1:
            f.write(format(sorted_amplitudes[i], '.8f') + " \n")
        else:
            f.write(format(sorted_amplitudes[i], '.8f') + ", ")

# Save the bin bandwidth
    f.write((listsfile_no_ext) + "_bandwidths = " + format(bandwidths, '.8f') + "\n")
    f.close()  


# print the generated .txt file
print("Contents of your data stored in the file: ")
f = open((root)+".txt", 'r')
file_contents = f.read()
print(file_contents)
f.close()