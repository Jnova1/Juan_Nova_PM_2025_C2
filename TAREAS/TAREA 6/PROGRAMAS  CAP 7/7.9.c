#include <stdio.h>

/* cuenta caracteres
el programa, al ecibir como datos una cadena de caracteres  y un caracter, cuenta cuantas veces
se encuentra el caracter en la cadena. */

int cuenta(char *, char);

void main(void)
{
    char car, cad[50];
    int res;
    printf("\Ingrese la cadena de caracteres: ");
    gets(cad);
    fflush(stdin);
    printf("\Ingrese el caracterer: ");
    car = getchar();
    res = cuenta(cad, car);
    printf("\n\n%c se encuentra %d veces en la cadena %s", car, res, cad);
}

int cuenta(char *cad, char car)
/* esta funcion se utiliza para obtener el numero de veces que se encuentra el caracter en la cadena. */
{
    int i = 0, r = 0;
    while (cad[i] != '\0')
    {
            if (cad[i] == car)
                r++;
            i++;
    }
    return (r);
}
