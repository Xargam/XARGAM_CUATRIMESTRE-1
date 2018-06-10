#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xmath.h"
#include "xvector.h"
#include "xget.h"


/*5-Una casa de repuestos registra el código de artículo (5 caracteres) ,
precio y cantidad de las 100 piezas que posee.
Se necesita contar con la posibilidad de ver distintos listados de acuerdo
 a la necesidad del usuario, es decir:
•	Listado ordenado por código de producto.
•	Listado ordenado por precio.
•	Listado ordenado por cantidad.
•	Listado de los códigos de pieza que tienen menos de 5 unidades en stock.
*/

#define CANT 100
#define CHARS 6

int main()
{
    char artCod[CANT][CHARS];
    float precio[CANT];
    int stock[CANT], seleccion = 0;
    for(int i = 0; i < CANT;  i++)
    {
        printf("Ingrese codigo de producto %d: ",i+1);
        getRangedSimStr(artCod[i],"","El codigo debe tener 5 letras.\nReingresar: ",5,5);
        strlwr(artCod[i]);
        printf("Ingrese el precio del producto %d: ",i+1);
        precio[i] = getFloat("");
        while(precio[i] < 0)
        {
            printf("El precio no puede ser negativo.\n Reingresar: ");
            precio[i] = getFloat("");
        }
        printf("Ingrese el stock del producto %d: ",i+1);
        stock[i] = getInt("");
    }
    system("cls");
    while(seleccion != 5)
    {
        system("cls");
        indexGenerator("Respuestos LEO",5,"1-Lista por codigo de producto.","2-Lista por precio.","3-Lista por stock.","4-Lista por stock menor a 5.","5-Salir.");
        seleccion = getRangedInt(1,5,"SELECCIONAR OPCION: ","ERROR OPCION INVALIDA.\nREINGRESAR: ");
        switch(seleccion)
        {

        case 1:
            for(int i = 0; i < CANT-1; i++)
            {
                for(int j = i+1; j < CANT; j++)
                {
                    if(strcmp(artCod[j],artCod[i]) < 0)
                    {
                        xvecFSwap(&precio[j],&precio[i]);
                        xvecISwap(&stock[i],&stock[j]);
                        xvecSSwap(artCod[j],artCod[i]);
                    }
                }
            }

            printf("Cod de producto:\tPrecio:\tStock:\n");
            for(int i = 0; i < CANT; i++)
            {
                printf("%s\t\t\t%.2f%d\n",artCod[i],precio[i],stock[i]);
            }
            system("pause");
            break;
        case 2:
            for(int i = 0; i < CANT-1; i++)
            {
                for(int j = i+1; j < CANT; j++)
                {
                    if(precio[j] < precio[i])
                    {
                        xvecFSwap(&precio[j],&precio[i]);
                        xvecISwap(&stock[i],&stock[j]);
                        xvecSSwap(artCod[j],artCod[i]);
                    }
                }
            }
            printf("Cod de producto:\tPrecio:\tStock:\n");
            for(int i = 0; i < CANT; i++)
            {
                printf("%s\t\t\t%.2f\t%d\n",artCod[i],precio[i],stock[i]);
            }
            system("pause");
            break;
        case 3:
            for(int i = 0; i < CANT-1; i++)
            {
                for(int j = i+1; j < CANT; j++)
                {
                    if(stock[j] > stock[i])
                    {
                        xvecFSwap(&precio[j],&precio[i]);
                        xvecISwap(&stock[i],&stock[j]);
                        xvecSSwap(artCod[j],artCod[i]);
                    }
                }
            }
            printf("Cod de producto:\tPrecio:\tStock:\n");
            for(int i = 0; i < CANT; i++)
            {
                printf("%s\t\t\t%.2f\t%d\n",artCod[i],precio[i],stock[i]);
            }
            system("pause");
            break;
        case 4:
            for(int i = 0; i < CANT-1; i++)
            {
                for(int j = i+1; j < CANT; j++)
                {
                    if(stock[j] > stock[i])
                    {
                        xvecFSwap(&precio[j],&precio[i]);
                        xvecISwap(&stock[i],&stock[j]);
                        xvecSSwap(artCod[j],artCod[i]);
                    }
                }
            }
            printf("Lista de productos con bajo stock: \n\n");
            printf("Cod de producto:\tPrecio:\tStock:\n");
            for(int i = 0; i < CANT; i++)
            {
                if(stock[i] < 5)
                {
                    printf("%s\t\t\t%.2f\t%d\n",artCod[i],precio[i],stock[i]);
                }
            }
            system("pause");
            break;
        case 5:
            seleccion = getInt("Presione 5 nuevamente para salir u otra tecla para continuar...\n");
            break;
        }

    }
    return 0;
}
