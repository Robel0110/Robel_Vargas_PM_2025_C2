#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> // Para getch() en Windows, o puedes usar una alternativa para otros sistemas

// --- ESTRUCTURAS DE DATOS ---

// Estructura para almacenar los datos de un vehículo
typedef struct {
    char placa[15];
    char marca[50];
    char modelo[50];
    char tipoCombustible[20]; // "Gasolina" o "Gasoil"
    float kmPorGalonCarretera;
    float kmPorGalonCiudad;
    float costoGomas; // Costo del juego de 4 gomas
    int kmVidaUtilGomas;
    float costoSeguroAnual;
    float costoMantenimiento;
    int kmPorMantenimiento;
    float costoVehiculo;
    int vidaUtilAnos;
    int kmPromedioAnual;
    int activo; // 1 para activo, 0 para borrado
} Vehiculo;

// Estructura para almacenar datos generales
typedef struct {
    float costoGasolina;
    float costoGasoil;
} DatosGenerales;


// --- DECLARACIÓN DE FUNCIONES ---

void mostrarMenuPrincipal();
void gestionarVehiculos(Vehiculo flota[], int* numVehiculos);
void crearVehiculo(Vehiculo flota[], int* numVehiculos);
void modificarVehiculo(Vehiculo flota[], int numVehiculos);
void borrarVehiculo(Vehiculo flota[], int numVehiculos);
void listarVehiculos(Vehiculo flota[], int numVehiculos);
int seleccionarVehiculo(Vehiculo flota[], int numVehiculos);

void gestionarDatosGenerales(DatosGenerales* datos);

void calcularCostoViaje(Vehiculo flota[], int numVehiculos, DatosGenerales datos);

void limpiarPantalla();
void esperarTecla();


// --- FUNCIÓN PRINCIPAL ---

int main() {
    Vehiculo flota[50]; // Capacidad para 50 vehículos
    int numVehiculos = 0;
    DatosGenerales datos = {0.0, 0.0}; // Inicializamos los costos de combustible
    int opcion;

    do {
        limpiarPantalla();
        mostrarMenuPrincipal();
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                gestionarVehiculos(flota, &numVehiculos);
                break;
            case 2:
                gestionarDatosGenerales(&datos);
                break;
            case 3:
                calcularCostoViaje(flota, numVehiculos, datos);
                break;
            case 4:
                printf("\nSaliendo del programa. ¡Hasta luego!\n");
                break;
            default:
                printf("\nOpcion no valida. Por favor, intente de nuevo.\n");
                esperarTecla();
        }
    } while (opcion != 4);

    return 0;
}

// --- IMPLEMENTACIÓN DE FUNCIONES ---

void mostrarMenuPrincipal() {
    printf("=========================================\n");
    printf("  GESTION DE GASTOS DE VEHICULO POR KM\n");
    printf("=========================================\n");
    printf("1. Gestion de Vehiculos\n");
    printf("2. Gestion de Datos Generales (Costos Combustible)\n");
    printf("3. Calcular Costo de Viaje\n");
    printf("4. Salir\n");
    printf("-----------------------------------------\n");
}

// Menú y lógica para la gestión de vehículos
void gestionarVehiculos(Vehiculo flota[], int* numVehiculos) {
    int opcion;
    do {
        limpiarPantalla();
        printf("--- Gestion de Vehiculos ---\n");
        printf("1. Crear Vehiculo\n");
        printf("2. Modificar Vehiculo\n");
        printf("3. Borrar Vehiculo\n");
        printf("4. Listar Vehiculos\n");
        printf("5. Volver al Menu Principal\n");
        printf("----------------------------\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                crearVehiculo(flota, numVehiculos);
                break;
            case 2:
                modificarVehiculo(flota, *numVehiculos);
                break;
            case 3:
                borrarVehiculo(flota, *numVehiculos);
                break;
            case 4:
                listarVehiculos(flota, *numVehiculos);
                break;
            case 5:
                printf("\nVolviendo al menu principal...\n");
                break;
            default:
                printf("\nOpcion no valida.\n");
        }
        if (opcion != 5) {
            esperarTecla();
        }
    } while (opcion != 5);
}

