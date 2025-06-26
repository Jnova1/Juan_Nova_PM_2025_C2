#include <stdio.h>

/* Suma matrices
El programa, al recibir como datos dos arreglos bidimensionales del mismo tamano, calcula la suma de ambos y la almacena en un tercer arreglo bidimensional. */

const int MAX = 50;

/* Prototipo de funciones */
void lectura(int [] [MAX], int, int);
void suma(int [] [MAX], int [] [MAX], int [] [MAX], int, int);
void imprime(int [] [MAX], int, int);

int main(void)
{
    int MAX[MAX][MAX], MB[MAX][MAX], MC[MAX][MAX];
    /* Declaracion de los tres arreglos */
    int FIL, COL;
    do
    {
        printf("Ingrese el numero de filas de los areglos: ");
        scanf("d%", &FIL);
    }
    while (FIL> MAX || FIL< 1);
    /* Se verifica que el numero de filas sea correcto */
    do
    {
    printf("Ingrese el numero de filas de los areglos: ");
    scanf("d%", &COL);
    }
    while
        /* se verifica que el numero de columnas sea correcto */
        printf("\Lectura del arreglo MA\n");
    lectura(MA, FIL, COL);
        printf("\Lectura del arreglo MB\n");
    lectura(MB, FIL, COL);
    Suma (MA, MB, MC, FIL, COL);
        printf("\Lectura del arreglo MC\n");
        imprime(MC, FIL, COL);
}

void lectura(int A[][MAX], int F, int C)
/* La fucion lectura se utiliza para leer un arreglo bidimensional entero de F filas y C columnas. */
{
    int I, J;
    for (I=0; I<F; I++)
        for (J=0; J<C; J++)
    {
        printf("Ingrese el elemento %d %d: ", I+1, J+1);
        scanf("%d", &A[I][J]);
    }
}

void suma(int M1[][MAX], int M2[][MAX], int M3[][MAX], int F, int C)
/* la funcion suma se utiliza para sumar los arreglos y almacenar el resultado en un tercer arreglo bidimencional */
{
    int I, J;
    for (I=0; I<F; I++)
        for (J=0; J<C; J++)
            M3[I][J]= M1[I][J] + M2[I][J];
}

void imprime(int A[][MAX], int F, int C)
/* la funcion imprime se utiliza para escribir un arreglo bidimensional de tipo entero de f filas y c columnas */
{
    int I, J;
    for (I=0; I<F; I++)
        for (J=0; J<C; J++)
            printf("\nEl elemento %d %d: %d", I, J, A[I][J])
}
