#include <stdio.h>
#include <stdlib.h>

#include "xget.h"
#include "xlook.h"
#include "xstring.h"
#include "xvector.h"

#include "xProductos-Proveedores.h"
#include "xProductos.h"
#include "xProveedores.h"

#define LIBRE 0
#define OCUPADO 1


//Funciones de menu:



/** \brief Muestra un menu para la alta de proveedores y productos.
 *
 * \param prods: Array de productos de productos.
 * \param prodTam: Tamaño del array.
 * \param codigoProducto: ultimo codigo cargado de productos.
 * \param provs: Array de proveedores.
 * \param provTam: Tamaño del array de proveedores
 * \param codigoProveedor: ultimo codigo cargado de proveedores.
 * \return
 *
 */

void altaMenu(eProductos prods[],int prodTam,int* codigoProducto,eProveedores provs[],int provTam,int* codigoProveedor)
{
    int quit = 0;
    int selection;

    do
    {
        xlkIndexGenerator("Menu altas",3,"1* Alta producto.","2* Alta proveedor.","0* Volver.");
        if( getRangedInt(&selection,0,2," -Seleccionar opcion: ","\n** Opcion invalida.\n\n") )
        {
            switch(selection)
            {
            case 1:
                if( altaProducto(prods,prodTam,provs,provTam,codigoProducto) )
                {
                    printf("* Producto dado de alta en el sistema.\n\n");
                }
                else
                {
                    printf("* No hay espacio para agregar mas productos al sistema.\n\n");
                }
                system("pause");
                break;
            case 2:
                if( altaProveedor(provs,provTam,codigoProveedor))
                {
                    printf("* Proveedor dado de alta en el sistema.\n\n");
                }
                else
                {
                    printf("* No hay espacio para agregar mas proveedores al sistema.\n\n");
                }
                system("pause");
                break;
            case 0:
                quit = 1;
                break;
            }
        }
        else
        {
            system("pause");
        }
    }
    while( !quit );
    system("cls");
}



/** \brief Muestra un menu para la baja de proveedores y productos.
 *
 * \param prods: Array de productos de productos.
 * \param prodTam: Tamaño del array.
 * \param provs: Array de proveedores.
 * \param provTam: Tamaño del array de proveedores.
 * \return
 *
 */

void bajaMenu(eProductos prods[],int prodTam,eProveedores provs[],int provTam)
{
    int quit = 0;
    int selection;
    int reading;

    do
    {
        xlkIndexGenerator("Menu bajas",3,"1* Baja producto.","2* Baja proveedor.","0* Volver.");
        if( getRangedInt(&selection,0,2," -Seleccionar opcion: ","\n** Opcion invalida.\n\n") )
        {
            switch(selection)
            {
            case 1:
                reading = bajaProducto(prods,provTam,provs,provTam);
                if( reading == 1 )
                {
                    printf("* Producto dado de baja del sistema.\n\n");
                }
                else if(reading == 0)
                {
                    printf("* Accion cancelada. No se realizo ninguna baja.\n\n");
                }
                else if(reading == -1)
                {
                    printf("* No se ha encontrado el producto que busca.\n\n");
                }
                else
                {
                    printf("* No hay productos cargados en el sistema.\n\n");
                }
                system("pause");
                break;
            case 2:
                reading = bajaProveedor(provs,provTam,prods,prodTam);
                if( reading == 1)
                {
                    printf("* Proveedor dado de baja del sistema.\n\n");
                }
                else if( reading == 0)
                {
                    printf("* Accion cancelada. No se realizo ninguna baja.\n\n");
                }
                else if(reading == -1)
                {
                    printf("* No se ha encontrado el proveedor que busca.\n\n");
                }
                else
                {
                    printf("* No hay productos cargados en el sistema.\n\n");
                }
                system("pause");
                break;
            case 0:
                quit = 1;
                break;
            }
        }
        else
        {
            system("pause");
        }
    }
    while( !quit);
    system("cls");
}



/** \brief Muestra un menu para la modificacion de proveedores y productos.
 *
 * \param prods: Array de productos de productos.
 * \param prodTam: Tamaño del array.
 * \param provs: Array de proveedores.
 * \param provTam: Tamaño del array de proveedores.
 * \return
 *
 */

