#include <stdio.h>
#include <stdlib.h>

#include "xget.h"
#include "xlook.h"
#include "xstring.h"

#include "xProductos-Proveedores.h"
#include "xProductos.h"
#include "xProveedores.h"

#define LIBRE 0
#define OCUPADO 1


//Funciones de menu:

void altaMenu(eProductos prods[],int prodTam,int* codigoProducto,eProveedores provs[],int provTam,int* codigoProveedor)
{
    int quit = 0;
    int selection;

    do
    {
        xlkIndexGenerator("Menu altas",3,"1-Alta producto.","2-Alta proveedor.","0-Salir");
        if( getRangedInt(&selection,0,2," -Seleccionar opcion: ","** Opcion invalida.") )
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
                break;
            case 0:
                system("cls");
                quit = 1;
                break;
            }
        }
        system("pause");
    }
    while( quit == 0);
}

void bajaMenu(eProductos prods[],int prodTam,eProveedores provs[],int provTam)
{
    int quit = 0;
    int selection;
    int reading;

    do
    {
        xlkIndexGenerator("Menu bajas",3,"1-baja producto.","2-baja proveedor.","0-Salir");
        if( getRangedInt(&selection,0,2," -Seleccionar opcion: ","** Opcion invalida.") )
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
                    printf("* Accion cancelada.No se realizo ninguna baja.\n\n");
                }
                else
                {
                    printf("* No se ha encontrado el producto que busca.\n\n");
                }
                break;
            case 2:
                reading = bajaProveedor(provs,provTam);
                if( reading == 1)
                {
                    printf("* Proveedor dado de baja del sistema.\n\n");
                }
                else if( reading == 0)
                {
                    printf("* Accion cancelada. No se realizo ninguna baja.\n\n");
                }
                else
                {
                    printf("* No se ha encontrado el proveedor que busca.\n\n");
                }
                break;
            case 0:
                system("cls");
                quit = 1;
                break;
            }
        }
        system("pause");
    }
    while( !quit);
}



void modificacionMenu(eProductos prods[],int prodTam,eProveedores provs[],int provTam)
{
    int quit = 0;
    int selection;
    int reading;

    do
    {
        xlkIndexGenerator("Menu bajas",3,"1-Modificar producto.","2-Modificar proveedor.","0-Salir");
        if( getRangedInt(&selection,0,2," -Seleccionar opcion: ","** Opcion invalida.") )
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
                else
                {
                    printf("* No se ha encontrado el producto que busca.\n\n");
                }
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
                else
                {
                    printf("* No se ha encontrado el producto que busca.\n\n");
                }
                break;
            case 0:
                system("cls");
                quit = 1;
                break;
            }
        }
        system("pause");
    }
    while( !quit);
}



void mostrarMenuInformar( eProductos prods[], int prodTam, eProveedores provs[], int provTam )
{
    int seleccion ;
    int exit = 0;

    do
    {
        xlkIndexGenerator("Informes",5,"1-Total y promedio de importes, productos que lo superan.","2-Total y promedio de importes, productos que NO lo superan.","3-Cantidad de productos con stock menor o igual a 10.","4-Cantidad de productos con stock mayor a 10.","0-Volver.");
        if( getRangedInt(&seleccion,0,4," -Seleccionar opcion: ","**Opcion invalida.\n\n") )
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
        }
        system("pause");

    }
    while( !exit);
}


void mostrarMenuListar( eProductos prods[], int prodTam, eProveedores provs[], int provTam )
{
    int seleccion ;
    int exit = 0;

    do
    {
        xlkIndexGenerator("Informes",13,"1-Ordenar productos.","2-Mostrar productos con stock menor o igual a 10.","3-Mostrar productos con stock mayor a 10.","4-Mostrar productos que superan el promedio de importes.","5-Mostrar productos que NO superan el promedio de importes.","6-Mostrar proveedor n eo de importghfes.","7-Mostrar productos por proveedor.","8-Mostrar productos de un proveedor determinado.", "9-Mostrar proveedor que provee mas productos.","10-Mostrar proveedor que provee menos productos.","11-Mostrar proveedor del producto mas caro.","12-Mostrar proveedor del producto mas barato.","0-Volver.");
        if( getRangedInt(&seleccion,0,12," -Seleccionar opcion: ","**Opcion invalida.\n\n") )
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
        }
        system("pause");

    }
    while( !exit);
}

