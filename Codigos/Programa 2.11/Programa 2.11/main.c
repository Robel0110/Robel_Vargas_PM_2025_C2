#include <stdio.h>
#include <stdlib.h>
 /* Billete de ferrocarril.

 El programa calcula el costo de un billete de ferrocarril teniendo en
 cuenta la distancia entre las dos ciudades y el tiempo de permanencia
 del pasajero.

 DIS y TIE: variables de tipo entero.
 BIL: variable de tipo real. */

void main(void)
{
    int DIS, TIE;
    float BIL;
    printf("Ingrese La Distancia Entre Ciudades Y El Tiempo De Estancia: ");
    scanf("%d %d", &DIS, &TIE);
    if ((DIS*2 > 500) && (TIE > 10))
        BIL = DIS * 2 * 0.19 * 0.8;
    else
        BIL = DIS * 2 * 0.19;
    printf("\n\nCosto Del Billete: %7.2", BIL);
}
