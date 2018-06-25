#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xget.h"
#include "xFiles.h"
#include "xlook.h"
#include "xGenericStruct.h"
#include "xArrayList.h"
#include "xvalidate.h"
#include "xEmail.h"


/*
Desarrollar en ANSI C:
Una compañía de servicios de marketing por correo electrónico requiere una
aplicación que permita depurar una lista de destinatarios, la cual se encuentran en un
archivo de texto del tipo csv. La aplicación deberá permitir seleccionar el archivo de
destinatarios, el archivo de lista negra (personas que no deben recibir el mail) y al
elegir la opción depurar generar una nueva lista que contenga todos los destinatarios
que no se encuentran en la lista negra.
Opciones del sistema
1. CARGAR DESTINATARIOS: Se solicita al usuario el nombre del archivo de
destinatarios y se carga el arrayList de destinatarios.
2. CARGAR LISTA NEGRA: Se solicita al usuario el nombre del archivo de lista
negra y se carga el arrayList de destinatarios.
3. DEPURAR: Genera una nueva lista que contenga todos los destinatarios que
no se encuentran en la lista negra y elimina los destinatarios repetidos.
4. LISTAR : En esta opción se listan a las personas que les sera enviado el
correo.
Nota 1: El código deberá tener comentarios con la documentación de cada una de las funciones y
respetar las reglas de estilo de la cátedra.
Nota 1: Se deberá utilizar la biblioteca arrayList.
*/

int main()
{
    int selection;
    char filename[301];
    int quit = 0;
    int i;
    int j;

    arrayList* destinatarios = al_newArrayList();
    arrayList* depuracion = al_newArrayList();

    if( depuracion == NULL || destinatarios == NULL)
    {
        xlkShowMessage(XLK_MEM_ERROR,0,0,3);
    }

    do
    {
        xlkIndexGenerator("DEPURAR DESTINATARIOS",5,"1-Cargar destinatarios.","2-Cargar lista negra.","3-Depurar.","4-Listar.","5-Salir.");
        if( getRangedInt(&selection,1,5,"Seleccionar opcion: ","Opcion invalida.") )
        {
            system("cls");
            switch(selection)
            {
            case 1:
                if( getRangedStr(filename,1,300,"Ingrese el nombre del archivo de destinatarios: ","El nombre de archivo es invalido.",1) )
                {
                    if( strcmp(filename,"destinatarios.csv") == 0 )
                    {
                        xlkShowMessage(XLK_VALID_FILE,1,1,-1);
                        if( xmailParser(filename,destinatarios) )
                        {
                            xlkShowMessage(XLK_PARSER_OK,0,1,-1);
                            xlkShowMessage("Destinatarios cargados con exito.",0,2,-1);
                        }
                        else
                        {
                            xlkShowMessage(XLK_PARSER_ERROR,0,2,-1);
                        }
                    }
                    else
                    {
                        xlkShowMessage(XLK_INVALID_FILE,0,2,-1);
                    }
                }
                break;
            case 2:
                if( getRangedStr(filename,1,300,"Ingrese el nombre del archivo de destinatarios en lista negra: ","El nombre de archivo es invalido.",1) )
                {
                    if( strcmp(filename,"lista negra.csv") == 0 )
                    {
                        xlkShowMessage(XLK_VALID_FILE,1,1,-1);
                        if( xmailParser(filename,destinatarios) )
                        {
                            xlkShowMessage(XLK_PARSER_OK,0,1,-1);
                            xlkShowMessage("Destinatarios en lista negra cargados con exito.",0,2,-1);
                        }
                        else
                        {
                            xlkShowMessage(XLK_PARSER_ERROR,0,2,-1);
                        }
                    }
                    else
                    {
                        xlkShowMessage(XLK_INVALID_FILE,0,2,-1);
                    }
                }
                break;
            case 3:
                for( i = 0 ; i < destinatarios->len(destinatarios)-1 ; i++)
                {
                    for( j = 0 ; j < destinatarios->len(destinatarios) ; j++ )
                    {
                        if( xmailComparaEmail( destinatarios->get(destinatarios,i) ,  ) )
                    }
                    if( destinatarios->contains(destinatarios, destinatarios->get(destinatarios, i)) < 2 )
                    {
                        depuracion->add(depuracion,destinatarios->get(destinatarios, i));
                    }
                }
                break;
            case 4:
                if( depuracion->len(depuracion) > 0)
                {
                    xlkCenterPrintf("LISTA DE DESTINATARIOS",2);
                    for(i = 0 ; i < depuracion->len(depuracion) ; i++ )
                    {
                        printf("I %d\n",i);
                        xmailMostrarDestinatario(depuracion->get(depuracion,i) );
                    }
                }
                else if( destinatarios->len(destinatarios) > 0)
                {
                    xlkCenterPrintf("LISTA DE DESTINATARIOS",2);
                    for(i = 0 ; i < destinatarios->len(destinatarios) ; i++ )
                    {
                        printf("I %d\n",i);
                        xmailMostrarDestinatario(destinatarios->get(destinatarios,i) );
                    }
                }
                else
                {
                    xlkShowMessage("No hay destinatarios cargados.",0,2,-1);
                }

                break;
            case 5:
                system("cls");
                quit = validateDualExit(XLK_EXITMSG,XLK_INVALID_ANSWER,'s','n');
                xlkEnterPrinter(2);
                break;
            }
        }
        system("pause");
    }
    while(quit == 0);

    generic2_PointerDestroyer(destinatarios->pElements,destinatarios->len(destinatarios));
    destinatarios->deleteArrayList(destinatarios);
    return 0;
}
