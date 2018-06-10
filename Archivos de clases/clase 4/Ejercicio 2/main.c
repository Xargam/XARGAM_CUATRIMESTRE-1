#include <stdio.h>
#include <stdlib.h>

int main()
{
    #define CANT 5

    int legajo[CANT], i,edad[CANT];;
    float sueldo[CANT];

    for(i = 0; i < CANT; i++)
    {
        legajo[i] = i + 1;

        printf("Ingrese el sueldo: \n",i + 1);
        scanf("%f", &sueldo[i]);

        printf("Ingrese la edad\n");
        scanf("%d", &edad[i]);
    }

    for(i = 0; i < CANT; i++)
    {
        printf("Numero de legajo %d \tsueldo %.2f \tedad %d\n",legajo[i], sueldo[i],edad[i]);
    }



    return 0;
}
