#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Get input string to analyze
    string input_string = get_string("Text: ");

    int letter_count = 0, word_count = 1, sentence_count = 0;

    // Count letters, words, and sentences in the input string.
    // Assume that any character A-Z and a-z is a letter.
    for (int i = 0, length = strlen(input_string); i < length; i++)
    {
        if ((input_string[i] >= 'a' && input_string[i] <= 'z') || (input_string[i] >= 'A' && input_string[i] <= 'Z'))
        {
            letter_count++;
        }

        // Any sequence of characters separated by space is a word.
        if (input_string[i] == ' ')
        {
            word_count++;
        }

        // If a period, exclamation point, or question mark is encountered, increment sentence count.
        if (input_string[i] == '.' || input_string[i] == '!' || input_string[i] == '?')
        {
            sentence_count++;
        }
    }

    // Calculate the reading index grade level of the input text.
    float L = (float) letter_count / (float) word_count * 100;
    float S = (float) sentence_count / (float) word_count * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print the reading index grade level of the input text.
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    return 0;
}