#ifndef XPRODUCTOS_PROVEEDORES_H_INCLUDED
#define XPRODUCTOS_PROVEEDORES_H_INCLUDED

#include "xProductos.h"
#include "xProveedores.h"

//Funciones de menu:

void altaMenu(eProductos prods[],int prodTam,int* codigoProducto,eProveedores provs[],int provTam,int* codigoProveedor );
void bajaMenu(eProductos prods[],int prodTam,eProveedores provs[],int provTam);
void modificacionMenu(eProductos prods[],int prodTam,eProveedores provs[],int provTam);
void mostrarMenuInformar( eProductos prods[], int prodTam , eProveedores provs[] , int provTam );
void mostrarMenuListar( eProductos prods[], int prodTam , eProveedores provs[] , int provTam );

//FUNCIONES MENU INFORMAR:

void prodMostrarImportesMayoresAlPromedio ( eProductos prod[] , int prodTam ,eProveedores prov[] , int provTam);
void prodMostrarImportesMenoresAlPromedio ( eProductos prod[] , int prodTam ,eProveedores prov[] , int provTam);
void prodMostrarStocksMenorIgual10 ( eProductos prod[] , int prodTam ,eProveedores prov[] , int provTam);
void prodMostrarStocksMayor10 ( eProductos prod[] , int prodTam ,eProveedores prov[] , int provTam);

//FUNCIONES MENU LISTAR:

void ordenarProductos(eProductos prod[] , int prodTam ,eProveedores prov[] , int provTam);
void ListarProdsCantMenorIgualA10(eProductos prod[] , int prodTam ,eProveedores prov[] , int provTam);
void ListarProdsCantMayorA10(eProductos prod[] , int prodTam ,eProveedores prov[] , int provTam);
void ListarProdsImportesMayoresAlPromedio(eProductos prod[] , int prodTam ,eProveedores prov[] , int provTam);
void ListarProdsImportesMenoresAlPromedio(eProductos prod[] , int prodTam ,eProveedores prov[] , int provTam);
void ListarProvsCantidadProdMenorIgualA10(eProductos prod[] , int prodTam ,eProveedores prov[] , int provTam);
void ListarProductorPorProveedor(eProductos prod[] , int prodTam ,eProveedores prov[] , int provTam);
void ListarProductosDeUnProveedor(eProductos prod[] , int prodTam ,eProveedores prov[] , int provTam);
void ListarProveedorMasProductos(eProductos prod[] , int prodTam ,eProveedores prov[] , int provTam);
void ListarProveedorMenosProductos(eProductos prod[] , int prodTam ,eProveedores prov[] , int provTam);
void ListarProveedorProductoMasCaro(eProductos prod[] , int prodTam ,eProveedores prov[] , int provTam);
void ListarProveedorProductoMasBarato(eProductos prod[] , int prodTam ,eProveedores prov[] , int provTam);


#endif // XPRODUCTOS
