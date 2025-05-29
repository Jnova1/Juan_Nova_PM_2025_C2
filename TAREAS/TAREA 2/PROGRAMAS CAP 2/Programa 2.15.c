/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
/* Spa.
   El programa, al recibir como datos el tipo de tratamiento, la edad y el
   nC:mero de dC-as de internaciC3n de un cliente en un spa, calcula el costo
   total del tratamiento.
   TRA, EDA, DIA: variables de tipo entero.
   COS: variable de tipo real. */

void main(void)
{
	int TRA, EDA, DIA;
	float COS;

	printf("Ingrese tipo de tratamiento, edad y dC-as: ");
	scanf("%d %d %d", &TRA, &EDA, &DIA);

	switch(TRA)
	{
	case 1:
		COS = DIA * 2800;
		break;
	case 2:
		COS = DIA * 1950;
		break;
	case 3:
		COS = DIA * 2500;
		break;
	case 4:
		COS = DIA * 1150;
		break;
	default:
		COS = -1;
		break;
	}

	if (COS != -1)
	{
		if (EDA >= 60)
			COS = COS * 0.75;
		else if (EDA <= 25)
			COS = COS * 0.85;

		printf("\nClave tratamiento: %d\t DC-as: %d\t Costo total: %8.2f\n", TRA, DIA, COS);
	}
	else
		printf("\nLa clave del tratamiento es incorrecta\n");
}


