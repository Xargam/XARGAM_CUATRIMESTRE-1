#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xLogs.h"
#include "xvalidate.h"
#include "xlook.h"

//ESTRUCTURA sLog

//Muestra



/** \brief Muestra datos de un puntero a estructura del tipo sLog.
 *
 * \param log : Puntero a estructura del tipo log a mostrar.
 * \param service : Servicio asociado al log a mostrar.
 * \return Devuelve [1] si la estructura se mostró o [0] si hubo un error y no se pudo realizar la accion.
 *
 */

int log_show(sLog* log, sService* service )
{
    int verify = 0;
    if( log != NULL && service != NULL )
    {
        verify = 1;
        xlkSortPrintf("%s,%s,%s,%s,%d",1,log->date,log->time,service->name,log->msg,log->gravedad);
    }
    return verify;
}



//Constructor



/** \brief Reserva espacio dinamico para una estructura del tipo sLog.
 *
 * \param
 * \return Devuelve la estructura si la memoria fue reservada correctamente o NULL en caso de error.
 *
 */

sLog* log_newLog(void)
{
    sLog* log = (sLog*) malloc(sizeof(sLog));
    if(log != NULL)
    {
        strcpy( log->date, "" );
        strcpy( log->time, "" );
        strcpy( log->msg, "" );
        log->gravedad = 0;
        log->serviceId = 0;
    }
    return log;
}



//Setters



/** \brief Setea el campo date (fecha) de un puntero al tipo de dato sLog.
 *
 * \param log : Puntero a sLog donde setear el dato.
 * \param date : Cadena con fecha a setear.
 * \return Devuelvo [1] si el dato fue seteado correctamente o [0] en caso contrario.
 *
 */

int log_setDate( sLog* log, char* date )
{
    int verify = 0;
    if( date != NULL && log != NULL)
    {
        if( validateStringRange(date,6,10) )
        {
            strcpy( log->date, date);
            verify = 1;
        }
    }
    return verify;
}



/** \brief Setea el campo time (hora) de un puntero al tipo de dato sLog.
 *
 * \param log : Puntero a sLog donde setear el dato.
 * \param time : Cadena con horario a setear.
 * \return Devuelvo [1] si el dato fue seteado correctamente o [0] en caso contrario.
 *
 */

int log_setTime( sLog* log, char* time )
{
    int verify = 0;
    if( time != NULL && log != NULL)
    {
        if( validateStringRange(time,4,5) && validateIsCorrectTime(time,0) )
        {
            strcpy( log->time, time);
            verify = 1;
        }
    }
    return verify;
}



/** \brief Setea el campo serviceId ( id de servicio ) de un puntero al tipo de dato sLog.
 *
 * \param log : Puntero a sLog donde setear el dato.
 * \param id : Entero con id a setear.
 * \return Devuelvo [1] si el dato fue seteado correctamente o [0] en caso contrario.
 *
 */

int log_setServiceId( sLog* log, int id )
{
    int verify = 0;
    if( log != NULL)
    {
        if( validateIntCondition(id,1,1) )
        {
            log->serviceId = id;
            verify = 1;
        }
    }
    return verify;
}



/** \brief Setea el campo gravedad de un puntero al tipo de dato sLog.
 *
 * \param log : Puntero a sLog donde setear el dato.
 * \param gravedad : Entero con gravedad a setear.
 * \return Devuelvo [1] si el dato fue seteado correctamente o [0] en caso contrario.
 *
 */

int log_setGravedad( sLog* log, int gravedad )
{
    int verify = 0;
    if( log != NULL)
    {
        if( validateIntRange(gravedad,0,9) )
        {
            log->gravedad = gravedad;
            verify = 1;
        }
    }
    return verify;
}



/** \brief Setea el campo msg de un puntero al tipo de dato sLog.
 *
 * \param log : Puntero a sLog donde setear el dato.
 * \param message : Cadena con mensaje de error a setear.
 * \return Devuelvo [1] si el dato fue seteado correctamente o [0] en caso contrario.
 *
 */

int log_setMsg( sLog* log, char* message )
{
    int verify = 0;
    if( log != NULL && message != NULL)
    {
        if( validateStringRange(message,1,64) )
        {
            strcpy(log->msg, message);
            verify = 1;
        }
    }
    return verify;
}



//Getters:



/** \brief Obtiene la fecha de un puntero al tipo de dato sLog.
 *
 * \param Puntero a sLog de donde obtener el dato.
 * \return Devuelve una cadena con el dato correspondiente.
 *
 */

char* log_getDate( sLog* log )
{
    return log->date;
}



