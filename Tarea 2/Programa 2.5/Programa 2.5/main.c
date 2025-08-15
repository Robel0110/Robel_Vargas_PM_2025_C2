#include <stdio.h>
#include <math.h>

/*Funcion matematica.
El programa obtiene el resultado de una funcion.

OP y T: variables de tipo entero.
RES: variable de tipo real.*/

void main(void)
{
    int OP, T;
    float RES;
    printf("Ingresar La Opcion Del Calculo Y El Valor Entero: ");
    scanf("%d %d", &OP, &T);
    switch(OP)
    {
        case 1:
            RES = T / 5;
            break;
        case 2:
            RES = pow(T, T);
            break;
        case 3:
        case 4:
            RES = 6 * T / 5;
            break;
        default:
            RES = 1;
            break;
    }
    printf("\nResultado: %7.2", RES);
}
