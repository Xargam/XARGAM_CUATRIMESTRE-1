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



/** \brief Inicializa el estado de un vector de proveedores en 0 y establece el codigo de proveedor por defecto ( 0 - "Sin asignar" ).
*
* \param provs: Vector de proveedores a inicializar.
* \param provTam: Tamaño del vector.
* \return
*
*/

void inicializarProveedores(eProveedores provs[], int provTam)
{
    int i;

    provs[provTam-1].estado = 1;
    provs[provTam-1].codigoProveedor = 0;
    strcpy( provs[provTam-1].descripcion, "Sin asignar");

    for( i = 0 ; i < provTam-1 ; i++ )
    {
        provs[i].estado = 0;

    }
}



//Funcion solo para depuracion:



/** \brief Harcodea un array de proveedores con 4 elementos. El tamaño del mismo debe debe ser como minimo 4.
 *
 * \param provs: Vector de proveedores a harcodear.
 * \return
 *
 */

void harcodearProveedores( eProveedores provs[])
{
    provs[0].estado = 1;
    provs[0].codigoProveedor = 1;
    strcpy( provs[0].descripcion, "Sony");

    provs[1].estado = 1;
    provs[1].codigoProveedor = 2;
    strcpy( provs[1].descripcion, "Ford");

    provs[2].estado = 1;
    provs[2].codigoProveedor = 3;
    strcpy( provs[2].descripcion, "Marolio");

    provs[3].estado = 1;
    provs[3].codigoProveedor = 4;
    strcpy( provs[3].descripcion, "Rivadavia");
}

//ABM DEPENDENCIAS:



/** \brief Busca un proveedor especifico en un array a traves de un codigo de proveedor pasado por parametro.
 *
 * \param provs : Array de proveedores donde realizar la busqueda.
 * \param provTam : Tamaño del array.
 * \param codigoProveedor: Codigo de proveedor a buscar en el array.
 * \return Devuelve el indice donde se encuentra proveedor buscado. En caso de no hallarse devuelve -1.
 *
 */

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


/** \brief Busca un sitio libre en un array de proveedores. Se basa en el campo de estado, 1 ocupado, 0 libre.
 *
 * \param provs: Array de proveedores donde buscar lugar.
 * \param provTam: Tamaño del array.
 * \return Devuelve el indice del primer lugar vacio en el array. En caso de no haber lugar devuelve -1.
 *
 */

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



/** \brief Da de alta un proveedor.
 *
 * \param provs : Array de proveedores.
 * \param provTam : Tamaño del array.
 * \param codigoProveedor: Puntero a entero que debe contener el ultimo codigo de proveedor cargado.
 * \return Devuelve 1 si el proveedor se cargo con exito o 0 si no hay espacio en el array.
 *
 */

int altaProveedor( eProveedores provs[], int provTam, int* codigoProveedor )
{
    system("cls");
    int verify  = 0;
    int freeIndex = buscarLibreProveedores( provs,provTam);
    if( freeIndex > -1)
    {
        verify = 1;
        provs[freeIndex].codigoProveedor = (*codigoProveedor += 1);
        while( !getRangedGraphicStr(provs[freeIndex].descripcion,1,50,"* Ingrese descripcion del proveedor: ","** Se produjo un error al validar la descripcion.\n\n",1) );
        xstrCapsSpaceFixer(provs[freeIndex].descripcion);
        provs[freeIndex].estado = 1;
    }
    system("cls");
    return verify;
}



/** \brief Elimina un proveedor.
 *
 * \param provs: Array de proveedores donde buscar un proveedor para dar de baja.
 * \param provTam: Tamaño del array de proveedores.
 * \param prods: Array de productos asociado al de proveedores.
 * \param prodTam: Tamaño del array de productos.
 * \return Devuelve 1 si usuario elimino un producto , 0 si cancelo la baja, -1 si el producto que el usuario buscaba no existe o -2 si no hay productos cargados.
 *
 */

