#include <stdio.h>
#include <string.h>

/* cuenta cadenas.
el programa, al recibir dos cadenas de caracteres, calcula e imprime
cuantas veces se encuentra la 2nda cada en la 1ra*/

void main(void)
{
    char cad1[50], cad2[50], *cad0 = " ";
    int i = 0;
    printf("\Ingrese la cadena de caracteres: ");
    gets(cad1);
    printf("\Ingrese la cadena d=a buscar: ");
    gets(cad2);
    strcpy(cad0, cad1);
    cad0 = strstr (cad0, cad2);
    /* si no existe se almacena NULL.*/
    while (cad0 != NULL)
    {
        i++;
        cad0 = strstr (cad0 + 1, cad2);
        /* se modifica nuevamente la cadena, moviendo el apuntador una posicion */
    }
    printf("\nEl numero de veces que aparece la 2nda cadena es: %d", i);
}
