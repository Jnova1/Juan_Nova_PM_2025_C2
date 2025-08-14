
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEHICULOS 50
#define ARCHIVO "vehiculos.dat"

typedef struct {
    char placa[20];
    char marca[30];
    char modelo[30];
    char tipoCombustible[20]; // "Gasolina" o "Gasoil"
    float kmGalonCarretera;
    float kmGalonCiudad;
    float costoGomas;
    float kmGomas;
    float costoSeguroAnual;
    float costoMantenimiento;
    float kmMantenimiento;
    float costoVehiculo;
    float vidaUtil; // en años
    float kmAnuales;
} Vehiculo;

Vehiculo vehiculos[MAX_VEHICULOS];
int totalVehiculos = 0;

float precioGasolina = 0;
float precioGasoil = 0;

// ---------------- FUNCIONES ----------------
void guardarDatos() {
    FILE *f = fopen(ARCHIVO, "wb");
    if (!f) {
        printf("Error al guardar datos.\n");
        return;
    }
    fwrite(&totalVehiculos, sizeof(int), 1, f);
    fwrite(vehiculos, sizeof(Vehiculo), totalVehiculos, f);
    fwrite(&precioGasolina, sizeof(float), 1, f);
    fwrite(&precioGasoil, sizeof(float), 1, f);
    fclose(f);
}

void cargarDatos() {
    FILE *f = fopen(ARCHIVO, "rb");
    if (!f) return;
    fread(&totalVehiculos, sizeof(int), 1, f);
    fread(vehiculos, sizeof(Vehiculo), totalVehiculos, f);
    fread(&precioGasolina, sizeof(float), 1, f);
    fread(&precioGasoil, sizeof(float), 1, f);
    fclose(f);
}

void crearVehiculo() {
    if (totalVehiculos >= MAX_VEHICULOS) {
        printf("No se pueden agregar más vehículos.\n");
        return;
    }

    Vehiculo v;
    printf("Placa: ");
    scanf(" %[^\n]", v.placa);
    printf("Marca: ");
    scanf(" %[^\n]", v.marca);
    printf("Modelo: ");
    scanf(" %[^\n]", v.modelo);
    printf("Tipo Combustible (Gasolina/Gasoil): ");
    scanf(" %[^\n]", v.tipoCombustible);
    printf("Km por galón en carretera: ");
    scanf("%f", &v.kmGalonCarretera);
    printf("Km por galón en ciudad: ");
    scanf("%f", &v.kmGalonCiudad);
    printf("Costo gomas: ");
    scanf("%f", &v.costoGomas);
    printf("Km vida útil gomas: ");
    scanf("%f", &v.kmGomas);
    printf("Costo seguro anual: ");
    scanf("%f", &v.costoSeguroAnual);
    printf("Costo mantenimiento: ");
    scanf("%f", &v.costoMantenimiento);
    printf("Km entre mantenimientos: ");
    scanf("%f", &v.kmMantenimiento);
    printf("Costo vehículo: ");
    scanf("%f", &v.costoVehiculo);
    printf("Vida útil (años): ");
    scanf("%f", &v.vidaUtil);
    printf("Km anuales promedio: ");
    scanf("%f", &v.kmAnuales);

    vehiculos[totalVehiculos++] = v;
    guardarDatos();
}

void listarVehiculos() {
    if (totalVehiculos == 0) {
        printf("No hay vehículos registrados.\n");
        return;
    }
    for (int i = 0; i < totalVehiculos; i++) {
        printf("\nVehículo %d:\n", i + 1);
        printf("Placa: %s\n", vehiculos[i].placa);
        printf("Marca: %s\n", vehiculos[i].marca);
        printf("Modelo: %s\n", vehiculos[i].modelo);
        printf("Tipo Combustible: %s\n", vehiculos[i].tipoCombustible);
    }
}

