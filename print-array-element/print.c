#include<stdio.h>
#include<cs50.h>

int main(void) {

    int size = get_int("Please enter size:");
    int arr[size];
    for (int i = 0;i<size;i++){

        arr[i] = i+1;
        printf("Element at index %i is %i\n", i, arr[i]);
    }
}
