#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;

    printf("Sumas de 3 en 3 hasta 99:\n");
    for(i = 3; i < 100; i += 3)
    {
        printf("%d\n",i);
    }
    return 0;
}
