#include <stdio.h>

int main() {
    int NUM;
    scanf("%d", &NUM);

    for (int i = 2; i < NUM; i++) {
        int contador = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                contador++;
            }
        }
        if (contador == 2) {
            printf("%d\n", i);
        }
    }

    return 0;
}
