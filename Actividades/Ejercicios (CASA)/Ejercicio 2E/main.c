#include <stdio.h>
#include <stdlib.h>
#include "xget.h"
#include <conio.h>

#define CANT 30
#define ESC 27

 /*2-	Se ingresa el apellido, la nota y el legajo de los 30 alumnos de un curso.
     Realizar un programa que me permita modificar los datos ingresados hasta que el usuario lo determine.
    Para ello se ingresa el legajo y la nota a modificar. Si no se encuentra el legajo se deberá mostrar un mensaje de error.
    */

typedef struct
{
    char apellido [50];
    float nota;
    int legajo;

}Alumno;

int main()
{
    int legajo, flag;
    char seleccion = 'a';
    Alumno curso[CANT];
    for(int i = 0; i < CANT; i++)
    {
        getRangedSimStr(curso[i].apellido,"Ingrese apellido del alumno: ","Apellido invalido o demasiado largo.\n Reingrese: ",1,49);
        curso[i].legajo = getInt("Ingrese legajo: ");
        curso[i].nota = getRangedFloat(0,10,"Ingrese nota: ","Nota invalida.\nReingrese: ");
    }
    printf("\n\nPresione ESC para salir u otra tecla para modificar los datos ingresados: ");
    seleccion = getch();
    while(seleccion != ESC)
    {
        flag = 0;
        legajo = getInt("\nPara modificar los datos ingrese legajo de alumno: ");
        for(int i = 0; i < CANT; i++)
        {
            if(legajo == curso[i].legajo)
            {
                printf("\nLa nota actual del alumno es %.2f: ",curso[i].nota);
                curso[i].nota = getRangedFloat(0,10,"Modificar: ","Nota invalida.\nReingresar: ");
                flag++;
                break;
            }
        }
        if(flag == 0)
        {
            printf("El legajo no se encontro.\n\n");

        }
        printf("Presione ESC para salir u otra tecla para continuar...");
        seleccion = getch();
    }

    return 0;
}
