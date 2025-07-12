#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int k);

int main(int argc, string argv[])
{
    // check if command line input is only digits only when entered

    if (argc > 1)
    {
        bool check = only_digits(argv[1]);
    }

    int key = 0;

    // check if only command line argument is entered

    if (argc != 2 || argc < 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // check if each command line input is an digit or not

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit((int) argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    key = atoi(argv[1]);

    string plaintext = get_string("Enter plain text: ");

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = rotate(plaintext[i], key);
        printf("%c", c);
    }
    printf("\n");

    return 0;
}

// checks if key is an digit

bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// rotate char if any alphabet else return as is

char rotate(char c, int k)
{
    if (isupper(c))
    {
        c = (((c - 'A') + k) % 26) + 'A';
    }
    else if (islower(c))
    {
        c = (((c - 'a') + k) % 26) + 'a';
    }
    return c;
}
