#include <stdio.h>

/* Busqueda secuencial en arreglos desordenaos. */

const int MAX=100;                     /* Prototipos de funciones. */

void lectura(int, int);
int busca(int *, int, int);

void main(void)
{
    int RES, ELE, TAM, VEC[MAX];
    do
    {
        printf("Ingrese el tamano del areglo: ");
        scanf("%d", &TAM);
    }
    while (TAM>MAX || TAM<1);             /* se llama a la funcion que busca en el arreglo sea correcto . */
    lectura(VEC, TAM);
    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);
    RES = busca(VEC, TAM, ELE);          /* Se llama a la funcion que busca en el arreglo. */
    if (RES)
        /* si RES tiene un valor verdadero -diferente de 0-, se escribe la posicion en la que se encontro el elemento. */
        printf("\nEl elemento se encuentra en la posicion %d",  RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo");
}

void lectura(int A[], int T)
/* la funcion lectura se utiliza para leer un arreglo undimensional de T elementos de tipo entero */
{
    int I;
    for (I=0; I<T; I++)
    {
        printf("Ingrese el elemento %d: ", I+1);
        scanf("%d", &A[I]);
    }
}

int busca(int A[], int T, int K)
/* Esta funcion localiza en el arreglo un elemento determinado. si el elemento es encontrado, regresa la posicion correspondiente. en caso contrario, regresa 0 */
{
    int I = 0, BAN = 0, RES;
    while (I < T && !BAN)
        if (A[I] == K)
        BAN++;
    else
        I++;
    if (BAN)
        RES = I + 1;
    /* Se asigna I+1 dado que las posiciones en el arreglo comienzan desde cero. */
    else
        RES = BAN;
    return (RES);
}
