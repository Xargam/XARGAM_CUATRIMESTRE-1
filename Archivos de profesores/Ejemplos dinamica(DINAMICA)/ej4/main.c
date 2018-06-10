#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;

}eEmpleado;

void mostrarEmp(eEmpleado* );

eEmpleado* newEmpleadoParam(int, char*, float);

eEmpleado* newEmpleado();

int main()
{
    eEmpleado* unEmpleado;

    unEmpleado=newEmpleadoParam(1234,"Jorge",20000);

    if(unEmpleado == NULL)
    {
        printf("No hay memo \n\n");
        exit(1);
    }

    mostrarEmp(unEmpleado);

    return 0;
}

void mostrarEmp(eEmpleado* emp)
{
    printf("%d %s %.2f\n",emp->legajo,emp->nombre,emp->sueldo);
}

eEmpleado* newEmpleado()
{
    eEmpleado* p;

    p=(eEmpleado*) malloc(sizeof(eEmpleado));

    if(p != NULL)
    {
        p->legajo = 0;
        strcpy(p->nombre,"");
        p->sueldo=0;
    }

    return p;
}

eEmpleado* newEmpleadoParam(int legajo, char* nombre, float sueldo)
{
    eEmpleado* p;

    p=(eEmpleado*) malloc(sizeof(eEmpleado));

    if(p != NULL)
    {
        p->legajo = legajo;
        strcpy(p->nombre,nombre);
        p->sueldo=sueldo;
    }

    return p;
}
