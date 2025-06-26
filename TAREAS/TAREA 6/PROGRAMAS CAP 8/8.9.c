#include <stdio.h>
#include <string.h>

/* Bienes raices.
El programa maneja informacion sobre las propiedades que tiene una empresa de bienes raices de la ciudad de Lima, Peru, tanto para venta como para renta*/

typedef struct
{
    char zona[20];
    char calle[20];
    char colo[20];
}ubicacion;

typedef struct
{
    char clave[5];
    float scu;
    float ste;
    char car[50];
    ubicacion ubi;

    float precio;
    char dispo;
}propiedades;

void lectura(propiedades, int);
void F1(propiedades *, int);
void F2(propiedades *, int);

void main(void)
{
    propiedades PROPIE[100];
    int TAM;
    do
    {
        printf("Ingrese el numero de propiedades:");
        scanf("%d", &TAM);
    }
    while (TAM > 100 || TAM < 1);
    lectura(PROPIE, TAM);
    F1(PROPIE, TAM);
    F2(PROPIE, TAM);
}

void lectura(propiedades A[], int T)
{
    int I;
    for (I=0; I<T; I++)
    {
        printf("\n\tIngrese datos de la propiedad %d", I+1);
        printf("\nClave: ");
        fflush(studin);
        gets(A[I].calve);
        printf("Superficie cubierta: ");
        scanf("%f", &A[I].scu);
        printf("Superficie terreno: ");
        scanf("%f", &A[I].ste);
        printf("Caracteristicas: ");
        fflush(studin);
        gets(A[I].car);
        printf("\tZona: ");
        fflush(studin);
        gets(A[I].ubi.zona);
        printf("\tcalle: ");
        fflush(studin);
        gets(A[I].ubi.calle);
        printf("\tColonia: ");
        fflush(studin);
        gets(A[I].ubi.colo);
        printf("precio: ");
        scanf("%f", &A[I].precio);
        printf("Disponibilidad (venta-V Renta-R): ");
        scanf("%c", &A[I].dispo);
    }
}

void F1(propiedades A[], int T)
{
    int I;
    printf("\n\t\tListado de propiedades para venta en Miraflores");
    for (I=0; I<T; I++)
        if ((A[I].precio >= 450000) && (strcmp (A[I].precio <= 650000))
    {
        printf("\nClave de la propiedad: ");
        puts(A[I].clave);
        printf("\nSuperficie cubierta: %f", A[I].scu);
        printf("\nSuperficie terreno: %f", A[I].ste);
        printf("\nCaracteristicas: ");
        puts(A[I].car);
        printf("calle: ");
        puts(A[I].ubi.calle);
        printf("Colonia: ");
        puts(A[I].ubi.colo);
        printf("Precio: %.2f\n", A[I].precio);
    }
}

void F2(propiedades A[], int T)
{
    int I;
    float li, ls;
    char zon[20];
    printf("\n\t\tListado de propiedades para renta");
    printf("\nIngrese zona geografica: ");
    fflush(studin);
    gets(zon);
    printf("Ingrese el limite inferior del precio: ");
    scanf("%f", &li);
    printf("Ingrese el limite superio del precio: ");
    scanf("%f", &ls);
    for (I=0; I<T; I++)
        if ((A[I].dispo == 'R') && ((strcmp (A[I].ubi.zona, zon) == 0))
            if ((A[I].precio >= li) && (A[I].precio <= ls))
    {
        printf("\nClave de la propiedad: ");
        puts(A[I].clave);
        printf("\nSuperficie cubierta: %d", A[I].scu);
        printf("\nSuperficie terreno: %d", A[I].ste);
        printf("\nCaracteristicas: ");
        puts(A[I].car);
        printf("calle: ");
        puts(A[I].ubi.calle);
        printf("Colonia: ");
        puts(A[I].ubi.colo);
        printf("Precio: %.2f", A[I].precio);
    }
}
