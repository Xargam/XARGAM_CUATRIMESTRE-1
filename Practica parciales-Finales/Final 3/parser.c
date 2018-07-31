#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xArrayList.h"
#include "xMessage.h"

int xpar_parseMessages( arrayList* lista , char* filePath )
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
            char popularidad[10];

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
                message_setPopularidad(msg,atoi(popularidad));

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



int xpar_parseUsers( arrayList* lista , char* filePath )
{
    int verify = 0;

    if( lista != NULL && filePath != NULL)
    {
        FILE* file = fopen(filePath,"r");
        if( file != NULL)
        {
            char userId[10];
            char nick[51];
            char popularidad[10];

            verify = 1;

            while( !feof(file) )
            {
                if( fscanf(file,"%[^;];%[^;];%[^\n]\n",campo1,campo15,campo3) != 3)
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

                eGenerica* gen = generica_newGenerica();

                if( gen == NULL)
                {
                    verify = 0;
                    break;
                }
                generica_setCampo1(gen,atoi(campo1));
                generica_setCampo15(gen,atol(campo15));
                generica_setCampo3(gen,campo3);
                lista->add(lista,gen);
            }
            if( fclose(file) )
            {
                verify = 0;
            }
        }
    }
    return verify ;
}


/*
int xpar_unparseGenerica( arrayList* lista, char* filePath )
{
    int verify = 0;
    if( lista != NULL && filePath != NULL )
    {
        FILE* file = fopen(filePath,"w");
        if( file != NULL )
        {
            verify = 1;
            int i;
            for( i = 0 ; i < lista->len(lista) ; i++)
            {
                if( fprintf(file,"%d;%ld;%s\n", generica_getCampo1( lista->get(lista,i) ), generica_getCampo15( lista->get(lista,i) ), generica_getCampo3( lista->get(lista,i)) ) < 0 )
                {
                    verify = 0;
                    break;
                }
            }
            if( fclose(file))
            {
                verify = 0;
            }
        }
    }
    return verify ;
}*/
