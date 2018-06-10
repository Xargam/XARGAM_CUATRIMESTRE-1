#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "xget.h"
#include "xlook.h"
#include "xvalidate.h"
#include "xstring.h"
#include "xEmpleados.h"
#define TAM 10


int main()
{
    eEmpleados prods[TAM];
    eSectores provs[TAM];

    int seleccion;
    int exit = 0;

    inicializarEmpleados(prods,TAM);
    inicializarSectores(provs,TAM);
    harcodearSec(provs);
    harcodearEmp(prods);

    do
    {
        xlkIndexGenerator("Microsoft Menu principal.",3,"1- EMPLEADOS .","2- SECTORES .","3- SALIR .");
        seleccion = getInt("-  Seleccionar opcion: ");
        switch(seleccion)
        {
        case 1:
            mostrarMenuEmpleados( prods , TAM , provs , TAM );
            break;
        case 2:
            mostrarMenuSectores( prods , TAM , provs , TAM );
            break;
        case 3:
            exit = validateDualExit("\nEsta seguro de que desea salir? s/n : ","\nNo se reconoce su respuesta.\nReingrese: ",'s','n');
            break;
        default:
            printf("\nOpcion invalida.\n\n");
            system("pause");
            break;
        }
    }
    while(exit == 0);
    printf("\n");
    return 0;
}
