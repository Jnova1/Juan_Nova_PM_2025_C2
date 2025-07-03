#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
	char nombre[50];
	float promedio;
} Alumno;

// FunciC3n para ingresar alumnos y guardarlos en archivo binario
void guardarAlumnos(const char* archivo, int cantidad) {
	Alumno alumnos[MAX];
	FILE* f = fopen(archivo, "wb");

	if (!f) {
		printf("No se pudo abrir el archivo para escritura.\n");
		return;
	}

	for (int i = 0; i < cantidad; i++) {
		printf("Alumno #%d\n", i + 1);
		printf("Nombre: ");
		scanf(" %[^\n]", alumnos[i].nombre);
		printf("Promedio: ");
		scanf("%f", &alumnos[i].promedio);
		fwrite(&alumnos[i], sizeof(Alumno), 1, f);
	}

	fclose(f);
}

// FunciC3n para leer los alumnos desde el archivo
int leerAlumnos(const char* archivo, Alumno alumnos[]) {
	FILE* f = fopen(archivo, "rb");
	int i = 0;

	if (!f) {
		printf("No se pudo abrir el archivo para lectura.\n");
		return 0;
	}

	while (fread(&alumnos[i], sizeof(Alumno), 1, f)) {
		i++;
	}

	fclose(f);
	return i;
}

// BubbleSort por nombre
void ordenarPorNombre(Alumno alumnos[], int n) {
	Alumno temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (strcmp(alumnos[j].nombre, alumnos[j + 1].nombre) > 0) {
				temp = alumnos[j];
				alumnos[j] = alumnos[j + 1];
				alumnos[j + 1] = temp;
			}
		}
	}
}

// BubbleSort por promedio
void ordenarPorPromedio(Alumno alumnos[], int n) {
	Alumno temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (alumnos[j].promedio > alumnos[j + 1].promedio) {
				temp = alumnos[j];
				alumnos[j] = alumnos[j + 1];
				alumnos[j + 1] = temp;
			}
		}
	}
}

// FunciC3n para mostrar los alumnos
void mostrarAlumnos(Alumno alumnos[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%s - Promedio: %.2f\n", alumnos[i].nombre, alumnos[i].promedio);
	}
}

// FunciC3n principal
void menu() {
	const char* archivo = "alumnos.dat";
	Alumno alumnos[MAX];
	int opcion, cantidad;

	do {
		printf("\n1. Guardar alumnos\n");
		printf("2. Mostrar alumnos ordenados por nombre\n");
		printf("3. Mostrar alumnos ordenados por promedio\n");
		printf("4. Salir\n");
		printf("Seleccione una opciC3n: ");
		scanf("%d", &opcion);

		switch (opcion) {
		case 1:
			printf("B?CuC!ntos alumnos desea ingresar? ");
			scanf("%d", &cantidad);
			guardarAlumnos(archivo, cantidad);
			break;
		case 2:
			cantidad = leerAlumnos(archivo, alumnos);
			ordenarPorNombre(alumnos, cantidad);
			mostrarAlumnos(alumnos, cantidad);
			break;
		case 3:
			cantidad = leerAlumnos(archivo, alumnos);
			ordenarPorPromedio(alumnos, cantidad);
			mostrarAlumnos(alumnos, cantidad);
			break;
		case 4:
			printf("Saliendo del programa...\n");
			break;
		default:
			printf("OpciC3n no vC!lida.\n");
		}

	} while (opcion != 4);
}

int main() {
	menu();
	return 0;
}

