#include <stdio.h>
#include <ctype.h>

/* Decodifica.
el programa decodifica una cadena de caracteres compuesta por numeros y letras. */

void interpreta(char *);

void main(void)
{
    char cad[50];
    printf("\Ingrese la cadena de caracteres: ");
    gets(cad);
    interpreta(cad);
    return 0;
}
void interpreta(char *cadena)
/*esta funcion se utiliza para decodificar la cadena de caracteres. */
{
    int i = 0, j, k;
    while (cadena[i] != '\0')
    {
        if (isalpha (cadena[i]))            /* se utiliza isalpha para observar si el caracter es una letra */
        {
            if (i > 0 && isdigit(cadena[i - 1]))
        {
            k = cadena[i - 1] - 48;
            /* en la variable entera k se almacena el ascii del mundo -convertido en carater- que nos interesa, menos 48 que corresponde al ascii del digito 0. */
            for (j = 0; j < k; j++)
                putchar(cadena[i]);
        }
        i++;
        }
    }
}
