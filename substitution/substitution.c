#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    string text = argv[1]; //Initialising the input Key

    // If the user does not enter the key properly
    if (argc == 1)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    if (strlen(text) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < strlen(text); i++)
    {
        if (!isalpha(text[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
        }
    }

    for (int i = 0; i < strlen(text); i++)
    {
        for (int j = i + 1; j < strlen(text); j++)
        {
            if (text[i] == text[j])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    // initialising the plaintext
    string plaintext = get_string("plaintext: ");

    for (int i = 0; i < strlen(text); i++)
    {
        if (islower(text[i])) // converting the key to upper alphabet
        {
            text[i] = text[i] - 32;
        }
    }

    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i])) //if the text is upper alphabet
        {
            int position = plaintext[i] - 65;
            printf("%c", text[position]);
        }
        else if (islower(plaintext[i])) //if the text is lower alphabet
        {
            int position = plaintext[i] - 97;
            printf("%c", text[position] + 32);
        }

        else
        {
            printf("%c", plaintext[i]); //if the text does not have alphabet
        }
    }

    printf("\n");
}