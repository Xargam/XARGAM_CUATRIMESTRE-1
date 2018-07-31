#include <stdio.h>
#include <stdlib.h>

#include "xlook.h"
#include "xArrayList.h"
#include "xMessage.h"
#include "parser.h"

int main()
{
    arrayList* mensajes = al_newArrayList();
    arrayList* usuarios = al_newArrayList();

    if(mensajes == NULL || usuarios == NULL)
    {
        exit(EXIT_FAILURE);
    }

    xpar_parseMessages(mensajes,"mensajes.csv");

    xlkLinePrinter(0);
    for(int i = 0 ; i < mensajes->len(mensajes) ; i++)
    {
        xlkSortPrintf(0,100,"%s,%s,%s",1,"Id de mensaje:","Id de usuario:","Popularidad:");
        xlkSortPrintf(0,1000,"%d%d%d",1,message_getId( mensajes->get(mensajes,i) ),message_getUserId(mensajes->get(mensajes,i)), message_getPopularidad(mensajes->get(mensajes,i)));
        xlkSortPrintf(0,100,"%s",1,"Mensaje:" );
        xlkSortPrintf(0,5000,"%s",1, message_getMessage( mensajes->get(mensajes,i)));

    }
    return 0;
}
