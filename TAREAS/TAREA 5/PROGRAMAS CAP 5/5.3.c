#include <stdio.h>

/* Apuntadores, variables y valores. */

int main(void)
{
    int X = 3, Y = 7, Z[5] = {2, 4, 6, 8, 10};
    printf("X = %d \t Y = %d \t Z[0] = %d Z[1] = %d \t Z[3] = %d \t Z[4] = %d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    int  *IX;                              /* IX representa un apuntador a un entero */
    IX = &X;                               /* IX apunta a X. IX tiene la dirreccion de X. */
    Y = *IX;                               /* Y toma el valor de X, ahora vale 3. */
    *IX = 1;                               /* X se modifica, ahora vale 1. */

    printf("X = %d \t Y = %d \t Z[0] = %d Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);
    X = Z[2] + 5;                          /* X se modifica, ahora vale Z[2] + 5 = 20. Recuerda que *IX contiene el valor de Z[2]. */
    Z[2] = Z[2] - 5;                        /* Z[2] se modifica, ahora vale 10. */

    printf("X = %d \t Y = %d \t Z[0] = %d Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);
    Z[2]++;                                 /* Z[2] se modifica, se incrementa en 1. Z[2] ahora vale 11. */
    Z[2] += 1;                              /* Z[2] se vuelve a modificar, ahora vale 12. */

    printf("X = %d \t Y = %d \t Z[0] = %d Z[1] = %d \t Z[3] = %d \t Z[4] = %d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);
    IX = &Z[3];                         /* X se modifica. el apuntador IX accede temporalmente a Z[3], por lo tanto X toma este valor (8). obserava que IX no se reasigna */
    X = *IX;                               /* Y se modifica, toma el valor Z[2] (12). */
    Y = Z[2];

    printf("X = %d \t Y = %d \t Z[0] = %d Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);
    IX = IX + 1;                           /* IX se modifica. observa la forma de mover el apuntador. Ahora IX apunta al cuarto elemento de Z (Z[3]). */
    Y = *IX;                               /* Y se modifica, ahora, vale Z[3] (8). */

    printf("X = %d \t Y = %d \t Z[0] = %d Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);
    IX = IX + 4;                           /* IX se modifica. observa que el apuntador se mueve 4 posiciones y cae en una direccion afuera del arreglo. esto ocasionara un error. */
    Y = *IX;                               /* Y se modifica, toma valor (basura) de una celda incorrecta. es un error que no senala el compilador del lenguje C. */

    printf("X = %d \t Y = %d \t Z[0] = %d Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);
    IX = &X;                               /* IX apunta a la variable entera X */
    IX = IX + 1;                           /* IX se mueve una posicion y cae en una celda incorrecta. */
    X = *IX;                               /* X toma el valor (basura) de la celda a la que apunta IX. */

    printf("X = %d \t Y = %d \t Z[0] = %d Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    return 0;
}