/** \brief Obtiene la hora de un puntero al tipo de dato sLog.
 *
 * \param Puntero a sLog de donde obtener el dato.
 * \return Devuelve una cadena con el dato correspondiente.
 *
 */

char* log_getTime( sLog* log )
{
    return log->time;
}



/** \brief Obtiene el serviceId de un puntero al tipo de dato sLog.
 *
 * \param Puntero a sLog de donde obtener el dato.
 * \return Devuelve un entero con el dato correspondiente.
 *
 */

int log_getServiceId( sLog* log )
{
    return log->serviceId;
}



/** \brief Obtiene la gravedad de un puntero al tipo de dato sLog.
 *
 * \param Puntero a sLog de donde obtener el dato.
 * \return Devuelve un entero con el dato correspondiente.
 *
 */

int log_getGravedad( sLog* log )
{
    return log->gravedad;
}



/** \brief Obtiene el msg (mensaje de error) de un puntero al tipo de dato sLog.
 *
 * \param Puntero a sLog de donde obtener el dato.
 * \return Devuelve una cadena con el dato correspondiente.
 *
 */

char* log_getMsg( sLog* log )
{
    return log->msg;
}



//ESTRUCTURA sServices

//Muestra



/** \brief Muestra datos de un puntero a estructura del tipo sService.
 *
 * \param service : Puntero a estructura del tipo service a mostrar.
 * \return Devuelve [1] si la estructura se mostró o [0] si hubo un error y no se pudo realizar la accion.
 *
 */

int service_show(sService* service)
{
    int verify = 0;
    if( service != NULL )
    {
        verify = 1;
        xlkSortPrintf("%d,%s,%s",1,service->id,service->name,service->email);
    }
    return verify;

}


//Constructor y destructor:



/** \brief Reserva espacio dinamico para una estructura del tipo sService.
 *
 * \param
 * \return Devuelve la estructura si la memoria fue reservada correctamente o NULL en caso de error.
 *
 */

sService* service_newService(void)
{
    sService* service = (sService*) malloc(sizeof(sService));
    if(service != NULL)
    {
        strcpy( service->name, "" );
        strcpy( service->email, "" );
        service->id = 0;
    }
    return service;
}



//Setters:



/** \brief Setea el campo id de un puntero al tipo de dato sService.
 *
 * \param service : Puntero a sService donde setear el dato.
 * \param id : Entero con id a setear.
 * \return Devuelvo [1] si el dato fue seteado correctamente o [0] en caso contrario.
 *
 */

int service_setId( sService* service, int id )
{
    int verify = 0;
    if( service != NULL)
    {
        if( validateIntCondition(id,1,1) )
        {
            service->id = id;
            verify = 1;
        }
    }
    return verify;
}



/** \brief Setea el campo name de un puntero al tipo de dato sService.
 *
 * \param service : Puntero a sService donde setear el dato.
 * \param name : Cadena con nombre a setear.
 * \return Devuelvo [1] si el dato fue seteado correctamente o [0] en caso contrario.
 *
 */

int service_setName( sService* service, char* name )
{
    int verify = 0;
    if( name != NULL && service != NULL)
    {
        if( validateStringRange(name,1,32) )
        {
            strcpy( service->name, name);
            verify = 1;
        }
    }
    return verify;
}



/** \brief Setea el campo email de un puntero al tipo de dato sService.
 *
 * \param service : Puntero a sService donde setear el dato.
 * \param email : Cadena con email a setear.
 * \return Devuelvo [1] si el dato fue seteado correctamente o [0] en caso contrario.
 *
 */

int service_setEmail( sService* service, char* email )
{
    int verify = 0;
    if( email != NULL && service != NULL)
    {
        if( validateStringRange(email,4,64) )
        {
            strcpy( service->email, email);
            verify = 1;
        }
    }
    return verify;
}



//Getters




/** \brief Obtiene el id de un puntero al tipo de dato sService.
 *
 * \param Puntero a sLog de donde obtener el dato.
 * \return Devuelve un entero con el dato correspondiente.
 *
 */

int service_getId( sService* service)
{
    return service->id;
}



/** \brief Obtiene el nombre de un puntero al tipo de dato sService.
 *
 * \param Puntero a sService de donde obtener el dato.
 * \return Devuelve una cadena con el dato correspondiente.
 *
 */

char* service_getName( sService* service )
{
    return service->name;
}



/** \brief Obtiene el email de un puntero al tipo de dato sService.
 *
 * \param Puntero a sService de donde obtener el dato.
 * \return Devuelve una cadena con el dato correspondiente.
 *
 */

char* service_getEmail( sService* service )
{
    return service->email;
}
