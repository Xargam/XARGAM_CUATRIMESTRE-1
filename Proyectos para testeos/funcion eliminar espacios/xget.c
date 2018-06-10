#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



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
void getRangedSimStr(int minChars, int maxChars,char message[],char eMessage[],char vec[])
{
    char palabra[1000];
    printf("%s", message);
    while(getchar()!='\n');
    scanf("%s",palabra);

    while(strlen(palabra) > maxChars || strlen(palabra) < minChars)
    {
        printf("%s",eMessage);
        while(getchar()!='\n');
        scanf("%s",palabra);
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
void getRangedStr(int minChars,int maxChars,char message[],char eMessage[],char vec[] )
{
    char palabra[1000];
    printf("%s", message);
    setbuf(stdin,NULL);
    scanf("%[^\n]",palabra);
    while(strlen(palabra) > maxChars || strlen(palabra) < minChars)
    {
        printf("%s",eMessage);
        setbuf(stdin,NULL);
        scanf("%[^\n]",palabra);

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
    return letra;
}



/** \brief Solicita un numero entero al usuario y lo devuelve si y solo si es validado. Verifica que el
 *\brief numero no tenga letras.
 *
 * \param minimum: valor minimo que puede tener el numero que elige el usuario
 * \param maximum: valor maximo que puede tener el numero que elige el usuario
 * \param message: mensaje mostrado al solicitar el numero al usuario
 * \param errorMessage: mensaje mostrado si el usuario escribio un numero fuera de rango
 *\return Devuelve el numero entero solicitado validado
 *
 */
int getRangedInt(int minimum,int maximum,char message[],char errorMessage[])
{
    char num[150] = {};
    int number;
    int isNum = 0;
    printf("%s",message);
    setbuf(stdin,NULL);
    scanf("%s",num);
    isNum = validateIIsNum(num);
    number = atoi(num);
    while(number < minimum || number > maximum || isNum == 0)
    {
        printf("%s",errorMessage);
        setbuf(stdin, NULL);
        scanf("%s", num);
        isNum = validateIIsNum(num);
        number = atoi(num);
    }
    return number;
}



/** \brief Recibe una cadena de caracteres y verifica que este compuesta solamente de numeros.
 *
 * \param number: cadena de caracteres a verificar.
 * \return devuelve 1 si la cadena de caracteres solo contiene numeros o 0 si hay alguna letra.
 *
 */
int validateIIsNum(char number[])
{
    int verify = 1;
    for(int i = 0; number[i] != '\0'; i++)
    {
        if(isdigit(number[i]) == 0)
        {
            verify = 0;
            break;
        }
    }
    return verify;
}



/** \brief Recibe una cadena de caracteres y verifica que este compuesta solamente de numeros y solo un punto ubicado
 * \brief despues de la primera posicion.
 *
 * \param number: cadena de caracteres a verificar.
 * \return devuelve 1 si la cadena de caracteres solo contiene numeros o 0 si hay alguna letra.
 *
 */
int validateFIsNum(char number[])
{
    int verify = 1, pointCounter = 0;
    for(int i = 0; number[i] != '\0'; i++)
    {
        if(number[i] == '.' && i == 0)
        {
            verify = 0;
            break;
        }
        else if(number[i] == '.' && pointCounter == 0)
        {
            pointCounter++;
        }
        else if(number[i] == '.' && pointCounter > 0)
        {
            verify = 0;
            break;
        }


        if(isdigit(number[i]) == 0 && number[i] != '.')
        {
            verify = 0;
            break;
        }
    }
    return verify;
}



/** \brief Solicita un numero flotante al usuario y lo devuelve si y solo si es validado
 * \brief y no contiene puntos invalidos o letras.
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
    char num[150] = {};
    int isNum = 0;
    float number;
    printf("%s",message);

    setbuf(stdin, NULL);
    scanf("%s",num);
    isNum = validateFIsNum(num);
    number = atof(num);

    while(number < minimum || number > maximum || isNum == 0)
    {
        printf("%s",errorMessage);
        setbuf(stdin, NULL);
        scanf("%s",num);
        isNum = validateFIsNum(num);
        number = atof(num);

    }
    return number;
}



/** \brief pide un flotante al usuario correctamente escrito, sin letras ni puntos invalidos.
 *
 * \param message: Mensaje a ser mostrado.
 * \param errorMessage: Mensaje a ser mostrado en caso de error.
 * \return devuelve el flotante validado.
 *
 */
float getValidFloat(char message[], char errorMessage[])
{
    char num[150] = {};
    int isNum = 0;
    float number;

    printf("%s",message);
    setbuf(stdin, NULL);
    scanf("%s",num);
    isNum = validateFIsNum(num);
    number = atof(num);

    while(isNum == 0)
    {
        printf("%s",errorMessage);
        setbuf(stdin, NULL);
        scanf("%s",num);
        isNum = validateFIsNum(num);
        number = atof(num);
    }
    return number;
}




/** \brief pide un entero al usuario correctamente escrito, sin letras ni puntos.
 *
 * \param message: Mensaje mostrado al pedir el entero.
 * \param errorMessage: Mensaje mostrado en caso de error.
 * \return devuelve el entero validado.
 *
 */
int getValidInt(char message[], char errorMessage[])
{
    char num[150] = {};
    int number;
    int isNum = 0;
    printf("%s",message);
    setbuf(stdin,NULL);
    scanf("%s",num);
    isNum = validateIIsNum(num);
    number = atoi(num);
    while(isNum == 0)
    {
        printf("%s",errorMessage);
        setbuf(stdin, NULL);
        scanf("%s", num);
        isNum = validateIIsNum(num);
        number = atoi(num);
    }
    return number;
}

