#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xEmpleados.h"
#include "xget.h"
#include "xvalidate.h"
#include "xstring.h"
#include "xlook.h"


// Funciones de HARCODEO de estructuras:

// eProductos :


//XE1-1
/** \brief Carga datos a modo hardcode en los 3 primeros indices de un vector de PRODUCTOS .
 *
 * \param prod : Vector de PRODUCTOS a hardcodear.
 * \return
 *
 */

void harcodearProd( eProductos prod[] )
{
    strcpy( prod[1].descripcion , "Leito");
    prod[1].importe = 25445;
    prod[1].codigoProducto = 2525;
    prod[1].codigoProveedor = 1;
    prod[1].isBusy = 1;

    strcpy( prod[0].descripcion , "Nancy");
    prod[0].importe = 28456;
    prod[0].codigoProducto = 2526;
    prod[0].codigoProveedor = 1;
    prod[0].isBusy = 1;

    strcpy( prod[2].descripcion , "Nahuel");
    prod[2].importe = 30456;
    prod[2].codigoProducto = 2527;
    prod[2].codigoProveedor = 1;
    prod[2].isBusy = 1;
}



// eProveedores :


//XE1-2
/** \brief Carga datos a modo hardcode en los 5 primeros indices de un vector de PROVEEDORES .
 *
 * \param prov : Vector de PROVEEDORES a hardcodear
 * \return
 *
 */

void harcodearProv( eProveedores prov[] )
{
    prov[0].codigoProveedor = 1;
    prov[1].codigoProveedor = 2;
    prov[2].codigoProveedor = 3;
    prov[3].codigoProveedor = 4;
    prov[4].codigoProveedor = 5;
    strcpy( prov[0].descripcion,"RRHH");
    strcpy( prov[1].descripcion,"Sistemas");
    strcpy( prov[2].descripcion,"Administracion");
    strcpy( prov[3].descripcion,"Deposito");
    strcpy( prov[4].descripcion,"Compras");
    prov[0].isBusy = 1;
    prov[1].isBusy = 1;
    prov[2].isBusy = 1;
    prov[3].isBusy = 1;
    prov[4].isBusy = 1;
}



//Funciones exclusivas eProductos :

//Basico:


//XE1-3
/** \brief Inicializa el estado de los PRODUCTOS de un vector en 0 para ser leidos como desocupados.
 *
 * \param prod : Vector de PRODUCTOS a inicializar.
 * \param prodTam : Cantidad de elementos del vector de PRODUCTOS .
 * \return
 *
 */

void inicializarProductos( eProductos prod[], int prodTam )
{
    for(int i=0; i < prodTam ; i++)
    {
        prod[i].isBusy = 0;
    }
}



//Funciones de muestra:


//XE1-4
/** \brief muestra a todos los PRODUCTOS por PROVEEDOR .
 *
 * \param prod : Vector de PRODUCTOS a mostrar.
 * \param prodTam : Tamaño del vector de PRODUCTOS .
 * \param prov : Vector de PROVEEDORES a mostrar.
 * \param provTam : Tamaño del vector de PROVEEDORES .
 * \param
 * \return
 *
 */

void mostrarProductosPorProveedor( eProductos prod[], int prodTam, eProveedores prov[], int provTam )
{
    int flag = 0;
    int i, j;
    for( i = 0; i < provTam ; i++)
    {
        if(prov[i].isBusy == 1)
        {
            for(int j = 0; j < prodTam ; j++)
            {
                if( prov[i].codigoProveedor == prod[j].codigoProveedor && prod[j].isBusy == 1)
                {
                    if(flag == 0)
                    {
                        printf("--------------------------------------------------------------------------------");
                        printf(" PRODUCTOS del PROVEEDOR %s:\n", prov[i].descripcion);
                        printf("--------------------------------------------------------------------------------\n");
                        printf(" CODIGO DE PRODUCTO     DESCRIPCION     IMPORTE\n\n");
                        flag++;
                    }
                    printf(" %-8d\t\t%-16s%-10.2f\n", prod[j].codigoProducto, prod[j].descripcion , prod[j].importe);

                }
                if(j == prodTam - 1 && flag == 1)
                {
                    printf("\n--------------------------------------------------------------------------------\n");
                }
            }
            flag = 0;
        }
    }
    for( j = 0; j < prodTam ; j++)
    {
        if( prod[j].isBusy == 1)
        {
            if( prod[j].codigoProveedor == 0 && flag == 0)
            {
                flag++;
                printf("--------------------------------------------------------------------------------");
                printf(" PRODUCTOS sin PROVEEDOR asignado:\n");
                printf("--------------------------------------------------------------------------------\n");
                printf(" CODIGO DE PRODUCTO     DESCRIPCION     IMPORTE\n\n");
                printf(" %-8d\t\t%-16s%-10.2f\n", prod[j].codigoProducto, prod[j].descripcion , prod[j].importe );
            }
            else if( prod[j].codigoProveedor == 0)
            {
                printf(" %-8d\t\t%-16s%-10.2f\n", prod[j].codigoProducto, prod[j].descripcion , prod[j].importe );
            }
        }
    }
    if(flag == 1)
    {
        printf("\n--------------------------------------------------------------------------------\n");
    }
}


