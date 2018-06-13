#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>


//Funciones complemento: Validar correcta escritura de un numero:


//XG1-1
/** \brief Recibe una cadena de caracteres y verifica que este compuesta solamente de numeros.
 *
 * \param number: cadena de caracteres a verificar.
 * \return Devuelve [1] si la cadena de caracteres solo contiene numeros o [0] si hay otro tipo de caracteres en ella.
 *
 */

int validateIsNum(char* number)
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
    if(number[0] == '-' && number[1] == '\0')
    {
        verify = 0;
    }
    return verify;
}


//XG1-2
/** \brief Verifica si una cadena de caracteres puede convertirse a un numero real.
 *
 * \param number: cadena de caracteres a verificar.
 * \return Devuelve [1] si la cadena puede convertirse a un numero real o [0] si no es posible.
 *
 */

int validateIsRealNum(char* number)
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

        if(isdigit(number[i]) == 0 )
        {
            if(i == 0 && number[i] == '-' )
            {
                negNum++;
                continue;
            }
            verify = 0;
            break;
        }
    }
    if(number[0] == '-' && number[1] == '\0')
    {
        verify = 0;
    }
    return verify;
}


//XG1-2.1
/** \brief Recibe una cadena de caracteres y verifica si contiene numeros.
 *
 * \param word: cadena de caracteres a verificar.
 * \return Devuelve [1] si la cadena solo contiene letras (es alfabetica) o [0] si contiene algun numero.
 *
 */

int validateIsAlphabeticStr(char* word)
{
    int verify = 1;
    int i;
    for(i = 0 ; *(word + i) != '\0' ; i++ )
    {
        if( !isalpha(*(word+i)) )
        {
            if( word[i] == ' ')
            {
                continue;
            }
            verify = 0;
            break;
        }
    }
    return verify ;
}


//XG1-2.2
/** \brief Recibe una cadena de caracteres y verifica que contenga unicamente numeros y/o letras.
 *
 * \param word: cadena de caracteres a verificar.
 * \return Devuelve [1] si la cadena solo contiene numeros y/o letras o [0] si contiene contiene otro tipo de caracteres.
 *
 */

int validateIsAlphanumericStr(char* word)
{
    int verify = 1;
    int i;
    for(i = 0 ; word[i] != '\0' ; i++ )
    {
        if( !isalnum(word[i]) )
        {
            if( word[i] == ' ')
            {
                continue;
            }
            verify = 0;
            break;
        }
    }
    return verify ;
}


//XG1-2.3
/** \brief Recibe una cadena de caracteres y verifica que contenga caracteres imprimibles.
 *
 * \param word: cadena de caracteres a verificar.
 * \return Devuelve [1] si la cadena es imprimible o [0] si no es imprimible.
 *
 */

int validateIsGraphicStr(char* word)
{
    int verify = 1;
    int i;
    for(i = 0 ; *(word + i) != '\0' ; i++ )
    {
        if( !isgraph(word[i]) )
        {
            if( word[i] == ' ')
            {
                continue;
            }
            verify = 0;
            break;
        }
    }
    return verify ;
}


//XG1-3
/** \brief Elimina los ceros adicionales que pueda llegar a tener una cadena de caracteres con NUMEROS.
 *
 * \param number: Cadena de caracteres a la que limpiar ceros.
 * \return
 *
 */

void zeroFixer(char* number)
{
    int indicePunto = -1;
    int flag = 0;

    //Elimina los ceros delante del numero y busca el punto decimal.
    int i;
    for(i = 0; number[i] != '\0'; i++)
    {
        if(number[i] == '-')
        {
            continue;
        }

        if(number[i] == '0' && number[i+1] != '.' && flag == 0)
        {
            for(int j = i; number[j] != '\0'; j++)
            {
                number[j] = number[j+1];
            }
            i--;
            if(number[i+1] != '0')
            {
                flag++;
            }
        }
        else if(number[i] != '0' && flag == 0)
        {
            flag++;
        }

        if(number[i] == '.')
        {
            indicePunto = i;
            break;
        }
    }

    if(indicePunto != -1)
    {
        //Invierte la cadena y elimina los ceros despues de la coma luego vuelve a invertirla.
        strrev(number);
        for(i = 0; number[i] == '0'; i++)
        {
            for(int j = i; number[j] != '\0'; j++)
            {
                number[j] = number[j+1];
            }
            i--;
        }
        strrev(number);
    }

    //Si no hay nada despues del punto, este es borrado
    if(number[indicePunto+1] == '\0')
    {
        number[indicePunto] = '\0';
    }

    //Si por alguna razon se escribio el -0, el programa comete el error de borrar el 0, aca se corrige.
    if(number[0] == '-' && number[1] == '\0')
    {
        number[0] = '0';
    }
    else if(number[0] == '-' && number[1] == '0' && number[2] == '\0')
    {
        //Si por alguna razon se escribio -0.0, el programa borra el ultimo 0 y el punto y quedando el -0, aca se corrige.
        number[1] = '\0';
        number[0] = '0';
    }
    else if(number[0] == '\0')
    {
        //Si es escriben todos ceros el programa los borra aca se corrige
        number[1] = '\0';
        number[0] = '0';
    }
}


