#include <stdio.h>
#include <stdlib.h>

#include "xget.h"
#include "xlook.h"
#include "xstring.h"
#include "xvalidate.h"

#include "xProductos.h"
#include "xProveedores.h"
#include "xProductos-Proveedores.h"


#define LIBRE 0
#define OCUPADO 1

//Funciones basicas:



void inicializarProductos(eProductos prods[], int prodTam)
{
    int i;
    for( i = 0 ; i < prodTam ; i++ )
    {
        prods[i].estado = LIBRE;
        prods[i].codigoProveedor = LIBRE;
    }
}



//ABM DEPENDENCIAS:


int buscarProducto(eProductos prods[], int prodTam, int codigoProducto)
{
    int i;
    int matchIndex = -1 ;
    for(i = 0; i < prodTam ; i++)
    {
        if( prods[i].estado == OCUPADO && prods[i].codigoProduto == codigoProducto)
        {
            matchIndex = i;
            break;
        }
    }
    return matchIndex;
}


int buscarLibreProductos(eProductos prods[], int prodTam)
{
    int i;
    int freeIndex = -1 ;
    for(i = 0; i < prodTam ; i++)
    {
        if( prods[i].estado == LIBRE)
        {
            freeIndex = i;
            break;
        }
    }
    return freeIndex;
}



eProductos pedirProducto(void)
{
    eProductos nuevoProducto;
    while( !getRangedGraphicStr( nuevoProducto.descripcion, 1,50,"Ingrese descripcion del producto: ","\nSe produjo un error al validar la descripcion.\nDescripcion demasiado larga o invalida.",1) )
    {
        printf("\n\n");
    }
    xstrCapsSpaceFixer( nuevoProducto.descripcion);
    while( !getConditionedFloat( &nuevoProducto.importe, 0.0001,1,"\n\nIngrese el importe del producto: ","\nSe produjo un error al validar el importe.") );
    while( !getConditionedInt( &nuevoProducto.cantidad, 0,1,"\n\nIngrese el stock del producto: ","\nSe produjo un error al validar el stock.") );
    return nuevoProducto;
}



//ALTA, BAJA Y MODIFICACION:



int altaProducto(eProductos prods[], int prodTam, eProveedores provs[], int provTam, int* codigoProducto)
{
    int verify = 0;
    int index = buscarLibreProductos(prods, prodTam);

    if( index > -1)
    {
        int codigoProveedor;
        int valid = 0;

        prods[index] = pedirProducto();
        while( !valid )
        {
            system("cls");
            xlkCenterPrintf("LISTA DE PROVEEDORES",1);
            mostrarProveedores(provs,provTam);
            if( getConditionedInt(&codigoProveedor,0,1,"Ingrese el codigo del proveedor que desea asignarle al producto: ","\nEl codigo es incorrecto.") )
            {
                if( buscarProveedor(provs, provTam, codigoProveedor) > -1)
                {
                    prods[index].codigoProveedor = codigoProveedor;
                    valid++;
                }
            }
            printf("\n\n");
        }
        prods[index].codigoProduto = (*codigoProducto += 1) ;
        prods[index].estado = OCUPADO;
        verify = 1;
    }
    return verify;
}



int bajaProducto(eProductos prods[], int prodTam, eProveedores provs[], int provTam)
{
    int verify = -1;
    int index;
    int buscarCodigo;
    mostrarProductos( prods,prodTam, provs, provTam);
    if( getValidInt(&buscarCodigo,"* Ingrese el codigo del producto que desea eliminar: ","\n** El numero ingresado es incorrecto.") )
    {
        if( (index = buscarProducto(prods,prodTam,buscarCodigo)) > -1)
        {
            verify = 0;
            xlkCenterPrintf("ELIMINARA EL SIGUIENTE PRODUCTO",1);
            xlkSortPrintf(1,"%s,%s,%s,%s",4,"PROVEEDOR:","DESCRICPION:","IMPORTE:","CANTIDAD:");
            mostrarProducto(prods[index],provs,provTam);
            if( validateDualExit("* Esta seguro que desea eliminar el producto? s/n: ","** Respuesta invalida.",'s','n') )
            {
                prods[index].estado = 0;
                verify = 1;
            }
        }
    }
    return verify;
}



