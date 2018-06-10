#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "xget.h"
#define CANT 3


/*
3-	Se ingresa nombre, sexo y edad de 100
personas. Se pide averiguar la cantidad de mujeres que tienen entre 20 y 30 años
y cuantos hombres son menores a 37 años.
*/

typedef struct
{
    char nombre[50];
    char sexo;
    int edad;

}Personas;

int main()
{
    Personas cienPersonas[CANT];
    int contadorMujeres20 = 0, contadorHombresMenos37 = 0;


    for(int i = 0; i < CANT;i++)
    {
        getRangedSimStr(cienPersonas[i].nombre,"Ingrese nombre: ","Nombre invalido o muy largo.\nReingrese: ",1,49);
        cienPersonas[i].sexo = getChar("Ingrese sexo(f o m): ");
        while(cienPersonas[i].sexo != 'f' && cienPersonas[i].sexo != 'm')
        {
            cienPersonas[i].sexo = getChar("Error, reingrese: ");
        }
        cienPersonas[i].edad = getRangedInt(0,150,"Ingrese edad: ","Error, reingresar: ");

    }
    for(int i = 0; i < CANT; i++)
    {
        if(cienPersonas[i].sexo == 'f' && cienPersonas[i].edad > 19 && cienPersonas[i].edad < 31)
        {
            contadorMujeres20++;
        }
        if(cienPersonas[i].sexo == 'm' && cienPersonas[i].edad < 37)
        {
            contadorHombresMenos37++;
        }
    }
    printf("Hay %d mujeres de entre 20 y 30 años. Hay %d hombres menores a 37 años.",contadorMujeres20,contadorHombresMenos37);
    return 0;
}


