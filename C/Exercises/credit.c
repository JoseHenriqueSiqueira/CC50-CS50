#include <cs50.h>
#include <stdio.h>
#include <math.h>

// Function to get a positive long number from the user
long get_positive_long(void);

// Function to determine if a card is valid and return its type
string determine_card_type(long card);

int main(void)
{
    // Get card number from user
    long card = get_positive_long();

    // Determine card type and print result
    string card_type = determine_card_type(card);
    printf("%s\n", card_type);
}

// Function to get a positive long number from the user
long get_positive_long(void)
{
    long n;
    do
    {
        n = get_long("Card: ");
    }
    while (n < 0);
    return n;
}

// Function to determine if a card is valid and return its type
string determine_card_type(long card)
{
    // Get the length of the card number
    int length = 0;
    long temp = card;
    while (temp > 0)
    {
        temp /= 10;
        length++;
    }

    // Check if card number has a valid length
    if (length != 13 && length != 15 && length != 16)
    {
        return "INVALID";
    }

    // Get the first two digits of the card number
    int first_two_digits = card / pow(10, length - 2);

    // Calculate sum of digits
    int sum = 0;
    int digit;
    bool double_digit = false;
    for (int i = length - 1; i >= 0; i--)
    {
        digit = card % 10;
        card /= 10;

        if (double_digit)
        {
            digit *= 2;
            if (digit >= 10)
            {
                sum += digit / 10;
                sum += digit % 10;
            }
            else
            {
                sum += digit;
            }
        }
        else
        {
            sum += digit;
        }

        double_digit = !double_digit;
    }

    // Check if the sum of digits is divisible by 10
    if (sum % 10 != 0)
    {
        return "INVALID";
    }

    // Check if the card is AMEX, MASTERCARD, or VISA based on the first two digits
    if (length == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        return "AMEX";
    }
    else if (length == 16 && first_two_digits >= 51 && first_two_digits <= 55)
    {
        return "MASTERCARD";
    }
    else if ((length == 13 || length == 16) && (first_two_digits / 10 == 4))
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}
