#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nombre[50];
    int edad;
    float promedio;
} Alumno;

void guardarAlumnos(const char *archivo) {
    int cantidad;
    printf("¿Cuántos alumnos desea guardar?: ");
    scanf("%d", &cantidad);

    // Memoria dinámica para los alumnos
    Alumno *lista = (Alumno *)malloc(cantidad * sizeof(Alumno));

    if (lista == NULL) {
        printf("No se pudo asignar memoria.\n");
        return;
    }

    // Pedir los datos
    for (int i = 0; i < cantidad; i++) {
        printf("\nAlumno %d\n", i + 1);
        printf("Nombre: ");
        scanf(" %[^\n]", lista[i].nombre); // Leer nombre con espacios
        printf("Edad: ");
        scanf("%d", &lista[i].edad);
        printf("Promedio: ");
        scanf("%f", &lista[i].promedio);
    }

    // Guardar en archivo binario
    FILE *f = fopen(archivo, "wb");
    if (!f) {
        printf("Error abriendo el archivo.\n");
        free(lista);
        return;
    }

    // Primero escribimos la cantidad
    fwrite(&cantidad, sizeof(int), 1, f);
    // Luego los datos
    fwrite(lista, sizeof(Alumno), cantidad, f);

    fclose(f);
    free(lista);
    printf("Alumnos guardados correctamente.\n");
}

void leerAlumnos(const char *archivo) {
    FILE *f = fopen(archivo, "rb");
    if (!f) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    int cantidad;
    fread(&cantidad, sizeof(int), 1, f);

    // Memoria dinámica para leer los alumnos
    Alumno *lista = (Alumno *)malloc(cantidad * sizeof(Alumno));

    if (lista == NULL) {
        printf("No se pudo asignar memoria para leer.\n");
        fclose(f);
        return;
    }

    fread(lista, sizeof(Alumno), cantidad, f);
    fclose(f);

    // Mostrar los datos
    printf("\n--- Alumnos leídos del archivo ---\n");
    for (int i = 0; i < cantidad; i++) {
        printf("\nAlumno %d:\n", i + 1);
        printf("Nombre: %s\n", lista[i].nombre);
        printf("Edad: %d\n", lista[i].edad);
        printf("Promedio: %.2f\n", lista[i].promedio);
    }

    free(lista);
}

int main() {
    const char *nombreArchivo = "alumnos.bin";
    int opcion;

    do {
        printf("\nMenú:\n");
        printf("1. Guardar alumnos\n");
        printf("2. Leer alumnos\n");
        printf("0. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                guardarAlumnos(nombreArchivo);
                break;
            case 2:
                leerAlumnos(nombreArchivo);
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 0);

    return 0;
}
