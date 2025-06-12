#include <stdio.h>

/* Prueba de parametros por referencia. */

void f1(int *);
/* Prototipo de funcion. El parametro es de tipo entero y por referencia observa el uso del operador de indireccion. */

void main(void)
{
    int I, K = 4;
    for (I = 1; I <= 3; I++)
    {
   printf("\n\nValor de k antes de llamr a funcion: %d", ++K);
   f1(&K);
   printf("\nValor de k  despues de llamr a funcion: %d", K);
   /* Llama a la funcion f1. se pasa la direccion de la variable K, por medio del operador de direccion: &. */
    }
    return 0;

}
void f1(int *R)
/* La funcion f1 recibe un parametro por referencia. cada vez que el parametro se utiliza en la funcion debe ir por el operador de indireccion. */
{
    *R += *R;
}
