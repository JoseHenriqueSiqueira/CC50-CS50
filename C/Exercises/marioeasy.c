// Rename file to 'mario.c' before use 'check50 cs50/problems/2021/x/mario/less'
#include <cs50.h>
#include <stdio.h>

// Get a positive number from user
int get_positive_number(void);

// Print a wall
void print_wall(int height);

int main(void)
{
    // Get user input for wall height
    int height = get_positive_number();

    // Print wall
    print_wall(height);
}

int get_positive_number(void)
{
    int height;

    // Keep prompting the user for input until they provide a valid value
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    return height;
}

void print_wall(int height)
{
    // Loop over each row of the wall
    for (int row = 0; row < height; row++)
    {
        // Print the left half of the row
        for (int col = 0; col < height; col++)
        {
            // Print spaces for empty spaces
            if (col < height - row - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}