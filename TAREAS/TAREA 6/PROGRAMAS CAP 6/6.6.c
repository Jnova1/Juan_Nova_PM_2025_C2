#include <stdio.h>

/* inercambia
el programa intercambia las columnas de un arreglo bidimensional. los elemntos de la primers columna se intercambian con los de la ultima, los de la segunda con los de la penultima,y asi sucesivamente. */

const int MAX = 50;

void lectura(float [][MAX],int, int);
void intercambia(float [][MAX], int, int);
void imprime(float [][MAX],int, int);

int main(void)
{
    int F, C;
    float MAT[MAX][MAX];
    do
    {
        printf("Ingrese el numero de fila: ");
        scanf("%d", &F);
    }
    while (F > MAX || F < 1);     /* Se verifica que el numero de columnas sea correcto. */

    do
    {
        printf("Ingrese el numero de columnas: ");
        scanf("%d", &C);
    }
    while (C > MAX || C < 1);     /* Se verifica que el numero de columnas sea correcto. */
    lectura(MAT, F, C);
    intercambia(MAT, F, C);
    imprime(MAT, F, C);
}

void lectura(float A[][MAX], int F, int C)
/* la funcion lectura se utiliza para leer un arreglo bidimensional de tipo real de F filas y C columnas*/
{
    int I, J;
    for (I=0; I<F; I++)
    for (J=0; J<C; J++)
    {
        printf("Ingrese el elemento %d %d:  ", I+1, J+1);
        scanf("%f", &A[I][J]);
    }
}
void intercambia(float A[][MAX], int F, int C)
/* ESta funcion se utiliza para intercambiar las columnas del arreglo bidimensional. onserva que el indice correspondiente a las columnas solo se mueve hasta la mitad del arreglo. */
{
    int I, J;
    float AUX;
    /*observa que en esta funcion el indice I se utiliza para columnas, y el indice J para las filas*/
    for (I=0; I < (C / 2); I++)
    for (J=0; J < F; J++)
    {
        AUX = A[J][I];
        A[J][I] = A[J][C-I-1];
        A[J][C-1]=AUX;
    }
}

void imprime(float A[][MAX], int F, int C)
/* la funcion imprime se tiliza para escribir un arreglo bidimensional de tipo real de F filas y C columnas*/
{
    int I, J;
    for (I=0; I<F; I++)
    for (J=0; J<C; J++)
        printf("\nElemento %d %d: %5.2f", I+1, J+1, A[I][J]);
}
