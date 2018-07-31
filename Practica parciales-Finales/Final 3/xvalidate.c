#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>


//Validacion de salida:


//XV1-1//
/** \brief pide un caracter y verifica que sea la tecla ESCAPE
 *
 * \return devuelve [1] si el caracter solicitado es la tecla ESCAPE o [0] si no lo es.
 *
 */

int validateESCExit(char* text)
{
    int esc = 1;
    char letra;

    printf("%s",text);
    letra = getch();
    if(letra != 27)
    {
        esc = 0;
    }
    return esc;
}


//XV1-2//
/** \brief Imprime un texto y verifica que el caracter que ingreso el usuario sea igual al que se pasa por parametro.
 *
 * \param text: Texto a imprimir para pedir un caracter para salir.
 * \param Char: Caracter que se verificara si el usuario ingresa.
 * \return devuelve 1 si el caracter que ingreso el usuario es igual al parametro Char o 0 si no lo es.
 *
 */

int validateExit(char* text,char Char)
{
    char letra;
    int exit = 0;

    printf("%s", text);
    letra = getch();
    letra = tolower(letra);
    Char = tolower(Char);

    if(letra == Char)
    {
        exit = 1;
    }
    return exit;
}


//XV1-3//
/** \brief Establece dos caracteres posibles, uno para continuar y otro para salir.
 *
 * \param text: Texto mostrado al solicitar un caracter.
 * \param errorText: Texto mostrado en caso de colocar un caracter invalido.
 * \param continueChar: caracter en caso de que el usuario desee continuar en el programa.
 * \param exitChar: caracter en caso de que el usuario quiera salir del programa.
 * \return devuelve 1 si el usuario eligio el continueChar o 0 si eligio el exitChar.
 *
 */
int validateDualExit(char* text,char* errorText,char continueChar, char exitChar)
{
    char letra;
    int exit = 0;
    continueChar = tolower(continueChar);
    exitChar = tolower(exitChar);

    do
    {
        printf("* %s", text);
        letra = getch();
        letra = tolower(letra);
        if(letra != continueChar && letra != exitChar)
        {
            printf("\n** %s\n\n", errorText);
        }
    }
    while(letra != continueChar && letra != exitChar);

    if(letra == continueChar)
    {
        exit = 1;
    }

    return exit;
}



//Dependencias validacion de fechas:


//XV1-4//
/** \brief verifica si un año es bisiesto
 *
 * \param year: año a verificar.
 * \return devuelve 1 si el año es bisiesto o 0 si no lo es.
 *
 */
int validateLeapYear(int year)
{
    int leap = 0;
    if(year % 4 == 0 &&( year % 100 != 0 || year % 400 ==0))
    {
        leap = 1;
    }
    return leap;
}


//XV1-5//
/** \brief valida una fecha segun las especificaciones del usuario y la existencia de la misma.
 *
 * \param day: dia a validar.
 * \param month: mes a validar.
 * \param year: año a validar.
 * \param minYear: año minimo que puede ser el año a validar.
 * \param maxYear: año maximo que puede ser el año a validar.
 * \return Devuelve [1] si la fecha es valida o [0] si no lo es.
 *
 */
int validateDate(int day, int month,int year, int minYear,int maxYear)
{
    int valid = 1;
    if(year > maxYear || year < minYear || month < 1 || month > 12 || day < 1 || day > 31 )
    {
        valid = 0;
    }
    if(month == 4 && day > 30)
    {
        valid = 0;
    }
    if(month == 2 && validateLeapYear(year) == 1 && day > 29)
    {
        valid = 0;
    }
    if(month == 2 && validateLeapYear(year) == 0 && day > 28)
    {
        valid = 0;
    }
    if(month == 6 && day > 30)
    {
        valid = 0;
    }
    if(month == 9 && day >30)
    {
        valid = 0;
    }
    if(month == 11 && day > 30)
    {
        valid = 0;
    }
    return valid;
}



/** \brief Verifica que una cadena contenga caracteres del 0 al 9 unicamente.
 *
 * \param cad : Cadena a revisar.
 * \return Devuelve [1] si la cadena es numerica o [0] si no lo es.
 *
 */

int validateIsNumericStr(char* cad)
{
    int i;
    int verify = 1;
    for( i = 0 ; cad[i] != '\0' ; i++ )
    {
        if( !isdigit(cad[i]) )
        {
            verify = 0;
            break;
        }
    }
    return verify;
}



//Validacion de fechas:


