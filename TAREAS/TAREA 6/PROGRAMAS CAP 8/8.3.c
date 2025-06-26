#include <stdio.h>
#include <string.h>

/* Estructura-3.
El programa muesra la manera  en qu se declara una estructura anidada, asi como la forma de acceso a los campos de las variables o apuntadores de tipo estructura,
tanto para lectura com para escritura. se utiliza ademas una funcion que recibe como parametro un apuntador de tipo estructura. */

typedef struct            /* declaracion de la estructura domicilio utilizando un typedf. */
{
    char calle[20];
    int numero;
    int cp;
    char localidad[20];
} domicilio;

struct empleado        /* declaracion de la structura anidada empleado. */

{
    char nombre[20];
    char departamento[20];
    float sueldo;
       domicilio direccion;             /* direccion es un campo de tipo estructura domicilio de la estructura empleado. */
};

void lectura(struct empleado *a)
/* funcion que permite leer los campos de un apuntador de tipo estructura empleado. */

{
    printf("Ingrese el nombre del empleado: ");
    gets(a->nombre);
    fflush(stdin);
    printf("Ingrese el departamento de la empresa: ");
    gets(a->departamento);
    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &a->sueldo);
    fflush(stdin);
    printf("--Ingrese la direccion del empleado---: ");
    printf("\n\tCalle: ");
    gets(a->direccion.calle);
    printf("\tNumero: ");
    scanf("%d", &a->direccion.numero);
    printf("\tCodigo postal: ");
    scanf("%d", &a->direccion.cp);
    fflush(stdin);
    printf("\tLocalidad: ");
    gets(a->direccion.localidad);
}

void main(void)
{
    struct empleado e0 = {"Artuto", "Compras", 15500.75, {"San Jeronimo", 120, 3490, "Toluca"}};
    struct empleado *e1, *e2, e3, e4;
    /* se declaran diferentes variables y apuntadores de la estructura empleado para que el lector pueda apreciar
    tambien las diferentes formas en que los campos reciben valores. */

    /* se decalram diferentes variables y apuntadores de la estructura empleado para que el lector pueda aprecir tambien las diferentes formas en que los campos reciben valores. */

    /* en el lector programa principal se leen los campos de una variable, e3, y un apuntador de tipo estructura, *e1.*/
    e1 = (struct empleado *)malloc(sizeof(struct empleado));
}
    printf("Ingrese el nombre del empleado 1:\n");
    scanf("%s", &(*e1).nombre);
    fflush(stdin);
    printf("Ingrese el departamento de la empresa: ");
    gets(e1->departamento);
    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e1->sueldo);
    printf("--Ingrese la direccion del empleado---: ");
    printf("\n\tCalle: ");
    fflush(stdin);
    gets(e1->direccion.calle);
    printf("\tNumero: ");
    scanf("%d", &e1->direccion.numero);
    printf("\tCodigo postal: ");
    scanf("%d", &e1->direccion.cp);
    printf("\tLocalidad: ");
    fflush(stdin);
    gets(e1->direccion.localidad);

    printf("Ingrese el nombre del empleado 3: ");
    scanf("%s", &e3.nombre);
    fflush(stdin);
    printf("Ingrese el departamento de la empresa: ");
    gets(e3.departamento);
    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e3.sueldo);
    printf("--Ingrese la direccion del empleado---: ");
    printf("\n\tCalle: ");
    fflush(stdin);
    gets(e3.direccion.calle);
    printf("\tNumero: ");
    scanf("%d", &e3.direccion.numero);
    printf("\tCodigo postal: ");
    scanf("%d", &e3.direccion.cp);
    printf("\tLocalidad: ");
    fflush(stdin);
    gets(e3.direccion.localidad);

    /* en la funcion lectura se leen los campos de una variable, e4, y un apuntador de tipo estructura, *e2.*/
    e2 = (struct empleado *)malloc(sizeof(struct empleado));
    lectura(e2);

    lectura(&e4);

    printf("\nDatos del empleado 1\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s\n",     e1->nombre,        e1->departamento,
               e1->sueldo,         e1->direccion.calle,          e1->direccion.numero,
           e1->direccion.cp,        e1->direccion.localidad);

    printf("\nDatos del empleado 4\n");
    printf("%s\t%s\t%.2f\t%d\t%d\t%s\n",     e4->nombre,        e4->departamento,
           e4->sueldo,         e4->direccion.calle,          e4->direccion.numero,
           e4->direccion.cp,        e4->direccion.localidad);
}
