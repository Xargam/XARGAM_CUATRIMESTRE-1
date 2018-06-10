#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int i;
    int acumulador = 0;

    printf("Ingrese un numero y se sumaran sus antecedentes a partir del 0:\n");
    scanf("%d",&numero);

    for(i = 0; i < numero ; i++)
    {
        acumulador += i;
    }

    printf("La suma de todos los numeros que anteceden a %d es: %d.",numero, acumulador);


    return 0;
}
