#include <stdio.h>

/* Producto de vectores. El programa calcula el proucto de dos vectores y almacena el resultaod en otro arreglo unidimensional. */

const int MAX = 10;                     /* se define una constante par el tamano de los arreglos */
void Lectura(int VEC[], int T);
void Imprime(int VEC[], int T);         /* Observa que en los parametros, para indicar que lo que se recibe es un arreglo, se puede escribir VEC[] o *vec[]. */
void Producto(int *X, int *Y, int *Z, int T);

void main(void)
{
    int VE1[MAX], VE2[MAX], VE3[MAX];
    /* Se declaran tres arreglos de tipo entero de 10 elementos. */
    Lectura(VE1, MAX);
    /* se llama a la funcion Lectura. observa que el paso del arreglo a la funcion es por referencia. solo se debe incluir el nombre del areglo a la funcion es po referncia. solo se debe incluir el nombre del arreglo. */
    Lectura(VE2, MAX);
    Producto(VE1, VE2, VE3, MAX);
    /* Se llama a la suncion producto. se pasan los nombres de los tres areglos. */
    printf("\nProducto de los vectores");
    Imprime(VE3, MAX);

    return 0;
}

void Lectura(int VEC[], int T)
/* La funcion lectura se utiliza para leer un arreglo unidimensional de T elemtos de tipo entero. */
{
    int I;
    printf("\n");
    for (I=0; I<T; I++)
    {
        printf("Ingrese el elemento %d: ", I+1);
        scanf("%d", &VEC[I]);
    }
}

void Imprime(int VEC[], int T)
/* la funcion imprime se utiliza para imprimir un arreglo unidimensional de T elemtos de tipo entero. */
{
    int I;
    for (I=0; I<T; I++)
        printf("\n VEC[%d]: %d", I+1, VEC[I]);
}

/* Esta funcion se utiliza para calcular el producto de dos arreglos unidimensionales de T elementos de tipo entero */
void Producto(int *X, int *Y, int *Z, int T)
{
    int I;
    for(I=0; I<T; I++)
        Z[I] = X[I] * Y[I];
}
