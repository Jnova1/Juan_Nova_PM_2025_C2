#include <stdio.h>

/* Universidad.
el programa, al recibir informacion sobre el numero de alumnos que han ingresado a sus ocho diferentes careras e los dos semenstres lectivos de los ultimos cinco anos, obtiene informacion util para el departmento de escolar */

const int F = 8, C = 2, P = 5;
/* Se declaran constantes para la fila, la columna y la profundidad. */
void lectura( int [][C][P], int, int, int);
void funcion1( int [][C][P], int, int, int);
void funcion2( int [][C][P], int, int, int);
void funcion3( int [][C][P], int, int, int);
/* prototipo de funciones. cada prototipo de funcion corresponde a uno de los incisos. */

int main(void)
{
    int uni[F][C][P];
    lectura(uni, F, C, P);
    funcion1(uni, F, C, P);
    funcion2(uni, F, C, P);
    funcion3(uni, 6, C, P);
    /* se coloca el 6 como parametro ya que es la clave de la ingenieria en computacion. */

    return 0;
}

void lectura(int A[][C][P], int F1, int C0, int PR)
/* la funcion lectura se utiliza para leer un arreglo tridimensioanl de tpo entero de F1 filas, C0 columnas y PR profundidad. observa que al ser tridimensional se necesitan tres ciclos para recorrer el arreglo. */
{
    int K, I, J;
    for (K=0; K<PR; K++)
        for (I=0; I<F1; I++)
        for (J=0; J<C0; J++)
    {
        printf("Ano: %d\tCarrera: %d\tSemestre: %d ", K+1, I+1, J+1);
        scanf("%d", &A[I][J][K]);
    }
}

void funcion1(int A[][C][P], int F1, int C0, int PR)
/* Esta funcion se utiliza para determinar el ano en el que ingreso el mayor numero de alumnos a la universidad. observa que el primer ciclo externo  corresponde a los anos */
{
    int K, I, J, MAY = 0, AO = -1, SUM;
    for (K = 0; K < PR; K++)
        /* Por cada ano se suma el ingreso de los dos semestres de las ocho carreras*/
    {
        SUM = 0;
          for (I = 0; I < F1; I++)
           for (J = 0; J < C0; J++)
           SUM += A[I][J][K];
          if (SUM > MAY)
          {
              MAY = SUM;
              AO = K;
          }
    }
    printf("\n\nAno con mayor ingreso de alumnos: %d   Alumnos: %d", AO+1, MAY);
}

void funcion2(int A[][C][P], int F1, int C0, int PR)
/* esta funcion se utilizan para determinar la carrera que recibio el mayor numero de alumnos el ultimo ano. obseva que no se utiliza un ciclo para los planos de la profundidad, ya que es un dato (PR)*/
{
    int I, J, MAY = 0, CAR = -1, SUM;
    for (I=0; I<F1; I++)
        SUM += A[I][J][PR-1];
    if (SUM > MAY)
    {
        MAY = SUM;
        CAR = I;
    }
    printf("\n\nCarrera con mayor numero de alumnos: %d alumnos: %d", CAR+1, MAY);
}

void funcion3(int A[][C][P], int F1, int C0, int PR)
/* esta funcion se utiliza para determinar el ao en el que la carrera ingenieria en computacion recibio el mayor numero de aunnos. observa que no se utiliza un ciclo para trabajar con las filas, ya que es un dato (F1) */
{
    if (F1 < 1 || F1 > 8)
    {
        printf("\n\nError: carrera no valida. \n");
        return;
    }

   int K, J, MAY = 0, AO = -1, SUM;
    for (K=0; K<PR; K++)
    {
        SUM = 0;
           for (J=0; J<C0; J++)
           SUM += A[F1-1][J][K];
          if (SUM > MAY)
          {
              MAY = SUM;
              AO = K;
          }
    }
    printf("\n\nAno con mayor ingreso de alumnos: %d   Alumnos: %d", AO+1, MAY);
}
