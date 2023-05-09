import math
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


def closest_note_name(freq):
    C4_frequency = (261.63 * 2)
    note_names = ['c', 'cis', 'd', 'ees', 'e', 'f', 'fis', 'g', 'gis', 'a', 'bes', 'b']
    num_half_steps = round(12 * math.log2(freq / C4_frequency))
    note_name = note_names[num_half_steps % 12]
    octave = 4 + num_half_steps // 12
    if octave < 4:
        return note_name + ("," * (4 - octave))
    else:
        return note_name + ("'" * (octave - 4))
      
# Print closest note for each frequency
for frequency in frequencies:
    closest_note = closest_note_name(frequency)
    print(closest_note)
    #print("Closest note to %.2f Hz is %s" % (frequency, closest_note))