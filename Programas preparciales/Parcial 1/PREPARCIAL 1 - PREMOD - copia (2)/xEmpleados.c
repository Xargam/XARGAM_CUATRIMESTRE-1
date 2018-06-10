#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xEmpleados.h"
#include "xget.h"
#include "xvalidate.h"
#include "xstring.h"
#include "xlook.h"


// Funciones de HARCODEO de estructuras:

// eEmpleados :


//XE1-1
/** \brief Carga datos a modo hardcode en los 3 primeros indices de un vector de EMPLEADOS .
 *
 * \param emp : Vector de EMPLEADOS a hardcodear.
 * \return
 *
 */

void harcodearEmp( eEmpleados emp[] )
{
    strcpy( emp[1].nombre , "Leito");
    emp[1].sueldo = 25445;
    emp[1].sexo = 'm';
    emp[1].legajo = 2525;
    emp[1].idSector = 1;
    emp[1].isBusy = 1;
    emp[1].fechaIngreso.anio = 1996;
    emp[1].fechaIngreso.mes = 07;
    emp[1].fechaIngreso.dia = 2;

    strcpy( emp[0].nombre , "Nancy");
    emp[0].sueldo = 28456;
    emp[0].sexo = 'f';
    emp[0].legajo = 2526;
    emp[0].idSector = 1;
    emp[0].isBusy = 1;
    emp[0].fechaIngreso.anio = 1997;
    emp[0].fechaIngreso.mes = 07;
    emp[0].fechaIngreso.dia = 2;

    strcpy( emp[2].nombre , "Nahuel");
    emp[2].sueldo = 30456;
    emp[2].sexo = 'm';
    emp[2].legajo = 2527;
    emp[2].idSector = 1;
    emp[2].isBusy = 1;
    emp[2].fechaIngreso.anio = 1998;
    emp[2].fechaIngreso.mes = 07;
    emp[2].fechaIngreso.dia = 2;
}



// eSectores :


//XE1-2
/** \brief Carga datos a modo hardcode en los 5 primeros indices de un vector de SECTORES .
 *
 * \param sec : Vector de SECTORES a hardcodear
 * \return
 *
 */

void harcodearSec( eSectores sec[] )
{
    sec[0].idSector = 1;
    sec[1].idSector = 2;
    sec[2].idSector = 3;
    sec[3].idSector = 4;
    sec[4].idSector = 5;
    strcpy( sec[0].descripcion,"RRHH");
    strcpy( sec[1].descripcion,"Sistemas");
    strcpy( sec[2].descripcion,"Administracion");
    strcpy( sec[3].descripcion,"Deposito");
    strcpy( sec[4].descripcion,"Compras");
    sec[0].isBusy = 1;
    sec[1].isBusy = 1;
    sec[2].isBusy = 1;
    sec[3].isBusy = 1;
    sec[4].isBusy = 1;
}



//Funciones exclusivas eEmpleados :

//Basico:


//XE1-3
/** \brief Inicializa el estado de los EMPLEADOS de un vector en 0 para ser leidos como desocupados.
 *
 * \param emp : Vector de EMPLEADOS a inicializar.
 * \param empTam : Cantidad de elementos del vector de EMPLEADOS .
 * \return
 *
 */

void inicializarEmpleados( eEmpleados emp[], int empTam )
{
    for(int i=0; i < empTam ; i++)
    {
        emp[i].isBusy = 0;
    }
}



//Funciones de muestra:


//XE1-4
/** \brief muestra a todos los EMPLEADOS por SECTOR .
 *
 * \param emp : Vector de EMPLEADOS a mostrar.
 * \param empTam : Tamaño del vector de EMPLEADOS .
 * \param sec : Vector de SECTORES a mostrar.
 * \param secTam : Tamaño del vector de SECTORES .
 * \param
 * \return
 *
 */

