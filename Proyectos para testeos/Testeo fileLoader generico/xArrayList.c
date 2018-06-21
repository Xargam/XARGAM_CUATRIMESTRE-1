#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xArrayList.h"

// funciones privadas
int resizeUp(arrayList* this);
int expand(arrayList* this,int index);
int contract(arrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return arrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
arrayList* al_newArrayList(void)
{
    arrayList* this;
    arrayList* returnAux = NULL;
    void* pElements;
    this = (arrayList *)malloc(sizeof(arrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deletearrayList = al_deletearrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList arrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(arrayList* this, void* pElement)
{
    int verify = 0;
    int okResizeUp = 0;
    if( this != NULL && pElement != NULL)
    {
        if( this->len(this) == this->reservedSize)
        {
            okResizeUp = resizeUp(this);
        }
    }
    else
    {
        verify = -1;
    }

    if(!verify && !okResizeUp)
    {
        *(this->pElements + this->len(this)) = pElement;
        this->size++;
    }

    return verify;
}





/** \brief  Delete arrayList
 * \param pList arrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deletearrayList(arrayList* this)
{
    int verify = -1;
    if( this != NULL)
    {
        verify = 0;
        free(this);
    }

    return verify;
}

/** \brief  Delete arrayList
 * \param pList arrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */

int al_len(arrayList* this)
{
    int length = -1;
    int returnChecker;
    returnChecker = al_isEmpty(this);
    if( returnChecker == 0)
    {
        length = this->size;
    }
    else if ( returnChecker == 1)
    {
        length = 0;
    }

    return length;
}


/** \brief  Get an element by index
 * \param pList arrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(arrayList* this, int index)
{
    void* returnAux = NULL;
    if( this != NULL)
    {
        if( index < this->len(this) && index >= 0 )
        {
            returnAux = *(this->pElements + index);
        }
    }
    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList arrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(arrayList* this, void* pElement)
{
    int verify = -1;
    if( this != NULL && pElement != NULL)
    {
        int i;
        verify = 0;
        for(i = 0 ; i < this->len(this) ; i++)
        {
            if( *(this->pElements + i) == pElement)
            {
                verify = 1;
                break;
            }
        }
    }
    return verify;
}


/** \brief  Set a element in pList at index position
 * \param pList arrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(arrayList* this, int index,void* pElement)
{
    int verify = -1;

    if( this != NULL && pElement != NULL   )
    {
        if( ( index < this->len(pElement) && index > -1 ) || index == 0 )
        {
            verify = 0;
            *(this->pElements + index) = pElement;
        }

    }

    return verify;
}


/** \brief  Remove an element by index
 * \param pList arrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(arrayList* this,int index)
{
    int returnAux = -1;

    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList arrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(arrayList* this)
{
    int returnAux = -1;

    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList arrayList* Pointer to arrayList
 * \return arrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
arrayList* al_clone(arrayList* this)
{
    arrayList* returnAux = NULL;

    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList arrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(arrayList* this, int index, void* pElement)
{
    int returnAux = -1;

    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList arrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(arrayList* this, void* pElement)
{
    int returnAux = -1;

    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList arrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(arrayList* this)
{
    int verify = -1;
    if( this != NULL)
    {
        if( this->size == 0)
        {
            verify = 1;
        }
        else
        {
            verify = 0;
        }
    }

    return verify;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList arrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(arrayList* this,int index)
{
    void* returnAux = NULL;

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList arrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
arrayList* al_subList(arrayList* this,int from,int to)
{
    void* returnAux = NULL;

    return returnAux ;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList arrayList* Pointer to arrayList
 * \param pList2 arrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(arrayList* this,arrayList* this2)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList arrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(arrayList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;

    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList arrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(arrayList* this)
{
    void** pElementsAux;
    int verify = -1;
    if( this != NULL)
    {
        pElementsAux=(void**)realloc(this->pElements, sizeof(void*)*(this->reservedSize+AL_INCREMENT));
        if( pElementsAux != NULL )
        {
            verify = 0;
            this->pElements = pElementsAux;
            this->reservedSize += AL_INCREMENT;
        }
    }
    return verify;
}

/** \brief  Expand an array list
 * \param pList arrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(arrayList* this,int index)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList arrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(arrayList* this,int index)
{
    int returnAux = -1;

    return returnAux;
}



/** \brief Recorre un archivo y carga los elementos en un arrayList.
 *
 * \param filePath: Ruta del archivo a leer.
 * \param dataSize: Tamaño en bytes de cada puntero que se debe leer del archivo.
 * \return Devuelve un arrayList con elementos cargados, en caso de error devuelve un puntero a NULL.
 *
 */

arrayList* xfiFileLoader( char* filePath, int dataSize)
{
    arrayList* arrayList = NULL;
    int reading;
    int okFlag = 0;

    if( filePath != NULL )
    {
        FILE* file = fopen(filePath,"rb");
        if(file != NULL )
        {
            arrayList = al_newArrayList();
            if( arrayList != NULL)
            {
                while( !feof(file) )
                {
                    void* pointer = malloc(sizeof(dataSize));
                    if( pointer == NULL)
                    {
                        okFlag = 1;
                        break;
                    }
                    reading = fread(pointer,sizeof(dataSize),1,file);
                    if(reading != 1)
                    {
                        if( feof(file) )
                        {
                            break;
                        }
                        else
                        {
                            free(pointer);
                            okFlag = 1;
                            break;
                        }
                    }

                    arrayList->add(arrayList,pointer);
                }
            }
            if( fclose(file) )
            {
                okFlag = 1;
            }
        }
        if( okFlag )
        {
            int i;
            for(i = 0 ; i < arrayList->len(arrayList) ; i++ )
            {
                free( arrayList->get(arrayList,i) );
            }
            free(arrayList->pElements);
            free(arrayList);
            arrayList = NULL;
        }
    }
    return  arrayList;
}
