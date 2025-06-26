#include <stdio.h>

/* Declaracion de cadenas de caracteres y asignacion de valores. */

void main(void)
{
    char *cad0;
    cad0 = "Argentina";            /* la declaracion de caracteres y asignacion de valores */
    puts(cad0);

    cad0 = "Brasil";
    /* Correcto. se modifica el contenido de la posicion de la posicion en memoria a la que apunta la variable cad0 -apuntador de tipo cadena de caracteres. */
    puts(cad0);

    char cad1[100];
    gets(cad1);
    /* Incorrecto. Ambas lecturas generan un error en la ejecucion del programa.
    para que un apuntador de tipo cadena de caracteres se pueda utilizar con la funcion de lectura gets,
    es necesario inicializarlo como se hace la siguiente instruccion. */

    char cad3[100] = "";
    gets(cad3);
    /* Correcto. primero se le isigna un valor a la posicion de memoria a la que apunta cad1 lego podemos modificar el contenido de esta posicion de memoria utilizando la funcion gets. */

    char cad2[10] = "Mexico";    /* Correcto*/
    puts(cad2);
    gets(cad2);
    /* El valor de una cadena (declarada como cadena[longitud]) se puede modificar por medio de lecturas o utilizando funciones de la biblioteca string.h (ejemplo 7.6). */
    puts(cad2);
    strcpy(cad2, "Guatemala");
    /* Incorrecto. Observa cuidadosamente el caso anterior y analiza la diferencia que existe con este. Aqui se produce un error en la compilacion del programa, al tratar de asignar la cadena de carateres "Guatemala", al caracter 11 de la cadena. */
}
