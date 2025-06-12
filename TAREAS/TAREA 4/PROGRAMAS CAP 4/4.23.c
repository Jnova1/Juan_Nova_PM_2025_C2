#include <stdio.h>

void trueque(int *x, int *y)
{
    int tem;
    tem = *x;
    *x = *y;
    *y = tem;
}

int suma(int x)
{
    return (x + x);
}
 int main()
 {
     int x = 5, y = 10, 2;

     printf("\nsuma(10) = %d\n", suma(10));

     y = suma(10);
     printf("\nNuevo valor de y = %d\n", y);
     printf("\nAntes del trueque: x = %d, y = %d\n", x, y);
     printf("\nDespues del trueque: x = %d, y = %d\n",x, y);

     return 0;
 }
