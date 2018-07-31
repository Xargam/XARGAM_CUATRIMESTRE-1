#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xget.h"
#include "xvalidate.h"
#include "xArrayWork.h"
#include "xlook.h"



/*
--------------------------------------------ETIQUETAS------------------------------------------------->
Cambiar tipo de dato de las funciones:

*---->   eGeneric*
*---->   generic

Sustitucion automatica de campo en documentaciones:

*---->   %campo%

Sustitucion automatica de tipo de dato en documentaciones:

*---->   %tipoDeDato%

------------------------------>
* Buscar setter y getter:
------------------------------>

Enteros:       $INT$
Longs:         $LONG$
Long longs     $LONGLONG$

Flotantes:     $FLOAT$
Doubles        $DOUBLE$

Caracteres:    $CHAR$
String         $CHAR*$

------------------------------>
*Buscar constructor:
------------------------------>

Constructor:   $BUILDER$

------------------------------>
*Buscar comparadores:
------------------------------>

Comparador:               $COMP$
Buscador de igualdad:     $SAME$

------------------------------------------------------------------------------------------------------>
*/


// Constructor $BUILDER$

/** \brief Reserva espacio dinamico para un puntero del tipo de dato %tipoDeDato% e inicializa sus campos.
 *
 * \param
 * \return Devuelve un puntero a una estructura del tipo de dato %tipoDeDato% , en caso de error un puntero a NULL.
 *
 */

