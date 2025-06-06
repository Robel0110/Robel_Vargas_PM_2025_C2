#include <stdio.h>
#include <math.h>

int main() {
    int x, signo = 1, contador = 0, n = 1;
    double suma = 0.0, termino, potencia, factorial = 1.0;

    // Leer el valor de x
    printf("Ingrese el valor de x (en radianes): ");
    scanf("%d", &x);

    // Inicializar variables
    potencia = x;

    do {
        // Calcular factorial de n (1!, 3!, 5!, etc.)
        factorial = 1.0;
        for (int i = 1; i <= n; i++) {
            factorial *= i;
        }

        // Calcular el término actual
        termino = signo * potencia / factorial;

        // Si el término es muy pequeño, salir del bucle
        if (fabs(termino) <= 0.001) {
            break;
        }

        // Acumular el término
        suma += termino;
        contador++;

        // Preparar para el siguiente término
        signo *= -1;  // Alternar el signo
        potencia *= x * x;  // x^1, x^3, x^5, etc.
        n += 2;  // Siguiente número impar
    } while (1);

    // Mostrar resultados
    printf("El valor aproximado de sen(%d) es: %.6f\n", x, suma);
    printf("Numero de terminos requeridos: %d\n", contador);

    return 0;
}
