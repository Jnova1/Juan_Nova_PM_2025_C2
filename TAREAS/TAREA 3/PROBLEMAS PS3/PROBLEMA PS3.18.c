#include <stdio.h>


void main(void)
{
	int N, I, J;

	printf("Ingresa un numero entero positivo (N): ");
	scanf("%d", &N);

	for (I = N; I >= 1; I--)
	{
		for (J = 1; J <= I; J++)
		{
			printf("%d ", J);
		}

		for (J = I; J >= 1; J--)
		{
			printf("%d ", J);
		}

		printf("\n");
	}
}








