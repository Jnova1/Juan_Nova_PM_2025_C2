#include <stdio.h>

/* Transpusta.el programa calcula la transpuesta de una matriz*/

const int MAX = 50;

void lectura(int [][MAX], int, int);
void transpuesta(int [][MAX], int [][MAX], int, int);
void imprime(int [][MAX], int, int);

int main(void)
{
    int MAT[MAX][MAX], TRA[MAX][MAX];
    int FIL, COL;
    do
    {
        printf("Ingrese el numero de filas de la matriz: ");
        scanf("%d", &FIL);
    }
    while (FIL > MAX || FIL < 1);
    /* Se verifica que el numero de filas sea correcto */
    do
    {
        printf("Ingrese el numero de columnas de la matriz: ");
        scanf("%d", &COL);
    }
    while (COL > MAX || COL < 1);
    /* se verifica que el numero de columnas sea correcto. */
    lectura(MAT, FIL, COL);
    transpuesta(MAT, TRA, FIL, COL);
    imprime(TRA, COL, FIL);
}

void lectura(int A[][MAX], int F, int C)
/* ESta funcion se utiliza para una matriz de tipo entero de F filas y C columnas */
{
    int I, J;
    for (I=0; I<F; I++)
        for (J=0; J<C; J++)
    {
        printf("Ingrese el elemento %d %d: ", I+1, J+1);
        scanf("%d", &A[I][J]);
    }
}

void transpuesta(int M1[][MAX], int M2[][MAX], int F, int C)
/* Esta funcion se utiliza para calcular la transpuesta */
{
     int I, J;
    for (I=0; I<F; I++)
    for (J=0; J<C; J++)
    M2[J][I] = M1[I][J];
}

void imprime(int A[][MAX], int F, int C)
/* ESta funcion se utiliza para escribir una matriz de tipo entero de  F filas y C columnas - en este caso la transpuesta  */
{
     int I, J;
    for (I=0; I<F; I++)
    for (J=0; J<C; J++)
        printf("\nElementos %d %d: %d ", I+1, J+1, A[I][J]);
}

