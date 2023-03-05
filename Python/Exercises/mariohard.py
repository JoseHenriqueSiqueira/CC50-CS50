def get_positive_int():
    while True:
        try:
            # Prompt user for input
            n = int(input("Height: "))
            # Validate input
            if 1 <= n <= 8:
                # Return valid input
                return n
        except ValueError:
            # Ignore input that cannot be converted to an integer
            pass

def wall(height):
    for row in range(height):
        # Print left and right half of wall
        print(" " * (height - row - 1) + "#" * (row + 1) + "  " + "#" * (row + 1))

if __name__ == "__main__":
    # Get height from user
    n = get_positive_int()
    # Print wall of given height
    wall(n)