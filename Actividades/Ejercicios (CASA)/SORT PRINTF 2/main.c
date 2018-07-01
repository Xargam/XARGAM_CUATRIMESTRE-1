#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "xlook.h"

void xlkSortPrintf2(char dataType[],int style,...);
void xlkStrLimitedCpy(char string[], char remainChars[] );
int xlkStartStringChecker(char* stringToLook,int totalArguments,...);
void xlkStringCutter(char* stringToCut, int index );

int main()
{
    xlkSortPrintf2("%s,%s,%s,%s,%s,%s,%d,%d,%s",1,"ID DEL PRODUCTO","CANTIDAD DEL PRODUCTO","PROVEEDOR DEL PRODUCTO","PRECIO","FECHA","DESCRIPCION",1,450,"SONY");
    return 0;
}

void xlkSortPrintf2(char dataType[],int style,...)
{
    va_list arguments;

    int styleAux = style;
    style = 1000;

    va_start(arguments,style);

    int i,j = 0;
    int flag;
    int format;
    int argumentsToPrint;
    int argumentsReg = 0;

    char formatSpecifiers[strlen(dataType)+1];
    strcpy(formatSpecifiers, dataType);
    xlkStrLimitedCpy(formatSpecifiers,"%scdflif");

    char dataToPrint[1000][1000];
    char dataToPrintAux[1000];

    if( styleAux )
    {
        printf("--------------------------------------------------------------------------------");
    }
    do
    {
        printf(" ");
        argumentsToPrint = 0;
        for(i = 0,j = 0 ; i < 6 ; i++ )
        {
            if( (format = xlkStartStringChecker(formatSpecifiers,9,"%c","%s","%d","%f","%lf","%ld","%li","%lld","%lli")) != -1 )
            {
                if( format == 8 || format == 9)
                {
                    xlkStringCutter(formatSpecifiers,3);
                }
                else if(format == 7 || format == 6 || format == 5)
                {
                    xlkStringCutter(formatSpecifiers,2);
                }
                else
                {
                    xlkStringCutter(formatSpecifiers,1);
                }

                argumentsToPrint++;

                switch(format)
                {
                case 1:
                    sprintf(dataToPrint[j],"%c",va_arg(arguments, int));
                    j++;
                    break;
                case 2:
                    sprintf(dataToPrint[j],"%s",va_arg(arguments, char*));
                    j++;
                    break;
                case 3:
                    sprintf(dataToPrint[j],"%d",va_arg(arguments, int));
                    j++;
                    break;
                case 4:
                case 5:
                    sprintf(dataToPrint[j],"%.2f",va_arg(arguments, double));
                    j++;
                    break;
                case 6:
                case 7:
                    sprintf(dataToPrint[j],"%ld",va_arg(arguments, long ));
                    j++;
                    break;
                case 8:
                case 9:
                    sprintf(dataToPrint[j],"%lld",va_arg(arguments, long long ));
                    j++;
                    break;
                }
            }
            else
            {
                break;
            }
        }

        argumentsReg += argumentsToPrint;

        if( argumentsReg <= 1000 && argumentsToPrint > 0 )
        {
            if( (argumentsReg - argumentsToPrint) % 6 == 0 )
            {
                argumentsToPrint = 6;
            }
            for(i = 0 ; i < argumentsToPrint ; i++ )
            {
                switch(argumentsToPrint)
                {
                case 1:
                    if( strlen(dataToPrint[i]) > 76)
                    {
                        stringSeparator(76,dataToPrint[i],dataToPrintAux);
                        printf("%-76s  ", dataToPrint[i]);
                        strcpy( dataToPrint[i], dataToPrintAux);
                        flag = 1;
                    }
                    else
                    {
                        printf("%-76s  ", dataToPrint[i]);
                        dataToPrint[i][0] = '\0';
                    }
                    break;
                case 2:
                    if( strlen(dataToPrint[i]) > 37)
                    {
                        stringSeparator(37,dataToPrint[i],dataToPrintAux);
                        printf("%-37s  ", dataToPrint[i]);
                        strcpy( dataToPrint[i], dataToPrintAux);
                        flag = 1;
                    }
                    else
                    {
                        printf("%-37s  ", dataToPrint[i]);
                        dataToPrint[i][0] = '\0';
                    }
                    break;
                case 3:
                    if( strlen(dataToPrint[i]) > 23)
                    {
                        stringSeparator(23,dataToPrint[i],dataToPrintAux);
                        printf("%-23s  ", dataToPrint[i]);
                        strcpy( dataToPrint[i], dataToPrintAux);
                        flag=1;
                    }
                    else
                    {
                        printf("%-23s  ", dataToPrint[i]);
                        dataToPrint[i][0] = '\0';
                    }
                    break;
                case 4:
                    if( strlen(dataToPrint[i]) > 17)
                    {
                        stringSeparator(17,dataToPrint[i],dataToPrintAux);
                        printf("%-17s  ", dataToPrint[i]);
                        strcpy( dataToPrint[i], dataToPrintAux);
                        flag=1;
                    }
                    else
                    {
                        printf("%-17s  ", dataToPrint[i]);
                        dataToPrint[i][0] = '\0';
                    }
                    break;
                case 5:
                    if( strlen(dataToPrint[i]) > 13)
                    {
                        stringSeparator(13,dataToPrint[i],dataToPrintAux);
                        printf("%-13s  ",dataToPrint[i]);
                        strcpy( dataToPrint[i], dataToPrintAux);
                        flag=1;
                    }
                    else
                    {
                        printf("%-13s  ", dataToPrint[i]);
                        dataToPrint[i][0] = '\0';
                    }
                    break;
                case 6:
                    if( strlen(dataToPrint[i]) > 11)
                    {
                        stringSeparator(11,dataToPrint[i],dataToPrintAux);
                        printf("%-11s  ",dataToPrint[i]);
                        strcpy( dataToPrint[i], dataToPrintAux);
                        flag=1;
                    }
                    else
                    {
                        printf("%-11s  ", dataToPrint[i]);
                        dataToPrint[i][0] = '\0';
                    }
                    break;
                }
                if( flag && i == argumentsToPrint-1 )
                {
                    printf("\n ");
                    i = -1;
                    flag = 0;
                }

            }
            printf("\n");
            if( styleAux )
            {
                printf("--------------------------------------------------------------------------------");
            }

        }
        else
        {
            argumentsToPrint = 0;
        }


    }
    while( argumentsToPrint > 0);


    va_end(arguments);
}



void xlkStrLimitedCpy(char string[], char remainChars[] )
{
    int i, j, k;   //Variables de ITERACION

    int remainCharsLen = strlen(remainChars); //Cantidad de caracteres de remainChars

    char newString[strlen(string)+1];

    for( i = 0,k = 0 ; string[i] != '\0' ; i++)
    {
        for(j = 0 ; j < remainCharsLen ; j++ )
        {
            if(string[i] == remainChars[j])
            {
                newString[k] = string[i];
                k++;
                break;
            }
        }
    }
    newString[k] = '\0';

    strcpy(string,newString);
}



int xlkStartStringChecker(char* stringToLook,int totalArguments,...)
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


void xlkStringCutter(char* stringToCut, int index )
{
    if( index > -1 && index <= strlen(stringToCut) && stringToCut != NULL)
    {
        int cutIndex = strlen(stringToCut) - index;
        strrev(stringToCut);
        stringToCut[cutIndex-1] = '\0';
        strrev(stringToCut);
    }
}
