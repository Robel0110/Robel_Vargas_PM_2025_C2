#include <stdio.h>

int main() {
    int N;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &N);

    if(N <= 0) {
        printf("El numero debe ser positivo.\n");
        return 1;
    }

    for(int fila = 1; fila <= N; fila++) {
        // Parte creciente
        for(int num = 1; num <= fila; num++) {
            printf("%d ", num);
        }
        // Parte decreciente
        for(int num = fila-1; num >= 1; num--) {
            printf("%d ", num);
        }
        printf("\n");
    }

    return 0;
}