void mostrarEmpleadosPorProveedor( eEmpleados emp[], int empTam, eSectores sec[], int secTam )
{
    int flag = 0;
    int i, j;
    for( i = 0; i < secTam ; i++)
    {
        if(sec[i].isBusy == 1)
        {
            for(int j = 0; j < empTam ; j++)
            {
                if( sec[i].idSector == emp[j].idSector && emp[j].isBusy == 1)
                {
                    if(flag == 0)
                    {
                        printf("--------------------------------------------------------------------------------");
                        printf(" EMPLEADOS del SECTOR %s:\n", sec[i].descripcion);
                        printf("--------------------------------------------------------------------------------\n");
                        printf(" LEGAJO   NOMBRE \t SEXO \t SUELDO       FECHA DE INGRESO \n\n");
                        flag++;
                    }
                    printf(" %-8d %-15s%c\t %-16.2f%d/%d/%d\n", emp[j].legajo, emp[j].nombre , emp[j].sexo, emp[j].sueldo, emp[j].fechaIngreso.dia, emp[j].fechaIngreso.mes, emp[j].fechaIngreso.anio );

                }
                if(j == empTam - 1 && flag == 1)
                {
                    printf("\n--------------------------------------------------------------------------------\n");
                }
            }
            flag = 0;
        }
    }
    for( j = 0; j < empTam ; j++)
    {
        if( emp[j].isBusy == 1)
        {
            if( emp[j].idSector == 0 && flag == 0)
            {
                flag++;
                printf("--------------------------------------------------------------------------------");
                printf(" EMPLEADOS sin SECTOR asignado:\n");
                printf("--------------------------------------------------------------------------------\n");
                printf(" LEGAJO   NOMBRE \t SEXO \t SUELDO       FECHA DE INGRESO \n\n");
                printf(" %-8d %-15s %c\t %-16.2f%d/%d/%d\n", emp[j].legajo, emp[j].nombre , emp[j].sexo, emp[j].sueldo, emp[j].fechaIngreso.dia, emp[j].fechaIngreso.mes, emp[j].fechaIngreso.anio );
            }
            else if( emp[j].idSector == 0)
            {
                printf(" %-8d %-15s %c\t %-16.2f%d/%d/%d\n", emp[j].legajo, emp[j].nombre , emp[j].sexo, emp[j].sueldo, emp[j].fechaIngreso.dia, emp[j].fechaIngreso.mes, emp[j].fechaIngreso.anio );
            }
        }
    }
    if(flag == 1)
    {
        printf("\n--------------------------------------------------------------------------------\n");
    }
}


//XE1-5
/** \brief Muestra todos los EMPLEADOS de un vector de EMPLEADOS .
 *
 * \param emp : Vector de EMPLEADOS a mostrar.
 * \param empTam : Tamaño del vector de EMPLEADOS .
 * \param sec : Vector de SECTORES asociado al vector de EMPLEADOS .
 * \param secTam : Tamaño del vector de SECTORES .
 * \return
 *
 */

void mostrarTodosLosEmpleados( eEmpleados emp[], int empTam, eSectores sec[], int secTam )
{
    printf("                       >>> Lista de EMPLEADOS <<<\n");
    printf("--------------------------------------------------------------------------------");
    printf(" SECTOR \t LEGAJO   NOMBRE \t  SEXO \t SUELDO       FECHA DE INGRESO\n");
    printf("--------------------------------------------------------------------------------\n");
    for(int i=0; i< empTam ; i++)
    {
        if( emp[i].isBusy == 1)
        {
            if( emp[i].idSector == 0)
            {
                printf(" %-15s %-8d %-16s%c\t %-16.2f%d/%d/%d\n","Sin asignar", emp[i].legajo, emp[i].nombre , emp[i].sexo, emp[i].sueldo, emp[i].fechaIngreso.dia, emp[i].fechaIngreso.mes, emp[i].fechaIngreso.anio );
            }
            else
            {
                for(int j = 0; j < secTam ; j++)
                {

                    if( emp[i].idSector == sec[j].idSector && sec[j].isBusy == 1)
                    {
                        printf(" %-15s %-8d %-16s%c\t %-16.2f%d/%d/%d\n", sec[j].descripcion, emp[i].legajo, emp[i].nombre , emp[i].sexo, emp[i].sueldo, emp[i].fechaIngreso.dia, emp[i].fechaIngreso.mes, emp[i].fechaIngreso.anio );
                        break;
                    }

                }
            }




        }
    }
    printf("\n--------------------------------------------------------------------------------\n");
}


//XE1-6
/** \brief Muestra UN EMPLEADO .
 *
 * \param empVar : Variable de tipo eEmpleados a mostrar.
 * \param sec : Vector de SECTORES asociado al EMPLEADO .
 * \param secTam : tamaño del vector de SECTORES .
 * \return
 *
 */

