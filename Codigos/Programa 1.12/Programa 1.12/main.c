#include <stdio.h>
#include <math.h>
 /* Igualdad de expresiones.

 El programa, al recibir como datos T, P y N, comprueba la igualdad de
 una expresión determinada.

 T, P y N: variables de tipo entero. */

void main(void)
{
    int T, P, N;
    printf("Ingrese Los Valores De T, P y N: ");
    scanf("%d %d %d", &T, &P, &N);
    if (P != 0)
    {
        if (pow(T / P, N) == pow(T, N) / pow(P, N))
            printf("\nSe Comprueba La Igualdad");
        else
            printf("\nNo Se Comprueba La Igualdad");
    }
    else
        printf("\nP Tiene Que Ser Diferente De Cero");
}
