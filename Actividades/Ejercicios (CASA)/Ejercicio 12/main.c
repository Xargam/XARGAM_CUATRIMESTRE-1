#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contadorImpares = 0;
    int i;

    printf("Numeros impares de 0 a 100:\n");

    for(i = 0; i < 101; i++ )
    {
        if(i % 2 != 0)
        {
            printf("%d\n",i);
            contadorImpares++;

        }
    }

    printf("Se han hallado %d numeros impares entre 0 y 100 inclusive.",contadorImpares);

    return 0;
}
