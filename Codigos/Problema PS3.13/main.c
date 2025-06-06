#include <stdio.h>

int es_primo(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int N1, N2;
    scanf("%d %d", &N1, &N2);

    if (N1 > N2) {
        int temp = N1;
        N1 = N2;
        N2 = temp;
    }

    for (int i = N1; i <= N2 - 2; i++) {
        if (es_primo(i) && es_primo(i + 2)) {
            printf("(%d, %d)\n", i, i + 2);
        }
    }

    return 0;
}