void modificacionMenu(eProductos prods[],int prodTam,eProveedores provs[],int provTam)
{
    int quit = 0;
    int selection;
    int reading;

    do
    {
        xlkIndexGenerator("Menu modificaciones",3,"1* Modificar producto.","2* Modificar proveedor.","0* Volver.");
        if( getRangedInt(&selection,0,2," -Seleccionar opcion: ","\n** Opcion invalida.\n\n") )
        {
            switch(selection)
            {
            case 1:
                reading = modificarProducto(prods,provTam,provs,provTam);
                if( reading == 1 )
                {
                    printf("* Se aplicaron con exito las modificaciones.\n\n");
                }
                else if(reading == 0)
                {
                    printf("* No se realizaron modificaciones.\n\n");
                }
                else if(reading == -1)
                {
                    printf("* No se ha encontrado el producto que busca.\n\n");
                }
                else
                {
                    printf("* No hay productos cargados en el sistema.\n\n");
                }
                system("pause");
                break;
            case 2:
                reading = modificarProveedor(provs,provTam);
                if( reading == 1)
                {
                    printf("* Se aplicaron con exito las modificaciones.\n\n");
                }
                else if( reading == 0)
                {
                    printf("* No se realizaron modificaciones.\n\n");
                }
                else if(reading == -1)
                {
                    printf("* No se ha encontrado el proveedor que busca.\n\n");
                }
                else
                {
                    printf("* No hay productos cargados en el sistema.\n\n");
                }
                system("pause");
                break;
            case 0:
                quit = 1;
                break;
            }
        }
        else
        {
            system("pause");
        }
    }
    while( !quit);
    system("cls");
}



/** \brief Muestra un menu de informes de datos acerca de productos y proveedores.
 *
 * \param prods: Array de productos de productos.
 * \param prodTam: Tamaño del array.
 * \param provs: Array de proveedores.
 * \param provTam: Tamaño del array de proveedores.
 * \return
 *
 */

void mostrarMenuInformar( eProductos prods[], int prodTam, eProveedores provs[], int provTam )
{
    int seleccion ;
    int exit = 0;

    do
    {
        xlkIndexGenerator("Menu Informes",5,"1* Total y promedio de importes, cantidad de productos que lo superan.","2* Total y promedio de importes, cantidad de productos que NO lo superan.","3* Cantidad de productos con stock menor o igual a 10.","4* Cantidad de productos con stock mayor a 10.","0* Volver.");
        if( getRangedInt(&seleccion,0,4," -Seleccionar opcion: ","\n** Opcion invalida.\n\n") )
        {
            switch(seleccion)
            {
            case 1:
                prodMostrarImportesMayoresAlPromedio(prods, prodTam, provs, provTam);
                break;
            case 2:
                prodMostrarImportesMenoresAlPromedio(prods, prodTam, provs, provTam);
                break;
            case 3:
                prodMostrarStocksMenorIgual10(prods, prodTam, provs, provTam);
                break;
            case 4:
                prodMostrarStocksMayor10(prods, prodTam, provs, provTam);
                break;
            case 0:
                exit = 1;
                break;
            }
            if( seleccion > 0)
            {
                system("pause");
            }
        }
        else
        {
            system("pause");
        }

    }
    while( !exit);
    system("cls");
}



/** \brief Muestra un menu de listado variados de productos y proveedores.
 *
 * \param prods: Array de productos de productos.
 * \param prodTam: Tamaño del array.
 * \param provs: Array de proveedores.
 * \param provTam: Tamaño del array de proveedores.
 * \return
 *
 */

