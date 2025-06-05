#include <stdio.h>


void main(void)
{
    int x, n = 1, signo = 1, i;
    float termino, sen = 0.0, diferencia;
    int factorial;
    
    printf("Ingresa el valor de x (en radianes): ");
    scanf("%d", &x);

    do
    {
        factorial = 1;
        for (i = 1; i <= n; i++)
        {
            factorial = factorial * i;
        }

        float potencia = 1;
        for (i = 1; i <= n; i++)
        {
            potencia = potencia * x;
        }

        termino = signo * (potencia / factorial);
        
        sen = sen + termino;

        if (signo == 1)
            signo = -1;
        else
            signo = 1;

        if (termino < 0)
            diferencia = -termino;
        else
            diferencia = termino;

        n = n + 2;

    } while (diferencia > 0.001);

    printf("\nAproximación de sen(%d) = %f", x, sen);
}