//XE1-5
/** \brief Muestra todos los PRODUCTOS de un vector de PRODUCTOS .
 *
 * \param prod : Vector de PRODUCTOS a mostrar.
 * \param prodTam : Tamaño del vector de PRODUCTOS .
 * \param prov : Vector de PROVEEDORES asociado al vector de PRODUCTOS .
 * \param provTam : Tamaño del vector de PROVEEDORES .
 * \return
 *
 */

void mostrarTodosLosProductos( eProductos prod[], int prodTam, eProveedores prov[], int provTam )
{
    printf("                       >>> Lista de PRODUCTOS <<<\n");
    printf("--------------------------------------------------------------------------------");
    printf(" PROVEEDOR \t CODIGO DE PRODUCTO     DESCRIPCION     IMPORTE\n");
    printf("--------------------------------------------------------------------------------\n");
    for(int i=0; i< prodTam ; i++)
    {
        if( prod[i].isBusy == 1)
        {
            if( prod[i].codigoProveedor == 0)
            {
                printf(" %-15s %-8d\t\t%-16s%-10.2f\n","Sin asignar", prod[i].codigoProducto, prod[i].descripcion , prod[i].importe );
            }
            else
            {
                for(int j = 0; j < provTam ; j++)
                {

                    if( prod[i].codigoProveedor == prov[j].codigoProveedor && prov[j].isBusy == 1)
                    {
                        printf(" %-15s %-8d\t\t%-16s%-10.2f\n", prov[j].descripcion, prod[i].codigoProducto, prod[i].descripcion , prod[i].importe );
                        break;
                    }

                }
            }




        }
    }
    printf("\n--------------------------------------------------------------------------------\n");
}


//XE1-6
/** \brief Muestra UN PRODUCTO .
 *
 * \param prodVar: Variable de tipo eProductos a mostrar.
 * \param prov : Vector de PROVEEDORES asociado al PRODUCTO .
 * \param provTam : tamaño del vector de PROVEEDORES .
 * \return
 *
 */

void mostrarProducto( eProductos empVar, eProveedores prov[], int provTam )
{
    int flag = 0;
    printf("--------------------------------------------------------------------------------");
    printf(" PROVEEDOR \t CODIGO DE PRODUCTO     DESCRIPCION     IMPORTE\n");
    printf("--------------------------------------------------------------------------------\n");
    for(int j = 0; j < provTam ; j++)
    {
        if( empVar.codigoProveedor == prov[j].codigoProveedor && prov[j].isBusy == 1)
        {
            printf(" %-15s %-8d\t\t%-16s%-10.2f\n", prov[j].descripcion, empVar.codigoProducto, empVar.descripcion , empVar.importe );
            flag++;
            break;
        }
    }
    if(flag == 0)
    {
        printf(" %-15s %-8d\t\t%-16s%-10.2f\n","Sin asignar", empVar.codigoProducto, empVar.descripcion , empVar.importe );
    }
    printf("\n--------------------------------------------------------------------------------\n");

}



// ABM dependencias:


//XE1-7
/** \brief Recorre un vector de PRODUCTOS y revisa si existe uno en especial.
 *
 * \param prod : Vector de PRODUCTOS a revisar.
 * \param prodTam : Tamaño del vector de PRODUCTOS a revisar.
 * \param codigoDelProducto : Se verificara si esta en el vector.
 * \return Devuelve -1 si el PRODUCTO no se encuentra en el vector o el numero de indice donde se encuentra el PRODUCTO .
 *
 */

int buscarProducto( eProductos prod[], int prodTam, int codigoDelProducto )
{
    int indiceDelProducto = -1;
    for(int i=0; i < prodTam ; i++)
    {
        if( prod[i].isBusy == 1 && prod[i].codigoProducto == codigoDelProducto )
        {
            indiceDelProducto = i;
            break;
        }
    }
    return indiceDelProducto ;
}


//XE1-8
/** \brief Busca un indice libre en un array de PRODUCTOS .
 *
 * \param prod : Array de PRODUCTOS a revisar.
 * \param prodTam : Tamaño del array de PRODUCTOS .
 * \return
 *
 */

int buscarIndiceLibreProd( eProductos prod[], int prodTam )
{
    int indiceLibre = -1;
    int i;
    for( i = 0; i < prodTam ; i++)
    {
        if(prod[i].isBusy == 0)
        {
            indiceLibre = i;
            break;
        }
    }
    return indiceLibre ;
}


