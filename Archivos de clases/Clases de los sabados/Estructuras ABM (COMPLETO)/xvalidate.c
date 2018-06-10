#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "xvalidate.h"


/** \brief pide un caracter y verifica que sea la tecla ESCAPE
 *
 * \return devuelve 1 si el caracter solicitado es la tecla ESCAPE o 0 si no lo es.
 *
 */
int validateESCExit(void)
{
    int esc = 0;
    char letra;

    printf("Presione la tecla ESC para salir u otra tecla para continuar...");
    letra = getch();
    if(letra == 27)
    {
        esc++;
    }
    return esc;
}



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

    for(int i = 0;numero[i] != '\0'; i++)
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



/** \brief Imprime un texto y verifica que el caracter que ingreso el usuario sea igual al que se pasa por parametro.
 *
 * \param text: Texto a imprimir para pedir un caracter para salir.
 * \param Char: Caracter que se verificara si el usuario ingresa.
 * \return devuelve 1 si el caracter que ingresa el usuario es igual al parametro Char o 0 si no lo es.
 *
 */
int validateExit(char text[],char Char)
{
    char letra;
    int exit = 0;

    printf("%s", text);
    letra = getch();
    if(letra == Char)
    {
        exit = 1;
    }
    return exit;
}



/** \brief Establece dos caracteres posibles, uno para continuar y otro para salir. Si el usuario ingresa uno distinto
 * \brief se le vuelve a pedir el ingreso de un caracter.
 *
 * \param text: Texto mostrado al solicitar un caracter.
 * \param errorText: Texto mostrado en caso de colocar un caracter invalido.
 * \param continueChar: caracter en caso de que el usuario desee continuar en el programa.
 * \param exitChar: caracter en caso de que el usuario quiera salir del programa.
 * \return devuelve 1 si el usuario eligio el continueChar o 0 si eligio el exitChar.
 *
 */
int validateDualExit(char text[],char errorText[],char continueChar, char exitChar)
{
    char letra;
    int exit = 0;

    printf("%s", text);
    letra = getch();

    while(letra != continueChar && letra != exitChar)
    {
        printf("\n%s", errorText);
        letra = getch();

    }

    if(letra == continueChar)
    {
        exit = 1;
    }

    return exit;
}



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



/** \brief valida una fecha segun las especificaciones del usuario y la existencia de la misma.
 *
 * \param day: dia a validar.
 * \param month: mes a validar.
 * \param year: año a validar.
 * \param minYear: año minimo que puede ser el año a validar.
 * \param maxYear: año maximo que puede ser el año a validar.
 * \return Devuelve 0 si la fecha es valida o un numero menor a 0 si no lo es.
 *
 */
int validateDate(int day, int month,int year, int minYear,int maxYear)
{
    int valid = 0;
    if(year > maxYear || year < minYear || month < 1 || month > 12 || day < 1 || day > 31 )
    {
        valid--;
    }
    if(month == 4 && day > 30)
    {
        valid--;
    }
    if(month == 2 && validateLeapYear(year) == 1 && day > 29)
    {
        valid--;
    }
    if(month == 2 && validateLeapYear(year) == 0 && day > 28)
    {
        valid--;
    }
    if(month == 6 && day > 30)
    {
        valid--;
    }
    if(month == 9 && day >30)
    {
        valid--;
    }
    if(month == 11 && day > 30)
    {
        valid--;
    }
    return valid;
}
