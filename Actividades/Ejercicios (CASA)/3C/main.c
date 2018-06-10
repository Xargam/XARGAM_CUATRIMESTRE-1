#include <stdio.h>
#include <stdlib.h>
#include "xget.h"
#include <string.h>
#include <ctype.h>

#define CANT 3
#define CHARS 50

/*3-	Cargar 10 nombres en una matriz convenientemente dimensionada.
Una vez que se terminó de cargar la matriz se pide pasar todas las iniciales a mayúsculas
y el resto de las letras a minúsculas. Mostrar la matriz definitiva. */

int main()
{
    char matriz[CANT][CHARS];
    char primeraLetra;
    for(int i = 0; i< CANT; i++)
    {
        printf("Ingrese nombre %d: ",i+1);
        getRangedSimStr(matriz[i],"","Nombre invalido, reingrese: ",1,49);
        strlwr(matriz[i]);
        primeraLetra = matriz[i][0];
        primeraLetra = toupper(primeraLetra);
        matriz[i][0] = primeraLetra;

    }
    for(int i = 0; i < CANT; i++)
    {
        printf("%s\n",matriz[i]);
    }

    return 0;
}
