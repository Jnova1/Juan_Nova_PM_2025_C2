/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

/* Nomina.
El programa, al recibir los salarios de 15 profesores, obtiene el total de la nomina de la universidad.

I: variable de tipo entero.
SAL y NOM: variable de tipo real. */

void main(void)
{
	int I;
	float SAL, NOM;
	NOM = 0;

	for (I = 1; I <= 15; I++)
	{
		printf("Ingrese el salario del profesor %d:\t", I);
		scanf("%f", &SAL);
		NOM = NOM + SAL;
	}

	printf("\nEl total de la nomina es: %.2f", NOM);
}
