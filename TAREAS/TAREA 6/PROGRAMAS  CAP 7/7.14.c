#include <stdio.h>

/* calcula longitud en forma recursiva.
el programa calcula de manera recursiva la longitud de la cadena sin utilizar la funcion strlen */

int cuenta(char *);

void main(void)
{
    int i;
    char cad[50];
    printf("\Ingrese la cadena de caracteres: ");
    gets(cad);
    i = cuenta(cad);
    printf("\Longitud de la cadena %d", i);
}

int cuenta(char *cadena)
/* esta funcion calcula la longitud de la cadena en forma recursiva. es importante tener conocimientos tanto de pilas como de recursivas
para comprender la solucion propuesta, aunque esta sea muy simple. observa que mientras no lleguemos al ultimo caracter de la cadena, incrementamos la cuenta en uno
y llamamos a la funcion con el siguiente caracte. */
{
    if (cadena[0] == '\0')
        return 0;
    else
        return (1 + cuenta (&cadena[1]));
}
