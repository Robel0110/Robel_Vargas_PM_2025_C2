#include <stdio.h>

int main() {
    int N, i, j;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &N);

    if(N <= 0) {
        printf("El numero debe ser positivo.\n");
        return 1;
    }

    // Parte creciente
    for(i = 1; i <= N; i++) {
        for(j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    // Parte decreciente
    for(i = N-1; i >= 1; i--) {
        for(j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}
