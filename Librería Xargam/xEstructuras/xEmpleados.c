#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xEmpleados.h"
#include "xget.h"
#include "xvalidate.h"
#include "xstring.h"
#include "xlook.h"


// Funciones de HARCODEO de estructuras:

//eEmpleado:


//XE1-1
/** \brief Carga datos a modo hardcode en los 3 primeros indices de un vector de empleados.
 *
 * \param emp: Vector de empleados a hardcodear.
 * \return
 *
 */

void hardCodearEmp(eEmpleado emp[])
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



//eSector:


//XE1-2
/** \brief Carga datos a modo hardcode en los 5 primeros indices de un vector de sectores.
 *
 * \param sec: Vector de sectores a hardcodear
 * \return
 *
 */

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

void inicializarEmpleados(eEmpleado vec[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        vec[i].isBusy = 0;
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

void mostrarTodosLosEmpleados(eEmpleado emp[], int tamEmp,eSector sec[],int tamSec)
{
    system("cls");
    printf("---------------------------Lista de Empleados-----------------------------------\n");
    printf("SECTOR:\t\tLEGAJO:\tNOMBRE:\t\tSEXO:\tSUELDO:\t\tFECHA INGRESO:\n\n");
    for(int i=0; i< tamEmp; i++)
    {
        if(emp[i].isBusy == 1)
        {
            if(emp[i].idSector == 0)
            {
                printf(" %-15s%-8d%-16s%c\t%-16.2f%d/%d/%d\n","Sin asignar",emp[i].legajo,emp[i].nombre,emp[i].sexo,emp[i].sueldo,emp[i].fechaIngreso.dia,emp[i].fechaIngreso.mes,emp[i].fechaIngreso.anio);
            }
            else
            {
                for(int j = 0; j < tamSec; j++)
                {

                    if(emp[i].idSector == sec[j].idSector && sec[j].isBusy == 1)
                    {
                        printf(" %-15s%-8d%-16s%c\t%-16.2f%d/%d/%d\n",sec[j].descripcion,emp[i].legajo,emp[i].nombre,emp[i].sexo,emp[i].sueldo,emp[i].fechaIngreso.dia,emp[i].fechaIngreso.mes,emp[i].fechaIngreso.anio);
                        break;
                    }

                }
            }




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

void mostrarEmpleado(eEmpleado emp,eSector sec[],int tamSec)
{
    int flag = 0;
    printf("SECTOR:\t\tLEGAJO:\tNOMBRE:\t\tSEXO:\tSUELDO:\t\tFECHA INGRESO:\n\n");
    for(int j = 0; j < tamSec; j++)
    {
        if(emp.idSector == sec[j].idSector && sec[j].isBusy == 1)
        {
            printf(" %-15s%-8d%-16s%c\t%-16.2f%d/%d/%d\n",sec[j].descripcion,emp.legajo,emp.nombre,emp.sexo,emp.sueldo,emp.fechaIngreso.dia,emp.fechaIngreso.mes,emp.fechaIngreso.anio);
            flag++;
            break;
        }
    }
    if(flag == 0)
    {
        printf(" %-15s%-8d%-16s%c\t%-16.2f%d/%d/%d\n","Sin asignar",emp.legajo,emp.nombre,emp.sexo,emp.sueldo,emp.fechaIngreso.dia,emp.fechaIngreso.mes,emp.fechaIngreso.anio);
    }

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

int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{
    int index = -1;
    for(int i=0; i < tam; i++)
    {
        if(vec[i].isBusy == 1 && vec[i].legajo == legajo)
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

int buscarIndiceLibreEmp(eEmpleado emp[], int tam)
{
    int index = -1;
    for(int i=0; i < tam; i++)
    {
        if(emp[i].isBusy == 0)
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

eEmpleado pedirEmpleado(eEmpleado emp[],int empTam, eSector sec[],int tamSec)
{
    eEmpleado nuevoEmpleado;
    nuevoEmpleado.isBusy = 0;
    int dia, mes, anio;
    int id, verificacion;
    char nombre[50];

    int legajo = getConditionedInt(1,1,"\nIngrese legajo del empleado: ","El numero de legajo es invalido, reingrese: ");
    int IndiceEmpleadoRepetido = buscarEmpleado(emp, empTam, legajo);
    if(IndiceEmpleadoRepetido == -1)
    {
        printf("\n-  El legajo fue dado de alta exitosamente.\n\n");
        system("pause");
        nuevoEmpleado.legajo = legajo;
        mostrarTodosLosSectores(sec,tamSec);
        id = getInt("\nIngrese ID del sector del empleado: ");
        verificacion = buscarIdSector(sec,tamSec,id);
        if(verificacion != -1)
        {
            nuevoEmpleado.idSector = id;
            printf("\n-  El sector ha sido asociado correctamente.\n\n");
            system("pause");
            system("cls");
            getRangedStr(2,49,"Ingrese nombre del empleado: ","Nombre invalido, reingrese: ",nombre);
            xstrCapsSpaceFixer(nombre);
            xstrCapsAdder(nombre);
            strcpy(nuevoEmpleado.nombre,nombre);
            nuevoEmpleado.sexo = getGenre("\nIngese sexo del empleado (f o m): ","Sexo invalido, reingrese: ");
            getValidDate("\n\nEscriba la fecha de ingreso separando dia, mes y anio sin barras: \n","Se produjo un error al validar la fecha...\nReingrese fecha: ",2018,1900,&dia,&mes,&anio);
            nuevoEmpleado.fechaIngreso.dia = dia;
            nuevoEmpleado.fechaIngreso.mes = mes;
            nuevoEmpleado.fechaIngreso.anio = anio;
            nuevoEmpleado.sueldo = getConditionedFloat(0,1,"\nIngrese sueldo del empleado: $","Sueldo invalido, reingrese: ");
            printf("\n");
            nuevoEmpleado.isBusy = 1;
        }
        else
        {
            printf("\nEl sector no se ha encontrado.");
        }

    }
    else
    {
        printf("\nEl legajo que intenta asignar se encuentra en uso por otro empleado.");
    }
    return nuevoEmpleado;
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

int altaEmpleado(eEmpleado emp[], int tam,eSector sec[],int tamSec)
{
    int reg;
    int indiceLibre = buscarIndiceLibreEmp(emp,tam);

    if(indiceLibre == -1)
    {
        reg = -1;
    }
    else
    {
        emp[indiceLibre] = pedirEmpleado(emp,tam,sec,tamSec);
        if(emp[indiceLibre].isBusy == 0)
        {
            reg = 0;
        }
        else
        {
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

int bajaEmpleado(eEmpleado emp[],int tam,eSector sec[], int tamSec)
{
    int reg = 0;
    mostrarTodosLosEmpleados(emp,tam,sec,tamSec);
    int legajo = getInt("Ingrese legajo del empleado a eliminar: ");
    int verificacion; // Se almacena el indice recibido por buscarEmpleado() para determinar si el empleado existe.
    int confirm; // Segun el valor de esta variable el usuario confirma o no la eliminacion del empleado.
    verificacion = buscarEmpleado(emp,tam,legajo);
    if(verificacion == -1)
    {
        reg = -1;
    }
    else
    {
        system("cls");
        printf("Dara de baja al siguiente empleado: \n\n");
        mostrarEmpleado(emp[verificacion],sec,tamSec);
        confirm = validateExit("\nConfirmar baja? s/n:\n",'s');
        if(confirm == 1)
        {
            emp[verificacion].isBusy = 0;
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

int modificarEmpleado(eEmpleado emp[],int tam,eSector sec[],int secTam)
{

    system("cls");
    mostrarTodosLosEmpleados(emp,tam,sec,secTam);
    int legajo = getInt("\nIngrese el legajo del empleado a modificar: ");

    int salir = 0;

    int dia, mes, anio, seleccion, legajoRepetido, id, verificacion, reg = -1;
    char nombre[50];

    int indiceEmpleadoLegajo = buscarEmpleado(emp,tam,legajo);

    if(indiceEmpleadoLegajo > -1)
    {
        system("cls");
        printf("Va a modificar al siguiente empleado:\n\n");
        mostrarEmpleado(emp[indiceEmpleadoLegajo],sec,secTam);
        reg = 0;
        if(validateExit("\nConfirmar: s/n: ",'s') == 1)
        {
            do
            {
                xlkHeadGenerator("Modificar empleado:");
                mostrarEmpleado(emp[indiceEmpleadoLegajo],sec,secTam);
                xlkIndexBodyGenerator(7,"1-Cambiar legajo.","2-Cambiar nombre.","3-Cambiar fecha de ingreso.","4-Cambiar sueldo.","5-Cambiar sexo","6-Cambiar sector.","0-Volver.");
                seleccion = getInt("Seleccionar opcion: ");
                switch(seleccion)
                {
                case 1:
                    legajo = getConditionedInt(1,1,"\nIngrese nuevo legajo: ","Legajo invalido: ");
                    legajoRepetido = buscarEmpleado(emp,tam,legajo);
                    if(legajoRepetido == -1)
                    {
                        emp[indiceEmpleadoLegajo].legajo = legajo;
                        printf("\nLegajo actualizado.\n\n");
                        reg++;
                    }
                    else
                    {
                        printf("\nEl legajo que intenta cargar se encuentra en uso.\n\n");
                    }
                    system("pause");
                    break;
                case 2:
                    getRangedStr(2,49,"\nIngrese nuevo nombre: ","Nombre invalido, reingrese: ",nombre);
                    xstrCapsSpaceFixer(nombre);
                    xstrCapsAdder(nombre);
                    strcpy(emp[indiceEmpleadoLegajo].nombre,nombre);
                    printf("\nNombre actualizado.\n\n");
                    reg++;
                    system("pause");
                    break;
                case 3:
                    getValidDate("\nIngrese fecha de ingreso: ","Se produjo un error al validar la fecha...\nReingrese: ",2018,1900,&dia,&mes,&anio);
                    emp[indiceEmpleadoLegajo].fechaIngreso.dia = dia;
                    emp[indiceEmpleadoLegajo].fechaIngreso.mes = mes;
                    emp[indiceEmpleadoLegajo].fechaIngreso.anio = anio;
                    printf("\nFecha actualizada.\n\n");
                    reg++;
                    system("pause");
                    break;
                case 4:
                    emp[indiceEmpleadoLegajo].sueldo = getConditionedFloat(0,1,"\nIngrese nuevo sueldo: $","Sueldo invalido, reingrese: ");
                    printf("\nSueldo actualizado.\n\n");
                    reg++;
                    system("pause");
                    break;
                case 5:
                    emp[indiceEmpleadoLegajo].sexo = getGenre("\nIngrese nuevo sexo: ","Sexo invalido, reingrese: ");
                    printf("\n\nSexo actualizado.\n\n");
                    reg++;
                    system("pause");
                    break;
                case 6:
                    mostrarTodosLosSectores(sec,secTam);
                    id = getInt("\nIngrese nuevo ID de sector: ");
                    verificacion = buscarIdSector(sec,secTam,id);
                    if(verificacion != -1)
                    {
                        emp[indiceEmpleadoLegajo].idSector = id;
                        printf("\nSector del empleado actualizado.\n\n");
                        reg++;
                    }
                    else
                    {
                        printf("\nSector inexistente.\n\n");
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



//Adicionales:


//XE2-4
/** \brief Ordena empleados por 3 criterios: 1-Nombre, 2-Sueldo, 3-Leagajo
 *
 * \param emp: Vector de empleados a ordenar.
 * \param tam: Tamaño del vector de empleados.
 * \return
 *
 */

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



//Funciones exclusivas de eSector:

//Basico:


//XE2-5
/** \brief Define el estado de un vector de sectores en 0.
 *
 * \param sec: Vector de sectores a inicializar.
 * \param tam: Tamaño del vector.
 * \return
 *
 */

void inicializarSectores(eSector sec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        sec[i].isBusy = 0;
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

void mostrarTodosLosSectores(eSector sec[], int tamSec)
{
    system("cls");
    printf("-------------Lista de sectores--------------------------------------------------\n");
    printf(" ID DEL SECTOR:\t\tDESCRIPCION:\n\n");
    for(int i=0; i< tamSec; i++)
    {
        if(sec[i].isBusy == 1)
        {
            printf(" %d\t\t\t%s\n",sec[i].idSector,sec[i].descripcion);
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

void mostrarSector(eSector sec)
{
    printf(" ID de sector:\t\tDescripcion:\n\n");
    printf(" %d\t\t\t%s\n",sec.idSector,sec.descripcion);
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

int buscarIndiceLibreSec(eSector sec[], int tam)
{
    int index = -1;
    for(int i=0; i < tam; i++)
    {
        if(sec[i].isBusy == 0)
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

int buscarIdSector(eSector sec[],int tam,int id)
{
    int index = -1;
    for(int i = 0; i < tam; i++)
    {
        if(sec[i].idSector == id && sec[i].isBusy == 1)
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

int altaSector(eSector sec[],int tam)
{
    char descripcion[51];
    int indiceLibre = buscarIndiceLibreSec(sec,tam);
    int indiceIdRepetida;
    int idSector;
    int reg;
    if(indiceLibre != -1)
    {
        idSector = getConditionedInt(1,1,"\nIngrese numero de sector (Debe ser mayor a 0): ","Numero incorrecto, reingrese: ");
        indiceIdRepetida = buscarIdSector(sec,tam,idSector);
        if(indiceIdRepetida == -1)
        {
            reg = 1;
            sec[indiceLibre].idSector = idSector;
            getRangedStr(2,51,"\n\nIngrese nombre del sector: ","El nombre que ingreso es invalido, pruebe otro: ",descripcion);
            strcpy(sec[indiceLibre].descripcion, descripcion);
            sec[indiceLibre].isBusy = 1;
        }
        else
        {
            reg = 0;
        }
    }
    else
    {
        reg = -1;
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

int bajaSector(eSector sec[],int tam, eEmpleado emp[],int empTam)
{
    int id,reg;
    mostrarTodosLosSectores(sec,tam);
    id = getInt("Ingrese ID del sector a eliminar: ");
    int verificacion = buscarIdSector(sec,tam,id);
    system("cls");
    if(verificacion == -1)
    {
        reg = -1;
    }
    else
    {
        printf("Dara de baja al siguiente sector: \n\n");
        mostrarSector(sec[verificacion]);
        if(validateExit("\nConfirmar baja? s/n:\n",'s') == 1)
        {
            sec[verificacion].isBusy = 0;
            for(int i = 0; i < tam; i++)
            {
                if(sec[verificacion].idSector == emp[i].idSector)
                {
                    emp[i].idSector = 0;
                }
            }
            reg = 1;
        }
        else
        {
            reg= 0;
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

int modificarSector(eSector sec[],int tam)
{
    system("cls");
    printf("Lista de sectores: ");
    mostrarTodosLosSectores(sec,tam);

    int id = getInt("\nIngrese el id del sector a modificar: ");
    int salir = 0, seleccion, verificacion,reg = 0;

    char descripcion[51];
    verificacion = buscarIdSector(sec,tam,id);
    if(verificacion > -1)
    {
        system("cls");
        printf("Va a modificar el siguiente sector:\n\n");
        mostrarSector(sec[verificacion]);
        if(validateExit("\nConfirmar: s/n:\n",'s') == 1)
        {
            do
            {
                xlkHeadGenerator("Modificar sector:");
                mostrarSector(sec[verificacion]);
                xlkIndexBodyGenerator(3,"1-Cambiar id.","2-Cambiar nombre.","0-Volver.");
                seleccion = getInt("Seleccionar opcion: ");
                int verif;
                switch(seleccion)
                {
                case 1:
                    id = getConditionedInt(1,1,"Ingrese nueva ID positiva: ","Numero de ID invalido, pruebe otro: ");
                    verif = buscarIdSector(sec,tam,id);
                    if(verif == -1)
                    {
                        sec[verificacion].idSector = id;
                        printf("\nID actualizada.\n");
                        reg++;
                    }
                    else
                    {
                        printf("El ID que intenta cargar se encuentra en uso:\n");
                    }
                    system("pause");
                    break;
                case 2:
                    getRangedStr(2,50,"Ingrese nueva descripcion: ","Descripcion invalida, reingrese: ",descripcion);
                    xstrCapsSpaceFixer(descripcion);
                    strcpy(sec[verificacion].descripcion,descripcion);
                    printf("\nDescrupcion actualizada.\n");
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
