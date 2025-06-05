/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>

/* Suma positivos.
El programa, al recibir como datos N nC:meros enteros, obtiene la suma de los enteros positivos.

I, N, NUM, SUM: variables de tipo entero. */

void main(void)
{
	int I, N, NUM, SUM;
	SUM = 0;

	printf("Ingrese el numero de datos:\t");
	scanf("%d", &N);

	for (I = 1; I <= N; I++)
	{
		printf("Ingrese el dato numero %d:\t", I);
		scanf("%d", &NUM);

		if (NUM > 0)
			SUM = SUM + NUM;
	}

	printf("\nLa suma de los numeros positivos es: %d", SUM);
}
