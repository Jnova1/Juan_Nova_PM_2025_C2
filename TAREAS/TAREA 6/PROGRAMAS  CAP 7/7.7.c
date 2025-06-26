#include <stdio.h>
#include <string.h>

    /* otras funciones de la biblioteca string.h para el manejo de cadenas. */

    int main()
    {
        int i;
        char cad0[20] = "Hola Mexico";
        char cad1[20] = "Hola Guatemala";
        char cad2[20] = "Hola Venezuela";
        char cad3[20] = "Hola Mexico";
        char *c, c3;

        i = strcmp(cad0, cad1);
        /* la funcion strcmp permite comparar dos cadenas de caracteres.
        si la primera cadena - en este caso cad0- es mayor a la segunda -cad1-, regresa un valor positivo;
        si es menor, un valor negativo y de otra forma, 0. */
        printf("\nResultado de la comparacion -cad0 y cad1-:%d", i);

        i = strcmp(cad0, cad2);
        printf("\nResultado de la comparacion -cad0 y cad2-:%d", i);

        i = strcmp(cad0, cad3);
        printf("\nResultado de la comparacion -cad0 y cad3-:%d", i);

        i = strlen(cad0);
        /* la funcion srlen obtiene la longitud -el numero de caracteres- de una cadena. */
        printf("\nLongitud cadena cad0: %d", i);

        i = strlen(cad0);
        printf("\nLongitud cadena cad1: %d", i);

        c = strchr(cad1, 'G');                 /* c es un apuntador de tipo caracter*/

        /* la funcion strchr busca la posicion en la que se encuentra un determinado caracter en la cadena de caracteres.
        si lo encuentra regresa un apuntador a la primera ocurrencia del caracter en la cadena, de otra forma regresa NULL. */
        if (c != NULL)

        {
            c3 = *c;                 /* c3 roma el contenido de la celda de memoria a la que apunta c. */
            printf("\nEl valor de c3 es: %c", c3);
        }

        c = strchr(cad2, 'V');
        if (c != NULL)
        {
            c = *c;
            printf("\nEl valor de c3 es: %c", c3);
        }
    }
