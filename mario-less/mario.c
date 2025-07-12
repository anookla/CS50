#include <cs50.h>
#include <stdio.h>

void print_row(int spaces, int bricks);

int main(void)
{
    int size = 0; // size variable
    int spaces = 0; // number of spaces variable
    // prompt for user input the size of pyramid
    do
    {
        size = get_int("Please enter the size:");
    }
    while (size <= 0);
    // Print a pyramid of that height
    for (int i = 0 ;i <size ; i++)
    {
        spaces = size - (i + 1);
        print_row(spaces, i + 1);
    }
}
void print_row(int spaces, int bricks)
{
    // print spaces
    for(int i = 0;i < spaces ; i++)
    {
        printf(" ");
    }
    // print bricks
    for(int j = 0;j < bricks; j++)
    {
        printf("#");
    }
    printf("\n");
}
