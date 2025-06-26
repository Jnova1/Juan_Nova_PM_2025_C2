#include <stdio.h>
#include <ctype.h>

/* cuena letras minusculas y mayusculas.
el programa, al recibir como dato una frase, determina el numero de letrs minuscuas y mayusculas que exiten en la frase. */

void main(void)
{
    char cad[50];
    int i = 0, mi = 0, ma = 0;
    printf("\Ingrese la cadena de caracteres (maximo 50): ");
    gets(cad);
    while (cad[i] != '\0')
        {
        if (islower (cad[i]))
            mi++;
        else
        if (isupper (cad[i]))
        ma++;
        i++;
        }
    printf("\n\nNumero de letras minusculas: %d", mi);
    printf("\nNumero de letras mayusculas: %d", ma);
}
