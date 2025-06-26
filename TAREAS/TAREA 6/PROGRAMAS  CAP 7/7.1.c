#include <stdio.h>

/* funciones para el manejo de caracteres de la biblioteca stdio.h*/
void main(void)
{
    char p1, p2, p3 = '$';
    /* declaracion de las variables tipo caracter p1, p2 y p3. observa que a p3*/
    printf("\nIngrese un caracter: ");
    p1=getchar();
    putchar(p1);
    printf("\n");
    fflush(stdin);

    printf("\nEl caracter p3 es: ");
    putchar(p3);
    printf("\n");
    printf("\nIngrese otro caracte: ");
    fflush(stdin);
    scanf("%c", &p2);
    printf("\n char %c", p2);
}
