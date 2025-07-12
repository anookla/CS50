#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Please enter exactly one command line argument \n");
        return 1;
    }

    int key_length = strlen(argv[1]);

    if (key_length != 26)
    {
        printf("please ensure key has 26 characters\n");
        return 1;
    }

    for (int i = 0; i < key_length; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("please ensure all the characters are alphabetical only\n");
            return 1;
        }

        int j = i;
        for (j = i; j < key_length - 1; j++)
        {
            if (tolower(argv[1][i]) == tolower(argv[1][j + 1]))
            {
                printf("Please ensure characters on the key are not repeated\n");
                return 1;
            }
        }
    }

    string input_string = get_string("plaintext:");
    int length = strlen(input_string);

    for (int i = 0; i < length; i++)
    {
        if (isalpha(input_string[i]))
        {
            int index = tolower(input_string[i]) - 'a';
            if (isupper(input_string[i]))
            {
                input_string[i] = toupper(argv[1][index]);
            }
            else
            {
                input_string[i] = tolower(argv[1][index]);
            }
        }
    }
    printf("ciphertext: %s", input_string);
    printf("\n");
}
