#include <stdio.h>
#include <ctype.h>

/* Verifica.
el programa, al recibir como datos una cadena de caracteres y una posicion especifica en la cadena, determina si el caracter correpondiente es una letr minuscula. */

void main(void)
{
    char p, cad[50];
    int n;
    printf("\Ingrese la cadena de caracteres (maximo 50): ");
    gets(cad);
    printf("\Ingrese la posicion en la cadena que desea verificar: ");
    scanf("%d", &n);
    if ((n >= 0) && (n < 50))
    {
        p = cad[n-1];
        if (islower (p))
            printf("\n%c es un letra minuscula", p);
        else
            printf("\n%c no es un letra minuscula", p);
    }
    else
        printf("\nEl valor ingresado de n es incorrecto");
}
