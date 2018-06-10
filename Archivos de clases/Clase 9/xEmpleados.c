#include <stdio.h>
#include <stdlib.h>
#include "xEmpleados.h"
#include "xget.h"
#include "xvalidate.h"


/** \brief Elimina un empleado del sistema.
 *
 * \param emp: Recibe un vector de empleados para que el usuario busque en el posibles empleados a borrar.
 * \param tam: tamaño del vector de empleado.
 * \return
 *
 */

void bajaEmpleado(eEmpleado emp[],int tam,eSector sec[], int tamSec)
{
    int legajo, salir;
    int verificacion;
    mostrarTodosLosEmpleados(emp,tam,sec,tamSec);
    legajo = getConditionedInt(1,1,"Ingrese legajo del empleado a dar de baja: ","Legajo invalido reingrese: ");
    verificacion = buscarEmpleado(emp,tam,legajo);
    if(verificacion == -1)
    {
        printf("Legajo no encontrado.\n");
    }
    else
    {
        printf("\nDara de baja al siguiente empleado: \n");
        mostrarEmpleado(emp[verificacion]);
        salir = validateExit("Confirmar baja? s/n:\n",'s');
        system("cls");
        if(salir == 1)
        {
            emp[verificacion].isBusy = 0;
            printf("Baja completada.\n");
        }
        else
        {
            printf("Accion anulada.\n");
        }
    }
}



/** \brief Inicializa el estado de los empleados del vector en 0, para ser leidos como desocupados.
 *
 * \param vec: Vector de empleados a inicializar.
 * \param tam: Cantidad de elementos del vector.
 * \return
 *
 */

void inicializarEmpleados(eEmpleado vec[], int tam)
{
    for(int i=0; i< tam; i++)
    {
        vec[i].isBusy = 0;
    }
}

