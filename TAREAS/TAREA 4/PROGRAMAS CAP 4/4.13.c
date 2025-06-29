#include <stdio.h>
#include <math.h>

/* Pares e impares.
El programa, al recibir como datos N numeros enteros, calcula cuantos de ellos son pares y cuantos impares, con la ayuda de una funcion. */

void parimp(int, int *, int *);

void main(void)
{
    int I, N, NUM, PAR = 0, IMP = 0;
    printf("Ingresa el numero de datos: ");
    scanf("%d", &N);
    for (I =1; I <= N; I++)
    {
        printf("Ingresa el numero %d:", I);
        scanf("%d", &NUM);
        parimp(NUM, &PAR, &IMP);
        /* Llamada a la funcion. PAso de parametros por valor y por referencia. */
    }
    printf("\nNumero de pares: %d", PAR);
    printf("\nNumero de impares: %d", IMP);
}

void parimp(int NUM, int *p, int *I)
/* La funcion incrementa el parametro *p o *I, segun sea el numero par o impar. */
{
    if (NUM % 2 == 0)
        (*p)++;
    else
        (*I)++;
}