void mostrarMenuListar( eProductos prods[], int prodTam, eProveedores provs[], int provTam )
{
    int seleccion ;
    int exit = 0;

    do
    {
        xlkIndexGenerator("Menu listar",13,"1*  Mostrar lista ordenada de productos.","2*  Mostrar productos con stock menor o igual a 10.","3*  Mostrar productos con stock mayor a 10.","4*  Mostrar productos que superan el promedio de importes.","5*  Mostrar productos que NO superan el promedio de importes.","6*  Mostrar proveedores cuya cantidad de producto es menor o igual a 10.","7*  Mostrar productos por proveedor.","8*  Mostrar productos de un proveedor determinado.", "9*  Mostrar proveedor que provee mas productos.","10* Mostrar proveedor que provee menos productos.","11* Mostrar proveedor del producto mas caro.","12* Mostrar proveedor del producto mas barato.","0*  Volver.");
        if( getRangedInt(&seleccion,0,12," -Seleccionar opcion: ","\n** Opcion invalida.\n\n") )
        {
            switch(seleccion)
            {
            case 1:
                ordenarProductos(prods,prodTam, provs, provTam);
                break;
            case 2:
                ListarProdsCantMenorIgualA10(prods,prodTam, provs, provTam);
                break;
            case 3:
                ListarProdsCantMayorA10(prods, prodTam, provs, provTam);
                break;
            case 4:
                ListarProdsImportesMayoresAlPromedio(prods,prodTam, provs, provTam);
                break;
            case 5:
                ListarProdsImportesMenoresAlPromedio(prods,prodTam, provs, provTam);
                break;
            case 6:
                ListarProvsCantidadProdMenorIgualA10(prods,prodTam, provs, provTam);
                break;
            case 7:
                ListarProductorPorProveedor(prods,prodTam, provs, provTam);
                break;
            case 8:
                ListarProductosDeUnProveedor(prods,prodTam, provs, provTam);
                break;
            case 9:
                ListarProveedorMasProductos(prods,prodTam, provs, provTam);
                break;
            case 10:
                ListarProveedorMenosProductos(prods,prodTam, provs, provTam);
                break;
            case 11:
                ListarProveedorProductoMasCaro(prods,prodTam, provs, provTam);
                break;
            case 12:
                ListarProveedorProductoMasBarato(prods,prodTam, provs, provTam);
                break;
            case 0:
                exit = 1;
                break;
            }
            if( seleccion > 0)
            {
                system("pause");
            }
        }
        else
        {
            system("pause");
        }
    }
    while( !exit);
    system("cls");
}



//FUNCIONES MENU INFORMAR:



/** \brief Obtiene la suma y calcula el promedio de importes, luego muestra cuantos productos superan dicho promedio.
 *
 * \param prod : Vector de productos.
 * \param prodTam : Tamaño del vector de productos.
 * \param prov : Vector de proveedores .
 * \param provTam : Tamaño del vector de proveedores .
 *
 */

void prodMostrarImportesMayoresAlPromedio ( eProductos prod[], int prodTam, eProveedores prov[], int provTam )
{
    system("cls");
    float promedio ;
    float acumulador = 0;
    int contador = 0;
    int flag = 0;
    int contadorProdsMasPromedio = 0;
    int i;

    for(i = 0 ; i < prodTam ; i++ )
    {
        if( prod[i].estado == OCUPADO)
        {
            acumulador += prod[i].importe ;
            flag = 1;
            contador++;
        }
    }
    promedio = acumulador / contador ;

    for (i = 0 ; i < prodTam ; i++)
    {
        if( prod[i].estado == OCUPADO && prod[i].importe > promedio)
        {
            contadorProdsMasPromedio++;
        }
    }
    if( !flag)
    {
        printf("** No hay productos cargados en el sistema.\n\n");
    }
    else
    {
        xlkCenterPrintf("DATOS DE IMPORTES",1);
        xlkSortPrintf(1,"%s,%s",2,"SUMA DE IMPORTES:","PROMEDIO DE IMPORTES:");
        xlkSortPrintf(3,"%f,%f",2,acumulador,promedio);
        printf("\n* Hay %d productos que superan el promedio de importes.\n\n",contadorProdsMasPromedio);
    }


}



/** \brief Obtiene la suma y calcula el promedio de importes, luego muestra cuantos productos NO superan dicho promedio.
 *
 * \param prod : Vector de productos .
 * \param prodTam : Tamaño del vector de productos.
 * \param prov : Vector de proveedores .
 * \param provTam : Tamaño del vector de proveedores .
 *
 */

void prodMostrarImportesMenoresAlPromedio(eProductos prod[], int prodTam, eProveedores prov[], int provTam)
{
    system("cls");
    float promedio ;
    float acumulador = 0;
    int contador = 0;
    int contadorProdsMenosPromedio = 0;
    int i;
    int flag = 0;

    for(i = 0 ; i < prodTam ; i++ )
    {
        if( prod[i].estado == 1)
        {
            acumulador += prod[i].importe ;
            contador++;
        }
    }
    promedio = acumulador / contador ;

    for (i = 0 ; i < prodTam ; i++)
    {
        if( prod[i].estado == OCUPADO && prod[i].importe < promedio)
        {
            contadorProdsMenosPromedio++;
            flag = 1;
        }
    }
    if( !flag )
    {
        printf("** No hay productos cargados en el sistema.\n\n");
    }
    else
    {
        xlkCenterPrintf("DATOS DE IMPORTES",1);
        xlkSortPrintf(1,"%s,%s",2,"SUMA DE IMPORTES:","PROMEDIO DE IMPORTES:");
        xlkSortPrintf(3,"%f,%f",2,acumulador,promedio);
        printf("\n* Hay %d productos que no superan el promedio de importes.\n\n",contadorProdsMenosPromedio);
    }

}


