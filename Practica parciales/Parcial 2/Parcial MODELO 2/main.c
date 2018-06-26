#include <stdio.h>
#include <stdlib.h>
#include "xget.h"
#include "xlook.h"

#include "xArrayList.h"

/*
Una compañía desea mejorar su servicio de atención al cliente para lo cual decide
desarrollar un sistema de organización de espera. Dicha empresa cuenta con dos
tipos de tramites, los urgentes y los regulares. Los tramites urgentes deben tener
prioridad de atención por sobre los regulares. Modo de proceder de los clientes:
1. El cliente selecciona la operación a realizar y registra su DNI.
• TRAMITE URGENTE
• TRAMITE REGULAR
2. Luego de obtener un turno, el cliente espera a ser llamado.
Opciones del sistema
1. TRAMITE URGENTE: Se otorga un numero de turno para los tramites
urgentes.
2. TRAMITE REGULAR: Se otorga un numero de turno para los tramites
regulares.
3. PROXIMO CLIENTE: El sistema le indicara al usuario quien es el próximo turno
a ser atendido y a que tramite corresponde.
4. LISTAR : En esta opción se listan las personas pendientes de ser atendidas en
cada tramite.
5. INFORMAR:
◦ Los clientes atendidos en cada uno de los tramites ordenados por DNI
de manera descendente.
*/

int main()
{
    int selection;
    int quit = 0;
    arrayList* tramiteRegular = al_newArrayList();
    arrayList* tramiteUrgente = al_newArrayList();
    if( tramiteRegular == NULL || tramiteUrgente == NULL)
    {
        xlkShowMessage(XLK_MEM_ERROR,0,0,3);
    }

    do
    {
        xlkIndexGenerator("TURNO SOFT V1.0.0",6,"1* Tramite urgente.","2* Tramite regular.","3* Proximo cliente.","4* Listar.","5* Informar.","6*  Salir.");
        if( getValidInt(&selection,"Seleccionar opcion: ","Opcion invalida.") )
        {
            system("cls");
            switch(selection)
            {
            case 1:

                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            }
        }
        system("pause");
    }
    while( quit == 0);


    return 0;
}