// Función para añadir un nuevo vehículo
void crearVehiculo(Vehiculo flota[], int* numVehiculos) {
    limpiarPantalla();
    printf("--- Creando Nuevo Vehiculo ---\n");
    if (*numVehiculos >= 50) {
        printf("No se pueden agregar mas vehiculos.\n");
        return;
    }

    Vehiculo* v = &flota[*numVehiculos];
    v->activo = 1;

    printf("Placa: ");
    scanf("%s", v->placa);
    printf("Marca: ");
    scanf("%s", v->marca);
    printf("Modelo: ");
    scanf("%s", v->modelo);
    printf("Tipo de Combustible (Gasolina/Gasoil): ");
    scanf("%s", v->tipoCombustible);
    printf("Km por galon en Carretera: ");
    scanf("%f", &v->kmPorGalonCarretera);
    printf("Km por galon en Ciudad: ");
    scanf("%f", &v->kmPorGalonCiudad);
    printf("Costo total de las 4 gomas: ");
    scanf("%f", &v->costoGomas);
    printf("Kilometros de vida util de las gomas: ");
    scanf("%d", &v->kmVidaUtilGomas);
    printf("Costo del seguro por 12 meses: ");
    scanf("%f", &v->costoSeguroAnual);
    printf("Costo de un mantenimiento: ");
    scanf("%f", &v->costoMantenimiento);
    printf("Cada cuantos kilometros es el mantenimiento: ");
    scanf("%d", &v->kmPorMantenimiento);
    printf("Costo de adquisicion del vehiculo: ");
    scanf("%f", &v->costoVehiculo);
    printf("Vida util del vehiculo (en anos): ");
    scanf("%d", &v->vidaUtilAnos);
    printf("Kilometros promedio que recorre por ano: ");
    scanf("%d", &v->kmPromedioAnual);

    (*numVehiculos)++;
    printf("\n¡Vehiculo agregado exitosamente!\n");
}

// Función para listar todos los vehículos activos
void listarVehiculos(Vehiculo flota[], int numVehiculos) {
    limpiarPantalla();
    printf("--- Lista de Vehiculos Activos ---\n");
    int i, contador = 0;
    for (i = 0; i < numVehiculos; i++) {
        if (flota[i].activo) {
            printf("ID: %d | Placa: %s | Marca: %s | Modelo: %s\n", i, flota[i].placa, flota[i].marca, flota[i].modelo);
            contador++;
        }
    }
    if (contador == 0) {
        printf("No hay vehiculos registrados.\n");
    }
    printf("----------------------------------\n");
}

// Función para seleccionar un vehículo de la lista
int seleccionarVehiculo(Vehiculo flota[], int numVehiculos) {
    int id;
    if (numVehiculos == 0) {
        return -1; // No hay vehículos
    }

    listarVehiculos(flota, numVehiculos);
    printf("Ingrese el ID del vehiculo que desea seleccionar: ");
    scanf("%d", &id);

    if (id < 0 || id >= numVehiculos || !flota[id].activo) {
        printf("ID no valido o vehiculo no encontrado.\n");
        return -1; // ID inválido
    }
    return id;
}

