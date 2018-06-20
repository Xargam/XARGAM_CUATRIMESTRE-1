#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "xlook.h"
#define ARCH "data.csv"

int csvGenericParser(FILE* filePointer, int dataToParse,char format[], int totalArguments,...);
int startStringChecker(char* stringToLook,int totalArguments,...);
void stringCutter(char* stringToCut, int index );
void* stringConditionalConversor(char* inputString, char* stringCompare, void* output );

typedef struct
{
    int id;
    char nombre[200];
    char apellido[200];
    int estado;
} ePersonas;

int main()
{
    ePersonas personas[2000];
    char format[]= {"%d;%s;%s;-->%s;%d;%s;%d;<--"};
    int case1 = 1;
    int case2 = 0;

    char strCmp[]= {"TRUE"};
    char strCmp2[]= {"FALSE"};

    FILE* file = fopen(ARCH,"r");
    if( file == NULL)
    {
        file = fopen(ARCH, "w");
    }
    int i = 0;
    fscanf(file,"%[^\n]\n",personas[i].nombre);
    printf("LONGI: %ld",ftell(file) );
    system("pause");
    while( csvGenericParser(file,4,format,8,&personas[i].id, personas[i].nombre, personas[i].apellido, &personas[i].estado , strCmp , &case1 , strCmp2 , &case2  ))
    {
        xlkSortPrintf(1,"%d,%s,%s,%d",4,personas[i].id , personas[i].nombre , personas[i].apellido, personas[i].estado);
        i++;
    }
    fclose(file);
    return 0;
}


void* stringConditionalConversor(char* inputString, char* stringCompare, void* output )
{
    void* returnPointer = NULL;
    if( stricmp(inputString, stringCompare ) == 0 )
    {
        returnPointer = output;
    }
    return returnPointer;
}