/** \brief Muestra cuantos productos tienen un stock menor o igual a 10.
 *
 * \param prod : Vector de productos.
 * \param prodTam : Tamaño del vector de productos.
 * \param prov : Vector de proveedores .
 * \param provTam : Tamaño del vector de proveedores .
 *
 */

void prodMostrarStocksMenorIgual10 ( eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    int contadorStock = 0;
    int i;
    xlkCenterPrintf("INFORME DEL STOCK DE PRODUCTOS",2);
    for (i = 0 ; i < prodTam ; i++)
    {
        if( prod[i].estado == OCUPADO && prod[i].cantidad <= 10)
        {
            contadorStock++;
        }
    }
    printf("\n* Hay %d productos con stock 10 o menor.\n\n",contadorStock);
}



/** \brief Muestra cuantos productos tienen un stock mayor a 10.
 *
 * \param prod : Vector de productos.
 * \param prodTam : Tamaño del vector de productos.
 * \param prov : Vector de proveedores.
 * \param provTam : Tamaño del vector de proveedores .
 *
 */

void prodMostrarStocksMayor10(eProductos prod[], int prodTam, eProveedores prov[], int provTam)
{
    system("cls");
    int contadorStock = 0;
    int i;
    xlkCenterPrintf("INFORME DEL STOCK DE PRODUCTOS",2);
    for (i = 0 ; i < prodTam ; i++)
    {
        if( prod[i].estado == OCUPADO && prod[i].cantidad > 10)
        {
            contadorStock++;
        }
    }
    printf("\n* Hay %d productos con stock mayor a 10.\n\n",contadorStock);
}


//FUNCIONES MENU LISTAR:



/** \brief Llista todos los productos ordenados por importe de manera descendente y por descripcion ascendente.
 *
 * \param prod : Vector de productos .
 * \param prodTam : Tamaño del vector de productos.
 * \param prov : Vector de proveedores .
 * \param provTam : Tamaño del vector de proveedores .
 *
 */

void ordenarProductos(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    eProductos aux;
    int i;
    int j;

    for( i = 0; i < prodTam-1; i++)
    {
        for( j = i+1; j<prodTam; j++)
        {
            if( prod[j].importe > prod[i].importe && prod[j].estado == OCUPADO && prod[i].estado == OCUPADO)
            {
                aux = prod[i];
                prod[i] = prod[j];
                prod[j] = aux;
            }
            else if( prod[j].importe == prod[i].importe && prod[j].estado == OCUPADO && prod[i].estado == OCUPADO)
            {
                if( stricmp(prod[j].descripcion, prod[i].descripcion) < 0)
                {
                    aux = prod[i];
                    prod[i] = prod[j];
                    prod[j] = aux;
                }
            }
        }
    }
    xlkCenterPrintf("LISTADO ORDENADO",1);
    if( !mostrarProductos(prod, prodTam, prov, provTam) )
    {
        printf("** No hay productos cargados.\n\n");
    }
}



/** \brief Lista los productos con un stock menor o igual a 10.
 *
 * \param prod : Vector de productos .
 * \param prodTam : Tamaño del vector de productos.
 * \param prov : Vector de proveedores .
 * \param provTam : Tamaño del vector de proveedores .
 *
 */

void ListarProdsCantMenorIgualA10(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    int i;
    int flag = 0;

    xlkCenterPrintf("PRODUCTOS CON STOCK MENOR O IGUAL A 10",1);
    xlkSortPrintf(1,"%s,%s,%s,%s,%s",5,"PROVEEDOR:","CODIGO DE PRODUCTO:","DESCRICPION:","IMPORTE:","CANTIDAD:");
    for (i = 0 ; i < prodTam ; i++)
    {
        if( prod[i].estado == OCUPADO && prod[i].cantidad <= 10)
        {
            flag = 1;
            mostrarProductoBuscarProv(prod[i],prov,provTam);
        }
    }
    if(!flag )
    {
        system("cls");
        printf("** No hay productos que cumplan lo solicitado.\n\n");
    }

}



/** \brief Lista los productos con un stock mayor a 10.
 *
 * \param prod : Vector de productos .
 * \param prodTam : Tamaño del vector de productos.
 * \param prov : Vector de proveedores .
 * \param provTam : Tamaño del vector de proveedores .
 *
 */

