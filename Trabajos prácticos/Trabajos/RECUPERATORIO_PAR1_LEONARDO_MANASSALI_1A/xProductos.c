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

//Funciones basicas:



/** \brief Inicializa el estado de un vector de productos en 0 y establece el codigo de proveedor por defecto ( 0 - "Sin asignar" ).
 *
 * \param prods: Vector de productos a inicializar.
 * \param prodTam: Tama�o del vector.
 * \return
 *
 */

void inicializarProductos(eProductos prods[], int prodTam)
{
    int i;
    for( i = 0 ; i < prodTam ; i++ )
    {
        prods[i].estado = LIBRE;
        prods[i].codigoProveedor = 0;
    }
}


//----FUNCION SOLO PARA DEPURACION----

/** \brief Harcodea un array de productos con 10 elementos. El tama�o del mismo debe debe ser como minimo 10.
 *
 * \param prods: Vector de productos a harcodear.
 * \return
 *
 */

void harcodearProductos( eProductos prods[])
{
    prods[0].estado = 1;
    prods[0].codigoProduto = 1;
    prods[0].codigoProveedor = 1;
    strcpy( prods[0].descripcion, "Auriculares");
    prods[0].cantidad = 8;
    prods[0].importe = 500.75;

    prods[1].estado = 1;
    prods[1].codigoProduto = 2;
    prods[1].codigoProveedor = 1;
    strcpy( prods[1].descripcion, "Parlante bluetooth portatil");
    prods[1].cantidad = 300;
    prods[1].importe = 750.99;

    prods[2].estado = 1;
    prods[2].codigoProduto = 3;
    prods[2].codigoProveedor = 1;
    strcpy( prods[2].descripcion, "Play Station 4 Pro");
    prods[2].cantidad = 10;
    prods[2].importe = 19855.80;

    prods[3].estado = 1;
    prods[3].codigoProduto = 4;
    prods[3].codigoProveedor = 2;
    strcpy( prods[3].descripcion, "Focus C4");
    prods[3].cantidad = 5;
    prods[3].importe = 750000;


    prods[4].estado = 1;
    prods[4].codigoProduto = 5;
    prods[4].codigoProveedor = 2;
    strcpy( prods[4].descripcion, "Fiesta PR-45");
    prods[4].cantidad = 2;
    prods[4].importe = 350000;


    prods[5].estado = 1;
    prods[5].codigoProduto = 6;
    prods[5].codigoProveedor = 3;
    strcpy( prods[5].descripcion, "Pideos pack grande");
    prods[5].cantidad = 250;
    prods[5].importe = 80.50;


    prods[6].estado = 1;
    prods[6].codigoProduto = 7;
    prods[6].codigoProveedor = 3;
    strcpy( prods[6].descripcion, "Verduras precocidas");
    prods[6].cantidad = 15000;
    prods[6].importe = 35;


    prods[7].estado = 1;
    prods[7].codigoProduto = 8;
    prods[7].codigoProveedor = 3;
    strcpy( prods[7].descripcion, "Cubitos");
    prods[7].cantidad = 1;
    prods[7].importe = 23.47;

    prods[8].estado = 1;
    prods[8].codigoProduto = 9;
    prods[8].codigoProveedor = 4;
    strcpy( prods[8].descripcion, "Cuaderno tapa dura");
    prods[8].cantidad = 29;
    prods[8].importe = 100;

    prods[9].estado = 1;
    prods[9].codigoProduto = 10;
    prods[9].codigoProveedor = 4;
    strcpy( prods[9].descripcion, "Block de hojas A4");
    prods[9].cantidad = 9;
    prods[9].importe = 180;
}



//ABM DEPENDENCIAS:



/** \brief Busca un producto especifico en un array a traves de un codigo de producto pasado por parametro.
 *
 * \param prods : Vector de productos donde realizar la busqueda.
 * \param prodTam : Tama�o del array.
 * \param codigoProducto: Codigo a buscar en el array.
 * \return Devuelve el indice donde se encuentra el producto buscado. En caso de no hallarse devuelve -1.
 *
 */

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



/** \brief Busca un sitio libre en un array de productos. Se basa en el campo de estado, 1 ocupado, 0 libre.
 *
 * \param prods: Array de productos donde buscar lugar.
 * \param prodTam: Tama�o del array de productos.
 * \return Devuelve el indice del primer lugar vacio en el array. En caso de no haber lugar devuelve -1.
 *
 */

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



/** \brief Pide al usuario datos para cargar un producto y los mismos son validados.
 *
 * \param
 * \return Devuelve una variable de tipo eProductos con los datos cargados.
 *
 */

eProductos pedirProducto(void)
{
    eProductos nuevoProducto;
    while( !getRangedGraphicStr( nuevoProducto.descripcion, 1,50,"* Ingrese descripcion del producto: ","** Se produjo un error al validar la descripcion.\nDescripcion demasiado larga o invalida.\n\n",1) );
    xstrCapsSpaceFixer( nuevoProducto.descripcion);
    while( !getConditionedFloat( &nuevoProducto.importe, 0.0001,1,"* Ingrese el importe del producto: ","\n** Se produjo un error al validar el importe.\n\n") );
    while( !getConditionedInt( &nuevoProducto.cantidad, 0,1,"* Ingrese el stock del producto: ","\n** Se produjo un error al validar el stock.\n\n") );
    return nuevoProducto;
}



