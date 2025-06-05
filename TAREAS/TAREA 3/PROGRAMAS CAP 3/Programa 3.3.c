/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>

/* Suma pagos.
El programa, al recibir como datos un conjunto de pagos realizados en el C:ltimo mes, obtiene la suma de los mismos.

PAG y SPA: variables de tipo real. */

void main(void)
{
	float PAG, SPA;
	SPA = 0;

	printf("Ingrese el primer pago:\t");
	scanf("%f", &PAG);

	while (PAG != 0)
	{
		SPA = SPA + PAG;
		printf("Ingrese el siguiente pago (0 para terminar):\t");
		scanf("%f", &PAG);
	}

	printf("\nEl total de pagos del mes es: %.2f", SPA);
}