int csvGenericParser( FILE* filePointer, int dataToParse,char format[], int totalArguments,...)
{
    int verify = 0;
    if( dataToParse < 21 && dataToParse > -1 && totalArguments < 201 && totalArguments > -1 && filePointer != NULL && format != NULL && strlen(format) < 1000 && !feof(filePointer) )
    {
        char auxFormat[1000];
        strcpy(auxFormat,format);
        verify = 1;
        va_list arguments;
        va_start(arguments, totalArguments );

        char matrizDatos[20][1000];
        char conversionArgument[1000];
        char argumentToCompare[1000];
        char* stringPointer;
        int* integerPointer;
        long* longPointer;
        long long* longLongPointer;
        double* doublePointer;
        void* pointer;
        int i;
        int j;
        int flagConversion = 0;
        int flag2Conversion = 0;
        int flag3 = 0;
        int formatReader;
        int lastFormat;

        switch(dataToParse)
        {
        case 1:
            fscanf(filePointer,"%[^\n]\n",matrizDatos[0]);
            break;
        case 2:
            fscanf(filePointer,"%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1]);
            break;
        case 3:
            fscanf(filePointer,"%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2]);
            break;
        case 4:
            fscanf(filePointer,"%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3]);
            break;
        case 5:
            fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4]);
            break;
        case 6:
            fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5]);
            break;
        case 7:
            fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5], matrizDatos[6]);
            break;
        case 8:
            fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7]);
            break;
        case 9:
            fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8]);
            break;
        case 10:
            fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9]);
            break;
        case 11:
            fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9],matrizDatos[10]);
            break;
        case 12:
            fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9],matrizDatos[10],matrizDatos[11]);
            break;
        case 13:
            fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9],matrizDatos[10],matrizDatos[11],matrizDatos[12]);
            break;
        case 14:
            fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9],matrizDatos[10],matrizDatos[11],matrizDatos[12],matrizDatos[13]);
            break;
        case 15:
            fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9],matrizDatos[10],matrizDatos[11],matrizDatos[12],matrizDatos[13],matrizDatos[14]);
            break;
        case 16:
            fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9],matrizDatos[10],matrizDatos[11],matrizDatos[12],matrizDatos[13],matrizDatos[14],matrizDatos[15]);
            break;
        case 17:
            fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9],matrizDatos[10],matrizDatos[11],matrizDatos[12],matrizDatos[13],matrizDatos[14],matrizDatos[15],matrizDatos[16]);
            break;
        case 18:
            fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9],matrizDatos[10],matrizDatos[11],matrizDatos[12],matrizDatos[13],matrizDatos[14],matrizDatos[15],matrizDatos[16],matrizDatos[17]);
            break;
        case 19:
            fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9],matrizDatos[10],matrizDatos[11],matrizDatos[12],matrizDatos[13],matrizDatos[14],matrizDatos[15],matrizDatos[16],matrizDatos[17],matrizDatos[18]);
            break;
        case 20:
            fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9],matrizDatos[10],matrizDatos[11],matrizDatos[12],matrizDatos[13],matrizDatos[14],matrizDatos[15],matrizDatos[16],matrizDatos[17],matrizDatos[18],matrizDatos[19]);
            break;
        }
        for( i = 0, j = 0; i < totalArguments ; i++)
        {
            if( flagConversion )
            {
                flag2Conversion = 1 - flag2Conversion;
            }

            formatReader = startStringChecker(format,11,"%s;","%c;","%d;","%i;","%ld;","%li;","%lld;","%lli;","%f;","-->","<--");
            stringCutter(format,2);
            switch(formatReader)
            {
            case 1:
            case 2:
                if(flagConversion && flag2Conversion == 1 )
                {
                    strcpy(argumentToCompare,va_arg(arguments,char*));
                }
                else if( flagConversion && flag2Conversion == 0 )
                {
                    lastFormat = formatReader;
                    stringPointer = stringConditionalConversor(conversionArgument,argumentToCompare, va_arg(arguments,void*));
                    if( stringPointer != NULL && !flag3)
                    {
                        strcpy( ((char*)pointer),stringPointer);
                        flag3 = 1;
                    }
                }
                else if( !flagConversion)
                {
                    stringPointer = va_arg(arguments,char*);
                    if( stringPointer != NULL)
                    {
                        strcpy(stringPointer, matrizDatos[j]);
                        j++;
                    }
                }
                break;
            case 3:
            case 4:
                if( flagConversion && flag2Conversion == 0 )
                {
                    lastFormat = formatReader;
                    integerPointer = stringConditionalConversor(conversionArgument,argumentToCompare, va_arg(arguments,void*));
                    if( integerPointer != NULL && !flag3)
                    {
                        *((int*)pointer) = *integerPointer;
                        flag3 = 1;
                    }
                }
                else if( !flagConversion )
                {
                    integerPointer = va_arg(arguments,int*);
                    *integerPointer = atoi(matrizDatos[j]);
                    j++;
                }
                break;
            case 5:
            case 6:
                if( flagConversion && flag2Conversion == 0 )
                {
                    lastFormat = formatReader;
                    longPointer = stringConditionalConversor(conversionArgument,argumentToCompare, va_arg(arguments,void*));
                    if( longPointer != NULL  && !flag3)
                    {
                        *((long*)pointer) = *longPointer;
                        flag3 = 1;
                    }
                }
                else if( !flagConversion )
                {
                    longPointer = va_arg(arguments,long*);
                    *longPointer = atol(matrizDatos[j]);
                    j++;
                }
                break;
            case 7:
            case 8:
                if( flagConversion && flag2Conversion == 0  )
                {
                    lastFormat = formatReader;
                    longLongPointer = stringConditionalConversor(conversionArgument,argumentToCompare, va_arg(arguments,void*));
                    if( longLongPointer != NULL && !flag3)
                    {
                        *((long long*)pointer) = *longLongPointer;
                        flag3 = 1;
                    }
                }
                else if( !flagConversion)
                {
                    longLongPointer = va_arg(arguments,long long*);
                    *longLongPointer = atoll(matrizDatos[j]);
                    j++;
                }
                break;
            case 9:
                if( flagConversion && flag2Conversion == 0  )
                {
                    lastFormat = formatReader;
                    doublePointer = stringConditionalConversor(conversionArgument,argumentToCompare, va_arg(arguments,void*));
                    if( doublePointer != NULL && !flag3)
                    {
                        *((double*)pointer) = *doublePointer;
                        flag3 = 1;
                    }
                }
                else if(!flagConversion)
                {
                    doublePointer = va_arg(arguments,double*);
                    *doublePointer = atof(matrizDatos[j]);
                    j++;
                }
                break;
            case 10:
                pointer = va_arg(arguments,void*);
                strcpy( conversionArgument,matrizDatos[j]);
                j++;
                flagConversion = 1;
                break;
            case 11:
                if(flag3 == 0)
                {
                    switch(lastFormat)
                    {
                    case 1:
                    case 2:
                        strcpy( ((char*)pointer), conversionArgument );
                        break;
                    case 3:
                    case 4:
                        *integerPointer = atoi(conversionArgument);
                        *((int*)pointer) = *integerPointer;
                        break;
                    case 5:
                    case 6:
                        *longPointer = atol(conversionArgument);
                        *((long*)pointer) = *longPointer;
                        break;
                    case 7:
                    case 8:
                        *longLongPointer = atoll(conversionArgument);
                        *((long long*)pointer) = *longLongPointer;
                        break;
                    case 9:
                        *doublePointer = atof(conversionArgument);
                        *((double*)pointer) = *doublePointer;
                        break;
                    }
                }
                i--;
                flag3 = 0;
                flagConversion = 0;
                flag2Conversion = 0;
                break;
            }
        }
        strcpy(format,auxFormat);
        va_end(arguments);
    }

    return verify;
}


int startStringChecker(char* stringToLook,int totalArguments,...)
{
    int match = -1;
    if(stringToLook != NULL)
    {
        va_list arguments;
        va_start(arguments, totalArguments);

        int i;
        int j;

        for(i = 1 ; i <= totalArguments && match== -1 ; i++)
        {
            char* stringArgument = va_arg(arguments,char*);

            for(j = 0 ; stringArgument[j] != '\0'  ; j++)
            {
                match = i;
                if( stringToLook[j] != stringArgument[j] )
                {
                    match = -1;
                    break;
                }
            }
        }

        va_end(arguments);
    }
    return match;
}


void stringCutter(char* stringToCut, int index )
{
    if( index > -1 && index <= strlen(stringToCut) && stringToCut != NULL)
    {
        int cutIndex = strlen(stringToCut) - index;
        strrev(stringToCut);
        stringToCut[cutIndex-1] = '\0';
        strrev(stringToCut);
    }
}
