/*******************************************************
 * Written by Lerentis
 * 
 * This file is part of C Course 2016 - HS-Bochum.
 * 
 *******************************************************/

#include <stdio.h>

void printSizeOf(double doubleArray[]);
void printLength(double doubleArray[]);

int main(int argc, char *argv[])
{

    int var = 5;
    int *varptr = &var;

    printf("%d \n", *varptr);
    printf("%p \n", varptr);

    /* an array with 5 elements */
    double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
    double *p;
    unsigned int i;

    p = balance;

    /* output each array element's value */
    printf( "Array values using pointer\n");

    for ( i = 0; i < (sizeof(balance) / sizeof(double)); i++ ) {
       printf("*(p + %d) : %f\n",  i, *(p + i) );
    }

    printf( "Array values using balance as address\n");

    for ( i = 0; i < (sizeof(balance) / sizeof(double)); i++ ) {
       printf("*(balance + %d) : %f\n",  i, *(balance + i) );
    }

    printf( "Array values using java notation\n");

    for ( i = 0; i < (sizeof(balance) / sizeof(double)); i++) {
        printf("balance[%d] : %f \n", i, balance[i]);
    }

    printSizeOf(balance);
    printLength(balance);

    return 0;
}


void printSizeOf(double doubleArray[])
{
    printf("sizeof of parameter: %d\n", (int) sizeof(doubleArray));
}

void printLength(double doubleArray[])
{
    printf("Length of parameter: %d\n", (int)( sizeof(doubleArray) / sizeof(doubleArray[0]) ));
}
