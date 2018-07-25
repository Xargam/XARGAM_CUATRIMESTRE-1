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

    if( services == NULL || log == NULL )
    {
        printf("%s\n\n",XLK_MEM_ERROR);
        system("pause");
        exit(EXIT_FAILURE);
    }

    int selection;
    int quit = 0;

    do
    {
        xlkIndexGenerator("Log SERVER 010",3,"1-Leer log.","2-Procesar informacion.","3-Mostrar estadisticas.");
        if( getRangedInt(&selection,0,3,"Seleccionar opcion: ","Opcion invalida.") )
        {
            system("cls");
            switch(selection)
            {
            case 1:
                xPar_parseServices(services,"services.txt");
                xPar_parseLog(log,"log.txt");
                printf("* Informacion leida.");
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            }
        }
        xlkEnterPrinter(2);
        system("pause");
    }
    while(quit == 0);

    return 0;
}

