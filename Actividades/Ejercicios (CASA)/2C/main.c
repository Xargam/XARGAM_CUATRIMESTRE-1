#include <stdio.h>
#include <stdlib.h>
#include "xget.h"
#include "xvector.h"

#define CANT 4
#define CHARS 5

int main()
{
    int vec[CANT];
    char matriz[CANT][CHARS];

    for(int i = 0; i < CANT; i++)
    {
        printf("Ingrese el nombre de la persona %d: ",i+1);
        getRangedStr(matriz[i],"","Nombre invalido, reingresar: ",0,4);
        printf("Ingrese la edad de la persona %d: ",i+1);
        vec[i] = getRangedInt(0,150,"","Edad Invalida, Reingresar: ");
    }
    printf("\nNombre:\t\tEdad:\n");
    for(int i = 0; i < CANT; i++)
    {
        printf("%d-%s\t\t%d\n",i+1,matriz[i],vec[i]);
    }


    return 0;
}
