#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>


//INFORMACION IMPORTANTE: En la consola CMD entran 90 caracteres o digitos por linea.


//Funciones complemento - Trabajo con cadenas de caracteres:



/** \brief Elimina los caracteres de una cadena de caracteres que no esten especificados en remainChars.
 *
 * \param string: Cadena de caracteres a reducir.
 * \param remainChars: String que sera separado en caracteres y seran los que no seran eliminados de la cadena a reducir.
 * \return
 *
 */

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



/** \brief Separa una cadena a partir de un caracter especifico copiandose el resto de la cadena a otra y borrandose lo copiado desde la primera cadena.
 *
 * INFO ADICIONAL: Si hay espacios, la funcion hara la separacion desde el ultimo antes del caracter divisor.
 * \param splitterCharacter: numero de caracter a partir del cual el string1 finalizara y se copiaran los caracteres siguientes.
 * \param string1: Cadena a dividir a partir del caracter divisor(splitterCharacter).
 * \param string2: Cadena en la que se copiara el contenido que se encuentre despues del caracter divisor en string1.
 * \return
 *
 */

void xlkStringSeparator(int splitterCharacter, char* string1, char* string2 )
{
    int i;
    int j;
    int flag = 0;
    int cutIndex = 0;
    int lastSpaceIndex = -1;
    for( i = 0, j = 0 ; string1[i] != '\0'; i++ )
    {
        if( string1[i] == ' ')
        {
            lastSpaceIndex = i;
        }
        if( i >= splitterCharacter )
        {
            if(flag == 0)
            {
                if( lastSpaceIndex != -1)
                {
                    cutIndex = lastSpaceIndex;
                    splitterCharacter = lastSpaceIndex;
                    i = lastSpaceIndex ;
                    flag++;
                    continue;
                }
                else
                {
                    cutIndex = i;
                    flag++;
                }

            }
            string2[j] = string1[i];
            j++;
        }
    }
    string1[cutIndex] = '\0';
    string2[j] = '\0';
}



/** \brief Corta una cadena desde el indice especificado.
 *
 * \param stringToCut:
 * \param index: Indice de corte. El caracter del mismo e indices a la izquierda son eliminados.
 * \return
 *
 */

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



/** \brief Revisa el comienzo de una cadena y verifica si coincide con alguna de las cadenas pasadas como argumento.
 *
 * \param stringToLook : String a comparar.
 * \param totalArguments : Cantidad de cadenas que se pasaran como argumento para comparar con strinToLook.
 * \param ... : Se agregan tantas cadenas como totalArguments indique.
 * \return Devuelve [-1] Si no hubo coincidencias o el numero de argumento que coincide con el inicio de stringToLook.
 *
 */

int xlkStartStringChecker(char* stringToLook, int totalArguments, ...)
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



//Generadores de menus completos:


//XL1-1
/** \brief Genera un menu con la cantidad de opciones y texto a eleccion.
 *
 * \param head: Encabezado del menu.
 * \param totalOptions: se coloca un entero que indica la cantidad de opciones a generar
 * \param Se agregan parametros con string para las opciones, segun la cantidad elegida.
 *
 */

void xlkIndexGenerator(char head[],int totalOptions,...)
{
    system("cls");
    int i;
    va_list arguments;
    va_start(arguments,totalOptions);
    printf("#*---*---*---*---*---*---*---*---*---*----*---*---*---*---*---*---*---*---*---*#\n");
    printf("  *%s\n                                                                           ",head);
    printf("\n#*---*---*---*---*---*---*---*---*---*----*---*---*---*---*---*---*---*---*---*#\n");
    printf("###########____________________________________________________________________#\n"    );
    printf("   MENU:\n\n"                                                                          );
    printf("###########____________________________________________________________________#\n"  );
    for(i = 0; i < totalOptions; i++)
    {
        printf("-  %s\n",va_arg(arguments,char*));
    }
    printf("\n############___________________________________________________________________#\n");
    va_end(arguments);
}



//Generadores de fragmentos de menu:


//XL1-2
/** \brief Recuadra un texto con un diseño agradable para utilizarlo como encabezado destacado.
 *
 * \param mode:[distinto de 0] genera un encabezado con una linea debajo del mismo. mode:[0] no genera la linea.
 * \param text: texto a encuadrar.
 * \return
 *
 */