void ListarProdsCantMayorA10(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    int i;
    int flag = 0;
    xlkCenterPrintf("PRODUCTOS CON STOCK MAYOR A 10",1);
    xlkSortPrintf(1,"%s,%s,%s,%s,%s",5,"PROVEEDOR:","CODIGO DE PRODUCTO:","DESCRICPION:","IMPORTE:","CANTIDAD:");
    for (i = 0 ; i < prodTam ; i++)
    {
        if( prod[i].estado == OCUPADO && prod[i].cantidad > 10)
        {
            flag = 1;
            mostrarProductoBuscarProv(prod[i],prov,provTam);
        }
    }
    if(!flag )
    {
        system("cls");
        printf("** No hay productos que cumplan lo solicitado.\n\n");
    }

}



/** \brief Lista los productos con un importe mayor al promedio.
 *
 * \param prod : Vector de productos .
 * \param prodTam : Tamaño del vector de productos.
 * \param prov : Vector de proveedores .
 * \param provTam : Tamaño del vector de proveedores .
 *
 */

void ListarProdsImportesMayoresAlPromedio(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    float promedio ;
    float acumulador = 0;
    int contador = 0;
    int i;
    int flag = 0;

    for(i = 0 ; i < prodTam ; i++ )
    {
        if( prod[i].estado == OCUPADO)
        {
            acumulador += prod[i].importe ;
            contador++;
            flag = 1;
        }
    }
    if( !flag)
    {
        printf("** No hay productos cargados en el sistema.\n\n");
    }
    else
    {
        flag = 0;
        promedio = acumulador / contador ;
        xlkCenterPrintf("DATOS DE IMPORTES",1);
        xlkSortPrintf(1,"%s,%s",2,"SUMA DE IMPORTES:","PROMEDIO DE IMPORTES:");
        xlkSortPrintf(3,"%f,%f",2,acumulador,promedio);
        printf("\n");
        xlkCenterPrintf("PRODUCTOS QUE SUPERAN EL PROMEDIO DE LOS IMPORTES:",1);
        xlkSortPrintf(1,"%s,%s,%s,%s,%s",5,"PROVEEDOR:","CODIGO DE PRODUCTO:","DESCRICPION:","IMPORTE:","CANTIDAD:");

        for (i = 0 ; i < prodTam ; i++)
        {
            if( prod[i].estado == OCUPADO && prod[i].importe > promedio )
            {
                flag = 1;
                mostrarProductoBuscarProv(prod[i],prov,provTam);
            }
        }
        if(!flag)
        {
            system("cls");
            printf("**No hay productos que cumplan lo solicitado.\n\n");
        }
    }

}



/** \brief Lista los productos con un importe menor al promedio.
 *
 * \param prod : Vector de productos .
 * \param prodTam : Tamaño del vector de productos.
 * \param prov : Vector de proveedores .
 * \param provTam : Tamaño del vector de proveedores .
 *
 */

void ListarProdsImportesMenoresAlPromedio(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    float promedio ;
    float acumulador = 0;
    int contador = 0;
    int i;
    int flag = 0;

    for(i = 0 ; i < prodTam ; i++ )
    {
        if( prod[i].estado == OCUPADO)
        {
            acumulador += prod[i].importe ;
            contador++;
            flag = 1;
        }
    }
    if( !flag)
    {
        printf("** No hay productos cargados en el sistema.\n\n");
    }
    else
    {
        flag = 0;
        promedio = acumulador / contador ;
        xlkCenterPrintf("DATOS DE IMPORTES",1);
        xlkSortPrintf(1,"%s,%s",2,"SUMA DE IMPORTES:","PROMEDIO DE IMPORTES:");
        xlkSortPrintf(3,"%f,%f",2,acumulador,promedio);
        printf("\n");
        xlkCenterPrintf("PRODUCTOS QUE NO SUPERAN EL PROMEDIO DE LOS IMPORTES:",1);
        xlkSortPrintf(1,"%s,%s,%s,%s,%s",5,"PROVEEDOR:","CODIGO DE PRODUCTO:","DESCRICPION:","IMPORTE:","CANTIDAD:");
        for (i = 0 ; i < prodTam ; i++)
        {
            if( prod[i].estado == OCUPADO && prod[i].importe < promedio)
            {
                flag = 1;
                mostrarProductoBuscarProv(prod[i],prov,provTam);
            }
        }
         if(!flag)
        {
            system("cls");
            printf("**No hay productos que cumplan lo solicitado.\n\n");
        }
    }
}



/** \brief Lista los proveedores que proveen menos de 10 productos
 *
 * \param prod : Vector de productos .
 * \param prodTam : Tamaño del vector de productos.
 * \param prov : Vector de proveedores .
 * \param provTam : Tamaño del vector de proveedores .
 *
 */

