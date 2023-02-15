#include <cs50.h>
#include <math.h>
#include <stdio.h>

// Declare the function that gets a positive float number from the user
float get_positive_float_number(void);

// Main function
int main(void)
{
    // Get a positive float number from the user and round it to the nearest cent
    float cash = get_positive_float_number();
    int cents = round(cash * 100);

    // Declare variables to keep track of the coin value and the number of coins used
    int value = 0;
    int num_coins = 0;

    // Calculate the minimum number of coins required to give the user change
    while (value < cents)
    {
        if (value + 25 <= cents)  // If a quarter can be used
        {
            value += 25;
        }
        else if (value + 10 <= cents)  // If a dime can be used
        {
            value += 10;
        }
        else if (value + 5 <= cents)  // If a nickel can be used
        {
            value += 5;
        }
        else  // If a penny can be used
        {
            value += 1;
        }
        num_coins++;
    }

    // Print the minimum number of coins required
    printf("%i\n", num_coins);
}

// Get a positive float number from user
float get_positive_float_number(void)
{
    float n;
    do
    {
        n = get_float("Money: ");
    }
    while (n <= 0);
    return n;
}