//ALTA, BAJA Y MODIFICACION:



/** \brief Da de alta un producto en un array con un codigo autoincremental.
 *
 * \param prods : Array de productos donde almacenar el producto nuevo.
 * \param prodTam : Tama�o del array de productos.
 * \param provs: Array donde buscar un proveedor para asignarle al producto.
 * \param provTam: Tama�o del array de proveedores asociado.
 * \param codigoProducto: Puntero a entero que debe contener el ultimo codigo de producto cargado o 0 en caso de no haber.
 * \return Devuelve 1 si el producto se cargo con exito o 0 si no hay espacio en el array.
 *
 */

int altaProducto(eProductos prods[], int prodTam, eProveedores provs[], int provTam, int* codigoProducto)
{
    system("cls");
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
            mostrarProveedores(provs,provTam);
            xlkSortPrintf(1,"%s",1,"NO ASIGNAR UN PROVEEDOR:");
            mostrarProveedor(provs[provTam-1]);
            if( getConditionedInt(&codigoProveedor,0,1,"\n* Ingrese el codigo del proveedor que desea asignarle al producto: ","\n**El codigo es incorrecto.") )
            {
                if( buscarProveedor(provs, provTam, codigoProveedor) > -1)
                {
                    printf("\n");
                    prods[index].codigoProveedor = codigoProveedor;
                    valid++;
                }
                else
                {
                    printf("\n** No se encontro el proveedor.\n\n");
                    system("pause");
                }
            }
            else
            {
                printf("\n\n");
                system("pause");
            }
        }
        prods[index].codigoProduto = (*codigoProducto += 1) ;
        prods[index].estado = OCUPADO;
        verify = 1;
    }
    return verify;
}



/** \brief Elimina un producto de un array.
 *
 * \param prods: Array de productos.
 * \param prodTam: Tama�o del array de productos.
 * \param provs: Array de proveedores asociado.
 * \param provTam: Tama�o del array.
 * \return Devuelve 1 si usuario elimino un producto , 0 si cancelo la baja , -1 si el producto que el usuario buscaba no existe o -2 si no hay productos cargados.
 *
 */

