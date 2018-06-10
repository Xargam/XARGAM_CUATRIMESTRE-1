#ifndef xEMPLEADOS_H_INCLUDED
#define xEMPLEADOS_H_INCLUDED


//Declaracion de estructuras:

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

} eEmpleado;

typedef struct
{
    int idSector;
    char descripcion[51];
    int isBusy;

} eSector;

//¡Para encontrar una funcion en xEmpleados.c copiar ID al costado del protipo y buscar!

//-----------------Prototipos de HARCODEO DE ESTRUCTURAS---------------------------------------------------------------#


//eEmpleado:

void hardCodearEmp(eEmpleado emp[]); //XE1-1

//eSector:

void hardCodearSec(eSector sec[]); //XE1-2


//-----------------Prototipos de funciones exclusivas eEmpleado--------------------------------------------------------#


//Basico:

void inicializarEmpleados(eEmpleado[], int tam); //XE1-3

//Funciones de muestra:

void mostrarEmpleadosPorSector(eEmpleado emp[],int empTam,eSector sec[],int secTam); //XE1-4
void mostrarTodosLosEmpleados(eEmpleado emp[], int tamEmp,eSector sec[],int tamSec); //XE1-5
void mostrarEmpleado(eEmpleado emp,eSector sec[],int tamSec); //XE1-6

// ABM dependencias:

int buscarEmpleado(eEmpleado vec[], int tam, int legajo); //XE1-7
int buscarIndiceLibreEmp(eEmpleado emp[], int tam); //XE1-8
eEmpleado pedirEmpleado(eEmpleado emp[],int empTam, eSector sec[],int tamSec); //XE1-9

//ALTA BAJA MODIFICACION:

int altaEmpleado(eEmpleado emp[], int tam,eSector sec[],int tamSec); //XE2-1
int bajaEmpleado(eEmpleado emp[],int tam,eSector sec[], int tamSec); //XE2-2
int modificarEmpleado(eEmpleado emp[],int tam,eSector sec[],int secTam); //XE2-3

//Adicionales:

void ordenarEmpleados(eEmpleado emp[], int tam); //XE2-4


//-----------------Prototipos de funciones exclusivas eSector----------------------------------------------------------#


//Basico:

void inicializarSectores(eSector sec[], int tam); //XE2-5

//Funciones de muestra:

void mostrarTodosLosSectores(eSector sec[], int tamSec); //XE2-6
void mostrarSector(eSector sec);  //XE2-7

// ABM dependencias:

int buscarIndiceLibreSec(eSector sec[], int tam); //XE2-8
int buscarIdSector(eSector sec[],int tam,int id); //XE2-9

//ALTA BAJA MODIFICACION:

int altaSector(eSector sec[],int tam); //XE3-1
int bajaSector(eSector sec[],int tam, eEmpleado emp[],int empTam); //XE3-2
int modificarSector(eSector sec[],int tam); //XE3-3

#endif // xEMPLEADOS_H_INCLUDED
