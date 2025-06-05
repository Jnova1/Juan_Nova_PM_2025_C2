#include <stdio.h>

void main(void)
{
	int N1, N2, RES;

	printf("Ingresa el primer numero (N1): ");
	scanf("%d", &N1);

	printf("Ingresa el segundo numero (N2): ");
	scanf("%d", &N2);

	while (N1 != N2)
	{
		if (N1 > N2)
			N1 = N1 - N2;
		else
			N2 = N2 - N1;
	}

	RES = N1;  // Ya que N1 == N2

	printf("El Maximo Comun Divisor es: %d\n", RES);
}






