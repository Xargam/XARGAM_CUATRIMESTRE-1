#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Productos.h"
#include "xstring.h"
#include "xget.h"
#include "xmath.h"
#include "xvalidate.h"

int buscarLibre(eProducto prod[],int elements)
{
    int index = -1;
    for(int i = 0; i < elements; i++)
    {
        if(prod[i].estado == 0)
        {
            index = i;
        }
    }
    return index;
}

eProducto pedirProducto()
{
    char descripcion[150];
    eProducto prod;
    prod.id = getConditionedInt(1,1,"Ingrese ID del producto: ","ID invalida, reingrese: ");
    getRangedStr(0,149,"Ingrese descripcion del producto: ","Descripcion invalida, reingrese: ",descripcion);
    xstrCapsSpaceFixer(descripcion);
    strcpy(prod.descripcion,descripcion);
    prod.precio = getConditionedFloat(0,1,"Ingrese precio del producto: ","Precio invalido, reingrese: ");
    prod.stock = getConditionedInt(0,1,"Ingrese stock del producto: ","stock invalido, reingrese: ");
    prod.estado = 1;
    return prod;
}

int ingresarProductoEnLista(eProducto prod[], int elements)
{
    int index = buscarLibre(prod,elements);
    if(index != -1)
    {
        prod[index] = pedirProducto();
    }
    return index;
}

void mostrarUnProducto(eProducto prod)
{
    printf("\nID:\tDescripcion:\tPrecio:\tStock:\n");
    printf("%d\t%s\t\t%.2f\t%d\t\n",prod.id,prod.descripcion,prod.precio,prod.stock);
}

void mostrarListaDeProductos(eProducto prod[],int elements)
{
    for(int i = 0; i < elements; i++)
    {
        if(prod[i].estado == 1)
        {
            mostrarUnProducto(prod[i]);
        }

    }

}

void borrarProducto(eProducto prod[], int index)
{
    prod[index].estado = 0;
}

void modificarProducto(eProducto prod[], int index)
{
    int selection, salir = 0,seguro = 0;
    char descripcion[150];
    do
    {
        system("cls");
        mostrarUnProducto(prod[index]);
        indexGenerator("Modificar este produco: ",5,"1-Cambiar ID.","2-Cambiar descripcion.","3-Cambiar precio.","4-Cambiar stock","5-Volver.");
        selection = getRangedInt(1,5,"Seleccionar opcion: ","Opcion invalida, reingrese: ");
        switch(selection)
        {
        case 1:
            seguro = validateExit("Seguro que desea realizar una modificacion? s/n\n",'s');
            if(seguro == 1)
            {
                prod[index].id = getConditionedInt(1,1,"Ingrese nueva ID del producto: ","ID invalida, reingrese: ");
            }
            break;
        case 2:
            seguro = validateExit("Seguro que desea realizar una modificacion? s/n\n",'s');
            if(seguro == 1)
            {
                getRangedStr(0,149,"Ingrese nueva descripcion del producto: ","Descripcion invalida, reingrese: ",descripcion);
                xstrCapsSpaceFixer(descripcion);
                strcpy(prod[index].descripcion,descripcion);
            }
            break;
        case 3:
            seguro = validateExit("Seguro que desea realizar una modificacion? s/n\n",'s');
            if(seguro == 1)
            {
                prod[index].precio = getConditionedFloat(0,1,"Ingrese nuevo precio del producto: ","Precio invalido, reingrese: ");
            }
            break;
        case 4:
            seguro = validateExit("Seguro que desea realizar una modificacion? s/n\n",'s');
            if(seguro == 1)
            {
                prod[index].stock = getConditionedInt(0,1,"Ingrese nuevo stock del producto: ","stock invalido, reingrese: ");
            }
            break;
        case 5:
            salir = 1;
            break;
        }
    }
    while(salir == 0);


}



void ordenarProductos(eProducto prod[],int elements)
{
    for(int i = 0; i < elements-1; i++)
    {
        for(int j = i+1; j < elements; j++)
        {
            if(stricmp(prod[j].descripcion,prod[i].descripcion) < 0)
            {
                eProducto aux;
                aux = prod[i];
                prod[i] = prod[j];
                prod[j] = aux;
            }
        }
    }
}
