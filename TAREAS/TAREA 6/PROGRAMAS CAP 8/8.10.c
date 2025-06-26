#include <stdio.h>
#include <string.h>

/*Vendedores. */

typedef struct
{
    char noba[10];
    char nucu[10];
}banco;

typedef union
{
    banco che;
    banco nomi;
    char venta;
} fpago;

typedef struct
{
    char cnu[20];
    char col[20];
    char cp[5];
    char ciu[15];
}domicilio;

typedef struct
{
    int num;
    char nom[20];
    float ven[20];
    domicilio domi;
    float sal;
    fpago pago;
    int cla;
}vendedor;

void lectura(vendedor, int);
void F1(vendedor *, int);
void F2(vendedor *, int);
void F3(vendedor *, int);
void F4(vendedor *, int);

void main(void)
{
    vendedor VENDEDORES[100];
    int TAM;
    do
    {
        printf("Ingrese el numero de vendedores: ");
        scanf("%d", &TAM);
    }
    while (TAM > 100 || TAM < 1);
    lectura(VENDEDORES, TAM);
    F1(VENDEDORES, TAM);
    F2(VENDEDORES, TAM);
    F3(VENDEDORES, TAM);
    F4(VENDEDORES, TAM);
    printf("\n\tFIN DEL PROGRAMA");
}

void lectura(vendedor A[], int T)
{
    int I, J;
    for (I=0; I<T; I++)
    {
        printf("\n\tIngrese datos del vendedor %d", I+1);
        printf("\nNumero de vendedor: ");
        scanf("%d", &A[I].num);
        printf("Nombre de vendedor: ");
        fflush(studin);
        gets(A[I].nom);
        printf("Venta del ano: \n");
        for (J=0; J<12; J++)
        {
            printf("\tMes %d: ", J+1);
            scanf("%f", &A[I].ven[J]);
        }
        printf("Domicilio del vendedor: \n");
        printf("\tCalle y numero: ");
        fflush(studin);
        gets(A[I].domi.cnu);
        printf("\tColonia: ");
        fflush(studin);
        gets(A[I].domi.col);
        printf("\tCodigo postal: ");
        fflush(studin);
        gets(A[I].domi.cp);
        printf("\tCiudad: ");
        fflush(studin);
        gets(A[I].domi.ciu);
        printf("Salario del vendedor: ");
        scanf("%f", &A[I].sal);
        printf("Forma de pago (Banco-1 Nomina-2 Ventanilla-3): ");
        scanf("%d", &A[I].cla);
        switch(A[I].cla);
        {
            case 1:{
        printf("\tNombre del banco: ");
        fflush(studin);
        gets(A[I].pago.che.noba);
        printf("\tNumero de cuneta: ");
        fflush(studin);
        gets(A[I].pago.che.nucu);
            }
            break;
            case 2;{
        printf("\tNombre del banco: ");
        fflush(studin);
        gets(A[I].pago.che.noba);
        printf("\tNumero de cuneta: ");
        fflush(studin);
        gets(A[I].pago.che.nucu);
            }
            break;
            case 3: A[I].pago.venta = 'S';
            break;
        }
    }
}

void F1(vendedor A[], int T)
int I, J;
float SUM;
printf("\n\t\tVentas totales de los vendedores");
    for (I=0; I<T; I++)
    {
        printf("\nVendedor: %d", A[I].num);
        SUM = 0.0;
        for (J=0; J<12; J++)
        {
            SUM = 0.0;
            for (J=0; J<12; J++)
                SUM += A[I].ven[J];
            if (SUM < 300000.00)
                printf("\nNumero de empleados: %d\nNombre: %d\nVentas: %.2f", A[I].num,
                       A[I].nom,SUM);
        }
    }

    void F4(vendedor A[], int T)
    {
        int I, J;
        float SUM;
        printf("\n\t\tVendedores co cuenta en el banco");
        for (I=0; I<T; I++)
            if (A[I].cla == 1)
            printf("\nNumero de vendedores: %d\n Banco: %s\nCuenta: %s",
                   A[I].num,
                   A[I].pago.che.noba, A[I].pago.che.nucu);
    }

