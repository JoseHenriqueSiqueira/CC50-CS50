#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Check for command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check if the key is valid
    string key = argv[1];
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Verify key has only alphabetical characters and no repeated letters
    bool chars[26] = {0}; // create a boolean array of size 26 initialized with zeros
    for (int i = 0; i < 26; i++)
    {
        char c = key[i]; // get the current character of the key
        if (!isalpha(c)) // if the character is not alphabetical
        {
            printf("Key must only contain alphabets.\n");
            return 1;
        }
        else if (chars[tolower(c) - 'a']) // if the character has already been used
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
        else // mark the character as used
        {
            chars[tolower(c) - 'a'] = true;
        }
    }

    // Get plaintext input from user
    string plaintext = get_string("plaintext: ");

    // Encrypt plaintext to ciphertext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i]; // get the current character of the plaintext
        if (isalpha(c)) // if the character is alphabetical
        {
            char keyChar = key[tolower(c) - 'a']; // get the corresponding character in the key
            c = isupper(c) ? toupper(keyChar) : tolower(keyChar); // set the case of the ciphertext character
        }
        printf("%c", c); // print the ciphertext character
    }
    printf("\n");
    return 0;
}
