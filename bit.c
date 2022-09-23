/*
    Class - CSCI 247 Winter 2022
    Name - Aric Schroeder

    Program - Performs various forms of bit manipulation with user provided variable input.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int getbit(int x);
int getbit_p(int x, int p);
int get_nbits(int x, int n);
int setbit(int x);
int setbit_p(int x, int p);
int set_nbits(int x, int p);
int clearbit(int x);
int clearbit_p(int x, int p);
int clear_nbits(int x, int n);

// helper method
int concat(int a, int b);

int main() {
    char methods[9][12] = {
        "getbit",
        "getbit_p",
        "get_nbit",
        "setbit",
        "setbit_p",
        "set_nbits",
        "clearbit",
        "clearbit_p",
        "clear_nbits"
    };

    // Simple command line interface. Quite a bit of repeated code but should suffice for assignment requirements.
    bool runLoop = true;
    while (runLoop)
    {
        int * userMethodSelectPointer = malloc(sizeof(int));
        printf("\n\ngetbit (1), getbit_p (2), get_nbit (3), \nsetbit (4), setbit_p (5), set_nbits (6), \nclearbit (7), clearbit_p (8), clear_nbits (9).\t ");
        printf("\nEnter the number shown next to the method you would like to compute\t: ");
        scanf("%d", userMethodSelectPointer);

        int selectedMethod = * userMethodSelectPointer;
        printf("\nYou selected '%s'\n\n", methods[selectedMethod - 1]);

        int * x = malloc(sizeof(int));
        int * p = malloc(sizeof(int));
        int * n = malloc(sizeof(int));
        int input_x, input_p, input_n;

        if(selectedMethod == 1) {
            printf("please choose an x\t: ");
            scanf("%d", x);
            input_x = * x;
            printf("\noutput: %d", getbit(input_x));

        } else if(selectedMethod == 2){
            printf("please choose x\t: ");
            scanf("%d", x);
            printf("please choose p\t: ");
            scanf("%d", p);
            input_x = * x;
            input_p = * p;
            printf("\noutput: %d", getbit_p(input_x, input_p));

        } else if(selectedMethod == 3) {
            printf("please choose x\t: ");
            scanf("%d", x);
            printf("please choose n\t: ");
            scanf("%d", p);
            input_x = * x;
            input_n = * n;
            printf("\noutput: %d", get_nbits(input_x, input_n));

        } else if(selectedMethod == 4) {
            printf("please choose an x\t: ");
            scanf("%d", x);
            input_x = * x;
            printf("\noutput: %d", setbit(input_x));

        } else if(selectedMethod == 5) {
            printf("please choose x\t: ");
            scanf("%d", x);
            printf("please choose p\t: ");
            scanf("%d", p);
            input_x = * x;
            input_p = * p;
            printf("\noutput: %d", setbit_p(input_x, input_p));

        } else if(selectedMethod == 6) {
            printf("please choose x\t: ");
            scanf("%d", x);
            printf("please choose n\t: ");
            scanf("%d", n);
            input_x = * x;
            input_n = * n;
            printf("\noutput: %d", set_nbits(input_x, input_n));

        } else if(selectedMethod == 7) {
            printf("please choose x\t: ");
            scanf("%d", x);
            input_x = * x;
            printf("\noutput: %d", clearbit(input_x));

        } else if(selectedMethod == 8) {
            printf("please choose x\t: ");
            scanf("%d", x);
            printf("please choose p\t: ");
            scanf("%d", p);
            input_x = * x;
            input_p = * p;
            printf("\noutput: %d", clearbit_p(input_x, input_p));

        } else if(selectedMethod == 9) {
            printf("please choose x\t: ");
            scanf("%d", x);
            printf("please choose n\t: ");
            scanf("%d", n);
            input_x = * x;
            input_n = * n;
            printf("\noutput: %d", clear_nbits(input_x, input_n));
        } else {
            printf("\nInvalid input. Program Terminated.");
            runLoop = false;
        }
    }
    return(0);
}

// Returns last bit in a byte.
int getbit(int x) {
    return x & 1;
}

// Returns bit at position p
int getbit_p(int x, int p) {
    // printf("%d", (x >> p) & 1);
    return (x >> p) & 1;
}

// Returns n bits from x
int get_nbits(int x, int n) {
    int bit = x & 1;

    for(int i = 0; i < n - 1; i++) {
        int nextBit = x >> 1 & 1;
        bit = concat(bit, nextBit);
    }
    return bit;
}

// Sets position of last bit
int setbit(int x) {
    x |= 1;
    return x;
}

// Sets bit at position p
int setbit_p(int x, int p) {
    x |= 1 << p;
    return x;
}

// Sets n rightmost bits
int set_nbits(int x, int n) {
    for(int i = 0; i < n; i++) {
        x |= 1 << i;
    }
    return x;
}

// Clears bit at rightmost position
int clearbit(int x) {
    printf("%d\n", x);
    x &= INT_MAX << 1;
    return x;
}

// Clears bit at position p
int clearbit_p(int x, int p) {
    int bitToSet = 0;
    int setBit = setbit_p(bitToSet, p);
    x &= ~setBit;
    return x;
}

int clear_nbits(int x, int n) {
    x &= INT16_MAX << n;
    return x;
}

// Concatinates two integers
int concat(int a, int b)
{
    char string1[20];
    char string2[20];
    sprintf(string1, "%d", a);
    sprintf(string2, "%d", b);
    strcat(string1, string2);
 
    // Concatinated string to integer
    int output = atoi(string1);
 
    return output;
}