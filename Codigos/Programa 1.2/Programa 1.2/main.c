#include <stdio.h>
#include <stdlib.h>

/*Inviertir datos?
El programa, al recibir como dato un conjunto de datos de entrada, invierte el
orden de los mismos cuando los imprime.

A, B, C y: Son variables de tipo entero.*/

void main(void)
{
    int A, B, C, D;
    printf("Ingrese Cuatro Datos de Tipo Entero: ");
    scanf("%d %d %d %d", &A, &B, &C, &D);
    printf("\n %d %d %d %d ", D, C, B, A);
}