eGeneric* generic_newGeneric(void)
{
    eGeneric* generic = (eGeneric*)malloc(sizeof(eGeneric));
    if( generic != NULL )
    {
        strcpy(generic->word, "");
        generic->intNumber = 0;
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



// Set y get ENTEROS $INT$



/** \brief Setea el campo %campo% en un puntero al tipo de dato %tipoDeDato% .
 *
 * \param generic : Puntero donde setear %campo% .
 * \param num : %campo% a setear en la estructura.
 * \return Devuelve [1] si el dato fue seteado correctamente o [0] en caso de error .
 *
 */

int generic_setInt( eGeneric* generic , int num )
{
    int verify = 0;
    if( generic != NULL )
    {
        if(validateIntRange(num,0,5) )
        {
            verify = 1;
            generic->intNumber = num;
        }
    }
    return verify;
}



/** \brief Obtiene el dato %campo% de un puntero al tipo de dato %tipoDeDato% .
 *
 * \param generic : Puntero de donde obtener el dato %campo% .
 * \return Devuelve el dato correspondiente al atributo de la estructura .
 *
 */

int generic_getInt( eGeneric* generic )
{
    return generic->intNumber;
}



// Set y get LONGS: $LONG$



/** \brief Setea el campo %campo% en un puntero al tipo de dato %tipoDeDato% .
 *
 * \param generic : Puntero donde setear %campo% .
 * \param num : %campo% a setear en la estructura.
 * \return Devuelve [1] si el dato fue seteado correctamente o [0] en caso de error .
 *
 */

int generic_setLong( eGeneric* generic , long num )
{
    int verify = 0;
    if( generic != NULL )
    {
        validateLongRange(num,0,5);
        if( 1)
        {
            verify = 1;
            generic->longNumber = num;
        }
    }
    return verify;
}



/** \brief Obtiene el dato %campo% de un puntero al tipo de dato %tipoDeDato% .
 *
 * \param generic : Puntero de donde obtener el dato %campo% .
 * \return Devuelve el dato correspondiente al atributo de la estructura .
 *
 */

long generic_getLong( eGeneric* generic )
{
    return generic->longNumber;
}



// Set y get LONG LONGS: $LONGLONG$




/** \brief Setea el campo %campo% en un puntero al tipo de dato %tipoDeDato% .
 *
 * \param generic : Puntero donde setear %campo% .
 * \param num : %campo% a setear en la estructura.
 * \return Devuelve [1] si el dato fue seteado correctamente o [0] en caso de error .
 *
 */

int generic_setLongLong( eGeneric* generic , long long num )
{
    int verify = 0;
    if( generic != NULL )
    {
        if( 1 )
        {
            verify = 1;
            generic->longLongNumber = num;
        }
    }
    return verify;
}



/** \brief Obtiene el dato %campo% de un puntero al tipo de dato %tipoDeDato% .
 *
 * \param generic : Puntero de donde obtener el dato %campo% .
 * \return Devuelve el dato correspondiente al atributo de la estructura .
 *
 */

long long generic_getLongLong( eGeneric* generic )
{
    return generic->longLongNumber;
}



// Set y get FLOTANTES: $FLOAT$



/** \brief Setea el campo %campo% en un puntero al tipo de dato %tipoDeDato% .
 *
 * \param generic : Puntero donde setear %campo% .
 * \param num : %campo% a setear en la estructura.
 * \return Devuelve [1] si el dato fue seteado correctamente o [0] en caso de error .
 *
 */

int generic_setFloat( eGeneric* generic , float num )
{
    int verify = 0;
    if( generic != NULL )
    {
        if( 1 )
        {
            verify = 1;
            generic->floatNumber = num;
        }
    }
    return verify;
}



/** \brief Obtiene el dato %campo% de un puntero al tipo de dato %tipoDeDato% .
 *
 * \param generic : Puntero de donde obtener el dato %campo% .
 * \return Devuelve el dato correspondiente al atributo de la estructura .
 *
 */

float generic_getFloat( eGeneric* generic )
{
    return generic->floatNumber;
}



// Set y get DOUBLES: $DOUBLE$



/** \brief Setea el campo %campo% en un puntero al tipo de dato %tipoDeDato% .
 *
 * \param generic : Puntero donde setear %campo% .
 * \param num : %campo% a setear en la estructura.
 * \return Devuelve [1] si el dato fue seteado correctamente o [0] en caso de error .
 *
 */

int generic_setDouble( eGeneric* generic , double num )
{
    int verify = 0;
    if( generic != NULL )
    {
        if( 1 )
        {
            verify = 1;
            generic->doubleNumber = num;
        }
    }
    return verify;
}



/** \brief Obtiene el dato %campo% de un puntero al tipo de dato %tipoDeDato% .
 *
 * \param generic : Puntero de donde obtener el dato %campo% .
 * \return Devuelve el dato correspondiente al atributo de la estructura .
 *
 */

double generic_getDouble( eGeneric* generic )
{
    return generic->doubleNumber;
}



// Set y get CHAR : $CHAR$



/** \brief Setea el campo %campo% en un puntero al tipo de dato %tipoDeDato% .
 *
 * \param generic : Puntero donde setear %campo% .
 * \param num : %campo% a setear en la estructura.
 * \return Devuelve [1] si el dato fue seteado correctamente o [0] en caso de error .
 *
 */

int generic_setChar( eGeneric* generic , char let )
{
    int verify = 0;
    if( generic != NULL )
    {
        if( 1 )
        {
            verify = 1;
            generic->character = let;
        }
    }
    return verify;
}



/** \brief Obtiene el dato %campo% de un puntero al tipo de dato %tipoDeDato% .
 *
 * \param generic : Puntero de donde obtener el dato %campo% .
 * \return Devuelve el dato correspondiente al atributo de la estructura .
 *
 */

char generic_getChar( eGeneric* generic )
{
    return generic->character;
}



// Set y get CHAR* : $CHAR*$



/** \brief Setea el campo %campo% en un puntero al tipo de dato %tipoDeDato% .
 *
 * \param generic : Puntero donde setear %campo% .
 * \param num : %campo% a setear en la estructura.
 * \return Devuelve [1] si el dato fue seteado correctamente o [0] en caso de error .
 *
 */

int generic_setString( eGeneric* generic , char* word )
{
    int verify = 0;
    if( generic != NULL && word != NULL)
    {
        if( 1 )
        {
            verify = 1;
            strcpy(generic->word , word);
        }
    }
    return verify;
}



/** \brief Obtiene el dato %campo% de un puntero al tipo de dato %tipoDeDato% .
 *
 * \param generic : Puntero de donde obtener el dato %campo% .
 * \return Devuelve el dato correspondiente al atributo de la estructura .
 *
 */

char* generic_getString( eGeneric* generic )
{
    return generic->word;
}



//FUNCIONES ABM



/** \brief Pide %estructura% .
 *
 * \return Devuelve un puntero a %estructura% cargado de datos en caso de error devuelve NULL.
 *
 */

eGeneric* generic_requester(void)
{
    eGeneric* lm = generic_newGeneric();
    if( lm != NULL)
    {
        int verify;
        int number = 45;
        do
        {
            verify = 0;
            if( 1 )
            {
                if( generic_setInt(lm,number) )
                {
                    verify=1;
                }
            }
        }
        while(verify == 0 );

    }
    return lm;
}


/** \brief Muestra los datos de un puntero al tipo de dato  %estructura% .
 *
 * \param Variable de tipo %estructura% a mostrar.
 * \return Devuelve [1] si se pudo mostrar el dato o [0] en caso de error.
 *
 */

int generic_show(eGeneric* gen )
{
    int verify = 0;
    if( gen != NULL)
    {
        verify = 1;
    }
    return verify;
}



/** \brief Permite al usuario modificar una estructura.
 *
 * \param gen : puntero a %estructura% que se desea modificar.
 * \param message : Mensaje a ser mostrado al pedirle al usuario el dato irrepible de la estructura.
 * \param eMessage : Mensaje a ser mostrado en caso de que el usuario escriba un dato erroneo.
 * \return Devuelve [1] si el usuario modifico algun dato , [0] si no lo hizo o [-1] en caso de un puntero a NULL.
 *
 */

int generic_modify(eGeneric* gen )
{
    int verify = -1;
    if( gen != NULL)
    {
        int selection;
        int quit = 0;
        verify = 0;
        do
        {
            xlkIndexGenerator("HEAD",3,"1* uno.","2* dos.","3* tres.");
            if(getRangedInt(&selection,0,3,"Seleccionar opcion: ","Opcion invalida."))
            {
                system("cls");
                switch(selection)
                {
                case 1:
                    //verify = generic_modify(gen);
                    break;
                case 2:
                    //verify = generic_getFloat(gen);
                    break;
                case 3:
                    quit = validateDualExit(XLK_EXITMSG,XLK_INVALID_ANSWER,'s','n');
                    break;
                }
            }
            system("pause");
        }
        while(quit == 0);
    }
    return verify;
}


//MODIFICAR DATOS:



/** \brief Permite al usuario modifica el %campo% de un puntero a %estructura%.
 *
 * \param gen : Puntero a %estructura%.
 * \param message : Mensaje a ser mostrado al pedir el dato para modificar la estructura.
 * \param eMessage : Mensaje a ser mostrado en caso de error.
 * \return Devuelve [-1] en caso de dato erroneo, [0] en caso de anularse la modificacion o [1] si el dato fue modificado.
 *
 */

int eGeneric_ModifyInt(eGeneric* gen, char message[], char eMessage[])
{
    int verify = -1;
    int number = 45;

    if( 1 )
    {
        verify = 0;
        if( validateDualExit(XLK_EXITMSG,XLK_INVALID_ANSWER,'s','n') )
        {
            verify = 1;
            gen->intNumber = number;
        }
    }
    return verify;
}



//COMPARAR ESTRUCTURAS  $COMP$



/** \brief Compara dos punteros a estructuras del tipò %campo% .
 *
 * \param generic1 : Puntero a ser comparado con otro.
 * \param generic2 : Puntero a ser comparado con el primero.
 * \return Devuelve [1] si el primer puntero es mayor, [0] si son iguales o [-1] si el primer puntero es menor.
 *
 */

int generic_compare(void* generic1 ,void* generic2)
{
    int comparision = 0;

    if( ((eGeneric*)generic1)->intNumber > ((eGeneric*)generic2)->intNumber )
    {
        comparision = 1;
    }
    if( ((eGeneric*)generic1)->intNumber < ((eGeneric*)generic2)->intNumber )
    {
        comparision = -1;
    }
    return comparision;
}
