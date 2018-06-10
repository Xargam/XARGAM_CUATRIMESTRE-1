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
    eProductos prods[TAM];
    eProveedores provs[TAM];

    int seleccion;
    int exit = 0;

    inicializarEmpleados(prods,TAM);
    inicializarProveedores(provs,TAM);
    harcodearProv(provs);
    harcodearProd(prods);

    do
    {
        xlkIndexGenerator("Productos y proveedores SOFT V2 - Leonardo Manassali 1A ",5,"1-Productos.","2-Proveedores.","3-Informar.","4-Listar.","5-Salir.");
        seleccion = getInt("-  Seleccionar opcion: ");
        switch(seleccion)
        {
        case 1:
            mostrarMenuProductos( prods , TAM , provs , TAM );
            break;
        case 2:
            mostrarMenuProveedores( prods , TAM , provs , TAM );
            break;
        case 3:
            mostrarMenuInformar(prods ,TAM , provs , TAM );
        case 4:
            break;
        case 5:
            system("cls");
            exit = validateDualExit("Esta seguro de que desea salir? s/n : ","\nNo se reconoce su respuesta.\nReingrese: ",'s','n');
            break;
        default:
            printf("\nOpcion invalida.\n\n");
            system("pause");
            break;
        }
    }
    while(exit == 0);
    system("cls");
    return 0;
}
