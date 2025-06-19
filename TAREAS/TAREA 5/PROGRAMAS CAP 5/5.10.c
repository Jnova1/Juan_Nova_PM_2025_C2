#include <stdio.h>

/* Busqueda secuencial en arreglos ordenados en forma creciente. */

#define MAX 100

void lectura(int[], int);                  /* prototipos de funciones. */
int busca(int[], int, int);

int main(void)
{
    int RES, ELE, TAM, VEC[MAX];
    do
    {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1);
    /* se verifica que el tamano del arreglo sea correcto. */
    lectura(VEC, TAM);
    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);
    RES = busca(VEC, TAM, ELE);              /* se llama a la funcion que busca en el arreglo. */

    if (RES)
        /* si RES tiene un valor verdadero -diferente de 0-, se escribe la posicion en la que se encontro al elemento */
        printf("\nEl elemento se encuentra en la posicion: %d", RES);
        else
            printf("El elemento no se encuentra en el arreglo");

            return 0;
}

void lectura(int A[], int T)
/* La funcion Lectura se utiliza para leer un arreglo unidimensional de T elementos de tipo entero. */

{
    int I;
    for (I=0; I<T; I++)
    {
        printf("Ingrese el elemento %d: ", I+1);
        scanf("%d", &A[I]);
    }
}

int busca(int A[], int T, int E)
/* esta funion se utiliza para localizar el elemento E en el arreglo unidimensional A.
 si se encuentra, la funcion regresa la posicion correspondiente. En caso contrario regresa 0. */
 {
     int Res, I = 0, BAN = 0;
     while ((I < T) && (E >= A[I]) && !BAN)
        /* observa que se incorpora una condicion. */
        {
        if (A[I] == E)
        BAN = 1;
     else
     I++;
        }
     if (BAN)
        Res = I + 1;
     /* se asigna I+! dado que las posiciones en el arreglo comienzan desde cero. */
     else
        Res = 0;

     return (Res);
 }