void modificarVehiculo() {
    listarVehiculos();
    if (totalVehiculos == 0) return;

    int id;
    printf("Seleccione número de vehículo a modificar: ");
    scanf("%d", &id);
    id--;
    if (id < 0 || id >= totalVehiculos) {
        printf("Vehículo no válido.\n");
        return;
    }

    printf("Nueva marca: ");
    scanf(" %[^\n]", vehiculos[id].marca);
    printf("Nuevo modelo: ");
    scanf(" %[^\n]", vehiculos[id].modelo);

    guardarDatos();
}

void borrarVehiculo() {
    listarVehiculos();
    if (totalVehiculos == 0) return;

    int id;
    printf("Seleccione número de vehículo a borrar: ");
    scanf("%d", &id);
    id--;
    if (id < 0 || id >= totalVehiculos) {
        printf("Vehículo no válido.\n");
        return;
    }

    for (int i = id; i < totalVehiculos - 1; i++) {
        vehiculos[i] = vehiculos[i + 1];
    }
    totalVehiculos--;
    guardarDatos();
}

void gestionarCombustible() {
    printf("Precio Gasolina: ");
    scanf("%f", &precioGasolina);
    printf("Precio Gasoil: ");
    scanf("%f", &precioGasoil);
    guardarDatos();
}

void calcularCostoViaje() {
    listarVehiculos();
    if (totalVehiculos == 0) return;

    int id;
    printf("Seleccione vehículo: ");
    scanf("%d", &id);
    id--;
    if (id < 0 || id >= totalVehiculos) {
        printf("Vehículo no válido.\n");
        return;
    }

    float kmViaje, porcCiudad;
    printf("Kilómetros del viaje: ");
    scanf("%f", &kmViaje);
    printf("Porcentaje en ciudad (0-100): ");
    scanf("%f", &porcCiudad);

    Vehiculo v = vehiculos[id];
    float kmCiudad = kmViaje * (porcCiudad / 100.0);
    float kmCarretera = kmViaje - kmCiudad;

    float costoComb = 0;
    if (strcasecmp(v.tipoCombustible, "Gasolina") == 0)
        costoComb = (kmCiudad / v.kmGalonCiudad + kmCarretera / v.kmGalonCarretera) * precioGasolina;
    else
        costoComb = (kmCiudad / v.kmGalonCiudad + kmCarretera / v.kmGalonCarretera) * precioGasoil;

    float costoGomas = (kmViaje / v.kmGomas) * v.costoGomas;
    float costoSeguro = (v.costoSeguroAnual / v.kmAnuales) * kmViaje;
    float costoMant = (kmViaje / v.kmMantenimiento) * v.costoMantenimiento;
    float depreciacionAnual = v.costoVehiculo / v.vidaUtil;
    float costoDep = (depreciacionAnual / v.kmAnuales) * kmViaje;

    float costoTotal = costoComb + costoGomas + costoSeguro + costoMant + costoDep;
    float costoPorKm = costoTotal / kmViaje;

    printf("\n--- RESULTADOS ---\n");
    printf("Costo Combustible: %.2f\n", costoComb);
    printf("Costo Gomas: %.2f\n", costoGomas);
    printf("Costo Seguro: %.2f\n", costoSeguro);
    printf("Costo Mantenimiento: %.2f\n", costoMant);
    printf("Costo Depreciación: %.2f\n", costoDep);
    printf("Costo por km: %.2f\n", costoPorKm);
    printf("Costo total del viaje: %.2f\n", costoTotal);
}

// ---------------- MAIN ----------------
void main() {
    cargarDatos();
    int opcion;
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Crear vehículo\n");
        printf("2. Listar vehículos\n");
        printf("3. Modificar vehículo\n");
        printf("4. Borrar vehículo\n");
        printf("5. Gestionar precios combustibles\n");
        printf("6. Calcular costo de viaje\n");
        printf("7. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: crearVehiculo(); break;
            case 2: listarVehiculos(); break;
            case 3: modificarVehiculo(); break;
            case 4: borrarVehiculo(); break;
            case 5: gestionarCombustible(); break;
            case 6: calcularCostoViaje(); break;
            case 7: printf("Saliendo...\n"); break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 7);
}