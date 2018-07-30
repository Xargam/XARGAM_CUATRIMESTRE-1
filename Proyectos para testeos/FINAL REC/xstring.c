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
void xstrNameCapsAdder(char word[])
{
    strlwr(word);
    word[0] = toupper(word[0]);
    int i;
    for( i = 0; word[i] != '\0'; i++)
    {
        if(word[i] == ' ' && word[i+1] != '\0')
        {
            word[i+1] = toupper(word[i+1]);
        }
    }
}


//XS1-2
/** \brief Recibe un vector de caracteres y elimina los espacios incorrectos que este tenga.
 *
 * \param word: palabra a corregir.
 * \return
 */

void xstrSpaceFixer(char* word)
{
    if( word != NULL )
    {
        int i, j;
        char auxWord[strlen(word)+1];

        for( i = 0,j = 0; word[i] != '\0' ; i++)
        {
            if( !(word[i] == ' ' && word[i+1] == ' ' ) && !(j == 0 && word[i] == ' ') && !(word[i+1] == '\0' && word[i] == ' ') )
            {
                auxWord[j] = word[i];
                j++;
            }
        }
        auxWord[j] = '\0';
        strcpy(word,auxWord);
    }
}



/** \brief Coloca mayuscula en la primer letra de una oracion y el resto del texto es convertido a minuscula.
 *
 * \param word : Cadena de caracteres a corregir.
 * \return
 *
 */

void xstrSentenceFixer(char* word)  //XS1-3
{
    if( word != NULL )
    {
        strlwr(word);
        word[0] = toupper(word[0]);
    }
}



/** \brief Devuelve el primer caracter imprimible (que no sea espacio) de una cadena de caracteres.
 *
 * \param word : Cadena de caracteres de donde tomar caracter.
 * \return Devuelve el caracter, en caso de error devolvera un espacio.
 *
 */

char xstrStringToChar(char* word)
{
    char character = ' ';
    if( word != NULL)
    {
        int i;
        for(i = 0 ; word[i] != '\0' ; i++)
        {
            if( isgraph(word[i]) )
            {
                printf("CHAR %c\n",word[i]);
                system("pause");
                character = word[i];
            }
        }
    }
    return character;
}
