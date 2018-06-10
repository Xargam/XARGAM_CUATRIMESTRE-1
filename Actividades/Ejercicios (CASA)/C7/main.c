#include <stdio.h>
#include <stdlib.h>
#include "xmath.h"
#include "xget.h"
#include "xvector.h"
#include <string.h>
#include <conio.h>



#define CHARS 51
#define CANT 10

/*
7-	Cargar una matriz con 10 apellidos. Por medio de un menú de opciones realizar las siguientes tareas:
a-	Mostrar todos los apellidos en mayúsculas
b-	Mostrar todos los apellidos en minúsculas
c-	Salir.

*/

int main()
{
    char apellido[CANT][CHARS] = {"Gonzales","Landaverde","Dominguez","Ortiz","Esquivich","Navarrette","Varde","Otano","De la Vega","Friz"}, seleccion = 'n';
    while(seleccion != 's')
    {
        system("cls");
        indexGenerator("ESCUELA 22",3,"a-Mostrar todos los apellidos en mayusculas","b-Mostrar todos los apellidos en minusculas","c-Salir.");
        seleccion = getChar("SELECCIONAR OPCION: ");
        switch(seleccion)
        {
        case 'a':
            for(int i = 0; i < CANT; i++)
            {
                strupr(apellido[i]);
                printf("%s\n",apellido[i]);
            }
            system("pause");
            break;
        case 'b':
            for(int i = 0; i < CANT; i++)
            {
                strlwr(apellido[i]);
                printf("%s\n",apellido[i]);
            }
            system("pause");
            break;
        case 'c':
            printf("Seguro? s/n");
            seleccion = getch();
            break;

        default:
            printf("ERROR: Opcion inexistente.");
            break;
        }
    }
    return 0;
}
