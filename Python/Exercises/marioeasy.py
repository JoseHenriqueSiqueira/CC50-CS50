def get_positive_int():
    while True:
        try:
            n = int(input("Height: "))
            if 1 <= n <= 8:
                return n
        except ValueError:
            pass

def bridge(height):
    for row in range(height):
        print(" " * (height - row - 1) + "#" * (row + 1))

if __name__ == "__main__":
    n = get_positive_int()
    bridge(n)