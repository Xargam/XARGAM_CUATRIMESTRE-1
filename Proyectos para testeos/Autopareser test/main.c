#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "xlook.h"
#define ARCH "autos.csv"

int csvGenericParser(FILE* filePointer, int dataToParse,char* format, int totalArguments,...);
int startStringChecker(char* stringToLook,int totalArguments,...);
void stringCutter(char* stringToCut, int index );
void* stringConditionalConversor(char* inputString, char* stringCompare, void* output );

typedef struct
{
    int id;
    char marca[200];
    char modelo[200];
    char color[200];
    int anio;

} eAutos;

int main()
{
    eAutos autos[2000];
    FILE* file = fopen(ARCH,"r");
    if( file == NULL)
    {
        file = fopen(ARCH, "w");
    }
    int i = 0;
    fscanf(file,"%[^\n]\n",autos[i].marca);
    system("pause");
    while( csvGenericParser(file,5,"%d;%s;%s;%s;%d;",5, &autos[i].id ,autos[i].marca, autos[i].modelo ,autos[i].color , &autos[i].anio ))
    {
        xlkSortPrintf(1,"%d,%s,%s,%s,%d",5,autos[i].id , autos[i].marca , autos[i].modelo,autos[i].color , autos[i].anio);
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

int csvGenericParser( FILE* filePointer, int dataToParse,char* format, int totalArguments,...)
{
    int verify = 0;

    if( dataToParse < 21 && dataToParse > -1 && totalArguments < 201 && totalArguments > -1 && filePointer != NULL && format != NULL && strlen(format) < 1000 && !feof(filePointer) )
    {
        char format2[1000];
        strcpy(format2 , format);
        verify = 1; //Variable de retorno indicando error o final de archivo.
        va_list arguments;
        va_start(arguments, totalArguments );

        char matrizDatos[20][1000]; //Matriz que guarda strings con los datos leidos de una linea del archivo que se debe parsear. El parser soporta archivos de 20 datos.
        char conversionArgument[1000]; //Cuando el usuario quiere convertir un dato leido del archivo en otro string o en otro tipo de dato, se guarda en esta cadena "especial".
        char argumentToCompare[1000];  //Recibe parametros con los que se debe comparar un dato leido del archivo para transformarlo.

        //Punteros utilizados para guardar parametros:

        char* stringPointer;
        int* integerPointer;
        long* longPointer;
        long long* longLongPointer;
        double* doublePointer;
        void* pointer;

        //Numero para guardar parametros de posible conversion:

        int integerNumber; //Entero utilizado para leer argumentos que indican comparaciones de un dato del archivo.
        double doubleNumber;
        long longNumber;
        long long longLongNumber;

        int i; // Variable de iteraciones relacionada con los argumentos que se van leyendo.
        int j; // Variable de iteraciones relacionada con la matriz de datos leidos del archivo.

        int flagConversion = 0; //Bandera que indica que se estan leyendo parametros relacionados a un dato que se debe convertir.
        int flag2Conversion = 0; //Bandera que dice al programa si se esta leyendo un string a comparar o un dato que que se podria asignar a un parametro de conversion.
        int flag3 = 0; // Si se convirtio un parametro esta bandera indica que se detengan las comparaciones con los sigguientes parametros y que se dejen pasar.
        int formatReader; //Lee la cadena de formato.
        int lastFormat; // Guarda el ultimo dato de format reader.

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
                flag2Conversion = 1 - flag2Conversion; // si flag2 es 1 se lee argumento de comparacion , 0 se realiza comparacion y/o asignacion .
            }
            formatReader = startStringChecker(format2,11,"%s;","%c;","%d;","%i;","%ld;","%li;","%lld;","%lli;","%f;","-->","<--"); // Leo la cadena de fomato.
            stringCutter(format2,2); //Corto la cadena de formato para poder leer el siguiente.
            switch(formatReader)
            {
            case 1:
            case 2:
                if(flagConversion && flag2Conversion == 1 )
                {
                    strcpy(argumentToCompare,va_arg(arguments,char*)); //Leo un argumento que deberia ser un string para comparar con un dato del archivo que debe convertirse.
                }
                else if( flagConversion && flag2Conversion == 0 )
                {
                    lastFormat = formatReader; //Guardo el ultimo formato leido.
                    stringPointer = stringConditionalConversor(conversionArgument,argumentToCompare, va_arg(arguments,char*)); //Comparo argumento a convertir con string de parametro.
                    if( stringPointer != NULL && !flag3)
                    {
                        strcpy( ((char*)pointer),stringPointer); //Si no devuelve null el conversor y flag3 es 0 (no se realizo asignacion) asigno el dato convertido.
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
                    integerNumber = va_arg(arguments,int);
                    integerPointer = stringConditionalConversor(conversionArgument,argumentToCompare, &integerNumber );
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
                    longNumber = va_arg(arguments,long);
                    longPointer = stringConditionalConversor(conversionArgument,argumentToCompare, &longNumber );
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
                    longLongNumber = va_arg(arguments,long long);
                    longLongPointer = stringConditionalConversor(conversionArgument,argumentToCompare, &longLongNumber );
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
                    doubleNumber = va_arg(arguments,double);
                    doublePointer = stringConditionalConversor(conversionArgument,argumentToCompare, &doubleNumber);
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
                pointer = va_arg(arguments,void*); //Si es el caso 10 lei una flechita, que indica un puntero que debe ser cargado con el dato del archivo convertido si es posible.
                strcpy( conversionArgument,matrizDatos[j]); //El dato de esta posicion lo guardo en el string conversionArgument para comparalo.
                j++; //Cada vez que leo un dato de la matriz incremento el indice de iteraciones relacionado a la matriz.
                flagConversion = 1; //Indico que lei un argumento que es de comparacion para su analisis.
                break;
            case 11:
                //Si es el caso 11 lei la flechita de final de parametros de conversion.
                if(flag3 == 0) //Si la bandera es 0, el dato de conversion no se convirtio nunca, le asigno el dato que vino del archivo segun ultimo formato leido.
                {
                    switch(lastFormat)
                    {
                    case 1:
                    case 2:
                        strcpy( ((char*)pointer), conversionArgument );
                        break;
                    case 3:
                    case 4:
                        integerNumber = atoi(conversionArgument);
                        *((int*)pointer) = integerNumber;
                        break;
                    case 5:
                    case 6:
                        longNumber = atol(conversionArgument);
                        *((long*)pointer) = longNumber;
                        break;
                    case 7:
                    case 8:
                        longLongNumber = atoll(conversionArgument);
                        *((long long*)pointer) = longLongNumber;
                        break;
                    case 9:
                        doubleNumber = atof(conversionArgument);
                        *((double*)pointer) = doubleNumber;
                        break;
                    }
                }
                i--; //Como no se lee ningun parametro bajo la variable de iteraciones para evitar colapsos.
                flag3 = 0; //Resstablezco todas las banderas relacionadas con argumentos de conversion.
                flagConversion = 0;
                flag2Conversion = 0;
                break;
            }
        }
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
