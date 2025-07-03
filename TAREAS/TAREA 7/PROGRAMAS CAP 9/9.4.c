#include <stdio.h>

/* Archivo y cadenas de caracteres.*/

void main(void)
{
    char cad[50];
    FILE *ap;
    if((ap = fopen("arc.txt", "w")) != NULL)
    {
        while (!feof(ap))
        {
            fgets(cad, 50, ap);
            puts(cad);
        }
        fclose(ap);
    }
    else
        printf("No se puede abrir el archivo");
}
