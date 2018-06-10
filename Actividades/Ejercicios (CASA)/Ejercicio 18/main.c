#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;

    printf("Ingrese un numero:\n");

    scanf("%d",&numero);

    if(numero > 0)
    {
        printf("El numero es positivo.");
    }
    else if(numero == 0)
    {
        printf("El numero es neutro.");
    }
    else
    {
        printf("El numero es negativo.");
    }


    return 0;
}
