#include <stdio.h>
#include <stdlib.h>
#define TAM 5

/*
6-	Se registran de los 50 medicamentos que existen en una farmacia el código de producto , el precio y la cantidad en existencia. Se pide:
a-	Listado ordenado por código de producto
b-	Código del medicamento de precio mas bajo
*/

typedef struct
{
    int codigoProducto ;
    float precio ;
    int stock ;

} eMedicamentos  ;

int main()
{
    int i;
    int j;
    int codigoBajo;
    float precioBajo;
    int flag = 0;
    eMedicamentos farmacos[TAM];
    eMedicamentos *ptrMed;
    eMedicamentos aux;
    ptrMed = farmacos;

    for( i = 0 ; i < TAM ; i++ )
    {
        printf("Ingrese el codigo de producto: ");
        scanf("%d", &(*(ptrMed + i )).codigoProducto );
        fflush(stdin);

        printf("\nIngrese el precio: ");
        scanf("%f", &(*(ptrMed + i )).precio );
        fflush(stdin);

        printf("\nStock: ");
        scanf("%d", &(*(ptrMed + i)).stock );
        fflush(stdin);

        if(flag == 0)
        {
            codigoBajo = (*(ptrMed + i)).codigoProducto ;
            precioBajo = (*(ptrMed + i)).precio ;
            flag++;
        }
        else if( (*(ptrMed + i )).precio  < precioBajo)
        {
            precioBajo = (*(ptrMed + i)).codigoProducto  ;
            codigoBajo = (*(ptrMed + i)).codigoProducto ;

        }
    }

    for( i = 0 ; i < TAM - 1 ; i++ )
    {
        for(j = i + 1 ; j < TAM ; j++)
        {
            if( (*(ptrMed + j )).codigoProducto  > (*(ptrMed + i)).codigoProducto )
            {
               aux = (*(ptrMed + i)) ;
               (*(ptrMed + i )) = (*(ptrMed + j)) ;
               (*(ptrMed + j))  = aux;
            }
        }
    }

    printf("El producto de precio mas bajo tiene el codigo %d\n", codigoBajo);
    printf("COD DE PRODUCTO  PRECIO\tSTOCK\n\n");
    for(i = 0 ; i < TAM ; i++)
    {
        printf("%d            %.2f\t %d\n", (*(ptrMed +i )).codigoProducto , (*(ptrMed + i)).precio , (*(ptrMed + i)).stock );
    }



    return 0;
}

