#include <stdio.h>
#include <stdlib.h>

int main()
{
    char dia[11];

    printf("Ingrese un dia de semana:\n");
    scanf("%s",dia);

    if(dia[11] == 'lunes' || dia[11] == 'martes' || dia[11] == 'miercoles' || dia[11] == 'jueves' || dia[11] == 'viernes')
    {
        printf("A trabajar.");
    }
    else if(dia[11] == 'sabado' || dia[11] == 'domingo')
    {
        printf("Buen finde.");
    }
    else
    {
        printf("No has ingresado un dia valido.");
    }

    return 0;
}
