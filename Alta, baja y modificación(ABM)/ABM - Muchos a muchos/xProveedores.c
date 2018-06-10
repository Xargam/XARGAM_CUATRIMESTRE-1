#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xProveedores.h"

#include "xget.h"
#include "xvalidate.h"
#include "xstring.h"
#include "xlook.h"


// Funciones de HARCODEO de estructuras:

//eProducto:


//XE1-1
/** \brief Carga datos a modo hardcode en los 3 primeros indices de un vector de empleados.
 *
 * \param emp: Vector de empleados a hardcodear.
 * \return
 *
 */
/*
void hardCodearProd(eProductos prod[])
{
    strcpy(emp[1].nombre, "Leito");
    emp[1].sueldo = 25445;
    emp[1].sexo = 'm';
    emp[1].legajo = 2525;
    emp[1].idSector = 1;
    emp[1].isBusy = 1;
    emp[1].fechaIngreso.anio = 1996;
    emp[1].fechaIngreso.mes = 07;
    emp[1].fechaIngreso.dia = 2;

    strcpy(emp[0].nombre, "Nancy");
    emp[0].sueldo = 28456;
    emp[0].sexo = 'f';
    emp[0].legajo = 2526;
    emp[0].idSector = 1;
    emp[0].isBusy = 1;
    emp[0].fechaIngreso.anio = 1997;
    emp[0].fechaIngreso.mes = 07;
    emp[0].fechaIngreso.dia = 2;

    strcpy(emp[2].nombre, "Nahuel");
    emp[2].sueldo = 30456;
    emp[2].sexo = 'm';
    emp[2].legajo = 2527;
    emp[2].idSector = 1;
    emp[2].isBusy = 1;
    emp[2].fechaIngreso.anio = 1998;
    emp[2].fechaIngreso.mes = 07;
    emp[2].fechaIngreso.dia = 2;
}


*/
//eSector:


//XE1-2
/** \brief Carga datos a modo hardcode en los 5 primeros indices de un vector de sectores.
 *
 * \param sec: Vector de sectores a hardcodear
 * \return
 *
 */
/*
void hardCodearSec(eSector sec[])
{
    sec[0].idSector = 1;
    sec[1].idSector = 2;
    sec[2].idSector = 3;
    sec[3].idSector = 4;
    sec[4].idSector = 5;
    strcpy(sec[0].descripcion,"RRHH");
    strcpy(sec[1].descripcion,"Sistemas");
    strcpy(sec[2].descripcion,"Administracion");
    strcpy(sec[3].descripcion,"Deposito");
    strcpy(sec[4].descripcion,"Compras");
    sec[0].isBusy = 1;
    sec[1].isBusy = 1;
    sec[2].isBusy = 1;
    sec[3].isBusy = 1;
    sec[4].isBusy = 1;
}

*/

//Funciones exclusivas eEmpleado:

//Basico:


//XE1-3
/** \brief Inicializa el estado de los empleados de un vector en 0 para ser leidos como desocupados.
 *
 * \param vec: Vector de empleados a inicializar.
 * \param tam: Cantidad de elementos del vector.
 * \return
 *
 */

void inicializarProductos(eProductos prod[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        prod[i].status = 0;
    }
}



//Funciones de muestra:


//XE1-4
/** \brief muestra a todos los empleados separados segun al sector al que pertenezcan.
 *
 * \param emp: Vector de empleados a mostrar.
 * \param empTam: Tamaño del vector de empleados.
 * \param sec: Vector de sectores a mostrar.
 * \param secTam: Tamaño del vector de sectores.
 * \param
 * \return
 *
 */