int bajaProducto(eProductos prods[], int prodTam, eProveedores provs[], int provTam)
{
    int verify = -1;
    int index;
    int buscarCodigo;
    system("cls");
    if( mostrarProductos( prods,prodTam, provs, provTam) )
    {
        if( getValidInt(&buscarCodigo,"\n* Ingrese el codigo del producto que desea eliminar: ","\n** El numero ingresado es incorrecto.") )
        {
            if( (index = buscarProducto(prods,prodTam,buscarCodigo)) > -1)
            {
                verify = 0;
                system("cls");
                xlkCenterPrintf("ELIMINARA EL SIGUIENTE PRODUCTO",1);
                xlkSortPrintf(1,"%s,%s,%s,%s,%s",5,"PROVEEDOR:","CODIGO DE PRODUCTO","DESCRICPION:","IMPORTE:","CANTIDAD:");
                mostrarProductoBuscarProv(prods[index],provs,provTam);
                if( validateDualExit("\n* Esta seguro que desea eliminar el producto? s/n: ","** Respuesta invalida.",'s','n') )
                {
                    prods[index].estado = 0;
                    verify = 1;
                }
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



/** \brief Modifica los campos de un producto.
 *
 * \param prods: Array de productos donde buscar producto para modificar.
 * \param prodTam: Tama�o del array de productos.
 * \param provs: Array de proveedores asociado al array de productos.
 * \param provTam: Tama�o del array de proveedores.
 * \return Devuelve 1 si el usuario hizo alguna modificacion, 0 si no hizo ninguna y -1 si no se puedo encontrar el producto que busco o -2 si no hay productos cargados.
 *
 */

int modificarProducto(eProductos prods[], int prodTam, eProveedores provs[], int provTam)
{
    int verify = -1;
    int index;
    int buscarCodigo;
    system("cls");
    if( mostrarProductos( prods,prodTam, provs, provTam) )
    {
        if( getValidInt(&buscarCodigo,"\n* Ingrese el codigo del producto que desea modificar: ","\n** El numero ingresado es incorrecto.") )
        {
            if( (index = buscarProducto(prods,prodTam,buscarCodigo)) > -1)
            {
                verify = 0;
                system("cls");
                int selection;
                int quit = 0;
                do
                {
                    xlkHeadGenerator(1,"MODIFICAR PRODUCTO:" );
                    xlkSortPrintf(1,"%s,%s,%s,%s,%s",5,"PROVEEDOR:","CODIGO DE PRODUCTO:","DESCRICPION:","IMPORTE:","CANTIDAD:");
                    mostrarProductoBuscarProv(prods[index],provs, provTam);
                    xlkIndexBodyGenerator(1,5,"1- Cambiar descripcion.","2- Cambiar importe.","3- Cambiar stock","4- Cambiar proveedor.","0- Volver");
                    if( getRangedInt(&selection,0,4," -Seleccionar opcion: ","\nOpcion invalida.") )
                    {


                        switch(selection)
                        {
                        case 1:
                            system("cls");
                            if( !getRangedGraphicStr( prods[index].descripcion, 1,50,"Ingrese nueva descripcion del producto: ","** Se produjo un error al validar la descripcion.",1) )
                            {
                                printf("\n** La descripcion no se modifico.\n\n");
                            }
                            else
                            {
                                xstrCapsSpaceFixer( prods[index].descripcion);
                                printf("\n* Descripcion actualizada.\n\n");
                                verify = 1;
                            }
                            break;
                        case 2:
                            system("cls");
                            if( !getConditionedFloat( &prods[index].importe, 0.0001,1,"Ingrese nuevo importe del producto: ","\n** Se produjo un error al validar el importe.") )
                            {
                                printf("\n** El importe no se modifico.\n\n");
                            }
                            else
                            {
                                printf("\n* Importe actualizado.\n\n");
                                verify = 1;
                            }
                            break;
                        case 3:
                            system("cls");
                            if( !getConditionedInt( &prods[index].cantidad, 0,1,"Ingrese nuevo stock del producto: ","\n** Se produjo un error al validar el stock.") )
                            {
                                printf("\n** El stock no se modifico.\n\n");
                            }
                            else
                            {
                                printf("\n* Stock actualizado.\n\n");
                                verify = 1;
                            }
                            break;
                        case 4:
                            system("cls");
                            mostrarProveedores(provs,provTam);
                            if( getConditionedInt(&buscarCodigo,1,1,"\n* Ingrese el nuevo codigo del proveedor que desea asignarle al producto: ","\n** El codigo es incorrecto.\n\n") )
                            {
                                if( buscarProveedor(provs, provTam, buscarCodigo) > -1)
                                {
                                    printf("\n* Proveedor actualizado.\n\n");
                                    prods[index].codigoProveedor = buscarCodigo;
                                    verify = 1;
                                }
                                else
                                {
                                    printf("\n** El proveedor no se encontro.\n\n");
                                }
                            }
                            break;
                        case 0:
                            quit = 1;
                            break;

                        }
                        if( selection > 0)
                        {
                            system("pause");
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



/** \brief Muestra un producto de un array.
 *
 * \param prodVar: Variable de tipo eProductos a mostrar.
 * \param provVar: Variable de tipo eProveedores que contiene datos del proveedor asociado al producto.
 * \return
 *
 */

void mostrarProducto( eProductos prodVar, eProveedores provVar)
{
    xlkSortPrintf(3,"%s,%d,%s,%f,%d",5,provVar.descripcion,prodVar.codigoProduto,prodVar.descripcion, prodVar.importe, prodVar.cantidad);
}



/** \brief Muestra un producto buscando su proveedor.
 *
 * \param prodVar: Variable de tipo eProductos a mostrar.
 * \param provs: Array de proveedores donde buscar el proveedor correspondiente al producto.
 * \param provTam: Tama�o del array de proveedores.
 * \return Devuelve 1 si mostro algun dato o 0 si no mostro nada.
 *
 */

int mostrarProductoBuscarProv( eProductos prodVar, eProveedores provs[], int provTam)
{
    int i;
    int verify = 0;
    for( i = 0 ; i < provTam ; i++)
    {
        if( provs[i].estado == OCUPADO && provs[i].codigoProveedor == prodVar.codigoProveedor)
        {
            xlkSortPrintf(3,"%s,%d,%s,%f,%d",5,provs[i].descripcion,prodVar.codigoProduto,prodVar.descripcion, prodVar.importe, prodVar.cantidad);
            verify = 1;
        }
    }
    return verify;
}



/** \brief Muestra todos los productos de un array de productos.
 *
 * \param prods: Array de productos a mostrar.
 * \param prodTam: Tama�o del array de productos.
 * \param provs: Array de proveedores donde buscar proveedores de los productos.
 * \param provTam: Tama�o del array de proveedores.
 * \return Devuelve 1 si mostro algun dato o 0 si no mostro nada.
 *
 */

int mostrarProductos( eProductos prods[], int prodTam, eProveedores provs[],int provTam)
{
    int i;
    int j;
    int verify = 0;

    xlkCenterPrintf("LISTA DE PRODUCTOS",1);
    xlkSortPrintf(1,"%s,%s,%s,%s,%s",5,"PROVEEDOR:","CODIGO DE PRODUCTO:","DESCRICPION:","IMPORTE:","CANTIDAD:");

    for( i = 0 ; i < prodTam ; i++ )
    {
        if( prods[i].estado == OCUPADO )
        {
            for( j = 0 ; j < provTam ; j++)
            {
                if( provs[j].estado == OCUPADO && prods[i].codigoProveedor == provs[j].codigoProveedor)
                {
                    mostrarProducto(prods[i],provs[j]);
                    verify = 1;
                }
            }

        }
    }
    if(verify == 0)
    {
        system("cls");
    }
    return verify;
}
