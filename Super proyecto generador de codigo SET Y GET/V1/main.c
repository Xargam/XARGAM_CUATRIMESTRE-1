#include <stdio.h>
#include <stdlib.h>

#include "xlook.h"
#include "xget.h"
#include "xstring.h"
typedef struct
{
    char date[11];
    char time[6];
    int serviceId;
    int gravedad;
    char msg[65];

} sLog;

void structRecognizer(char* structDeclaration );

int main()
{
    int selection;
    int quit = 0;
    char estructura[500];
    do
    {
        xlkIndexGenerator("LEONARDO MANASSALI - GENERADOR DE FUNCIONES SET  Y GET - PARCIALES - FINALES",2,"1-Generar archivo.","2-Salir.");
        printf("%s", estructura);
        system("pause");
        if( getRangedInt(&selection,1,2,"Seleccionar opcion: ","Opcion incorrecta."));
        {
            system("cls");
            switch(selection)
            {
            case 1:
                getRangedStr(estructura,0,499,"FORMATO DE DECLARACION ADMITIDO: \n\ntypedef struct\n{\n    int campo1\n    char campo2[100]\n\n}eEstructura;\n\n* Para reconocer la estructura y sus tipos de datos pegue la declaracion aqui:\n","Error.",1);
                printf("%s", estructura);
                system("pause");

                break;
            case 2:
                break;
            }

            xlkEnterPrinter(2);
            system("pause");
        }
    }
    while( quit == 0 );

    return 0;
}


void structRecognizer(char* structDeclaration )
{

}
