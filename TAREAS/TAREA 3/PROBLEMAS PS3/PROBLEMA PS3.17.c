#include <stdio.h>

void main(void)
{
    int N, I, J;

    printf("Ingresa un número entero positivo (N): ");
    scanf("%d", &N);

    for (I = 1; I <= N; I++)
    {
        for (J = 1; J <= I; J++)
        {
            printf("%d ", J);
        }

        for (J = I - 1; J >= 1; J--)
        {
            printf("%d ", J);
        }

        printf("\n");
    }
}








