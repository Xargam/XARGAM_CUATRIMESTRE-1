#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int acumulador = 0;

    for(int i = 0; i < 2;i++)
    {
        printf("Ingrese un numero:\n");
        scanf("%d",&numero);
        setbuf(stdin, NULL);
        acumulador += numero;
    }

    printf("La suma de los numeros que ingreso es: %d", acumulador);
    return 0;
}
