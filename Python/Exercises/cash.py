# Get a positive float number from user
def get_positive_float_number():
    while True:
        try:
            # Prompt user for input
            n = float(input("Cash: "))
            # Validate input
            if n > 0:
                # Return valid input
                return n
        except ValueError:
            # Ignore input that cannot be converted to a float
            pass

def cash(money):
    coins = [25, 10, 5, 1] # Define the coin values in decreasing order
    num_coins = 0
    for coin in coins:
        while money >= coin: # While the coin can be used
            money -= coin
            num_coins += 1
    # Print the number of coins needed
    print(num_coins)

if __name__ == "__main__":
    # Get the amount of money from the user
    money = get_positive_float_number()
    # Convert the amount to cents and round to the nearest penny
    money = round(money * 100)
    # Calculate the minimum number of coins needed
    cash(money)