/*
void mostrarEmpleadosPorSector(eEmpleado emp[],int empTam,eSector sec[],int secTam)
{
    system("cls");
    int flag = 0;
    int i, j;
    for( i = 0; i < secTam; i++)
    {
        if(sec[i].isBusy == 1)
        {
            for(int j = 0; j < empTam; j++)
            {
                if(sec[i].idSector == emp[j].idSector && emp[j].isBusy == 1)
                {
                    if(flag == 0)
                    {
                        printf("--------------------------------------------------------------------------------");
                        printf("Empleados del sector %s:\n",sec[i].descripcion);
                        printf("--------------------------------------------------------------------------------\n");
                        printf("SECTOR:\t\tLEGAJO:\tNOMBRE:\t\tSEXO:\tSUELDO:\t\tFECHA INGRESO:\n\n");
                        flag++;
                    }
                    printf(" %-15s%-8d%-16s%c\t%-16.2f%d/%d/%d\n",sec[i].descripcion,emp[j].legajo,emp[j].nombre,emp[j].sexo,emp[j].sueldo,emp[j].fechaIngreso.dia,emp[j].fechaIngreso.mes,emp[j].fechaIngreso.anio);
                }
                if(j == empTam-1 && flag == 1)
                {
                    printf("\n--------------------------------------------------------------------------------\n");
                }
            }
            flag = 0;
        }
    }
    for( j = 0; j < empTam; j++)
    {
        if(emp[j].isBusy == 1)
        {
            if(emp[j].idSector == 0 && flag == 0)
            {
                flag++;
                printf("--------------------------------------------------------------------------------");
                printf("Empleados sin sector asignado:\n");
                printf("--------------------------------------------------------------------------------\n");
                printf("LEGAJO:\tNOMBRE:\t\tSEXO:\tSUELDO:\t\tFECHA INGRESO:\n\n");
                printf(" %-8d%-16s%c\t%-16.2f%d/%d/%d\n",emp[j].legajo,emp[j].nombre,emp[j].sexo,emp[j].sueldo,emp[j].fechaIngreso.dia,emp[j].fechaIngreso.mes,emp[j].fechaIngreso.anio);
            }
            else if(emp[j].idSector == 0)
            {
                printf(" %-8d%-16s%c\t%-16.2f%d/%d/%d\n",emp[j].legajo,emp[j].nombre,emp[j].sexo,emp[j].sueldo,emp[j].fechaIngreso.dia,emp[j].fechaIngreso.mes,emp[j].fechaIngreso.anio);
            }
        }
    }
    if(flag == 1)
    {
        printf("\n--------------------------------------------------------------------------------\n");
    }
}
*/

//XE1-5
/** \brief Muestra todos los empleados de un array de empleados.
 *
 * \param emp: Vector de empleados a mostrar.
 * \param tamEmp: Tamaño del vector de empleados.
 * \param sec: Vector de sectores asociado al vector de empleados.
 * \param tamSec: Tamaño del vector de sectores.
 * \return
 *
 */

void mostrarTodosLosProductos(eProductos prod[], int tamProd)
{
    system("cls");
    printf("---------------------------Lista de Productos-----------------------------------\n");
    printf("CODIGO\tDESCRIPCION:\tSTOCK:\tIMPORTE:\n");
    printf("\n\n");
    for(int i=0; i< tamProd; i++)
    {
        if(prod[i].status == 1)
        {
            printf(" %d\t%15s\t%d\t%.2f\n",prod[i].codigoProducto,prod[i].descripcion,prod[i].cantidad,prod[i].importe);
        }

    }
    printf("\n--------------------------------------------------------------------------------\n");
}


//XE1-6
/** \brief Muestra UN empleado.
 *
 * \param emp: Variable de tipo eEmpleado a mostrar.
 * \param sec: Vector de sectores asociado al empleado.
 * \param tamSec: tamaño del vector de sectores.
 * \return
 *
 */

void mostrarProducto(eProductos prod)
{
    printf("DESCRIPCION:\tSTOCK:\tIMPORTE:\n");
    printf(" %15s\t\t%d\t\t%.2f\n",prod.descripcion,prod.cantidad,prod.importe);
}



// ABM dependencias:


//XE1-7
/** \brief Recorre un vector de empleados y revisa si existe un legajo determinado como parametro,
 *
 * \param vec: Vector de empleados a revisar.
 * \param tam: Tamaño del vector.
 * \param legajo: Legajo a buscar si esta en el vector.
 * \return Devuelve -1 si el legajo no se encuentra en el vector o el numero de indice de donde se ha repetido.
 *
 */

int buscarProducto(eProductos prod[], int tam, int IDProducto)
{
    int index = -1;
    for(int i=0; i < tam; i++)
    {
        if(prod[i].status == 1 && prod[i].codigoProducto == IDProducto)
        {
            index = i;
            break;
        }
    }
    return index;
}


//XE1-8
/** \brief Busca un indice libre en un array de empleados.
 *
 * \param emp: Array de empleados a revisar.
 * \param tam: Tamaño del array.
 * \return
 *
 */

