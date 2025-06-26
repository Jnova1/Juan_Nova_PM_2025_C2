#include <stdio.h>

/* Diagonal principal.
El programa, al recibir como dato una matriz de tipo entero, escribe la diagonal principal. */

const int TAM = 10;

void lectura(int [][TAM], int);
void imprime(int [][TAM], int);
/* observa que siempre es necesario declara el numero de columnas. si no lo haces, el compilador marcara un error de sintaxis */

int main(void)
{
    int MAT[TAM][TAM];
    lectura(TAM, TAM);
    imprime(TAM, TAM);
    return 0;
}

void lectura(int A[] [TAM], int F)
/* la funcion lectura se utiliza para leer un arreglo bidimensional. observa que solo se debe pasar como paramentro el numero de flas ya que la matriz es cuadrada. */
{
    int I, J;
    for (I=0; I<F; I++)
        for (J=0; J<F; J++)
    {
        printf("Ingrese el elemento %d %d: ", I+1, J+1);
        scanf("%d", &A[I][J]);
    }
}

void imprime(int A[][TAM], int F)
/* la funcion imprime se utiliza para escribir un arreglo bidimensional cuadrada de F filas y columnas. */
{
    int I,J;
    for (I=0; I<F; I++)
    for (J=0; J<F; J++)
        if (I == J)
        printf("\nDiagonal [%d][%d]: %d ", I, J, A[I][J]);
}
