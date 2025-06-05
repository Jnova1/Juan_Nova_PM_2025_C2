#include <stdio.h>
#include <math.h>

void main(void)
{
    int T, P, R;
    float E;

    for (T = 1; T <= 20; T++)
    {
        for (P = 1; P <= 20; P++)
        {
            for (R = 1; R <= 10; R++)
            {
                E = 7 * pow(T, 4) - 6 * pow(P, 3) + 12 * pow(R, 5);

                if (E < 5850)
                {
                    printf("T = %d, P = %d, R = %d = E = %.0f\n", T, P, R, E);
                }
            }
        }
    }
}









