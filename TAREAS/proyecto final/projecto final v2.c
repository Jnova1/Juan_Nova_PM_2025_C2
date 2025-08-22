#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#endif

typedef struct {
    char placa[20];
    char marca[50];
    char modelo[50];
    char tipoCombustible[20];  
    float kmGalonCarretera;
    float kmGalonCiudad;
    float costoGomas;             
    float kmVidaGomas;
    float costoSeguro;            
    float costoMantenimiento;     
    float kmEntreMantenimientos;
    float costoVehiculo;
    float vidaUtilAnios;         
    float kmAnuales;
} Vehiculo;

#define MAX_VEH 50
static Vehiculo vehiculos[MAX_VEH];
static int totalVehiculos = 0;

static const char *ARCHIVO_TXT = "vehiculos.txt";

static void limpiarBuffer(void){ int c; while((c=getchar())!='\n' && c!=EOF){} }

static void toUpperInPlace(char *s){
    for(; *s; ++s) *s = (char)toupper((unsigned char)*s); // solo afecta A-Z, OK para GASOLINA/GASOIL
}

static void trim(char *s){
    size_t i=0; while(s[i] && isspace((unsigned char)s[i])) i++;
    if(i) memmove(s, s+i, strlen(s+i)+1);
    size_t n=strlen(s); while(n>0 && isspace((unsigned char)s[n-1])) s[--n]='\0';
}


static void guardarVehiculosTXT(void){
    FILE *f = fopen(ARCHIVO_TXT, "w");
    if(!f){ printf("Error al guardar datos.\n"); return; }

    for(int i=0;i<totalVehiculos;i++){
        Vehiculo v = vehiculos[i];
        fprintf(f,
            "Placa=%s,Marca=%s,Modelo=%s,TipoCombustible=%s,"
            "KmGalonCarretera=%.2f,KmGalonCiudad=%.2f,"
            "CostoGomas=%.2f,KmVidaGomas=%.2f,CostoSeguro=%.2f,"
            "CostoMantenimiento=%.2f,KmEntreMantenimientos=%.2f,"
            "CostoVehiculo=%.2f,VidaUtilAños=%.2f,KmAnuales=%.2f\n",
            v.placa, v.marca, v.modelo, v.tipoCombustible,
            v.kmGalonCarretera, v.kmGalonCiudad,
            v.costoGomas, v.kmVidaGomas, v.costoSeguro,
            v.costoMantenimiento, v.kmEntreMantenimientos,
            v.costoVehiculo, v.vidaUtilAnios, v.kmAnuales
        );
    }
    fclose(f);
}

static int parseLineaEtiquetas(const char *line, Vehiculo *out){
    char buf[1024]; strncpy(buf, line, sizeof(buf)-1); buf[sizeof(buf)-1]='\0';
    char *token = strtok(buf, ",");
    int asignados = 0;
    Vehiculo v; memset(&v, 0, sizeof(v));

    while(token){
        char *eq = strchr(token, '=');
        if(eq){
            *eq = '\0';
            char key[64]; strncpy(key, token, sizeof(key)-1); key[sizeof(key)-1]='\0';
            char *val = eq+1;
            trim(key); trim(val);

            if(strcmp(key,"Placa")==0){ strncpy(v.placa,val,sizeof(v.placa)-1); asignados++; }
            else if(strcmp(key,"Marca")==0){ strncpy(v.marca,val,sizeof(v.marca)-1); asignados++; }
            else if(strcmp(key,"Modelo")==0){ strncpy(v.modelo,val,sizeof(v.modelo)-1); asignados++; }
            else if(strcmp(key,"TipoCombustible")==0){ strncpy(v.tipoCombustible,val,sizeof(v.tipoCombustible)-1); toUpperInPlace(v.tipoCombustible); asignados++; }
            else if(strcmp(key,"KmGalonCarretera")==0){ v.kmGalonCarretera=(float)atof(val); asignados++; }
            else if(strcmp(key,"KmGalonCiudad")==0){ v.kmGalonCiudad=(float)atof(val); asignados++; }
            else if(strcmp(key,"CostoGomas")==0){ v.costoGomas=(float)atof(val); asignados++; }
            else if(strcmp(key,"KmVidaGomas")==0){ v.kmVidaGomas=(float)atof(val); asignados++; }
            else if(strcmp(key,"CostoSeguro")==0){ v.costoSeguro=(float)atof(val); asignados++; }
            else if(strcmp(key,"CostoMantenimiento")==0){ v.costoMantenimiento=(float)atof(val); asignados++; }
            else if(strcmp(key,"KmEntreMantenimientos")==0){ v.kmEntreMantenimientos=(float)atof(val); asignados++; }
            else if(strcmp(key,"CostoVehiculo")==0){ v.costoVehiculo=(float)atof(val); asignados++; }
            else if(strcmp(key,"VidaUtilAños")==0){ v.vidaUtilAnios=(float)atof(val); asignados++; }
            else if(strcmp(key,"KmAnuales")==0){ v.kmAnuales=(float)atof(val); asignados++; }
        }
        token = strtok(NULL, ",");
    }
    if(asignados>=14){ *out = v; return 1; }
    return 0;
}

