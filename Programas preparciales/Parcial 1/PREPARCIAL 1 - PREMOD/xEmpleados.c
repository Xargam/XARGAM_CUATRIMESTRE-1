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
/** \brief Carga datos a modo hardcode en los 3 primeros indices de un vector de productos .
 *
 * \param prod : Vector de productos a hardcodear.
 * \return
 *
 */

void harcodearProd( eProductos prod[] )
{
    strcpy( prod[1].descripcion, "Pendrive 8gb");
    prod[1].importe = 210.95;
    prod[1].codigoProducto = 1;
    prod[1].cantidad = 10;
    prod[1].codigoProveedor = 1;
    prod[1].isBusy = 1;

    strcpy( prod[0].descripcion, "MicroSD 8gb");
    prod[0].importe = 350;
    prod[0].codigoProducto = 2;
    prod[0].cantidad = 2;
    prod[0].codigoProveedor = 1;
    prod[0].isBusy = 1;

    strcpy( prod[2].descripcion, "Auricular");
    prod[2].importe = 480.20;
    prod[2].codigoProducto = 3;
    prod[2].cantidad = 25;
    prod[2].codigoProveedor = 1;
    prod[2].isBusy = 1;
}



// eProveedores :


//XE1-2
/** \brief Carga datos a modo hardcode en los 5 primeros indices de un vector de proveedores .
 *
 * \param prov : Vector de proveedores a hardcodear
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
    strcpy( prov[0].descripcion,"Sony Store");
    strcpy( prov[1].descripcion,"Utra Prov");
    strcpy( prov[2].descripcion,"Indalo");
    strcpy( prov[3].descripcion,"Philips SDR");
    strcpy( prov[4].descripcion,"USA Amazon");
    prov[0].isBusy = 1;
    prov[1].isBusy = 1;
    prov[2].isBusy = 1;
    prov[3].isBusy = 1;
    prov[4].isBusy = 1;
}



//Funciones exclusivas eProductos :

//Basico:


//XE1-3
/** \brief Inicializa el estado de los productos de un vector en 0 para ser leidos como desocupados.
 *
 * \param prod : Vector de productos a inicializar.
 * \param prodTam : Cantidad de elementos del vector de productos .
 * \return
 *
 */

void inicializarEmpleados( eProductos prod[], int prodTam )
{
    for(int i=0; i < prodTam ; i++)
    {
        prod[i].isBusy = 0;
    }
}



//Funciones de muestra:


//XE1-4
/** \brief muestra a todos los productos por proveedor .
 *
 * \param prod : Vector de productos a mostrar.
 * \param prodTam : Tamaño del vector de productos .
 * \param prov : Vector de proveedores a mostrar.
 * \param provTam : Tamaño del vector de proveedores .
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
                        printf(" Productos del proveedor %s:\n", prov[i].descripcion);
                        printf("________________________________________________________________________________\n");
                        printf(" Codigo de producto  \t Descripcion \t\t Cantidad  \t Importe  \n");
                        printf("________________________________________________________________________________\n");
                        flag++;
                    }
                    printf(" %-5d\t\t\t %-16s\t %-5d\t\t %-11.2f\n", prod[j].codigoProducto, prod[j].descripcion, prod[j].cantidad, prod[j].importe );

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
                printf(" productos sin proveedor asignado:\n");
                printf("--------------------------------------------------------------------------------");
                printf("________________________________________________________________________________\n");
                printf(" Codigo de producto  \t Descripcion  \t\t Cantidad  \t Importe  \n");
                printf("________________________________________________________________________________\n");
                printf(" %-5d\t\t\t %-16s\t %-5d\t\t %-11.2f\n", prod[j].codigoProducto, prod[j].descripcion, prod[j].cantidad, prod[j].importe );
            }
            else if( prod[j].codigoProveedor == 0)
            {
                printf(" %-5d\t\t\t %-16s\t %-5d\t\t %-11.2f\n", prod[j].codigoProducto, prod[j].descripcion, prod[j].cantidad, prod[j].importe );
            }
        }
    }
    if(flag == 1)
    {
        printf("\n--------------------------------------------------------------------------------\n");
    }
}


//XE1-5
/** \brief Muestra todos los productos de un vector de productos .
 *
 * \param prod : Vector de productos a mostrar.
 * \param prodTam : Tamaño del vector de productos .
 * \param prov : Vector de proveedores asociado al vector de productos .
 * \param provTam : Tamaño del vector de proveedores .
 * \return
 *
 */

