#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "xmath.h"
#define ESC 27
#define CANT 5

int main()
{
    int seleccion;
    char letra = 's';
    char descripcion[CANT][30] = {" "};
    char auxDescripcion[310];
    int stock[CANT] = {};
    float precio[CANT]= {};
    int id[CANT] = {};
    int posicion;

    while(letra == 's')
    {
        system("cls");
        printf("Menu:\n");
        printf("1-Cargar vector\n");
        printf("2-Mostrar vector\n");
        printf("3-Ordenar vector\n");
        printf("4-Salir\n\n");
        printf("Seleccione opcion: ");
        scanf("%d",&seleccion);
        setbuf(stdin,NULL);
        switch(seleccion)
        {
        case 1:
            posicion = findFreeSlot(id,CANT);
            if(posicion != -1)
            {
                printf("\nIngrese id del producto: ");
                scanf("%d",&id[posicion]);
                setbuf(stdin, NULL);
                do
                {
                    printf("\nIngrese descripcion del producto: ");
                    scanf("%[^\n]",auxDescripcion);
                    setbuf(stdin, NULL);

                }
                while(strlen(auxDescripcion) > 30);
                strcpy(descripcion[posicion],auxDescripcion);
                printf("\nIngrese el precio del producto: $");
                scanf("%f",&precio[posicion]);
                setbuf(stdin, NULL);
                printf("\nIngrese stock disponible: ");
                scanf("%d", &stock[posicion]);
            }
            else
            {
                printf("No hay espacio para guardar datos.\n");
                printf("Desea borrar algun dato? s/n\n");
                letra = tolower(letra);
                letra = getch();
                if(letra == 's')
                {
                    printf("Escribir el numero correspondiente a los datos que desea borrar: \n");
                    printf("\tID:\tDescripcion:\tPrecio:\tStock\t\n");
                    for(int i = 0; i < CANT; i++)
                    {
                        printf("%d- \t%d\t%s\t\t%.2f\t%d\t\n",i+1,id[i],descripcion[i],precio[i],stock[i]);
                    }
                    printf("Ingrese datos a borrar: ");
                    scanf("%d",&seleccion-1);

                    id[seleccion] = 0;
                    strcpy(descripcion[seleccion],"");
                    precio[seleccion] = 0.0;
                    stock[seleccion] = 0;
                }
            }
            letra = 's';
            break;
        case 2:
            printf("%s\t%s\t%s\t%s\t\n","ID:","Descripcion:","Precio:","Stock:");
            for(int i = 0; i < CANT; i++)
            {
                printf("%d\t%s\t\t%.2f\t%d\t\n",id[i],descripcion[i],precio[i],stock[i]);
            }
            system("pause");
            break;
        case 3:
            for(int i = 0; i < CANT-1; i++)
            {
                for(int j = i+1; j < CANT; j++)
                {
                    if(stricmp(descripcion[j],descripcion[i]) < 0)
                    {
                        char auxS[30];
                        int auxI;
                        float auxF;

                        strcpy(auxS,descripcion[i]);
                        strcpy(descripcion[i],descripcion[j]);
                        strcpy(descripcion[j],auxS);

                        auxF = precio[i];
                        precio[i] = precio[j];
                        precio[j] = auxF;

                        auxI = id[i];
                        id[i] = id[j];
                        id[j] = auxI;

                        auxI = stock[i];
                        stock[i] = stock[j];
                        stock[j] = auxI;
                    }
                }
            }
            break;
        case 4:
            printf("Salir? s/n");
            letra = getch();
            break;
        }
    }
    return 0;
}