static int parseLineaCSV(const char *line, Vehiculo *out){
    Vehiculo v; memset(&v, 0, sizeof(v));
    char buf[1024]; strncpy(buf, line, sizeof(buf)-1); buf[sizeof(buf)-1]='\0';

    char *p = buf;
    char *fields[14]; int n=0;
    for(char *tok = strtok(p, ","); tok && n<14; tok=strtok(NULL, ",")) fields[n++]=tok;
    if(n!=14) return 0;

    strncpy(v.placa, fields[0], sizeof(v.placa)-1);
    strncpy(v.marca, fields[1], sizeof(v.marca)-1);
    strncpy(v.modelo, fields[2], sizeof(v.modelo)-1);
    strncpy(v.tipoCombustible, fields[3], sizeof(v.tipoCombustible)-1); toUpperInPlace(v.tipoCombustible);
    v.kmGalonCarretera = (float)atof(fields[4]);
    v.kmGalonCiudad    = (float)atof(fields[5]);
    v.costoGomas       = (float)atof(fields[6]);
    v.kmVidaGomas      = (float)atof(fields[7]);
    v.costoSeguro      = (float)atof(fields[8]);
    v.costoMantenimiento = (float)atof(fields[9]);
    v.kmEntreMantenimientos = (float)atof(fields[10]);
    v.costoVehiculo    = (float)atof(fields[11]);
    v.vidaUtilAnios    = (float)atof(fields[12]);
    v.kmAnuales        = (float)atof(fields[13]);

    *out = v;
    return 1;
}

static void cargarVehiculosTXT(void){
    FILE *f = fopen(ARCHIVO_TXT, "r");
    if(!f) return;
    char line[1024];
    totalVehiculos = 0;
    while(fgets(line, sizeof(line), f)){
        trim(line);
        if(line[0]=='\0' || line[0]=='#') continue;
        Vehiculo v;
        if(parseLineaEtiquetas(line, &v) || parseLineaCSV(line, &v)){
            if(totalVehiculos<MAX_VEH) vehiculos[totalVehiculos++]=v;
        }
    }
    fclose(f);
}

// ---------- crear/listar/calcular ----------
static void crearVehiculo(void){
    if(totalVehiculos>=MAX_VEH){ printf("Limite de vehiculos alcanzado.\n"); return; }
    Vehiculo v; memset(&v,0,sizeof(v));

    printf("\nCreando nuevo vehiculo...\n");
    printf("Placa: "); fgets(v.placa,sizeof(v.placa),stdin); v.placa[strcspn(v.placa,"\n")]=0;
    printf("Marca: "); fgets(v.marca,sizeof(v.marca),stdin); v.marca[strcspn(v.marca,"\n")]=0;
    printf("Modelo: "); fgets(v.modelo,sizeof(v.modelo),stdin); v.modelo[strcspn(v.modelo,"\n")]=0;
    printf("Tipo Combustible (Gasolina/Gasoil): "); fgets(v.tipoCombustible,sizeof(v.tipoCombustible),stdin); v.tipoCombustible[strcspn(v.tipoCombustible,"\n")]=0; toUpperInPlace(v.tipoCombustible);

    printf("Km por galon en carretera: "); scanf("%f",&v.kmGalonCarretera); limpiarBuffer();
    printf("Km por galon en ciudad: ");    scanf("%f",&v.kmGalonCiudad);    limpiarBuffer();
    printf("Costo gomas (juego): ");       scanf("%f",&v.costoGomas);       limpiarBuffer();
    printf("Km vida util gomas: ");        scanf("%f",&v.kmVidaGomas);      limpiarBuffer();
    printf("Costo seguro anual: ");        scanf("%f",&v.costoSeguro);      limpiarBuffer();
    printf("Costo mantenimiento (por servicio): "); scanf("%f",&v.costoMantenimiento); limpiarBuffer();
    printf("Km entre mantenimientos: ");   scanf("%f",&v.kmEntreMantenimientos); limpiarBuffer();
    printf("Costo vehiculo: ");            scanf("%f",&v.costoVehiculo);    limpiarBuffer();
    printf("Vida util (años): ");          scanf("%f",&v.vidaUtilAnios);    limpiarBuffer();
    printf("Km promedio anuales: ");       scanf("%f",&v.kmAnuales);        limpiarBuffer();

    vehiculos[totalVehiculos++] = v;
    guardarVehiculosTXT();
    printf("Vehiculo agregado y guardado correctamente.\n");
}

