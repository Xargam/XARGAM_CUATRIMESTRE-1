#include <stdio.h>
#include <stdlib.h>
#include "xmath.h"
#include "xvalidate.h"
#include "xget.h"
#include "Productos.h"

#define CANT 5



/*char descripcion[CANT][30] = {" "};
    char auxDescripcion[310];
    int stock[CANT] = {};
    float precio[CANT]= {};
    int id[CANT] = {
*/

int main()
{
    int salir = 0;
    int flag;
    int seleccion;
    eProducto productos[CANT];
    for(int i = 0; i < CANT; i++)
    {
        productos[i].estado = 0;
    }
    do
    {
        flag = 0;
        indexGenerator("Leo Store 2.0",6,"1-Cargar producto","2-Mostrar productos","3-Ordenar productos","4-Borrar producto","5-Modificar producto","6-Salir");
        seleccion = getRangedInt(1,6,"Seleccionar opcion: ","Opcion invalida, reingrese: ");
        switch(seleccion)
        {
        case 1:
            if(buscarLibre(productos,CANT) == -1)
            {
                printf("No hay suficiente espacio para cargar otro producto.\n");

            }
            else
            {
                ingresarProductoEnLista(productos,CANT);
                printf("\nProducto ingresado al sistema.\n\n");
            }
            break;
        case 2:
            mostrarListaDeProductos(productos,CANT);
            break;
        case 3:
            ordenarProductos(productos,CANT);
            printf("\nSe ordenaron los productos alfabeticamente.\n");
            break;
        case 4:
            printf("Lista de productos:\n");
            mostrarListaDeProductos(productos,CANT);
            seleccion = getConditionedInt(1,1,"\nIngrese la ID del producto que desea borrar: ","ID invalida, reingrese: ");
            for(int i = 0; i < CANT; i++)
            {
                if(seleccion == productos[i].id)
                {
                    flag++;
                    printf("\n\nSe borrara el siguiente producto: \n");
                    mostrarUnProducto(productos[i]);
                    if(validateExit("\nConfirmar? s/n: ",'s') == 1)
                    {
                        borrarProducto(productos,i);
                    }
                    else
                    {
                        printf("\nAccion anulada.\n");
                    }
                    printf("\n");
                    break;
                }
            }
            if(flag == 0)
            {
                printf("\nLa ID ingresada no se ha encontrado.\n");
            }
            break;
        case 5:
            system("cls");
            printf("Lista de productos:\n");
            mostrarListaDeProductos(productos,CANT);
            seleccion = getConditionedInt(1,1,"\nIngrese la ID del producto que desea modificar: ","ID invalida, reingrese: ");
            for(int i = 0; i < CANT; i++)
            {
                if(seleccion == productos[i].id)
                {
                    flag++;
                    system("cls");
                    printf("Producto: ");
                    modificarProducto(productos,i);
                    break;
                }
            }
            if(flag == 0)
            {
                printf("\nLa ID ingresada no se ha encontrado.\n");
            }
            break;
        case 6:
            salir = validateESCExit();
            break;
        }
        system("pause");
        system("cls");
    }
    while(salir == 0);
    return 0;
}
