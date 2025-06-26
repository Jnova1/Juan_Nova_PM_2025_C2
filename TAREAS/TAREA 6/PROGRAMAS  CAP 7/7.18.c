#include <stdio.h>

/* CADENA INVERTIDA RESUELTA EN FORMA RECURSIVA. */

void inverso(char *);

void main(void)
{
    char fra[50];
    printf("\Ingrese la linea de texto: ");
    gets(fra);
    printf("\nEscribe la linea de texto en forma inversa: ");
    inverso(fra);
}

void inverso(char *cadena)
/* La funcion inverso obtiene precisamente el inverso de la cadena. La solucion presentada es simple, pero para comprenderla es necesario tener conocimientos tanto de pilas como de recursividad.
observa que mientras no se encuentre el caracter de terminacion de la cadena, se llama a la funcion recursiva con el apuntador al siguiente caracter de la cadena. Por otra parte, queda pendiente de ejecutar
- almacenado en una pila- el caracter al cual apunta *cadena*/
{
    if (cadena[0]!= '\0')
    {
        inverso(&cadena[1]);
        putchar(cadena[0]);
    }
}
