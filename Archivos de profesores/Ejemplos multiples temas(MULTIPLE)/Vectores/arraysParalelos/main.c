#include <stdio.h>
#include <stdlib.h>
#define CANT 5

int main()
{
    int i, leg[CANT], edad[CANT];
    float sueldo[CANT];

    for(i=0; i<CANT; i++){
        leg[i] = i+1;

        printf("\nEdad: ");
        scanf("%d", &edad[i]);

        printf("\nSueldo: ");
        scanf("%f", &sueldo[i]);
    }

    printf("\nLeg\tEdad\tSueldo");
    for(i=0; i<CANT; i++){
        printf("\n%d\t%d\t%.2f", leg[i], edad[i], sueldo[i]);
    }

    return 0;
}
