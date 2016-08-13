/*******************************************************
 * Written by Lerentis
 * 
 * This file is part of C Course 2016 - HS-Bochum.
 * 
 *******************************************************/

#include <stdio.h>

void tauschen_referenz(int*,int*);

int main()
{

    int a,b;
    a = 5;
    b = 10;

    printf("Variablen vor dem Tauschen in der main : a = %d \t b= %d \n",a,b);

    tauschen_referenz(&a,&b);

    printf("Variablen nach dem Tauschen in der main : a = %d \t b= %d \n",a,b);


    return 0;
}

void tauschen_referenz(int* a ,int* b){
    printf("Variablen vor dem Tauschen in der Funktion : a = %d \t b= %d \n",*a,*b);
    int tmp = *a;
    *a = *b;
    *b = tmp;
    printf("Variablen nach dem Tauschen in der Funktion : a = %d \t b= %d \n",*a,*b);
}