int buscarIndiceLibreProducto(eProductos prod[], int tam)
{
    int index = -1;
    for(int i=0; i < tam; i++)
    {
        if(prod[i].status == 0)
        {
            index= i;
            break;
        }
    }
    return index;
}


//XE1-9
/** \brief Pide datos de un empleado validando que legajo no exista y que se le asigne un sector existente.
 *
 * \param emp: Vector de empleados donde verificar legajos.
 * \param empTam: Tamaño del vector de empleados.
 * \param sec: Vector de sectores donde verificar sectores posibles para el nuevo empleado.
 * \param tamSec: Tamaño del vector de sectores.
 * \return Devuelve una variable de tipo de eEmpleado cargada de datos.
 *
 */

eProductos pedirProducto(eProductosProveedores linker[],int linkerTam, eProveedores prov[],int tamProv)
{
    eProductos nuevoProducto;

    int id, verificacion;
    int indiceLibre;
    char descripcion[50];

    mostrarTodosLosProveedores(prov,tamProv);
    id = getInt("\nIngrese el codigo de proveedor de este producto: ");
    verificacion = buscarProveedores(prov,tamProv,id);
    if(verificacion != -1)
    {
        indiceLibre = BuscarIndiceLibreProductosProveedores(linker,linkerTam);
        linker[indiceLibre].codigoProveedor = id;

        printf("\n-  El proveedor ha sido asociado correctamente.\n\n");
        system("pause");
        system("cls");
        getRangedStr(2,49,"Ingrese descripcion del producto: ","Descripcion invalida, reingrese: ",descripcion);
        xstrCapsSpaceFixer(descripcion);
        strcpy(nuevoProducto.descripcion,descripcion);
        nuevoProducto.importe = getConditionedFloat(0,1,"\nIngrese importe del producto: $","Importe invalido, reingrese: ");
        printf("\n");
        nuevoProducto.cantidad = getConditionedInt(0,1,"\nIngrese stock disponible del producto: ","Stock invalido, reingrese: ");
        nuevoProducto.status = 1;
    }
    else
    {
        printf("\nEl proveedor no se ha encontrado.");
    }
    return nuevoProducto;
}



//ALTA BAJA MODIFICACION:


//XE2-1
/** \brief Da de alta un nuevo empleado al sistema verificando que el legajo no se repita y que se elija un sector
 * \brief correcto.
 *
 * \param emp: vector donde se dara de alta el empleado.
 * \param tam: cantidad de elementos del vector.
 * \param sec: vector de sectores asociado a empleados.
 * \param tamSec: cantidad de elementos del vector de sectores.
 * \return devuelve -1 si no hay espacio para dar de alta un empleado, 0 si se produjo un error al validar legajo o
 * \return sector o 1 si el empleado fue dado de alta correctamente.
 *
 */

int altaProducto(eProductos prod[], int tam,eProveedores prov[],int tamProv,eProductosProveedores linker[], int tamLinker,int* IDProd)
{
    int reg;
    int indiceLibre = buscarIndiceLibreProducto(prod,tam);
    int id = *IDProd;

    if(indiceLibre == -1)
    {
        reg = -1;
    }
    else
    {
        prod[indiceLibre] = pedirProducto(linker,tamLinker,prov,tamProv);
        if(prod[indiceLibre].status == 0)
        {
            reg = 0;
        }
        else
        {
            prod[indiceLibre].codigoProducto = ++id;
            indiceLibre = BuscarIndiceLibreProductosProveedores(linker,tamLinker);
            linker[indiceLibre].codigoProducto = id;
            linker[indiceLibre].status = 1;
            reg = 1;
        }
    }
    return reg;
}


//XE2-2
/** \brief Elimina un empleado del sistema.
 *
 * \param emp: Recibe un vector de empleados para que el usuario busque en el posibles empleados a borrar.
 * \param tam: Tamaño del vector de empleados.
 * \param sec: Vector de sectores de empleados.
 * \param tamSec: Tamaño del vector de sectores.
 * \return devuelve 1 si el empleado se encontro y se dio de baja, devuelve 0 si el empleado se encontro pero
 * \return no se dio de baja o devuelve -1 si el empleado no se encontro.
 *
 */

