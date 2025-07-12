#include <cs50.h>
#include <stdio.h>

void printRow(int height);
void printSpaces(int height);
void printHashes(int TotalLeftcount);

int main()
{

    int height;
    do
    {
        height = get_int("Enter required height for the pyramid: ");
    }
    while (height < 1 || height > 8);

    printRow(height);
}

void printRow(int height)
{
    for (int row = 1; row <= height; row++)
    {
        printSpaces(height - (row));
        printHashes(height - (height - row));
        printf("  ");
        printHashes(height - (height - row));
        printf("\n");
    }
}

void printSpaces(int spacesCount)
{
    for (int Count = 0; Count < spacesCount; Count++)
    {
        printf(" ");
    }
}

void printHashes(int TotalLeftcount)
{
    for (int j = 0; j < TotalLeftcount; j++)
    {
        printf("#");
    }
}
