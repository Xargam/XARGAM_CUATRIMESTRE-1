#include <stdio.h>
#include <stdlib.h>
#include "xget.h"

int main()
{
    int vec[5];

    for(int i = 0; i < 5 ; i++)
    {
        printf("Ingrese numero: ");
        scanf("%d", vec + i);
        setbuf(stdin, NULL);
    }

    for(int i = 0; i < 5 ; i++)
    {
        printf("%d\n", *(vec + i));
    }


    return 0;
}
