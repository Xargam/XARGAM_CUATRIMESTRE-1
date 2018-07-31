#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xMessage.h"
#include "xvalidate.h"



/** \brief Reserva espacio dinamico para un puntero del tipo de dato sUser e inicializa sus campos.
 *
 * \param
 * \return Devuelve un puntero a una estructura del tipo de dato sUser , en caso de error un puntero a NULL.
 *
 */

sMessage* message_newMessage(void)
{
    sMessage* message = (sMessage*)malloc(sizeof(sMessage));
    if( message != NULL )
    {
        strcpy(message->message, "");
        message->popularidad = 0;
        message->userId = 0;
        message->messageId = 0;
    }
    return message;
}



/** \brief Setea el campo ID en un puntero al tipo de dato sUser .
 *
 * \param message : Puntero donde setear ID.
 * \param id : ID a setear en la estructura.
 * \return Devuelve [1] si el dato fue seteado correctamente o [0] en caso de error .
 *
 */

int message_setId( sMessage* message , int id )
{
    int verify = 0;
    if( message != NULL )
    {
        if(validateIntCondition(id,1,1) )
        {
            verify = 1;
            message->messageId = id;
        }
    }
    return verify;
}



/** \brief Obtiene el dato ID de un puntero al tipo de dato sUser .
 *
 * \param message : Puntero de donde obtener el dato ID .
 * \return Devuelve el dato correspondiente al atributo de la estructura .
 *
 */

int message_getId( sMessage* message )
{
    return message->messageId;
}



/** \brief Setea el campo NICK en un puntero al tipo de dato sUser .
 *
 * \param message : Puntero donde setear NICK .
 * \param nick : NICK a setear en la estructura.
 * \return Devuelve [1] si el dato fue seteado correctamente o [0] en caso de error .
 *
 */

int message_setMessage( sMessage* message , char* msg )
{
    int verify = 0;
    if( message != NULL && msg != NULL)
    {
        if( validateStringRange(msg,1,3500) )
        {
            verify = 1;
            strcpy(message->message , msg);
        }
    }
    return verify;
}



/** \brief Obtiene el dato NICK de un puntero al tipo de dato sUser .
 *
 * \param message : Puntero de donde obtener el dato NICK .
 * \return Devuelve el dato correspondiente al atributo de la estructura .
 *
 */

char* message_getMessage( sMessage* message )
{
    return message->message;
}


/** \brief Setea el campo popularidad en un puntero al tipo de dato sUser .
 *
 * \param message : Puntero donde setear popularidad .
 * \param popularidad : popularidad a setear en la estructura.
 * \return Devuelve [1] si el dato fue seteado correctamente o [0] en caso de error .
 *
 */

int message_setUserId( sMessage* message , int userId )
{
    int verify = 0;
    if( message != NULL )
    {
        if(validateIntCondition(userId,1,1) )
        {
            verify = 1;
            message->userId = userId;
        }
    }
    return verify;
}



/** \brief Obtiene el dato popularidad de un puntero al tipo de dato sUser .
 *
 * \param message : Puntero de donde obtener el dato popularidad.
 * \return Devuelve el dato correspondiente al atributo de la estructura .
 *
 */

int message_getUserId( sMessage* message )
{
    return message->userId;
}



/** \brief Setea el campo popularidad en un puntero al tipo de dato sUser .
 *
 * \param message : Puntero donde setear popularidad .
 * \param popularidad : popularidad a setear en la estructura.
 * \return Devuelve [1] si el dato fue seteado correctamente o [0] en caso de error .
 *
 */

int message_setPopularidad( sMessage* message , int popularidad )
{
    int verify = 0;
    if( message != NULL )
    {
        if(validateIntCondition(popularidad,0,1) )
        {
            verify = 1;
            message->popularidad = popularidad;
        }
    }
    return verify;
}



/** \brief Obtiene el dato popularidad de un puntero al tipo de dato sUser .
 *
 * \param message : Puntero de donde obtener el dato popularidad.
 * \return Devuelve el dato correspondiente al atributo de la estructura .
 *
 */

int message_getPopularidad( sMessage* message )
{
    return message->popularidad;
}

