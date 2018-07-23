#include <stdio.h>
#include <stdlib.h>

#include "xParser.h"
#include "xLogs.h"
#include "xArrayList.h"


//Parsers:



/** \brief Parsea un archivo separado por comas con datos del tipo sLog. Luego carga los datos leidos en un arrayList.
 *
 * \param lista : Puntero a arrayList donde se cargaran los datos.
 * \param filePath : Ruta del archivo a parsear.
 * \return Devuelve [1] si el parseo se completo correctamente o [0] si hubo algun error.
 *
 */

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


/** \brief Parsea un archivo separado por comas con datos del tipo sService. Luego carga los datos leidos en un arrayList.
 S
 * \param lista : Puntero a arrayList donde se cargaran los datos.
 * \param filePath : Ruta del archivo a parsear.
 * \return Devuelve [1] si el parseo se completo correctamente o [0] si hubo algun error.
 *
 */

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
                if( fscanf(file,"%[^;];%[^;];%[^\n]\n",id,name,email) != 3 )
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
    return verify ;
}


//UnParsers:

/** \brief Deparsea un archivo de registro de errores de servicios.
 *
 * \param services : Array List con punteros del tipo sService.
 * \param log : Array List con punteros del tipo sLog.
 * \param filePath : Ruta donde se escribira el archivo.
 * \return Devuelve [1] si el parseo se completo correctamente o [0] si hubo algun error.
 *
 */

int xPar_unParseErrors( arrayList* services , arrayList* log , char* filePath )
{
    int verify = 0;


    if( services != NULL && log != NULL && filePath != NULL)
    {
        FILE* file = fopen(filePath,"w");
        if( file != NULL )
        {
            verify = 1;
            int i;
            int j;
            for( i = 0 ; i < log->len(log) ; i++ )
            {
                for( j = 0 ; j < services->len(services) ; j++)
                {
                    if( log_getServiceId( log->get(log,i) ) == service_getId( services->get(services,j) ) )
                    {
                        fprintf(file,"%s;%s;%s;%s;%s\n", log_getDate( log->get(log,i) ) , log_getTime( log->get(log,i) ) , service_getName( services->get(services,j) ) , log_getMsg( log->get(log,i) ) , service_getEmail( services->get(services,j) ) );
                        break;
                    }
                }
            }
            if( fclose(file) )
            {
                verify = 0;
            }
        }
    }
    return verify;
}
