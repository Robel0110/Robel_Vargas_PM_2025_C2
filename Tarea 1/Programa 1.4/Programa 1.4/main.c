#include <stdio.h>
#include <stdlib.h>

/* La Superficie De un Triangulo.
Este programa al recibir como datos la base y la altura de un triangulo,
calcula la superfiecie de este.

BAS, ALT y SUP: estas variables son de tipo real*/

void main(void)
{
    float BAS, ALT, SUP;
    printf("Ingrese la base y la altura del triangulo que desee: ");
    scanf("%f %f", &BAS, &ALT);
    SUP = BAS * ALT / 2;
    printf("\nLa superficie de este triangulo es: %5.2f", SUP);
}
