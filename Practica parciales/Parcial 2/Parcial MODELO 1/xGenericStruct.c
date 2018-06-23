#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xget.h"
#include "xvalidate.h"
#include "xGenericStruct.h"
#include "xlook.h"

//BASICO


/** \brief Reserva espacio dinamico para un array de %estructura% .
 *
 * \param size : Cantidad de elementos.
 * \return devuelve un puntero a %estructura% .
 *
 */

eGeneric* generic_newGeneric(int size)
{
    eGeneric* generic = NULL;
    if( size > 0)
    {
        generic = malloc(sizeof(eGeneric)*size);
    }
    return generic;
}



/** \brief Reserva espacio dinamico para un array de doble punteros a %estructura% .
 *
 * \param size : Cantidad de elementos.
 * \return devuelve un puntero a %estructura% .
 *
 */

eGeneric** generic_newGenericDblPointer(int size)
{
    eGeneric** generic = NULL;
    if( size > 0)
    {
        generic = malloc(sizeof(eGeneric*)*size);
    }
    return generic;
}



//Destructores:



/** \brief Libera un puntero.
 *
 * \param pointer: Puntero a liberar.
 * \return Devuelve [1] si el puntero fue liberado o [0] en caso contrario.
 *
 */

int generic1_PointerDestroyer( void* pointer )
{
    int destroyed = 0;

    if( pointer != NULL )
    {
        destroyed = 1;
        free(pointer);
    }
    return destroyed;
}



/** \brief Libera punteros anidados en un puntero doble.
 *
 * \param pointer : Puntero doble a liberar.
 * \param size : Cantidad de punteros anidados que se deben eliminar.
 * \return Devuelve [1] si los punteros se liberaron o [0] en caso contrario.
 *
 */

int generic2_PointerDestroyer( void** pointer, int size  )
{
    int destroyed = 0;

    if( pointer != NULL && size > 0  )
    {
        destroyed = 1;
        int i;
        for( i = 0 ; i < size ; i++)
        {
            free(pointer[i]);
            pointer[i] = NULL;
        }
    }
    return destroyed;
}


/*
* \brief Elimina los punteros simples anidados en un puntero
 *
 * \param pointer : Puntero triple a liberar.
 * \param size : Cantidad de punteros anidados a eliminar.
 * \return
 *


int generic3_PointerDestroyer( void*** pointer, int size )
{
    int destroyed = 0;

    if( pointer != NULL && size > 0  )
    {
        destroyed = 1;
        int i;
        for( i = 0 ; i < size ; i++)
        {
            free(pointer[i][i]);
            pointer[i][i] = NULL;
        }
    }
    return destroyed;
}


int generic4_PointerDestroyer( void**** pointer, int size )
{
    int destroyed = 0;

    if( pointer != NULL && size > 0  )
    {
        destroyed = 1;
        int i;
        for( i = 0 ; i < size ; i++)
        {
            free(pointer[i][i][i]);
            pointer[i][i][i] = NULL;
        }
    }
    return destroyed;
}


int generic5_PointerDestroyer( void***** pointer, int size )
{
    int destroyed = 0;

    if( pointer != NULL && size > 0  )
    {
        destroyed = 1;
        int i;
        for( i = 0 ; i < size ; i++)
        {
            free(pointer[i][i][i][i]);
            pointer[i][i][i][i] = NULL;
        }
    }
    return destroyed;
}

*/

//SETTERS



/** \brief Setea %int% en un puntero a %estructura% .
 *
 * \param xGen : Puntero a %estructura% .
 * \param num : %int% a setear .
 * \param eMessage : Mensaje de error a mostrar si el dato a setear no es valido .
 * \return Devuelve [1] si el dato fue seteado o [0] en caso de error .
 *
 */

int generic_setInt( eGeneric* xGen, int num, char* eMessage )
{
    int verify = 0;
    if( xGen != NULL && eMessage != NULL )
    {
        if(validateIntRange(num,0,5) )
        {
            verify = 1;
            xGen->intNumber = num;
        }
        else
        {
            printf("** %s",eMessage);
            printf("\n\n");
        }
    }
    return verify;
}



/** \brief Setea %long% en un puntero a %estructura% .
 *
 * \param xGen : Puntero a %estructura% .
 * \param num : %long% a setear .
 * \param eMessage : Mensaje de error a mostrar si el dato a setear no es valido .
 * \return Devuelve [1] si el dato fue seteado o [0] en caso de error .
 *
 */

int generic_setLong( eGeneric* xGen, long num, char* eMessage )
{
    int verify = 0;
    if( xGen != NULL && eMessage != NULL )
    {
        if( validateLongRange(num,0,5) )
        {
            verify = 1;
            xGen->longNumber = num;
        }
        else
        {
            printf("** %s",eMessage);
        }
    }
    return verify;
}



/** \brief Setea %longlong% en un puntero a %estructura% .
 *
 * \param xGen : Puntero a %estructura% .
 * \param num : %longlong% a setear .
 * \param eMessage : Mensaje de error a mostrar si el dato a setear no es valido .
 * \return Devuelve [1] si el dato fue seteado o [0] en caso de error .
 *
 */

int generic_setLongLong( eGeneric* xGen, long long num, char* eMessage )
{
    int verify = 0;
    if( xGen != NULL && eMessage != NULL)
    {

        if( num > 45)
        {
            verify = 1;
            xGen->longLongNumber = num;
        }
        else
        {
            printf("** %s",eMessage);
        }
    }
    return verify;
}


/** \brief Setea %float% en un puntero a %estructura% .
 *
 * \param xGen : Puntero a %estructura% .
 * \param num : %float% a setear .
 * \param eMessage : Mensaje de error a mostrar si el dato a setear no es valido .
 * \return Devuelve [1] si el dato fue seteado o [0] en caso de error .
 *
 */

