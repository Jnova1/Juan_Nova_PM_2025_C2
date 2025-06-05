/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <math.h>

/* Suma cuadrados.
El programa, al recibir como datos un grupo de enteros positivos,
obtiene el cuadrado de los mismos y la suma correspondiente a dichos cuadrados. */

void main(void)
{
	int NUM;
	long CUA, SUC = 0;

	printf("\nIngrese un nC:mero entero (0 para terminar):\t");
	scanf("%d", &NUM);

	while (NUM)
		/* Observa que la condiciC3n es verdadera mientras el entero es diferente de cero. */
	{
		CUA = NUM, (NUM, 2);
		printf("%d al cubo es %ld\n", NUM, CUA);
		SUC = SUC + CUA;

		printf("Ingrese un nC:mero entero -0 para terminar):\t");
		scanf("%d", &NUM);
	}

	printf("\nLa suma de los cuadrados es: %ld\n", SUC);
}




