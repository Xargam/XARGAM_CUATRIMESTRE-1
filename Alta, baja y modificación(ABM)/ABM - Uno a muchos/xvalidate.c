#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


//Validacion de salida:


//XV1-1//
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


//XV1-2//
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


//XV1-3//
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
    while(getchar() != '\n');
    scanf("%d%d%d",&day,&month,&year);

    while(validateDate(day,month,year,MinYear,maxYear) < 0)
    {
        printf("%s\n",errorText);
        while(getchar() != '\n');
        scanf("%d%d%d",&day,&month,&year);

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
