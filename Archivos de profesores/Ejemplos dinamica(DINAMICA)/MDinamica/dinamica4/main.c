#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int legajo;
    char nombre[20];
    float sueldo;
}eEmpleado;

void mostrarEmpleado(eEmpleado*);
eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int, char*, float);
int main()
{
    eEmpleado* unEmpleado;

    unEmpleado = newEmpleadoParam(1234, "Jorge", 20000);

    if(unEmpleado == NULL){
        exit(1);
    }

    mostrarEmpleado(unEmpleado);

    return 0;
}

void mostrarEmpleado(eEmpleado* emp){

    printf("%d %s %.2f\n", emp->legajo, emp->nombre, emp->sueldo);
}

eEmpleado* newEmpleado(){

    eEmpleado* p;

    p = (eEmpleado*) malloc( sizeof(eEmpleado));
    if( p != NULL){
        p->legajo = 0;
        strcpy(p->nombre, "");
        p->sueldo = 0;
    }
    return p;
}

eEmpleado* newEmpleadoParam(int legajo, char* nombre, float sueldo){

    eEmpleado* p;

    p = (eEmpleado*) malloc( sizeof(eEmpleado));
    if( p != NULL){
        p->legajo = legajo;
        strcpy(p->nombre, nombre);
        p->sueldo = sueldo;
    }
    return p;
}

