#include <stdlib.h>
#include <stdio.h>
#include "dynamicManage.h"

dynamicManager* dyma_New(void)
{
    dynamicManager* this = (dynamicManager*)malloc(sizeof(dynamicManager));
    void** dynamicPointers = (void**) malloc(sizeof(void*)*INITIAL_VALUE);

    this->dynamicPointers = dynamicPointers;
    this->size = 0;
    this->reservedSize = INITIAL_VALUE;
    this->add = dyma_Add;
    this->totalFree = dyma_TotalFree;
    this->freeAll = dyma_FreeAll;
    this->freeLast = dyma_FreeLast;
    this->len = dyma_len;

    return this;
}

int dyma_Add(dynamicManager* this, void* dynamicPointer )
{
    int verify = 1;
    if( this != NULL && dynamicPointer != NULL)
    {
        if( this->len(this) == this->reservedSize )
        {
            if( (verify = dyma_resizeUp(this)) )
            {
                *(this->dynamicPointers + this->len(this)) = dynamicPointer;
                this->size++;
                verify = 1;
            }
        }


    }
    return verify;
}

int dyma_len(dynamicManager* this )
{
    int len = -1;
    if( this != NULL)
    {
        len = this->size;
    }
    return len;
}

int dyma_TotalFree(dynamicManager* this)
{
    int verify = 0;
    if( this != NULL)
    {
        int i;
        verify = 1;
        for( i = 0 ; i < this->len(this) ; i++)
        {
            free(this->dynamicPointers[i]);
            this->dynamicPointers[i] = NULL;
        }
        free(this->dynamicPointers);
        free(this);
    }
    return verify;
}

int dyma_FreeAll(dynamicManager* this )
{
    int verify = 0;
    if( this != NULL )
    {
        verify = 1;
        int i;
        for( i = 0 ; i < this->len(this) ; i++)
        {
            free(this->dynamicPointers[i]);
        }
        this->dynamicPointers = (void**)realloc(this->dynamicPointers,sizeof(void*)*INITIAL_VALUE);
        this->size = 0;
        this->reservedSize = INITIAL_VALUE;
    }
    return verify;
}

int dyma_resizeUp(dynamicManager* this)
{
    void** aux;
    int verify = 0;
    if( this != NULL)
    {
        int newSize = this->reservedSize + INCREMENT_VALUE;
        aux=(void**)realloc(this->dynamicPointers, sizeof(void*)*newSize);
        if( aux != NULL )
        {
            verify = 1;
            this->dynamicPointers = aux;
            this->reservedSize += INCREMENT_VALUE;
        }
    }
    return verify;
}


int dyma_FreeLast(dynamicManager* this)
{
    int verify = 0;
    if( this != NULL)
    {
        verify = 1;
        free( this->dynamicPointers[ (this->len(this)-1) ] );
    }
    return verify;
}