static void listarVehiculos(void){
    if(totalVehiculos==0){ printf("No hay vehiculos registrados.\n"); return; }
    printf("\nLista de vehiculos:\n");
    for(int i=0;i<totalVehiculos;i++){
        printf("%d) %s - %s %s\n", i+1, vehiculos[i].placa, vehiculos[i].marca, vehiculos[i].modelo);
    }
}

static void calcularCostoViaje(void){
    if(totalVehiculos==0){ printf("No hay vehiculos registrados.\n"); return; }
    listarVehiculos();
    int sel; printf("Seleccione vehiculo: "); scanf("%d",&sel); limpiarBuffer();
    if(sel<1 || sel>totalVehiculos){ printf("Seleccion invalida.\n"); return; }
    Vehiculo v = vehiculos[sel-1];

    float kmViaje, pctCiudad;
    printf("Kilometros del viaje: "); scanf("%f",&kmViaje); limpiarBuffer();
    printf("Porcentaje de km en ciudad (0-100): "); scanf("%f",&pctCiudad); limpiarBuffer();
    if(pctCiudad<0) pctCiudad=0; if(pctCiudad>100) pctCiudad=100;

    float kmCiudad = kmViaje*(pctCiudad/100.0f);
    float kmCarretera = kmViaje - kmCiudad;

    float precioGalon = (strcmp(v.tipoCombustible,"GASOLINA")==0) ? 300.0f : 250.0f;
    float costoCombustible = (kmCarretera/v.kmGalonCarretera + kmCiudad/v.kmGalonCiudad)*precioGalon;
    float costoGomas = (kmViaje/v.kmVidaGomas)*v.costoGomas;
    float costoSeguro = (v.costoSeguro/v.kmAnuales)*kmViaje;
    float costoMantenimiento = (kmViaje/v.kmEntreMantenimientos)*v.costoMantenimiento;
    float depreciacionAnual = v.costoVehiculo / v.vidaUtilAnios;
    float costoVehiculoDep = depreciacionAnual * (kmViaje / v.kmAnuales);

    float costoTotal = costoCombustible + costoGomas + costoSeguro + costoMantenimiento + costoVehiculoDep;
    float costoPorKm = costoTotal / kmViaje;

    printf("\n--- RESULTADO DESGLOSADO ---\n");
    printf("Combustible:        %.2f\n", costoCombustible);
    printf("Gomas:              %.2f\n", costoGomas);
    printf("Seguro:             %.2f\n", costoSeguro);
    printf("Mantenimiento:      %.2f\n", costoMantenimiento);
    printf("Depreciacion:       %.2f\n", costoVehiculoDep);
    printf("TOTAL:              %.2f\n", costoTotal);
    printf("Costo por km:       %.2f\n", costoPorKm);
}

int main(void){
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    cargarVehiculosTXT();

    int opcion;
    do{
        printf("\n--- MENU ---\n");
        printf("1. Crear vehiculo\n");
        printf("2. Listar vehiculos\n");
        printf("3. Calcular costo viaje\n");
        printf("0. Salir\n");
        printf("Seleccione opcion: ");
        if(scanf("%d",&opcion)!=1){ limpiarBuffer(); opcion=-1; }
        limpiarBuffer();

        switch(opcion){
            case 1: crearVehiculo(); break;
            case 2: listarVehiculos(); break;
            case 3: calcularCostoViaje(); break;
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opcion invalida.\n");
        }
    }while(opcion!=0);
    return 0;
}
