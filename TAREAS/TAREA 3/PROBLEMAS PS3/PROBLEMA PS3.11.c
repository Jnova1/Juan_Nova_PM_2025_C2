#include <stdio.h>

void main(void)
{
    int N, I;
    float VIN1, VIN2, VIN3, VIN4;
    float TV1 = 0, TV2 = 0, TV3 = 0, TV4 = 0;
    float TAN;

    printf("Ingrese el numero de años de produccion: ");
    scanf("%d", &N);

    I = 1;
    while (I <= N)
    {
        printf("\nAño %d:\n", I);
        printf("Ingrese produccion de vino tipo 1 (litros): ");
        scanf("%f", &VIN1);
        printf("Ingrese produccion de vino tipo 2 (litros): ");
        scanf("%f", &VIN2);
        printf("Ingrese produccion de vino tipo 3 (litros): ");
        scanf("%f", &VIN3);
        printf("Ingrese produccion de vino tipo 4 (litros): ");
        scanf("%f", &VIN4);

        TV1 += VIN1;
        TV2 += VIN2;
        TV3 += VIN3;
        TV4 += VIN4;

        TAN = VIN1 + VIN2 + VIN3 + VIN4;
        printf("Total producido en el año %d: %.2f litros\n", I, TAN);

        I++;
    }

    printf("\n--- RESUMEN TOTAL ---\n");
    printf("Total vino tipo 1: %.2f litros\n", TV1);
    printf("Total vino tipo 2: %.2f litros\n", TV2);
    printf("Total vino tipo 3: %.2f litros\n", TV3);
    printf("Total vino tipo 4: %.2f litros\n", TV4);
}