//XG1-4
/** \brief Compara dos cadenas de caracteres numericas como si fueran numeros y define cual es el mayor.
 *
 * \param number1: cadena de caracteres numericos a comparar con number2.
 * \param number2: cadena de caracteres numericos comparada con number1.
 * \return Devuelve [1] si el primer numero es mayor, [0] si ambos son iguales o [-1] si el primero es menor.
 *
 */

int strNumCmp(char* number1, char* number2)
{
    zeroFixer(number1);
    zeroFixer(number2);
    int i; // Variable de iteraciones For.
    int enteros1 = -1; // Contador de enteros del vector 1.
    int enteros2 = -1; // Contador de enteros del vector 2.
    int flagNeg = 0; // Bandera que indica signo de los numeros: 1 negativos / 0 positivos.
    int verif = 0; // Verificacion que devolvera la funcion para decir cual de los dos vectores tiene el mayor numero.
    int flagNull = 0; //Se utiliza en el ultimo for.

    //Revisa que un vector tenga signo negativo y el otro no. En ese caso ya se conoce al numero mayor.

    if(number1[0] != '-' && number2[0] == '-')
    {
        verif = 1;
    }
    else if(number1[0] == '-' && number2[0] != '-')
    {
        verif = -1;
    }
    else
    {
        //Si se  llega a este punto los dos vectores son negativos o los dos son positivos.
        //Se verifica que ambos tengan signo, en ese caso la bandera indicara que los vectores contienen numeros negativos.

        if(number1[0] == '-' && number2[0] == '-')
        {
            flagNeg++;
        }

        //Se recorren ambos vectores para contar la cantidad de numeros hasta el punto o el final del numero en caso de no haberlo.

        for(i = 0; enteros1 == -1 || enteros2 == -1 ; i++)
        {
            if(number1[i] == '\0')
            {
                //Si enteros vale -1 quiere que el num no tiene punto. Se guarda i equivalente a los nums totales.
                if(enteros1 == -1)
                {
                    enteros1 = i;
                }
            }
            if(number2[i] == '\0')
            {
                if(enteros2 == -1)
                {
                    enteros2 = i;
                }
            }
            //Revisa en busca del punto decimal y guarda el indice, que es equivalente a los nums enteros totales.
            if(number1[i] == '.')
            {
                enteros1 = i;
            }
            if(number2[i] == '.')
            {
                enteros2 = i;
            }
        }

        //Si el primer numero tiene mas enteros que el segundo es por descarte el mayor.
        //Se toma encuenta que ambos numeros pueden ser negativos por lo que el numero mas grande sera el menor

        if(enteros1 > enteros2)
        {
            if(flagNeg == 1)
            {
                verif = -1;
            }
            else
            {
                verif = 1;
            }

        }
        else if(enteros1 < enteros2)
        {
            if(flagNeg == 1)
            {
                verif = 1;
            }
            else
            {
                verif = -1;
            }
        }
        else if(enteros1 == enteros2)
        {
            /*Como  los numeros tienen igual cantidad de enteros se recorre el vector desde el numero mas significativo hasta encontrar una diferencia.
            *Si vec1 y vec2 se estan recorriendo y no se hallo el '\0' flagNull vale 0.
            *Si vec1 es '\0' es decir que no tiene mas numeros flagNull suma 1.
            *si vec2 es '\0' es decir que no tiene mas numero flagNull suma 2.
            *Si se encontro el '\0' en ambos vectores no tiene sentido seguir iterando, flag llega a valer 3 y el for
            termina. En un caso como ese los numeros son iguales ya que se llego a recorrer los numero de principio
            a fin sin salir del bucle.
            */

            for(i = 0; flagNull < 3; i++)
            {
                if(number1[i] == '\0' )
                {
                    flagNull++;

                }
                if(number2[i] == '\0')
                {
                    flagNull += 2;
                }

                if(flagNull == 0)
                {
                    if(flagNeg == 1)
                    {
                        if(number1[i] > number2[i])
                        {
                            verif = -1;
                            break;
                        }
                        else if(number1[i] < number2[i])
                        {
                            verif = 1;
                            break;
                        }
                    }
                    else
                    {
                        if(number1[i] > number2[i])
                        {
                            verif = 1;
                            break;
                        }
                        else if(number1[i] < number2[i])
                        {
                            verif = -1;
                            break;
                        }
                    }
                }

                /*Si flagNull cambio a 1 o 2 quiere decir que un numero es mas largo que otro y no se encontraron diferencias
                hasta ese entonces, por ello se establece como mayor al numero correspondiente segun el signo y se rompe
                el bucle. */

                if(flagNull == 1)
                {
                    if(flagNeg == 1)
                    {
                        verif = 1;
                        break;
                    }
                    else
                    {
                        verif = -1;
                        break;
                    }
                }
                else if(flagNull == 2)
                {
                    if(flagNeg == 1)
                    {
                        verif = -1;
                        break;
                    }
                    else
                    {
                        verif = 1;
                        break;
                    }
                }
            }
        }
    }
    return verif;
}



