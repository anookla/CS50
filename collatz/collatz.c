

// n should be positive and user input

// if n is 1 then stop and steps should be 0

// else if n is even then repeat process on n/2

// else if n is odd then repeat process on 3*n+1


#include<cs50.h>
#include<stdio.h>


int collatz(int n);



int main(void) {


    int input = get_int("Enter a number:");
    if (input > 0) {
    printf("Steps is %i\n", collatz(input));
    }
}

int collatz(int n) {


    if ( n == 1) {
        return 0;
    }
    else if ( n%2 == 0) {
        return 1 + collatz(n/2);
    }
    else
    {
        return 1 + collatz(3*n+1);
    }
}
