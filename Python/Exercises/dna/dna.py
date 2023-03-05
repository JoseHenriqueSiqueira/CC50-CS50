import csv
import sys

def main():
    # Check for correct command line arguments
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # Read in database file and populate list of profiles
    try:
        profiles = []
        with open(sys.argv[1], mode="r") as database_file:
            reader = csv.DictReader(database_file)
            STRs = reader.fieldnames[1:] # Extract STR names from header row
            for row in reader:
                profiles.append(row)
    except FileNotFoundError:
        print(f"Could not open file: {sys.argv[1]}")
        sys.exit(1)

    # Read in sequence file and count STRs
    try:
        with open(sys.argv[2], mode="r") as sequence_file:
            sequence = sequence_file.readline().strip() # Read first line and remove newline character
            seq_str_count = count_str(sequence, STRs)
    except FileNotFoundError:
        print(f"Could not open file: {sys.argv[2]}")
        sys.exit(1)

    # Find matching profile, if any
    match = find_match(profiles, seq_str_count, STRs)
    if match:
        print(match["name"])
    else:
        print("No match")

def count_str(sequence, STRs):
    # Initialise dictionary to store STR counts
    str_count = {}
    for str in STRs:
        max_count = 0
        i = 0
        # Loop over sequence and count number of consecutive STR repeats
        while i < len(sequence):
            count = 0
            while sequence[i:i + len(str)] == str:
                count += 1
                i += len(str)
            max_count = max(max_count, count)
            i += 1
        str_count[str] = max_count
    return str_count

def find_match(profiles, seq_str_count, STRs):
    # Loop over each profile and compare STR counts with sequence STR counts
    for profile in profiles:
        if all(int(profile[str]) == seq_str_count[str] for str in STRs):
            return profile
    return None

if __name__ == "__main__":
    main()