//Pedir string:


//XG1-5
/** \brief pide un string al usuario y lo guarda solo si cumple con la cantidad de caracteres especificada.
 *
 * \param word: cadena donde se guardara el string si es valido.
 * \param minChars Cantidad minima de caracteres del string.
 * \param maxChars Cantidad maxima de caracteres del string.
 * \param message: Mensaje a ser mostrado.
 * \param eMessage: Mensaje a ser mostrado en caso de error.
 * \param mode 1: pide un string sin limitaciones (puede contener espacios).
 * \param mode 0: pide un string limitado a una palabra (sin espacios).
 * \return Devuelve [1] si el string se valido y se guardo o [0] si no se lo pudo validar.
 *
 */

int getRangedStr(char* word,int minChars,int maxChars,char* message,char* eMessage, int mode)
{
    char palabra[1000];
    int verificacion = 1;

    if(mode)
    {
        printf("%s", message);
        scanf("%999[^\n]",palabra);
        while(getchar() != '\n');
    }
    else
    {
        printf("%s", message);
        scanf("%999s",palabra);
        while(getchar() != '\n');
    }

    if(strlen(palabra) > maxChars || strlen(palabra) < minChars)
    {
        printf("\n%s",eMessage);
        verificacion = 0;
    }
    else
    {
        strcpy(word, palabra);
    }

    return verificacion ;
}


//XG1-6
/** \brief Pide un string con una cantidad de caracteres unicamente alfabeticos especificada y lo guarda solo si es valido.
 *
 * \param word: cadena donde se guardara el string en caso de ser validado.
 * \param minChars Cantidad minima de caracteres del string.
 * \param maxChars Cantidad maxima de caracteres del string.
 * \param message: Mensaje a ser mostrado.
 * \param eMessage: Mensaje a ser mostrado en caso de error.
 * \param mode 1: pide un string sin limitaciones (puede contener espacios).
 * \param mode 0: pide un string limitado a una palabra (sin espacios).
 * \return Devuelve [0] si el string fue validado y guardado o [-1] si no pudo validarse.
 *
 */

int getRangedAlphaStr(char *word,int minChars, int maxChars, char *message,char *eMessage,int mode)
{
    char palabra[1000];
    int verificacion = 1;

    if(mode)
    {
        printf("%s", message);
        scanf("%999[^\n]",palabra);
        while(getchar() != '\n');
    }
    else
    {
        printf("%s", message);
        scanf("%999s",palabra);
        while(getchar() != '\n');
    }

    if(strlen(palabra) > maxChars || strlen(palabra) < minChars || !validateIsAlphabeticStr(palabra))
    {
        printf("\n%s",eMessage);
        verificacion = 0;
    }
    else
    {
        strcpy(word,  palabra);
    }

    return verificacion ;
}


