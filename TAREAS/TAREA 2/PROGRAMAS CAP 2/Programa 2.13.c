/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

 #include <stdio.h>
 #include <math.h>
 /* Función.
 El programa, al recibir como dato un valor entero, calcula el resultado de 
 una función.
 Y: variable de tipo entero.
 X: variable de tipo real. */
 #include <stdio.h>
#include <math.h>

void main(void)
{
    float X;
    int Y;

    printf("Ingrese el valor de Y: ");
    scanf("%d", &Y);

    if (Y < 0 || Y > 50)
        X = 0;
    else if (Y <= 10)
        X = 4.0 / Y - Y;  
    else if (Y <= 25)
        X = pow(Y, 3) - 12;
    else
        X = pow(Y, 2) + pow(Y, 3) - 18;

    printf("\n\nY = %d\tX = %8.2f\n", Y, X);

}


