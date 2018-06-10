#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int numero;
    int maximo;

    for(i = 1; i < 4; i++)
    {
        printf("Ingrese un numero:\n");
        scanf("%d",&numero);

        if(i == 1 || maximo < numero)
        {
            maximo = numero;
        }
    }

    printf("El numero maximo ingresado fue %d.\b",maximo);

    return 0;
}
