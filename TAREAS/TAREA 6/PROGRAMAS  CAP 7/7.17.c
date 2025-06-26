#include <stdio.h>
#include <string.h>

/* cadena invertida.
el programa obtiene la cadena invertida.*/

char * inverso(char *);

void main(void)
{
    char fra[50], aux[50];
    printf("\nIngrese la lnea de texto: ");
    gets(fra);
    strcpy(aux, inverso(fra));           /* se copia a aux el resultado de a funcion inverso. */
    printf("\nEscribe la linea de texto en forma inversa: ");
    puts(aux);
}

char * inverso(char *cadena)
/* La funcion calcula el inverso de una cadena ynregres el resutado al programa principal. */
{
    int i = 0, j, lon;
    char cad;
    lon = strlen(cadena);
    j = lon-1;
    while (1 < ((lon - 1) / 2))
        /* observa que el reemplazo de los caracteres se debe realizar solamente hasta la mitad de la cadena. */
    {
        cad = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = cad;
        i++;
        j--;
    }
    return (cadena);
}
