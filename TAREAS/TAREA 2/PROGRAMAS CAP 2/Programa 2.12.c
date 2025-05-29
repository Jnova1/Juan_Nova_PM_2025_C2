/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

/* Igualdad de expresiones.
   El programa, al recibir como datos T, P y N, comprueba la igualdad de
   una expresión determinada.
   T, P y N: variables de tipo entero.*/

void main(void)
{
    int T, P, N;

    printf("Ingrese los valores de T, P y N: ");
    scanf("%d %d %d", &T, &P, &N);

    if (P != 0)
    {
        if (pow(T / P, N) == (pow(T, N) / pow(P, N)))
            printf("\nSe comprueba la igualdad");
        else
            printf("\nNo se comprueba la igualdad");
    }
    else
    
        printf("\nP tiene que ser diferente de cero");
    }

