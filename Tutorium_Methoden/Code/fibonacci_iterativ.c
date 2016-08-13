/*******************************************************
 * Written by Lerentis
 * 
 * This file is part of C Course 2016 - HS-Bochum.
 * 
 *******************************************************/

#include <stdio.h>

int main()
{
  int n, first = 0, second = 1, next, c;

  printf("Enter the range of the Fibonacci series: ");
  scanf("%d",&n);

  printf("Fibonacci Series:\n");

  for ( c = 0 ; c < n ; c++ )
    {
      if ( c <= 1 )
	next = c;
      else
	{
	  next = first + second;
	  first = second;
	  second = next;
	}
      printf("%d\n",next);
    }

  return 0;
}
