#include <stdio.h>
#include <stdlib.h>
/*En este projecto se escribe un programa que determine el rango de edad
de una persona

1- De 0 a�os (anios) a 1 a�o - Recien Nacido
2- De 1 a�os a 12 - Ni�o
3- De 12 a�os a 17 - Adolescente
4- De 18 a�os a 38 - Adulto
5- De 39 a�os a 75 - Adulto Mayor
6- De 76 a�os a 86 - Envejeciente
7- Mayor de 86 - Anciano*/

int main()
{
    int edad = 0;
    printf("\nEscriba La Edad Del Paciente: ");
    scanf("%i", &edad);
    if(edad >= 0 && edad < 130)
    {
        if(edad == 0)
        {
            printf("\nEs Un Infante Dosis Recomendada 0ml");
        }else if(edad < 12)
        {
            printf("\nEs Un Ninio Dosis Recomendada 0.5ml");
        }else if(edad >= 12 && edad < 17)
        {
            printf("\nEs Un Adolescente Dosis Recomendada 0.75ml");
        } else if (edad >= 18 && edad < 38)
        {
            printf("\nEs Un Adulto Dosis Recomendada 1ml");
        }else if (edad >=39 && edad < 75)
        {
            printf("\nEs Un Adulto Mayor");
        }
        {
            printf("\nEdad no valida");
        }
    }else
    {
    printf("\nValores no validos");
    }
}
