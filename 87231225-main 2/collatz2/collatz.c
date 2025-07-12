#include<stdio.h>
#include<cs50.h>

int collatz(int value);

int counter = 0;

int main() {

int n = get_int("Please enter a value for n:");

int steps = collatz(n);

printf("number of steps is %i \n", steps);
}

int collatz(int value) {


    if (value == 1) {
        return counter;
    }
    else if (value%2 == 0)
    {
        counter++;
        collatz(value/2);
    }
    else if (value%2 == 1) {
        counter++;
        collatz(3*value+1);
    }

    return counter;
}
