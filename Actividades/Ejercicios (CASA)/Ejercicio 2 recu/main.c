#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[41];
    char localidad[41];

    printf("Ingrese su localidad:\n");
    scanf("%s",localidad);
    fflush(stdin);

    printf("Ingrese su nombre:\n");
    scanf("%s",nombre);

    printf("Usted se llama %s y vive en %s.", nombre, localidad);

    return 0;
}
