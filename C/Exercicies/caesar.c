#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // check if the number of arguments is not 2 or if the first argument is not a number
    if (argc != 2 || !isdigit(*argv[1]))
    {
        printf("Usage: ./ceasar k\n");
        return 1;
    }

    // check if the first argument contains only digits
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // convert the key from string to int and limit it to 26
    int key = atoi(argv[1]) % 26;

    // prompt the user for the text to be encrypted
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    // iterate over the plaintext and encrypt each character
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++)
    {
        char c = plaintext[i];

        // if the character is not alphabetic, print it as is
        if (!isalpha(c))
        {
            printf("%c", c);
            continue;
        }

        // determine if the character is uppercase or lowercase and calculate the offset accordingly
        bool is_upper = isupper(c);
        int offset = is_upper ? 'A' : 'a';

        // convert the character to a 0-based index, encrypt it, and convert it back to a character
        char p = c - offset;
        char result = (p + key) % 26 + offset;

        // print the encrypted character
        printf("%c", result);
    }

    printf("\n");
    return 0;
}