#include <stdio.h>
#include <stdlib.h>
#include "xlook.h"
#define CANT 5

/*
5-	Un restaurante que dispone de 50 mesas , necesita llevar cuenta de las ventas diarias.
Para ello cada vez que una mesa es ocupada se registra el número de mesa y el valor de lo
que van consumiendo. Una vez que se cierra el local se deben obtener los siguientes resultados
a-	Venta total del día
b-	Mesas que no fueron ocupadas
c-	Listado ordenado por venta que muestre	Nro de mesa         Venta
*/

int main()
{
    float ventas[CANT] = {};
    int selection;
    int exit = 0;
    int mesa;
    int i;

    float acumulador = 0;

    while(exit == 0)
    {
        system("cls");
        xlkIndexGenerator("Tango Resto", 4, "1-Agregar venta","2-Venta total del día","3-Mesas que no fueron ocupadas", "4-Lista de ventas");
        printf("- seleccionar opcion: ");
        scanf("%d",&selection);
        switch(selection)
        {
        case 1:
            printf("Ingrese numero de mesa: ");
            scanf("%d", &mesa);
            fflush(stdin);
            if(mesa > CANT|| mesa < 1)
            {
                printf("\nError. El numero no existe");
            }
            else
            {
                printf("\nIngrese venta: ");
                scanf("%f", ventas + (mesa - 1));
                fflush(stdin);
            }
            break;
        case 2:
            for(i = 0 ; i < CANT ; i++)
            {
                if( *(ventas + i) != 0 )
                {
                    acumulador += *(ventas + i);
                }
            }
            printf("Recaudacion total: %.2f", acumulador);
            break;
        case 3:
            for( i = 0; i < CANT ; i++)
            {
                if( *(ventas + i) == 0)
                {
                    printf("Mesa %d nunca fue ocupada.\n", i+1);
                }
            }
            break;
        case 4:
            printf("\n\nNRO DE MESA:\tVENTA\n\n");
            for( i = 0 ; i < CANT ; i++)
            {
                if( *(ventas + i) != 0)
                {
                    printf("%d   %.2f\n", i +1, *(ventas + i ));
                }
            }
            break;
        default:
            printf("Opcion invalida.");
            break;
        }
        printf("\n\n");
        system("pause");
    }


    printf("Hello world!\n");
    return 0;
}
