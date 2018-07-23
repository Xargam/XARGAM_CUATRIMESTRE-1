#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int anio;
    int mes;
    int dia;

} eFecha;

typedef struct
{
    char* nombre;
    eFecha fechaNacimiento;
} eAlumno;

eAlumno* newAlumno(int dia, int mes, int anio);

int main()
{
    if( alumno != NULL)
    {
        printf("FECHA %d/%d/%d NOMBRE %s\n",alumno->fechaNacimiento.anio,alumno->fechaNacimiento.mes,alumno->fechaNacimiento.dia,alumno->nombre);
    }

    return 0;
}
