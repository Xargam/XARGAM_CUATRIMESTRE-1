#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vec[20] ;
    int i;

    for( i = 0 ; i < 20 ; i++)
    {
        printf("Ingrese un numero: ");
        printf("\n");
        scanf("%d", vec + i);
        fflush(stdin);
    }

    for( i = 0 ; i < 20 ; i++ )
    {
        printf("%d\n" , *(vec + i ));
    }
    return 0;
}
