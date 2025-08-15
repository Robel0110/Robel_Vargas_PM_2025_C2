#include <stdio.h>

int main() {
    for(int fila = 1; fila <= 10; fila++) {
        int valor_central = fila + (fila - 1);  // Cálculo del valor central
        int num = fila;
        int direccion = 1;

        // Imprimir espacios iniciales para alineación (opcional)
        for(int espacio = 0; espacio < 10 - fila; espacio++) {
            printf(" ");
        }

        for(int contador = 1; contador <= 2*fila - 1; contador++) {
            printf("%d", num % 10);

            if(num == valor_central) {
                direccion = -1;
            }

            num += direccion;
        }
        printf("\n");
    }

    return 0;
}