//XV1-6//
/** \brief Pide una fecha validando que este en un determinado rango de años y que realmente pueda existir o haya existido. Pide la fecha hasta ser validada correctamente.
 *
 * \param text: Texto a ser mostrado al pedir la fecha.
 * \param errorText: Texto a ser mostrado en caso de ser la fecha invalida.
 * \param maxYear: año maximo considerado al validar la fecha.
 * \param minYear: año minimo considerado al validar la fecha.
 * \param daySave: variable entera donde guardar el dia validado.
 * \param monthSave: variable entera donde guardar el mes validado.
 * \param yearSave: variable entera donde guardar el año validado.
 * \return
 *
 */

void validate_getValidDate(char text[], char errorText[],int maxYear,int MinYear,int* daySave,int* monthSave,int* yearSave)
{
    int day, month, year;
    printf("%s",text);
    scanf("%d%d%d",&day,&month,&year);
    while(getchar() != '\n');

    while(validateDate(day,month,year,MinYear,maxYear) < 0)
    {
        printf("%s\n",errorText);
        scanf("%d%d%d",&day,&month,&year);
        while(getchar() != '\n');

    }
    *daySave = day;
    *monthSave = month;
    *yearSave = year;
}



/** \brief verifica que un horario sea correcto.
 *
 * \param time : Cadena con horario a validar.
 * \param better: Si se coloca un cero se consideran validos: 20 25 , 1 25 ...En caso contrario el formato solo será 07:25 .
 * \return Devuelve [1] si el horario es correcto o [0] si no lo es.
 *
 */

int validateIsCorrectTime(char* time,int better )
{
    int verify = 0;

    if( time != NULL && ( (better && strlen(time) == 5) || (!better && strlen(time) < 6)  ) )
    {
        char auxCad[10];
        switch( strlen(time))
        {
        case 3:
            if( validateIsNumericStr(time) )
            {
                auxCad[0] = time[1];
                auxCad[1] = time[2];
                auxCad[2] = '\0';
                if( atoi(auxCad) < 60)
                {
                    verify = 1;
                }
            }
            break;
        case 4:
            auxCad[0] = time[0];
            auxCad[1] = time[2];
            auxCad[2] = time[3];
            auxCad[3] = '\0';
            if( validateIsNumericStr(auxCad) &&( time[1] == ':' || isdigit(time[1]) ) )
            {
                if( time[1] == ':' )
                {
                    auxCad[0] = time[3];
                    auxCad[1] = time[2];
                    auxCad[2] = '\0';
                    if( atoi(auxCad) < 60)
                    {
                        verify = 1;
                    }
                }
                else
                {
                    auxCad[0] = time[0];
                    auxCad[1] = time[1];
                    auxCad[2] = '\0';
                    if( atoi(auxCad) < 24)
                    {
                        auxCad[0] = time[2];
                        auxCad[1] = time[3];
                        auxCad[2] = '\0';
                        if( atoi(auxCad) < 60)
                        {
                            verify = 1;
                        }
                    }
                }
            }

            break;
        case 5:
            auxCad[0] = time[0];
            auxCad[1] = time[1];
            auxCad[2] = time[3];
            auxCad[3] = time[4];
            auxCad[4] = '\0';
            if( validateIsNumericStr(auxCad) && time[2] == ':' )
            {
                auxCad[0] = time[0];
                auxCad[1] = time[1];
                auxCad[2] = '\0';
                if( atoi(auxCad) < 24)
                {
                    auxCad[0] = time[3];
                    auxCad[1] = time[4];
                    auxCad[2] = '\0';
                    if( atoi(auxCad) < 60)
                    {
                        verify = 1;
                    }
                }

            }
            break;
        }
    }
    return verify;
}



//Validacion numeros:


//XV1-7//
/** \brief Verifica que un numero flotante tenga o no decimales.
 *
 * \param num: Es el numero flotante a verificar.
 * \return devuelve 1 si el numero tiene decimales o 0 si no tiene.
 *
 */
int validateHasDecimals(float num)
{
    int comprobacion = 0, flag = 0;

    char numero[1000];

    sprintf(numero,"%f", num);
    printf("Conversion a cadena: %s\n",numero);

    for(int i = 0; numero[i] != '\0'; i++)
    {
        if(numero[i] == '.')
        {
            flag++;
        }

        if(flag == 1 && numero[i] > '0')
        {
            comprobacion++;
            break;
        }

    }
    return comprobacion;
}



//Validacion de numeros:


//XV1-8
/** \brief Recibe un entero y verifica que este se encuentre dentro de un rango especifico.
 *
 * \param number : Numero entero a verificar.
 * \param minNumber: Numero entero minimo del rango a fijar.
 * \param maxNumber: Numero entero maximo del rango a fijar.
 * \return Devuelve [1] si el numero es valido y esta en rango o [0] si el numero esta fuera de rango.
 *
 */
