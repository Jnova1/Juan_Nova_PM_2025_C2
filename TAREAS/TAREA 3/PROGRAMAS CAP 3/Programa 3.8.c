/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
# include <stdio.h>
/* Factorial.
El programa calcula el factorial de un nC:mero entero.
FAC, I, NUM: variables de tipo entero. */
void main(void)
{
	int I, NUM;
	long FAC;
	printf("\nIngrese el nC:mero: ");
	scanf("%d", &NUM);
	if (NUM >= 0)
	{
		FAC = 1;
		for (I=1; I <= NUM; I++)
			FAC *= I;
		printf("\El factorial de %d es: %ld", NUM, FAC);
	}
	else
		printf("\nError en el dato ingresado");
}



