#include <stdio.h>
#include <stdlib.h>
#include "xlook.h"
#include "xget.h"

typedef struct
{
    char nombre[50];
    int edad ;
    float sueldo ;
} ePersonas ;

int main()
{
    ePersonas personas[10] ;

    int seleccion ;
    int desplazamientos = 0;

    xlkIndexGenerator("Encabezado",4,"1-Alta","2-Baja","3-modificacion","4-Salir");
    seleccion = getInt("ingrese opcion:");
    switch(seleccion)
    {
    case 1:

        printf("alta persona:\n\n");
        getRangedStr(2,49,"Ingrese nombre de la persona","ERROR, reingrese: ",personas[desplazamientos].nombre );
        personas[desplazamientos].edad = getRangedInt(0,150,"Ingrese edad: ","Error: edad invalida.");
        personas[desplazamientos].sueldo = getConditionedFloat(1,1,"Ingrese sueldo: ","Error: sueldo invalido.");
        desplazamientos++;
        break;
    case 2 :
    break;
    case 3:
        break;
    case 4:
        break;
    }

    return 0;
}
