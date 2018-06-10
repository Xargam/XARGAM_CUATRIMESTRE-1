#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/** \brief pide un string al usuario que no conste de espacios, muestra un mensaje, lo valida y lo guarda
 *
 * \param vec: vector donde se guarda el caracter
 * \param message: Mensaje al ser mostrado
 * \param eMessage: Mensaje en caso de error
 * \param minChars Cantidad minima de caracteres del string
 * \param maxChars Cantidad maxima de caracteres del string
 * \return
 *
 */

void getRangedSimStr(char* vec,char message[],char eMessage[],int minChars, int maxChars)
{
    char palabra[1000];
    printf("%s", message);
    scanf("%s",palabra);
    while(getchar()!='\n');
    while(strlen(palabra) > maxChars || strlen(palabra) < minChars)
    {
        printf("%s",eMessage);
        scanf("%s",palabra);
        while(getchar()!='\n');
    }
    strcpy(vec,  palabra);
}



/** \brief pide un string al usuario, muestra un mensaje, lo valida y lo guarda
 *
 * \param vec: vector donde se guarda el caracter
 * \param message: Mensaje al ser mostrado
 * \param eMessage: Mensaje en caso de error
 * \param minChars Cantidad minima de caracteres del string
 * \param maxChars Cantidad maxima de caracteres del string
 * \return
 *
 */

void getRangedStr(char* vec,char message[],char eMessage[],int minChars, int maxChars)
{
    char palabra[1000];
    printf("%s", message);
    setbuf(stdin,NULL);
    scanf("%[^\n]",palabra);
    setbuf(stdin,NULL);
    while(strlen(palabra) > maxChars || strlen(palabra) < minChars)
    {
        printf("%s",eMessage);
        scanf("%[^\n]",palabra);
        setbuf(stdin,NULL);
    }
    strcpy(vec,  palabra);
}



/** \brief solicita un entero y muestra un mensaje.
 *
 * \param texto: mensaje a ser a mostrado.
 * \return devuelve el entero antes solicitado
 *
 */
int getInt(char texto[])
{
    int number;
    printf("%s",texto);
    setbuf(stdin, NULL);
    scanf("%d",&number);
    setbuf(stdin, NULL);
    return number;
}



/** \brief solicita un flotante y muestra un mensaje
 *
 * \param texto: mensaje a ser a mostrado.
 * \return devuelve el flotante antes solicitado
 *
 */
float getFloat(char texto[])
{
    float number;
    printf("%s",texto);
    setbuf(stdin, NULL);
    scanf("%f",&number);
    setbuf(stdin, NULL);
    return number;
}



/** \brief solicita un caracter y muestra un mensaje
 *
 * \param texto: mensaje a ser a mostrado.
 * \return devuelve el caracter antes solicitado.
 *
 */
char getChar(char texto[])
{
    char letra;
    printf("%s",texto);
    setbuf(stdin, NULL);
    letra = getchar();
    setbuf(stdin, NULL);
    return letra;
}



/** \brief Solicita un numero entero al usuario y lo devuelve si y solo si es validado.
 *
 * \param minimum: valor minimo que puede tener el numero que elige el usuario
 * \param maximum: valor maximo que puede tener el numero que elige el usuario
 * \param message: mensaje mostrado al solicitar el numero al usuario
 * \param errorMessage: mensaje mostrado si el usuario escribio un numero fuera de rango
 *\return Devuelve el numero entero solicitado validado
 *
 */
int getRangedInt(int minimum,int maximum,char message[],char errorMessage[] )
{
    int num;
    printf("%s",message);
    setbuf(stdin, NULL);
    scanf("%d",&num);
    setbuf(stdin, NULL);
    while(num < minimum || num > maximum)
    {
        printf("%s",errorMessage);
        scanf("%d", &num);
        setbuf(stdin, NULL);

    }
    return num;
}



/** \brief Solicita un numero flotante al usuario y lo devuelve si y solo si es validado.
 *
 * \param minimum: valor minimo que puede tener el numero que elige el usuario
 * \param maximum: valor maximo que puede tener el numero que elige el usuario
 * \param message: mensaje mostrado al solicitar el numero al usuario
 * \param errorMessage: mensaje mostrado si el usuario escribio un numero fuera de rango
 * \return Devuelve el numero flotante solicitado validado
 *
 */
float getRangedFloat(float minimum,float maximum,char message[],char errorMessage[] )
{
    float num;
    printf("%s",message);
    setbuf(stdin, NULL);
    scanf("%f",&num);
    setbuf(stdin, NULL);
    while(num < minimum || num > maximum)
    {
        printf("%s",errorMessage);
        scanf("%f", &num);
        setbuf(stdin, NULL);
    }
    return num;
}


