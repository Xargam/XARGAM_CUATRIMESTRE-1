#include <stdio.h>
#include <stdlib.h>

float numeroUsuario();
float areaCirculo (float x);

int main()
{

    float area;
    float numero;

    numero = numeroUsuario();
    area = areaCirculo(numero);
    printf("El area del circulo es %.2f",area);


    return 0;
}

float numeroUsuario()
{
    float numero;
    printf("Ingrese el radio del circulo:\n");
    scanf("%f",&numero);
    return numero;
}

float areaCirculo(float x)
{
    float area;
    area = 3.14 * x * x;
    return area;

}
