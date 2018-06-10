#include <stdio.h>
#include <stdlib.h>

#define CANT 3

int main()
{
    int codigoP[CANT], cantidad[CANT], iPrecioMin;
    float precio[CANT], precioMin;
    for(int i = 0;i < CANT; i++)
    {
        printf("\nIngrese codigo de producto: ");
        scanf("%d",&codigoP[i]);
        printf("\nIngrese precio del producto: ");
        scanf("%f",&precio[i]);
        printf("\nIngrese el inventario del producto: ");
        scanf("%d",&cantidad[i]);
        system("cls");

    }

    for(int i = 0; i < CANT-1; i++)
    {
        for(int j = i+1; j < CANT; j++)
        {
            if(codigoP[i] < codigoP[j])
            {
                int aux = codigoP[i];
                codigoP[i] = codigoP[j];
                codigoP[j] = aux;

                aux = precio[i];
                precio[i] = precio[j];
                precio[j] = aux;

                aux = cantidad[i];
                cantidad[i] = cantidad[j];
                cantidad[j] = aux;
            }

        }

    }
    precioMin = precio[0];
    iPrecioMin = 0;
    for(int i = 0; i < CANT; i++)
    {
        if(precio[i] < precioMin)
        {
            precioMin = precio[i];
            iPrecioMin = i;
        }

    }
    printf("Cod de producto:\tPrecio:\tStock:\n");
    {
        for(int i = 0; i < CANT; i++)
        {
            printf("%d\t                %.2f\t%d\n",codigoP[i],precio[i],cantidad[i]);
        }
    }
    printf("\nEl codigo del medicamento de precio mas bajo es %d, su precio $%.2f",codigoP[iPrecioMin],precioMin);
    return 0;
}

