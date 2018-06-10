#include <stdio.h>
#include <stdlib.h>

#include "xPerson.h"
#include <string.h>
#include "xlook.h"
#include "xget.h"
#include "xvalidate.h"
#include "xstring.h"
#include "xvector.h"
#include "xget.h"
#include "xPerson.h"
#define CANT 20

int main()
{
    ePerson people[CANT];
    initializePersons(people, CANT);
    //hardcode(people);


    int selection;
    int exit = 0;
    int functionValueReceiver;

    do
    {
        system("cls");
        xlkIndexGenerator("(PREMIUM) PEOPLE MANAGER SOFT V3.0.1   ||   LEONARDO MANASSALI 1A",5,"1-Agregar una persona.","2-Borrar una persona.","3-Imprimir lista ordenada por nombre.","4-Imprimir grafico de edades.","5-Salir.");
        selection = getRangedInt(1,5," -Seleccionar opcion: "," ERROR: opcion invalida.\n\n -Seleccionar opcion: ");
        switch(selection)
        {
        case 1:
            printf("\n *Agregar una persona: \n");
            functionValueReceiver = newPerson(people,CANT);
            if(functionValueReceiver == 1)
            {
                printf("\n\nPersona agregada al sistema.\n\n");
            }
            else if(functionValueReceiver == 0)
            {
                printf("\n\nYa existe una persona con ese DNI en el sistema.\n\n");
            }
            else if(functionValueReceiver == -1)
            {
                printf("\n\nNo hay espacio para agregar mas personas.\n\n");
            }
            break;
        case 2:
            printf("\n *Borrar una persona: \n");

            functionValueReceiver = deletePerson(people,CANT);
            if(functionValueReceiver == 1)
            {
                printf("\n\nPersona borrada del sistema.\n\n");
            }
            else if(functionValueReceiver == 0)
            {
                printf("\n\nAccion cancelada. No se ha dado de baja a ninguna persona.\n\n");
            }
            else if(functionValueReceiver == -1)
            {
                printf("\n\nNo se ha encontrado a la persona.\n\n");
            }
            break;
        case 3:
            sortPeople(people,CANT);
            showPeople(people,CANT);
            break;
        case 4:
            functionValueReceiver = graph(people,CANT);
            if(functionValueReceiver == 0)
            {
                printf("\n\nNo hay personas cargadas en el sistema.\n\n");
            }
            break;
        case 5:
            exit = validateDualExit("\nEsta seguro que desea salir? s/n  :\n","Error: respuesta incorrecta. Reingrese: ",'s','n');
            if(exit == 1)
            {
                system("cls");
                printf("Programa apagado.\n");
            }
            printf("\n");
            break;
        }
        system("pause");
    }
    while(exit == 0);
    return 0;
}
