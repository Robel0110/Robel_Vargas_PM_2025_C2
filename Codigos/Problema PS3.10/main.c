#include <stdio.h>

int main() {
    // Precios de localidades
    float L1, L2, L3, L4, L5, L6;
    // Variables de la venta
    int CLA, CAN;
    float monto;
    // Boletos vendidos por localidad
    int BOLETOS1 = 0, BOLETOS2 = 0, BOLETOS3 = 0;
    int BOLETOS4 = 0, BOLETOS5 = 0, BOLETOS6 = 0;
    // Recaudación total
    float TOTAL = 0;

    // Lectura de precios
    printf("Ingrese el precio de la localidad 1: ");
    scanf("%f", &L1);
    printf("Ingrese el precio de la localidad 2: ");
    scanf("%f", &L2);
    printf("Ingrese el precio de la localidad 3: ");
    scanf("%f", &L3);
    printf("Ingrese el precio de la localidad 4: ");
    scanf("%f", &L4);
    printf("Ingrese el precio de la localidad 5: ");
    scanf("%f", &L5);
    printf("Ingrese el precio de la localidad 6: ");
    scanf("%f", &L6);

    // Lectura de ventas
    do {
        printf("\nIngrese el tipo de localidad (1-6, 0 para terminar): ");
        scanf("%d", &CLA);
        printf("Ingrese la cantidad de boletos (0 para terminar): ");
        scanf("%d", &CAN);

        if (CLA == 0 && CAN == 0) {
            break; // Salir del ciclo
        }

        // Calcular monto y actualizar boletos vendidos
        switch (CLA) {
            case 1:
                monto = L1 * CAN;
                BOLETOS1 += CAN;
                break;
            case 2:
                monto = L2 * CAN;
                BOLETOS2 += CAN;
                break;
            case 3:
                monto = L3 * CAN;
                BOLETOS3 += CAN;
                break;
            case 4:
                monto = L4 * CAN;
                BOLETOS4 += CAN;
                break;
            case 5:
                monto = L5 * CAN;
                BOLETOS5 += CAN;
                break;
            case 6:
                monto = L6 * CAN;
                BOLETOS6 += CAN;
                break;
            default:
                printf("Localidad inválida.\n");
                monto = 0;
                break;
        }

        // Acumular la recaudación
        TOTAL += monto;
        printf("Monto de la venta: $%.2f\n", monto);

    } while (1);

    // Mostrar resultados
    printf("\nBoletos vendidos por localidad:\n");
    printf("Localidad 1: %d\n", BOLETOS1);
    printf("Localidad 2: %d\n", BOLETOS2);
    printf("Localidad 3: %d\n", BOLETOS3);
    printf("Localidad 4: %d\n", BOLETOS4);
    printf("Localidad 5: %d\n", BOLETOS5);
    printf("Localidad 6: %d\n", BOLETOS6);

    printf("\nRecaudación total: $%.2f\n", TOTAL);

    return 0;
}