//XE1-9
/** \brief Pide datos de un PRODUCTO y valida los datos.
 *
 * \param prod : Vector de PRODUCTOS para validar que el dato unico e irrepetible no haya sido antes cargado.
 * \param prodTam : Tamaño del vector de PRODUCTOS  .
 * \param prov : Vector de PROVEEDORES donde verificar PROVEEDORES posibles para el nuevo PRODUCTO .
 * \param provTam : Tamaño del vector de PROVEEDORES .
 * \return Devuelve una variable de tipo de eProductos cargada de datos.
 *
 */

eProductos pedirProducto( eProductos prod[], int prodTam, eProveedores prov[], int provTam )
{
    eProductos nuevoProducto ;
    nuevoProducto.isBusy = 0;

    int codigoDelProveedor, verificacion, codigoDelProducto, indiceProductoRepetido ;
    char descripcion[50] ;

    codigoDelProducto = getConditionedInt(1,1,"\nIngrese CODIGO DE PRODUCTO del PRODUCTO : ","\nEl numero de CODIGO DE PRODUCTO es invalido, reingrese: ");
    indiceProductoRepetido = buscarProducto ( prod, prodTam, codigoDelProducto );

    if( indiceProductoRepetido == -1)
    {
        printf("\n-  El CODIGO DE PRODUCTO fue dado de alta exitosamente.\n\n");
        system("pause");
        nuevoProducto.codigoProducto = codigoDelProducto ;
        system("cls");
        mostrarTodosLosProveedores( prov, provTam );
        codigoDelProveedor = getInt("\nIngrese CODIGO DE PROVEEDOR del PRODUCTO : ");
        verificacion = buscarProveedor( prov, provTam, codigoDelProveedor );
        if( verificacion != -1)
        {
            nuevoProducto.codigoProveedor = codigoDelProveedor ;
            printf("\n-  El PROVEEDOR ha sido asociado correctamente.\n\n");
            system("pause");
            system("cls");

            getRangedStr(2,49,"Ingrese DESCRIPCION del PRODUCTO : ","\nValidacion fallida , reingrese DESCRIPCION : ", descripcion );
            xstrCapsSpaceFixer( descripcion );
            strcpy( nuevoProducto.descripcion , descripcion );

            nuevoProducto.importe = getConditionedFloat(0,1,"\nIngrese IMPORTE del PRODUCTO : $","\nValidacion fallida, reingrese IMPORTE : ");

            printf("\n");

            nuevoProducto.isBusy = 1;
        }
        else
        {
            printf("\n* El PROVEEDOR no se ha encontrado.");
        }

    }
    else
    {
        printf("\n* El CODIGO DE PRODUCTO se encuentra en uso por otro PRODUCTO del sistema.");
    }
    return nuevoProducto ;
}



//ALTA BAJA MODIFICACION:


//XE2-1
/** \brief Da de alta un nuevo PRODUCTO al sistema verificando que el CODIGO DE PRODUCTO no se repita y que se elija un PROVEEDOR VALIDO.
 *
 * \param prod : vector donde se dara de alta el PRODUCTO .
 * \param prodTam : cantidad de elementos del vector de PRODUCTOS .
 * \param prov : vector de PROVEEDORES asociado a vector de PRODUCTOS .
 * \param provTam : cantidad de elementos del vector de PROVEEDORES .
 * \return devuelve -1 si no hay espacio para dar de alta PRODUCTOS , 0 si se produjo un error al validar o
 * \return 1 si el PRODUCTO fue dado de alta correctamente.
 *
 */

int altaProducto( eProductos prod[], int prodTam, eProveedores prov[], int provTam )
{
    int reg ;
    int indiceLibre ;

    indiceLibre = buscarIndiceLibreProd( prod, prodTam );
    if( indiceLibre == -1)
    {
        reg = -1 ;
    }
    else
    {
        prod[indiceLibre] = pedirProducto( prod, prodTam, prov, provTam );
        if( prod[indiceLibre].isBusy == 0)
        {
            reg = 0 ;
        }
        else
        {
            reg = 1 ;
        }
    }

    return reg ;
}


//XE2-2
/** \brief Elimina un PRODUCTO del sistema.
 *
 * \param prod : Recibe un vector de PRODUCTOS para que el usuario busque en el posibles PRODUCTOS a borrar.
 * \param prodTam : Tamaño del vector de PRODUCTOS .
 * \param prov : Vector de PROVEEDORES asociado al vector de PRODUCTOS .
 * \param provTam : Tamaño del vector de PROVEEDORES .
 * \return devuelve 1 si el PRODUCTO se dio de baja, devuelve 0 si el PRODUCTO se encontro pero no se dio de baja o devuelve -1 si el PRODUCTO no se encontro.
 *
 */

