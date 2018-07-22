#include <stdio.h>
#include <stdlib.h>

#include "xParser.h"
#include "xLogs.h"

int xPar_parseLog( arrayList* lista, char* filePath )
{
    int verify = 0;

    if( lista != NULL && filePath != NULL)
    {
        FILE* file = fopen(filePath,"r");
        if( file != NULL)
        {
            char date[11];
            char time[6];
            char serviceId[7];
            char gravedad[7];
            char msg[65];

            verify = 1;

            while( !feof(file) )
            {
                if( fscanf(file,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",date,time,serviceId,gravedad,msg) != 5)
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

                sLog* log = log_newLog();

                if( log == NULL)
                {
                    verify = 0;
                    break;
                }
                log_setDate(log,date);
                log_setTime(log,time);
                log_setServiceId(log,atoi(serviceId));
                log_setGravedad(log,atoi(gravedad));
                log_setMsg(log,msg);
                lista->add(lista,log);
            }
            if( fclose(file) )
            {
                verify = 0;
            }
        }
    }

    return verify ;
}



int xPar_parseServices( arrayList* lista, char* filePath )
{
    int verify = 0;
    if( lista != NULL && filePath != NULL )
    {
        FILE* file = fopen(filePath,"r");
        if( file != NULL )
        {
            char id[7];
            char email[64];
            char name[32];

            verify = 1;

            while( !feof(file) )
            {
                if( fscanf(file,"%[^;];%[^;];%[^;]\n",id,name,email) != 3 )
                {
                    if( feof(file) )
                    {
                        break;
                    }
                    else
                    {
                        verify = 0;
                        break;
                    }

                    sService* service = service_newService();
                    if( service == NULL )
                    {
                        verify = 0;
                        break;
                    }
                    service_setId(service,atoi(id));
                    service_setName(service,name);
                    service_setEmail(service,email);

                    lista->add(lista,service);
                }
                if( fclose(file))
                {
                    verify = 0;
                }
            }

        }
    }
    return verify ;
}
