#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    printf("Numeros pares entre 1 y 100:\n");

    for(i = 1; i < 101; i++ )
    {
        if(i % 2 == 0)
        {
            printf("%d\n",i);


        }
    }

    return 0;
}
