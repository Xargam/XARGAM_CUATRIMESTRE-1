#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;

    printf("Multiplos de 6 comprendidos entre 0 y 100:\n");
    for(i = 0; i < 101; i += 6)
    {
        printf("%d\n",i);
    }
    return 0;
}