int validateIntRange(int number,int minNumber, int maxNumber)
{
    int verify = 1;
    if(number < minNumber || number > maxNumber )
    {
        verify = 0;
    }
    return verify;
}


//XV1-9
/** \brief Recibe un long y verifica que este se encuentre dentro de un rango especifico.
 *
 * \param number : Numero long a verificar.
 * \param minNumber: Numero long minimo del rango a fijar.
 * \param maxNumber: Numero long maximo del rango a fijar.
 * \return Devuelve [1] si el numero es valido y esta en rango o [0] si el numero esta fuera de rango.
 *
 */

int validateLongRange(long number,long minNumber, long maxNumber)
{
    int verify = 1;
    if(number < minNumber || number > maxNumber )
    {
        verify = 0;
    }
    return verify;
}


//XV2-1
/** \brief Recibe un float y verifica que este se encuentre dentro de un rango especifico.
 *
 * \param number : Numero float a verificar.
 * \param minNumber: Numero float minimo del rango a fijar.
 * \param maxNumber: Numero float maximo del rango a fijar.
 * \return Devuelve [1] si el numero es valido y esta en rango o [0] si el numero esta fuera de rango.
 *
 */

int validateFloatRange(float number,float minNumber, float maxNumber)
{
    int verify = 1;
    if(number < minNumber || number > maxNumber )
    {
        verify = 0;
    }
    return verify;
}


//XV2-2
/** \brief Recibe un entero y verifica que este cumpla la condicion establecida respecto al numero de referencia.
 *
 * \param number : Numero entero a verificar.
 * \param refNumber: Numero entero que se toma como referencia para establecer un rango.
 * \param condition:[mayor a 0] Se verificara que el numero(number) sea MAYOR o IGUAL al numero de referencia(refNumber).
 * \param condition:[0] Se verificara que el numero(number) sea IGUAL al numero de referencia(refNumber).
 * \param condition:[menor a 0] Se verificara que el numero(number) sea MENOR o IGUAL al numero de referencia(refNumber).
 * \return Devuelve [1] si el numero es valido y cumple la condicion establecida o [0] si no la cumple.
 *
 */

int validateIntCondition(int number,int refNumber, int condition)
{
    int verify = 1;

    if( condition > 0)
    {
        if(number < refNumber )
        {
            verify = 0;
        }
    }
    else if(condition == 0)
    {
        if(number != refNumber )
        {
            verify = 0;
        }
    }
    else if(condition < 0)
    {
        if(number > refNumber )
        {
            verify = 0;
        }
    }
    return verify;
}


//XV2-3
/** \brief Recibe un long y verifica que este cumpla la condicion establecida respecto al numero de referencia.
 *
 * \param number : Numero long a verificar.
 * \param refNumber: Numero long que se toma como referencia para establecer un rango.
 * \param condition:[mayor a 0] Se verificara que el numero(number) sea MAYOR o IGUAL al numero de referencia(refNumber).
 * \param condition:[0] Se verificara que el numero(number) sea IGUAL al numero de referencia(refNumber).
 * \param condition:[menor a 0] Se verificara que el numero(number) sea MENOR o IGUAL al numero de referencia(refNumber).
 * \return Devuelve [1] si el numero es valido y cumple la condicion establecida o [0] si no la cumple.
 *
 */

int validateLongCondition(long number,long refNumber, int condition)
{
    int verify = 1;

    if( condition > 0)
    {
        if(number < refNumber )
        {
            verify = 0;
        }
    }
    else if(condition == 0)
    {
        if(number != refNumber )
        {
            verify = 0;
        }
    }
    else if(condition < 0)
    {
        if(number > refNumber )
        {
            verify = 0;
        }
    }
    return verify;
}


//XV2-4
/** \brief Recibe un float y verifica que este cumpla la condicion establecida respecto al numero de referencia.
 *
 * \param number : Numero float a verificar.
 * \param refNumber: Numero float que se toma como referencia para establecer un rango.
 * \param condition:[mayor a 0] Se verificara que el numero(number) sea MAYOR o IGUAL al numero de referencia(refNumber).
 * \param condition:[0] Se verificara que el numero(number) sea IGUAL al numero de referencia(refNumber).
 * \param condition:[menor a 0] Se verificara que el numero(number) sea MENOR o IGUAL al numero de referencia(refNumber).
 * \return Devuelve [1] si el numero es valido y cumple la condicion establecida o [0] si no la cumple.
 *
 */

