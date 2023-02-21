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

def sort_frequencies(frequencies, amplitudes, bandwidths):
    zipped = zip(frequencies, amplitudes)
    sorted_zipped = sorted(zipped, key=lambda x: x[0])
    sorted_frequencies, sorted_amplitudes = zip(*sorted_zipped)
    return list(sorted_frequencies), list(sorted_amplitudes), bandwidths
result = sort_frequencies(frequencies, amplitudes, bandwidths)
sorted_frequencies, sorted_amplitudes, sorted_bandwidths = result

# Save the selected frequencies
with open((listsfile_no_ext)+".txt", "w") as f:
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
    f.write((listsfile_no_ext) + "_bandwidths = " + format(bandwidths, '.8f') + "\n")
    f.close()  


# print the generated .txt file
print("Contents of your data stored in the file: ")
f = open((listsfile_no_ext)+".txt", 'r')
file_contents = f.read()
print(file_contents)
f.close()