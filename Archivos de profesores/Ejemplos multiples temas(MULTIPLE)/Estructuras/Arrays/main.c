#include <stdio.h>
#include <stdlib.h>



typedef struct {
    char nombre[20];
    int legajo;
    float sueldo;
    char sexo;
}eEmpleado;

void mostrarEmpleado(eEmpleado);
void mostrarEmpleados(eEmpleado[], int);
void ordenarEmpleados(eEmpleado[], int);


int main()
{

 eEmpleado plantel[] = {{"Juan", 1111, 1000.75, 'm'},{"Ana", 2222, 20000, 'f'},{"Luis", 3333, 30000, 'm'}};

/*
 unEmpleado.legajo = 1234;
 strcpy(unEmpleado.nombre, "Juan");
 unEmpleado.sueldo = 50000.50;
 unEmpleado.sexo = 'm';

printf("Ingrese nombre: ");
gets(unEmpleado.nombre);
printf("Ingrese legajo: ");
scanf("%d", &unEmpleado.legajo);
printf("Ingrese sueldo: ");
scanf("%f", &unEmpleado.sueldo);
printf("Ingrese sexo: ");
fflush(stdin);
scanf("%c", &unEmpleado.sexo);
*/
//mostrarEmpleados(plantel, 3);

ordenarEmpleados(plantel, 3);

mostrarEmpleados(plantel, 3);

    return 0;
}

void mostrarEmpleados(eEmpleado vec[], int tam){
    for(int i=0; i< tam; i++){

        mostrarEmpleado(vec[i]);
    }
}
void mostrarEmpleado(eEmpleado emp){
 printf("\nNombre: %s \n", emp.nombre);
 printf("Legajo: %d \n", emp.legajo);
 printf("Sueldo: %.2f \n", emp.sueldo);
 printf("Sexo: %c \n", emp.sexo);
}

void ordenarEmpleados(eEmpleado vec[], int tam){

eEmpleado aux;

for(int i=0; i< tam-1; i++){
    for(int j= i+1; j<tam; j++){
        if( strcmp(vec[i].nombre, vec[j].nombre) > 0){
            aux = vec[i];
            vec[i] = vec[j];
            vec[j] = aux;
        }
    }
}



}
