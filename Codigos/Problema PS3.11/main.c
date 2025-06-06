#include <stdio.h>

int main() {
    int N;
    printf("Ingrese el n�mero de a�os: ");
    scanf("%d", &N);

    float VIN[N][4];               // Matriz de producci�n [a�o][tipo de vino]
    float total_tipo[4] = {0};     // Total por tipo de vino
    float total_anual[N];          // Total por a�o

    // Inicializar total_anual
    for (int i = 0; i < N; i++) {
        total_anual[i] = 0;
    }

    // Entrada de datos y acumulaci�n
    for (int i = 0; i < N; i++) {
        printf("A�o %d:\n", i + 1);
        for (int j = 0; j < 4; j++) {
            printf("  Litros del tipo de vino %d: ", j + 1);
            scanf("%f", &VIN[i][j]);

            total_tipo[j] += VIN[i][j];     // Acumular por tipo
            total_anual[i] += VIN[i][j];    // Acumular por a�o
        }
    }

    // Mostrar total por tipo
    printf("\nTotal producido por tipo de vino:\n");
    for (int j = 0; j < 4; j++) {
        printf("Tipo %d: %.2f litros\n", j + 1, total_tipo[j]);
    }

    // Mostrar total por a�o
    printf("\nTotal de producci�n por a�o:\n");
    for (int i = 0; i < N; i++) {
        printf("A�o %d: %.2f litros\n", i + 1, total_anual[i]);
    }

    return 0;
}