void mostrarEmpleado( eEmpleados empVar, eSectores sec[], int secTam )
{
    int flag = 0;
    printf("--------------------------------------------------------------------------------");
    printf(" SECTOR \t LEGAJO   NOMBRE \t  SEXO \t SUELDO       FECHA DE INGRESO\n");
    printf("--------------------------------------------------------------------------------\n");
    for(int j = 0; j < secTam ; j++)
    {
        if( empVar.idSector == sec[j].idSector && sec[j].isBusy == 1)
        {
            printf(" %-15s %-8d %-16s%c\t %-16.2f%d/%d/%d\n", sec[j].descripcion, empVar.legajo, empVar.nombre , empVar.sexo, empVar.sueldo, empVar.fechaIngreso.dia, empVar.fechaIngreso.mes, empVar.fechaIngreso.anio );
            flag++;
            break;
        }
    }
    if(flag == 0)
    {
        printf(" %-15s%-8d%-16s%c\t%-16.2f%d/%d/%d\n","Sin asignar", empVar.legajo, empVar.nombre , empVar.sexo, empVar.sueldo, empVar.fechaIngreso.dia, empVar.fechaIngreso.mes, empVar.fechaIngreso.anio );
    }
    printf("\n--------------------------------------------------------------------------------\n");

}



// ABM dependencias:


//XE1-7
/** \brief Recorre un vector de EMPLEADOS y revisa si existe uno en especial.
 *
 * \param emp : Vector de EMPLEADOS a revisar.
 * \param empTam : Tamaño del vector de EMPLEADOS a revisar.
 * \param legajo : Se verificara si esta en el vector.
 * \return Devuelve -1 si el EMPLEADO no se encuentra en el vector o el numero de indice donde se encuentra el EMPLEADO .
 *
 */

int buscarEmpleado( eEmpleados emp[], int empTam, int legajo )
{
    int indiceDelEmpleado = -1;
    for(int i=0; i < empTam ; i++)
    {
        if( emp[i].isBusy == 1 && emp[i].legajo == legajo )
        {
            indiceDelEmpleado = i;
            break;
        }
    }
    return indiceDelEmpleado ;
}


//XE1-8
/** \brief Busca un indice libre en un array de EMPLEADOS .
 *
 * \param emp : Array de EMPLEADOS a revisar.
 * \param empTam : Tamaño del array de EMPLEADOS .
 * \return
 *
 */

int buscarIndiceLibreEmp( eEmpleados emp[], int empTam )
{
    int indiceLibre = -1;
    int i;
    for( i = 0; i < empTam ; i++)
    {
        if(emp[i].isBusy == 0)
        {
            indiceLibre = i;
            break;
        }
    }
    return indiceLibre ;
}


//XE1-9
/** \brief Pide datos de un EMPLEADO y valida los datos.
 *
 * \param emp : Vector de EMPLEADOS para validar que el dato unico e irrepetible no haya sido antes cargado.
 * \param empTam : Tamaño del vector de EMPLEADOS  .
 * \param sec : Vector de SECTORES donde verificar SECTORES posibles para el nuevo EMPLEADO .
 * \param secTam : Tamaño del vector de SECTORES .
 * \return Devuelve una variable de tipo de eEmpleados cargada de datos.
 *
 */

eEmpleados pedirEmpleado( eEmpleados emp[], int empTam, eSectores sec[], int secTam )
{
    eEmpleados nuevoEmpleado ;
    nuevoEmpleado.isBusy = 0;

    int dia, mes, anio ;
    int idDelSector, verificacion, legajo, indiceEmpleadoRepetido ;
    char nombre[50] ;

    legajo = getConditionedInt(1,1,"\nIngrese LEGAJO del EMPLEADO : ","\nEl numero de LEGAJO es invalido, reingrese: ");
    indiceEmpleadoRepetido = buscarEmpleado ( emp, empTam, legajo );

    if( indiceEmpleadoRepetido == -1)
    {
        printf("\n-  El LEGAJO fue dado de alta exitosamente.\n\n");
        system("pause");
        nuevoEmpleado.legajo = legajo ;
        mostrarTodosLosSectores( sec, secTam );
        idDelSector = getInt("\nIngrese ID DE SECTOR del EMPLEADO : ");
        verificacion = buscarSector( sec, secTam, idDelSector );
        if( verificacion != -1)
        {
            nuevoEmpleado.idSector = idDelSector ;
            printf("\n-  El SECTOR ha sido asociado correctamente.\n\n");
            system("pause");
            system("cls");

            getRangedStr(2,49,"Ingrese NOMBRE del EMPLEADO : ","\nValidacion fallida , reingrese NOMBRE : ", nombre );
            xstrCapsSpaceFixer( nombre );
            xstrCapsAdder( nombre );
            strcpy( nuevoEmpleado.nombre , nombre );

            nuevoEmpleado.sexo = getGenre("\nIngese SEXO del EMPLEADO (f o m): ","\nValidacion fallida , reingrese SEXO : ");

            getValidDate("\n\nEscriba la FECHA DE INGRESO separando DIA , MES y ANIO sin barras: \n","\nSe produjo un error al validar la FECHA DE INGRESO ...\nReingrese: ",2018,1900, &dia, &mes, &anio );
            nuevoEmpleado.fechaIngreso.dia = dia ;
            nuevoEmpleado.fechaIngreso.mes = mes ;
            nuevoEmpleado.fechaIngreso.anio = anio ;

            nuevoEmpleado.sueldo = getConditionedFloat(0,1,"\nIngrese SUELDO del EMPLEADO : $","\nValidacion fallida, reingrese SUELDO : ");

            printf("\n");

            nuevoEmpleado.isBusy = 1;
        }
        else
        {
            printf("\n* El SECTOR no se ha encontrado.");
        }

    }
    else
    {
        printf("\n* El LEGAJO se encuentra en uso por otro EMPLEADO del sistema.");
    }
    return nuevoEmpleado ;
}