int bajaProducto( eProductos prod[], int prodTam, eProveedores prov[], int provTam )
{
    int reg = 0 ;
    int codigoDelProducto ;
    int verificacion ; // Se almacena el indice recibido por buscarProducto() para determinar si el empleado existe.

    system("cls");
    mostrarTodosLosProductos( prod, prodTam, prov, provTam );
    codigoDelProducto = getInt("Ingrese CODIGO DE PRODUCTO del PRODUCTO a eliminar: ");

    verificacion = buscarProducto( prod, prodTam, codigoDelProducto );
    if( verificacion == -1)
    {
        reg = -1 ;
    }
    else
    {
        system("cls");
        printf("                   <<< ELIMINARA EL SIGUIENTE PRODUCTO >>>\n");
        mostrarProducto( prod[verificacion], prov, provTam );

        if(validateDualExit("\nConfirmar? s/n : ","\nNo se reconoce su respuesta.\nReingrese: ",'s','n') == 1)
        {
            prod[verificacion].isBusy = 0;
            reg = 1 ;
        }
        else
        {
            reg = 0 ;
        }
    }
    system("cls");
    return reg ;
}


//XE2-3
/** \brief Permite al usuario modificar datos de un PRODUCTO de un vector de PRODUCTOS .
 *
 * \param prod : Vector de PRODUCTOS donde el usuario buscara.
 * \param prodTam : Tamaño del vector de PRODUCTOS .
 * \param prov : Vector de PROVEEDORES asociado al vector de PRODUCTOS .
 * \param provTam : Tamaño del vector de PROVEEDORES .
 * \return Devuelve -1 si el PRODUCTO a modificar no existe, 0 si se encontro un PRODUCTO y no se modifico y un entero
 * \return positivo si se realizo alguna modificacion a un PRODUCTO .
 *
 */

int modificarProducto ( eProductos prod[], int prodTam, eProveedores prov[], int provTam )
{
    char descripcion[50] ;
    int codigoDelProducto, seleccion, codigoProductoRepetido, codigoDelProveedor, verificacion, indiceProductoCodigo ;
    int reg = -1, salir = 0;

    system("cls");
    mostrarTodosLosProductos( prod, prodTam, prov, provTam );

    codigoDelProducto = getInt("Ingrese CODIGO DE PRODUCTO del PRODUCTO a modificar: ");
    indiceProductoCodigo = buscarProducto( prod, prodTam, codigoDelProducto );

    if( indiceProductoCodigo > -1)
    {
        reg = 0 ;
        system("cls");
        printf("                   <<< MODIFICARA EL SIGUIENTE PRODUCTO >>>\n");
        mostrarProducto( prod[indiceProductoCodigo], prov, provTam );

        if(validateDualExit("\nConfirmar? s/n : ","\nNo se reconoce su respuesta.\nReingrese: ",'s','n') == 1)
        {
            do
            {
                xlkNoLineHeadGenerator("Modificar PRODUCTO :");
                mostrarProducto( prod[indiceProductoCodigo], prov, provTam );
                xlkNoLineIndexBodyGenerator(5,"1- CAMBIAR CODIGO DE PRODUCTO .","2- CAMBIAR DESCRIPCION .","3- CAMBIAR IMPORTE .","4- CAMBIAR PROVEEDOR .","0- VOLVER .");
                seleccion = getInt("- Seleccionar opcion: ");
                switch(seleccion)
                {
                case 1:
                    codigoDelProducto = getConditionedInt(1,1,"\nIngrese nuevo CODIGO DE PRODUCTO : ","Se proujo un error al validar, reingrese CODIGO DE PRODUCTO : ");
                    codigoProductoRepetido = buscarProducto( prod, prodTam, codigoDelProducto );
                    if( codigoProductoRepetido > -1 )
                    {
                        printf("\n* El CODIGO DE PRODUCTO que intenta cargar se encuentra en uso.\n\n");

                    }
                    else if( validateDualExit("\nAplicar cambio? s/n : ","\nNo se reconoce su respuesta.\nReingrese: ",'s','n') == 1 && codigoProductoRepetido == -1)
                    {
                        prod[indiceProductoCodigo].codigoProducto = codigoDelProducto;
                        printf("\n\n* Modificacion realizada.\n\n");
                        reg ++ ;
                    }
                    else
                    {
                        printf("\n\n* Accion cancelada.\n\n");
                    }
                    system("pause");
                    break;
                case 2:
                    getRangedStr(2,49,"\nCambiar DESCRIPCION : "," Se produjo un error al validar, reingrese DESCRIPCION : ", descripcion );
                    xstrCapsSpaceFixer( descripcion );
                    xstrCapsAdder( descripcion );
                    strcpy( prod[indiceProductoCodigo].descripcion , descripcion );
                    printf("\n* Modificacion realizada.\n\n");
                    reg ++ ;
                    system("pause");
                    break;
                case 3:
                    prod[indiceProductoCodigo].importe = getConditionedFloat(0,1,"\nCambiar IMPORTE : $"," Se produjo un error al validaR, reingrese IMPORTE : ");
                    printf("\n* Modificacion realizada.\n\n");
                    reg ++ ;
                    system("pause");
                    break;
                case 4:
                    mostrarTodosLosProveedores( prov, provTam );
                    codigoDelProveedor = getInt("\nCambiar CODIGO DE PROVEEDOR : ");
                    verificacion = buscarProveedor( prov, provTam, codigoDelProveedor );
                    if( verificacion != -1)
                    {
                        prod[indiceProductoCodigo].codigoProveedor = codigoDelProveedor ;
                        printf("\n* Modificacion realizada.\n\n");
                        reg ++ ;
                    }
                    else
                    {
                        printf("\n* PROVEEDOR inexistente.\n\n");
                    }
                    system("pause");
                    break;
                case 0:
                    salir = 1;
                    break;
                default:
                    printf("\n Opcion invalida.\n");
                    system("pause");
                    break;
                }

            }
            while(salir == 0);
        }
    }
    else
    {
        reg = -1 ;
    }

    system("cls");

    return reg ;
}