//XG1-6.1
/** \brief Pide un string con una cantidad de caracteres unicamente alfaNumericos especificada y lo guarda solo si es valido.
 *
 * \param word: Cadena donde se guardara el string solicitado al usuario en caso de ser valido.
 * \param minChars: Cantidad minima de caracteres que puede tener el string.
 * \param maxChars: Cantidad maxima de caracteres que puede tener el string.
 * \param message: Mensaje a ser mostrado al pedir el string.
 * \param eMessage: Mensaje a ser mostrado en caso de error.
 * \param mode: [1] Pide un string no limitado de multiples palabras.
 * \param mode: [0] Pide un string limitado de una sola palabra. Lee hasta el primer espacio.
 * \return Devuelve [1] si el string se valido y se guardo o [0] si no se lo pudo validar.
 *
 */

int getRangedAlphaNumStr(char* word,int minChars, int maxChars, char* message, char* eMessage, int mode)    //XG1-6.1
{
    char palabra[1000];
    int verificacion = 1;

    if(mode)
    {
        printf("%s", message);
        scanf("%999[^\n]",palabra);
        while(getchar() != '\n');
    }
    else
    {
        printf("%s", message);
        scanf("%999s",palabra);
        while(getchar() != '\n');
    }

    if(strlen(palabra) > maxChars || strlen(palabra) < minChars || !validateIsAlphanumericStr(palabra))
    {
        printf("\n%s",eMessage);
        verificacion = 0;
    }
    else
    {
        strcpy(word,  palabra);
    }

    return verificacion ;

}


//XG1-6.2
/** \brief Pide un string con una cantidad de caracteres unicamente imprimibles especificada y lo guarda solo si es valido.
 *
 * \param word: Cadena donde se guardara el string solicitado al usuario en caso de ser valido.
 * \param minChars: Cantidad minima de caracteres que puede tener el string.
 * \param maxChars: Cantidad maxima de caracteres que puede tener el string.
 * \param message: Mensaje a ser mostrado al pedir el string.
 * \param eMessage: Mensaje a ser mostrado en caso de error.
 * \param mode: [1] Pide un string no limitado de multiples palabras.
 * \param mode: [0] Pide un string limitado de una sola palabra. Lee hasta el primer espacio.
* \return Devuelve [1] si el string se valido y se guardo o [0] si no se lo pudo validar.
 *
 */

int getRangedGraphicStr(char* word,int minChars, int maxChars, char* message, char* eMessage, int mode)
{
    char palabra[1000];
    int verificacion = 1;

    if(mode)
    {
        printf("%s", message);
        scanf("%999[^\n]",palabra);
        while(getchar() != '\n');
    }
    else
    {
        printf("%s", message);
        scanf("%999s",palabra);
        while(getchar() != '\n');
    }

    if(strlen(palabra) > maxChars || strlen(palabra) < minChars || !validateIsGraphicStr(palabra))
    {
        printf("\n%s",eMessage);
        verificacion = 0;
    }
    else
    {
        strcpy(word,  palabra);
    }

    return verificacion ;
}


//Pedir numeros o caracteres sin validar:



//XG1-7
/** \brief Solicita un entero al usuario y muestra un mensaje.
 *
 * \param texto: mensaje a ser a mostrado.
 * \return Devuelve el entero solicitado.
 *
 */

int getInt(char* texto)
{
    int number;
    printf("%s",texto);
    scanf("%d",&number);
    setbuf(stdin, NULL);
    return number;
}


//XG1-8
/** \brief Solicita un long al usuario y muestra un mensaje.
 *
 * \param texto: mensaje a ser a mostrado.
 * \return Devuelve el long solicitado.
 *
 */

long getLong(char* texto)
{
    long number;
    printf("%s",texto);
    scanf("%ld",&number);
    setbuf(stdin, NULL);
    return number;
}


//XG1-9
/** \brief Solicita un flotante al usuario y muestra un mensaje.
 *
 * \param texto: mensaje a ser a mostrado.
 * \return Devuelve el flotante solicitado.
 *
 */

float getFloat(char* texto)
{
    float number;
    printf("%s",texto);
    scanf("%f",&number);
    setbuf(stdin, NULL);
    return number;
}


//XG2-1
/** \brief Solicita un caracter al usuario y muestra un mensaje.
 *
 * \param texto: mensaje a ser a mostrado.
 * \return Devuelve el caracter solicitado.
 *
 */