//ALTA BAJA MODIFICACION:


//XE2-1
/** \brief Da de alta un nuevo EMPLEADO al sistema verificando que el LEGAJO no se repita y que se elija un SECTOR VALIDO.
 *
 * \param emp : vector donde se dara de alta el EMPLEADO .
 * \param empTam : cantidad de elementos del vector de EMPLEADOS .
 * \param sec : vector de SECTORES asociado a vector de EMPLEADOS .
 * \param secTam : cantidad de elementos del vector de SECTORES .
 * \return devuelve -1 si no hay espacio para dar de alta EMPLEADOS , 0 si se produjo un error al validar o
 * \return 1 si el EMPLEADO fue dado de alta correctamente.
 *
 */

int altaEmpleado( eEmpleados emp[], int empTam, eSectores sec[], int secTam )
{
    int reg ;
    int indiceLibre ;

    indiceLibre = buscarIndiceLibreEmp( emp, empTam );
    if( indiceLibre == -1)
    {
        reg = -1 ;
    }
    else
    {
        emp[indiceLibre] = pedirEmpleado( emp, empTam, sec, secTam );
        if( emp[indiceLibre].isBusy == 0)
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
/** \brief Elimina un EMPLEADO del sistema.
 *
 * \param emp : Recibe un vector de EMPLEADOS para que el usuario busque en el posibles EMPLEADOS a borrar.
 * \param empTam : Tamaño del vector de EMPLEADOS .
 * \param sec : Vector de SECTORES asociado al vector de EMPLEADOS .
 * \param secTam : Tamaño del vector de SECTORES .
 * \return devuelve 1 si el EMPLEADO se dio de baja, devuelve 0 si el EMPLEADO se encontro pero no se dio de baja o devuelve -1 si el EMPLEADO no se encontro.
 *
 */

int bajaEmpleado( eEmpleados emp[], int empTam, eSectores sec[], int secTam )
{
    int reg = 0 ;
    int legajo ;
    int verificacion ; // Se almacena el indice recibido por buscarEmpleado() para determinar si el empleado existe.

    system("cls");
    mostrarTodosLosEmpleados( emp, empTam, sec, secTam );
    legajo = getInt("Ingrese LEGAJO del EMPLEADO a eliminar: ");

    verificacion = buscarEmpleado( emp, empTam, legajo );
    if( verificacion == -1)
    {
        reg = -1 ;
    }
    else
    {
        system("cls");
        printf("                   <<< ELIMINARA EL SIGUIENTE EMPLEADO >>>\n");
        mostrarEmpleado( emp[verificacion], sec, secTam );

        if(validateDualExit("\nConfirmar? s/n : ","\nNo se reconoce su respuesta.\nReingrese: ",'s','n') == 1)
        {
            emp[verificacion].isBusy = 0;
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
/** \brief Permite al usuario modificar datos de un EMPLEADO de un vector de EMPLEADOS .
 *
 * \param emp : Vector de EMPLEADOS donde el usuario buscara.
 * \param empTam : Tamaño del vector de EMPLEADOS .
 * \param sec : Vector de SECTORES asociado al vector de EMPLEADOS .
 * \param secTam : Tamaño del vector de SECTORES .
 * \return Devuelve -1 si el EMPLEADO a modificar no existe, 0 si se encontro un EMPLEADO y no se modifico y un entero
 * \return positivo si se realizo alguna modificacion a un EMPLEADO .
 *
 */

int modificarEmpleado ( eEmpleados emp[], int empTam, eSectores sec[], int secTam )
{
    char nombre[50] ;
    int dia, mes, anio ;
    int legajo, seleccion, legajoEmpleadoRepetido , idDelSector, verificacion, indiceEmpleadoLegajo ;
    int reg = -1, salir = 0;

    system("cls");
    mostrarTodosLosEmpleados( emp, empTam, sec, secTam );

    legajo = getInt("Ingrese LEGAJO del EMPLEADO a modificar: ");
    indiceEmpleadoLegajo = buscarEmpleado( emp, empTam, legajo );

    if( indiceEmpleadoLegajo > -1)
    {
        reg = 0 ;
        system("cls");
        printf("                   <<< MODIFICARA EL SIGUIENTE EMPLEADO >>>\n");
        mostrarEmpleado( emp[indiceEmpleadoLegajo], sec, secTam );

        if(validateDualExit("\nConfirmar? s/n : ","\nNo se reconoce su respuesta.\nReingrese: ",'s','n') == 1)
        {
            do
            {
                xlkNoLineHeadGenerator("Modificar EMPLEADO :");
                mostrarEmpleado( emp[indiceEmpleadoLegajo], sec, secTam );
                xlkNoLineIndexBodyGenerator(7,"1- CAMBIAR LEGAJO .","2- CAMBIAR NOMBRE .","3- CAMBIAR FECHA DE INGRESO .","4- CAMBIAR SUELDO .","5- CAMBIAR SEXO .","6- CAMBIAR SECTOR .","0- VOLVER .");
                seleccion = getInt("- Seleccionar opcion: ");
                switch(seleccion)
                {
                case 1:
                    legajo = getConditionedInt(1,1,"\nIngrese nuevo LEGAJO : ","Se proujo un error al validar, reingrese LEGAJO : ");
                    legajoEmpleadoRepetido = buscarEmpleado( emp, empTam, legajo );
                    if( legajoEmpleadoRepetido > -1 )
                    {
                        printf("\n* El LEGAJO que intenta cargar se encuentra en uso.\n\n");

                    }
                    else if( validateDualExit("\nAplicar cambio? s/n : ","\nNo se reconoce su respuesta.\nReingrese: ",'s','n') == 1 && legajoEmpleadoRepetido == -1)
                    {
                        emp[indiceEmpleadoLegajo].legajo = legajo;
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
                    getRangedStr(2,49,"\nCambiar NOMBRE : "," Se produjo un error al validar, reingrese NOMBRE : ", nombre );
                    xstrCapsSpaceFixer( nombre );
                    xstrCapsAdder( nombre );
                    strcpy( emp[indiceEmpleadoLegajo].nombre , nombre );
                    printf("\n* Modificacion realizada.\n\n");
                    reg ++ ;
                    system("pause");
                    break;
                case 3:
                    getValidDate("\nCambiar FECHA DE INGRESO : ","Se produjo un error al validar la FECHA DE INGRESO ...\nReingrese: ",2018,1900, &dia, &mes, &anio );
                    emp[indiceEmpleadoLegajo].fechaIngreso.dia = dia ;
                    emp[indiceEmpleadoLegajo].fechaIngreso.mes = mes ;
                    emp[indiceEmpleadoLegajo].fechaIngreso.anio = anio ;
                    printf("\n* Modificacion realizada.\n\n");
                    reg ++ ;
                    system("pause");
                    break;
                case 4:
                    emp[indiceEmpleadoLegajo].sueldo = getConditionedFloat(0,1,"\nCambiar SUELDO : $"," Se produjo un error al validaR, reingrese SUELDO : ");
                    printf("\n* Modificacion realizada.\n\n");
                    reg ++ ;
                    system("pause");
                    break;
                case 5:
                    emp[indiceEmpleadoLegajo].sexo = getGenre("\nCambiar SEXO : ","Se produjo un error al validar, reingrese SEXO : ");
                    printf("\n* Modificacion realizada.\n\n");
                    reg ++ ;
                    system("pause");
                    break;
                case 6:
                    mostrarTodosLosSectores( sec, secTam );
                    idDelSector = getInt("\nCambiar ID DE SECTOR : ");
                    verificacion = buscarSector( sec, secTam, idDelSector );
                    if( verificacion != -1)
                    {
                        emp[indiceEmpleadoLegajo].idSector = idDelSector ;
                        printf("\n* Modificacion realizada.\n\n");
                        reg ++ ;
                    }
                    else
                    {
                        printf("\n* SECTOR inexistente.\n\n");
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
/** \brief Ordena EMPLEADOS por 3 criterios: 1- DESCRIPCION , 2- SUELDO ,  3- LEGAJO .
 *
 * \param emp : Vector de EMPLEADOS a ordenar.
 * \param empTam : Tamaño del vector de EMPLEADOS .
 * \return
 *
 */

void ordenarEmpleados( eEmpleados emp[], int empTam )
{
    for(int i = 0; i < empTam - 1; i++)
    {
        for(int j = i+1; j < empTam ; j++)
        {
            if(stricmp( emp[j].nombre , emp[i].nombre ) < 0)
            {
                eEmpleados aux ;
                aux = emp[i] ;
                emp[i] = emp[j] ;
                emp[j] = aux ;
            }
            else if( stricmp( emp[j].nombre, emp[i].nombre ) == 0)
            {
                if( emp[j].sueldo > emp[i].sueldo )
                {
                    eEmpleados aux ;
                    aux = emp[i] ;
                    emp[i] = emp[j] ;
                    emp[j] = aux ;
                }
                else if( emp[j].sueldo == emp[i].sueldo )
                {
                    if( emp[j].legajo > emp[i].legajo )
                    {
                        eEmpleados aux ;
                        aux = emp[i] ;
                        emp[i] = emp[j] ;
                        emp[j] = aux ;
                    }
                }

            }
        }
    }
}



//Funciones exclusivas de eSectores :

//Basico:


//XE2-5
/** \brief Define el estado de un vector de SECTORES en 0.
 *
 * \param sec : Vector de SECTORES a inicializar.
 * \param secTam : Tamaño del vector de SECTORES .
 * \return
 *
 */

void inicializarSectores( eSectores sec[], int secTam )
{
    for(int i = 0; i < secTam ; i++)
    {
        sec[i].isBusy = 0;
    }
}



//Funciones de muestra:


//XE2-6
/** \brief Muestra todos los SECTORES de un vector de SECTORES .
 *
 * \param sec: Vector de SECTORES a mostrar.
 * \param secTam: Tamaño del vector de SECTORES .
 * \return
 *
 */

void mostrarTodosLosSectores( eSectores sec[], int secTam )
{
    printf("                       >>> Lista de SECTORES <<<\n");
    printf("--------------------------------------------------------------------------------");
    printf(" ID DE SECTOR :\t\t DESCRIPCION :\n");
    printf("--------------------------------------------------------------------------------\n");
    for(int i=0; i< secTam ; i++)
    {
        if( sec[i].isBusy == 1)
        {
            printf(" %d\t\t\t\t %-30s\n", sec[i].idSector , sec[i].descripcion );
        }
    }
    printf("\n--------------------------------------------------------------------------------\n");
}


//XE2-7
/** \brief Muestra un SECTOR .
 *
 * \param secVar: Variable de tipo eSectores a mostrar.
 * \return
 *
 */

void mostrarSector( eSectores secVar )
{
    printf("--------------------------------------------------------------------------------");
    printf(" ID DE SECTOR :\t\t DESCRIPCION :\n");
    printf("--------------------------------------------------------------------------------\n");
    printf(" %d\t\t\t\t %-30s\n", secVar.idSector, secVar.descripcion );
    printf("\n--------------------------------------------------------------------------------\n");
}



// ABM dependencias:


//XE2-8
/** \brief Busca un indice libre en un vector de SECTORES .
 *
 * \param sec : Vector de SECTORES a revisar.
 * \param tam : Tamaño del vector de SECTORES .
 * \return devuelve -1 si no hay espacio en el vector o un indice libre si lo halla.
 *
 */

int buscarIndiceLibreSec( eSectores sec[], int secTam )
{
    int indiceLibre = -1;
    for(int i=0; i < secTam ; i++)
    {
        if(sec[i].isBusy == 0)
        {
            indiceLibre = i;
            break;
        }
    }
    return indiceLibre ;
}


//XE2-9
/** \brief Revisa un vector de SECTORES para determinar si un SECTOR se encuentra en el vector.
 *
 * \param sec : Vector de SECTORES a revisar.
 * \param tam : Tamaño del vector de SECTORES .
 * \param idDelSector : ID DE SECTOR a buscar en el vector.
 * \return devuelve -1 si no encontro el SECTOR o el indice del vector donde se halla.
 *
 */

int buscarSector( eSectores sec[], int secTam, int idDelSector )
{
    int indiceCoincidencia = -1;
    for(int i = 0; i < secTam ; i++)
    {
        if( sec[i].idSector == idDelSector && sec[i].isBusy == 1)
        {
            indiceCoincidencia = i;
            break;
        }
    }
    return indiceCoincidencia ;
}



//ALTA BAJA MODIFICACION:


//XE3-1
/** \brief Da de alta un nuevo SECTOR en el sistema.
 *
 * \param sec : Vector de SECTORES donde dar de alta un nuevo SECTOR .
 * \param secTam : Tamaño del vector de SECTORES .
 * \return Devuelve -1 si no hay espacio para crear un SECTOR , 0 si se produjo un error al validar algun dato o
 * \return 1 si el SECTOR se creo con exito.
 *
 */

int altaSector( eSectores sec[], int secTam )
{
    char descripcion[50] ;
    int indiceLibre ;
    int verificacion ;
    int idDelSector ;
    int reg = -1;
    indiceLibre = buscarIndiceLibreSec( sec, secTam );
    if( indiceLibre != -1)
    {
        idDelSector = getConditionedInt(1,1,"\nIngrese ID DE SECTOR (Debe ser mayor a 0): ","\nNumero incorrecto, reingrese: ");
        verificacion = buscarSector( sec, secTam, idDelSector );
        if(verificacion == -1)
        {
            reg = 1 ;
            sec[indiceLibre].idSector = idDelSector ;
            getRangedStr(2,49,"\nIngrese DESCRIPCION del SECTOR : ","\nSe produjo un error al validar, reingrese DESCRIPCION : ", descripcion );
            strcpy( sec[indiceLibre].descripcion, descripcion );
            sec[indiceLibre].isBusy = 1;
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
/** \brief Da de baja un SECTOR del sistema y asigna a los EMPLEADOS el SECTOR un equivalente a "Sin asignar".
 *
 * \param sec : Vector de SECTORES donde buscar un SECTOR para dar de baja.
 * \param secTam : Tamaño del vector SECTORES .
 * \param emp : vector de EMPLEADOS a revisar si corresponde con un SECTOR dado de baja.
 * \param empTam : Tamaño del vector de EMPLEADOS .
 * \return Devuelve -1 si no se encontro un SECTOR , 0 si se encontro uno y el usuario anulo la baja o 1 si se concreto
 * \return la baja de un SECTOR .
 *
 */

int bajaSector( eSectores sec[], int secTam, eEmpleados emp[], int empTam )
{
    int idDelSector, reg ;
    int verificacion ;

    system("cls");
    mostrarTodosLosSectores( sec, secTam );

    idDelSector = getInt("Ingrese ID DE SECTOR a eliminar: ");
    verificacion = buscarSector( sec, secTam, idDelSector );
    if( verificacion == -1)
    {
        reg = -1 ;
    }
    else
    {
        system("cls");
        printf("                   <<< ELIMINARA ESTE SECTOR >>>\n");
        mostrarSector( sec[verificacion] );
        if(validateDualExit("\nConfirmar? s/n : ","\nNo se reconoce su respuesta.\nReingrese: ",'s','n') == 1)
        {
            sec[verificacion].isBusy = 0;
            for(int i = 0; i < secTam ; i++)
            {
                if( sec[verificacion].idSector == emp[i].idSector )
                {
                    emp[i].idSector = 0;
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
/** \brief Permite al usuario modificar datos de un SECTOR de un vector de SECTORES .
 *
 * \param sec : Vector de SECTORES donde el usuario buscara un SECTOR a modificar.
 * \param secTam : Tamaño del vector de SECTORES .
 * \param emp : vector de EMPLEADOS asociado.
 * \param empTam : Tamaño del vector de EMPLEADOS  asociado .
 * \return Devuelve -1 si el SECTOR a modificar no existe, 0 si se encontro un SECTOR y no se modifico y un entero
 * \return positivo si se realizo alguna modificacion.
 *
 */

int modificarSector( eSectores sec[] , int secTam , eEmpleados emp[] , int empTam )
{
    int idDelSector ;
    int salir = 0, seleccion, verificacion, reg = 0, verif , i ;
    char descripcion[50] ;

    system("cls");
    mostrarTodosLosSectores( sec, secTam );

    idDelSector = getInt("\nIngrese ID DE SECTOR a modificar: ");
    verificacion = buscarSector( sec, secTam, idDelSector );

    if( verificacion > -1)
    {
        system("cls");
        printf("                   <<< MODIFICARA AL SIGUIENTE SECTOR >>>\n");
        mostrarSector( sec[verificacion] );

        if(validateDualExit("\nConfirmar? s/n : ","\nNo se reconoce su respuesta.\nReingrese: ",'s','n') == 1)
        {
            do
            {
                xlkNoLineHeadGenerator("Modificar SECTOR :");
                mostrarSector( sec[verificacion] );
                xlkNoLineIndexBodyGenerator(3,"1- CAMBIAR ID DE SECTOR .","2- CAMBIAR DESCRIPCION .","0- VOLVER .");
                seleccion = getInt("- Seleccionar opcion: ");

                switch( seleccion )
                {
                case 1:
                    idDelSector = getConditionedInt(1,1,"\nIngrese nuevo ID DE SECTOR (Debe ser mayor a 0): ","\nSe produjo un error al validar.\nRecuerde que un ID DE SECTOR debe ser mayor a 0.\nReingrese: ");
                    verif = buscarSector( sec, secTam, idDelSector );
                    if( verif == -1)
                    {
                        for(i = 0 ; i < empTam ; i++)
                        {
                            if( emp[i].idSector == sec[verificacion].idSector )
                            {
                                emp[i].idSector = idDelSector ;
                            }
                        }
                        sec[verificacion].idSector = idDelSector ;
                        printf("\n* Modificacion realizada.\n\n");
                        reg++ ;
                    }
                    else
                    {
                        printf("El ID DE SECTOR que intenta cargar se encuentra en uso:\n");
                    }
                    system("pause");
                    break;
                case 2:
                    getRangedStr(2,50,"\nIngrese nueva DESCRIPCION : ","\nSe produjo un error al validar, reingrese DESCRIPCION : ", descripcion );
                    xstrCapsSpaceFixer( descripcion );
                    strcpy( sec[verificacion].descripcion, descripcion );
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
/** \brief Muestra el menu de acciones de EMPLEADOS .
 *
 * \param emp : Vector de EMPLEADOS .
 * \param empTam : Tamaño del vector de EMPLEADOS .
 * \param sec : Vector de SECTORES asociado.
 * \param secTam : Tamaño del vector de SECTORES asociado.
 * \return
 *
 */

void mostrarMenuEmpleados( eEmpleados emp[], int empTam, eSectores sec[], int secTam )     //XE3-4
{
    int functionValueReceiver ;
    int seleccion ;
    int exit = 0;
    do
    {
        xlkIndexGenerator(" EMPLEADOS ",7,"1-ALTA.","2-BAJA.","3-MODIFICACION.","4-ORDENAMIENTO.","5-MOSTRAR EMPLEADOS .","6-MOSTRAR EMPLEADOS POR SECTOR .","0-VOLVER.");
        seleccion = getInt("-  Seleccionar opcion: ");
        switch(seleccion)
        {
        case 1:
            printf("\n* Agregar nuevo EMPLEADO :\n");
            functionValueReceiver = altaEmpleado( emp , empTam , sec , secTam );
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
            functionValueReceiver = bajaEmpleado( emp, empTam, sec, secTam );
            if(functionValueReceiver == -1)
            {
                printf("* No se ha encontrado el EMPLEADO especificado.\n\n");
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
            functionValueReceiver = modificarEmpleado( emp, empTam, sec, secTam );
            if(functionValueReceiver == -1)
            {
                printf("* No se ha encontrado el EMPLEADO especificado.\n\n");
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
            ordenarEmpleados( emp, empTam );
            printf("\n* Se han ordenado todos los EMPLEADOS del sistema.\n\n");
            system("pause");
            break;
        case 5:
            system("cls");
            mostrarTodosLosEmpleados( emp, empTam, sec, secTam );
            system("pause");
            break;
        case 6:
            system("cls");
            mostrarEmpleadosPorProveedor( emp, empTam, sec, secTam );
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
/** \brief Muestra el menu de acciones de los SECTORES .
 *
 * \param emp : Vector de EMPLEADOS asociado.
 * \param empTam : Tamaño del vector de EMPLEADOS asociado.
 * \param sec : Vector de SECTORES .
 * \param secTam : Tamaño del vector de SECTORES .
 * \return
 *
 */

void mostrarMenuSectores( eEmpleados emp[], int empTam, eSectores sec[], int secTam )
{
    int functionValueReceiver ;
    int seleccion;
    int exit = 0;
    do
    {
        xlkIndexGenerator(" SECTORES ",5,"1-ALTA.","2-BAJA.","3-MODIFICACION.","4-MOSTRAR SECTORES .","0-VOLVER.");
        seleccion = getInt("-  Seleccionar opcion: ");
        switch(seleccion)
        {
        case 1:
            printf("\n* Agregar un nuevo SECTOR :\n");
            functionValueReceiver = altaSector( sec, secTam );
            if(functionValueReceiver == -1)
            {
                printf("* No hay espacio suficiente para realizar mas altas de este tipo.\n\n");
            }
            else if(functionValueReceiver == 0)
            {
                printf("* El ID DE SECTOR que intenta asignar se encuentra en uso.\n\n");
            }
            else
            {
                printf("* Alta realizada.\n\n");
            }
            system("pause");
            break;
        case 2:
            functionValueReceiver = bajaSector( sec, secTam, emp, empTam );
            if(functionValueReceiver == -1)
            {
                printf("* No se ha encontrado el SECTOR especificado.\n\n");
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
            functionValueReceiver = modificarSector( sec , secTam , emp , empTam );
            if(functionValueReceiver == -1)
            {
                printf("* No se ha encontrado el SECTOR especificado.\n\n");
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
            mostrarTodosLosSectores( sec, secTam );
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
