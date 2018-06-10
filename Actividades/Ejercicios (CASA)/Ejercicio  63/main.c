#include <stdio.h>
#include <stdlib.h>
#define CANT 100

int main()
{
    int i;
    int edad[CANT];
    int salario[CANT];
    int acumulador = 0;
    float promedio;

    for(i = 0; i < CANT; i++)
    {
        printf("Ingrese salario del empleado de legajo %d: \n",i+1);
        scanf("%d",&salario[i]);
        while(salario[i] < 0)
        {
            printf("ERROR: salario invalido. REINGRESAR: \n");
            scanf("%d",&salario[i]);
        }
        printf("Ingrese edad del empleado de legajo %d: \n",i+1);
        scanf("%d",&edad[i]);

        while(edad[i] > 150 || edad[i] < 0)
        {
            printf("ERROR: edad invalida. REINGRESAR: \n");
            scanf("%d",&edad[i]);

        }
        acumulador += edad[i];

    }

    promedio = (float) acumulador / CANT;

    for(i = 0; i < CANT; i++)
    {
        int contador = 0;

        if(edad[i] > promedio)
        {
            printf("El empleado de legajo %d supera el promedio de edad de %.2f años. Tiene %d años.\n",i+1,promedio, edad[i]);
            contador++;
        }
        if(contador == 0 && i == CANT - 1)
        {
            printf("No hubo empleados que superen la edad promedio.");
        }

    }


    return 0;
}
