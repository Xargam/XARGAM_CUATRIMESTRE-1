#include <stdio.h>
#include <stdlib.h>
#include "xlook.h"
#include "xvalidate.h"
#define CANT 50

int main()
{
    int vec[CANT]={};
    int exit = 0;
    int selection;
    int i;
    int j;
    int aux;
    int flag = 0;

    while(exit == 0)
    {
        system("cls");
        xlkIndexGenerator("Vector Tool.", 4 , "1-Cargar vector." , "2-Ordenar vector." , "3-Mostrar vector." , "4-Salir.");
        printf("- Seleccionar opcion: ");
        scanf("%d" , &selection );
        fflush(stdin);
        switch(selection)
        {
        case 1:
            for(i = 0 ; i < CANT ; i++ )
            {
                if( *(vec + i) == 0)
                {
                    printf("\nIngrese un numero: ");
                    scanf("%d", vec + i);
                    flag++;
                    break;
                }
            }
            if(flag == 0)
            {
                printf("No hay espacio");;
            }
            printf("\nNumero cargado.");
            break;
        case 2:
            for( i = 0 ; i < CANT-1 ; i++)
            {
                for(j = i + 1 ; j < CANT  ; j++)
                {
                    if( *(vec + j) > *(vec + i))
                    {
                        aux = *(vec + i);
                        *(vec + i) = *(vec + j);
                        *(vec + j) = aux;
                    }
                }
            }
            printf("\nElementos ordenados de mayor a menor.");
            break;
        case 3:
            printf("\n");
            for( i = 0 ; i < CANT ; i++ )
            {
                if( *(vec + i ) != 0)
                {
                    printf("%d\n", *(vec + i));
                    flag++;
                }

            }
            if(flag == 0)
            {
                printf("No hay elementos cargados en el vector.");
            }
            break;
        case 4:
            exit = validateDualExit("\nEsta seguro de que desea salir? s/n : ","\nNo se reconoce su respuesta, reingrese: ",'s','n');
            break;
        }
        flag = 0;
        system("pause");

    }
    return 0;
}
