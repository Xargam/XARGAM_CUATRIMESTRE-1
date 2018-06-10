#include <stdio.h>
#include <stdlib.h>

int main()
{
    #define CANTIDAD 5

    int vector[CANTIDAD],i;

    for(i = 0; i < CANTIDAD; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&vector[i]);
    }

    for(i = 0; i < CANTIDAD; i++)
    {
        printf("Elemento de la posicion %d: %d\n",i,vector[i]);

    }
    return 0;


}
