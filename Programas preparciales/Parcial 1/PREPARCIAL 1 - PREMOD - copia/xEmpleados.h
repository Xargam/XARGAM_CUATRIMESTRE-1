#ifndef XPRODUCTOS_H_INCLUDED
#define XPRODUCTOS_H_INCLUDED


//Declaracion de estructuras:

typedef struct
{
    int dia ;
    int mes ;
    int anio ;

} eFecha ;

typedef struct
{
    int codigoProducto ;
    char descripcion[50] ;
    char sexo ;
    float importe ;
    eFecha fechaIngreso ;
    int codigoProveedor ;
    int isBusy ;

} eProductos ;

typedef struct
{
    int codigoProveedor ;
    char descripcion[50] ;
    int isBusy ;

} eProveedores ;

//¡Para encontrar una funcion en xEmpleados.c copiar ID al costado del protipo y buscar!

//-----------------Prototipos de HARCODEO DE ESTRUCTURAS---------------------------------------------------------------#


//eProductos:

void harcodearEmp( eProductos prod[] ); //XE1-1

//eProveedores:

void harcodearSec( eProveedores prov[] ); //XE1-2


//-----------------Prototipos de funciones exclusivas eProductos--------------------------------------------------------#


//Basico:

void inicializarEmpleados( eProductos prod[] , int prodTam ); //XE1-3

//Funciones de muestra:

void mostrarEmpleadosPorProveedor( eProductos prod[] , int prodTam , eProveedores prov[] , int provTam ); //XE1-4
void mostrarTodosLosEmpleados( eProductos prod[] , int prodTam , eProveedores prov[] , int provTam ); //XE1-5
void mostrarEmpleado( eProductos prodVar , eProveedores prov[] , int provTam ); //XE1-6

// ABM dependencias:

int buscarEmpleado( eProductos prod[] , int prodTam , int legajo ); //XE1-7
int buscarIndiceLibreEmp( eProductos prod[] , int prodTam ); //XE1-8
eProductos pedirEmpleado( eProductos prod[] , int prodTam , eProveedores prov[] , int provTam ); //XE1-9

//ALTA BAJA MODIFICACION:

int altaEmpleado( eProductos prod[] , int prodTam , eProveedores prov[] , int provTam ); //XE2-1
int bajaEmpleado( eProductos prod[] , int prodTam , eProveedores prov[] , int provTam ); //XE2-2
int modificarEmpleado( eProductos prod[] , int prodTam , eProveedores prov[] , int provTam ); //XE2-3

//Adicionales:

void ordenarEmpleados( eProductos prod[] , int prodTam ); //XE2-4


//-----------------Prototipos de funciones exclusivas eProveedores ---------------------------------------------------------#


//Basico:

void inicializarSectores( eProveedores prov[] , int provTam ); //XE2-5

//Funciones de muestra:

void mostrarTodosLosSectores( eProveedores prov[] , int provTam ); //XE2-6
void mostrarSector( eProveedores secVar );  //XE2-7

// ABM dependencias:

int buscarIndiceLibreSec( eProveedores prov[] , int provTam ); //XE2-8
int buscarSector( eProveedores prov[] , int provTam , int idDelSector ); //XE2-9

//ALTA BAJA MODIFICACION:

int altaSector( eProveedores prov[] , int provTam ); //XE3-1
int bajaSector( eProveedores prov[] , int provTam , eProductos prod[] , int prodTam ); //XE3-2
int modificarSector( eProveedores prov[] , int provTam , eProductos prod[] , int prodTam ); //XE3-3

//FUNCIONES DE MENU DE AMBAS ESTRUCTURAS:

void mostrarMenuEmpleados( eProductos prod[] , int prodTam , eProveedores prov[] , int provTam ); //XE3-4
void mostrarMenuSectores( eProductos prod[] , int prodTam , eProveedores prov[] , int provTam ); //XE3-5

#endif // xPRODUCTOS_H_INCLUDED
