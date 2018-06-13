#include <stdio.h>
#include <stdlib.h>

#include "xget.h"
#include "xlook.h"
#include "xstring.h"
#include "xvalidate.h"

#include "xProductos.h"
#include "xProveedores.h"
#include "xProductos-Proveedores.h"

#define TAM 100


int main()
{
    int idProducto = 10;
    int idProveedor = 4;
    int quit = 0;
    int selection;

    eProductos productos[100];
    eProveedores proveedores[100];

    inicializarProductos(productos, TAM);
    inicializarProveedores(proveedores, TAM);

   // harcodearProductos(productos);
 //   harcodearProveedores(proveedores);

    do
    {
        xlkIndexGenerator("ProduSoft V1.0.0 - RECUPERATORIO PARCIAL 1 - LEONARDO MANSSALI 1A",8,"1* Altas.","2* Bajas.","3* Modificaciones.","4* Mostrar productos.","5* Mostrar proveedores.","6* Informar.","7* Listar.","8* Salir.");
        if( getRangedInt(&selection,1,8," -Seleccionar opcion: ","\n** Opcion invalida.\n\n") )
        {
            switch(selection)
            {
            case 1:
                altaMenu(productos,TAM,&idProducto,proveedores,TAM,&idProveedor);
                break;
            case 2:
                bajaMenu(productos,TAM,proveedores,TAM);
                break;
            case 3:
                modificacionMenu(productos,TAM,proveedores,TAM);
                break;
            case 4:
                system("cls");
                if( !mostrarProductos(productos,TAM,proveedores,TAM) )
                {
                    system("cls");
                    printf("** No hay productos cargados en el sistena.\n\n");
                }
                system("pause");
                break;
            case 5:
                system("cls");
                if( !mostrarProveedores(proveedores, TAM) )
                {
                    system("cls");
                    printf("** No hay productos cargados en el sistena.\n\n");
                }
                system("pause");
                break;
            case 6:
                mostrarMenuInformar(productos,TAM,proveedores,TAM);
                break;
            case 7:
                mostrarMenuListar(productos,TAM, proveedores, TAM);
                break;
            case 8:
                system("cls");
                quit = validateDualExit("* Esta seguro que desea salir? s/n: ","** Respuesta invalida.",'s','n');
                printf("\n\n");
                break;
            }
        }
        else
        {
            system("pause");
        }
    }
    while(!quit);

    printf("Programa finalizado!\n");
    return 0;
}