char getChar(char* texto)
{
    char letra;
    printf("%s",texto);
    letra = getchar();
    setbuf(stdin, NULL);
    return letra;
}


//XG2-1.1
/** \brief Solicita un string al usuario de hasta 999 caracteres sin incluir el '\0' y muestra un mensaje.
 *
 * \param text : Texto a ser mostrado.
 * \param mode :[1] Se pide un string que puede tener espacios (multiples palabras).
 * \param mode :[0] Se pide un string que NO puede tener espacios (una palabra).
 * \return Devuelve el string solicitado.
 *
 */

char* get999String(char* text, int mode)
{
    char* string;
    char vec[1000];

    printf(text);
    if(mode)
    {
        scanf("%[^\n]",vec);
        while( getchar() != '\n');
    }
    else
    {
        scanf("%s",vec);
        while( getchar() != '\n');
    }
    string = vec;
    return string;
}


// Pedir numeros y validarlos:


//XG2-2
/** \brief Pide un numero entero al usuario y lo guarda solo si es valido. Valida rango, ausencia de punto decimal y que sus digitos sean numeros.
 *
 * \param number: puntero a entero donde guardar el numero solicitado en caso de ser valido.
 * \param message: Mensaje mostrado al pedir el entero.
 * \param errorMessage: Mensaje mostrado en caso de error.
 * \return devuelve [1] si el entero es valido o [0] si se se produce un error de validacion.
 *
 */

int getValidInt(int* number, char message[], char errorMessage[])
{
    char num[8];
    int verificacion = 1;

    printf("%s",message);
    scanf("%7s",num);
    while(getchar() != '\n');

    if(!validateIsNum(num)|| strNumCmp(num,"32767") > 0 || strNumCmp(num,"-32768") < 0)
    {
        printf("%s",errorMessage);
        verificacion = 0;
    }
    else
    {
        *number = atoi(num);
    }

    return verificacion;
}


//XG2-3
/** \brief Pide un numero long al usuario y lo guarda solo si es valido. Valida rango, ausencia de punto decimal y que sus digitos sean numeros.
 *
 * \param number: puntero a long donde guardar el numero solicitado en caso de ser valido.
 * \param message: mensaje a ser mostrado al pedir el numero.
 * \param errorMessage: mensaje a ser mostrado en caso de error.
 * \return Devuelve [1] si el long es valido o [0] si no lo es.
 *
 */

int getValidLong(long* number, char* message, char* errorMessage)
{
    int verificacion = 1;
    char num[13];
    printf("%s",message);

    scanf("%12s",num);
    while(getchar() != '\n');

    if( !validateIsNum(num)|| strNumCmp(num,"2147483647") > 0 || strNumCmp(num,"-2147483648") < 0)
    {
        printf("%s",errorMessage);
        verificacion = 0;
    }
    else
    {
        *number = atol(num);
    }
    return verificacion ;
}


//XG2-4
/** \brief Pide un numero flotante al usuario y lo guarda solo si es valido. Valida rango, cantida de puntos correcta y que sus digitos sean numeros.
 *
 * \param number: puntero a float donde guardar el numero solicitado en caso de ser valido.
 * \param message: mensaje a ser mostrado.
 * \param errorMessage: mensaje a ser mostrado en caso de error.
 * \return devuelve [1] si el flotante es valido o [0] si no lo es.
 *
 */
//Se limita el rango del flotante a pedir debido al error de rendondeo de iee754!!!!!
int getValidFloat(float* number, char* message, char* errorMessage)
{
    char num[11];
    int verificacion = 1;

    printf("%s",message);
    scanf("%10s",num);
    while(getchar() != '\n');


    if( !validateIsRealNum(num)|| strNumCmp(num,"10000000") > 0 || strNumCmp(num,"-10000000") < 0)
    {
        printf("%s",errorMessage);
        verificacion = 0;
    }
    else
    {
        *number = atof(num);
    }
    return verificacion;
}


//XG2-5
/** \brief Pide un numero long long al usuario y lo guarda solo si es valido. Valida rango, ausencia de punto decimal y que sus digitos sean numeros.
 *
 * \param number: puntero a long long donde guardar el numero solicitado en caso de ser validado
 * \param message: mensaje a ser mostrado al pedir el numero.
 * \param errorMessage: mensaje a ser mostrado en caso de error.
 * \return Devuelve [1] si el long long es valido o [0] si no lo es.
 *
 */

