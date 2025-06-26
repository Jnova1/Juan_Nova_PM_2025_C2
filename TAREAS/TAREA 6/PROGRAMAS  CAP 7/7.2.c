#include <stdio.h>
#include <ctype.h>

/* Funciones para el manejo de carcteres de la biblioteca ctype.h */

void main(void)
{
    char p1;
    printf("\Ingrese un caracter para analizar si este es un digito: ");
    p1 = getchar();
    if (isdigit (p1))
        /* La funcion isdigit regresa 1 si p1 es un digito y 0 en caso contrario */
        if (isdigit (p1))
        /* La funcion isdigit regresa 1 si p1 es un digito y 0 en caso contrario */
        printf("%c es un digito \n", p1);
    else
        printf("%c no es un digito \n", p1);

    fflush(stdin);
    printf("\Ingrese un caracter para examina si este es una letra mayuscula: ");
    p1 = getchar();
    if (isalpha (p1))
        /* La funcion isalpha regresa 1 si p1 es una letra y 0 en caso contrario. */
        printf("%c es una letra \n", p1);
    else
        printf("%c no es una letra \n", p1);

    fflush(stdin);
    printf("\Ingrese un caracter para examina si este es una letra minuscula: ");
    p1 = getchar();
    if (isalpha (p1))
        if (islower (p1))
        /* la fucion islower regresa 1 si p1 es una letra minuscula y 0 en caso cotrario
        la funcion isuper, por otra parte, regresa 1 si p1 es una ltra mayuscula
        y 0 en caso contrario */
        printf("%c es una letra minuscula \n", p1);
    else
        printf("%c no es una letra minuscula \n", p1);
    else
        printf("%c no es una letra \n", p1);

     fflush(stdin);
    printf("\Ingrese una letra para convertirla de mauscula a  minuscula: ");
    p1 = getchar();
    if (isalpha (p1))
        if (isupper (p1))
       printf("%c fue convertida de mayuscula a minuscula \n", tolower(p1));
    /* la funcion tolowe convierte de mayuscula a minuscula. si la convierte de minuscula a myuscula. si la letra es mayuscula no la modifica.  */
    else
       printf("%c es una letra minuscula \n", p1);
    else
        printf("%c no es una letra \n", p1);

}
