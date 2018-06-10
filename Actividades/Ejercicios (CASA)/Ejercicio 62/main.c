#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int i;
    int A[100];
    int B[100];
    int C[100];

    for(i = 0; i < 100; i++)
    {
         C[i] = 0;
    }
    for(i = 0;i < 100; i++)
    {
        A[i] = 1+rand() % ( 11 - 1);
        B[i] = -4+rand() % (2 - -4);
    }

    C[0] = A[0];
    C[1] = B[0];

    for(i = 0; i < 100; i++)
    {
        if(A[i] < C[0])
        {
            C[0] = A[i];
        }
        if(B[i] < C[1] )
        {
            C[1] = B[i];
        }

    }
    printf("Elementos del vector A:\n");
    for(i =0; i < 100; i++)
    {
        printf("\t%d ",A[i]);

    }
    printf("\nElementos del vector B:\n");
     for(i =0; i < 100; i++)
    {
        printf("\t%d ",B[i]);

    }
    printf("\nElementos del vector C:\n");
    for(i = 0; i < 100; i++)
    {
        printf("\t%d ",C[i]);
    }

    return 0;
}