//FUNCIONES MENU INFORMAR:



/** \brief Obtiene la suma y el promedio de los importes de todos los productos cargados y muestra los productos cuyo importe supera ese promedio.
 *
 * \param prod : Vector de productos asociado.
 * \param prodTam : Tamaño del vector de productos asociado.
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
    int contadorProdsMasPromedio = 0;
    int i;

    for(i = 0 ; i < prodTam ; i++ )
    {
        if( prod[i].estado == OCUPADO)
        {
            acumulador += prod[i].importe ;
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

    xlkCenterPrintf("DATOS DE IMPORTES",1);
    xlkSortPrintf(1,"%s,%s",2,"SUMA DE IMPORTES:","PROMEDIO DE IMPORTES:");
    xlkSortPrintf(3,"%f,%f",2,acumulador,promedio);
    xlkCenterPrintf("PRODUCTOS CON IMPORTES MAYORES AL PROMEDIO",1);
    printf("%d productos.",contadorProdsMasPromedio);
}





/** \brief Obtiene la suma y el promedio de los importes de todos los productos cargados y muestra los productos cuyo importe NO supera ese promedio.
 *
 * \param prod : Vector de productos asociado.
 * \param prodTam : Tamaño del vector de productos asociado.
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
        }
    }

    xlkCenterPrintf("DATOS DE IMPORTES",1);
    xlkSortPrintf(1,"%s,%s",2,"SUMA DE IMPORTES:","PROMEDIO DE IMPORTES:");
    xlkSortPrintf(3,"%f,%f",2,acumulador,promedio);
    xlkCenterPrintf("PRODUCTOS CON IMPORTES MENORES AL PROMEDIO",1);
    printf("%d productos.",contadorProdsMenosPromedio);
}


/** \brief Muestra productos con stock menor o igual a 10.
 *
 * \param prod : Vector de productos asociado.
 * \param prodTam : Tamaño del vector de productos asociado.
 * \param prov : Vector de proveedores .
 * \param provTam : Tamaño del vector de proveedores .
 *
 */

void prodMostrarStocksMenorIgual10 ( eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    int contadorStock = 0;
    int i;

    for (i = 0 ; i < prodTam ; i++)
    {
        if( prod[i].estado == OCUPADO && prod[i].cantidad <= 10)
        {
            contadorStock++;
        }
    }
    xlkCenterPrintf("PRODUCTOS CON STOCK MENOR O IGUAL A 10",1);
    printf("%d productos.",contadorStock);
}



/** \brief Muestra productos con stock mayor a 10.
 *
 * \param prod : Vector de productos asociado.
 * \param prodTam : Tamaño del vector de productos asociado.
 * \param prov : Vector de proveedores .
 * \param provTam : Tamaño del vector de proveedores .
 *
 */

void prodMostrarStocksMayor10(eProductos prod[], int prodTam, eProveedores prov[], int provTam)
{
    system("cls");
    int contadorStock = 0;
    int i;

    for (i = 0 ; i < prodTam ; i++)
    {
        if( prod[i].estado == OCUPADO && prod[i].cantidad > 10)
        {
            contadorStock++;
        }
    }
    xlkCenterPrintf("PRODUCTOS CON STOCK MAYOR A 10",1);
    printf("%d productos.",contadorStock);
}


//FUNCIONES MENU LISTAR:


