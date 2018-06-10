#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int contador = 0;
    int acumulador = 0;
    float promedio;

    while(contador < 5)
    {
        printf("Ingrese un numero:\n");
        scanf("%d",&numero);
        acumulador += numero;
        contador++;
    }

    promedio = (float) acumulador / contador;
    printf("El promedio de los numeros que ingreso es: %.2f",promedio);

    return 0;
}
