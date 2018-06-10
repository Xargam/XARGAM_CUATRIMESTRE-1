#include <stdio.h>
#include <stdlib.h>
#include "xmath.h"
#include <ctype.h>
#include <conio.h>

#define CANT 3

int main()
{
    int acumulador = 0;
    int edad[CANT];
    char sexo[CANT], sexoMayor;
    int legajo[CANT], legMayor;
    float promedioEdad;
    int maxEdad, flag = 0, contadorMujeres1978 = 0;

    for(int i = 0; i < CANT; i++)
    {
        printf("Ingrese legajo del empleado: \n");
        scanf("%d",&legajo[i]);
        setbuf(stdin, NULL);

        rangedGetInt(&edad[i],18,150,"Ingrese edad del empleado: \n","La edad debe estar entre 18 años y 150 años. Reingrese:\n");
        do
        {
            printf("Ingrese sexo del empleado('f' o 'm'): \n");
            sexo[i] = getch();
            sexo[i] = tolower(sexo[i]);
        }
        while(sexo[i] != 'f' && sexo[i] != 'm');

        if(flag == 0 || edad[i] > maxEdad)
        {
            maxEdad = edad[i];
            legMayor = legajo[i];
            sexoMayor = sexo[i];
            flag++;

        }
        if(sexo[i] == 'f' && edad[i] == 40)
        {
            contadorMujeres1978++;
        }
        acumulador += edad[i];
    }
    promedioEdad = (float)  acumulador / CANT;
    printf("El promedio de edad de los empleados es %.2f\n",promedioEdad);
    printf("Hubo %d mujeres nacidas en 1978\n",contadorMujeres1978);
    printf("La persona de mayor edad tiene %d años, su legajo es %d y su sexo es %c",maxEdad,legMayor,sexoMayor);

    return 0;
}