void xlkHeadGenerator(int mode, char text[])
{
    system("cls");
    printf("\\/  \\/   \\/  \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/\n");
    printf(" ** %s\n\n",text);
    printf("/\\  /\\   /\\  /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\\n");
    if(mode)
    {
        printf("________________________________________________________________________________\n");
    }

}


//XL1-3
/** \brief Genera un listado de opciones de cantidad variable sin encabezado.
 *
 * \param mode:[distinto de 0] genera un cuerpo de menu con una linea arriba del mismo. mode:[0] no genera la linea.
 * \param totalOptions: cantidad de opciones del listado.
 * \param ... Se colocan tantos argumentos como cantidad de opciones con texto a mostrar.
 * \return
 *
 */
void xlkIndexBodyGenerator(int mode,int totalOptions,...)
{
    va_list arguments;
    va_start(arguments,totalOptions);
    int i;
    if(mode)
    {
        printf("________________________________________________________________________________\n");
    }
    for( i=0; i < totalOptions; i++)
    {
        printf(" * %s\n",va_arg(arguments,char*));
    }
    printf("________________________________________________________________________________\n\n");
    va_end(arguments);
}


//XL1-4
/** \brief Muestra un mensaje al usuario con enters y añadidos a elegir.
 *
 * \param message : Mensaje a mostrar.
 * \param startEnters : Cantidad de enters(\n) que se imprimiran antes de mostrar el mensaje.
 * \param endEnters : Cantidad de enters(\n) que se imprimiran despues de mostrar el mensaje.
 * \param adds : [0] Muestra el mensaje con un system("cls").
 * \param adds : [1] Muestra el mensaje con un system("pause").
 * \param adds : [2] Muestra el mensaje con un system("cls") previo y un system("pause").
 * \param adds : [3] Muestra el mensaje con un system("cls") previo, un system("pause") y un exit.
 * \param adds : [ != (0, 1, 2 ,3) ] Muestra el mensaje.
 * \return
 *
 */

void xlkShowMessage(char* message, int startEnters,int endEnters, int adds )
{
    int i;
    if( startEnters > 0 )
    {
        for(i = 0 ; i < startEnters ; i++)
        {
            printf("\n");
        }
    }
    switch(adds)
    {
    case 0:
        system("cls");
        printf("* %s",message);
        break;
    case 1:
        printf("* %s",message);
        printf("\n\n");
        system("pause");
        break;
    case 2:
        system("cls");
        printf("* %s",message);
        printf("\n\n");
        system("pause");
        break;
    case 3:
        system("cls");
        printf("* %s",message);
        printf("\n\n");
        system("pause");
        exit(1);
        break;
    default :
        printf("* %s",message);
        break;
    }

    if( endEnters > 0 )
    {
        for(i = 0 ; i < endEnters ; i++)
        {
            printf("\n");
        }
    }
}



//XL1-6
/** \brief Imprime datos de manera encolumnada y ordenada.
 *
 * \param acotado : En 0 esta desactivado. Si tiene un numero negativo o postivo, segun su valor encolumnara los datos.
 * \param acotado : Si vale 5 será traducido a columnas con %5s separaciones.
 * \param dataType : Especificadores de formato separados o no por , : Ej: %d,%f,%ld.
 al igual que printf.
 * \param lines : [2] Se imprime una linea punteada superior e inferior a modo de decoracion.
 * \param lines : [1] Se imprime una linea inferior a modo de decoracion.
 * \param lines : [0] Los datosn se imprimen sin decoracion.
 * \param ... : Argumentos con datos a imprimir.
 * \return
 *
 */
