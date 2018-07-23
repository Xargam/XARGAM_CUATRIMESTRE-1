#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "xget.h"
#include "xlook.h"
#include "xLogs.h"
#include "xParser.h"
#include "xFiles.h"
#include "xvalidate.h"


int main()
{
    arrayList* services = al_newArrayList();
    arrayList* log = al_newArrayList();
    arrayList* warnings = al_newArrayList();
    arrayList* errors = al_newArrayList();

    int erroresMenos3 = 0;
    int errores3 = 0;
    int errores4a7 = 0;
    int erroresMas7 = 0;

    int contadorFallos = 0;
    int maxFallos = 0;
    void* servicioMasFallos;

    if( services == NULL || log == NULL || warnings == NULL || errors == NULL )
    {
        printf("%s\n\n",XLK_MEM_ERROR);
        system("pause");
        exit(EXIT_FAILURE);
    }

    int selection;
    int quit = 0;
    int i;
    int j;

    do
    {
        xlkIndexGenerator("Log SERVER 010",4,"1-Leer log.","2-Procesar informacion.","3-Mostrar estadisticas.","4-Salir.");
        if( getRangedInt(&selection,0,4,"Seleccionar opcion: ","Opcion invalida.") )
        {
            system("cls");
            switch(selection)
            {
            case 1:
                xPar_parseServices(services,"services.txt");
                xPar_parseLog(log,"log2.txt");
                printf("* Informacion leida.");
                break;
            case 2:
                xlkCenterPrintf("Errores de gravedad 4 a 7:",2);
                xlkSortPrintf("%s,%s,%s,%s,%s",1,"Fecha:","Hora:","Nombre del servicio:","Mensaje de error:","Gravedad:");
                for( i = 0 ; i < log->len(log) ; i++ )
                {
                    if( log_getGravedad( log->get(log,i)) < 3  )
                    {
                        erroresMenos3++;
                    }
                    else if( log_getGravedad( log->get(log,i) ) == 3 && log_getServiceId( log->get(log,i) ) != 45)
                    {
                        errores3++;
                        warnings->add(warnings, log->get(log,i) );
                    }
                    else if( log_getGravedad( log->get(log,i) ) > 3 && log_getGravedad( log->get(log,i) ) < 8 )
                    {
                        errores4a7++;
                        for( j = 0 ; j < services->len(services) ; j++)
                        {
                            if( service_getId(services->get(services,j) ) == log_getServiceId( log->get(log,i) ) )
                            {
                                log_show(log->get(log,i), services->get(services,j) );
                            }
                        }
                    }
                    else if( log_getGravedad( log->get(log,i) )> 7 )
                    {
                        erroresMas7++;
                        errors->add(errors,log->get(log,i));
                    }
                }
                xPar_unParseErrors(services,errors,"errors.txt");
                xPar_unParseErrors(services,warnings,"warnings.txt");
                break;
            case 3:
                for( i = 0 ; i < services->len(services) ; i++ )
                {
                    for( j = 0 ; j < log->len(log) ; j++ )
                    {
                        if( log_getServiceId( log->get(log,j) ) == service_getId( services->get(services,i) ) )
                        {
                            contadorFallos++;
                        }
                        if( ( i == 0 || contadorFallos > maxFallos ) && j == log->len(log)-1 )
                        {
                            servicioMasFallos = services->get(services,i);
                            maxFallos = contadorFallos;
                        }
                    }
                    contadorFallos = 0;
                }
                xlkCenterPrintf("SERVICIO CON MAS FALLOS: ",2);
                xlkSortPrintf("%s,%s,%s",1,"Id del servicio:","Nombre del servicio: ","Email de soporte:");
                service_show(servicioMasFallos);
                xlkSortPrintf("%s,%s,%s,%s",2,"Fallos de gravedad menor a 3:","Fallos de gravedad 3:","Fallos de gravedad de 4 a 7:","Fallos de gravedad mayor a 7:");
                xlkSortPrintf("%d,%d,%d,%d",2,erroresMenos3,errores3,errores4a7,erroresMas7);
                break;
            case 4:
                quit = validateDualExit(XLK_EXITMSG,XLK_INVALID_ANSWER,'s','n');
                break;
            }
        }
        xlkEnterPrinter(2);
        system("pause");
    }
    while(quit == 0);
    services->deleteArrayList(services);
    services->deleteArrayList(log);
    services->deleteArrayList(warnings);
    services->deleteArrayList(errors);
    return 0;
}

