def get_positive_int():
    while True:
        try:
            # Prompt user for input
            n = int(input("Card Number: "))
            # Validate input
            if n > 0:
                # Return valid input
                return n
        except ValueError:
            # Ignore input that cannot be converted to an integer
            pass

def determine_card_type(card):
    # Get the length of the card number
    length = 0
    temp = card
    while temp > 0:
        temp //= 10
        length += 1
    # Check if card number has a valid length
    if length != 13 and length != 15 and length != 16:
        return "INVALID"
    # Get the first two digits of the card number
    first_two_digits = card // pow(10, length - 2)
    # Calculate sum of digits
    sum = 0
    digit = 0
    double_digit = False
    for i in range(length - 1, -1, -1):
        digit = card % 10
        card //= 10
        if double_digit:
            digit *= 2
            if digit >= 10:
                sum += digit // 10
                sum += digit % 10
            else:
                sum += digit
        else:
            sum += digit
        double_digit = not double_digit
    # Check if the sum of digits is divisible by 10
    if sum % 10 != 0:
        return "INVALID"
    # Check if the card is AMEX, MASTERCARD, or VISA based on the first two digits
    if length == 15 and (first_two_digits == 34 or first_two_digits == 37):
        return "AMEX"
    elif length == 16 and first_two_digits >= 51 and first_two_digits <= 55:
        return "MASTERCARD"
    elif (length == 13 or length == 16) and (first_two_digits // 10 == 4):
        return "VISA"
    else:
        return "INVALID"

if __name__ == "__main__":
    # Get card number from user
    card = get_positive_int()
    card_type = determine_card_type(card)
    print(card_type)