void xlkSortPrintf(int acotado,char* dataType,int lines,...)
{
    if(dataType != NULL && lines > -1 && lines < 3 && acotado <= 74 && acotado >= -74)
    {
        va_list arguments; //DECLARACION LISTA DE ARGUMENTOS VARIABLES
        int styleAux = lines; //COPIO LA ESTETICA SOLICITADA POR EL USUARIO A OTRA VARIABLE
        int i,j; //VARIABLES DE ITERACION
        int flag = 0; //UTILIZADA PARA SABER SI LAS PALABRAS O DATOS SON MAS LARGOS Y DEBE HACERSE UNA BAJADA DE LINEA.
        int format = 0; //NUMERO ENTERO QUE SE RELACIONA CON  EL FORMATO DEL DATO A LEER COMO ARGUMENTO.
        int argumentsToPrint; //CUENTA LA CANTIDAD DE ARGUMENTOS VARIABLES QUE SE DETECTAN
        int argumentsReg = 0; //REGISTRA LOS ARGUMENTOS QUE SE IMPRIMEN, LA FUNCION NO DEJA QUE ESTE REGISTRO SUPERE LOS 1000


        lines = 1000; //A LINES LE ASIGNO EL NUMERO DE ARGUMENTOS MAXIMO QUE PODRA IMPRIMIR LA FUNCION
        va_start(arguments,lines); //INICIALIZO LISTA DE ARGUMENTOS VARIABLES

        char formatSpecifiers[strlen(dataType)+1]; //SE REALIZA UNA COPIA DE LA CADENA DE FORMATO PARA PODER MODIFICARLA
        strcpy(formatSpecifiers, dataType);
        xlkStrLimitedCpy(formatSpecifiers,"%scdflif"); //ESTA FUNCION SOLO DEJA EL STRING QUE CORRESPONDAN CON FORMATOS VALIDOS.

        char dataToPrint[6][1000]; //MATRIZ QUE VA GUARDANDO LOS ARGUMENTOS LEIDOS PARA LUEGO IMPRIMIRLOS.
        char dataToPrintAux[1000]; //AUXILIAR UTILIZADO PARA COPIAS.

        char formatoAcotado[10]= {"  %"};
        int lenSuma = 0;

        if( acotado )
        {
            sprintf(dataToPrintAux,"%d",acotado);
            strcat(formatoAcotado,dataToPrintAux);
            strcat(formatoAcotado,"s  ");
        }

        if( styleAux == 2) //SI EL ESTILO ES TRUE, SE IMPRIME DECORACION
        {
            printf("--------------------------------------------------------------------------------");
        }

        do
        {
            argumentsToPrint = 0;
            for(i = 0,j = 0 ; i < 6 && format != -1 ; i++ )
            {
                //LEE EL TIPO DE DATO Y VA CORTANDO LA CADENA HASTA LEER TODAS LAS MASCARAS
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

                    argumentsToPrint++; //CONTADOR DE ARGUMENTOS DETECTADOS

                    //SE GUARDA EL DATO DETECTADO COMO CADENA

                    switch(format)
                    {
                    case 1:
                        sprintf(dataToPrint[j],"%c",va_arg(arguments, int));
                        break;
                    case 2:
                        sprintf(dataToPrint[j],"%s",va_arg(arguments, char*));

                        break;
                    case 3:
                        sprintf(dataToPrint[j],"%d",va_arg(arguments, int));
                        break;
                    case 4:
                    case 5:
                        sprintf(dataToPrint[j],"%.2f",va_arg(arguments, double));
                        break;
                    case 6:
                    case 7:
                        sprintf(dataToPrint[j],"%ld",va_arg(arguments, long ));
                        break;
                    case 8:
                    case 9:
                        sprintf(dataToPrint[j],"%lld",va_arg(arguments, long long ));
                        break;
                    }
                    lenSuma += strlen(dataToPrint[j]);
                    j++;

                }
            }

            argumentsReg += argumentsToPrint;
            if( argumentsReg <= 1000 && argumentsToPrint > 0 )
            {
                printf(" "); //ESPACIO INICIAL PARA SEPARAR DATOS DEL BORDE DE LA PANTALLA

                for(i = 0 ; i < argumentsToPrint ; i++ )
                {
                    switch(argumentsToPrint)
                    {
                    case 1:
                        if( acotado )
                        {
                            printf(formatoAcotado,dataToPrint[i]);
                        }
                        else if( strlen(dataToPrint[i]) > 77)
                        {
                            //SI LA PALABRA ES DEMASIADO LARGA, LA CORTO Y EL RESTO LA IMPRIMO EN OTRA VUELTA DE ITERACION DEL FOR.

                            xlkStringSeparator(77,dataToPrint[i],dataToPrintAux);
                            printf("%-77s ", dataToPrint[i]);
                            strcpy( dataToPrint[i], dataToPrintAux);
                            flag = 1; //INDICA QUE EL FOR DEBE VOLVER A DAR LA VUELTA POR QUE UNA PALABRA ES LARGA.
                        }
                        else
                        {
                            printf("%-77s ", dataToPrint[i]);
                            dataToPrint[i][0] = '\0';
                        }
                        break;
                    case 2:
                        if( acotado )
                        {
                            printf(formatoAcotado,dataToPrint[i]);
                        }
                        else if( strlen(dataToPrint[i]) > 38)
                        {
                            xlkStringSeparator(38,dataToPrint[i],dataToPrintAux);
                            printf("%-38s ", dataToPrint[i]);
                            strcpy( dataToPrint[i], dataToPrintAux);
                            flag = 1;
                        }
                        else
                        {
                            printf("%-38s ", dataToPrint[i]);
                            dataToPrint[i][0] = '\0';
                        }
                        break;
                    case 3:
                        if( acotado )
                        {
                            printf(formatoAcotado,dataToPrint[i]);
                        }
                        else if( strlen(dataToPrint[i]) > 25)
                        {
                            xlkStringSeparator(25,dataToPrint[i],dataToPrintAux);
                            printf("%-25s ", dataToPrint[i]);
                            strcpy( dataToPrint[i], dataToPrintAux);
                            flag=1;
                        }
                        else
                        {
                            printf("%-25s ", dataToPrint[i]);
                            dataToPrint[i][0] = '\0';
                        }
                        break;
                    case 4:
                        if( acotado )
                        {
                            printf(formatoAcotado,dataToPrint[i]);
                        }
                        else if( strlen(dataToPrint[i]) > 18)
                        {
                            xlkStringSeparator(18,dataToPrint[i],dataToPrintAux);
                            printf("%-18s ", dataToPrint[i]);
                            strcpy( dataToPrint[i], dataToPrintAux);
                            flag=1;
                        }
                        else
                        {
                            printf("%-18s ", dataToPrint[i]);
                            dataToPrint[i][0] = '\0';
                        }
                        break;
                    case 5:
                        if( acotado )
                        {
                            printf(formatoAcotado,dataToPrint[i]);
                        }
                        else if( strlen(dataToPrint[i]) > 14)
                        {
                            xlkStringSeparator(14,dataToPrint[i],dataToPrintAux);
                            printf("%-14s ",dataToPrint[i]);
                            strcpy( dataToPrint[i], dataToPrintAux);
                            flag=1;
                        }
                        else
                        {
                            printf("%-14s ", dataToPrint[i]);
                            dataToPrint[i][0] = '\0';
                        }
                        break;
                    case 6:
                        if( acotado )
                        {
                            printf(formatoAcotado,dataToPrint[i]);
                        }
                        else if( strlen(dataToPrint[i]) > 12)
                        {
                            xlkStringSeparator(12,dataToPrint[i],dataToPrintAux);
                            printf("%-12s ",dataToPrint[i]);
                            strcpy( dataToPrint[i], dataToPrintAux);
                            flag=1;
                        }
                        else
                        {
                            printf("%-12s ", dataToPrint[i]);
                            dataToPrint[i][0] = '\0';
                        }
                        break;
                    }
                    if( flag && i == argumentsToPrint-1 )
                    {
                        printf("\n");
                        i = -1; //REINICIA EL FOR
                        flag = 0;
                    }

                }

                if( styleAux == 1 || styleAux == 2 )
                {

                    printf("\n--------------------------------------------------------------------------------");


                }
                if( styleAux == 0)
                {
                    printf("\n");
                }

            }
        }
        while( argumentsToPrint > 0);
        va_end(arguments); //CIERRE DE LISTA DE ARGUMENTOS VARIABLES
    }
}
/*
void xlkSortPrintf(char* dataType,int lines,...)
{
    if(dataType != NULL && lines > -1 && lines < 3 )
    {
        va_list arguments; //DECLARACION LISTA DE ARGUMENTOS VARIABLES
        int styleAux = lines; //COPIO LA ESTETICA SOLICITADA POR EL USUARIO A OTRA VARIABLE
        int i,j; //VARIABLES DE ITERACION
        int flag = 0; //UTILIZADA PARA SABER SI LAS PALABRAS O DATOS SON MAS LARGOS Y DEBE HACERSE UNA BAJADA DE LINEA.
        int format = 0; //NUMERO ENTERO QUE SE RELACIONA CON  EL FORMATO DEL DATO A LEER COMO ARGUMENTO.
        int argumentsToPrint; //CUENTA LA CANTIDAD DE ARGUMENTOS VARIABLES QUE SE DETECTAN
        int argumentsReg = 0; //REGISTRA LOS ARGUMENTOS QUE SE IMPRIMEN, LA FUNCION NO DEJA QUE ESTE REGISTRO SUPERE LOS 1000

        lines = 1000; //A LINES LE ASIGNO EL NUMERO DE ARGUMENTOS MAXIMO QUE PODRA IMPRIMIR LA FUNCION
        va_start(arguments,lines); //INICIALIZO LISTA DE ARGUMENTOS VARIABLES

        char formatSpecifiers[strlen(dataType)+1]; //SE REALIZA UNA COPIA DE LA CADENA DE FORMATO PARA PODER MODIFICARLA
        strcpy(formatSpecifiers, dataType);
        xlkStrLimitedCpy(formatSpecifiers,"%scdflif"); //ESTA FUNCION SOLO DEJA EL STRING QUE CORRESPONDAN CON FORMATOS VALIDOS.

        char dataToPrint[6][1000]; //MATRIZ QUE VA GUARDANDO LOS ARGUMENTOS LEIDOS PARA LUEGO IMPRIMIRLOS.
        char dataToPrintAux[1000]; //AUXILIAR UTILIZADO PARA COPIAS.


        if( styleAux == 2) //SI EL ESTILO ES TRUE, SE IMPRIME DECORACION
        {
            printf("--------------------------------------------------------------------------------");
        }
        do
        {
            argumentsToPrint = 0;
            for(i = 0,j = 0 ; i < 6 && format != -1 ; i++ )
            {
                //LEE EL TIPO DE DATO Y VA CORTANDO LA CADENA HASTA LEER TODAS LAS MASCARAS
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

                    argumentsToPrint++; //CONTADOR DE ARGUMENTOS DETECTADOS

                    //SE GUARDA EL DATO DETECTADO COMO CADENA

                    switch(format)
                    {
                    case 1:
                        sprintf(dataToPrint[j],"%c",va_arg(arguments, int));
                        break;
                    case 2:
                        sprintf(dataToPrint[j],"%s",va_arg(arguments, char*));

                        break;
                    case 3:
                        sprintf(dataToPrint[j],"%d",va_arg(arguments, int));
                        break;
                    case 4:
                    case 5:
                        sprintf(dataToPrint[j],"%.2f",va_arg(arguments, double));
                        break;
                    case 6:
                    case 7:
                        sprintf(dataToPrint[j],"%ld",va_arg(arguments, long ));
                        break;
                    case 8:
                    case 9:
                        sprintf(dataToPrint[j],"%lld",va_arg(arguments, long long ));
                        break;
                    }
                    j++;
                }
            }
            argumentsReg += argumentsToPrint;
            if( argumentsReg <= 1000 && argumentsToPrint > 0 )
            {
                for(i = 0 ; i < argumentsToPrint ; i++ )
                {
                    printf(" "); //ESPACIO INICIAL PARA SEPARAR DATOS DEL BORDE DE LA PANTALLA
                    switch(argumentsToPrint)
                    {
                    case 1:
                        if( strlen(dataToPrint[i]) > 76)
                        {
                            //SI LA PALABRA ES DEMASIADO LARGA, LA CORTO Y EL RESTO LA IMPRIMO EN OTRA VUELTA DE ITERACION DEL FOR.

                            xlkStringSeparator(76,dataToPrint[i],dataToPrintAux);
                            printf("%-76s ", dataToPrint[i]);
                            strcpy( dataToPrint[i], dataToPrintAux);
                            flag = 1; //INDICA QUE EL FOR DEBE VOLVER A DAR LA VUELTA POR QUE UNA PALABRA ES LARGA.
                        }
                        else
                        {
                            printf("%-76s ", dataToPrint[i]);
                            dataToPrint[i][0] = '\0';
                        }
                        break;
                    case 2:
                        if( strlen(dataToPrint[i]) > 37)
                        {
                            xlkStringSeparator(37,dataToPrint[i],dataToPrintAux);
                            printf("%-37s ", dataToPrint[i]);
                            strcpy( dataToPrint[i], dataToPrintAux);
                            flag = 1;
                        }
                        else
                        {
                            printf("%-37s ", dataToPrint[i]);
                            dataToPrint[i][0] = '\0';
                        }
                        break;
                    case 3:
                        if( strlen(dataToPrint[i]) > 23)
                        {
                            xlkStringSeparator(23,dataToPrint[i],dataToPrintAux);
                            printf("%-23s ", dataToPrint[i]);
                            strcpy( dataToPrint[i], dataToPrintAux);
                            flag=1;
                        }
                        else
                        {
                            printf("%-23s ", dataToPrint[i]);
                            dataToPrint[i][0] = '\0';
                        }
                        break;
                    case 4:
                        if( strlen(dataToPrint[i]) > 17)
                        {
                            xlkStringSeparator(17,dataToPrint[i],dataToPrintAux);
                            printf("%-17s ", dataToPrint[i]);
                            strcpy( dataToPrint[i], dataToPrintAux);
                            flag=1;
                        }
                        else
                        {
                            printf("%-17s ", dataToPrint[i]);
                            dataToPrint[i][0] = '\0';
                        }
                        break;
                    case 5:
                        if( strlen(dataToPrint[i]) > 13)
                        {
                            xlkStringSeparator(13,dataToPrint[i],dataToPrintAux);
                            printf("%-13s ",dataToPrint[i]);
                            strcpy( dataToPrint[i], dataToPrintAux);
                            flag=1;
                        }
                        else
                        {
                            printf("%-13s ", dataToPrint[i]);
                            dataToPrint[i][0] = '\0';
                        }
                        break;
                    case 6:
                        if( strlen(dataToPrint[i]) > 11)
                        {
                            xlkStringSeparator(11,dataToPrint[i],dataToPrintAux);
                            printf("%-11s ",dataToPrint[i]);
                            strcpy( dataToPrint[i], dataToPrintAux);
                            flag=1;
                        }
                        else
                        {
                            printf("%-11s ", dataToPrint[i]);
                            dataToPrint[i][0] = '\0';
                        }
                        break;
                    }
                    if( flag && i == argumentsToPrint-1 )
                    {
                        printf("\n");
                        i = -1; //REINICIA EL FOR
                        flag = 0;
                    }

                }
                if( styleAux == 1 || styleAux == 2 )
                {
                    printf("\n--------------------------------------------------------------------------------");
                }
                if( styleAux == 0)
                {
                    printf("\n");
                }

            }
        }
        while( argumentsToPrint > 0);
        va_end(arguments); //CIERRE DE LISTA DE ARGUMENTOS VARIABLES
    }
}
*/