//Adicionales:


//XE2-4
/** \brief Ordena PRODUCTOS por 3 criterios: 1- DESCRIPCION , 2- IMPORTE ,  3- CODIGO DE PRODUCTO .
 *
 * \param prod : Vector de PRODUCTOS a ordenar.
 * \param prodTam : Tamaño del vector de PRODUCTOS .
 * \return
 *
 */

void ordenarProductos( eProductos prod[], int prodTam )
{
    for(int i = 0; i < prodTam - 1; i++)
    {
        for(int j = i+1; j < prodTam ; j++)
        {
            if(stricmp( prod[j].descripcion , prod[i].descripcion ) < 0)
            {
                eProductos aux ;
                aux = prod[i] ;
                prod[i] = prod[j] ;
                prod[j] = aux ;
            }
            else if( stricmp( prod[j].descripcion, prod[i].descripcion ) == 0)
            {
                if( prod[j].importe > prod[i].importe )
                {
                    eProductos aux ;
                    aux = prod[i] ;
                    prod[i] = prod[j] ;
                    prod[j] = aux ;
                }
                else if( prod[j].importe == prod[i].importe )
                {
                    if( prod[j].codigoProducto > prod[i].codigoProducto )
                    {
                        eProductos aux ;
                        aux = prod[i] ;
                        prod[i] = prod[j] ;
                        prod[j] = aux ;
                    }
                }

            }
        }
    }
}



//Funciones exclusivas de eProveedores :

//Basico:


//XE2-5
/** \brief Define el estado de un vector de PROVEEDORES en 0.
 *
 * \param prov : Vector de PROVEEDORES a inicializar.
 * \param provTam : Tamaño del vector de PROVEEDORES .
 * \return
 *
 */

void inicializarProveedores( eProveedores prov[], int provTam )
{
    for(int i = 0; i < provTam ; i++)
    {
        prov[i].isBusy = 0;
    }
}



//Funciones de muestra:


//XE2-6
/** \brief Muestra todos los PROVEEDORES de un vector de PROVEEDORES .
 *
 * \param prov: Vector de PROVEEDORES a mostrar.
 * \param provTam: Tamaño del vector de PROVEEDORES .
 * \return
 *
 */

void mostrarTodosLosProveedores( eProveedores prov[], int provTam )
{
    printf("                       >>> Lista de PROVEEDORES <<<\n");
    printf("--------------------------------------------------------------------------------");
    printf(" CODIGO DE PROVEEDOR :\t\t DESCRIPCION :\n");
    printf("--------------------------------------------------------------------------------\n");
    for(int i=0; i< provTam ; i++)
    {
        if( prov[i].isBusy == 1)
        {
            printf(" %d\t\t\t\t %-30s\n", prov[i].codigoProveedor , prov[i].descripcion );
        }
    }
    printf("\n--------------------------------------------------------------------------------\n");
}


//XE2-7
/** \brief Muestra un PROVEEDOR .
 *
 * \param provVar: Variable de tipo eProveedores a mostrar.
 * \return
 *
 */

void mostrarProveedor( eProveedores provVar )
{
    printf("--------------------------------------------------------------------------------");
    printf(" CODIGO DE PROVEEDOR :\t\t DESCRIPCION :\n");
    printf("--------------------------------------------------------------------------------\n");
    printf(" %d\t\t\t\t %-30s\n", provVar.codigoProveedor, provVar.descripcion );
    printf("\n--------------------------------------------------------------------------------\n");
}



// ABM dependencias:


//XE2-8
/** \brief Busca un indice libre en un vector de PROVEEDORES .
 *
 * \param prov : Vector de PROVEEDORES a revisar.
 * \param tam : Tamaño del vector de PROVEEDORES .
 * \return devuelve -1 si no hay espacio en el vector o un indice libre si lo halla.
 *
 */

int buscarIndiceLibreProv( eProveedores prov[], int provTam )
{
    int indiceLibre = -1;
    for(int i=0; i < provTam ; i++)
    {
        if(prov[i].isBusy == 0)
        {
            indiceLibre = i;
            break;
        }
    }
    return indiceLibre ;
}


//XE2-9
/** \brief Revisa un vector de PROVEEDORES para determinar si un PROVEEDOR se encuentra en el vector.
 *
 * \param prov : Vector de PROVEEDORES a revisar.
 * \param tam : Tamaño del vector de PROVEEDORES .
 * \param codigoDelProveedor : CODIGO DE PROVEEDOR a buscar en el vector.
 * \return devuelve -1 si no encontro el PROVEEDOR o el indice del vector donde se halla.
 *
 */

int buscarProveedor( eProveedores prov[], int provTam, int codigoDelProveedor )
{
    int indiceCoincidencia = -1;
    for(int i = 0; i < provTam ; i++)
    {
        if( prov[i].codigoProveedor == codigoDelProveedor && prov[i].isBusy == 1)
        {
            indiceCoincidencia = i;
            break;
        }
    }
    return indiceCoincidencia ;
}



//ALTA BAJA MODIFICACION:


//XE3-1
/** \brief Da de alta un nuevo PROVEEDOR en el sistema.
 *
 * \param prov : Vector de PROVEEDORES donde dar de alta un nuevo PROVEEDOR .
 * \param provTam : Tamaño del vector de PROVEEDORES .
 * \return Devuelve -1 si no hay espacio para crear un PROVEEDOR , 0 si se produjo un error al validar algun dato o
 * \return 1 si el PROVEEDOR se creo con exito.
 *
 */

int altaProveedor( eProveedores prov[], int provTam )
{
    int indiceLibre ;
    int verificacion ;
    int codigoDelProveedor ;
    int reg = -1;
    indiceLibre = buscarIndiceLibreProv( prov, provTam );
    if( indiceLibre != -1)
    {
        codigoDelProveedor = getConditionedInt(1,1,"\nIngrese CODIGO DE PROVEEDOR (Debe ser mayor a 0): ","\nNumero incorrecto, reingrese: ");
        verificacion = buscarProveedor( prov, provTam, codigoDelProveedor );
        if(verificacion == -1)
        {
            reg = 1 ;
            prov[indiceLibre].codigoProveedor = codigoDelProveedor ;
            getRangedStr(2,49,"\nIngrese DESCRIPCION del PROVEEDOR : ","\nSe produjo un error al validar, reingrese DESCRIPCION : ", prov[indiceLibre].descripcion );
            prov[indiceLibre].isBusy = 1;
        }
        else
        {
            reg = 0 ;
        }
    }
    system("cls");
    return reg ;
}


//XE3-2
/** \brief Da de baja un PROVEEDOR del sistema y asigna a los PRODUCTOS el PROVEEDOR un equivalente a "Sin asignar".
 *
 * \param prov : Vector de PROVEEDORES donde buscar un PROVEEDOR para dar de baja.
 * \param provTam : Tamaño del vector PROVEEDORES .
 * \param prod : vector de PRODUCTOS a revisar si corresponde con un PROVEEDOR dado de baja.
 * \param prodTam : Tamaño del vector de PRODUCTOS .
 * \return Devuelve -1 si no se encontro un PROVEEDOR , 0 si se encontro uno y el usuario anulo la baja o 1 si se concreto
 * \return la baja de un PROVEEDOR .
 *
 */

int bajaProveedor( eProveedores prov[], int provTam, eProductos prod[], int prodTam )
{
    int codigoDelProveedor, reg ;
    int verificacion ;

    system("cls");
    mostrarTodosLosProveedores( prov, provTam );

    codigoDelProveedor = getInt("Ingrese CODIGO DE PROVEEDOR a eliminar: ");
    verificacion = buscarProveedor( prov, provTam, codigoDelProveedor );
    if( verificacion == -1)
    {
        reg = -1 ;
    }
    else
    {
        system("cls");
        printf("                   <<< ELIMINARA ESTE PROVEEDOR >>>\n");
        mostrarProveedor( prov[verificacion] );
        if(validateDualExit("\nConfirmar? s/n : ","\nNo se reconoce su respuesta.\nReingrese: ",'s','n') == 1)
        {
            prov[verificacion].isBusy = 0;
            for(int i = 0; i < provTam ; i++)
            {
                if( prov[verificacion].codigoProveedor == prod[i].codigoProveedor )
                {
                    prod[i].codigoProveedor = 0;
                }
            }
            reg = 1 ;
        }
        else
        {
            reg = 0 ;
        }
    }
    system("cls");
    return reg ;
}


