#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numero;
    int numEntero;
    int i;

    printf("Ingrese un numero:\n");
    scanf("%f",&numero);
    printf("Numeros naturales hallados desde %.2f al uno:\n",numero);

    numEntero = (int) numero;


    if(numEntero < 1)
    {
        printf("1\n");
    }
    else
    {
        for(i = 1 ;i <= numEntero ;i++)
        {
            printf("%d\n",i);
        }

    }


    return 0;
}