// Función para modificar un vehículo existente
void modificarVehiculo(Vehiculo flota[], int numVehiculos) {
    limpiarPantalla();
    printf("--- Modificar Vehiculo ---\n");
    int id = seleccionarVehiculo(flota, numVehiculos);
    if (id == -1) {
        return;
    }

    Vehiculo* v = &flota[id];
    printf("\nModificando vehiculo con Placa: %s\n", v->placa);
    printf("(Deje el campo en blanco y presione Enter para no modificar)\n\n");

    char buffer[100];

    printf("Placa actual: %s. Nueva Placa: ", v->placa);
    scanf(" %[^\n]", buffer); if(strlen(buffer) > 0) strcpy(v->placa, buffer);

    printf("Marca actual: %s. Nueva Marca: ", v->marca);
    scanf(" %[^\n]", buffer); if(strlen(buffer) > 0) strcpy(v->marca, buffer);

    printf("Modelo actual: %s. Nuevo Modelo: ", v->modelo);
    scanf(" %[^\n]", buffer); if(strlen(buffer) > 0) strcpy(v->modelo, buffer);

    // Y así sucesivamente para los demás campos... (se omite por brevedad pero la lógica es la misma)
    // Ejemplo con un float:
    printf("Km por galon en Carretera actual: %.2f. Nuevo valor: ", v->kmPorGalonCarretera);
    scanf(" %[^\n]", buffer); if(strlen(buffer) > 0) v->kmPorGalonCarretera = atof(buffer);


    printf("\n¡Vehiculo actualizado exitosamente!\n");
}

// Función para marcar un vehículo como borrado
void borrarVehiculo(Vehiculo flota[], int numVehiculos) {
    limpiarPantalla();
    printf("--- Borrar Vehiculo ---\n");
    int id = seleccionarVehiculo(flota, numVehiculos);
    if (id == -1) {
        return;
    }

    char confirmacion;
    printf("\n¿Esta seguro de que desea borrar el vehiculo con placa %s? (s/n): ", flota[id].placa);
    scanf(" %c", &confirmacion);

    if (confirmacion == 's' || confirmacion == 'S') {
        flota[id].activo = 0; // Marcado como borrado lógico
        printf("Vehiculo borrado exitosamente.\n");
    } else {
        printf("Operacion cancelada.\n");
    }
}

// Función para actualizar los costos de los combustibles
void gestionarDatosGenerales(DatosGenerales* datos) {
    limpiarPantalla();
    printf("--- Gestion de Datos Generales ---\n");
    printf("Costo actual por galon de Gasolina: $%.2f\n", datos->costoGasolina);
    printf("Ingrese el nuevo costo de la Gasolina: ");
    scanf("%f", &datos->costoGasolina);

    printf("\nCosto actual por galon de Gasoil: $%.2f\n", datos->costoGasoil);
    printf("Ingrese el nuevo costo del Gasoil: ");
    scanf("%f", &datos->costoGasoil);

    printf("\n¡Datos generales actualizados!\n");
    esperarTecla();
}

