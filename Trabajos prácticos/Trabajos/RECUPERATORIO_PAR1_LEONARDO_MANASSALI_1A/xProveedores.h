#ifndef XPROVEEDORES_H_INCLUDED
#define XPROVEEDORES_H_INCLUDED

#include "xProductos.h"

//Declaracion de estructuras:

typedef struct
{
    int codigoProveedor;
    char descripcion[51];
    int estado;

} eProveedores ;

//Funciones basicas:

void inicializarProveedores(eProveedores provs[], int provTam);
void harcodearProveedores( eProveedores provs[]);

//ABM DEPENDENCIAS:

int buscarProveedor(eProveedores provs[], int provTam,int codigoProveedor);
int buscarLibreProveedores(eProveedores provs[], int provTam);
eProveedores pedirProveedor(void);

//ALTA, BAJA Y MODIFICACION:

int altaProveedor( eProveedores provs[], int provTam, int* codigoProveedor );
//FUNCION BAJA SE ENCUENTRA EN xProductos-Proveedores
int modificarProveedor( eProveedores provs[], int provTam );

//FUNCIONES DE MUESTRA

void mostrarProveedor( eProveedores provVar );
int mostrarProveedores( eProveedores provs[] ,int provTam);

#endif // XPROVEEDORES_H


