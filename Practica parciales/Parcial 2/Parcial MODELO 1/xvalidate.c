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

void getValidDate(char text[], char errorText[],int maxYear,int MinYear,int* daySave,int* monthSave,int* yearSave)
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
 * \param minChars : cantidad minima de caracteres que puede tener la cadena.
 * \param maxChars : cantidad maxima de caracteres que puede tener la cadena.
 * \return Devuelve [1] si la cadena es valida y cumple con la cantidad de caracteres fijada o [0] si no es valida.
 *
 */

int validateStringRange(char* cad , int minChars , int maxChars)
{
    int verify = 1;
    if( strlen(cad) < minChars || strlen(cad) > maxChars)
    {
        verify = 0;
    }
    return verify ;
}
