#include <cs50.h>
#include <stdio.h>

int calculate_coins(int cents);

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // Calculate how many coins you should give customer
    int coins = calculate_coins(cents);

    printf("%i\n", coins);
}

int calculate_coins(int cents)
{
    // Calculate how many quarters you should give customer
    int coins = 0;
    while (cents >= 25)
    {
        coins++;
        cents = cents - 25;
    }
    while (cents >= 10)
    {
        coins++;
        cents = cents - 10;
    }
    while (cents >= 5)
    {
        coins++;
        cents = cents - 5;
    }
    while (cents >= 1)
    {
        coins++;
        cents = cents - 1;
    }
    return coins;
}
