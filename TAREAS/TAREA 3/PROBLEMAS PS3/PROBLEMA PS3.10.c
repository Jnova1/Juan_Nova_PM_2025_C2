#include <stdio.h>


void main(void)
{
    float L1, L2, L3, L4, L5, L6;
    int CLA, CAN;
    float MTO, TOT = 0;
    int B1 = 0, B2 = 0, B3 = 0, B4 = 0, B5 = 0, B6 = 0;

    // Lectura de precios
    printf("Ingrese el precio de la localidad 1: ");
    scanf("%f", &L1);
    printf("Ingrese el precio de la localidad 2: ");
    scanf("%f", &L2);
    printf("Ingrese el precio de la localidad 3: ");
    scanf("%f", &L3);
    printf("Ingrese el precio de la localidad 4: ");
    scanf("%f", &L4);
    printf("Ingrese el precio de la localidad 5: ");
    scanf("%f", &L5);
    printf("Ingrese el precio de la localidad 6: ");
    scanf("%f", &L6);

    // Lectura de ventas
    printf("\nIngrese la localidad y cantidad de boletos vendidos (0 0 para terminar):\n");
    scanf("%d %d", &CLA, &CAN);

    while (CLA != 0 || CAN != 0)
    {
        if (CLA == 1)
        {
            MTO = L1 * CAN;
            B1 += CAN;
        }
        else if (CLA == 2)
        {
            MTO = L2 * CAN;
            B2 += CAN;
        }
        else if (CLA == 3)
        {
            MTO = L3 * CAN;
            B3 += CAN;
        }
        else if (CLA == 4)
        {
            MTO = L4 * CAN;
            B4 += CAN;
        }
        else if (CLA == 5)
        {
            MTO = L5 * CAN;
            B5 += CAN;
        }
        else if (CLA == 6)
        {
            MTO = L6 * CAN;
            B6 += CAN;
        }
        else
        {
            MTO = 0;
            printf("Localidad inválida. No se registra la venta.\n");
        }

        TOT += MTO;

        if (MTO > 0)
            printf("Monto de la venta: %.2f\n", MTO);

        scanf("%d %d", &CLA, &CAN);
    }

    // Resultados
    printf("\n--- RESUMEN DE VENTAS ---\n");
    printf("Boletos localidad 1: %d\n", B1);
    printf("Boletos localidad 2: %d\n", B2);
    printf("Boletos localidad 3: %d\n", B3);
    printf("Boletos localidad 4: %d\n", B4);
    printf("Boletos localidad 5: %d\n", B5);
    printf("Boletos localidad 6: %d\n", B6);
    printf("Recaudación total: %.2f\n", TOT);
}



