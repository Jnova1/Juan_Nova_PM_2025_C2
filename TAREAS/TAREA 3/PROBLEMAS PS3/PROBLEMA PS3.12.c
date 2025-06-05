#include <stdio.h>

void main(void)
{
    int NUM, I, DIV, ES_PRIMO;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &NUM);

    I = 2;
    while (I < NUM)
    {
        ES_PRIMO = 1; 
        DIV = 2;

        while (DIV <= I / 2)
        {
            if (I % DIV == 0)
            {
                ES_PRIMO = 0; 
                break;
            }
            DIV++;
        }

        if (ES_PRIMO)
        {
            printf("%d ", I);
        }

        I++;
    }

    printf("\n");
}