//XE3-3
/** \brief Permite al usuario modificar datos de un PROVEEDOR de un vector de PROVEEDORES .
 *
 * \param prov : Vector de PROVEEDORES donde el usuario buscara un PROVEEDOR a modificar.
 * \param provTam : Tamaño del vector de PROVEEDORES .
 * \param prod : vector de PRODUCTOS asociado.
 * \param prodTam : Tamaño del vector de PRODUCTOS  asociado .
 * \return Devuelve -1 si el PROVEEDOR a modificar no existe, 0 si se encontro un PROVEEDOR y no se modifico y un entero
 * \return positivo si se realizo alguna modificacion.
 *
 */

int modificarProveedor( eProveedores prov[] , int provTam , eProductos prod[] , int prodTam )
{
    int codigoDelProveedor ;
    int salir = 0, seleccion, verificacion, reg = 0, verif , i ;

    system("cls");
    mostrarTodosLosProveedores( prov, provTam );

    codigoDelProveedor = getInt("\nIngrese CODIGO DE PROVEEDOR a modificar: ");
    verificacion = buscarProveedor( prov, provTam, codigoDelProveedor );

    if( verificacion > -1)
    {
        system("cls");
        printf("                   <<< MODIFICARA AL SIGUIENTE PROVEEDOR >>>\n");
        mostrarProveedor( prov[verificacion] );

        if(validateDualExit("\nConfirmar? s/n : ","\nNo se reconoce su respuesta.\nReingrese: ",'s','n') == 1)
        {
            do
            {
                xlkNoLineHeadGenerator("Modificar PROVEEDOR :");
                mostrarProveedor( prov[verificacion] );
                xlkNoLineIndexBodyGenerator(3,"1- CAMBIAR CODIGO DE PROVEEDOR .","2- CAMBIAR DESCRIPCION .","0- VOLVER .");
                seleccion = getInt("- Seleccionar opcion: ");

                switch( seleccion )
                {
                case 1:
                    codigoDelProveedor = getConditionedInt(1,1,"\nIngrese nuevo CODIGO DE PROVEEDOR (Debe ser mayor a 0): ","\nSe produjo un error al validar.\nRecuerde que un CODIGO DE PROVEEDOR debe ser mayor a 0.\nReingrese: ");
                    verif = buscarProveedor( prov, provTam, codigoDelProveedor );
                    if( verif == -1)
                    {
                        for(i = 0 ; i < prodTam ; i++)
                        {
                            if( prod[i].codigoProveedor == prov[verificacion].codigoProveedor )
                            {
                                prod[i].codigoProveedor = codigoDelProveedor ;
                            }
                        }
                        prov[verificacion].codigoProveedor = codigoDelProveedor ;
                        printf("\n* Modificacion realizada.\n\n");
                        reg++ ;
                    }
                    else
                    {
                        printf("El CODIGO DE PROVEEDOR que intenta cargar se encuentra en uso:\n");
                    }
                    system("pause");
                    break;
                case 2:
                    getRangedStr(2,50,"\nIngrese nueva DESCRIPCION : ","\nSe produjo un error al validar, reingrese DESCRIPCION : ", prov[verificacion].descripcion );
                    xstrCapsSpaceFixer( prov[verificacion].descripcion );
                    printf("\n* Modificacion realizada.\n\n");
                    reg++ ;
                    system("pause");
                    break;
                case 0:
                    salir = 1;
                    break;
                default:
                    printf("\nOpcion invalida.\n");
                    system("pause");
                    break;
                }

            }
            while( salir == 0);
        }
    }
    else
    {
        reg = -1 ;
    }
    system("cls");
    return reg ;
}



//FUNCIONES DE MENU:


// productos


//XE3-4
/** \brief Muestra el menu de acciones de PRODUCTOS .
 *
 * \param prod : Vector de PRODUCTOS .
 * \param prodTam : Tamaño del vector de PRODUCTOS .
 * \param prov : Vector de PROVEEDORES asociado.
 * \param provTam : Tamaño del vector de PROVEEDORES asociado.
 * \return
 *
 */

