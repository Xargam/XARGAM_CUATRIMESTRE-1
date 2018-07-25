#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xget.h"
#include "xvalidate.h"
#include "xArrayWork.h"
#include "xlook.h"

//Constructor:


/** \brief Reserva espacio dinamico para un array del tipo de dato %estructura% .
 *
 * \return Devuelve un puntero a una estructura del tipo de dato correspondiente en caso de error un puntero a NULL .
 *
 */

eGeneric* generic_newGeneric(void)
{
    eGeneric* generic = (eGeneric*)malloc(sizeof(eGeneric));
    if( generic != NULL )
    {
        strcpy(generic->test, "");
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



//SETTERS



/** \brief Setea %int% en un puntero al tipo de dato %estructura% .
 *
 * \param xGen : Puntero donde setear dato .
 * \param num : %int% a setear .
 * \return Devuelve [1] si el dato fue seteado correctamente o [0] en caso de error .
 *
 */

int generic_setInt( eGeneric* xGen, int num )
{
    int verify = 0;
    if( xGen != NULL )
    {
        if(validateIntRange(num,0,5) )
        {
            verify = 1;
            xGen->intNumber = num;
        }
    }
    return verify;
}



//GETTERS



/** \brief Obtiene %int% de un puntero al tipo de dato %estructura% .
 *
 * \param xGen : Puntero de donde obtener el dato .
 * \return Devuelve el dato correspondiente .
 *
 */

int generic_getInt( eGeneric* xGen )
{
    return xGen->intNumber;
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
        int number;
        do
        {
            verify = 0;
            if( getValidInt(&number,"INGRESE EG: ","Error")  )
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
      //  xlkSortPrintf(3,"",0);
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



//COMPARAR ESTRUCTURAS



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