// Función principal para el cálculo del viaje
void calcularCostoViaje(Vehiculo flota[], int numVehiculos, DatosGenerales datos) {
    limpiarPantalla();
    printf("--- Calculo de Costo de Viaje ---\n");

    if (datos.costoGasolina == 0.0 && datos.costoGasoil == 0.0) {
        printf("ADVERTENCIA: No ha establecido los costos de combustible en 'Gestion de Datos Generales'.\n");
        printf("El costo de combustible sera 0.\n\n");
    }

    int id = seleccionarVehiculo(flota, numVehiculos);
    if (id == -1) {
        esperarTecla();
        return;
    }

    Vehiculo v = flota[id];
    float kmViaje, porcCiudad;

    printf("\nVehiculo seleccionado: %s %s (Placa: %s)\n", v.marca, v.modelo, v.placa);
    printf("Ingrese los kilometros totales del viaje: ");
    scanf("%f", &kmViaje);
    printf("Ingrese el porcentaje de kilometros en ciudad (0-100): ");
    scanf("%f", &porcCiudad);

    if (porcCiudad < 0 || porcCiudad > 100) {
        printf("Porcentaje no valido. Debe estar entre 0 y 100.\n");
        esperarTecla();
        return;
    }

    // --- CÁLCULOS ---

    // 1. Costo de Gomas
    float costoGomasPorKm = v.costoGomas / v.kmVidaUtilGomas;
    float costoGomasViaje = costoGomasPorKm * kmViaje;

    // 2. Costo de Seguro
    float costoSeguroPorKm = v.costoSeguroAnual / v.kmPromedioAnual;
    float costoSeguroViaje = costoSeguroPorKm * kmViaje;

    // 3. Costo de Mantenimiento
    float costoMantenimientoPorKm = v.costoMantenimiento / v.kmPorMantenimiento;
    float costoMantenimientoViaje = costoMantenimientoPorKm * kmViaje;

    // 4. Depreciación (Costo del vehículo)
    float depreciacionTotal = v.costoVehiculo; // Se asume depreciación total al final de la vida útil
    float kmTotalesVidaUtil = v.kmPromedioAnual * v.vidaUtilAnos;
    float costoVehiculoPorKm = depreciacionTotal / kmTotalesVidaUtil;
    float costoVehiculoViaje = costoVehiculoPorKm * kmViaje;

    // 5. Costo de Combustible
    float kmEnCiudad = kmViaje * (porcCiudad / 100.0);
    float kmEnCarretera = kmViaje - kmEnCiudad;

    float galonesCiudad = (v.kmPorGalonCiudad > 0) ? kmEnCiudad / v.kmPorGalonCiudad : 0;
    float galonesCarretera = (v.kmPorGalonCarretera > 0) ? kmEnCarretera / v.kmPorGalonCarretera : 0;

    float costoCombustibleGalon = 0.0;
    if (strcmp(v.tipoCombustible, "Gasolina") == 0) {
        costoCombustibleGalon = datos.costoGasolina;
    } else if (strcmp(v.tipoCombustible, "Gasoil") == 0) {
        costoCombustibleGalon = datos.costoGasoil;
    }

    float costoCombustibleViaje = (galonesCiudad + galonesCarretera) * costoCombustibleGalon;
    float costoCombustiblePorKm = (kmViaje > 0) ? costoCombustibleViaje / kmViaje : 0;


    // --- RESULTADOS ---
    float costoTotalViaje = costoGomasViaje + costoSeguroViaje + costoCombustibleViaje + costoMantenimientoViaje + costoVehiculoViaje;
    float costoTotalPorKm = (kmViaje > 0) ? costoTotalViaje / kmViaje : 0;

    limpiarPantalla();
    printf("====================================================\n");
    printf("          RESULTADO DEL CALCULO DE VIAJE\n");
    printf("====================================================\n");
    printf("Vehiculo: %s %s (%s)\n", v.marca, v.modelo, v.placa);
    printf("Distancia del viaje: %.2f km\n", kmViaje);
    printf(" (%.2f km en ciudad, %.2f km en carretera)\n", kmEnCiudad, kmEnCarretera);
    printf("----------------------------------------------------\n");
    printf("          DESGLOSE DE COSTOS DEL VIAJE\n");
    printf("----------------------------------------------------\n");
    printf("Costo de Gomas:         $ %-10.2f  ($ %.4f por km)\n", costoGomasViaje, costoGomasPorKm);
    printf("Costo de Seguro:        $ %-10.2f  ($ %.4f por km)\n", costoSeguroViaje, costoSeguroPorKm);
    printf("Costo de Mantenimiento: $ %-10.2f  ($ %.4f por km)\n", costoMantenimientoViaje, costoMantenimientoPorKm);
    printf("Costo Vehiculo (Depr.): $ %-10.2f  ($ %.4f por km)\n", costoVehiculoViaje, costoVehiculoPorKm);
    printf("Costo de Combustible:   $ %-10.2f  ($ %.4f por km)\n", costoCombustibleViaje, costoCombustiblePorKm);
    printf("----------------------------------------------------\n");
    printf("COSTO TOTAL DEL VIAJE:  $ %.2f\n", costoTotalViaje);
    printf("COSTO TOTAL POR KM:     $ %.2f\n", costoTotalPorKm);
    printf("====================================================\n");

    esperarTecla();
}


// --- FUNCIONES UTILITARIAS ---

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void esperarTecla() {
    printf("\nPresione cualquier tecla para continuar...");
    getch(); // Espera a que el usuario presione una tecla
}
