#include <stdio.h>


void main(void)
{
    int N1, N2, I, J, ES_PRIMO, ANTERIOR_PRIMO = 0;

    printf("Ingresa el primer numero positivo: ");
    scanf("%d", &N1);
    printf("Ingresa el segundo numero positivo: ");
    scanf("%d", &N2);


    if (N1 > N2)
    {
        int TEMP = N1;
        N1 = N2;
        N2 = TEMP;
    }

    printf("Primos gemelos entre %d y %d:\n", N1, N2);

    for (I = N1; I <= N2; I++)
    {
        
        ES_PRIMO = 1;
        if (I < 2)
            ES_PRIMO = 0;
        else
        {
            for (J = 2; J <= I / 2; J++)
            {
                if (I % J == 0)
                {
                    ES_PRIMO = 0;
                    break;
                }
            }
        }

        if (ES_PRIMO)
        {
            if (I - ANTERIOR_PRIMO == 2)
            {
                printf("(%d, %d)\n", ANTERIOR_PRIMO, I);
            }
            ANTERIOR_PRIMO = I;
        }
    }
}