int bajaProducto(eProductos prod[],int tamProd)
{
    int reg = 0;
    int id;
    int verificacion; // Se almacena el indice recibido por buscarEmpleado() para determinar si el empleado existe.

    mostrarTodosLosProductos(prod,tamProd);
    id = getInt("Ingrese codigo del producto a eliminar: ");
    verificacion = buscarProducto(prod,tamProd,id);

    if(verificacion == -1)
    {
        reg = -1;
    }
    else
    {
        system("cls");
        printf("Dara de baja el siguiente producto: \n\n");
        mostrarProducto(prod[verificacion]);
        if(validateExit("\nConfirmar baja? s/n:\n",'s') == 1)
        {
            prod[verificacion].status = 0;
            reg = 1;
        }
        else
        {
            reg = 0;
        }
    }
    system("cls");
    return reg;
}


//XE2-3
/** \brief Permite al usuario modificar datos de un empleado de un vector de empleados.
 *
 * \param emp: Vector de empleados donde el usuario buscara.
 * \param tam: Tamaño del vector de empleados.
 * \param sec: Vector de sectores de empleados.
 * \param tam: Tamaño del vector de sectores.
 * \return Devuelve -1 si el empleado a modificar no existe, 0 si se encontro un empleado y no se modifico y un entero
 * \return positivo si se realizo alguna modificacion a un empleado.
 *
 */

