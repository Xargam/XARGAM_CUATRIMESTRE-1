#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xvalidate.h"
#include "xget.h"
#include "xmath.h"
#include <ctype.h>


#define CANT 3



/*

6-	Realizar una agenda para guardar los datos de hasta 200 personas de las cuales se toman los siguientes datos:

		Nombre
		Apellido
		Dirección
        Localidad
		Código Postal
		Fecha de nacimiento (Día, Mes y Año)

Utilizar estructuras anidadas. Usar una función para validar las fechas.
Se pide que una vez cargados los datos,se disponga de un menú de opciones que me permita hacer las siguientes consultas
1-	Consulta por apellido
2-	Consulta por localidad
3-	Consulta por Año de nacimiento
4-	Consulta por cumpleaños
*/

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    char nombre[50];
    char apellido[50];
    char direccion[100];
    char localidad[50];
    int codigoPostal;
    eFecha fecha;
    int estado;
} ePersona;

int main()
{
    ePersona personas[CANT];
    int seleccion, indice = -1, cp, dia, mes, anio;

    for(int i = 0; i < CANT; i++)
    {
        personas[i].estado = 0;
    }

    do
    {
        system("cls");
        indexGenerator("Dateas: ",5,"1-Cargar personas.","2-Consulta por apellido.","3-Consulta por localidad.","4-Consulta por Año de nacimiento.","4-Consulta por cumpleaños");
        switch(seleccion = getRangedInt(1,5,"SELECCIONAR OPCION","OPCION INVALIDA.\nREINGRESAR: "))
        {
        case 1:
            for(int i = 0; i < CANT; i++)
            {
                if(personas[i].estado == 0)
                {
                    indice = i;
                    break;
                }
            }
            getRangedStr(1,49,"Ingrese nombre: ","Error, nombre muy largo o invalido. Reingresar: ",personas[indice].nombre);
            printf("\n");
            getRangedStr(1,49,"Ingrese apellido: ","Error, apellido muy largo o invalido. Reingresar: ",personas[indice].apellido);
            printf("\n");
            getRangedStr(2,99,"Ingrese direccion: ","Direccion muy larga o invalida. Reingresar: ",personas[indice].direccion);
            printf("\n");
            getRangedStr(0,49,"Ingrese localidad: ","Error, localidad muy larga o invalida. Reingresar: ",personas[indice].localidad);
            printf("\n");
            cp = getInt("Ingrese codigo postal: ");
            while(isdigit(cp) == 1)
            {
                cp = getInt("Ingrese codigo postal: ");
            }
            personas[indice].codigoPostal = cp;
            dia = 40;//getInt("Ingrese dia de nacimiento: ");
            mes = 03;//getInt("Ingrese mes de nacimiento: ");
            anio = 2018;//getInt("Ingrese año de nacimiento: ");
            while(validateDate(dia,mes,anio,1880,2018) < 0)
            {
                printf("Se ha producido un error al validar la fecha.\n");
                dia = getInt("Ingrese dia de nacimiento: ");
                mes = getInt("Ingrese mes de nacimiento: ");
                anio = getInt("Ingrese año de nacimiento: ");
            }
            personas[indice].fecha.dia = dia;
            personas[indice].fecha.mes = mes;
            personas[indice].fecha.anio = anio;

        }
    }
    while(validateESCExit() == 0);
    return 0;
}