int generic_setFloat( eGeneric* xGen, float num, char* eMessage )
{
    int verify = 0;
    if( xGen != NULL && eMessage != NULL )
    {
        if(validateFloatRange(num,45,80) )
        {
            verify = 1;
            xGen->floatNumber = num;
        }
        else
        {
            printf("** %s",eMessage);
        }
    }
    return verify;
}



/** \brief Setea %double% en un puntero a %estructura% .
 *
 * \param xGen : Puntero a %estructura% .
 * \param num : %double% a setear .
 * \param eMessage : Mensaje de error a mostrar si el dato a setear no es valido .
 * \return Devuelve [1] si el dato fue seteado o [0] en caso de error .
 *
 */

int generic_setDouble( eGeneric* xGen, double num, char* eMessage )
{
    int verify = 0;
    if( xGen != NULL && eMessage != NULL )
    {
        if( num > 45)
        {
            verify = 1;
            xGen->doubleNumber = num;
        }
        else
        {
            printf("** %s",eMessage);
        }
    }
    return verify;
}



/** \brief Setea %char% en un puntero a %estructura% .
 *
 * \param xGen : Puntero a %estructura% .
 * \param character : %char% a setear .
 * \param eMessage : Mensaje de error a mostrar si el dato a setear no es valido .
 * \return Devuelve [1] si el dato fue seteado o [0] en caso de error.
 *
 */

int generic_setChar( eGeneric* xGen, char  character, char* eMessage  )
{
    int verify = 0;
    if( xGen != NULL && eMessage != NULL  )
    {
        if(  character != 's' )
        {
            verify = 1;
            xGen->character = character;
        }
        else
        {
            printf("** %s",eMessage);
        }
    }
    return verify;
}



/** \brief Setea %char*% en un puntero a %estructura% .
 *
 * \param xGen : Puntero a %estructura% .
 * \param string : %char*% a setear .
 * \param eMessage : Mensaje de error a mostrar si el dato a setear no es valido .
 * \return Devuelve [1] si el dato fue seteado o [0] en caso de error.
 *
 */

int generic_setString( eGeneric* xGen, char* string, char* eMessage )
{
    int verify = 0;
    if( xGen != NULL && string != NULL && eMessage != NULL )
    {
        if( validateStringRange(string,10,50) )
        {
            verify = 1;
            strcpy( xGen->vec, string);
        }
        else
        {
            printf("** %s",eMessage);
        }
    }
    return verify;
}


//GETTERS



/** \brief Obtiene %int% de un puntero a %estructura% .
 *
 * \param xGen : Puntero a %estructura% .
 * \return Devuelve un int .
 *
 */

int generic_getInt( eGeneric* xGen )
{
    return xGen->intNumber;
}


/** \brief Obtiene %long% de un puntero a %estructura% .
 *
 * \param xGen : Puntero a %estructura% .
 * \return Devuelve un long .
 *
 */

long generic_getLong( eGeneric* xGen )
{
    return xGen->longNumber;
}



/** \brief Obtiene %longlong% de un puntero a %estructura% .
 *
 * \param xGen : Puntero a %estructura% .
 * \return Devuelve un long long .
 *
 */

long long generic_getLongLong( eGeneric* xGen )
{
    return xGen->longLongNumber;
}



/** \brief Obtiene %float% de un puntero a %estructura% .
 *
 * \param xGen : Puntero a %estructura% .
 * \return Devuelve un float .
 *
 */

float generic_getFloat( eGeneric* xGen )
{
    return xGen->floatNumber;
}



/** \brief Obtiene %double% de un puntero a %estructura% .
 *
 * \param xGen : Puntero a %estructura% .
 * \return Devuelve un double .
 *
 */

double generic_getDouble( eGeneric* xGen )
{
    return xGen->doubleNumber;
}




/** \brief Obtiene %char% de un puntero a %estructura% .
 *
 * \param xGen : Puntero a %estructura% .
 * \return Devuelve un char .
 *
 */

char generic_getChar( eGeneric* xGen )
{
    return xGen->character;
}



/** \brief Obtiene %char*% de un puntero a %estructura% .
 *
 * \param xGen : Puntero a %estructura% .
 * \return Devuelve un char* .
 *
 */

char* generic_getString( eGeneric* xGen)
{
    return xGen->vec;
}

//FUNCIONES ABM



/** \brief Pide %estructura% .
 *
 * \return Devuelve un puntero a %estructura% cargado de datos.
 *
 */

eGeneric* generic_requester(void)
{
    eGeneric* lm = malloc(sizeof(eGeneric));
    if( lm != NULL)
    {
        int verify;
        int number;

        do
        {
            verify = 0;
            if( getValidInt(&number,"INGRESE EG: ","Error")  )
            {
                if( generic_setInt(lm,number,"NO ME GUSTA" ) )
                {
                    verify=1;
                }
            }
        }
        while(verify == 0 );

    }
    return lm;
}


/** \brief Muestra un %estructura%
 *
 * \param Variable de tipo %estructura% a mostrar.
 * \return
 *
 */

void generic_show(eGeneric* gen )
{
    xlkSortPrintf(1,"FGDFGFD",0);
}


 /** \brief Muestra todos los elementos de %estructura% .
  *
  * \param gen : Array que de %estructura% que se desea mostrar.
  * \return Devuelve un entero con la cantidad de datos leidos.
  *
  */

 int generic_showAll(eGeneric* gen , int quantity)
 {
     xlkCenterPrintf("LISTA DE DATOS",1);
     int i;
     for( i = 0 ; i < quantity ; i++)
     {
         xlkSortPrintf(1,"%d,%s,%f",3);
     }
     return i-2;
 }