void mostrarTodosLosProductos( eProductos prod[], int prodTam, eProveedores prov[], int provTam )
{
    printf("                       >>> Lista de productos <<<\n");
    printf("--------------------------------------------------------------------------------");
    printf(" Proveedor    Codigo producto   Descripcion \t Cantidad \t Importe \n");
    printf("--------------------------------------------------------------------------------\n");
    for(int i=0; i< prodTam ; i++)
    {
        if( prod[i].isBusy == 1)
        {
            if( prod[i].codigoProveedor == 0)
            {
                printf(" %-16s    %-5d \t%-16s %-5d\t\t %-11.2f\n","Sin asignar", prod[i].codigoProducto, prod[i].descripcion, prod[i].cantidad, prod[i].importe );
            }
            else
            {
                for(int j = 0; j < provTam ; j++)
                {

                    if( prod[i].codigoProveedor == prov[j].codigoProveedor && prov[j].isBusy == 1)
                    {
                        printf(" %-16s    %-5d \t%-16s %-5d\t\t %-11.2f\n", prov[j].descripcion, prod[i].codigoProducto, prod[i].descripcion, prod[i].cantidad, prod[i].importe );
                        break;
                    }
                }
            }

        }
    }
    printf("\n--------------------------------------------------------------------------------\n");
}


//XE1-6
/** \brief Muestra UN producto .
 *
 * \param prodVar : Variable de tipo eProductos a mostrar.
 * \param prov : Vector de proveedores asociado al producto .
 * \param provTam : tamaño del vector de proveedores .
 * \param estetica Mayor a 0: Mostrar detalles adicionales. Menor a 0: Mostrar solo informacion imprescindible.
 * \param estetica Igual a 0: Muestra detalles al principio del listado y no al final.
 * \return
 *
 */

void mostrarProducto( eProductos prodVar, eProveedores prov[], int provTam, int estetica )
{
    int flag = 0;
    if(estetica > 0 || estetica == 0 )
    {
        printf("--------------------------------------------------------------------------------");
        printf(" Proveedor    Codigo producto   Descripcion \t Cantidad \t Importe \n");
        printf("--------------------------------------------------------------------------------\n");
    }
    for(int j = 0; j < provTam ; j++)
    {
        if( prodVar.codigoProveedor == prov[j].codigoProveedor && prov[j].isBusy == 1)
        {
            printf(" %-16s    %-5d \t%-16s %-5d\t\t %-11.2f\n", prov[j].descripcion, prodVar.codigoProducto, prodVar.descripcion, prodVar.cantidad, prodVar.importe );
            flag++;
            break;
        }
    }
    if(flag == 0)
    {
        printf(" %-16s    %-5d \t%-16s %-5d\t\t %-11.2f\n","Sin asignar", prodVar.codigoProducto, prodVar.descripcion, prodVar.cantidad, prodVar.importe );
    }
    if(estetica > 0)
    {
        printf("\n--------------------------------------------------------------------------------\n");
    }
}



// ABM dependencias:


//XE1-7
/** \brief Recorre un vector de productos y revisa si existe uno en especial.
 *
 * \param prod : Vector de productos a revisar.
 * \param prodTam : Tamaño del vector de productos a revisar.
 * \param codigoProducto : Se verificara si esta en el vector.
 * \return Devuelve -1 si el producto no se encuentra en el vector o el numero de indice donde se encuentra el producto .
 *
 */

