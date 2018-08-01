#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xUser.h"
#include "xvalidate.h"


/** \brief Reserva espacio dinamico para un puntero del tipo de dato sUser e inicializa sus campos.
 *
 * \param
 * \return Devuelve un puntero a una estructura del tipo de dato sUser , en caso de error un puntero a NULL.
 *
 */

sUser* user_newUser(void)
{
    sUser* user = (sUser*)malloc(sizeof(sUser));
    if( user != NULL )
    {
        strcpy(user->nick, "");
        user->popularidad = 0;
        user->userId = 0;
    }
    return user;
}



/** \brief Setea el campo ID en un puntero al tipo de dato sUser .
 *
 * \param user : Puntero donde setear ID.
 * \param id : ID a setear en la estructura.
 * \return Devuelve [1] si el dato fue seteado correctamente o [0] en caso de error .
 *
 */

int user_setId( sUser* user , int id )
{
    int verify = 0;
    if( user != NULL )
    {
        if(validateIntCondition(id,1,1) )
        {
            verify = 1;
            user->userId = id;
        }
    }
    return verify;
}



/** \brief Obtiene el dato ID de un puntero al tipo de dato sUser .
 *
 * \param user : Puntero de donde obtener el dato ID .
 * \return Devuelve el dato correspondiente al atributo de la estructura .
 *
 */

int user_getId( sUser* user )
{
    return user->userId;
}



/** \brief Setea el campo NICK en un puntero al tipo de dato sUser .
 *
 * \param user : Puntero donde setear NICK .
 * \param nick : NICK a setear en la estructura.
 * \return Devuelve [1] si el dato fue seteado correctamente o [0] en caso de error .
 *
 */

int user_setNick( sUser* user , char* nick )
{
    int verify = 0;
    if( user != NULL && nick != NULL)
    {
        if( validateStringRange(nick,1,50) )
        {
            verify = 1;
            strcpy(user->nick , nick);
        }
    }
    return verify;
}



/** \brief Obtiene el dato NICK de un puntero al tipo de dato sUser .
 *
 * \param user : Puntero de donde obtener el dato NICK .
 * \return Devuelve el dato correspondiente al atributo de la estructura .
 *
 */

char* user_getNick( sUser* user )
{
    return user->nick;
}


/** \brief Setea el campo popularidad en un puntero al tipo de dato sUser .
 *
 * \param user : Puntero donde setear popularidad .
 * \param popularidad : popularidad a setear en la estructura.
 * \return Devuelve [1] si el dato fue seteado correctamente o [0] en caso de error .
 *
 */

int user_setPopularidad( sUser* user , long popularidad )
{
    int verify = 0;
    if( user != NULL )
    {
        if(validateIntCondition(popularidad,0,1) )
        {
            verify = 1;
            user->popularidad = popularidad;
        }
    }
    return verify;
}



/** \brief Obtiene el dato popularidad de un puntero al tipo de dato sUser .
 *
 * \param user : Puntero de donde obtener el dato popularidad.
 * \return Devuelve el dato correspondiente al atributo de la estructura .
 *
 */

long user_getPopularidad( sUser* user )
{
    return user->popularidad;
}