void ordenarProductos(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    eProductos aux;
    int i;
    int j;

    for( i = 0; i < prodTam-1; i++)
    {
        for( j = i+1; j<prodTam; j++)
        {
            if( prod[j].importe > prod[i].importe)
            {
                aux = prod[i];
                prod[i] = prod[j];
                prod[j] = aux;
            }
            else if( prod[j].importe == prod[i].importe)
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
    xlkCenterPrintf("LISTADO ORDENADO DE PRODUCTOS",1);
    mostrarProductos(prod, prodTam, prov, provTam);
}


void ListarProdsCantMenorIgualA10(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    int i;

    xlkCenterPrintf("PRODUCTOS CON STOCK MENOR O IGUAL A 10",1);
    xlkSortPrintf(1,"%s,%s,%s,%s,%s",5,"PROVEEDOR:","DESCRICPION:","CODIGO DE PRODUCTO:","IMPORTE:","CANTIDAD:");
    for (i = 0 ; i < prodTam ; i++)
    {
        if( prod[i].estado == OCUPADO && prod[i].cantidad <= 10)
        {
            mostrarProducto(prod[i],prov,provTam);
        }
    }
}

void ListarProdsCantMayorA10(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    int i;
    xlkCenterPrintf("PRODUCTOS CON STOCK MAYOR A 10",1);
    xlkSortPrintf(1,"%s,%s,%s,%s,%s",5,"PROVEEDOR:","DESCRICPION:","CODIGO DE PRODUCTO:","IMPORTE:","CANTIDAD:");
    for (i = 0 ; i < prodTam ; i++)
    {
        if( prod[i].estado == OCUPADO && prod[i].cantidad > 10)
        {
            mostrarProducto(prod[i],prov,provTam);
        }
    }
}


void ListarProdsImportesMayoresAlPromedio(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    float promedio ;
    float acumulador = 0;
    int contador = 0;
    int i;

    for(i = 0 ; i < prodTam ; i++ )
    {
        if( prod[i].estado == OCUPADO)
        {
            acumulador += prod[i].importe ;
            contador++;
        }
    }
    promedio = acumulador / contador ;

    xlkCenterPrintf("DATOS DE IMPORTES",1);
    xlkSortPrintf(1,"%s,%s",2,"SUMA DE IMPORTES:","PROMEDIO DE IMPORTES:");
    xlkSortPrintf(3,"%f,%f",2,acumulador,promedio);
    printf("\n");
    xlkCenterPrintf("PRODUCTOS QUE SUPERAN EL PROMEDIO DE LOS IMPORTES:",1);
    xlkSortPrintf(1,"%s,%s,%s,%s,%s",5,"PROVEEDOR:","CODIGO DE PRODUCTO:","DESCRICPION:","IMPORTE:","CANTIDAD:");

    for (i = 0 ; i < prodTam ; i++)
    {
        if( prod[i].estado == OCUPADO && prod[i].importe > promedio)
        {
            mostrarProducto(prod[i],prov,provTam);
        }
    }
}


void ListarProdsImportesMenoresAlPromedio(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    float promedio ;
    float acumulador = 0;
    int contador = 0;
    int i;

    for(i = 0 ; i < prodTam ; i++ )
    {
        if( prod[i].estado == OCUPADO)
        {
            acumulador += prod[i].importe ;
            contador++;
        }
    }
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
            mostrarProducto(prod[i],prov,provTam);
        }
    }
}


