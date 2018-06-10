#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED


typedef struct
{
    char descripcion[150];
    float precio;
    int stock;
    int id;
    int estado;

}eProducto;

int buscarLibre(eProducto prod[],int elements);

eProducto pedirProducto();

int ingresarProductoEnLista(eProducto prod[], int elements);

void modificarProducto(eProducto prod[], int index);

void borrarProducto(eProducto prod[], int index);

void mostrarListaDeProductos(eProducto prod[],int elements);

void mostrarUnProducto(eProducto prod);

void ordenarProductos(eProducto prod[],int elements);

#endif // PRODUCTOS_H_INCLUDED
