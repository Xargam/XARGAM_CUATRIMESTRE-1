#ifndef XEMPLEADOS_H_INCLUDED
#define XEMPLEADOS_H_INCLUDED


//Declaracion de estructuras:


typedef struct
{
    int codigoProducto ;
    char descripcion[50] ;
    float importe ;
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

void harcodearProd( eProductos prod[] ); //XE1-1

//eProveedores:

void harcodearProv( eProveedores prov[] ); //XE1-2


//-----------------Prototipos de funciones exclusivas eProductos--------------------------------------------------------#


//Basico:

void inicializarProductos( eProductos prod[] , int prodTam ); //XE1-3

//Funciones de muestra:

void mostrarProductosPorProveedor( eProductos prod[] , int prodTam , eProveedores prov[] , int provTam ); //XE1-4
void mostrarTodosLosProductos( eProductos prod[] , int prodTam , eProveedores prov[] , int provTam ); //XE1-5
void mostrarProducto( eProductos prodVar, eProveedores prov[] , int provTam ); //XE1-6

// ABM dependencias:

int buscarProducto( eProductos prod[] , int prodTam , int codigoDelProducto ); //XE1-7
int buscarIndiceLibreProd( eProductos prod[] , int prodTam ); //XE1-8
eProductos pedirProducto( eProductos prod[] , int prodTam , eProveedores prov[] , int provTam ); //XE1-9

//ALTA BAJA MODIFICACION:

int altaProducto( eProductos prod[] , int prodTam , eProveedores prov[] , int provTam ); //XE2-1
int bajaProducto( eProductos prod[] , int prodTam , eProveedores prov[] , int provTam ); //XE2-2
int modificarProducto( eProductos prod[] , int prodTam , eProveedores prov[] , int provTam ); //XE2-3

//Adicionales:

void ordenarProductos( eProductos prod[] , int prodTam ); //XE2-4


//-----------------Prototipos de funciones exclusivas eProveedores ---------------------------------------------------------#


//Basico:

void inicializarProveedores( eProveedores prov[] , int provTam ); //XE2-5

//Funciones de muestra:

void mostrarTodosLosProveedores( eProveedores prov[] , int provTam ); //XE2-6
void mostrarProveedor( eProveedores provVar );  //XE2-7

// ABM dependencias:

int buscarIndiceLibreProv( eProveedores prov[] , int provTam ); //XE2-8
int buscarProveedor( eProveedores prov[] , int provTam , int codigoDelProveedor ); //XE2-9

//ALTA BAJA MODIFICACION:

int altaProveedor( eProveedores prov[] , int provTam ); //XE3-1
int bajaProveedor( eProveedores prov[] , int provTam , eProductos prod[] , int prodTam ); //XE3-2
int modificarProveedor( eProveedores prov[] , int provTam , eProductos prod[] , int prodTam ); //XE3-3

//FUNCIONES DE MENU DE AMBAS ESTRUCTURAS:

void mostrarMenuProductos( eProductos prod[] , int prodTam , eProveedores prov[] , int provTam ); //XE3-4
void mostrarMenuProveedores( eProductos prod[] , int prodTam , eProveedores prov[] , int provTam ); //XE3-5

#endif // xEMPLEADOS_H_INCLUDED
