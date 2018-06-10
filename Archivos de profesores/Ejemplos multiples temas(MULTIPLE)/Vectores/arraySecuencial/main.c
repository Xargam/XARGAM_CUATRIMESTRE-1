#include <stdio.h>
#include <stdlib.h>

#define CANT 5

int main()
{
    int i, vec[CANT];

    for(i=0; i<CANT; i++){
        printf("\nIngrese: ");
        scanf("%d", &vec[i]);
    }

    for(i=0; i<CANT; i++){
        printf("\n%d", vec[i]);
    }

    return 0;
}
