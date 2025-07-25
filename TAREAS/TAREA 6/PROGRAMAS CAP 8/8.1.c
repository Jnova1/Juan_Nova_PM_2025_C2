#include <stdio.h>
#include <string.h>

/* Estructuras-1
El programa muestra la manera en que se cllara una esructura, asi como la forma en que se tiene acceso a los campos de las variables de tipo estructura
tanto para asignacion de valores como para lectura y escritura. */

struct alumno                   /* declaracion de la estructura */
{
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    char direccion[20];
};                         /* observa que la declaracion de una estructura termina co un punto y coma. */

void main(void)
{
    /* observa que las variables d tipo estructura se declaran como cualquier otra variable.
    a1, a2 y a3 son variables de tipo estructura alumno. */
    struct alumno a1 = {12, "Maria", "Contabilidad", 8.9, "Queretaro"}, a2, a3;
    /* los campos de a1 reciben valores directamente. */

    char nom[20], car[20], dir[20];
    int mat;
    float pro;

    /* los campos de a2 reiben valores por medio de una lectura. */
    printf("\Ingrese la matricula del alumno 2: ");
    scanf("%d", &a2.matricula);
    fflush(stdin);
    printf("\Ingrese el nombre del alumno 2: ");
    gets(a2.nombre);
    printf("\Ingrese la carrera del alumno 2: ");
    gets(a2.carrera);
    printf("\Ingrese el promedio del alumno 2: ");
    scanf("%f", &a2.promedio);
    fflush(stdin);
    printf("\Ingrese la direccion del alumno 2: ");
    gets(a2.direccion);

    /* Los campos de a3 reciben valores por medio de asignaciones. */
    printf("\Ingrese la matricula del alumno 3: ");
    scanf("%d", &mat);
    a3.matricula = mat;
    fflush(stdin);
    printf("\Ingrese el nombre del alumno 3: ");
    gets(nom);
    strcpy(a3.nombre, nom);
    printf("\Ingrese la carrera del alumno 3: ");
    gets(car);
    strcpy(a3.carrera, car);
    printf("\Ingrese el promedio del alumno 3: ");
    scanf("%f", &pro);
    a3.promedio = pro;
    fflush(stdin);
    printf("\Ingrese la direccion del alumno 3: ");
    gets(dir);
    strcpy(a3.direccion, dir);

    /* observa la forma en que se imprimen los campos de a1 y a2*/
    printf("\nDatos del alumno 1\n");
    printf("%d\n", a1.matricula);
    puts(a1.nombre);
    puts(a1.carrera);
    printf("%.2f\n", a1.promedio);
    puts(a1.direccion);

    printf("\nDatos del alumno 2\n");
    printf("%d\n", a2.matricula);
    puts(a2.nombre);
    puts(a2.carrera);
    printf("%.2f\n", a2.promedio);
    puts(a2.direccion);

    /* observa otra forma de escrbir los campos de la variable de tipo estructura a3. */
    printf("\nDatos del alumno 3\n");
    printf("%d \t %s \t %s \t %.2f \t %s", a3.matricula, a3.nombre, a3.carrera, a3.promedio, a3.direccion);
}
