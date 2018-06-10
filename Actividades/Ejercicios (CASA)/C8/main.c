#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xget.h"
#include "xvector.h"

#define CANT 5
#define CHARS 51
/*
8-	En una escuela se toman los apellidos y la nota de sus 100 alumnos.
Se pide realizar un programa que me permita ingresar los datos,
obtener el mejor promedio y mostrar en pantalla la lista ordenada
por nota decreciente de los alumnos de acuerdo con el siguiente formato
Nota		Apellido
##		Xxxxxxx

*/
int main()
{
    char apellidos[CANT][CHARS];
    float notas[CANT];

    for(int i = 0; i < CANT; i++)
    {
        getRangedSimStr(apellidos[i],"Ingrese apellido: ","Error, apellido demasiado largo o invalido.\nReingrese: ",1,50);
        notas[i] = getRangedInt(0,10,"Ingrese nota: ","Nota invalida: ");
    }
    for(int i = 0; i < CANT-1; i++)
    {
        for(int j= i+1;j<CANT;j++)
        {
            if(notas[j] > notas[i])
            {
                xvecFSwap(&notas[j],&notas[i]);
                xvecSSwap(apellidos[i],apellidos[j]);
            }
        }
    }
    system("cls");
    printf("Nota:\tApellido:\n");
    for(int i = 0; i < CANT; i++)
    {
        printf("%.2f\t%s\n",notas[i],apellidos[i]);
    }
    return 0;
}
