#include <stdio.h>
#include <stdlib.h>
#include "xget.h"

#define CANT 50

/*
4-	En un comercio se carga el precio y la descripción de 50 artículos.
Hacer un programa que me permita ingresar los datos y luego mostrarlos
ordenados por precio.
*/

typedef struct
{
    float precio;
    char descripcion[51];

} Articulos;

int main()
{
    Articulos miComercio[CANT];
    for(int i = 0; i <CANT; i++)
    {
        miComercio[i].precio= getRangedFloat(0,65000,"Ingrese precio: ","Error, reingrese: ");
        getRangedSimStr(miComercio[i].descripcion,"Ingrese descripcion: ","Error, descripcion invalida: ",1,50);
    }
    for(int i = 0; i< CANT-1;i++)
    {
        for(int j=i+1;j<CANT;j++)
        {
            if(miComercio[j].precio < miComercio[i].precio )
            {
                Articulos aux;
                aux = miComercio[i];
                miComercio[i] = miComercio[j];
                miComercio[j] = aux;
            }
        }
    }
    printf("\n\nDescripcion:\tPrecio:\n");
    for(int i = 0; i < CANT;i++)
    {
        printf("%s\t\t$%.2f\n",miComercio[i].descripcion,miComercio[i].precio);
    }



    return 0;
}
