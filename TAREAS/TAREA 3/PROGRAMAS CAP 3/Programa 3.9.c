/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>

/* Serie.
El programa imprime los terminos y obtiene la suma de una determinada serie.

I, SSE y CAM: variable de tipo entero. */

void main(void)
{
	int I = 2, CAM = 1;
	long SSE = 0;
	while (I <= 2500)
	{
		SSE = SSE + I;
		printf("\t %d", I);
		if (CAM)
		{
			I += 5;
			CAM --;
		}
		else
		{
			I +=3;
			CAM++;
		}
	}
	printf("\nLa suma de la serie es: %ld", SSE);
}



