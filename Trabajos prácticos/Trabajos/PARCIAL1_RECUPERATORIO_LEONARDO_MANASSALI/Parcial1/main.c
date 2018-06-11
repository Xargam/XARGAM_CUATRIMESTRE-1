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
    int idProducto = 0;
    int idProveedor = 0;
    int quit = 0;
    int selection;

    eProductos productos[100];
    eProveedores proveedores[100];

    inicializarProductos(productos, TAM);
    inicializarProveedores(proveedores, TAM);


    do
    {
        xlkIndexGenerator("ProductoSoftware V1.0.0 - RECUPERATORIO PARCIAL 1 - LEONARDO MANSSALI 1A",6,"1-Altas.","2-Bajas.","3-Modificaciones","4-Informar","5-Listar","6-Salir.");
        if( getRangedInt(&selection,1,6," -Seleccionar opcion: ","** Opcion invalida.") )
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
                mostrarMenuInformar(productos,TAM,proveedores,TAM);
                break;
            case 5:
                mostrarMenuListar(productos,TAM, proveedores, TAM);
                break;
            case 6:
                quit = validateDualExit("* Esta seguro que desea salir? s/n: ","** Respuesta invalida.",'s','n');
                break;
            }
        }
        system("pause");
    }
    while(!quit);

    return 0;
}
