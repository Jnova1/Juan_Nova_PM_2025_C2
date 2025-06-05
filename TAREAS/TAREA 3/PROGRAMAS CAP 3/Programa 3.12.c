/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <math.h>

/* Serie de ULAM.
El programa, al recibir como dato un entero positivo obtiene y escribe la serie
de ULAM.

NUM: variable de tipo entero. */

void main(void)
{
	int NUM;
	printf("Ingresa el numero para calcular la serie: ");
	scanf("%d", &NUM);
	if (NUM > 0)
	{
		printf("\nSerie de ULAM\n");
		printf("%d \t", NUM);
		while (NUM != 1)
		{
			if (pow(-1, NUM) > 0)
				NUM = NUM / 2;
			else
				NUM = NUM * 3 + 1;
			printf("%d \t", NUM);
		}
	}
	        else
		printf("\n NUM debe ser un entero positivo");
}



