#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "xget.h"
#include "xlook.h"
#include "xvalidate.h"
#include "xstring.h"
#include "xProveedores.h"

#define TAM 5


int main()
{
    eProveedores proveedores[TAM];
    eProductos productos[TAM];
    eProductosProveedores linker[TAM*TAM];

    inicializarProductos(productos,TAM);
    inicializarProveedores(proveedores,TAM);
    inicializarProductosProveedores(linker,TAM*TAM);

    int seleccion;
    int exit = 0;
    //int functionValueReceiver;
    int IDProductos = 0;
    int IDProveedores = 0;

    do
    {
        xlkIndexGenerator("Microsoft Menu principal.",3,"1-Productos.","2-Proveedores.","3-Salir.");
        seleccion = getInt("-  Seleccionar opcion: ");
        switch(seleccion)
        {
        case 1:
            do
            {
                xlkIndexGenerator("Productos",5,"1-Alta.","2-Baja.","3-Modificacion.","4-Mostrar.","0-Volver.");
                seleccion = getInt("-  Seleccionar opcion: ");
                switch(seleccion)
                {
                case 1:
                    printf("\n* Agregar un nuevo producto:\n");
                    altaProducto(productos,TAM,proveedores,TAM,linker,TAM*TAM,&IDProductos);
                    /*if(functionValueReceiver == 1)
                    {
                        system("cls");
                        printf("El empleado fue dado de alta con exito.\n\n");
                    }
                    else if(functionValueReceiver == 0)
                    {
                        printf("\n\nEl empleado NO fue cargado en el sistema.\n\n");
                    }
                    else
                    {
                        system("cls");
                        printf("No hay espacio para dar de alta mas empleados.\n\n");
                    }
                    */
                    system("pause");
                    break;
                case 2:
                    bajaProducto(productos,TAM);
                    /*if(functionValueReceiver == -1)
                    {
                        printf("El legajo no existe en el sistema.\n\n");
                    }
                    else if(functionValueReceiver == 0)
                    {
                        printf("Accion cancelada.\n\n");
                    }
                    else
                    {
                        printf("La baja del empleado fue exitosa.\n\n");
                    }
                    */
                    system("pause");
                    break;
                case 3:
                    system("color 06");
                    modificarProducto(productos,TAM,proveedores,TAM);
                    /*if(functionValueReceiver == -1)
                    {
                        printf("El legajo buscado no existe en el sistema.\n\n");
                    }
                    else if(functionValueReceiver == 0)
                    {
                        printf("No se realizaron modificaciones.\n\n");
                    }
                    else
                    {
                        printf("Se modifico el empleado con exito.\n\n");
                    }
                    */
                    system("pause");
                    system("color 07");
                    break;
                case 4:
                    mostrarTodosLosProductos(productos,TAM);
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
            exit = 0;
            break;
        case 2:
            system("color 07");
            do
            {
                xlkIndexGenerator("Proveedores",5,"1-Alta.","2-Baja.","3-Modificacion.","4-Mostrar.","0-Volver.");
                seleccion = getInt("-  Seleccionar opcion: ");
                switch(seleccion)
                {
                case 1:
                    printf("\n* Agregar un nuevo proveedor:\n");
                    altaProveedor(proveedores,TAM,&IDProveedores);
                    /*
                    if(functionValueReceiver == -1)
                    {
                        printf("No hay espacio suficiente para dar de alta a mas sectores.\n\n");
                    }
                    else if(functionValueReceiver == 0)
                    {
                        printf("La ID que intenta asignar ya se encuentra en uso por otro sector.\n\n");
                    }
                    else
                    {
                        printf("Sector dado de alta en el sistema.\n\n");
                    }
                    */
                    system("pause");
                    break;
                case 2:
                    bajaProveedor(proveedores,TAM);
                    /*
                    if(functionValueReceiver == -1)
                    {
                        printf("No se ha encontrado el sector. No se realizo ninguna baja.\n\n");
                    }
                    else if(functionValueReceiver == 0)
                    {
                        printf("Accion cancelada. No se realizo ninguna baja.\n\n");
                    }
                    else
                    {
                        printf("Se dio de baja al sector exitosamente.\n\n");
                    }
                    */
                    system("pause");
                    break;
                case 3:
                    modificarProveedor(proveedores,TAM);
                    /*
                    if(functionValueReceiver == -1)
                    {
                        printf("No se ha encontrado el sector. No se realizaron modificaciones.\n\n");
                    }
                    else if(functionValueReceiver == 0)
                    {
                        printf("No se realizaron modificaciones.\n\n");
                    }
                    else
                    {
                        printf("La modificacion se aplico con exito.\n\n");
                    }
                    */
                    system("pause");
                    break;
                case 4:
                    mostrarTodosLosProveedores(proveedores,TAM);
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
            exit = 0;
            break;
        case 3:
            exit =validateESCExit();
            break;
        default:
            printf("\nOpcion invalida.\n\n");
            system("pause");
            break;
        }
    }
    while(exit == 0);
    return 0;
}
