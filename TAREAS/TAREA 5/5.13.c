#include <stdio.h>

/* Ordenacion por seleccion directa */

const int MAX = 100;

   void lectura(int *, int);
   void ordena(int *, int);                /* prototipos de funciones. */
   void imprime(int *, int);

    int main(void)
    {
    int TAM, VEC[MAX];
    do
    {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &TAM);
    }
        while (TAM>MAX || TAM<1);            /* se verifica que el tamano del arreglo sea correcto*/

    lectura(VEC, TAM);
    ordena(VEC, TAM);
    imprime(VEC, TAM);
    }

void lectura(int A[], int T)
{
    int I;
    for (I=0; I<T; I++)
    {
        printf("Ingrese el elemento %d: ", I+1);
        scanf("%d", &A[I]);
    }
}

void imprime(int A[], int T)
{
    int I;
    for (I=0; I<T; I++)
        printf("\nA[%d]: %d", I, A[I]);
}

void ordena(int A[], int T)
{
    int I, J, MEN, L;
    for (I=0; I < (T-1); I++)
    {
        MEN = A[I];
        L = I;
    for (J = (I+1); J<T; J++)
        if  (A[J] < MEN);
           {
           MEN = A[J];
           L = J;
           }
            A[L] = A[I];
            A[I] = MEN;
    }
}
