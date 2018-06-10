#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[] = {1,2,45,78,8,9,47,47,48,484,8,458,489,4868,788,111,789,4555,123123,3},i;

    printf("Elementos del vector sin ordenar: \n\n");
    for(i = 0; i < 20; i++)
    {
        printf("%d ",vector[i]);
    }

    printf("\n\n");
    printf("Elementos del vector ordenados de manera decreciente: \n\n");

    for(i = 0; i < 19; i++)
    {
        for(int j = i+1; j < 20;j++ )
        {
            if(vector[i] < vector[j])
            {
                int aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }

    for(i = 0; i < 20; i++)
    {
        printf("%d ",vector[i]);
    }




    return 0;
}
