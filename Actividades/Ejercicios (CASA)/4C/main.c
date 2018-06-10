#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xget.h"
#include "xvector.h"

/*
4-	Cargar una matriz de caracteres con 30 nombres. Ordenar la matriz alfabéticamente y mostrarla en pantalla.
*/

#define CANT 30
#define CHARS 50

char matriz[CANT][CHARS];

int main()
{
    for(int i = 0 ; i < CANT; i++)
    {
        printf("Ingrese nombre %d\n",i+1);
        getRangedSimStr(matriz[i],"","Nombre invalido o muy largo, reingresar:",1,49);
    }


    for(int i = 0; i < CANT-1; i++)
    {
        for(int j= i+1; j < CANT; j++)
        {
            if(stricmp(matriz[j],matriz[i])< 0)
            {
                xvecSSwap(matriz[i],matriz[j]);
            }
        }
    }

    for(int i = 0; i < CANT; i++)
    {
        printf("\n%s",matriz[i]);
    }
    return 0;
}