void ListarProvsCantidadProdMenorIgualA10(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    int i;
    int j;
    int flag = 0;
    int acumulador = 0;
    xlkCenterPrintf("PROVEEDORES CON 10 O MENOS PRODUCTOS EN EL SISTEMA",1);
    for( i = 0 ; i < provTam ; i++)
    {
        if( prov[i].estado == OCUPADO )
        {
            for( j = 0 ; j < prodTam ; j++)
            {
                if( prod[j].estado == OCUPADO && prod[j].codigoProveedor == prov[i].codigoProveedor )
                {
                    acumulador += prod[j].cantidad;
                }
                if( j == (prodTam - 1) )
                {
                    if( acumulador <= 10 && prov[i].codigoProveedor > 0)
                    {
                        flag = 1;
                        xlkSortPrintf(1,"%s,%s,%s",3,"PROVEEDOR:","CANTIDAD DE PRODUCTOS QUE PROVEE:","ID DE PROVEEDOR:");
                        xlkSortPrintf(3,"%s,%d,%d",3,prov[i].descripcion,acumulador,prov[i].codigoProveedor);
                    }
                    acumulador = 0;
                }
            }
        }
    }
    if( flag == 0)
    {
        system("cls");
        printf("** No hay proveedores que provean 10 o menos productos.\n\n");
    }
}



/** \brief Lista los productos con su respectivo proveedor.
 *
 * \param prod : Vector de productos .
 * \param prodTam : Tamaño del vector de productos.
 * \param prov : Vector de proveedores .
 * \param provTam : Tamaño del vector de proveedores .
 *
 */

void ListarProductorPorProveedor(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    int i;
    int j;
    int flag = 0;
    int flag2 = 0; //Revisa si se leyo algun producto.

    xlkCenterPrintf("LISTADO DE PRODUCTOS",1);
    for(i = 0 ; i < provTam; i++)
    {
        if(prov[i].estado == OCUPADO)
        {
            for(j = 0; j < prodTam ; j++)
            {
                if(prod[j].estado == OCUPADO && prod[j].codigoProveedor == prov[i].codigoProveedor && prov[i].codigoProveedor > 0)
                {
                    flag2=1;
                    if( flag == 0)
                    {
                        xlkSortPrintf(1,"%s,%s",2,"PRODUCTOS DEL PROVEEDOR--->",prov[i].descripcion);
                        xlkSortPrintf(1,"%s,%s,%s,%s",4,"DESCRICPION:","CODIGO DE PRODUCTO:","IMPORTE:","CANTIDAD:");
                        flag=1;
                    }
                    mostrarProducto(prod[j],prov[i]);
                }

            }
            flag = 0;
        }
    }
    if(!flag2 )
    {
        system("cls");
        printf("** No hay productos cargados o no se registro un proveedor.\n\n");
    }
}



/** \brief Lista los productos de un proveedor a eleccion del usuario.
 *
 * \param prod : Vector de productos .
 * \param prodTam : Tamaño del vector de productos.
 * \param prov : Vector de proveedores .
 * \param provTam : Tamaño del vector de proveedores .
 *
 */

void ListarProductosDeUnProveedor(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    int buscarCodigo;
    int provIndex;
    int i;
    int flag = 0;

    if( mostrarProveedores(prov,provTam) )
    {
        if( getConditionedInt(&buscarCodigo,1,1,"\n* Ingrese el codigo de proveedor para mostrar sus productos: ","\n** El codigo de proveedor es invalido.\n\n") )
        {
            if( ( provIndex = buscarProveedor(prov,provTam,buscarCodigo)) > -1 )
            {
                system("cls");
                xlkSortPrintf(1,"%s,%s",2,"PRODUCTOS DEL PROVEEDOR--->",prov[provIndex].descripcion);
                xlkSortPrintf(1,"%s,%s,%s,%a",4,"DESCRICPION:","CODIGO DE PRODUCTO:","IMPORTE:","CANTIDAD:");

                for( i = 0; i < prodTam ; i++ )
                {
                    if( prod[i].estado == OCUPADO && prod[i].codigoProveedor == prov[provIndex].codigoProveedor )
                    {
                        mostrarProducto(prod[i], prov[provIndex]);
                        flag = 1;
                    }
                }
                if(flag == 0)
                {
                    system("cls");
                    printf("** El proveedor no provee ningun producto.\n\n");
                }
            }
            else
            {
                printf("\n** No se pudo encontrar el proveedor especificado.\n\n");
            }
        }
    }
    else
    {
        system("cls");
        printf("** No hay proveedores cargados.\n\n");
    }
}



