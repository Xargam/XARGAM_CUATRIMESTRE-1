#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero = 100;

    printf("Numeros del 100 al 0:\n");

    while(numero > -1 )
    {
        printf("%d\n",numero);
        numero--;
    }
    return 0;
}
