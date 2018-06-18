#include <stdio.h>
#include <stdlib.h>

void* xfiNewDynamicArray(int arraySize, int dataSize )
{
    void* singlePointer = (void*)malloc(sizeof(dataSize)*arraySize);
    return singlePointer;
}

void** xfiNewDynamicArray2(int arraySize, int dataSize )
{
    void** array = NULL;
    void* singlePointer = NULL;
    if(arraySize > 0)
    {
        array = (void**)malloc(sizeof(void*)*arraySize );
        if(array != NULL)
        {
            singlePointer = xfiNewDynamicArray(arraySize,sizeof(dataSize));
            if( singlePointer != NULL)
            {
                int i;
                for( i = 0 ; i < arraySize ; i++)
                {
                    array[i] = (singlePointer+i);
                }
            }
            else
            {
                free(array);
            }
        }
    }
    return array;
}

void** xfiArrayResizer2(void** arrayToResize, int newSize)
{
    if( newSize > 0)
    {
        arrayToResize = (void**)realloc(arrayToResize,sizeof(void*)*newSize );
    }
    else
    {
        arrayToResize = NULL;
    }

    return arrayToResize;
}

int xfiFileSync(char* filename)
{
    int verify = 1;

    FILE* file;

    file = fopen(filename, "rb");

    if( file == NULL )
    {
        file = fopen(filename, "wb" );
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



void** xfiFileLoader(char* filePath, int* quantity, int dataSize)
{
    void** doublePointer = NULL;

    int reading;
    int okFlag = 0;
    int index = 0;
    *quantity = index;

    if( filePath != NULL && quantity != NULL)
    {
        FILE* file = fopen(filePath,"rb");
        if(file != NULL )
        {
            doublePointer = xfiNewDynamicArray2(1,sizeof(dataSize));
            if( doublePointer != NULL )
            {
                while( !feof(file) )
                {
                    reading = fread( doublePointer[index],sizeof(dataSize),1,file);
                    if(reading != 1)
                    {
                        if( feof(file) )
                        {
                            break;
                        }
                        else
                        {
                            okFlag = 1;
                            break;
                        }
                    }
                    index++;
                    if( index >= *quantity )
                    {
                        if( (doublePointer = xfiArrayResizer2(doublePointer,index+1)) == NULL)
                        {
                            okFlag = 1;
                            break;
                        }
                        *quantity = index+1;
                    }
                }

            }
            if( fclose(file) )
            {
                okFlag = 1;
            }
        }
    }
    if( okFlag )
    {
        free(doublePointer);
    }

    return doublePointer;
}




