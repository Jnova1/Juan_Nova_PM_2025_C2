#include <stdio.h>

/* estructuras-2.
el programa muestra la manera en que se declara una estructura, asi como la forma en que se tiene acceso a los campos de los apuntadores de tipo
estructura tanto para lectura como para escritura. se utiliza ademas una funcion que recibe como parametro un apuntador de tipo estructura. */
struct alumno
{
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    char direccion[20];
};

void lectura(struct alumno *);           /* promedio de funcion*/

void main(void)
{
    struct alumno a0 = {120, "Maria", "Contabilidad", 8.9, "Queretaro"};
    struct alumno *a3, *a4, *a5, *a6;
    /* observa que las varibales *a3, *a4 y *a5 se declaran como apuntadores de tipo estructura alumno. a6 es una variable de tipo estructura alumno */

    a3 = &a0;                   /* en este caso al apuntador de tipo estructura alumno a3 se le asigna la direccion de la variable d etipo estructura alumno, a0. */

    a4 = (struct alumno *)malloc(sizeof(struct alumno));
    /* nota que el apuntador a4 es necesario asignarle una direccion de memoria. para tener acceso a los campos de un apuntador de tipo estructura, utiliza uno de los dos formatos sgts:
    apuntador -> campo
    o bien
    (*apuntador).campo
    en la lectura de los campos de la variable a4 se utilizan como ejemplo ambos formatos. */

    printf("n\Ingrese la matricula del alumno 4: ");
    scanf("%d", (*a4).matricula);
    fflush(stdin);
    printf("\Ingrese el nombre del alumno 4: ");
    gets(a4->nombre);
    printf("\Ingrese la carrera del alumno 4: ");
    gets((*a4).carrera);
    printf("\Ingrese el promedio del alumno 4: ");
    scanf("%f", &a4->promedio);
    fflush(stdin);
    printf("\Ingrese la direccion del alumno 4: ");
    gets(a4->direccion);

    a5 = (struct alumno *)malloc(sizeof(struct alumno));
    lectura(a5);                    /* en este caso se pasa el apuntador de tipo estuctura alumno a6, a la funcion lectura. observa que este caso debemos utilizar el operador de direccion para predecir a la variable. */
    printf("\nDatos del alumno 3\n");
    /* Observa la forma de escribir los campos de los apuntadores de tipo estructura. */

    printf("%d \t%s \t%s \t%.2f \t%s", a3->matricula, a3->nombre, a3->carrera, a3->promedio, a3->direccion);

    printf("\nDatos del alumno 4\n");
    printf("%d \t%s \t%s \t%.2f \t%s", a4->matricula, a4->nombre, a4->carrera, a4->promedio, a4->direccion);

    printf("\nDatos del alumno 5\n");
    printf("%d \t%s \t%s \t%.2f \t%s", a5->matricula, a5->nombre, a5->carrera, a5->promedio, a5->direccion);

    printf("\nDatos del alumno 6\n");
    /* observa la forma de escribir los campos de la variable tipo estructura. */
    printf("%d \t%s \t%s \t%.2f \t%s", a6->matricula, a6->nombre, a6->carrera, a6->promedio, a6->direccion);
}

void lectura(struct alumno *a)
/* esta funcion permite leer los campos de un apuntador de tipo estructura alumno. */
{
    printf("\nIngrese la direccion del alumno: ");
    scanf("%d", &(*a).matricula);
    fflush(stdin);
    printf("Ingrese el nombre del alumno: ");
    gets(a->nombre);
    fflush(stdin);
    printf("Ingrese la carrera del alumno: ");
    gets((*a).carrera);
    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &a->promedio);
    fflush(stdin);
    printf("Ingrese la direccion del alumno : ");
    gets(a->direccion);
}