/** \brief Lista el proveedor que provee mas productos y sus productos.
 *
 * \param prod : Vector de productos .
 * \param prodTam : Tamaño del vector de productos.
 * \param prov : Vector de proveedores .
 * \param provTam : Tamaño del vector de proveedores .
 *
 */

void ListarProveedorMasProductos(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    int i;
    int j;
    int flag = 0;

    int cantidadProductos1 = 0;
    int cantidadProductos2;
    int provIndex = -1;

    system("cls");
    for(i = 0 ; i < provTam ; i++ )
    {
        if( prov[i].estado == OCUPADO)
        {
            for( j = 0; j < prodTam ; j++)
            {
                if( prod[j].estado == OCUPADO && prod[j].codigoProveedor == prov[i].codigoProveedor)
                {
                    cantidadProductos1++;
                }
                if( (j == (prodTam - 1) && flag == 0) || (j == (prodTam -1) && cantidadProductos1 > cantidadProductos2 ))
                {
                    flag = 1;
                    cantidadProductos2 = cantidadProductos1;
                    if( cantidadProductos2 > 0)
                    {
                        provIndex = i;
                    }
                }
                if( j == prodTam - 1)
                {
                    cantidadProductos1 = 0;
                }
            }
        }
    }
    if(provIndex > -1 && prov[provIndex].codigoProveedor > 0 )
    {
        xlkCenterPrintf("PROVEEDOR QUE PROVEE MAS PRODUCTOS Y SUS PRODUCTOS",1);
        xlkSortPrintf(1,"%s,%s",2,"PRODUCTOS DEL PROVEEDOR--->",prov[provIndex].descripcion);
        xlkSortPrintf(1,"%s,%s,%s,%s,%s",5,"PROVEEDOR:","DESCRICPION:","CODIGO DE PRODUCTO:","IMPORTE:","CANTIDAD:");

        for( i = 0 ; i < prodTam ; i++)
        {
            if( prod[i].estado == OCUPADO && prod[i].codigoProveedor == prov[provIndex].codigoProveedor)
            {
                mostrarProducto(prod[i], prov[provIndex]);
            }
        }
    }
    else
    {
        system("cls");
        printf("** No hay productos que esten asociados a algun proveedor.\n\n");
    }
}



/** \brief Lista el proveedor que provee menos productos y sus productos.
 *
 * \param prod : Vector de productos .
 * \param prodTam : Tamaño del vector de productos.
 * \param prov : Vector de proveedores .
 * \param provTam : Tamaño del vector de proveedores .
 *
 */

void ListarProveedorMenosProductos(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    int i;
    int j;
    int flag = 0;

    int cantidadProductos1 = 0;
    int cantidadProductos2 = 0;
    int provIndex;

    system("cls");
    for(i = 0 ; i < provTam ; i++ )
    {
        if( prov[i].estado == OCUPADO)
        {
            for( j = 0; j < prodTam ; j++)
            {
                if( prod[j].estado == OCUPADO && prod[j].codigoProveedor == prov[i].codigoProveedor)
                {
                    cantidadProductos1++;
                }
                if( (j == (prodTam - 1) && flag == 0) || (j == (prodTam -1) && cantidadProductos1 < cantidadProductos2 ))
                {
                    if( cantidadProductos1 > 0)
                    {
                        flag = 1;
                        cantidadProductos2 = cantidadProductos1;
                        provIndex = i;
                        cantidadProductos1 = 0;
                    }
                }
                if( j == prodTam - 1)
                {
                    cantidadProductos1 = 0;
                }

            }
        }
    }
    if(cantidadProductos2 > 0 && prov[provIndex].codigoProveedor > 0 )
    {
        xlkCenterPrintf("PROVEEDOR QUE PROVEE MENOS PRODUCTOS Y SUS PRODUCTOS",1);
        xlkSortPrintf(1,"%s,%s",2,"PRODUCTOS DEL PROVEEDOR--->",prov[provIndex].descripcion);
        xlkSortPrintf(1,"%s,%s,%s,%s",4,"DESCRICPION:","CODIGO DE PRODUCTO:","IMPORTE:","CANTIDAD:");
        for( i = 0 ; i < prodTam ; i++)
        {
            if( prod[i].estado == OCUPADO && prod[i].codigoProveedor == prov[provIndex].codigoProveedor)
            {
                mostrarProducto(prod[i], prov[provIndex]);
            }
        }
    }
    else
    {
        printf("** Los proveedores cargados no proveen ningun producto.\n\n");
    }
}