//XL1-7
/** \brief Imprime un string en el centro de la pantalla.
 *
 * \param lines[2]: Centra el texto y lo imprime con dos lineas.
 * \param lines[1]: Centra el texto y lo imprime solo con una linea inferior.
 * \param lines[0]: Centra el texto y lo imprime.
* \param word: String a imprimir centrado.
 * \return
 *
 */

void xlkCenterPrintf( char* word, int lines)
{
    int screenCenter = 30;
    int wordRef = ((strlen(word) / 2) - 1) ;
    int start = screenCenter - (wordRef - 3);
    int i;

    if(lines == 2 || lines == 1)
    {
        if( lines == 2 )
        {
            printf("--------------------------------------------------------------------------------");
        }
        for( i = 0 ; i < start ; i++)
        {
            printf(" ");
        }
        printf("<<< %s >>>\n",word);
        if(lines == 2 || lines == 1)
        {
            printf("--------------------------------------------------------------------------------");
        }
    }
    else if( lines == 0)
    {
        for( i = 0 ; i < start+5 ; i++)
        {
            printf(" ");
        }
        printf("%s\n",word);
    }

}



/** \brief Imprime tantos enter (\n) como se especifique.
 *
 * \param number : Cantidad de enters (\n) a imprimir.
 * \return
 *
 */

void xlkEnterPrinter(int number)
{
    int i;
    for( i = 0 ; i < number ; i++)
    {
        printf("\n");
    }
}



/** \brief Imprime una linea decorativa punteada o recta.
 *
 * \param recta : [0] Imprime una linea punteada. [distinto de cero] Imprime una linea recta.
 * \param recta : [distinto de cero] Imprime una linea recta.
 * \return
 *
 */

void xlkLinePrinter(int recta)
{
    if( !recta )
    {
        printf("--------------------------------------------------------------------------------");
    }
    else
    {
        printf("________________________________________________________________________________");
    }
}
