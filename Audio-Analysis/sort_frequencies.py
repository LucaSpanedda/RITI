# import libraries
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("listsfile", help="Name of the lists file with the extension")
args = parser.parse_args()

with open(args.listsfile) as f:
    data = f.readlines()
frequencies = list(map(float, data[0].strip().split("=")[1].strip().split(",")))
amplitudes = list(map(float, data[1].strip().split("=")[1].strip().split(",")))
bandwidths = list(map(float, data[2].strip().split("=")[1].strip().split(",")))

print("Frequencies: ", frequencies)
print("Amplitudes: ", amplitudes)
print("Bandwidths: ", bandwidths)

def sort_frequencies(frequencies, amplitudes, bandwidths):
    zipped = zip(frequencies, amplitudes)
    sorted_zipped = sorted(zipped, key=lambda x: x[0])
    sorted_frequencies, sorted_amplitudes = zip(*sorted_zipped)
    return list(sorted_frequencies), list(sorted_amplitudes), bandwidths

result = sort_frequencies(frequencies, amplitudes, bandwidths)
print(result)