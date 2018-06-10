#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xlook.h"
#include "xstring.h"
#include "xget.h"
#include "xvalidate.h"


#define LIBRE 0
#define OCUPADO 1

#define CANT 3

//7-	Realizar un programa con un menú de opciones para hacer altas , bajas y modificaciones (ABM) de una agenda.

typedef struct
{
    int dia ;
    int mes ;
    int anio ;

} eFecha ;

typedef struct
{
    eFecha fechaEntrega ;
    char tarea[100] ;
    char tema[100] ;
    char materia[100] ;
    char profesor[100] ;
    int estado ;
    int numeroTarea ;
} eAgenda ;

int main()
{
    eAgenda agenda[CANT] ;
    eAgenda *ptrAgenda = agenda ;
    int exit = 0 ;
    int seleccion ;
    int i ;
    int numTarea = 0;

    for( i = 0 ; i < CANT ; i++)
    {
        (*( ptrAgenda + i )).estado = LIBRE ;
    }
    while(exit == 0)
    {
        xlkIndexGenerator("AGENDA",5, "1- ALTA ", "2- BAJA ", "3- MODIFICACION ", "4- MOSTRAR TAREAS ", "5-SALIR");
        if(inputGetInt(&seleccion, " -Seleccionar opcion: ", " *Opcion invalida.", 1, 5) == 1)
        {
            switch(seleccion)
            {
            case 1 :
                printf(" *ALTA TAREA:\n\n");
                for( i = 0 ; i < CANT ; i++ )
                {
                    if( (*(ptrAgenda + i )).estado == LIBRE )
                    {
                        getRangedStr(2,99,"INGRESE TAREA A AGENDAR: ", "ERROR DE VALIDACION, REINGRESE TAREA A AGENDAR : ", agenda[i].tarea );
                        getRangedStr(2,99,"INGRESE TEMA : ", "ERROR DE VALIDACION, REINGRESE TEMA : ",(*(ptrAgenda + i)).tema );
                        getRangedStr(2,99,"INGRESE MATERIA : ", "ERROR DE VALIDACION, REINGRESE MATERIA : ",(*(ptrAgenda + i)).materia );
                        getRangedStr(2,99,"INGRESE PROFESOR : ", "ERROR DE VALIDACION, REINGRESE PROFESOR : ",(*(ptrAgenda + i)).profesor );
                        getValidDate("INGRESE FECHA DE ENTREGA: ", "FECHA INVALIDA , REINGRESE: ",2030,2018, &(*(ptrAgenda + i)).fechaEntrega.dia, &(*(ptrAgenda + i)).fechaEntrega.mes, &(*(ptrAgenda + i)).fechaEntrega.anio );
                        (*(ptrAgenda + i)).estado = OCUPADO ;
                        numTarea++;
                        (*(ptrAgenda + i)).numeroTarea = numTarea ;
                        break;
                    }
                }
                break;
            case 2 :
                printf(" *BAJA TAREA:\n\n");
                printf(" NUM TAREA \t TEMA \t MATERIA PROFESOR \t FECHA DE ENTREGA \n\n");
                for( i = 0 ; i < CANT ; i++)
                {
                    if( (*(ptrAgenda + i )).estado == OCUPADO )
                    {
                        printf("%d %s\t%s\t%s\t%s %d/%d/%d\n", (*(ptrAgenda + i )).numTarea (*(ptrAgenda + i )).tarea, (*(ptrAgenda + i )).tema, (*(ptrAgenda + i )).materia, (*(ptrAgenda + i )).profesor, (*(ptrAgenda + i )).fechaEntrega.dia, (*(ptrAgenda + i )).fechaEntrega.mes, (*(ptrAgenda + i )).fechaEntrega.anio );
                    }
                }
                if()
                getValidInt("Ingrese numero de tarea: ","No es un numro valido.");


            case 4 :
                printf(" TAREA \t TEMA \t MATERIA PROFESOR \t FECHA DE ENTREGA \n\n");
                for( i = 0 ; i < CANT ; i++)
                {
                    if( (*(ptrAgenda + i )).estado == OCUPADO )
                    {
                        printf("%s\t%s\t%s\t%s %d/%d/%d\n", (*(ptrAgenda + i )).tarea, (*(ptrAgenda + i )).tema, (*(ptrAgenda + i )).materia, (*(ptrAgenda + i )).profesor, (*(ptrAgenda + i )).fechaEntrega.dia, (*(ptrAgenda + i )).fechaEntrega.mes, (*(ptrAgenda + i )).fechaEntrega.anio );
                    }
                }
                break;
            case 5 :
                exit = validateDualExit("Esta seguro que desea salir? s/n ","Respuesta invalida, reingrese: ",'s','n');
            }
        }
        system("pause");

    }
    printf("\n");
    return 0;

}


int buscarLibre(  )
{

}