void mostrarMenuProductos( eProductos prod[], int prodTam, eProveedores prov[], int provTam )     //XE3-4
{
    int functionValueReceiver ;
    int seleccion ;
    int exit = 0;
    do
    {
        xlkIndexGenerator(" PRODUCTOS ",7,"1-ALTA.","2-BAJA.","3-MODIFICACION.","4-ORDENAMIENTO.","5-MOSTRAR PRODUCTOS .","6-MOSTRAR PRODUCTOS POR PROVEEDOR .","0-VOLVER.");
        seleccion = getInt("-  Seleccionar opcion: ");
        switch(seleccion)
        {
        case 1:
            printf("\n* Agregar nuevo PRODUCTO :\n");
            functionValueReceiver = altaProducto( prod , prodTam , prov , provTam );
            if(functionValueReceiver == 1)
            {
                system("cls");
                printf("* Alta completada.\n\n");
            }
            else if(functionValueReceiver == 0)
            {
                printf("\n\n* No se completo la carga.\n\n");
            }
            else
            {
                system("cls");
                printf("No hay espacio suficiente para realizar mas altas de este tipo.\n\n");
            }
            system("pause");
            break;
        case 2:
            functionValueReceiver = bajaProducto( prod, prodTam, prov, provTam );
            if(functionValueReceiver == -1)
            {
                printf("* No se ha encontrado el PRODUCTO especificado.\n\n");
            }
            else if(functionValueReceiver == 0)
            {
                printf("* Baja cancelada.\n\n");
            }
            else
            {
                printf("* Baja realizada.\n\n");
            }
            system("pause");
            break;
        case 3:
            system("color 06");
            functionValueReceiver = modificarProducto( prod, prodTam, prov, provTam );
            if(functionValueReceiver == -1)
            {
                printf("* No se ha encontrado el PRODUCTO especificado.\n\n");
            }
            else if(functionValueReceiver == 0)
            {
                printf("* No se realizaron modificaciones.\n\n");
            }
            else
            {
                printf("* Se aplicaron modificaciones con exito.\n\n");
            }
            system("pause");
            system("color 07");
            break;
        case 4:
            ordenarProductos( prod, prodTam );
            printf("\n* Se han ordenado todos los PRODUCTOS del sistema.\n\n");
            system("pause");
            break;
        case 5:
            system("cls");
            mostrarTodosLosProductos( prod, prodTam, prov, provTam );
            system("pause");
            break;
        case 6:
            system("cls");
            mostrarProductosPorProveedor( prod, prodTam, prov, provTam );
            system("pause");
            break;
        case 0:
            exit = 1;
            break;
        default:
            printf("\nOpcion invalida.\n\n");
            system("pause");
            break;
        }
    }
    while(exit == 0);
}



// sector


//XE3-5
/** \brief Muestra el menu de acciones de los PROVEEDORES .
 *
 * \param prod : Vector de PRODUCTOS asociado.
 * \param prodTam : Tamaño del vector de PRODUCTOS asociado.
 * \param prov : Vector de PROVEEDORES .
 * \param provTam : Tamaño del vector de PROVEEDORES .
 * \return
 *
 */

void mostrarMenuProveedores( eProductos prod[], int prodTam, eProveedores prov[], int provTam )
{
    int functionValueReceiver ;
    int seleccion;
    int exit = 0;
    do
    {
        xlkIndexGenerator(" PROVEEDORES ",5,"1-ALTA.","2-BAJA.","3-MODIFICACION.","4-MOSTRAR PROVEEDORES .","0-VOLVER.");
        seleccion = getInt("-  Seleccionar opcion: ");
        switch(seleccion)
        {
        case 1:
            printf("\n* Agregar un nuevo PROVEEDOR :\n");
            functionValueReceiver = altaProveedor( prov, provTam );
            if(functionValueReceiver == -1)
            {
                printf("* No hay espacio suficiente para realizar mas altas de este tipo.\n\n");
            }
            else if(functionValueReceiver == 0)
            {
                printf("* El CODIGO DE PROVEEDOR que intenta asignar se encuentra en uso.\n\n");
            }
            else
            {
                printf("* Alta realizada.\n\n");
            }
            system("pause");
            break;
        case 2:
            functionValueReceiver = bajaProveedor( prov, provTam, prod, prodTam );
            if(functionValueReceiver == -1)
            {
                printf("* No se ha encontrado el PROVEEDOR especificado.\n\n");
            }
            else if(functionValueReceiver == 0)
            {
                printf("* Baja cancelada.\n\n");
            }
            else
            {
                printf("* Baja realizada.\n\n");
            }
            system("pause");
            break;
        case 3:
            system("color 06");
            functionValueReceiver = modificarProveedor( prov , provTam , prod , prodTam );
            if(functionValueReceiver == -1)
            {
                printf("* No se ha encontrado el PROVEEDOR especificado.\n\n");
            }
            else if(functionValueReceiver == 0)
            {
                printf("* No se realizaron modificaciones.\n\n");
            }
            else
            {
                printf("* Se aplicaron modificaciones con exito.\n\n");
            }
            system("pause");
            system("color 07");
            break;
        case 4:
            system("cls");
            mostrarTodosLosProveedores( prov, provTam );
            system("pause");
            break;
        case 0:
            exit = 1;
            break;
        default:
            printf("\nOpcion invalida.\n\n");
            system("pause");
            break;
        }
    }
    while(exit == 0);
}
