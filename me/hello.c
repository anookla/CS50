#include <cs50.h>
#include <stdio.h>

// Asks for user input for Name and then prints hello

int main(void)
{
    string s = get_string("Name: ");
    printf("hello, %s\n", s);
}