int modificarProducto(eProductos prods[], int prodTam, eProveedores provs[], int provTam)
{
    int verify = -1;
    int index;
    int buscarCodigo;
    mostrarProductos( prods,prodTam, provs, provTam);
    if( getValidInt(&buscarCodigo,"* Ingrese el codigo del producto que desea modificar: ","\n** El numero ingresado es incorrecto.") )
    {
        if( (index = buscarProducto(prods,prodTam,buscarCodigo)) > -1)
        {
            verify = 0;

            int selection;
            int quit = 0;
            do
            {
                xlkHeadGenerator(1,"MODIFICAR PRODUCTO:" );
                mostrarProducto(prods[index],provs, provTam);
                xlkIndexBodyGenerator(1,5,"1-Cambiar descripcion.","2-Cambiar importe.","3-Cambiar stock","4-Cambiar proveedor.","0-Salir");
                if( getRangedInt(&selection,0,4," -Seleccionar opcion: ","\nOpcion invalida.") )
                {


                    switch(selection)
                    {
                    case 1:
                        if( !getRangedGraphicStr( prods[index].descripcion, 1,50,"Ingrese nueva descripcion del producto: ","\nSe produjo un error al validar la descripcion.",1) )
                        {
                            printf("\n\n** La descripcion no se modifico.\n\n");
                        }
                        else
                        {
                            xstrCapsSpaceFixer( prods[index].descripcion);
                            printf("\n\n* Descripcion actualizada.\n\n");
                            verify = 1;
                        }
                        break;
                    case 2:
                        if( !getConditionedFloat( &prods[index].importe, 0.0001,1,"\n\nIngrese el importe del producto: ","\nSe produjo un error al validar el importe.") )
                        {
                            printf("\n\n** El importe no se modifico.\n\n");
                        }
                        else
                        {
                            printf("\n\n* Importe actualizado.\n\n");
                            verify = 1;
                        }
                        break;
                    case 3:
                        if( !getConditionedInt( &prods[index].cantidad, 0,1,"\n\nIngrese el stock del producto: ","\nSe produjo un error al validar el stock.") )
                        {
                            printf("\n\n** El stock no se modifico.\n\n");
                        }
                        else
                        {
                            printf("\n\n* Stock actualizado.\n\n");
                            verify = 1;
                        }
                        break;
                    case 4:
                        mostrarProveedores(provs,provTam);
                        if( getConditionedInt(&buscarCodigo,0,1,"Ingrese el codigo del proveedor que desea asignarle al producto: ","\nEl codigo es incorrecto.") )
                        {
                            if( buscarProveedor(provs, provTam, buscarCodigo) > -1)
                            {
                                printf("\n\n* Stock actualizado.\n\n");
                                prods[index].codigoProveedor = buscarCodigo;
                                verify = 1;
                            }
                            else
                            {
                                printf("** El proveedor no se encontro.\n\n");
                            }

                        }
                        if( verify == 0)
                        {
                            printf("\n\n** El stock no se modifico.\n\n");
                        }
                        break;
                    case 0:
                        quit = 1;
                        break;
                    }
                }
                system("pause");

            }
            while( !quit);
        }
    }
    return verify;
}



//FUNCIONES DE MUESTRA

void mostrarProducto( eProductos prodVar, eProveedores provs[], int provTam)
{
    int i;
    for( i= 0 ; i < provTam ; i++ )
    {
        if( provs[i].estado == OCUPADO && provs[i].codigoProveedor == prodVar.codigoProveedor )
        {
            xlkSortPrintf(3,"%s,%d,%s,%f,%d",5,provs[i].descripcion,prodVar.codigoProduto,prodVar.descripcion, prodVar.importe, prodVar.cantidad);
            break;
        }
    }
}




void mostrarProductos( eProductos prods[], int prodTam, eProveedores provs[],int provTam)
{
    int i;
    xlkCenterPrintf("LISTA DE PRODUCTOS",1);
    xlkSortPrintf(1,"%s,%s,%s,%s,%s",5,"PROVEEDOR:","CODIGO DE PRODUCTO:","DESCRICPION:","IMPORTE:","CANTIDAD:");

    for( i = 0 ; i < prodTam ; i++ )
    {
        if( prods[i].estado == OCUPADO )
        {
            mostrarProducto(prods[i],provs,provTam);
        }
    }
}
