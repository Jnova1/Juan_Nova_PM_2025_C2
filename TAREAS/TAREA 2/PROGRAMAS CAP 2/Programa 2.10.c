/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>
/* Par, impar o nulo.
NUM: variable de tipo entero. */

void main(void)
{
	int NUM;
	printf("Ingrese el numero: ");
	scanf("%d", &NUM);
	if (NUM == 0)
		printf("\nNulo");
	else if (pow (-1, NUM) > 0)
		printf("\nPar");
	else
		printf("\nImpar");
}