#include <stdio.h>
#include <stdlib.h>

#include "xlook.h"
#include "xArrayList.h"
#include "xMessage.h"
#include "parser.h"
#include "xUser.h"

int main()
{
    arrayList* mensajes = al_newArrayList();
    arrayList* usuarios = al_newArrayList();

    if(mensajes == NULL || usuarios == NULL)
    {
        exit(EXIT_FAILURE);
    }

    xpar_parseMessages(mensajes,"mensajes.csv");
    xpar_parseUsers(usuarios,"usuarios.csv");

    xlkLinePrinter(0);
    for(int i = 0 ; i < usuarios->len(usuarios) ; i++)
    {
        xlkSortPrintf(0,100,"%d,%s,%ld",1, user_getId( usuarios->get(usuarios,i)) , user_getNick(usuarios->get(usuarios,i)) , user_getPopularidad(usuarios->get(usuarios,i)) );
    }
    printf("UNPARSER: %d ", xpar_unparseFeed(usuarios,mensajes,"feed.csv"));
    return 0;
}
