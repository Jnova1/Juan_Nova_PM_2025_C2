#include <stdio.h>
#include <string.h>

/* Uniones.
El programa muestra bla manera como se declarav una union, asi como la forma de acceso a los campos de las variables de tipo union, si como la forma de acceso a los campos de las variables de tipo union tanto para asignacion de valores como para lectura y escritura. */

union datos
{
    char celular[15];
    char correo[20];
};

typedef struct
{
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    union datos personales;
    /* obserba que uno de los campos de la estructura alumno es una union. */
}alumno;

void lectura(alumno *a);

void main(void)
{
    alumno a1 = {120, "Maria", "Contabilidad", 8.9, "5-158-40-50"}, a2, a3;
    /* observa que solo el 1er compotente de una union puede recibir valores por mesio de este tipo de asignaciones.*/

    /* para que puedas observar las diferentes formas en que los campos de las variables de tipo estructura alumno reciben valores, ingresaos los valores
    directamente, los campos de a2 se leen en el programa principal, y los campos de a3 reciben  valores a traves de una funcion*/
    printf("Alumno 2\n");
    printf("Ingrese la matricula: ");
    scanf("%d", &a2.matricula);
    fflush(stdin);
    printf("Ingrese el nombre: ");
    gets(a2.nombre);
    fflush(stdin);
    printf("Ingrese la carrera: ");
    gets(a2.carrera);
    printf("Ingrese el promedio: ");
    scanf("%d", &a2.promedio);
    fflush(stdin);
    printf("Ingrese el correo electronico: ");
    gets(a2.personales.correo);
    /* observa que en la variable a2 de tipo estrctura*/

    printf("Alumno 3\n");
    lectura(&a3);    /* se llama a una funcion para leer los campos de la variable a3*/

    /* Impresion de resultados. */
        printf("\nDatos del alumno 1\n");
        printf("%d\n", a1.matricula);
        puts(a1.nombre);
        puts(a1.carrera);
        printf("%.2f\n", a1.promedio);
        puts(a1.personales.celular);
        /* observa que si tratamos de imprimir el campo correo, escribe basura.*/

        strcpy(a1.personales.correo, "hgimenez@hotmail.com");
        /* se ingres ahora un valor al segundo campo de la union de la varible a0. */

        puts(a1.personales.celular);
        /*ahora escribe basura n el campo del telefono celular.*/
        puts(a1.personales.correo);
        /* escribe el contenido del campo (hgimenez@hotmail.com)*/

        printf("\nDatos del alumno 2\n");
        printf("%d\n", a2.matricula);
        puts(a2.nombre);
        puts(a2.carrera);
        printf("%.2f\n", a2.promedio);
        puts(a2.personales.celular);
        puts(a2.personales.correo);

        printf("Ingrese el telefono celular del alumno 2: ");
        fflush(stdin);
        gets(a2.personales.celular);

        puts(a2.personales.celular);
        puts(a2.personales.correo);

        printf("\nDatos del alumno 3\n");
        printf("%d\n", a3.matricula);
        puts(a3.nombre);
        puts(a3.carrera);
        printf("%.2f\n", a3.promedio);
        puts(a3.personales.celular);
        puts(a3.personales.correo);
    }

    void lectura(alumno *a)
    /* la funcion lectura se utiliza para leer los campos de una variable de tipo estructura alumno*/
    {
    printf("\Ingrese la matricula: ");
    scanf("%d", &(*a).matricula);
    fflush(stdin);
    printf("\Ingrese el nombre: ");
    gets(a->nombre);
    fflush(stdin);
    printf("Ingrese la carrera: ");
    gets(a->carrera);
    printf("Ingrese el promedio: ");
    scanf("%f", &a->promedio);
    printf("Ingrese el telefono celular: ");
    fflush(stdin);
    gets(a->personales.celular);
    }