void mostrarTodosLosEmpleados(eEmpleado emp[], int tamEmp,eSector sec[],int tamSec)
{
    system("cls");
    printf("---Lista de Empleados---\n\n");
    printf("  Sector   Legajo  Nombre   Sexo   Sueldo   Fecha de Ingreso \n\n");
    for(int i=0; i< tamEmp; i++)
    {
        if(emp[i].isBusy == 1)
        {
            for(int j = 0; j < tamSec; j++)
            {
                if(emp[i].idSector == sec[j].idSector)
                {
                    printf("%s\t%d\t%s\t%c\t%.2f\t%d/%d/%d",sec[j].descripcion,emp[i].legajo,emp[i].nombre,emp[i].sueldo,emp[i].fechaIngreso.dia,emp[i].fechaIngreso.mes,emp[i].fechaIngreso.anio);
                }
            }
        }
    }



    /** \brief Muestra UN empleado.
     *
     * \param emp: Variable de tipo eEmpleado a mostrar.
     * \return
     *
     */

    void mostrarEmpleado(eEmpleado emp,eSector sec,int tam)
    {
        for(int j = 0; j < tamSec; j++)
        {
            if(emp.idSector == sec[j].idSector)
            {
                printf("%s\t%d\t%s\t%c\t%.2f\t%d/%d/%d",sec[j].descripcion);
            }
        }

    }

    int buscarIndiceLibre(eEmpleado emp[], int tam)
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



    /** \brief Da de alta un nuevo empleado al sistema verificando que el legajo no se repita y que haya espacio.
     *
     * \param emp: vector donde se dara de alta el empleado.
     * \param tam: cantidad de elementos del vector.
     * \return
     *
     */

    void altaEmpleado(eEmpleado emp[], int tam)
    {
        int legajo,IndiceEmpleadoRepetido;
        int indiceLibre = buscarIndiceLibre(emp,tam);

        if(indiceLibre == -1)
        {
            printf("No hay espacio suficiente para cargar otro empleado.\n");
        }
        else
        {
            legajo = getConditionedInt(1,1,"\nIngrese legajo del empleado: ","El numero de legajo es invalido, reingrese: ");
            IndiceEmpleadoRepetido = buscarEmpleado(emp, tam, legajo);
            if(IndiceEmpleadoRepetido == -1)
            {
                printf("\n\nLegajo dado de alta en el sistema.\n");
                emp[indiceLibre] = pedirEmpleado();
                emp[indiceLibre].legajo = legajo;
            }
            else
            {
                printf("El legajo ya ha sido cargado en el sistema:\n\n");
                mostrarEmpleado(emp[IndiceEmpleadoRepetido]);
            }
        }
    }



    /** \brief Pide datos de un empleado excluyendo el legajo, debido a que se debe validar antes de ser cargado.
     *
     * \return Devuelve una variable de tipo de eEmpleado cargada de datos.
     *
     */

    eEmpleado pedirEmpleado(void)
    {
        eEmpleado nuevoEmpleado;
        int dia, mes, anio;
        char nombre[50];

        nuevoEmpleado.idSector = getRangedInt(1,5,"Ingrese sector del empleado: ","Error el sector no existe, reingrese: ");
        getRangedStr(2,49,"\nIngrese nombre del empleado: ","Nombre invalido, reingrese: ",nombre);
        xstrCapsSpaceFixer(nombre);
        strcpy(nuevoEmpleado.nombre,nombre);
        nuevoEmpleado.sexo = getGenre("Ingese sexo del empleado (f o m): ","Sexo invalido, reingrese: ");
        getValidDate("\nIngrese fecha de ingreso: ","Reingrese la fecha: ",2018,1900,&dia,&mes,&anio);
        nuevoEmpleado.fechaIngreso.dia = dia;
        nuevoEmpleado.fechaIngreso.mes = mes;
        nuevoEmpleado.fechaIngreso.anio = anio;

        nuevoEmpleado.sueldo = getConditionedFloat(0,1,"Ingrese sueldo del empleado: $","Sueldo invalido, reingrese: ");
        printf("\n");
        nuevoEmpleado.isBusy = 1;

        return nuevoEmpleado;
    }



    /** \brief Permite al usuario modificar datos de un empleado en un vector de empleados.
     *
     * \param emp: Vector de empleados donde el usuario buscara.
     * \param tam: D
     * \return
     *
     */

    void modificarEmpleado(eEmpleado emp[],int tam)
    {
        system("cls");
        printf("Lista de emplados: ");
        mostrarTodosLosEmpleados(emp,tam);

        int legajo = getInt("\nIngrese el legajo del empleado a modificar: ");
        int salir = 0, dia, mes, anio, seleccion, legajoRepetido;
        char nombre[50];
        int indiceEmpleadoLegajo = buscarEmpleado(emp,tam,legajo);

        if(indiceEmpleadoLegajo > -1)
        {
            system("cls");
            printf("Va a modificar el siguiente empleado:\n\n");
            mostrarEmpleado(emp[indiceEmpleadoLegajo]);
            if(validateExit("Confirmar: s/n: ",'s') == 1)
            {
                do
                {
                    xlkHeadGenerator("Modificar empleado:");
                    system("color 06");
                    mostrarEmpleado(emp[indiceEmpleadoLegajo]);
                    xlkIndexBodyGenerator(7,"1-Cambiar legajo.","2-Cambiar nombre.","3-Cambiar fecha de ingreso.","4-Cambiar sueldo.","5-Cambiar sexo","6-Cambiar sector.","7-Volver.");
                    seleccion = getInt("Seleccionar opcion: ");
                    switch(seleccion)
                    {
                    case 1:
                        legajo = getConditionedInt(1,1,"Ingrese nuevo legajo: ","Legajo invalido: ");
                        legajoRepetido = buscarEmpleado(emp,tam,legajo);
                        if(legajoRepetido == -1)
                        {
                            emp[indiceEmpleadoLegajo].legajo = legajo;
                            printf("\nLegajo actualizado.\n");
                        }
                        else
                        {
                            printf("El legajo que intenta cargar se encuentra en uso:\n");
                        }
                        system("pause");
                        break;
                    case 2:
                        getRangedStr(2,49,"Ingrese nuevo nombre: ","Nombre invalido, reingrese: ",nombre);
                        xstrCapsSpaceFixer(nombre);
                        strcpy(emp[indiceEmpleadoLegajo].nombre,nombre);
                        printf("\nNombre actualizado.\n");
                        system("pause");
                        break;
                    case 3:
                        getValidDate("Ingrese fecha de ingreso: ","Reingrese la fecha: ",2018,1900,&dia,&mes,&anio);
                        emp[indiceEmpleadoLegajo].fechaIngreso.dia = dia;
                        emp[indiceEmpleadoLegajo].fechaIngreso.mes = mes;
                        emp[indiceEmpleadoLegajo].fechaIngreso.anio = anio;
                        printf("\nFecha actualizada.\n");
                        system("pause");
                        break;
                    case 4:
                        emp[indiceEmpleadoLegajo].sueldo = getConditionedFloat(0,1,"Ingrese nuevo sueldo: $","Sueldo invalido, reingrese: ");
                        printf("\nSueldo actualizado.\n");
                        system("pause");
                        break;
                    case 5:
                        emp[indiceEmpleadoLegajo].sexo = getGenre("Ingrese nuevo sexo: ","Sexo invalido, reingrese: ");
                        printf("\nSexo actualizado.\n");
                        system("pause");
                        break;
                    case 6:
                        emp[indiceEmpleadoLegajo].idSector = getRangedInt(1,5,"Ingrese nuevo sector del empleado: ","Error el sector no existe, reingrese: ");
                        printf("\nSector actualizado.\n");
                        system("pause");
                        break;
                    case 7:
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
            else
            {
                printf("\n\nAccion cancelada.\n");
            }
        }
        else
        {
            printf("\nEl empleado no se encontro.\n");
        }
    }

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


    void hardCodear(eSector sec[])
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

//listar todos los empleados
//listar los sectores por empleados.
