#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
    char nombre[20];
    int legajo;
    float sueldo;
    char sexo;
}eEmpleado;

void mostrarEmpleado(eEmpleado emp);

int main()
{
    eEmpleado unEmpleado = {"Juanete",105,8000.50,'m'};
    /*
    strcpy(unEmpleado.nombre, "Juanete");
    unEmpleado.legajo = 105;
    unEmpleado.sueldo = 8000.50;
    unEmpleado.sexo = 'm';
    */
    printf("Ingrese nombre: ");
    gets(unEmpleado.nombre);
    fflush(stdin);
    printf("Ingrese legajo: ");
    scanf("%d",&unEmpleado.legajo);
    setbuf(stdin, NULL);
    printf("Ingrese sueldo: ");
    scanf("%f",&unEmpleado.sueldo);
    setbuf(stdin, NULL);
    printf("Ingrese sexo: ");
    unEmpleado.sexo = getche();
    mostrarEmpleado(unEmpleado);
    return 0;
}

void mostrarEmpleado(eEmpleado emp)
{

    printf("\n\nNombre: %s\n",emp.nombre);
    printf("Legajo: %d\n",emp.legajo);
    printf("Sueldo: %.2f\n",emp.sueldo);
    printf("Sexo: %c\n",emp.sexo);
}