int bajaProveedor( eProveedores provs[], int provTam, eProductos prods[], int prodTam )
{
    int verify = -1;
    int index;
    int i;
    int buscarCodigo;
    system("cls");
    if( mostrarProveedores(provs, provTam) )
    {
        if( getConditionedInt(&buscarCodigo,1,1,"\n* Ingrese el codigo del proveedor que desea eliminar: ","\n** El numero ingresado es incorrecto.\n\n") )
        {
            if( (index = buscarProveedor(provs,provTam,buscarCodigo)) > -1)
            {
                verify = 0;
                system("cls");
                xlkCenterPrintf("ELIMINARA AL SIGUIENTE PROVEEDOR",1);
                xlkSortPrintf(1,"%s,%s",2,"CODIGO DE PROVEEDOR:","DESCRIPCION:");
                mostrarProveedor(provs[index]);
                if( validateDualExit("\n* Esta seguro que desea eliminar el proveedor? s/n: ","** Respuesta invalida.",'s','n') )
                {
                    for( i = 0 ; i < prodTam ; i++ )
                    {
                        if( prods[i].codigoProveedor == provs[index].codigoProveedor )
                        {
                            prods[i].codigoProveedor = 0;
                        }
                    }
                    provs[index].estado = 0;
                    verify = 1;
                }
            }
        }
        else
        {
            system("pause");
        }
    }
    else
    {
        verify = -2;
    }
    system("cls");
    return verify;
}



/** \brief Modifica los campos de un proveedor.
 *
 * \param provs: Array de proveedores.
 * \param provTam: Tamaño del array de proveedores.
 * \return Devuelve 1 si el usuario hizo alguna modificacion, 0 si no hizo ninguna, -1 si no se puedo encontrar el producto que busco o -2 si no hay productos cargados.
 *
 */

int modificarProveedor( eProveedores provs[], int provTam )
{
    int verify = -1;
    int index;
    int buscarCodigo;
    system("cls");
    if( mostrarProveedores(provs, provTam) )
    {
        if( getConditionedInt(&buscarCodigo,1,1,"\n* Ingrese el codigo del proveedor que desea modificar: ","\n** El numero ingresado es incorrecto.") )
        {
            if( (index = buscarProveedor(provs, provTam,buscarCodigo)) > -1)
            {
                verify = 0;
                system("cls");
                int selection;
                int quit = 0;
                do
                {
                    xlkHeadGenerator(1,"MODIFICAR PROVEEDOR:" );
                    xlkSortPrintf(1,"%s,%s",2,"CODIGO DE PROVEEDOR:","DESCRIPCION:");
                    mostrarProveedor(provs[index]);
                    xlkIndexBodyGenerator(1,2,"1- Cambiar descripcion.","0- Volver.");
                    if( getRangedInt(&selection,0,1," -Seleccionar opcion: ","\nOpcion invalida.") )
                    {
                        switch(selection)
                        {
                        case 1:
                            system("cls");
                            if( !getRangedGraphicStr( provs[index].descripcion, 1,50,"* Ingrese nueva descripcion del proveedor: ","** Se produjo un error al validar la descripcion.",1) )
                            {
                                printf("\n** La descripcion no se modifico.\n\n");
                            }
                            else
                            {
                                xstrCapsSpaceFixer( provs[index].descripcion);
                                printf("\n* Descripcion actualizada.\n\n");
                                verify = 1;
                            }
                            system("pause");
                            break;
                        case 0:
                            quit = 1;
                            break;
                        }
                    }
                }
                while( !quit);
            }
        }
    }
    else
    {
        verify = -2;
    }
    system("cls");
    return verify;
}


//FUNCIONES DE MUESTRA



/** \brief Muestra un proveedor.
 *
 * \param provVar: Variable de tipo eProveedores a mostrar.
 * \return
 *
 */

void mostrarProveedor( eProveedores provVar )
{
    xlkSortPrintf(3,"%d,%s",2,provVar.codigoProveedor,provVar.descripcion);
}



/** \brief Muestra todos los proveedores.
 *
 * \param provs: Array de proveedores a mostrar.
 * \param provTam: Tamaño del array de proveedores.
 * \return Devuelve 1 si mostro algun dato o 0 si no mostro nada.
 *
 */

int mostrarProveedores( eProveedores provs[],int provTam)
{
    int i;
    int verify = 0;
    xlkCenterPrintf("LISTA DE PROVEEDORES",1);
    xlkSortPrintf(1,"%s,%s",2,"CODIGO DE PROVEEDOR:","DESCRIPCION:");
    for(i = 0; i < provTam-1 ; i++)
    {
        if( provs[i].estado == OCUPADO )
        {
            mostrarProveedor(provs[i]);
            verify = 1;
        }
    }
    if(verify == 0)
    {
        system("cls");
    }
    return verify;
}


