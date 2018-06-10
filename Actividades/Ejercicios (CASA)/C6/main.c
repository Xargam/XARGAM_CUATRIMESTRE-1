#include <stdio.h>
#include <stdlib.h>
#include "xget.h"

/*
6-	Se cargan en una matriz los apellidos de 15 alumnos.
Realizar un programa que permita ingresar por teclado una letra y
obtenga la cantidad de alumnos cuyo apellido comienza con dicha letra.
*/

#define CHARS 51
#define CANT 5

int main()
{
    char apellidos[CANT][CHARS], letra;
    int  contador = 0;
    for(int i = 0; i < CANT; i++)
    {
        getRangedSimStr(apellidos[i],"Ingrese apellido: ","Apellido invalido o muy largo, reingresar: ",1,50);
    }
    letra = getChar("Ingrese una letra: ");

    for(int i = 0; i < CANT; i++)
    {
        if(apellidos[i][0] == letra)
        {
            contador++;
        }
    }
    printf("Hay %d alumnos que comienzan con la letra que ingreso.",contador);


    return 0;
}
