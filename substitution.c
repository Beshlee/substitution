#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// Function prototypes
bool is_valid_key(string key);
char substitute_char(char plaintext_char, string key);

int main(int argc, string argv[])
{
    // Check if exactly one argument (the key) is provided
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Validate the key
    string key = argv[1];
    if (!is_valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Get plaintext from the user
    string plaintext = get_string("plaintext: ");

    // Output ciphertext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", substitute_char(plaintext[i], key));
    }
    printf("\n");

    return 0;
}

// Function to check if the key is valid
bool is_valid_key(string key)
{
    // Check if the key length is exactly 26
    if (strlen(key) != 26)
    {
        return false;
    }

    bool seen[26] = {false};  // To track if each letter appears only once

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;  // Key contains a non-alphabetic character
        }

        // Check for duplicates (case-insensitive)
        int index = tolower(key[i]) - 'a';
        if (seen[index])
        {
            return false;  // Duplicate letter found
        }
        seen[index] = true;
    }

    return true;
}

// Function to substitute a character using the key
char substitute_char(char plaintext_char, string key)
{
    if (isupper(plaintext_char))
    {
        // Substituting uppercase letter
        return toupper(key[plaintext_char - 'A']);
    }
    else if (islower(plaintext_char))
    {
        // Substituting lowercase letter
        return tolower(key[plaintext_char - 'a']);
    }
    else
    {
        // Non-alphabetic characters remain unchanged
        return plaintext_char;
    }
}
