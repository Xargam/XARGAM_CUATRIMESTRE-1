#ifndef XEMPLEADOS_H_INCLUDED
#define XEMPLEADOS_H_INCLUDED


//Declaracion de estructuras:

typedef struct
{
    int dia ;
    int mes ;
    int anio ;

} eFecha ;

typedef struct
{
    int legajo ;
    char nombre[50] ;
    char sexo ;
    float sueldo ;
    eFecha fechaIngreso ;
    int idSector ;
    int isBusy ;

} eEmpleados ;

typedef struct
{
    int idSector ;
    char descripcion[50] ;
    int isBusy ;

} eSectores ;

//¡Para encontrar una funcion en xEmpleados.c copiar ID al costado del protipo y buscar!

//-----------------Prototipos de HARCODEO DE ESTRUCTURAS---------------------------------------------------------------#


//eEmpleados:

void harcodearEmp( eEmpleados emp[] ); //XE1-1

//eSectores:

void harcodearSec( eSectores sec[] ); //XE1-2


//-----------------Prototipos de funciones exclusivas eEmpleados--------------------------------------------------------#


//Basico:

void inicializarEmpleados( eEmpleados emp[] , int empTam ); //XE1-3

//Funciones de muestra:

void mostrarEmpleadosPorProveedor( eEmpleados emp[] , int empTam , eSectores sec[] , int secTam ); //XE1-4
void mostrarTodosLosEmpleados( eEmpleados emp[] , int empTam , eSectores sec[] , int secTam ); //XE1-5
void mostrarEmpleado( eEmpleados empVar , eSectores sec[] , int secTam ); //XE1-6

// ABM dependencias:

int buscarEmpleado( eEmpleados emp[] , int empTam , int legajo ); //XE1-7
int buscarIndiceLibreEmp( eEmpleados emp[] , int empTam ); //XE1-8
eEmpleados pedirEmpleado( eEmpleados emp[] , int empTam , eSectores sec[] , int secTam ); //XE1-9

//ALTA BAJA MODIFICACION:

int altaEmpleado( eEmpleados emp[] , int empTam , eSectores sec[] , int secTam ); //XE2-1
int bajaEmpleado( eEmpleados emp[] , int empTam , eSectores sec[] , int secTam ); //XE2-2
int modificarEmpleado( eEmpleados emp[] , int empTam , eSectores sec[] , int secTam ); //XE2-3

//Adicionales:

void ordenarEmpleados( eEmpleados emp[] , int empTam ); //XE2-4


//-----------------Prototipos de funciones exclusivas eSectores ---------------------------------------------------------#


//Basico:

void inicializarSectores( eSectores sec[] , int secTam ); //XE2-5

//Funciones de muestra:

void mostrarTodosLosSectores( eSectores sec[] , int secTam ); //XE2-6
void mostrarSector( eSectores secVar );  //XE2-7

// ABM dependencias:

int buscarIndiceLibreSec( eSectores sec[] , int secTam ); //XE2-8
int buscarSector( eSectores sec[] , int secTam , int idDelSector ); //XE2-9

//ALTA BAJA MODIFICACION:

int altaSector( eSectores sec[] , int secTam ); //XE3-1
int bajaSector( eSectores sec[] , int secTam , eEmpleados emp[] , int empTam ); //XE3-2
int modificarSector( eSectores sec[] , int secTam , eEmpleados emp[] , int empTam ); //XE3-3

//FUNCIONES DE MENU DE AMBAS ESTRUCTURAS:

void mostrarMenuEmpleados( eEmpleados emp[] , int empTam , eSectores sec[] , int secTam ); //XE3-4
void mostrarMenuSectores( eEmpleados emp[] , int empTam , eSectores sec[] , int secTam ); //XE3-5

#endif // xEMPLEADOS_H_INCLUDED
