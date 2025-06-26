#include <stdio.h>

/* casa de bolsa
el programa, al recibir como datos los precios mensuales de las acciones de sus cinco fondos de inversion, ademas del precio de las acciones al 31 de diciembre del 2003, genera informacion estadistica impostante para la empresa. */

void lecturaM(float [][12], int, int);
void lecturaV(float *, int);
void f1(float [][12], int, int, float *, float *);        /* prototipos de funciones. */
void f2(float [][12], int, int);
void f3(float *, int);


int main(void)
{
    float FON[5][12], PRE[5], REN[5];
    /* REn es un arreglo unidimensional de tipo real que se utiliza para almacenar el rendimiento anual de los fondos de inverion*/

    lecturaM(FON, 5, 12);
    lecturaV(PRE, 5);
    f1(FON, 5, 12, PRE, REN);
    f2(FON, 5, 12);
    f3(REN, 5);
}
void lecturaM(float A[][12], int F, int C)
/* esta funcion se utiliza para leer un arreglo bidimensional de tipo real de F filas y C columnas  */
{
     int I, J;
    for (I=0; I<F; I++)
        for (J=0; J<C; J++)
        {
            printf("precio fondo %d\t mes %d: ", I+1, J+1);
            scanf("%f", &A[I][J]);
        }
}

void lecturaV(float A[], int T)
/* esta funcion se utiliza para leer un arreglo unidimensional de tipo real de T elementos.  */
{
    int I;
    printf("\n");
    for (I=0; I<T; I++)
    {
         printf("precio fondo %d al 31/12/2003: ", I+1);
            scanf("%f", &A[I]);
    }
}

void f1(float A[][12], int F, int C, float B[], float V[])
{
    /* La funcion F1 se utiliza para calcular el rendimientos anual de los fondos de inversion. El resultado se lmacena en el arreglo unidimensional V*/
    int I;
    printf("\nRENDIMIENTOS ANUALES DE LOS FONDOS");
    for (I=0; I<F; I++)
    {
        V[I] = (A[I][C-1] - B[I]) / B[I] * 100;
        printf("\nFondo %d:  %.2f", I+1, V[I]);
    }
}

void f2(float A[][12], int F, int C)
{
    /* la funcion calcula el promedio anualizado de las acciones de los diferentes fondos. */
     int I, J;
     float SUM, PRO;
     printf("\n\nPROMEDIO ANUALIZADO DE LAS ACCIONES DE LOS FONDOS");
    for (I=0; I<F; I++)
    {
        SUM = 0;
        for (J=0; J<C; J++)
            SUM += A[I][J];
        PRO = SUM / C;
        printf("\nFondo %d: %.2f", I+1, PRO);
    }
}

void f3(float A[], int F)
/* esta funcion permite calcular los fondos con el mejor y peor rendimiento. */
{
    float ME = A[0], PE = A[0];
    int M = 0, P = 0, I;
    for (I=1; I<F; I++)
    {
        if (A[I] > ME)
        {
            ME = A[I];
            M = I;
        }
        if (A[I] < PE)
        {
            PE = A[I];
            P = I;
        }
    }
    printf("\n\nMEJOR Y PEOR FONDO DE INVERSION");
    printf("\nMejor fondo:   %d\tRendimiento:  %6.2f", M+1, ME);
    printf("\nPeor fondo:   %d\tRendimiento:  %6.2f", P+1, PE);
}
