#include <stdio.h>
#include <stdlib.h>

/* funciones para el manejo de caracteres de la biblioteca stdlib.h*/

void main(void)
{
    int i;
    double d;
    long l;
    char cad0[20], *cad1;

    printf("\nIngrese una cadena de caracteres: ");
    gets(cad0);
    i = atoi(cad0);
    /* La funcion atoi convierte una cadena de caracteres que contiene numeros a un valor de tipo entero. si la cadena comienza con oto caracter o no cotiene numeros, regresa 0 o el valor queda indefinido.  */

printf("\n%s \t %d", cad0, i+3);
/* Se imprime el valor de i+3 para demostrar que i ya fue convertido a un entero. */

printf("\nIngrese una cadena de caracteres: ");
gets(cad0);
d = atof(cad0);
/* la funcion atof convierte una cadena de caracteres que contiene numeros reales a un valor de tipo double. s la cadena comienza con otro caracter o no contiene numeros,regresa 0 o el valor queda indefinido. */
printf("\n%s \t %.2f ", cad0, d+1.50);

d = strtod(cad0, &cad1);
/* `la funcion strtod conviertw uuna cadena de caracteres que contiene numeros reales a un valor de tipo double. el resto de la cadena se almacena en el segundo argumento de la funcion, &cad1, un apuntador de tipo cadena de aracteres. si la cadena no contiene numeros o comienza con otro caracter, regresa 0
o el valor indefinido. */
printf("\n%s \t %.2f ", cad0, d+1.50);
puts(cad1);

l = atol(cad0);
/* la funcion atol convierte una cadena de caracteres que contiene numeros a un valor de tipo long. si la cadena no contiene numeros o comienza con otro caracter, regresa 0 o el valor queda indefinido. */
printf("\n%s \t %.2f ", cad0, 1+10);
puts(cad1);

l = strtol(cad0, &cad1, 0);
/* la funcion strtol convierte una cadena de caracteres que contiene numeros a un valor de tipo long. el esto de la cadena se almacena en el otro argumento de la funcion, &cad1. el tercer argumento se utiliza para indicar que la cadena puede estar en formato octal, decimal o hexadecimal. si la cadena no contiene numeros o comienza con otro caracter, regresa 0 o el valor queda indefinido. */
printf("\n%s \t %.2f ", cad0, 1+10);

}
