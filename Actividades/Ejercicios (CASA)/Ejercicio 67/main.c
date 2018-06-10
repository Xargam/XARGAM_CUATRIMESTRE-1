#include <stdio.h>
#include <stdlib.h>
#include "xmath.h"
#include <conio.h>
#include <ctype.h>

#define CANT 20
#define ESC 27


int main()
{
    char letra;
    while(letra != ESC)
    {
        system("cls");
        char seleccion;
        int numero, flag = 0, posicion;
        int vector[CANT] = {20,40,10,100,1000,-10,-20,-40,-80,-70,-100,-1000,80,-50,80,150,8000,10,1,0};
        indexGenerator(2,"a-Ingresar un numero y mostrar su posicion en el vector.","b-Ingresar la posicion del vector y mostrar el numero que contiene.");
        printf("\nSELECCIONAR OPCION: \n");
        seleccion = getch();
        seleccion = tolower(seleccion);

        if(seleccion == 'a')
        {
            printf("Ingrese un numero para buscar la posicion en el vector: \n");
            scanf("%d",&numero);
            setbuf(stdin, NULL);
            int i;
            for( i = 0; i < CANT; i++)
            {
                if(vector[i] == numero)
                {
                    printf("El numero %d se encuentra en la posicion %d\n",numero,i);
                    flag++;
                    break;
                }
            }
            if(flag == 0)
            {
                printf("El numero %d no se encuentra en el vector.\n",numero);
            }
        }
        else if(seleccion == 'b')
        {
            rangedGetInt(&posicion,0,19,"Ingrese la posicion del vector:\n","La posicion no existe, Reingrese:\n");
            printf("En la posicion %d se encuentra el numero %d.\n",posicion, vector[posicion]);


        }
        printf("Presion ESC para finalizar o presione otra tecla para continuar...\n");
        letra = getch();
    }

    return 0;
}


