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
 * \return Devuelve un puntero a %estructura% .
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
 * \return Devuelve un puntero a %estructura% cargado de datos en caso de error devuelve NULL.
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
 * \return Devuelve [1] si se pudo mostrar el dato o [0] en caso de error.
 *
 */

int generic_show(eGeneric* gen )
{
    int verify = 0;
    if( gen != NULL)
    {
        verify = 1;
        xlkSortPrintf("FGDFGFD",0);
    }
    return verify;
}


/** \brief Muestra todos los elementos de %estructura% .
 *
 * \param gen : Array que de %estructura% que se desea mostrar.
 * \return Devuelve un entero con la cantidad de datos leidos.
 *
 */

int generic_showAll(eGeneric* gen, int quantity)
{
    xlkCenterPrintf("LISTA DE DATOS",1);
    int i;
    for( i = 0 ; i < quantity ; i++)
    {
        xlkSortPrintf("%d,%s,%f",3);
    }
    return i-2;
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
                    verify = generic_modify(gen);
                    break;
                case 2:
                    verify = generic_getFloat(gen);
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
    int number;
    //getRangedInt(&aux,0,100,"Ingrese nuevo entero: ","Entero invalido.");
    if( getValidInt(&number,message,eMessage ) )
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



/** \brief Permite al usuario modifica el %campo% de un puntero a %estructura%.
 *
 * \param gen : Puntero a %estructura%.
 * \param message : Mensaje a ser mostrado al pedir el dato para modificar la estructura.
 * \param eMessage : Mensaje a ser mostrado en caso de error.
 * \return Devuelve [-1] en caso de dato erroneo, [0] en caso de anularse la modificacion o [1] si el dato fue modificado.
 *
 */

int eGeneric_ModifyFloat(eGeneric* gen, char message[], char eMessage[])
{
    int verify = -1;
    float number;
    //getRangedFloat(&aux,0,100,"Ingrese nuevo entero: ","Entero invalido.");
    if( getValidFloat(&number,message,eMessage ) )
    {
        verify = 0;
        if( validateDualExit(XLK_EXITMSG,XLK_INVALID_ANSWER,'s','n') )
        {
            verify = 1;
            gen->floatNumber = number;
        }
    }
    return verify;
}



/** \brief Permite al usuario modifica el %campo% de un puntero a %estructura%.
 *
 * \param gen : Puntero a %estructura%.
 * \param message : Mensaje a ser mostrado al pedir el dato para modificar la estructura.
 * \param eMessage : Mensaje a ser mostrado en caso de error.
 * \return Devuelve [-1] en caso de dato erroneo, [0] en caso de anularse la modificacion o [1] si el dato fue modificado.
 *
 */

int eGeneric_ModidyLong(eGeneric* gen, char message[], char eMessage[] )
{
    int verify = -1;
    long number;
    //getRangedLong(&aux,0,100,"Ingrese nuevo entero: ","Entero invalido.");
    if( getValidLong(&number,message,eMessage ) )
    {
        verify = 0;
        if( validateDualExit(XLK_EXITMSG,XLK_INVALID_ANSWER,'s','n') )
        {
            verify = 1;
            gen->longNumber = number;
        }
    }
    return verify;
}



/** \brief Permite al usuario modifica el %campo% de un puntero a %estructura%.
 *
 * \param gen : Puntero a %estructura%.
 * \param message : Mensaje a ser mostrado al pedir el dato para modificar la estructura.
 * \param eMessage : Mensaje a ser mostrado en caso de error.
 * \return Devuelve [-1] en caso de dato erroneo, [0] en caso de anularse la modificacion o [1] si el dato fue modificado.
 *
 */

int eGeneric_ModidyLongLong(eGeneric* gen, char message[], char eMessage[])
{
    int verify = -1;
    // long long number;
    //getRangedLong(&aux,0,100,"Ingrese nuevo entero: ","Entero invalido.");
    //if( getConditionedLong(&number,0,1,message,eMessage ) )
    {
        verify = 0;
        if( validateDualExit(XLK_EXITMSG,XLK_INVALID_ANSWER,'s','n') )
        {
            verify = 1;
            //gen->longLongNumber = number;
        }
    }
    return verify;
}



/** \brief Permite al usuario modifica el %campo% de un puntero a %estructura%.
 *
 * \param gen : Puntero a %estructura%.
 * \param message : Mensaje a ser mostrado al pedir el dato para modificar la estructura.
 * \param eMessage : Mensaje a ser mostrado en caso de error.
 * \return Devuelve [-1] en caso de dato erroneo, [0] en caso de anularse la modificacion o [1] si el dato fue modificado.
 *
 */

int eGeneric_ModidyDouble(eGeneric* gen, char message[], char eMessage[])
{
    int verify = -1;
    // double number;
    //getRangedLong(&aux,0,100,"Ingrese nuevo entero: ","Entero invalido.");
//   if( getConditionedFloat(&number,0,1,message,eMessage ) )
    {
        verify = 0;
        if( validateDualExit(XLK_EXITMSG,XLK_INVALID_ANSWER,'s','n') )
        {
            verify = 1;
            //     gen->doubleNumber = number;
        }
    }
    return verify;
}



/** \brief Permite al usuario modifica el %campo% de un puntero a %estructura%.
 *
 * \param gen : Puntero a %estructura%.
 * \param message : Mensaje a ser mostrado al pedir el dato para modificar la estructura.
 * \param eMessage : Mensaje a ser mostrado en caso de error.
 * \return Devuelve [-1] en caso de dato erroneo, [0] en caso de anularse la modificacion o [1] si el dato fue modificado.
 *
 */

int eGeneric_ModifyChar(eGeneric* gen, char message[], char eMessage[])
{
    int verify = -1;
    char character;

    if( getRangedChar(&character,0,1,message,eMessage,1 ) )
    {
        verify = 0;
        if( validateDualExit(XLK_EXITMSG,XLK_INVALID_ANSWER,'s','n') )
        {
            verify = 1;
            gen->character = character;
        }
    }
    return verify;
}



/** \brief Permite al usuario modifica el %campo% de un puntero a %estructura%.
 *
 * \param gen : Puntero a %estructura%.
 * \param message : Mensaje a ser mostrado al pedir el dato para modificar la estructura.
 * \param eMessage : Mensaje a ser mostrado en caso de error.
 * \return Devuelve [-1] en caso de dato erroneo, [0] en caso de anularse la modificacion o [1] si el dato fue modificado.
 *
 */

int eGeneric_ModidyString(eGeneric* gen, char message[], char eMessage[])
{
    int verify = -1;
    char vec[100];
    if( getRangedStr(vec,0,1,message,eMessage,1) )
    {
        verify = 0;
        if( validateDualExit(XLK_EXITMSG,XLK_INVALID_ANSWER,'s','n') )
        {
            verify = 1;
            strcpy( gen->vec, vec);
        }
    }
    return verify;
}



//BUCAR DATOS



/** \brief Compara un dato de un puntero a %estructura% con otro y verifica si son iguales.
 *
 * \param gen : puntero a %estructura% .
 * \param data : numero int que sera comparado con el que guarda la estructura.
 * \return Devuelve [-1] en caso de error , [0] si hay igualdad entre los datos o [1] si la hay.
 *
 */

int eGeneric_CheckInt(eGeneric* gen, int data)
{
    int verify = -1;
    if( gen  != NULL )
    {
        verify = 0;
        if( gen->intNumber == data)
        {
            verify = 1;
        }
    }
    return verify;
}



/** \brief Compara un dato de un puntero a %estructura% con otro y verifica si son iguales.
 *
 * \param gen : puntero a %estructura% .
 * \param data : numero float que sera comparado con el que guarda la estructura.
 * \return Devuelve [-1] en caso de error , [0] si hay igualdad entre los datos o [1] si la hay.
 *
 */

int eGeneric_CheckFloat(eGeneric* gen, float data)
{
    int verify = -1;
    if( gen  != NULL )
    {
        verify = 0;
        if( gen->intNumber == data)
        {
            verify = 1;
        }
    }
    return verify;
}



/** \brief Compara un dato de un puntero a %estructura% con otro y verifica si son iguales.
 *
 * \param gen : puntero a %estructura% .
 * \param data : numero long que sera comparado con el que guarda la estructura.
 * \return Devuelve [-1] en caso de error , [0] si hay igualdad entre los datos o [1] si la hay.
 *
 */

int eGeneric_CheckLong(eGeneric* gen, long data)
{
    int verify = -1;
    if( gen  != NULL )
    {
        verify = 0;
        if( gen->longNumber == data)
        {
            verify = 1;
        }
    }
    return verify;
}



/** \brief Compara un dato de un puntero a %estructura% con otro y verifica si son iguales.
 *
 * \param gen : puntero a %estructura% .
 * \param data : numero long long que sera comparado con el que guarda la estructura.
 * \return Devuelve [-1] en caso de error , [0] si hay igualdad entre los datos o [1] si la hay.
 *
 */

int eGeneric_CheckLongLong(eGeneric* gen, long long data)
{
    int verify = -1;
    if( gen  != NULL )
    {
        verify = 0;
        if( gen->longLongNumber == data)
        {
            verify = 1;
        }
    }
    return verify;
}



/** \brief Compara un dato de un puntero a %estructura% con otro y verifica si son iguales.
 *
 * \param gen : puntero a %estructura% .
 * \param data : numero double que sera comparado con el que guarda la estructura.
 * \return Devuelve [-1] en caso de error , [0] si hay igualdad entre los datos o [1] si la hay.
 *

 */
int eGeneric_checkDouble(eGeneric* gen, double data)
{
    int verify = -1;
    if( gen  != NULL )
    {
        verify = 0;
        if( gen->doubleNumber == data)
        {
            verify = 1;
        }
    }
    return verify;
}



/** \brief Compara un dato de un puntero a %estructura% con otro y verifica si son iguales.
 *
 * \param gen : puntero a %estructura% .
 * \param data : Caracter que sera comparado con el que guarda la estructura.
 * \return Devuelve [-1] en caso de error , [0] si hay igualdad entre los datos o [1] si la hay.
 *
 */

int eGeneric_checkChar(eGeneric* gen, char data)
{
    int verify = -1;
    if( gen  != NULL )
    {
        verify = 0;
        if( gen->character == data)
        {
            verify = 1;
        }
    }
    return verify;
}



/** \brief Compara un dato de un puntero a %estructura% con otro y verifica si son iguales.
 *
 * \param gen : puntero a %estructura% .
 * \param data : Cadena de caracteres que sera comparada con la que guarda la estructura.
 * \return Devuelve [-1] en caso de error , [0] si hay igualdad entre los datos o [1] si la hay.
 *
 */

int eGeneric_checkString(eGeneric* gen, char data[])
{
    int verify = -1;
    if( gen  != NULL )
    {
        verify = 0;
        if( stricmp( gen->character, data) == 0)
        {
            verify = 1;
        }
    }
    return verify;
}


//COMPARAR ESTRUCTURAS



/** \brief Compara el %campo% de dos %estructura%.
 *
 * \param generic1 : Puntero de tipo %estructura% a comparar con el segundo.
 * \param generic2 : Puntero de tipo %estructura% que sera comparado con el primero.
 * \return Devuelve [1] si el primer %estructura% es mayor, [0] si son iguales o [-1] si el primer %estructura% menor.
 *
 */

int generic_compare(void* generic1 ,void* generic2)
{
    int verify = 0;

    if(((eGeneric*)generic1)->intNumber > ((eGeneric*)generic2)->intNumber )
    {
        verify = 1;
    }
    if(((eGeneric*)generic1)->intNumber < ((eGeneric*)generic2)->intNumber)
    {
        verify = -1;
    }
    return verify;
}




