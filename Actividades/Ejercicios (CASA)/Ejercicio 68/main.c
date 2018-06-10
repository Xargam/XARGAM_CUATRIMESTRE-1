#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "xmath.h"

#define CANT 50
#define ESC 27

int main()
{
    int numMesa, flag = 0;
    float acumulador = 0,mesa[CANT];
    char seleccion, letra;


    for(int i = 0; i < CANT; i++)
    {
        mesa[i] = 0;
    }

    while(letra != ESC)
    {
        system("cls");
        indexGenerator(4,"a-Venta total del dia","b-Ver mesas desocupadas en todo el dia","c-Lista de ventas","d-Ingresar ventas");
        printf("Ingrese opcion: ");
        seleccion = getche();
        printf("\n");

        switch(seleccion)
        {
        case 'a':
            for(int i = 0; i < CANT; i++)
            {
                acumulador += mesa[i];
            }
            printf("\nLa venta total del dia es de $%.2f\n",acumulador);
            acumulador = 0;
            break;
        case 'b':
            printf("Mesas desocupadas: \n");
            for(int i = 0; i < CANT; i++)
            {
                if(mesa[i] == 0)
                {
                    printf("Mesa %d\n",i+1);
                    flag++;
                }
            }
            if(flag == 0)
            {
                printf("No hubo mesas desocupadas...\n");
            }
            flag = 0;
            break;
        case 'c':
            printf("\nMesa Nro:\tVentas:\n");
            for(int i = 0; i < CANT; i++)
            {
                printf("%d\t        %.2f\n",i+1,mesa[i]);
            }
            break;
        case 'd':
            rangedGetInt(&numMesa,1,50,"Ingrese el numero de mesa: ","El numero de mesa no es valido,reingresar: ");
            printf("Consumicion equivalente a: $");
            scanf("%f",&mesa[numMesa-1]);
            setbuf(stdin,NULL);
            break;
        }
        printf("Presione ESC para finalizar u otra tecla para continuar...\n");
        letra = getch();

    }
    return 0;
}