int getValidLongLong(long long* number, char* message, char* errorMessage)
{
    int verificacion = 1;
    char num[22];

    printf("%s",message);
    scanf("%21s",num);
    while(getchar() != '\n');

    if( !validateIsNum(num)|| strNumCmp(num,"9223372036854775807") > 0 || strNumCmp(num,"-9223372036854775808") < 0)
    {
        printf("%s",errorMessage);
        verificacion = 0;
    }
    else
    {
        *number = atoll(num);
    }

    return verificacion;
}



//Pedir numeros condicionados 1ra serie:


//XG2-6
/** \brief Solicita un numero entero correcto de un rango especifico al usuario y lo guarda solo si es valido.
 *
 * \param number: puntero a entero donde guardar el numero solicitado en caso de ser valido.
 * \param minimum: valor minimo que puede tener el numero a solicitar.
 * \param maximum: valor maximo que puede tener el numero a solicitar.
 * \param message: mensaje mostrado al usuario al solicitar el numero.
 * \param errorMessage: mensaje mostrado al usuario en caso de error.
 * \return Devuelve [1] si el entero es valido o [0] si no lo es.
 *
 */

int getRangedInt(int* number,int minimum,int maximum,char* message,char* errorMessage)
{
    char num[8];
    int auxNum;
    int verificacion = 1;

    printf("%s",message);
    scanf("%7s",num);
    while(getchar() != '\n');

    if(!validateIsNum(num)|| strNumCmp(num,"32767") > 0 || strNumCmp(num,"-32768") < 0)
    {
        verificacion = 0;
        printf("%s",errorMessage);
    }
    else
    {
        auxNum = atoi(num);
        if(auxNum < minimum || auxNum > maximum )
        {
            verificacion = 0;
            printf("%s",errorMessage);
        }
        else
        {
            *number = auxNum ;
        }
    }
    return verificacion;
}


//XG2-7
/** \brief Solicita un numero long correcto de un rango especifico al usuario y lo guarda solo si es valido.
 *
 * \param number: puntero a long donde guardar el numero solicitado en caso de ser valido.
 * \param minimum: valor minimo que puede tener el numero solicitado.
 * \param maximum: valor maximo que puede tener el numero solicitado.
 * \param message: mensaje mostrado al usuario al solicitar el numero.
 * \param errorMessage: mensaje mostrado al usuario en caso de error.
 * \return Devuelve [1] si el long es valido o [0] si no lo es.
 *
 */

int getRangedLong(long* number,long minimum,long maximum,char* message,char* errorMessage)
{
    char num[13];
    long auxNum;
    int verificacion = 1;

    printf("%s",message);
    scanf("%12s",num);
    while(getchar() != '\n');

    if(!validateIsNum(num)|| strNumCmp(num,"2147483647") > 0 || strNumCmp(num,"-2147483648") < 0)
    {
        verificacion = 0;
        printf("%s",errorMessage);
    }
    else
    {
        auxNum = atol(num);
        if(auxNum < minimum || auxNum > maximum )
        {
            verificacion = 0;
            printf("%s",errorMessage);
        }
        else
        {
            *number = auxNum ;
        }
    }
    return verificacion;
}


//XG2-8
/** \brief Solicita un numero flotante correcto de un rango especifico al usuario y lo guarda solo si es valido.
 *
 * \param number: puntero a float donde guardar el numero solicitado en caso de ser valido.
 * \param minimum: valor minimo que puede tener el numero solicitado.
 * \param maximum: valor maximo que puede tener el numero solicitado.
 * \param message: mensaje mostrado al solicitar el numero al usuario.
 * \param errorMessage: mensaje mostrado en caso de error.
 * \return Devuelve [1] si el float es valido o [0] si no lo es.
 *
 */
//Se limita el rango del flotante a pedir debido al error de rendondeo de iee754!!!!!
int getRangedFloat(float* number,float minimum,float maximum,char* message,char* errorMessage )
{
    char num[11];
    float auxNum;
    int verificacion = 1;

    printf("%s",message);
    scanf("%10s",num);
    while(getchar() != '\n');

    if(!validateIsRealNum(num)|| strNumCmp(num,"10000000") > 0 || strNumCmp(num,"-10000000") < 0)
    {
        printf("%s",errorMessage);
        verificacion = 0;
    }
    else
    {
        auxNum = atof(num);
        if(auxNum < minimum || auxNum > maximum )
        {
            printf("%s",errorMessage);
            verificacion = 0;
        }
        else
        {
            *number = auxNum ;
        }
    }

    return verificacion;
}