int buscarProducto( eProductos prod[], int prodTam, int codigoProducto )
{
    int indiceDelProducto = -1;
    for(int i=0; i < prodTam ; i++)
    {
        if( prod[i].isBusy == 1 && prod[i].codigoProducto == codigoProducto )
        {
            indiceDelProducto = i;
            break;
        }
    }
    return indiceDelProducto ;
}


//XE1-8
/** \brief Busca un indice libre en un array de productos .
 *
 * \param prod : Array de productos a revisar.
 * \param prodTam : Tamaño del array de productos .
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
/** \brief Pide datos de un producto y valida los datos.
 *
 * \param prod : Vector de productos para validar que el dato unico e irrepetible no haya sido antes cargado.
 * \param prodTam : Tamaño del vector de productos  .
 * \param prov : Vector de proveedores donde verificar proveedores posibles para el nuevo producto .
 * \param provTam : Tamaño del vector de proveedores .
 * \return Devuelve una variable de tipo de eProductos cargada de datos.
 *
 */

eProductos pedirProducto( eProductos prod[], int prodTam, eProveedores prov[], int provTam )
{
    eProductos nuevoProducto ;
    nuevoProducto.isBusy = 0;

    int codigoDelProveedor, verificacion, codigoProducto, indiceProductoRepetido ;
    char descripcion[50] ;

    codigoProducto = getConditionedInt(1,1,"\nIngrese codigo de producto a asignar: ","\nEl numero de codigo de producto es invalido, reingrese: ");
    indiceProductoRepetido = buscarProducto ( prod, prodTam, codigoProducto );

    if( indiceProductoRepetido == -1)
    {
        printf("\n-  El codigo de producto fue agregado al sistema.\n\n");
        system("pause");
        system("cls");
        nuevoProducto.codigoProducto = codigoProducto ;
        mostrarTodosLosProveedores( prov, provTam );
        codigoDelProveedor = getInt("\nIngrese codigo de proveedor para el producto : ");
        verificacion = buscarProveedor( prov, provTam, codigoDelProveedor );
        if( verificacion != -1)
        {
            nuevoProducto.codigoProveedor = codigoDelProveedor ;
            printf("\n-  El proveedor ha sido asociado correctamente.\n\n");
            system("pause");
            system("cls");

            getRangedStr(2,49,"Ingrese descripcion del producto : ","\nValidacion fallida , reingrese la descripcion del producto : ", descripcion );
            xstrCapsSpaceFixer( descripcion );
            xstrCapsAdder( descripcion );
            strcpy( nuevoProducto.descripcion, descripcion );

            nuevoProducto.cantidad = getConditionedInt(0,1,"\nEscriba stock del producto : ","\nSe produjo un error al validar el numero de stock ...\nReingrese: " );

            nuevoProducto.importe = getConditionedFloat(0,1,"\nIngrese importe del producto : $","\nValidacion fallida, reingrese importe del producto : ");

            printf("\n");

            nuevoProducto.isBusy = 1;
        }
        else
        {
            printf("\n* El proveedor no se ha encontrado.");
        }

    }
    else
    {
        printf("\n* El codigo de producto se encuentra en uso por otro producto del sistema.");
    }
    return nuevoProducto ;
}



//ALTA BAJA MODIFICACION:


//XE2-1
/** \brief Da de alta un nuevo producto al sistema verificando que el codigo de producto no se repita y que se elija un proveedor VALIDO.
 *
 * \param prod : vector donde se dara de alta el producto .
 * \param prodTam : cantidad de elementos del vector de productos .
 * \param prov : vector de proveedores asociado a vector de productos .
 * \param provTam : cantidad de elementos del vector de proveedores .
 * \return devuelve -1 si no hay espacio para dar de alta productos , 0 si se produjo un error al validar o
 * \return 1 si el producto fue dado de alta correctamente.
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
/** \brief Elimina un producto del sistema.
 *
 * \param prod : Recibe un vector de productos para que el usuario busque en el posibles productos a borrar.
 * \param prodTam : Tamaño del vector de productos .
 * \param prov : Vector de proveedores asociado al vector de productos .
 * \param provTam : Tamaño del vector de proveedores .
 * \return devuelve 1 si el producto se dio de baja, devuelve 0 si el producto se encontro pero no se dio de baja o devuelve -1 si el producto no se encontro.
 *
 */

