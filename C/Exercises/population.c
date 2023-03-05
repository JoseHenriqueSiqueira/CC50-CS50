#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Prompt for start size and validate input
    int start_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    // Prompt for end size and validate input
    int end_size;
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    // Calculate number of years until we reach end size
    int year = 0;
    int population = start_size;

    // If start and end size are the same, output 0 years and exit
    if (start_size == end_size)
    {
        printf("Years: 0\n");
        return 0;
    }

    // Calculate population growth until we reach end size
    while (population < end_size)
    {
        // Calculate the population using the provided formula
        population = round(population + (population / 3) - (population / 4));
        year++; // Increment year count
    }

    // Output the number of years it takes to reach end size
    printf("Years: %i\n", year);

    return 0;
}