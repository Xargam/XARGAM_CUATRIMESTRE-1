#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//Funciones de texto:


//XS1-1
/** \brief Recibe un vector de caracteres y establece en mayuscula la primer letra de la palabra.
 *  \brief En caso de palabras compuestas añade mayuscula a cada letra inicial. UTIL PARA NOMBRES COMPUESTOS.
 *
 * \param word: palabra a modificar..
 *
 */
void xstrCapsAdder(char word[])
{
    strlwr(word);
    word[0] = toupper(word[0]);
    for(int i = 0; word[i] != '\0'; i++)
    {
        if(word[i] == ' ')
        {
            word[i+1] = toupper(word[i+1]);
        }
    }
}


//XS1-2
/** \brief recibe un vector de caracteres, coloca en mayuscula la primera letra de la primer palabra y el resto las
 * \brief reduce a minuscula. Borra espacios ilogicos (mas de 1 un espacio seguidos).
 *
 * \param word: palabra a reparar.
 *
 */

void xstrSpaceFixer(char* word)
{
    strlwr(word);
    word[0] = toupper(word[0]);
    for(int i = 0; word[i] != '\0' ; i++)
    {
        if(word[i] == ' ' && word[i+1] == ' ')
        {
            for(int j = i+2; j < 100; j++)
            {
                word[j-1] = word[j];
            }
            i--;
        }
    }
}