int bajaProducto( eProductos prod[], int prodTam, eProveedores prov[], int provTam )
{
    int reg = 0 ;
    int codigoProducto ;
    int verificacion ; // Se almacena el indice recibido por buscarProducto() para determinar si el empleado existe.

    system("cls");
    mostrarTodosLosProductos( prod, prodTam, prov, provTam );
    codigoProducto = getInt("Ingrese codigo del producto a eliminar: ");

    verificacion = buscarProducto( prod, prodTam, codigoProducto );
    if( verificacion == -1)
    {
        reg = -1 ;
    }
    else
    {
        system("cls");
        printf("                   <<< ELIMINARA EL SIGUIENTE producto >>>\n");
        mostrarProducto( prod[verificacion], prov, provTam, 1 );

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
/** \brief Permite al usuario modificar datos de un producto de un vector de productos .
 *
 * \param prod : Vector de productos donde el usuario buscara.
 * \param prodTam : Tamaño del vector de productos .
 * \param prov : Vector de proveedores asociado al vector de productos .
 * \param provTam : Tamaño del vector de proveedores .
 * \return Devuelve -1 si el producto a modificar no existe, 0 si se encontro un producto y no se modifico y un entero
 * \return positivo si se realizo alguna modificacion a un producto .
 *
 */

int modificarProducto ( eProductos prod[], int prodTam, eProveedores prov[], int provTam )
{
    char descripcion[50] ;
    int codigoProducto, seleccion, codigoProductoRepetido, codigoDelProveedor, verificacion, indiceProductoCodigo ;
    int reg = -1, salir = 0;

    system("cls");
    mostrarTodosLosProductos( prod, prodTam, prov, provTam );

    codigoProducto = getInt("Ingrese el codigo del producto que desea modificar: ");
    indiceProductoCodigo = buscarProducto( prod, prodTam, codigoProducto );

    if( indiceProductoCodigo > -1)
    {
        reg = 0 ;
        system("cls");
        printf("                   <<< Modificara el siguiente producto >>>\n");
        mostrarProducto( prod[indiceProductoCodigo], prov, provTam, 1);

        if(validateDualExit("\nConfirmar? s/n : ","\nNo se reconoce su respuesta.\nReingrese: ",'s','n') == 1)
        {
            do
            {
                xlkNoLineHeadGenerator("Modificar producto :");
                mostrarProducto( prod[indiceProductoCodigo], prov, provTam, 1);
                xlkNoLineIndexBodyGenerator(6,"1-Cambiar codigo de producto.","2-Cambiar descripcion.","3-Cambiar cantidad.","4-Cambiar importe.","5-Cambiar proveedor.","0-Volver.");
                seleccion = getInt("- Seleccionar opcion: ");
                switch(seleccion)
                {
                case 1:
                    codigoProducto = getConditionedInt(1,1,"\nIngrese nuevo codigo de producto : ","Se proujo un error al validar, reingrese codigo de producto : ");
                    codigoProductoRepetido = buscarProducto( prod, prodTam, codigoProducto );
                    if( codigoProductoRepetido > -1 )
                    {
                        printf("\n* El codigo de producto que intenta cargar se encuentra en uso.\n\n");

                    }
                    else if( validateDualExit("\nAplicar cambio? s/n : ","\nNo se reconoce su respuesta.\nReingrese: ",'s','n') == 1 && codigoProductoRepetido == -1)
                    {
                        prod[indiceProductoCodigo].codigoProducto = codigoProducto;
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
                    getRangedStr(2,49,"\nCambiar descripcion : "," Se produjo un error al validar, reingrese descripcion : ", descripcion );
                    xstrCapsSpaceFixer( descripcion );
                    xstrCapsAdder( descripcion );
                    strcpy( prod[indiceProductoCodigo].descripcion, descripcion );
                    printf("\n* Modificacion realizada.\n\n");
                    reg ++ ;
                    system("pause");
                    break;
                case 3:
                    prod[indiceProductoCodigo].cantidad = getConditionedInt(0,1,"\nCambiar stock del producto : ","Se produjo un error al validar el stock ...\nReingrese: ");
                    printf("\n* Modificacion realizada.\n\n");
                    reg ++ ;
                    system("pause");
                    break;
                case 4:
                    prod[indiceProductoCodigo].importe = getConditionedFloat(0,1,"\nCambiar importe : $"," Se produjo un error al validaR, reingrese importe : ");
                    printf("\n* Modificacion realizada.\n\n");
                    reg ++ ;
                    system("pause");
                    break;
                case 5:

                    system("cls");
                    mostrarTodosLosProveedores( prov, provTam );
                    codigoDelProveedor = getInt("\nCambiar codigo de proveedor: ");
                    verificacion = buscarProveedor( prov, provTam, codigoDelProveedor );
                    if( verificacion != -1)
                    {
                        prod[indiceProductoCodigo].codigoProveedor = codigoDelProveedor ;
                        printf("\n* Modificacion realizada.\n\n");
                        reg ++ ;
                    }
                    else
                    {
                        printf("\n* proveedor inexistente.\n\n");
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
/** \brief Ordena productos por 3 criterios: 1- descripcion , 2- importe ,  3- codigo de producto .
 *
 * \param prod : Vector de productos a ordenar.
 * \param prodTam : Tamaño del vector de productos .
 * \return
 *
 */

void ordenarProductos( eProductos prod[], int prodTam )
{
    for(int i = 0; i < prodTam - 1; i++)
    {
        for(int j = i+1; j < prodTam ; j++)
        {
            if(stricmp( prod[j].descripcion, prod[i].descripcion ) < 0)
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
/** \brief Define el estado de un vector de proveedores en 0.
 *
 * \param prov : Vector de proveedores a inicializar.
 * \param provTam : Tamaño del vector de proveedores .
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
/** \brief Muestra todos los proveedores de un vector de proveedores .
 *
 * \param prov: Vector de proveedores a mostrar.
 * \param provTam: Tamaño del vector de proveedores .
 * \return
 *
 */

void mostrarTodosLosProveedores( eProveedores prov[], int provTam )
{
    printf("                       >>> Lista de proveedores <<<\n");
    printf("--------------------------------------------------------------------------------");
    printf(" codigo de proveedor:\t\t descripcion :\n");
    printf("--------------------------------------------------------------------------------\n");
    for(int i=0; i< provTam ; i++)
    {
        if( prov[i].isBusy == 1)
        {
            printf(" %d\t\t\t\t %-30s\n", prov[i].codigoProveedor, prov[i].descripcion );
        }
    }
    printf("\n--------------------------------------------------------------------------------\n");
}


//XE2-7
/** \brief Muestra un proveedor .
 *
 * \param provVar: Variable de tipo eProveedores a mostrar.
 * \return
 *
 */

void mostrarProveedor( eProveedores provVar )
{
    printf("--------------------------------------------------------------------------------");
    printf(" codigo de proveedor:\t\t descripcion :\n");
    printf("--------------------------------------------------------------------------------\n");
    printf(" %d\t\t\t\t %-30s\n", provVar.codigoProveedor, provVar.descripcion );
    printf("\n--------------------------------------------------------------------------------\n");
}



// ABM dependencias:


//XE2-8
/** \brief Busca un indice libre en un vector de proveedores .
 *
 * \param prov : Vector de proveedores a revisar.
 * \param tam : Tamaño del vector de proveedores .
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
/** \brief Revisa un vector de proveedores para determinar si un proveedor se encuentra en el vector.
 *
 * \param prov : Vector de proveedores a revisar.
 * \param tam : Tamaño del vector de proveedores .
 * \param codigoDelProveedor : codigo de proveedora buscar en el vector.
 * \return devuelve -1 si no encontro el proveedor o el indice del vector donde se halla.
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
/** \brief Da de alta un nuevo proveedor en el sistema.
 *
 * \param prov : Vector de proveedores donde dar de alta un nuevo proveedor .
 * \param provTam : Tamaño del vector de proveedores .
 * \return Devuelve -1 si no hay espacio para crear un proveedor , 0 si se produjo un error al validar algun dato o
 * \return 1 si el proveedor se creo con exito.
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
        codigoDelProveedor = getConditionedInt(1,1,"\nIngrese codigo del proveedor a asignar (Debe ser mayor a 0): ","\nNumero invalido, reingrese: ");
        verificacion = buscarProveedor( prov, provTam, codigoDelProveedor );
        if(verificacion == -1)
        {
            reg = 1 ;
            prov[indiceLibre].codigoProveedor = codigoDelProveedor ;
            getRangedStr(2,49,"\nIngrese descripcion del proveedor : ","\nSe produjo un error al validar, reingrese la descripcion del proveedor: ", prov[indiceLibre].descripcion );
            xstrCapsSpaceFixer(prov[indiceLibre].descripcion);
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
/** \brief Da de baja un proveedor del sistema y asigna a los productos el proveedor un equivalente a "Sin asignar".
 *
 * \param prov : Vector de proveedores donde buscar un proveedor para dar de baja.
 * \param provTam : Tamaño del vector proveedores .
 * \param prod : vector de productos a revisar si corresponde con un proveedor dado de baja.
 * \param prodTam : Tamaño del vector de productos .
 * \return Devuelve -1 si no se encontro un proveedor , 0 si se encontro uno y el usuario anulo la baja o 1 si se concreto
 * \return la baja de un proveedor .
 *
 */

int bajaProveedor( eProveedores prov[], int provTam, eProductos prod[], int prodTam )
{
    int codigoDelProveedor, reg ;
    int verificacion ;

    system("cls");
    mostrarTodosLosProveedores( prov, provTam );

    codigoDelProveedor = getInt("Ingrese codigo de proveedor a eliminar: ");
    verificacion = buscarProveedor( prov, provTam, codigoDelProveedor );
    if( verificacion == -1)
    {
        reg = -1 ;
    }
    else
    {
        system("cls");
        printf("                   <<< Eliminara al siguiente proveedor >>>\n");
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
/** \brief Permite al usuario modificar datos de un proveedor de un vector de proveedores .
 *
 * \param prov : Vector de proveedores donde el usuario buscara un proveedor a modificar.
 * \param provTam : Tamaño del vector de proveedores .
 * \param prod : vector de productos asociado.
 * \param prodTam : Tamaño del vector de productos  asociado .
 * \return Devuelve -1 si el proveedor a modificar no existe, 0 si se encontro un proveedor y no se modifico y un entero
 * \return positivo si se realizo alguna modificacion.
 *
 */

int modificarProveedor( eProveedores prov[], int provTam, eProductos prod[], int prodTam )
{
    int codigoDelProveedor ;
    int salir = 0, seleccion, verificacion, reg = 0, verif, i ;
    char descripcion[50] ;

    system("cls");
    mostrarTodosLosProveedores( prov, provTam );

    codigoDelProveedor = getInt("\nIngrese codigo de proveedora modificar: ");
    verificacion = buscarProveedor( prov, provTam, codigoDelProveedor );

    if( verificacion > -1)
    {
        system("cls");
        printf("                   <<< Modificara al siguiente proveedor >>>\n");
        mostrarProveedor( prov[verificacion] );

        if(validateDualExit("\nConfirmar? s/n : ","\nNo se reconoce su respuesta.\nReingrese: ",'s','n') == 1)
        {
            do
            {
                xlkNoLineHeadGenerator("Modificar proveedor :");
                mostrarProveedor( prov[verificacion] );
                xlkNoLineIndexBodyGenerator(3,"1-Cambiar codigo de proveedor.","2-Cambiar descripcion.","0-Volver.");
                seleccion = getInt("- Seleccionar opcion: ");

                switch( seleccion )
                {
                case 1:
                    codigoDelProveedor = getConditionedInt(1,1,"\nIngrese nuevo codigo de proveedor(Debe ser mayor a 0): ","\nSe produjo un error al validar.\nRecuerde que un codigo de proveedordebe ser mayor a 0.\nReingrese: ");
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
                        printf("El codigo de proveedorque intenta cargar se encuentra en uso:\n");
                    }
                    system("pause");
                    break;
                case 2:
                    getRangedStr(2,50,"\nIngrese nueva descripcion : ","\nSe produjo un error al validar, reingrese descripcion : ", descripcion );
                    xstrCapsSpaceFixer( descripcion );
                    strcpy( prov[verificacion].descripcion, descripcion );
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
/** \brief Muestra el menu de acciones de productos .
 *
 * \param prod : Vector de productos .
 * \param prodTam : Tamaño del vector de productos .
 * \param prov : Vector de proveedores asociado.
 * \param provTam : Tamaño del vector de proveedores asociado.
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
        xlkIndexGenerator(" Productos ",4,"1-Alta.","2-Baja.","3-Modificacion.","0-Volver.");
        seleccion = getInt("-  Seleccionar opcion: ");
        switch(seleccion)
        {
        case 1:
            printf("\n* Agregar nuevo producto :\n");
            functionValueReceiver = altaProducto( prod, prodTam, prov, provTam );
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
                printf("* No se ha encontrado el producto especificado.\n\n");
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
                printf("* No se ha encontrado el producto especificado.\n\n");
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
/** \brief Muestra el menu de acciones de los proveedores .
 *
 * \param prod : Vector de productos asociado.
 * \param prodTam : Tamaño del vector de productos asociado.
 * \param prov : Vector de proveedores .
 * \param provTam : Tamaño del vector de proveedores .
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
        xlkIndexGenerator(" Proveedores ",4,"1-Alta.","2-Baja.","3-Modificacion.","0-Volver.");
        seleccion = getInt("-  Seleccionar opcion: ");
        switch(seleccion)
        {
        case 1:
            printf("\n* Agregar un nuevo proveedor :\n");
            functionValueReceiver = altaProveedor( prov, provTam );
            if(functionValueReceiver == -1)
            {
                printf("* No hay espacio suficiente para realizar mas altas de este tipo.\n\n");
            }
            else if(functionValueReceiver == 0)
            {
                printf("* El codigo de proveedor que intenta asignar se encuentra en uso.\n\n");
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
                printf("* No se ha encontrado el proveedor especificado.\n\n");
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
            functionValueReceiver = modificarProveedor( prov, provTam, prod, prodTam );
            if(functionValueReceiver == -1)
            {
                printf("* No se ha encontrado el proveedor especificado.\n\n");
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



/** \brief Muestra un menu de informes de productos .
 *
 * \param prod : Vector de productos asociado.
 * \param prodTam : Tamaño del vector de productos asociado.
 * \return
 *
 */

void mostrarMenuInformar( eProductos prod[], int prodTam, eProveedores prov[], int provTam )
{
    int seleccion ;
    int exit = 0;

    do
    {
        xlkIndexGenerator("Informes",5,"1-Total y promedio de importes, productos que lo superan.","2-Total y promedio de importes, productos que NO lo superan.","3-Cantidad de productos con stock menor o igual a 10.","4-Cantidad de productos con stock mayor a 10.","0-Volver.");
        seleccion = getInt("-  Seleccionar opcion: ");
        switch(seleccion)
        {
        case 1:
            prodMostrarImportesMayoresAlPromedio(prod, prodTam, prov, provTam);
            system("pause");
            break;
        case 2:
            prodMostrarImportesMenoresAlPromedio(prod , prodTam , prov , provTam);
            system("pause");
            break;
        case 3:
            prodMostrarStocksMenorIgual10(prod , prodTam , prov , provTam);
            system("pause");
            break;
        case 4:
            prodMostrarStocksMayor10(prod , prodTam , prov , provTam);
            system("pause");
            break;
        case 0:
            exit = 1;
            break;
        default:
            printf("Opcion invalida.");
            system("pause");
            break;
        }
    }
    while(exit == 0);
}


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
    int flag = 0;
    int i;
    for(i = 0 ; i < prodTam ; i++ )
    {
        if( prod[i].isBusy == 1)
        {
            acumulador += prod[i].importe ;
            contador++;
        }
    }
    promedio = acumulador / contador ;
    printf("--------------------------------------------------------------------------------");
    printf("\n Suma de importes: %.2f\n",acumulador);
    printf(" Promedio de importes: %.2f\n\n",promedio);
    printf("--------------------------------------------------------------------------------");
    printf("             Productos que superan el promedio de importes:\n");
    for (i = 0 ; i < prodTam ; i++)
    {
        if( flag == 0 && prod[i].isBusy == 1 && prod[i].importe > promedio)
        {
            mostrarProducto( prod[i], prov, provTam, 0);
            flag++;
        }
        else if(prod[i].isBusy == 1 && prod[i].importe > promedio)
        {
            mostrarProducto( prod[i], prov, provTam, -1);
        }
    }
    printf("\n--------------------------------------------------------------------------------\n\n");
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
    int flag = 0;
    int i;
    for(i = 0 ; i < prodTam ; i++ )
    {
        if( prod[i].isBusy == 1)
        {
            acumulador += prod[i].importe ;
            contador++;
        }
    }
    promedio = acumulador / contador ;
    printf("--------------------------------------------------------------------------------");
    printf("\n Suma de importes: %.2f\n",acumulador);
    printf(" Promedio de importes: %.2f\n\n",promedio);
    printf("--------------------------------------------------------------------------------");
    printf("             Productos que NO superan el promedio de importes:\n");
    for (i = 0 ; i < prodTam ; i++)
    {
        if( flag == 0 && prod[i].isBusy == 1 && prod[i].importe < promedio)
        {
            mostrarProducto( prod[i], prov, provTam, 0);
            flag++;
        }
        else if(prod[i].isBusy == 1 && prod[i].importe < promedio)
        {
            mostrarProducto( prod[i], prov, provTam, -1);
        }
    }
    printf("\n--------------------------------------------------------------------------------\n\n");
}


/** \brief Muestra productos con stock menor o igual a 10.
 *
 * \param prod : Vector de productos asociado.
 * \param prodTam : Tamaño del vector de productos asociado.
 * \param prov : Vector de proveedores .
 * \param provTam : Tamaño del vector de proveedores .
 *
 */

void prodMostrarStocksMenorIgual10 ( eProductos prod[] , int prodTam ,eProveedores prov[] , int provTam)
{
    system("cls");
    int flag = 0;
    int i;
    printf("--------------------------------------------------------------------------------");
    printf("             Productos con stock menor o igual a 10:\n");
    for (i = 0 ; i < prodTam ; i++)
    {
        if( flag == 0 && prod[i].isBusy == 1 && prod[i].cantidad <= 10)
        {
            mostrarProducto( prod[i], prov, provTam, 0);
            flag++;
        }
        else if(prod[i].isBusy == 1 && prod[i].cantidad <= 10 )
        {
            mostrarProducto( prod[i], prov, provTam, -1);
        }
    }
    printf("\n--------------------------------------------------------------------------------\n\n");
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
    int flag = 0;
    int i;
    printf("--------------------------------------------------------------------------------");
    printf("             Productos con stock mayor a 10:\n");
    for (i = 0 ; i < prodTam ; i++)
    {
        if( flag == 0 && prod[i].isBusy == 1 && prod[i].cantidad > 10)
        {
            mostrarProducto( prod[i], prov, provTam, 0);
            flag++;
        }
        else if(prod[i].isBusy == 1 && prod[i].cantidad > 10 )
        {
            mostrarProducto( prod[i], prov, provTam, -1);
        }
    }
    printf("\n--------------------------------------------------------------------------------\n\n");
}
