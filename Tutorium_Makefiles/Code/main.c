/*******************************************************
 * Written by Lerentis
 * 
 * This file is part of C Course 2016 - HS-Bochum.
 * 
 *******************************************************/

#include <stdio.h>
#include "math_util.h"

int main(int argc, char *argv[])
{
    printf("Hello World!\n");

    int a = 5;
    int b = 3;

    printf("\n Summe \t");
    printf("%d",sum(a,b));
    printf("\n Teilen \t");
    printf("%f",devide(a,b));
    printf("\n Minus \t");
    printf("%d",minus(a,b));
    printf("\n Dividieren \t");
    printf("%d",multiply(a,b));
    printf("\n");

    return 0;
}