void ListarProvsCantidadProdMenorIgualA10(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{

}

void ListarProductorPorProveedor(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    int i;
    int j;
    int flag = 0;
    xlkCenterPrintf("LISTADO DE PRODUCTOS",1);
    for(i = 0 ; i < provTam; i++)
    {
        if(prov[i].estado == OCUPADO)
        {
            for(j = 0; j < prodTam ; j++)
            {
                if(prod[j].estado == OCUPADO && prod[j].codigoProveedor == prov[i].codigoProveedor)
                {
                    if( flag == 0)
                    {
                        xlkSortPrintf(1,"%s,%s",2,"PRODUCTOS DEL PROVEEDOR->",prov[i].descripcion);
                        xlkSortPrintf(1,"%s,%s,%s,%s",4,"DESCRICPION:","CODIGO DE PRODUCTO:","IMPORTE:","CANTIDAD:");
                        flag++;
                    }
                    xlkSortPrintf(3,"%s,%d,%f,%d",4,prod[i].descripcion,prod[i].codigoProduto,prod[i].importe, prod[i].cantidad);
                }

            }
            flag = 0;
        }
    }
}

void ListarProductosDeUnProveedor(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    int buscarCodigo;
    int provIndex;
    int i;
    mostrarProveedores(prov,provTam);
    if( getConditionedInt(&buscarCodigo,0,1,"* Ingrese el codigo de proveedor para mostrar sus productos: ","\n** El codigo de proveedor es invalido.") )
    {
        if( ( provIndex = buscarProveedor(prov,provTam,buscarCodigo)) > -1 )
        {
            xlkSortPrintf(1,"%s,%s",2,"PRODUCTOS DEL PROVEEDOR->",prov[provIndex].descripcion);
            xlkSortPrintf(1,"%s,%s,%s,%a",4,"DESCRICPION:","CODIGO DE PRODUCTO:","IMPORTE:","CANTIDAD:");

            for( i = 0; i < prodTam ; i++ )
            {
                if( prod[i].estado == OCUPADO && prod[i].codigoProveedor == prov[provIndex].codigoProveedor )
                {
                    xlkSortPrintf(3,"%s,%d,%f,%d",3,prod[i].descripcion,prod[i].codigoProduto,prod[i].importe, prod[i].cantidad);
                }
            }
        }
        else
        {
            printf("\n** No se pudo encontrar el proveedor especificado.\n\n");
        }
    }
}



void ListarProveedorMasProductos(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");

    int i;
    int j;
    int flag = 0;
    int contadorProductos[provTam];
    int provIndex;
    int proveedorCantidadProductos;

    for( i = 0 ; i < provTam ; i++ )
    {
        contadorProductos[i] = 0;
    }


    for(i = 0 ; i < provTam ; i++ )
    {
        if( prov[i].estado == OCUPADO)
        {
            for( j = 0; j < prodTam ; j++)
            {
                if( prod[j].estado == OCUPADO && prod[j].codigoProveedor == prov[i].codigoProveedor)
                {
                    contadorProductos[i]++;

                }
            }
        }
    }

    for( i = 0; i < provTam ; i++)
    {
        if( (flag == 0 && contadorProductos[i] > -1) || ( flag == 1 && contadorProductos[i] > proveedorCantidadProductos) )
        {
            proveedorCantidadProductos = contadorProductos[i];
            provIndex = i;
            flag = 1;
        }
    }

    xlkCenterPrintf("PROVEEDOR QUE PROVEE MAS PRODUCTOS Y SUS PRODUCTOS",1);

    if(prov[provIndex].codigoProveedor != 0 && proveedorCantidadProductos != 0 )
    {
        xlkSortPrintf(1,"%s,%s",2,"PRODUCTOS DEL PROVEEDOR->",prov[provIndex].descripcion);
        xlkSortPrintf(1,"%s,%s,%s,%s",4,"DESCRICPION:","CODIGO DE PRODUCTO:","IMPORTE:","CANTIDAD:");

        for( i = 0 ; i < prodTam ; i++)
        {
            if( prod[i].estado == OCUPADO && prod[i].codigoProveedor == prov[provIndex].codigoProveedor)
            {
                xlkSortPrintf(3,"%s,%d,%f,%d",4,prod[i].descripcion,prod[i].codigoProduto,prod[i].importe, prod[i].cantidad);
            }
        }
    }
    else
    {
        printf("No hay proveedores que provean productos.");
    }
}


void ListarProveedorMenosProductos(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");

    int flag = 0;
    int i;
    int j;
    int contadorProductos[provTam];
    int provIndex;
    int proveedorCantidadProductos = -1;

    for( i = 0 ; i < provTam ; i++ )
    {
        contadorProductos[i] = 0;
    }


    for(i = 0 ; i < provTam ; i++ )
    {
        if( prov[i].estado == OCUPADO)
        {
            for( j = 0; j < prodTam ; j++)
            {
                if( prod[j].estado == OCUPADO && prod[j].codigoProveedor == prov[i].codigoProveedor)
                {
                    contadorProductos[i]++;


                }
            }
        }
    }

    for( i = 0; i < provTam ; i++)
    {
        if( (flag == 0 && prov[i].estado == OCUPADO )|| (contadorProductos[i] < proveedorCantidadProductos && prov[i].estado == OCUPADO)  )
        {
            if( prov[i].codigoProveedor != 0)
            {
                proveedorCantidadProductos = contadorProductos[i];
                provIndex = i;
                flag = 1;
            }

        }
    }

    xlkCenterPrintf("PROVEEDOR QUE PROVEE MENOS PRODUCTOS Y SUS PRODUCTOS",1);

    if(prov[provIndex].codigoProveedor != 0 )
    {
        xlkSortPrintf(1,"%s,%s",2,"PRODUCTOS DEL PROVEEDOR->",prov[provIndex].descripcion);
        xlkSortPrintf(1,"%s,%s,%s,%s",4,"DESCRICPION:","CODIGO DE PRODUCTO:","IMPORTE:","CANTIDAD:");

        for( i = 0 ; i < prodTam ; i++)
        {
            if( prod[i].estado == OCUPADO && prod[i].codigoProveedor == prov[provIndex].codigoProveedor)
            {
                xlkSortPrintf(3,"%s,%d,%f,%d",4,prod[i].descripcion,prod[i].codigoProduto,prod[i].importe, prod[i].cantidad);
            }
        }
    }
}


void ListarProveedorProductoMasCaro(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    float importeMasAlto = -1;
    int provIndex;
    int flag = 0;
    int i;
    int j;


    for(i = 0 ; i < provTam ; i++ )
    {
        if( prov[i].estado == OCUPADO)
        {
            for( j = 0; j < prodTam ; j++)
            {
                if( prod[j].estado == OCUPADO )
                {
                    if( flag == 0)
                    {
                        importeMasAlto = prod[j].importe;
                        provIndex = i;
                        flag = 1;
                    }
                    if( prod[j].importe > importeMasAlto)
                    {
                         printf("PROVEEDOR %d IMPORTE %.2f PRODUCTO %d\n\n",i,importeMasBajo,j);
                        importeMasAlto = prod[j].importe;
                        provIndex = i;
                    }
                }

            }
        }
    }

    xlkCenterPrintf("PROVEEDOR QUE PROVEE PRODUCTO MAS CARO",1);
    xlkSortPrintf(1,"%s,%s",2,"PRODUCTOS DEL PROVEEDOR->",prov[provIndex].descripcion);
    xlkSortPrintf(1,"%s,%s,%s,%s",4,"DESCRICPION:","CODIGO DE PRODUCTO:","IMPORTE:","CANTIDAD:");

    for(i = 0 ; i < prodTam ; i++)
    {
        if( prod[i].estado == OCUPADO && prod[i].codigoProveedor == prov[provIndex].codigoProveedor)
        {
            xlkSortPrintf(3,"%s,%d,%f,%d",4,prod[i].descripcion,prod[i].codigoProduto,prod[i].importe, prod[i].cantidad);
        }
    }
}

void ListarProveedorProductoMasBarato(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    float importeMasBajo = -1;
    int provIndex;
    int flag = 0;
    int i;
    int j;


    for(i = 0 ; i < provTam ; i++ )
    {
        if( prov[i].estado == OCUPADO)
        {
            for( j = 0; j < prodTam ; j++)
            {
                if( prod[j].estado == OCUPADO )
                {
                    if( flag == 0)
                    {
                        importeMasBajo = prod[j].importe;
                        provIndex = i;

                        flag = 1;
                    }
                    printf("PROVEEDOR %d IMPORTE %.2f PRODUCTO %d\n\n",i,importeMasBajo,j);
                    if( prod[j].importe < importeMasBajo)
                    {
                        importeMasBajo = prod[j].importe;
                        printf("PROVEEDOR %d IMPORTE %.2f PRODUCTO %d\n\n",i,importeMasBajo,j);
                        provIndex = i;
                    }
                }

            }
        }
    }

    xlkCenterPrintf("PROVEEDOR QUE PROVEE PRODUCTO MAS BARATO",1);
    xlkSortPrintf(1,"%s,%s",2,"PRODUCTOS DEL PROVEEDOR->",prov[provIndex].descripcion);
    xlkSortPrintf(1,"%s,%s,%s,%s",3,"DESCRICPION:","CODIGO DE PRODUCTO:","IMPORTE:","CANTIDAD:");

    for(i = 0 ; i < prodTam ; i++)
    {
        if( prod[i].estado == OCUPADO && prod[i].codigoProveedor == prov[provIndex].codigoProveedor)
        {
            xlkSortPrintf(3,"%s,%d,%f,%d",3,prod[i].descripcion,prod[i].codigoProduto,prod[i].importe, prod[i].cantidad);
        }
    }
}
