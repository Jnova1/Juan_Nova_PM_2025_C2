#include <stdio.h>

void main(void)
{
	int N, I, J, val, espacio;

	printf("Ingresa un numero entero positivo (N): ");
	scanf("%d", &N);

	for (I = 1; I <= N; I++)
	{
		for (espacio = 1; espacio <= N - I; espacio++)
		{
			printf("  ");
		}

		for (J = 0; J < I; J++)
		{
			val = (I + J) % 10;
			printf("%d ", val);
		}

		for (J = I - 2; J >= 0; J--)
		{
			val = (I + J) % 10;
			printf("%d ", val);
		}

		printf("\n");
	}
}









