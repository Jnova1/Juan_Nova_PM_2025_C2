#include <stdio.h>
#include <stdlib.h>

int main() {
	int edad = 0;

	//Rangos de edad
	// 1 - Recien nacido persona de edad menor a 1 aC1o
	// 2 - Infante persona de edad entre 1 a 3 aC1os
	// 3 - NiC1o persona de edad entre 3 a 12 aC1os
	// 4 - Adolescente persona de entre 12 a 18 aC1os
	// 5 - Mayor de edad persona de edad entre 18 a 38 aC1os
	// 6 - Adulto mayor persona de edad entre 38 a 68 aC1os
	// 7 - Envejeciente persona mayor de 68 aC1os y menor de 86
	// 8 - Anciano persona mayor de 86 aC1os de edad

	printf("Ingrese su edad: ");
	scanf("%d", &edad);
	// el 0 es falso todo lo demas es verdadero
	if(edad >= 0 && edad <= 120) { //verificar la valides de los datos



		if(edad < 1) {
			printf("Usted es un recien nacido\n");
		}
		else if(edad >= 1 && edad < 3) {
			printf("Usted es un infante\n");
		}
		else if(edad >= 3 && edad < 12) {
			printf("Usted es un niC1o\n");
		}
		else if(edad >= 12 && edad < 18) {
			printf("Usted es un adolescente\n");
		}
		else if(edad >= 18 && edad < 38) {
			printf("Usted es mayor de edad\n");
		}
		else if(edad >= 38 && edad < 68) {
			printf("Usted es un adulto mayor\n");
		}
		else if(edad >= 68 && edad < 86) {
			printf("Usted es un envejeciente\n");
		}
		else {
			printf("Usted es un anciano\n");
		}
		// este codigo si es verdadero
	} else {
		if(edad < 0) {
			printf("\nError: Edad negativa\n");
		}
		if(edad > 120) {
			printf("\nError: eres un vampiro\n");
		}
	}



}
