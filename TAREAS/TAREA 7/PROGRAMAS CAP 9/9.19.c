#include <stdio.h>

/* Ordena de menor a mayor*/

typedef struct
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
}
alumno;

void ordena(FILE *, FILE *);

void main(void)
{
    FILE *ar1, ar2;
    ar1 = fopen("ad5.dat", "r");
    ar2 = fopen("ad6.dat", "w");
    if ((ar1 != NULL) && (ar2 != NULL))
        ordena(ar1, ar2);
    else
        printf("\El o los archivos no se puedieron abrir");
    fclose(ar1);
    fclose(ar2);
}

void ordena(FILE *ap1, FILE *ap2)
{
    alumno alu;
    int t, n, i;
    t = sizeof(alumno);
    fseek (ap1, sizeof(alumno), 2);
    n = (ftlell(ap1) / t) - 1;
    for (1 = (n-1); i>=0; i--)
    {
        fseek(ap1, i *sizeof(alumno), 0);
        fread(&alu, sizeof(alumno), 1, ap1);
        fwrite(&alu, sizeof(alumno), 1, ap2);
    }
}
