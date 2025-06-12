#include <stdio.h>

/* Parametros y funciones. */

int f1(void);
int f2(void);                       /* Prototipos de funciones. */

int f3(void);
int f4(void);
int k = 5;

int main(void)
{
    int I;
    for (I = 1; I <= 4; I++)
    {
        printf("\n\nEl resultado de la funcion f1 es: %d", f1());
        printf("\n\nEl resultado de la funcion f2 es: %d", f2());
        printf("\n\nEl resultado de la funcion f3 es: %d", f3());
        printf("\n\nEl resultado de la funcion f4 es: %d", f4());
    }
    return 0;
}

int f1(void)
{
    k *= k;
    return (k);
}
    int f2(void)
    {
        int k = 3;
        k++;
        return (k);
    }

    int f3(void)
    {
        static int k = 6;
        k += 3;
        return (k);
    }

    int f4(void)
    {
        int k = 4;
        k = k + k;
        return (k);
    }
