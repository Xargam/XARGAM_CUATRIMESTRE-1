#include <stdio.h>
#include <stdlib.h>
/*
void* xfiNewDynamicArray(int arraySize, int dataSize )
{
    void* singlePointer = (void*)malloc(sizeof(dataSize)*arraySize);
    return singlePointer;
}
*/

void* xfiNewDynamicPointer(int dataSize, int quantity)
{
    void* pointer =(void*)malloc(sizeof(dataSize)*quantity);
    return pointer;
}


int xfiFileSync(char* filePath)
{
    int verify = 1;

    FILE* file;

    file = fopen(filePath, "rb");

    if( file == NULL )
    {
        file = fopen(filePath, "wb" );
        if( file == NULL)
        {
            verify = -1;
        }
        else
        {
            verify = 0;
        }
    }
    else
    {
        verify = 1;
    }

    if(fclose(file))
    {
        verify = -1;
    }
    return verify;
}







