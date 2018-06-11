#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xget.h"
#include "xlook.h"
#include "xstring.h"
#include "xvalidate.h"

#include "xProductos.h"
#include "xProveedores.h"
#include "xProductos-Proveedores.h"

#define LIBRE 0
#define OCUPADO 1

void inicializarProveedores(eProveedores provs[], int provTam)
{
    int i;

    provs[provTam-1].estado = 1;
    provs[provTam-1].codigoProveedor = 0;
    strcpy( provs[provTam-1].descripcion, "Sin asignar.");

    for( i = 0 ; i < provTam-1 ; i++ )
    {
        provs[i].estado = 0;

    }
}


//ABM DEPENDENCIAS:


int buscarProveedor(eProveedores provs[], int provTam,int codigoProveedor)
{
    int i;
    int matchIndex = -1 ;
    for(i = 0; i < provTam ; i++)
    {
        if( provs[i].estado == OCUPADO && provs[i].codigoProveedor == codigoProveedor)
        {
            matchIndex = i;
            break;
        }
    }
    return matchIndex;
}


int buscarLibreProveedores(eProveedores provs[], int provTam)
{
    int i;
    int freeIndex = -1 ;
    for(i = 0; i < provTam ; i++)
    {
        if( provs[i].estado == LIBRE)
        {
            freeIndex = i;
            break;
        }
    }
    return freeIndex;
}

//ABM DEPENDENCIAS:


int altaProveedor( eProveedores provs[], int provTam, int* codigoProveedor )
{
    int verify  = 0;
    int freeIndex = buscarLibreProveedores( provs,provTam);
    if( freeIndex > -1)
    {
        verify = 1;
        provs[freeIndex].codigoProveedor = (*codigoProveedor += 1);
        while( !getRangedGraphicStr(provs[freeIndex].descripcion,1,50,"Ingrese descripcion del proveedor: ","\nSe produjo un error al validar la descripcion.",1) )
        {
            printf("\n\n");
        }
        xstrCapsSpaceFixer(provs[freeIndex].descripcion);
        provs[freeIndex].estado = 1;
    }
    return verify;
}



int bajaProveedor( eProveedores provs[], int provTam )
{
    int verify = -1;
    int index;
    int buscarCodigo;

    if( getValidInt(&buscarCodigo,"* Ingrese el codigo del proveedor que desea eliminar: ","\n** El numero ingresado es incorrecto.") )
    {
        if( (index = buscarProveedor(provs,provTam,buscarCodigo)) > -1)
        {
            verify = 0;
            xlkCenterPrintf("ELIMINARA AL SIGUIENTE PROVEEDOR",1);
            if( validateDualExit("* Esta seguro que desea eliminar el proveedor? s/n: ","** Respuesta invalida.",'s','n') )
            {
                provs[index].estado = 0;
                verify = 1;
            }
        }
    }
    return verify;
}

int modificarProveedor( eProveedores provs[], int provTam )
{
    int verify = -1;
    int index;
    int buscarCodigo;

    mostrarProveedores(provs, provTam);
    if( getValidInt(&buscarCodigo,"* Ingrese el codigo del proveedor que desea modificar: ","\n** El numero ingresado es incorrecto.") )
    {
        if( (index = buscarProveedor(provs, provTam,buscarCodigo)) > -1)
        {
            verify = 0;

            int selection;
            int quit = 0;
            do
            {
                xlkHeadGenerator(1,"MODIFICAR PROVEEDOR:" );
                mostrarProveedor(provs[index]);
                xlkIndexBodyGenerator(1,2,"1-Cambiar descripcion.","0-Salir");
                if( getRangedInt(&selection,0,1," -Seleccionar opcion: ","\nOpcion invalida.") )
                {
                    switch(selection)
                    {
                    case 1:
                        if( !getRangedGraphicStr( provs[index].descripcion, 1,50,"Ingrese nueva descripcion del proveedor: ","\nSe produjo un error al validar la descripcion.",1) )
                        {
                            printf("\n\n** La descripcion no se modifico.\n\n");
                        }
                        else
                        {
                            xstrCapsSpaceFixer( provs[index].descripcion);
                            printf("\n\n* Descripcion actualizada.\n\n");
                            verify = 1;
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

void mostrarProveedor( eProveedores provVar )
{
    xlkSortPrintf(3,"%d,%s",2,provVar.codigoProveedor,provVar.descripcion);
}

void mostrarProveedores( eProveedores provs[],int provTam)
{
    int i;
    xlkSortPrintf(1,"%s,%s",2,"ID DE PROVEEDOR:","DESCRIPCION:");
    for(i = 0; i < provTam ; i++)
    {
        if( provs[i].estado == OCUPADO )
        {
            mostrarProveedor(provs[i]);
        }
    }
}


