#include <stdio.h>

/* Cueta-numeros.
El programa, al recibir como datos un arreglo unidimensional de tipo entero y un numero entero, determina cuantas veces se encuentra el numero en el arreglo. */

int main(void)
{
    int I, NUM, CUE = 0;                 /* Declaracion del arreglo */
    int ARRE[100];
    for (I = 0; I < 100; I++)
    {
        printf("Ingrese el elemento  %d del arreglo: ", I + 1);
        scanf("%d", &ARRE[I]);
    }
        printf("Ingrese el numero a buscar en el arreglo: ");
        scanf("%d", &NUM);
        for (I=0; I<100; I++)
        {
            if (ARRE[I] == NUM)            /* Comparacion del numero con los elentos del arreglo */
            CUE++;
        }

        printf("\n\nEl %d encuenta %d veces en el arreglo", NUM, CUE);
    return 0;
}
