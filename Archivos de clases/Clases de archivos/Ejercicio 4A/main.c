#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
    int estado ;

} eEmpleado ;

void inicializarEmpleados(eEmpleado* empPtr, int tam);
eEmpleado* newEmpleado(void);
eEmpleado* newArrayEmpleados(int tam);
eEmpleado* newEmpleadoParam(char* nombre,int legajo, float sueldo);
void mostrarEmpleado(eEmpleado* empPtr);
void mostrarEmpleados(eEmpleado* empPtr , int tam);



int main()
{
    FILE* archivo ;
    eEmpleado* empleados ;

    if( (archivo = fopen("empleado.bin","rb")) == NULL )
    {
        if( (archivo = fopen("empleado.bin","wb")) == NULL )
        {
            printf("No se pudo abrir un archivo escencial...");
            exit(1);
        }
    }
    else
    {
        if( (archivo = fopen("empleado.bin","ab")) == NULL   )
        {
            printf("No se puedo abrir un archivo escencial...");
            exit(1);
        }
    }

    empleados = newArrayEmpleados(5);
    mostrarEmpleados(empleados,5);
    //printf("legajo: %d Nombre: %s Sueldo %.2f  Estado: %d\n", (*(empleados)).legajo, (*(empleados)).nombre, (*(empleados)).sueldo,(*(empleados)).estado );
    system("pause");
    free(empleados);
    fclose(archivo);
    return 0;
}

/* eEmpleado* newEmpleado(void)
{
    eEmpleado* empleado ;
    empleado = (eEmpleado*) malloc(sizeof( eEmpleado ));
    if( empleado != NULL)
    {
        (*(empleado)).legajo = 0;
        (*(empleado)).sueldo = 0.0;
        strcpy( (*(empleado)).nombre , "");
    }
    return empleado;
} */

eEmpleado* newEmpleado(void)
{
    eEmpleado* empleado ;
    if( (empleado = (eEmpleado*) malloc(sizeof( eEmpleado ))) != NULL)
    {
        (*(empleado)).legajo = 0;
        (*(empleado)).sueldo = 0.0;
        strcpy( (*(empleado)).nombre, "");
        (*(empleado)).estado = 0;
    }
    return empleado;
}

eEmpleado* newArrayEmpleados(int tam)
{
    eEmpleado* nuevoEmpleado = NULL;
    if(tam > 1)
    {
        nuevoEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado)*tam );
        if(nuevoEmpleado != NULL)
        {
            inicializarEmpleados(nuevoEmpleado , tam);
        }
    }
    return nuevoEmpleado;

}

eEmpleado* newEmpleadoParam(char* nombre,int legajo, float sueldo)
{
    eEmpleado* empleado ;
    empleado = newEmpleado();
    if( empleado != NULL)
    {
        (*(empleado)).legajo = legajo;
        (*(empleado)).sueldo = sueldo;
        strcpy( (*(empleado)).nombre, nombre );
        (*(empleado)).estado = 1;
    }
    return empleado;
}

void mostrarEmpleado(eEmpleado* empPtr)
{
    if(empPtr != NULL && (*(empPtr)).estado)
    {
        printf("%s %d %.2f\n", (*(empPtr)).nombre, (*(empPtr)).legajo, (*(empPtr)).sueldo  );
    }
}

void mostrarEmpleados(eEmpleado* empPtr , int tam)
{
    int i ;
    if(empPtr != NULL && tam > 0)
    {
        for(i = 0 ; i < tam ; i++)
        {
            if( (*(empPtr + i)).estado )
            {
                mostrarEmpleado((empPtr + i));
            }
        }
    }
}

void inicializarEmpleados(eEmpleado* empPtr, int tam)
{
    int i ;
    if( empPtr != NULL && tam > 0)
    {
        for(i = 0 ; i < tam ; i++)
        {
            (*(empPtr + i)).estado = 0;
        }
    }
}
