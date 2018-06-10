#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[] = {1,19,2,18,3,17,4,16,5,15,6,14,7,13,8,12,9,11,10,20}, mayor, indice;

    mayor = vector[0];
    indice = 0;

    printf("Elementos del vector 1: \n\n");
    for(int i = 0; i < 20; i++)
    {
        printf("%d ",vector[i]);
        if(vector[i] > mayor)
        {
            mayor = vector[i];
            indice = i;
        }
    }
    printf("\n\nEl elemento mayor es %d y se encuentra en el indice %d.\n",mayor,indice);


    return 0;
}
