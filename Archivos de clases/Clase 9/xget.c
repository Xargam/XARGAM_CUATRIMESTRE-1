#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "xget.h"
#include <conio.h>



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
    return verify;
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



/** \brief Recibe una cadena de caracteres y verifica que este compuesta solamente de numeros y solo un punto ubicado
 * \brief despues de la primera posicion.
 *
 * \param number: cadena de caracteres a verificar.
 * \return devuelve 1 si la cadena de caracteres solo contiene numeros o 0 si hay alguna letra.
 *
 */
int validateFIsNum(char number[])
{
    int verify = 1, pointCounter = 0, negNum = 0;
    for(int i = 0; number[i] != '\0'; i++)
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

        if(isdigit(number[i]) == 0)
        {
            if(number[i] == '-' && i == 0)
            {
                negNum++;
                continue;
            }
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



/** \brief Solicita un numero entero al usuario mayor, menor o igual a un numero y lo devuelve si y solo si es validado.
 * \brief Se validara ademas que el numero no tenga punto ni letras.
 *
 * \param refNumber: numero que se tomara como referencia para condicionar los numeros que podra ingresar el usuario.
 * \param condition 0: el usuario solo podra ingresar un numero igual al numero de referencia (refNumber).
 * \param condition menor a 0: el numero ingresado solo sera valido si es igual o menor al numero de referencia.
 * \param condition mayor a 0: el numero ingresado solo sera valido si es igual o mayor al numero de referencia.
 * \param message: mensaje mostrado al solicitar el numero al usuario.
 * \param errorMessage: mensaje mostrado en caso de error.
 *\return Devuelve el numero entero validado.
 *
 */
int getConditionedInt(int refNumber,int condition,char message[],char errorMessage[])
{
    char num[150] = {};
    int number;
    int isNum = 0;
    printf("%s",message);
    setbuf(stdin,NULL);
    scanf("%s",num);
    isNum = validateIIsNum(num);
    number = atoi(num);
    if(condition > 0)
    {
        while(number < refNumber || isNum == 0)
        {
            printf("%s",errorMessage);
            setbuf(stdin, NULL);
            scanf("%s", num);
            isNum = validateIIsNum(num);
            number = atoi(num);
        }

    }
    else if(condition == 0)
    {
        while(number != refNumber || isNum == 0)
        {
            printf("%s",errorMessage);
            setbuf(stdin, NULL);
            scanf("%s", num);
            isNum = validateIIsNum(num);
            number = atoi(num);
        }

    }
    else if(condition < 0)
    {
        while(number > refNumber || isNum == 0)
        {
            printf("%s",errorMessage);
            setbuf(stdin, NULL);
            scanf("%s", num);
            isNum = validateIIsNum(num);
            number = atoi(num);
        }
    }
    return number;
}



/** \brief Solicita un numero flotante al usuario mayor, menor o igual a un numero y lo devuelve si y solo si es validado.
 * \brief Se validara ademas que el numero no tenga puntos incorrectos y/o letras.
 *
 * \param refNumber: numero que se tomara como referencia para condicionar los numeros que podra ingresar el usuario.
 * \param condition 0: el usuario solo podra ingresar un numero igual al numero de referencia (refNumber).
 * \param condition menor a 0: el numero ingresado solo sera valido si es menor o igual al numero de referencia.
 * \param condition mayor a 0: el numero ingresado solo sera valido si es mayor o igual al numero de referencia.
 * \param message: mensaje mostrado al solicitar el numero al usuario.
 * \param errorMessage: mensaje mostrado en caso de error.
 *\return Devuelve el numero flotante solicitado validado
 *
 */
float getConditionedFloat(float refNumber,int condition,char message[],char errorMessage[])
{
    char num[150] = {};
    float number;
    int isNum = 0;
    printf("%s",message);
    setbuf(stdin,NULL);
    scanf("%s",num);
    isNum = validateFIsNum(num);
    number = atof(num);
    if(condition > 0)
    {
        while(number < refNumber || isNum == 0)
        {
            printf("%s",errorMessage);
            setbuf(stdin, NULL);
            scanf("%s", num);
            isNum = validateFIsNum(num);
            number = atof(num);
        }

    }
    else if(condition == 0)
    {
        while(number != refNumber || isNum == 0)
        {
            printf("%s",errorMessage);
            setbuf(stdin, NULL);
            scanf("%s", num);
            isNum = validateFIsNum(num);
            number = atof(num);
        }

    }
    else if(condition < 0)
    {
        while(number > refNumber || isNum == 0)
        {
            printf("%s",errorMessage);
            setbuf(stdin, NULL);
            scanf("%s", num);
            isNum = validateFIsNum(num);
            number = atof(num);
        }
    }
    return number;
}



/** \brief Pide al usuario que ingrese solo la letra f o m.
 *
 * \param text: Texto a ser mostrado al pedir letra.
 * \param errorText: Texto a mostrar en caso de no ser f o m
 * \return devuelve la letra validada.
 *
 */
char getGenre(char text[],char errorText[])
{
    char letra;
    printf("%s",text);
    letra = getch();
    while(letra != 'm' && letra != 'f')
    {
        printf("\n%s",errorText);
        letra = getche();
    }
    return letra;
}


