#include <stdio.h>
#include <stdlib.h>
#include "xvalidate.h"
#include "xlook.h"

#define CANT 20

/*
4-	Cargar un vector de 20 elementos usando punteros. Una vez terminada la carga y por medio de un menú de opciones realizar lo siguiente:
a-	Ingresar un número y mostrar en que posición dentro del vector se encuentra
b-	Ingresar la posición del vector y mostrar el número que se encuentra en esa posición
Si la posición es incorrecta o el número no se encuentra se debe mostrar un mensaje de error.
Ambos puntos deben ser hechos por medio de punteros.
*/

int main()
{
    int i;
    int exit = 0;
    int selection;
    int num;
    int vec[CANT];

    for(i = 0 ; i < CANT ; i++ )
    {
        printf("Ingrese un numero: ");
        scanf("%d" , vec + i);
        fflush(stdin);
    }

    while(exit == 0)
    {
        system("cls");
        xlkIndexGenerator("Vector tool V2" , 2 , "1-Ingresar un número y mostrar en que posición dentro del vector esta." , "2-Ingresar la posición del vector y mostrar el número de la misma.");
        scanf("%d" , &selection);
        fflush(stdin);
        switch(selection)
        {
        case 1:
            printf("Ingrese un numero: ");
            scanf("%d", &num);
            for( i = 0 ; i < CANT ; i++ )
            {
                if( *(vec + i) == num)
                {
                    printf("El numero se encuentra en la posicion %d del vector.\n", i);
                    break;
                }
            }
            if(i == CANT)
            {
                printf("No se encuntra el numero.");
            }
            break;
        case 2:
            printf("Ingrese un numero de posicion: ");
            scanf("%d", &num);
            if(num > CANT - 1 || num < 0)
            {
                printf("La posicion no existe en el vector.");
            }
            else
            {
                printf("El numero de la posicion %d es %d.", num , *( vec + num ));
            }
            break;
        default:
            printf("Opcion invalida.");
            break;
        }
        system("pause");
    }
    return 0;
}