//XG2-8.1
/**
* \brief Solicita un caracter al usuario segun el rango establecido y lo guarda en minuscula solo si es valido. El rango no distingue mayusculas.
* \param character: Se guarda el caracter ingresado si es valido.
* \param message: Es el mensaje a ser mostrado.
* \param eMessage: Es el mensaje a ser mostrado en caso de error.
* \param minimum: Limite inferior a validar.
* \param maximum: Limite superior a validar.
* \param mode: si es 1 el caracter se guarda en minuscula y si es 0 el caracter se guarda tal como el usuario lo ingreso.
* \return Si obtuvo el caracter [1] si no [0]
*
*/

int getRangedChar(char* character,char minimum, char maximum,char* message,char* eMessage, int mode)
{
    int validation = 1;
    char auxChar ;

    printf("%s",message);
    auxChar = getche();
    if(mode)
    {
        auxChar = tolower(auxChar);
    }
    if(isupper(auxChar))
    {
        minimum = toupper(minimum);
        maximum = toupper(maximum);
        if(auxChar < minimum || auxChar > maximum)
        {
            printf("%s",eMessage);
            validation = 0;
        }
        else
        {
            *character = auxChar;
        }
    }
    else
    {
        minimum = tolower(minimum);
        maximum = tolower(maximum);
        if(auxChar < minimum || auxChar > maximum)
        {
            printf("%s",eMessage);
            validation = 0;
        }
        else
        {
            *character = auxChar;
        }
    }

    return validation;
}



//2da Serie


//XG2-9
/** \brief Solicita al usuario un numero entero correcto en un rango delimitado por el numero de referencia (refNumber).
 *
 * \param number: puntero a entero donde guardar el numero solicitado en caso de ser valido.
 * \param refNumber: numero que se tomara como referencia para condicionar los numeros que podra ingresar el usuario.
 * \param condition: igual a 0: el usuario solo podra ingresar un numero igual al numero de referencia.
 * \param condition: menor a 0: el usuario solo podra ingresar un numero igual o menor al numero de referencia.
 * \param condition: mayor a 0: el usuario solo podra ingresar un numero igual o mayor al numero de referencia.
 * \param message: mensaje mostrado al solicitar el numero.
 * \param errorMessage: mensaje mostrado en caso de error.
 * \return Devuelve [1] si el numero es valido o [0] si no lo es.
 *
 */

int getConditionedInt(int* number,int refNumber,int condition,char* message,char* errorMessage)
{
    int auxNum;
    int verificacion = 1;
    char num[8];

    printf("%s",message);
    scanf("%7s",num);
    while(getchar() != '\n');

    if(!validateIsNum(num)|| strNumCmp(num,"32767") > 0 || strNumCmp(num,"-32768") < 0 )
    {
        printf("%s",errorMessage);
        verificacion = 0;
    }
    else
    {
        auxNum = atoi(num);
        if(condition > 0)
        {
            if( auxNum < refNumber)
            {
                printf("%s",errorMessage);
                verificacion = 0;
            }
            else
            {
                *number = auxNum ;
            }
        }
        else if(condition == 0)
        {
            if(auxNum != refNumber )
            {
                printf("%s",errorMessage);
                verificacion = 0;
            }
            else
            {
                *number = auxNum;
            }
        }
        else if(condition < 0)
        {
            if(auxNum > refNumber)
            {
                printf("%s",errorMessage);
                verificacion = 0;
            }
            else
            {
                *number = auxNum;
            }
        }
    }
    return verificacion;
}


//XG3-1
/** \brief Solicita al usuario un numero float correcto en un rango delimitado por el numero de referencia (refNumber).
 *
 * \param number: puntero a float donde guardar el numero solicitado en caso de ser valido.
 * \param refNumber: numero que se tomara como referencia para condicionar los numeros que podra ingresar el usuario.
 * \param condition: igual a 0: el usuario solo podra ingresar un numero igual al numero de referencia.
 * \param condition: menor a 0: el usuario solo podra ingresar un numero igual o menor al numero de referencia.
 * \param condition: mayor a 0: el usuario solo podra ingresar un numero igual o mayor al numero de referencia.
 * \param message: mensaje mostrado al solicitar el numero.
 * \param errorMessage: mensaje mostrado en caso de error.
 * \return Devuelve [1] si el numero es valido o [0] si no lo es.
 *
 */

