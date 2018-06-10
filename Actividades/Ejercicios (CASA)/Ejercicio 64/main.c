#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[20] = {-5,888,123,242,-454,4987,45646,897,1000,11111,8,1,23,45,-879,789,-7777,-14232,1222,-64000};
    int i, j;

    printf("Vector tal como fue leido: \n");
    for(i = 0; i < 20; i++)
    {
        printf("%d\n",vector[i]);
    }

    printf("\nNumeros vector ordenados:\n");
    for(i = 0; i < 19; i++)
    {
        for(j = i+1;j< 20;j++)
        {
            if(vector[i] < vector[j])
            {
                int aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }

    for(i = 0; i < 20;i++)
    {
        if(vector[i] < 0)
        {
            break;
        }
    }

    for(; i < 19; i++)
    {
        for(j= i+1; j < 20; j++)
        {
            int aux;
            if(vector[i] > vector[j])
            aux = vector[i];
            vector[i] = vector[j];
            vector[j] = aux;
        }
    }

    for(i = 0; i < 20; i++)
    {
        printf("%d\n",vector[i]);
    }

    return 0;
}
