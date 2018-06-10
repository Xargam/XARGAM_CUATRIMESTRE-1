#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



/** \brief recibe un vector de caracteres, coloca en mayuscula la primera letra de la primer palabra y el resto las
 reduce a minuscula. Borra espacios ilogicos,mas de 1 un espacio seguidos.
 *
 * \param word: palabras a reparar.
 *
 */

void xstrCapsSpaceFixer(char word[])
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



//Esto es util para trabajar con nombre propios compuestos.
/** \brief recibe un vector de caracteres y establece en mayuscula la primer letra de la palabra.
En caso de palabras compuestas añade mayuscula a cada letra inicial.
 *
 * \param word: palabra a la cual reparar espacios.
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