int modificarProducto(eProductos prod[],int tamProd,eProveedores prov[],int tamProv)
{
    system("cls");

    int id;
    int verificacion;
    int salir = 0;
    int reg = -1;
    int seleccion;
    char descripcion[50];
    int cantidad;
    int importe;

    mostrarTodosLosProductos(prod,tamProd);
    id = getInt("\nIngrese el codigo del producto a modificar: ");
    verificacion = buscarProducto(prod,tamProd,id);

    if(verificacion > -1)
    {
        reg = 0;
        system("cls");
        printf("Va a modificar al siguiente producto:\n\n");
        mostrarProducto(prod[verificacion]);

        if(validateExit("\nConfirmar: s/n: ",'s') == 1)
        {
            do
            {
                xlkHeadGenerator("Modificar producto:");
                mostrarProducto(prod[verificacion]);
                xlkIndexBodyGenerator(4,"1-Modificar stock.","2-Modificar descripcion.","3-Modificar importe.","0-Volver.");
                seleccion = getInt("Seleccionar opcion: ");
                switch(seleccion)
                {
                case 1:

                    cantidad = getConditionedInt(0,1,"\nIngrese nuevo stock: ","stock invalido: ");
                    if(validateDualExit("\nConfirmar cambios? s/n : ","\nNo se reconoce su respuesta.\nReingrese: ",'s','n') == 1)
                    {
                        prod[verificacion].cantidad = cantidad;
                        printf("\n\nStock actualizado.\n\n");
                    }
                    else
                    {
                        printf("\n\nAccion cancelada.\n\n");
                    }
                    system("pause");
                    break;
                case 2:
                    getRangedStr(1,49,"\nIngrese nueva descripcion: ","Descripcion invalida, reingrese: ",descripcion);
                    xstrCapsSpaceFixer(descripcion);
                    if(validateDualExit("\nConfirmar cambios? s/n : ","\nNo se reconoce su respuesta.\nReingrese: ",'s','n') == 1)
                    {
                        strcpy(prod[verificacion].descripcion,descripcion);
                        printf("\n\nDescripcion actualizada.\n\n");
                    }
                    else
                    {
                        printf("\n\nAccion cancelada.\n\n");
                    }
                    reg++;
                    system("pause");
                    break;
                case 3:
                    importe = getConditionedFloat(0,1,"Ingrese nuevo importe: ","Importe invalido, reingrese: ");
                    if(validateDualExit("\nConfirmar cambios? s/n : ","\nNo se reconoce su respuesta.\nReingrese: ",'s','n') == 1)
                    {
                        prod[verificacion].importe = importe;
                        printf("\n\nImporte actualizado.\n\n");
                    }
                    else
                    {
                        printf("\n\nAccion cancelada.\n\n");
                    }
                    reg++;
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
            while(salir == 0);
        }
    }
    else
    {
        reg = -1;
    }
    system("cls");
    return reg;
}

//Adicionales:


//XE2-4
/** \brief Ordena empleados por 3 criterios: 1-Nombre, 2-Sueldo, 3-Leagajo
 *
 * \param emp: Vector de empleados a ordenar.
 * \param tam: Tamaño del vector de empleados.
 * \return
 *
 */
/*
void ordenarEmpleados(eEmpleado emp[], int tam)
{
    for(int i = 0; i < tam-1; i++)
    {
        for(int j = i+1; j <tam; j++)
        {
            if(stricmp(emp[j].nombre,emp[i].nombre) < 0)
            {
                eEmpleado aux;
                aux = emp[i];
                emp[i] = emp[j];
                emp[j] = aux;
            }
            else if(stricmp(emp[j].nombre,emp[i].nombre) == 0)
            {
                if(emp[j].sueldo > emp[i].sueldo)
                {
                    eEmpleado aux;
                    aux = emp[i];
                    emp[i] = emp[j];
                    emp[j] = aux;
                }
                else if(emp[j].sueldo == emp[i].sueldo )
                {
                    if(emp[j].legajo > emp[i].legajo)
                    {
                        eEmpleado aux;
                        aux = emp[i];
                        emp[i] = emp[j];
                        emp[j] = aux;
                    }
                }

            }
        }
    }
}

*/

//Funciones exclusivas de eProveedores:

//Basico:


//XE2-5
/** \brief Define el estado de un vector de sectores en 0.
 *
 * \param sec: Vector de sectores a inicializar.
 * \param tam: Tamaño del vector.
 * \return
 *
 */

void inicializarProveedores(eProveedores prov[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        prov[i].status = 0;
    }
}



//Funciones de muestra:


//XE2-6
/** \brief Muestra todos los sectores de un vector de sectores.
 *
 * \param sec: Vector de sectores a mostrar.
 * \param tamSec: Tamaño del vector.
 * \return
 *
 */

void mostrarTodosLosProveedores(eProveedores prov[], int tamProv)
{
    system("cls");
    printf("-------------Lista de proveeedores------------------------------------------\n");
    printf("\nCODIGO DE PROVEEDOR:\t\tDESCRIPCION:\n\n");
    for(int i=0; i< tamProv; i++)
    {
        if(prov[i].status == 1)
        {
            printf(" %d\t\t\t%s\n",prov[i].codigoProveedor,prov[i].descripcion);
        }
    }
    printf("\n--------------------------------------------------------------------------------\n");
}


//XE2-7
/** \brief Muestra un sector.
 *
 * \param Variable de tipo eSector a mostrar.
 * \return
 *
 */

void mostrarProveedor(eProveedores prov)
{
    printf(" Codigo de Proveedor:\t\tDescripcion:\n\n");
    printf(" %d\t\t\t%s\n",prov.codigoProveedor,prov.descripcion);
}



// ABM dependencias:


//XE2-8
/** \brief Busca un indice libre en un vector de sectores.
 *
 * \param sec: Vector de sectores a revisar.
 * \param tam: Tamaño del vector.
 * \return devuelve -1 si no hay espacio en el vector o un indice libre si lo halla.
 *
 */

int buscarIndiceLibreProvedoores(eProveedores prov[], int tam)
{
    int index = -1;
    for(int i=0; i < tam; i++)
    {
        if(prov[i].status == 0)
        {
            index= i;
            break;
        }
    }
    return index;
}


//XE2-9
/** \brief Revisa un vector de sectores para determinar si una id pasada por parametro se encuentra dentro del mismo.
 *
 * \param sec: Vector de sectores a revisar.
 * \param tam: Tamaño del vector.
 * \param id: ID de sector a buscar  en el vector.
 * \return devuelve -1 si no encontro el ID o el indice del vector donde se halla dicha ID.
 *
 */

int buscarProveedores(eProveedores prov[],int tamProv,int IDProveedor)
{
    int index = -1;
    for(int i = 0; i < tamProv; i++)
    {
        if(prov[i].codigoProveedor == IDProveedor && prov[i].status == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}



//ALTA BAJA MODIFICACION:


//XE3-1
/** \brief Da de alta un nuevo sector en el sistema.
 *
 * \param sec: Vector de sectores donde dar de alta un nuevo sector.
 * \param tam: Tamaño del vector.
 * \return Devuelve -1 si no hay espacio para crear un sector o 0 si la id ingresada por el usuario ya existe o
 * \return 1 si el sector se crea con exito.
 *
 */

int altaProveedor(eProveedores prov[],int tam, int* IDProveedor)
{
    char descripcion[50];
    int indiceLibre;
    int reg = -1;
    int ID = *IDProveedor;

    indiceLibre = buscarIndiceLibreProvedoores(prov,tam);

    if(indiceLibre != -1)
    {
        getRangedStr(1,49,"Ingrese la descripcion del proveedor: ","\nDescripcion invalida, reingrese: ",descripcion);
        strcpy(prov[indiceLibre].descripcion, descripcion);
        prov[indiceLibre].codigoProveedor = ++ID;
        prov[indiceLibre].status = 1;
    }
    else
    {
        reg = 0;
    }
    system("cls");
    return reg;
}


//XE3-2
/** \brief Da de baja un sector del sistema.
 *
 * \param sec: Vector de sectores donde buscar un sector para dar de baja.
 * \param tam: Tamaño del vector.
 * \return Devuelve -1 si no se encontro un sector, 0 si se encontro uno y el usuario anulo la baja o 1 si se concreto
 * \return la baja de un sector.
 *
 */

int bajaProveedor(eProveedores prov[],int tamProv)
{
    int id;
    int reg = 0;
    int verificacion;

    mostrarTodosLosProveedores(prov,tamProv);

    id = getInt("Ingrese ID del proveedor a eliminar: ");
    verificacion = buscarProveedores(prov,tamProv,id);
    system("cls");
    if(verificacion == -1)
    {
        reg = -1;
    }
    else
    {
        printf("Dara de baja al siguiente proveedor: \n\n");
        mostrarProveedor(prov[verificacion]);
        if(validateExit("\nConfirmar baja? s/n:\n",'s') == 1)
        {
            prov[verificacion].status = 0;

            /*for(int i = 0; i < tam; i++)
            {
                if(prod[verificacion].codigoProveedor == emp[i].idSector)
                {
                    emp[i].idSector = 0;
                }
            }
            */
            reg = 1;
        }
    }
    system("cls");
    return reg;
}


//XE3-3
/** \brief Permite al usuario modificar datos de un sector de un vector de sectores.
 *
 * \param sec: Vector de sectores donde el usuario buscara un sector a modificar.
 * \param tam: Tamaño del vector de sectores.
 * \return Devuelve -1 si el sector a modificar no existe, 0 si se encontro un sector y no se modifico y un entero
 * \return positivo si se realizo alguna modificacion.
 *
 */

int modificarProveedor(eProveedores prov[],int tamProv)
{
    int id;
    int salir = 0;
    int verificacion;
    int reg = 0;
    int seleccion;
    char descripcion[50];

    system("cls");
    printf("Lista de proveedores: ");
    mostrarTodosLosProveedores(prov,tamProv);

    id = getInt("\nIngrese el codigo del proveedor a modificar: ");
    verificacion = buscarProveedores(prov,tamProv,id);

    if(verificacion > -1)
    {
        system("cls");
        printf("Va a modificar el siguiente proveedor:\n\n");
        mostrarProveedor(prov[verificacion]);
        if(validateExit("\nConfirmar: s/n:\n",'s') == 1)
        {
            do
            {
                xlkHeadGenerator("Modificar proveedor:");
                mostrarProveedor(prov[verificacion]);
                xlkIndexBodyGenerator(2,"1-Cambiar descripcion.","0-Volver.");

                seleccion = getInt("Seleccionar opcion: ");

                switch(seleccion)
                {
                case 1:
                    getRangedStr(1,49,"Ingrese nueva descripcion: ","Descripcion invalida, reingrese: ",descripcion);
                    if(validateDualExit("\nConfirmar cambios? s/n : ","\nNo se reconoce su respuesta.\nReingrese: ",'s','n') == 1)
                    {
                        strcpy(prov[verificacion].descripcion,descripcion);
                        xstrCapsSpaceFixer(descripcion);
                        printf("\nDescrupcion actualizada.\n");
                        reg++;
                    }
                    else
                    {
                        printf("\n\nAccion cancelada.\n\n");
                    }
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
            while(salir == 0);
        }
    }
    else
    {
        reg = -1;
    }
    system("cls");
    return reg;
}



int BuscarIndiceLibreProductosProveedores(eProductosProveedores linker[], int tam)
{
    int index = -1;
    for(int i=0; i < tam; i++)
    {
        if(linker[i].status == 0)
        {
            index= i;
            break;
        }
    }
    return index;
}



void inicializarProductosProveedores(eProductosProveedores linker[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        linker[i].status = 0;
    }
}
