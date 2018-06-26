#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int resizeDown(ArrayList* this );
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this = (ArrayList*)malloc(sizeof(ArrayList));

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
            this->deleteArrayList = al_deleteArrayList;
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
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement)
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
        *(this->pElements + this->size) = pElement;
        this->size++;
    }

    return verify;
}





/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int verify = -1;
    if( this != NULL )
    {
        verify = 0;
        free(this->pElements);
        free(this);
    }
    return verify;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */

int al_len(ArrayList* this)
{
    int length = -1;
    if( this != NULL)
    {
        if( al_isEmpty(this) != -1)
        {
            length = this->size;
        }
    }
    return length;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
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
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int verify = -1;
    if( this != NULL && pElement != NULL)
    {
        int i;
        verify = 0;
        for(i = 0 ; i < this->len(this) ; i++)
        {
            if( this->get(this,i) == pElement)
            {
                verify = 1;
                break;
            }
        }
    }
    return verify;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int verify = -1;

    if( this != NULL && pElement != NULL   )
    {
        if( index <= this->len(this) && index >= 0 )
        {
            if( index == this->len(this) )
            {
                if( !this->add(this, pElement) )
                {
                    verify = 0;
                }
            }
            else
            {
                *(this->pElements + index) = pElement;
                verify = 0;
            }
        }
    }

    return verify;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int verify = -1;
    if( this != NULL && index >= 0 && index < this->len(this))
    {
        if( !contract(this, index) )
        {
            verify = 0;
        }
    }

    return verify ;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int verify = -1;

    if( this != NULL)
    {
        void** auxElements;
        auxElements =(void**) realloc(this->pElements,sizeof(void*));
        if(auxElements != NULL)
        {
            verify = 0;
            this->pElements = auxElements;
            this->size = 0;
            this->reservedSize = 0;
        }

    }
    return verify;
}


/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;
    if( this != NULL)
    {
        returnAux =  al_newArrayList();
        if(returnAux != NULL)
        {
            int i;
            for( i = 0 ; i < this->len(this) ; i++)
            {
                returnAux->add(returnAux, this->get(this,i));
            }
            returnAux = this;
        }
    }
    return returnAux;
}



/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int verify = -1;
    if( this != NULL && index <= this->len(this) && index >= 0 )
    {
        if( index == this->len(this))
        {
            if( !this->add(this, pElement) )
            {
                verify = 0;
            }
        }
        else
        {
            if( !expand(this,index) )
            {
                if( !this->set(this,index,pElement) )
                {
                    verify = 0;
                }
            }
        }
    }
    return verify;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int index = -1;
    if( this != NULL && pElement != NULL)
    {
        int i;
        for( i = 0 ; i < this->len(this) ; i++)
        {
            if( this->get(this,i) ==  pElement )
            {
                index = i;
                break;
            }
        }
    }

    return index;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int verify = -1;
    if( this != NULL)
    {
        if( this->size == 0)
        {
            verify = 1;
        }
        else if(this->size > 0)
        {
            verify = 0;
        }
    }

    return verify;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;
    if( this != NULL && index >= 0 && index < this->len(this) )
    {
        if( (returnAux = this->get(this,index))!= NULL)
        {
            if( contract(this,index) )
            {
                returnAux = NULL;
            }
        }
    }
    return returnAux;
}



/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    ArrayList* returnAux = NULL;

    if( this != NULL && from != to && from < to && from >= 0 && to >= 0  )
    {
        returnAux = al_newArrayList();
        if( returnAux != NULL)
        {
            int i;
            for( i = from ; i < to ; i++)
            {
                returnAux->add(returnAux, this->get(this,i) );
            }
        }
    }
    return returnAux ;
}



/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int verify = -1;
    if( this != NULL && this2 != NULL)
    {
        if( this->len(this) != this2->len(this2) )
        {
            verify = 0;
        }
        else
        {
            int i;
            verify = 1;
            for( i = 0 ; i < this->len(this) ; i++ )
            {
                if( this->get(this,i) != this2->get(this2,i)  )
                {
                    verify = 0;
                    break;
                }
            }
        }
    }
    return verify;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    int i;
    int j;

    if( this != NULL && pFunc != NULL)
    {
        void* aux;
        if(order == 1)
        {
            returnAux = 0;
            for( i = 0 ; i < this->len(this)-1 ; i++ )
            {
                for( j = i +1 ; j < this->len(this) ; j++)
                {
                    if( pFunc(this->get(this, j),this->get(this,i)) == -1 )
                    {
                        aux = this->get(this,i);
                        this->set(this,i,this->get(this, j));
                        this->set(this,j,aux);
                    }
                }
            }
        }
        else if( order == 0)
        {
            returnAux = 0;
            for( i = 0 ; i < this->len(this)-1 ; i++ )
            {
                for( j = i +1 ; j < this->len(this) ; j++)
                {
                    if( pFunc(this->get(this, j),this->get(this,i) ) == 1)
                    {
                        aux = this->get(this,i);
                        this->set(this,i,this->get(this, j));
                        this->set(this,j,aux);
                    }
                }
            }
        }

    }

    return returnAux;
}

/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int verify = -1;
    if( this != NULL)
    {
        void** pElementsAux;
        int newSize = this->reservedSize + AL_INCREMENT;
        pElementsAux=(void**)realloc(this->pElements, sizeof(void*)*newSize);
        if( pElementsAux != NULL )
        {
            verify = 0;
            this->pElements = pElementsAux;
            this->reservedSize = newSize;
        }
    }
    return verify;
}



/** \brief reduce the number of elements in pList  elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeDown(ArrayList* this)
{
    int verify = -1;
    if( this != NULL)
    {
        void** pElementsAux;
        int newSize = this->reservedSize - AL_INCREMENT;
        pElementsAux = (void**)realloc(this->pElements, sizeof(void*)*newSize);
        if( pElementsAux != NULL )
        {
            verify = 0;
            this->pElements = pElementsAux;
            this->reservedSize = newSize;
        }
    }
    return verify;
}
/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int verify = -1;
    if( this != NULL )
    {
        verify = 0;
        this->size++;
        if( this->len(this) == this->reservedSize  )
        {
            verify =  resizeUp(this);
        }

        if( !verify )
        {
            int i;
            for( i = this->len(this) ; i > index  ; i--)
            {
                this->set(this,i,this->get(this,i-1));
            }
        }
    }
    return verify;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int verify = -1 ;
    if( this != NULL && index >= 0 && index < this->len(this) )
    {
        verify = 0;
        int i;
        for( i = index+1 ; i < this->len(this) ; i++)
        {
            this->set(this, i-1, this->get(this,i));
        }
        this->size--;
        if( this->len(this) < this->reservedSize - AL_INCREMENT)
        {
            if( resizeDown(this) )
            {
                verify = -1;
            }
        }
    }
    return verify;
}