/** \brief Lista el proveedor que provee el producto mas caro y sus productos.
 *
 * \param prod : Vector de productos .
 * \param prodTam : Tamaño del vector de productos.
 * \param prov : Vector de proveedores .
 * \param provTam : Tamaño del vector de proveedores .
 *
 */

void ListarProveedorProductoMasCaro(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    float importeMasAlto = -1;
    int provIndex;
    int flag = 0;
    int flag2 = 0; //Verifica si leyo algun dato.
    int i;
    int j;

    for(i = 0 ; i < provTam ; i++ )
    {
        if( prov[i].estado == OCUPADO)
        {
            for( j = 0; j < prodTam ; j++)
            {
                if( prod[j].estado == OCUPADO && prod[j].codigoProveedor == prov[i].codigoProveedor && prod[j].codigoProveedor)
                {
                    flag2 = 1;
                    if( flag == 0)
                    {
                        importeMasAlto = prod[j].importe;
                        provIndex = i;
                        flag = 1;
                    }
                    if( prod[j].importe > importeMasAlto)
                    {
                        importeMasAlto = prod[j].importe;
                        provIndex = i;
                    }
                }

            }
        }
    }
    if( !flag2 )
    {
        printf("** No hay productos cargados en el sistema.\n\n");
    }
    else
    {
        xlkCenterPrintf("PROVEEDOR QUE PROVEE PRODUCTO MAS CARO",1);
        xlkSortPrintf(1,"%s,%s",2,"PRODUCTOS DEL PROVEEDOR->",prov[provIndex].descripcion);
        xlkSortPrintf(1,"%s,%s,%s,%s",4,"DESCRICPION:","CODIGO DE PRODUCTO:","IMPORTE:","CANTIDAD:");

        for(i = 0 ; i < prodTam ; i++)
        {
            if( prod[i].estado == OCUPADO && prod[i].codigoProveedor == prov[provIndex].codigoProveedor && prov[provIndex].codigoProveedor > 0)
            {
                xlkSortPrintf(3,"%s,%d,%f,%d",4,prod[i].descripcion,prod[i].codigoProduto,prod[i].importe, prod[i].cantidad);
            }
        }
    }
}



/** \brief Lista el proveedor que provee el producto mas barato y sus productos.
 *
 * \param prod : Vector de productos .
 * \param prodTam : Tamaño del vector de productos.
 * \param prov : Vector de proveedores .
 * \param provTam : Tamaño del vector de proveedores .
 *
 */

void ListarProveedorProductoMasBarato(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    float importeMasBajo = -1;
    int provIndex;
    int flag = 0;
    int flag2 = 0; //Verifica si se leyo algun dato.
    int i;
    int j;


    for(i = 0 ; i < provTam ; i++ )
    {
        if( prov[i].estado == OCUPADO)
        {
            for( j = 0; j < prodTam ; j++)
            {
                if( prod[j].estado == OCUPADO && prod[j].codigoProveedor == prov[i].codigoProveedor && prod[j].codigoProveedor > 0 )
                {
                    flag2 = 1;
                    if( flag == 0)
                    {
                        importeMasBajo = prod[j].importe;
                        provIndex = i;

                        flag = 1;
                    }
                    if( prod[j].importe < importeMasBajo)
                    {
                        importeMasBajo = prod[j].importe;
                        provIndex = i;
                    }
                }

            }
        }
    }
    if( !flag2 )
    {
        printf("** No hay productos cargados en el sistema.\n\n");
    }
    else
    {
        xlkCenterPrintf("PROVEEDOR QUE PROVEE PRODUCTO MAS BARATO",1);
        xlkSortPrintf(1,"%s,%s",2,"PRODUCTOS DEL PROVEEDOR--->",prov[provIndex].descripcion);
        xlkSortPrintf(1,"%s,%s,%s,%s",3,"DESCRICPION:","CODIGO DE PRODUCTO:","IMPORTE:","CANTIDAD:");
        for(i = 0 ; i < prodTam ; i++)
        {
            if( prod[i].estado == OCUPADO && prod[i].codigoProveedor == prov[provIndex].codigoProveedor && prov[provIndex].codigoProveedor > 0)
            {
                xlkSortPrintf(3,"%s,%d,%f,%d",3,prod[i].descripcion,prod[i].codigoProduto,prod[i].importe, prod[i].cantidad);
            }
        }
    }
}
