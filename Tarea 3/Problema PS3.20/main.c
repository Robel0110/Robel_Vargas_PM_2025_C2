#include <stdio.h>
#include <math.h>

int main() {
    int T, P, R;
    double expresion;

    for(T = 1; 7*pow(T,4) < 5850; T++) {
        for(P = 1; 6*pow(P,3) < 5850 - 7*pow(T,4); P++) {
            for(R = 1; 12*pow(R,5) < 5850 - 7*pow(T,4) + 6*pow(P,3); R++) {
                expresion = 7*pow(T,4) - 6*pow(P,3) + 12*pow(R,5);
                if(expresion < 5850) {
                    printf("T=%d, P=%d, R=%d (Valor expresión: %.2f)\n", T, P, R, expresion);
                }
            }
        }
    }

    return 0;
}
