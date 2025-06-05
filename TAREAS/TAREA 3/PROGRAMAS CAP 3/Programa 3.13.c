/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
/* Fibonacci.
El programa calcula y escibe los primeros 50 numeros de Fibonacci.

I, PRI, SEC, SIG: variables de tipo entero. */

void main(void)
{
	int I, PRI = 0, SEG = 1, SIG;
	printf("\t %d \t %d", PRI, SEG);
	for (I = 3; I<= 50; I++)
	{
		SIG = PRI + SEG;
		PRI = SEG;
		SEG = SIG;
		printf("\t %d", SIG);
	}
}


