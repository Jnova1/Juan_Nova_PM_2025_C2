#include <stdio.h>

/* funciones para el manejo de cadenas de caracteres de la biblioteca stdio.h*/

void main(void)
{
    char *cad0 = "Buenos dias"; /* en este caso se asignan 11 caracteres mas el aracter de terminaccion '\0' a la posicion de memoria a la que apnta la variable cad0 -apuntador del tipo cadena de caracteres-*/

    char cad1[20] = "Hola";                  /* se asignan cuatro caracteres mas el caracter de terminacion a la variable tipo char cad1. observa que cad1 tiene espacio para 20 caracteres. */

    char cad2[] = "Mexico";                 /* en ese caso se asignan seis caracteres (mas el caracter de terminacion) a la variable cad2. observa que cad2 no tiene espacio reservado como cad1; por lo tanto, acepta cualquier numero de caracteres. */

    char cad3[] = {'B', 'i', 'e', 'n', 'v', 'e', 'n', 'i', 'd', 'o', '\0'};
    /* observa otra forma de asignacion de valores a la variable cad3. */

    char cad4[20], cad5[20], cad6[20];

    printf("\nLa cadena cad0 es: ");
    puts(cad0);
    /* la funcion puts es la mas apropiada para escribir cadenas de caracteres. Observa que esta funcion baja automaticamente una linea despues de imprimir la cadena. */

    printf("\nLa cadena cad1 es: ");
    printf("%s", cad1);
    /* La funcion*/

    printf("\nLa cadena cad2 es: ");
    puts(cad2);
    printf("\nLa cadena cad3 es: ");
    puts(cad3);

    printf("\nIngrese una linea de texto -se lee con gets-: \n");
    /* */

    gets(cad4);
    printf("\nLa cadena cad4 es: ");
    puts(cad4);
    fflush(stdin);

    printf("\nIngrese una linea de texto -se lee con scanf-: \n");
    scanf("%s", cad5);
    /**/

    printf("\nLa cadena cad5 es: ");
    printf("%s", cad5);
    fflush(stdin);

    char p;
    int i = 0;
    /**/
    printf("\nIngrese una linea de texto - se lee cada caracter con getchar-: \n");
    /**/

    while ((p = getchar())!= '\n')
        cad6[i++] = p;
    cad6[i] = '\0';

    /**/

    printf("\nLa cadena cad6 es: ");
    puts(cad6);

}