//Se limita el rango del flotante a pedir debido al error de rendondeo de iee754!!!!!
int getConditionedFloat(float* number, float refNumber,int condition,char* message,char* errorMessage)
{
    float auxNum;
    char num[11];
    int verificacion = 1;

    printf("%s",message);
    scanf("%10s",num);
    while(getchar() != '\n');

    if(!validateIsRealNum(num)|| strNumCmp(num,"10000000") > 0 || strNumCmp(num,"-10000000") < 0)
    {
        printf("%s",errorMessage);
        verificacion = 0;
    }
    else
    {
        auxNum = atof(num);
        if(condition > 0)
        {
            if(auxNum < refNumber)
            {
                printf("%s",errorMessage);
                verificacion = 0;
            }
            else
            {
                *number = auxNum ;
            }

        }
        else if(condition == 0)
        {
            if(auxNum != refNumber)
            {
                printf("%s",errorMessage);
                verificacion = 0;
            }
            else
            {
                *number = auxNum ;
            }

        }
        else if(condition < 0)
        {
            if(auxNum > refNumber)
            {
                printf("%s",errorMessage);
                verificacion = 0;
            }
            else
            {
                *number = auxNum;
            }
        }

    }
    return verificacion;
}


//XG3-2
/** \brief Solicita al usuario un numero long correcto en un rango delimitado por el numero de referencia (refNumber).
 *
 * \param number: puntero a long donde guardar el numero solicitado en caso de ser valido.
 * \param refNumber: numero que se tomara como referencia para condicionar los numeros que podra ingresar el usuario.
 * \param condition: igual a 0: el usuario solo podra ingresar un numero igual al numero de referencia.
 * \param condition: menor a 0: el usuario solo podra ingresar un numero igual o menor al numero de referencia.
 * \param condition: mayor a 0: el usuario solo podra ingresar un numero igual o mayor al numero de referencia.
 * \param message: mensaje mostrado al solicitar el numero.
 * \param errorMessage: mensaje mostrado en caso de error.
 * \return Devuelve [1] si el numero es valido o [0] si no lo es.
 *
 */

int getConditionedLong(long* number, long refNumber,int condition,char* message,char* errorMessage)
{
    long auxNum;
    int verificacion = 1;
    char num[13];

    printf("%s",message);
    scanf("%12s",num);
    while(getchar() != '\n');

    if(!validateIsNum(num)|| strNumCmp(num,"2147483647") > 0 || strNumCmp(num,"-2147483648") < 0 )
    {
        printf("%s",errorMessage);
        verificacion = 0;
    }
    else
    {
        auxNum = atol(num);
        if(condition > 0)
        {
            if( auxNum < refNumber)
            {
                printf("%s",errorMessage);
                verificacion = 0;
            }
            else
            {
                *number = auxNum ;
            }
        }
        else if(condition == 0)
        {
            if(auxNum != refNumber )
            {
                printf("%s",errorMessage);
                verificacion = 0;
            }
            else
            {
                *number = auxNum ;
            }

        }
        else if(condition < 0)
        {
            if( auxNum > refNumber)
            {
                printf("%s",errorMessage);
                verificacion = 0;
            }
            else
            {
                *number = auxNum ;
            }
        }
    }
    return verificacion;
}



//Otras:


//XG3-3
/** \brief Pide al usuario un caracter el cual debe ser f o m . No distingue las mayusculas.
 *
 * \param character: puntero a char donde guardar el caracter del usuario en caso de ser valido.
 * \param text: texto a ser mostrado al pedir el caracter.
 * \param errorText: texto a mostrar en caso de error.
 * \return Devuelve [1] si el caracter ingresado es (f o m) o [0] si no es.
 *
 */

int getPersonGenre(char* character, char* text,char* errorText)
{
    char letra;
    int verificacion = 1;
    printf("%s",text);
    letra = getche();
    letra = tolower(letra);
    if( letra != 'm' && letra != 'f')
    {
        printf("\n%s",errorText);
        verificacion = 0;
    }
    else
    {
        *character = letra;
    }
    return verificacion;
}
