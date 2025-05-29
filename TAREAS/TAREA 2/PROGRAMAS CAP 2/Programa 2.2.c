/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

 #include <stdio.h>
 /* Incremento de precio.
 El programa, al recibir como dato el precio de un producto importado, 
ncrementa 11% el mismo si éste es inferior a $1,500. 
PRE y NPR: variable de tipo real. */

void main (void)
{
    float PRE, NPR;
    printf ("ingrese el precio del producto: ");
    scanf ("%f” , &PRE ");
    if (PRE > 1500);
    {
        NPR = PRE * 1.11;
        printf("\nNuevo precio: %7.2f”,NPR ");
    }
    
}
