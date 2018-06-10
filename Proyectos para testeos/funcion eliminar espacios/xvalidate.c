#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


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
