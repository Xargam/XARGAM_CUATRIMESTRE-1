#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[20];
    int legajo;
    float sueldo;
    char sexo;

}empleados;

void mostrarPlantel(empleados emp[],int elementos);

int main()
{
    empleados plantel[] = {{"Leo",25,25.5,'m'},{"Martin",48,48.5,'m'}};
    mostrarPlantel(plantel,2);
    return 0;
}



void mostrarPlantel(empleados emp[], int elementos)
{
    for(int i = 0; i < elementos;i++)
    {
        printf("%s\n",emp[i].nombre);
        printf("%d\n",emp[i].legajo);
        printf("%c\n",emp[i].sexo);
        printf("%.2f\n",emp[i].sueldo);
    }
}

