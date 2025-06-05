/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>

/* Nomina de profesores.
El programa, al recibir como datos los salarios de los profesores de una
universidad, obtiene la nomina y el promedio de los salarios.

I: variable de tipo entero.
SAL, NOM y PRO: variables de tipo real. */

void main(void)
{
	int I = 0;
	float SAL, PRO, NOM = 0;
	printf("Ingrese el salario del profesor:\t");
	/* Observa que al menos se necesita ingresar el salario de un profesor para
	que no ocura un error de ejecucion del programa. */
	scanf("%f", &SAL);
	do
	{
		NOM = NOM + SAL;
		I = I + 1;
		printf("Ingrese el salario del profesor (-0 para termina- ):\t");
		scanf("%f", &SAL);
	}
	while (SAL);
	PRO = NOM / I;
	printf("\nNomina: %.2f \t Promedio de salarios: %.2f", NOM, PRO);


}



