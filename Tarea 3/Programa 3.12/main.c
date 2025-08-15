#include <stdio.h>

/* Serie de Fibonacci.
El programa calcula e imprime los primeros 50 números de Fibonacci.
A, B, AUX, I: variables de tipo entero. */
void main(void)
{
    int A = 0, B = 1, AUX, I;

    printf("Los primeros 50 números de Fibonacci son:\n");
    printf("%d\t", A);

    for (I = 1; I < 50; I++)
    {
        printf("%d\t", B);
        AUX = A + B;
        A = B;
        B = AUX;
    }
}
