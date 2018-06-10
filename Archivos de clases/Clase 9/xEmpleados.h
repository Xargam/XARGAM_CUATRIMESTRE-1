#ifndef xEMPLEADOS_H_INCLUDED
#define xEMPLEADOS_H_INCLUDED


typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int legajo;
    char nombre[50];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
    int idSector;
    int isBusy;

}eEmpleado;

typedef struct
{
    int idSector;
    char descripcion[51];
    int isBusy;

}eSector;

//Prototipos empleados:

void hardCodear(eSector sec[]);
void inicializarEmpleados(eEmpleado[], int);
void mostrarTodosLosEmpleados(eEmpleado vec[], int tamEmp,eSector sec[],int tamSec);
void mostrarEmpleado(eEmpleado emp,eSector sec[],int tamSec);
int buscarIndiceLibre(eEmpleado[], int);
int buscarEmpleado(eEmpleado[], int, int);
void bajaEmpleado(eEmpleado emp[],int tam,eSector sec[], int tamSec);
void modificarEmpleado(eEmpleado emp[],int tam);
void altaEmpleado(eEmpleado emp[], int tam);
eEmpleado pedirEmpleado(void);
void ordenarEmpleados(eEmpleado emp[], int tam);

//Prototipos sectores:

#endif // xEMPLEADOS_H_INCLUDED
