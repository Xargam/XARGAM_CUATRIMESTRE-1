#ifndef xEMPLEADOS_H_INCLUDED
#define xEMPLEADOS_H_INCLUDED


//Declaracion de estructuras:

typedef struct
{
    int codigoProveedor;
    char descripcion[50];
    int status;
} eProveedores;

typedef struct
{
    int codigoProducto;
    int cantidad;
    float importe;
    char descripcion[50];
    int status;

} eProductos;

typedef struct
{
    int codigoProducto;
    int codigoProveedor;
    int status;

} eProductosProveedores;

//¡Para encontrar una funcion en xEmpleados.c copiar ID al costado del protipo y buscar!

//-----------------Prototipos de HARCODEO DE ESTRUCTURAS---------------------------------------------------------------#


//eProducto:

//void hardCodearEmp(eEmpleado emp[]); //XE1-1

//eProveedor:

//void hardCodearSec(eSector sec[]); //XE1-2


//-----------------Prototipos de funciones exclusivas eProductos--------------------------------------------------------#


//Basico:

void inicializarProductos(eProductos prod[], int tam); //XE1-3

//Funciones de muestra:

//void mostrarEmpleadosPorSector(eEmpleado emp[],int empTam,eSector sec[],int secTam); //XE1-4
void mostrarTodosLosProductos(eProductos prod[], int tamProd); //XE1-5
void mostrarProducto(eProductos prod); //XE1-6

// ABM dependencias:

int buscarProducto(eProductos prod[], int tam, int IDProducto); //XE1-7
int buscarIndiceLibreProducto(eProductos prod[], int tam); //XE1-8
eProductos pedirProducto(eProductosProveedores linker[],int linkerTam, eProveedores prov[],int tamProv); //XE1-9

//ALTA BAJA MODIFICACION:

int altaProducto(eProductos prod[], int tam,eProveedores prov[],int tamProv,eProductosProveedores linker[], int tamLinker,int* IDProd); //XE2-1
int bajaProducto(eProductos prod[], int tamProd); //XE2-2
int modificarProducto(eProductos prod[],int tamProd,eProveedores prov[],int tamProv); //XE2-3

//Adicionales:

//void ordenarEmpleados(eEmpleado emp[], int tam); //XE2-4


//-----------------Prototipos de funciones exclusivas eProveedores----------------------------------------------------------#


//Basico:

void inicializarProveedores(eProveedores prov[], int tam); //XE2-5

//Funciones de muestra:

void mostrarTodosLosProveedores(eProveedores prov[], int tamProv); //XE2-6
void mostrarProveedor(eProveedores prod);  //XE2-7

// ABM dependencias:

int buscarIndiceLibreProveedores(eProveedores prov[], int tam); //XE2-8
int buscarProveedores(eProveedores prov[],int tamProv,int IDProveedor); //XE2-9

//ALTA BAJA MODIFICACION:

int altaProveedor(eProveedores prov[],int tam, int* IDProveedor); //XE3-1
int bajaProveedor(eProveedores prov[],int tamProv); //XE3-2
int modificarProveedor(eProveedores prov[],int tamProv); //XE3-3

//Funciones de estructuras LINK:

void inicializarProductosProveedores(eProductosProveedores vec[], int tam);
int BuscarIndiceLibreProductosProveedores(eProductosProveedores linker[], int tam);

//XE3-3
#endif // xEMPLEADOS_H_INCLUDED

