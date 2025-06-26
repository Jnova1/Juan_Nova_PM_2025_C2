#include <stdio.h>
#include <string.h>

/* escuela.
El programa genera informacion estadistica de los alumnos de una escuela*/

typedef struct     /* declaracion de la estructura alumno utilizando un typedef. */

{
    int matricula;
    char nombre[30];
    float cal[5];
    /*observa que el campo de la  estructura alumno es un arreglo unidimensional*/
    }
    alumno;

    void Lectura(alumno[], int T);
    void F1(alumno *, int TAM);
    void F2(alumno *, int TAM);
    void F3(alumno *, int TAM);

    void main(void)
    {
        alumno ARRE[50];    /* se declaa um arreglo unidimensional de tipo alumno*/
        int TAM;
        do
        {
            printf("Ingrese el tamno del arreglo: ");
            scanf("%d", &TAM);
        }
        while (TAM > 50 || TAM < 1);            /* se verifiva que el tamano del arreglo sea correcto */
        Lectura(ARRE, TAM);
        F1(ARRE, TAM);
        F2(ARRE, TAM);
        F3(ARRE, TAM);
    }
    void Lectura(alumno A[], int T)
    /* la funcion lectura se utiliza para leer un arreglo unidimensional de tipo estructura alumno de T elemento. */
    {
        int I, J;
        for (I=0; I<T; I++)
    {
        printf("\nIngrese los datos del alumno %d", I+1);
        printf("\nIngrese la matricula del alumno:", I+1);
        scanf("%d", &A[I].matricula);
        fflush(stdin);
        printf("\Ingrese el nombre del alumno: ");
        gets(A[I].nombre);
        for (J=0; J<5; J++)
        {
        printf("\nIngrese la calificacion %d del alumno %d:", J+1, I+1);
        scanf("%f", &A[I].cal[J]);
        }
    }
    }

    void F1(alumno A[], int T)
    /* La funcion F1 obtiene la matriculla y el promedio de cada alumno. */
    {
        int I, J;
        float SUM, PRO;
        for (I=0; I<T; I++)
        {
            printf("\nMatricula del alumno: %d", A[I].matricula);
            SUM = 0.0;
            for (J=0; J<5; J++)
                SUM = SUM + A[I].cal[J];
            PRO = SUM / 5;
            printf("\t\tPromedio: %.2f", PRO);
        }
    }

    void F2(alumno A[], int T)
    {
        int I;
        printf("\nAlumnos con calificacion en la 3ra materia > 9");
        for (I=0; I<T; I++)
            if(A[I].cal[2] > 9)
            printf("\nMatericula del alumno: %d", A[I].matricula);
    }
        void F3(alumno A[], int T)
        {
            int I;
        float SUM, PRO = 0.0;
        for (I=0; I<T; I++)
                SUM = SUM + A[I].cal[3];
            PRO = SUM / T;
            printf("\n\nPromedio de la materia 4: %.2f", PRO);
        }



