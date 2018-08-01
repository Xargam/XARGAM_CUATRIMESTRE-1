#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xArrayList.h"
#include "xMessage.h"
#include "xUser.h"

int xpar_parseMessages( arrayList* lista, char* filePath )
{
    int verify = 0;

    if( lista != NULL && filePath != NULL)
    {
        FILE* file = fopen(filePath,"r");
        if( file != NULL)
        {
            char message[3501];
            char msgId[10];
            char userId[10];
            char popularidad[15];

            verify = 1;

            while( !feof(file) )
            {
                if( fscanf(file,"%[^,],%[^,],%[^,],%[^\n]\n",msgId,userId,popularidad,message) != 4)
                {
                    if( feof(file))
                    {
                        break;
                    }
                    else
                    {
                        verify = 0;
                        break;
                    }
                }

                sMessage* msg = message_newMessage();

                if( msg == NULL)
                {
                    verify = 0;
                    break;
                }
                message_setId(msg,atoi(msgId));
                message_setMessage(msg,message);
                message_setUserId(msg,atoi(userId));
                message_setPopularidad(msg,atol(popularidad));

                lista->add(lista,msg);
            }
            if( fclose(file) )
            {
                verify = 0;
            }
        }
    }
    return verify ;
}



int xpar_parseUsers( arrayList* lista, char* filePath )
{
    int verify = 0;

    if( lista != NULL && filePath != NULL)
    {
        FILE* file = fopen(filePath,"r");
        if( file != NULL)
        {
            char userId[10];
            char nick[51];
            char popularidad[15];

            verify = 1;

            while( !feof(file) )
            {
                if( fscanf(file,"%[^,],%[^,],%[^\n]\n",userId,nick,popularidad) != 3)
                {
                    if( feof(file))
                    {
                        break;
                    }
                    else
                    {
                        verify = 0;
                        break;
                    }
                }

                sUser* user = user_newUser();

                if( user == NULL)
                {
                    verify = 0;
                    break;
                }
                user_setId(user, atoi(userId) );
                user_setNick(user,nick);
                user_setPopularidad(user,atol(popularidad));

                lista->add(lista,user);
            }
            if( fclose(file) )
            {
                verify = 0;
            }
        }
    }
    return verify ;
}



int xpar_unparseFeed( arrayList* usuarios, arrayList* mensajes, char* filePath )
{
    int verify = 0;
    if( usuarios != NULL && mensajes != NULL &&filePath != NULL )
    {
        FILE* file = fopen(filePath,"w");
        if( file != NULL )
        {
            verify = 1;
            int i, j;
            for( i = 0 ; i < usuarios->len(usuarios) && verify == 1 ; i++)
            {
                for(j = 0 ; j < mensajes->len(mensajes) ; j++)
                {
                    if( message_getUserId( mensajes->get(mensajes,j) ) == user_getId( usuarios->get(usuarios,i) ) )
                    {
                        if( fprintf(file,"%d,%s,%ld,%d,%s,%ld\n", message_getId( mensajes->get(mensajes,j) ) , message_getMessage( mensajes->get(mensajes,j) ) , message_getPopularidad(mensajes->get(mensajes,j)), message_getUserId( mensajes->get(mensajes,j) ) , user_getNick( usuarios->get(usuarios,i) ) , user_getPopularidad( usuarios->get(usuarios,i))) < 0 )
                        {
                            verify = 0;
                            break;
                        }
                    }
                }
            }
            if( fclose(file))
            {
                verify = 0;
            }
        }
    }
    return verify ;
}
