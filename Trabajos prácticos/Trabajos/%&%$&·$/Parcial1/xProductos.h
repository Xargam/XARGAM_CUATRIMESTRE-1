#ifndef XPRODUCTOS_H_INCLUDED
#define XPRODUCTOS_H_INCLUDED

#include "xProveedores.h"

//Declaracion de estructuras:

typedef struct
{
    int codigoProduto;
    int codigoProveedor;
    char descripcion[51];
    float importe;
    int cantidad;
    int estado;

} eProductos ;

//Funciones basicas:

void inicializarProductos(eProductos prods[], int prodTam);

//ABM DEPENDENCIAS:

int buscarProducto(eProductos prods[], int prodTam,int codigoProducto);
int buscarLibreProductos(eProductos prods[], int prodTam);
eProductos pedirProducto(void);

//ALTA, BAJA Y MODIFICACION:

int altaProducto(eProductos prods[], int prodTam, eProveedores provs[], int provTam, int* codigoProducto);
int bajaProducto(eProductos prods[], int prodTam, eProveedores provs[], int provTam);
int modificarProducto(eProductos prods[], int prodTam, eProveedores provs[], int provTam);

//FUNCIONES DE MUESTRA

void mostrarProducto( eProductos prodVar, eProveedores provs[] , int provTam);
void mostrarProductos( eProductos prods[] , int prodTam, eProveedores provs[] ,int provTam);


#endif // XPRODUCTOS_H
