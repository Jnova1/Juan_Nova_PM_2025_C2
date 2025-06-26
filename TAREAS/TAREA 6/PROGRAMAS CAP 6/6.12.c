#include <stdio.h>

/*lluvias
el programa, al recibir como dato un arreglo tridimensional que contiene informacion sobre lluvias, genera informacion estadistica. */

const int PRO = 24;
const int MES = 12;
const int ANO = 10;

void lectura(float [PRO][MES][ANO],int, int, int);
void funcion1(float [PRO][MES][ANO],int, int, int);
void funcion2(float [PRO][MES][ANO],int, int, int);
void funcion3(float [PRO][MES][ANO],int, int, int);


int main(void)
{
    float LLU[PRO][MES][ANO];
    lectura(LLU, PRO, MES, ANO);
    funcion1(LLU, PRO, MES, ANO);
    funcion2(LLU, PRO, MES, ANO);
    funcion3(LLU, 18, MES, 5);
}

void lectura(float A[][MES][ANO], int F, int C, int P)
/* Esta funcion se utiliza para leer un arreglo tridimensional de tipo real de F filas, C columnas y P planos de profundidad*/
{
    int K, I, J;
    for (K=0; K<P; K++)
    for (I=0; I<F; I++)
        for (J=0; J<C; J++)
    {
        printf("Año: %d\tProvincia: %d\tMes: %d", K+1, I+1, J+1);
        scanf("%f", &A[I][J][K]);
    }
}

void funcion1(float A[][MES][ANO], int F, int C, int P)
/* Esta funcion se utiliza para localizar la provincia que tuvo el mayor registro de precipitacion pluvial en los ultimos 10 anos. escribe ademas el registro correspondiente*/
{
    int K, I, J, EMAY = -1;
    float ELLU = -1.0, SUM;
    for (I=0; I<F; I++)
    {
        SUM = 0.0;
    for (K=0; K<P; K++)
        for (J=0; J<C; J++)
            SUM += A[I][J][K];
        SUM /= P * C;
        if (SUM > ELLU)
        {
            ELLU = SUM;
            EMAY = I;
        }
    }
    printf("\n\nProvincia con mayor registro de lluvias: %d", EMAY+1);
    printf("\nRegistro: %.2f", ELLU);
}

void funcion2(float A[][MES][ANO], int F, int C, int P)
/* Esta funcion se utiliza para localizar la provincia que tuvo el menor registro de lluvias en el ultimos ano. escribe ademas el registro correspondiente*/
{
    int I, J, EMEN;
    float ELLU = 1000, SUM;
    for (I=0; I<F; I++)
    {
        SUM = 0;
        for (J=0; J<C; J++)
            SUM += A[I][J][P-1];
        SUM /= C;
        if (SUM < ELLU)
        {
            ELLU = SUM;
            EMEN = I;
        }
    }
    printf("\n\nProvincia con menor registro anual de lluvias en el ultmo ano: %d", EMEN+1);
    printf("\nRegistro anual: %.2f", ELLU);
}

void funcion3(float A[][MES][ANO], int F, int C, int P)
/* Esta funcion se utiliza para localizar el mes con mayor registro de lluvias en
la provincia 18 en el quinto ano. escribe ademas el registro correspondiente*/
{
    int J, EMES = -1;
    float ELLU = 01.0;
        for (J=0; J<C; J++)
        {
            if (A[F-1][J][P-1] > ELLU)
            {
                ELLU = A[F-1][J][P-1];
                EMES = J;
            }
        }
        printf("\n\nMes: %d lluvias: %.2f", EMES+1, ELLU);
}

