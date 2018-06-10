#include <stdio.h>
#include <stdlib.h>

int main()
{
    int radio;
    float circunferencia;
    float area;

    printf("Ingrese el radio de su circulo.\n");
    scanf("%d",&radio);

    circunferencia = (float) radio * 2 * 3.14;
    area = (float) radio * radio * 3.14;

    printf("La circunferencia de su circulo es %.2f y el area del mismo es %.2f",circunferencia,area);
    return 0;
}
