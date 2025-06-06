#include <stdio.h>

/* Pares e impares.
El programa, al recibir como datos N números enteros, obtiene la suma de los
números pares y calcula el promedio de los impares.
I, N, NUM, SPA, SIM, CIM: variables de tipo entero.
*/

void main(void)
{
    int I, N, NUM, SPA = 0, SIM = 0, CIM = 0;

    printf("Ingrese el número de datos que se van a procesar:\t");
    scanf("%d", &N);

    if (N > 0)
    {
        for (I = 1; I <= N; I++)
        {
            printf("\nIngrese el número %d: ", I);
            scanf("%d", &NUM);

            if (NUM % 2 == 0)  // es par
                SPA += NUM;
            else                // es impar
            {
                SIM += NUM;
                CIM++;
            }
        }

        printf("\nLa suma de los números pares es: %d", SPA);
        if (CIM != 0)
            printf("\nEl promedio de los números impares es: %5.2f\n", (float)SIM / CIM);
        else
            printf("\nNo se ingresaron números impares\n");
    }
    else
        printf("\nEl valor de N es incorrecto\n");
}