int validateFloatCondition(float number,float refNumber, int condition)
{
    int verify = 1;

    if( condition > 0)
    {
        if(number < refNumber )
        {
            verify = 0;
        }
    }
    else if(condition == 0)
    {
        if(number != refNumber )
        {
            verify = 0;
        }
    }
    else if(condition < 0)
    {
        if(number > refNumber )
        {
            verify = 0;
        }
    }
    return verify;
}



//Validacion de string:


 //XV2-5
/** \brief Recibe una cadena de caracteres y verifica que cumpla con cierta cantidad de caracteres.
 *
 * \param cad : Cadena a verificar.
 * \param minChars : Cantidad minima de caracteres de la cadena.
 * \param maxChars : Cantidad maxima de caracteres de la cadena.
 * \return Devuelve [1] si la cadena es valida y cumple con la cantidad de caracteres fijada o [0] si no es valida.
 *
 */

int validateStringRange(char* cad , int minChars , int maxChars )
{
    int verify = 1;
    int chars = strlen(cad);
    if( chars < minChars || chars > maxChars)
    {
        verify = 0;
    }
    return verify ;
}



/** \brief Recibe una cadena de caracteres y verifica que contenga unicamente numeros y/o letras.
 *
 * \param word: cadena de caracteres a verificar.
 * \return Devuelve [1] si la cadena solo contiene numeros y/o letras o [0] si contiene contiene otro tipo de caracteres.
 *
 */

int validateIsAlphanumericStr(char* word)
{
    int verify = 1;
    int i;
    for(i = 0 ; word[i] != '\0' ; i++ )
    {
        if( !isalnum(word[i]) )
        {
            if( word[i] == ' ')
            {
                continue;
            }
            verify = 0;
            break;
        }
    }
    return verify ;
}



/** \brief Recibe una cadena de caracteres y verifica si contiene numeros.
 *
 * \param word: cadena de caracteres a verificar.
 * \return Devuelve [1] si la cadena solo contiene letras (es alfabetica) o [0] si contiene algun numero.
 *
 */

int validateIsAlphabeticStr(char* word)
{
    int verify = 1;
    int i;
    for(i = 0 ; *(word + i) != '\0' ; i++ )
    {
        if( !isalpha(*(word+i)) )
        {
            if( word[i] == ' ')
            {
                continue;
            }
            verify = 0;
            break;
        }
    }
    return verify ;
}



/** \brief Recibe una cadena de caracteres y verifica que contenga caracteres imprimibles.
 *
 * \param word: cadena de caracteres a verificar.
 * \return Devuelve [1] si la cadena es imprimible o [0] si no es imprimible.
 *
 */

int validateIsGraphicStr(char* word)
{
    int verify = 1;
    int i;
    for(i = 0 ; *(word + i) != '\0' ; i++ )
    {
        if( !isprint(word[i]) )
        {
            verify = 0;
            break;
        }
    }
    return verify ;
}



/** \brief Recibe una cadena de caracteres y verifica que este compuesta solamente de numeros.
 *
 * \param number: cadena de caracteres a verificar.
 * \return Devuelve [1] si la cadena de caracteres solo contiene numeros o [0] si hay otro tipo de caracteres en ella.
 *
 */

int validateIsNum(char* number)
{
    int verify = 1;
    int i;
    for( i = 0; number[i] != '\0'; i++)
    {
        if(isdigit(number[i])== 0)
        {
            if(number[i] == '-' && i == 0)
            {
                continue;
            }
            verify = 0;
            break;
        }
    }
    if(number[0] == '-' && number[1] == '\0')
    {
        verify = 0;
    }
    return verify;
}



/** \brief Verifica si una cadena de caracteres puede convertirse a un numero real.
 *
 * \param number: cadena de caracteres a verificar.
 * \return Devuelve [1] si la cadena puede convertirse a un numero real o [0] si no es posible.
 *
 */

int validateIsRealNum(char* number)
{
    int verify = 1, pointCounter = 0, negNum = 0;

    int i;
    for( i = 0; number[i] != '\0'; i++)
    {
        if(number[i] == '.' && i == 1 && negNum == 1)
        {
            verify = 0;
            break;
        }
        if(number[i] == '.' && i > 0 && pointCounter == 0 )
        {
            pointCounter++;
            continue;
        }

        if(isdigit(number[i]) == 0 )
        {
            if(i == 0 && number[i] == '-' )
            {
                negNum++;
                continue;
            }
            verify = 0;
            break;
        }
    }
    if(number[0] == '-' && number[1] == '\0')
    {
        verify = 0;
    }
    return verify;
}
