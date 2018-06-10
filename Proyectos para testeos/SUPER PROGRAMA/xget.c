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
 * \return devuelve 1 si la cadena de caracteres solo contiene numeros o 0 si hay alguna letra.
 *
 */

int validateIsNum(char num[])
{
    int verify = 1;
    for(int i = 0; num[i] != '\0'; i++)
    {
        if(isdigit(num[i])== 0)
        {
            if(num[i] == '-' && i == 0)
            {
                continue;
            }
            verify = 0;
            break;
        }
    }
    if(num[0] == '-' && num[1] == '\0')
    {
        verify = 0;
    }
    return verify;
}


//XG1-2
/** \brief Recibe una cadena de caracteres y verifica que este compuesta solamente de numeros y solo un punto ubicado
 * \brief despues de la primera posicion.
 *
 * \param number: cadena de caracteres a verificar.
 * \return devuelve 1 si la cadena de caracteres solo contiene numeros o 0 si hay alguna letra.
 *
 */

int validateIsRealNum(char* num)
{
    int verify = 1, pointCounter = 0, negNum = 0;

    for(int i = 0; num[i] != '\0'; i++)
    {
        if(num[i] == '.' && i == 1 && negNum == 1)
        {
            verify = 0;
            break;
        }
        if(num[i] == '.' && i > 0 && pointCounter == 0 )
        {
            pointCounter++;
            continue;
        }

        if(isdigit(num[i]) == 0)
        {
            if(num[i] == '-' && i == 0)
            {
                negNum++;
                continue;
            }
            verify = 0;
            break;
        }
    }
    if(num[0] == '-' && num[1] == '\0')
    {
        verify = 0;
    }
    return verify;
}


//XG1-3
/** \brief Elimina los ceros adicionales que pueda llegar a tener una cadena de caracteres con numeros.
 *
 * \param vec: Cadena de caracteres donde limpiar ceros.
 * \return
 *
 */

void zeroFixer(char* vec)
{
    int indicePunto = -1;
    int flag = 0;

    //Elimina los ceros delante del numero y busca el punto decimal.
    int i;
    for(i = 0; vec[i] != '\0'; i++)
    {
        if(vec[i] == '-')
        {
            continue;
        }

        if(vec[i] == '0' && vec[i+1] != '.' && flag == 0)
        {
            for(int j = i; vec[j] != '\0'; j++)
            {
                vec[j] = vec[j+1];
            }
            i--;
            if(vec[i+1] != '0')
            {
                flag++;
            }
        }
        else if(vec[i] != '0' && flag == 0)
        {
            flag++;
        }

        if(vec[i] == '.')
        {
            indicePunto = i;
            break;
        }
    }

    if(indicePunto != -1)
    {
        //Invierte la cadena y elimina los ceros despues de la coma luego vuelve a invertirla.
        strrev(vec);
        for(i = 0; vec[i] == '0'; i++)
        {
            for(int j = i; vec[j] != '\0'; j++)
            {
                vec[j] = vec[j+1];
            }
            i--;
        }
        strrev(vec);
    }

    //Si no hay nada despues del punto, este es borrado
    if(vec[indicePunto+1] == '\0')
    {
        vec[indicePunto] = '\0';
    }

    //Si por alguna razon se escribio el -0, el programa comete el error de borrar el 0, aca se corrige.
    if(vec[0] == '-' && vec[1] == '\0')
    {
        vec[0] = '0';
    }
    else if(vec[0] == '-' && vec[1] == '0' && vec[2] == '\0')
    {
        //Si por alguna razon se escribio -0.0, el programa borra el ultimo 0 y el punto y quedando el -0, aca se corrige.
        vec[1] = '\0';
        vec[0] = '0';
    }
    else if(vec[0] == '\0')
    {
        //Si es escriben todos ceros el programa los borra aca se corrige
        vec[1] = '\0';
        vec[0] = '0';
    }
}


//XG1-4
/** \brief Compleja funcion capaz de comparar numeros en cadena de caracteres de infinitas cifras.
 *
 * \param vec1: Vector de caracteres numericos a comparar con vec2.
 * \param  vec2: Vector de caracteres numericos a comparar con vec1.
 * \return Devuelve 0 si los numeros son iguales, -1 si el primero es menor o 1 si el primero es mayor.
 *
 */

int strNumCmp(char vec1[], char vec2[])
{
    zeroFixer(vec1);
    zeroFixer(vec2);
    int i; // Variable de iteraciones For.
    int enteros1 = -1; // Contador de enteros del vector 1.
    int enteros2 = -1; // Contador de enteros del vector 2.
    int flagNeg = 0; // Bandera que indica signo de los numeros: 1 negativos / 0 positivos.
    int verif = 0; // Verificacion que devolvera la funcion para decir cual de los dos vectores tiene el mayor numero.
    int flagNull = 0; //Se utiliza en el ultimo for.

    //Revisa que un vector tenga signo negativo y el otro no. En ese caso ya se conoce al numero mayor.

    if(vec1[0] != '-' && vec2[0] == '-')
    {
        verif = 1;
    }
    else if(vec1[0] == '-' && vec2[0] != '-')
    {
        verif = -1;
    }
    else
    {
        //Si se  llega a este punto los dos vectores son negativos o los dos son positivos.
        //Se verifica que ambos tengan signo, en ese caso la bandera indicara que los vectores contienen numeros negativos.

        if(vec1[0] == '-' && vec1[0] == '-')
        {
            flagNeg++;
        }

        //Se recorren ambos vectores para contar la cantidad de numeros hasta el punto o el final del numero en caso de no haberlo.

        for(i = 0; enteros1 == -1 || enteros2 == -1 ; i++)
        {
            if(vec1[i] == '\0')
            {
                //Si enteros vale -1 quiere que el num no tiene punto. Se guarda i equivalente a los nums totales.
                if(enteros1 == -1)
                {
                    enteros1 = i;
                }
            }
            if(vec2[i] == '\0')
            {
                if(enteros2 == -1)
                {
                    enteros2 = i;
                }
            }
            //Revisa en busca del punto decimal y guarda el indice, que es equivalente a los nums enteros totales.
            if(vec1[i] == '.')
            {
                enteros1 = i;
            }
            if(vec2[i] == '.')
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
                if(vec1[i] == '\0' )
                {
                    flagNull++;

                }
                if(vec2[i] == '\0')
                {
                    flagNull += 2;
                }

                if(flagNull == 0)
                {
                    if(flagNeg == 1)
                    {
                        if(vec1[i] > vec2[i])
                        {
                            verif = -1;
                            break;
                        }
                        else if(vec1[i] < vec2[i])
                        {
                            verif = 1;
                            break;
                        }
                    }
                    else
                    {
                        if(vec1[i] > vec2[i])
                        {
                            verif = 1;
                            break;
                        }
                        else if(vec1[i] < vec2[i])
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

void getRangedStr(int minChars,int maxChars,char message[],char eMessage[],char *vec )
{
    char palabra[1000];
    printf("%s", message);
    scanf("%999[^\n]",palabra);
    while(getchar() != '\n');
    while(strlen(palabra) > maxChars || strlen(palabra) < minChars)
    {
        printf("%s",eMessage);
        scanf("%999[^\n]",palabra);
        while(getchar() != '\n');
    }
    strcpy(vec,  palabra);
}


//XG1-6
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

void getRangedSimStr(int minChars, int maxChars,char message[],char eMessage[],char *vec)
{
    char palabra[1000];
    printf("%s", message);
    scanf("%999s",palabra);
    while(getchar()!='\n');

    while(strlen(palabra) > maxChars || strlen(palabra) < minChars)
    {
        printf("%s",eMessage);
        scanf("%s999",palabra);
        while(getchar()!='\n');
    }
    strcpy(vec,  palabra);
}



//Pedir numeros o caracteres sin validar:



//XG1-7
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


//XG1-8
/** \brief solicita un long y muestra un mensaje.
 *
 * \param texto: mensaje a ser a mostrado.
 * \return devuelve el long antes solicitado
 *
 */

long getLong(char texto[])
{
    long number;
    printf("%s",texto);
    setbuf(stdin, NULL);
    scanf("%ld",&number);
    return number;
}


//XG1-9
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


//XG2-1
/** \brief solicita un caracter y muestra un mensaje.
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



// Pedir numeros y validarlos:


//XG2-2
/** \brief pide un entero al usuario correctamente escrito, sin letras ni puntos.
 *
 * \param message: Mensaje mostrado al pedir el entero.
 * \param errorMessage: Mensaje mostrado en caso de error.
 * \return devuelve el entero validado.
 *
 */

int getValidInt(char message[], char errorMessage[])
{
    int number;
    char num[8];

    printf("%s",message);
    scanf("%7s",num);
    while(getchar() != '\n');

    while(validateIsNum(num) == 0 || strNumCmp(num,"32767") > 0 || strNumCmp(num,"-32768") < 0)
    {
        printf("%s",errorMessage);
        scanf("%7s",num);
        while(getchar() != '\n');
    }
    number = atoi(num);
    return number;
}


//XG2-3
/** \brief Pide al usuario un numero de tipo long y valida que no contenga letras, puntos o este exedido de rango.
 *
 * \param message: Mensaje a ser mostrado al pedir el numero.
 * \param errorMessage: Mensaje a ser mostrado en caso de error.
 * \return devuelve el numero que el usuario escribio si y solo si es validado.
 *
 */

long getValidLong(char message[], char errorMessage[])
{

    long number;
    int valid = -1;
    char num[13];
    printf("%s",message);
    scanf("%12s",num);
    while(getchar() != '\n');
    valid = validateIsNum(num);

    while(valid == 0 || strNumCmp(num,"2147483647") > 0 || strNumCmp(num,"-2147483648") < 0)
    {
        printf("%s",errorMessage);
        scanf("%12s",num);
        while(getchar() != '\n');
        valid = validateIsNum(num);
    }
    number = atol(num);
    return number;
}


//XG2-4
/** \brief pide un flotante al usuario correctamente escrito, sin letras ni puntos invalidos.
 *
 * \param message: Mensaje a ser mostrado.
 * \param errorMessage: Mensaje a ser mostrado en caso de error.
 * \return devuelve el flotante validado.
 *
 */

float getValidFloat(char message[], char errorMessage[])
{
    char num[11];
    float number;

    printf("%s",message);
    scanf("%10s",num);
    while(getchar() != '\n');

    while(validateIsRealNum(num) == 0 || strNumCmp(num,"10000000") > 0 || strNumCmp(num,"-10000000") < 0)
    {
        printf("%s",errorMessage);
        scanf("%10s",num);
        while(getchar() != '\n');
    }
    number = atof(num);

    return number;
}


//XG2-5
/** \brief Pide al usuario un numero long long y valida que no tenga letras, puntos o este exedido de rango.
 *
 * \param message: Mensaje a ser mostrado al pedir el numero.
 * \param errorMessage: Mensaje a ser mostrado en caso de error.
 * \return devuelve el numero que el usuario escribio si y solo si es validado.
 *
 */

long long getValidLongLong(char message[], char errorMessage[])
{
    long long number;
    char num[22];
    printf("%s",message);
    scanf("%21s",num);
    while(getchar() != '\n');

    while( validateIsNum(num) == 0 || strNumCmp(num,"9223372036854775807") > 0 || strNumCmp(num,"-9223372036854775808") < 0)
    {
        printf("%s",errorMessage);
        scanf("%21s",num);
        while(getchar() != '\n');
    }
    number = atoll(num);
    return number;
}



//Pedir numeros condicionados 1ra serie:


//XG2-6
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
    int number;
    char num[8];
    int valid = -1;

    printf("%s",message);
    scanf("%7s",num);
    while(getchar() != '\n');

    if(strNumCmp(num,"32767") <= 0 && strNumCmp(num,"-32768") >= 0 && validateIsNum(num) == 1)
    {
        number = atoi(num);
        valid++;
    }

    while( valid < 0 || number < minimum || number > maximum )
    {
        valid = -1;
        printf("%s",errorMessage);
        scanf("%7s",num);
        while(getchar() != '\n');

        if(strNumCmp(num,"32767") <= 0 && strNumCmp(num,"-32768") >= 0 && validateIsNum(num) == 1)
        {
            number = atoi(num);
            valid++;
        }
    }
    return number;
}


//XG2-7
/** \brief Solicita un numero long al usuario y lo devuelve si y solo si es validado. Verifica que el
 *\brief numero no tenga letras y no exeda del rango para su tipo.
 *
 * \param minimum: valor minimo que puede tener el numero que elige el usuario
 * \param maximum: valor maximo que puede tener el numero que elige el usuario
 * \param message: mensaje mostrado al solicitar el numero al usuario
 * \param errorMessage: mensaje mostrado si el usuario escribio un numero fuera de rango
 *\return Devuelve el numero long solicitado si y solo si es valido.
 *
 */

long getRangedLong(long minimum,long maximum,char message[],char errorMessage[])
{
    long number;
    char num[13];
    int valid = -1;

    printf("%s",message);
    scanf("%12s",num);
    while(getchar() != '\n');

    if(strNumCmp(num,"2147483647") <= 0 && strNumCmp(num,"-2147483648") >= 0 && validateIsNum(num) == 1)
    {
        number = atol(num);
        valid++;
    }

    while( valid < 0 || number < minimum || number > maximum )
    {
        valid = -1;
        printf("%s",errorMessage);
        scanf("%12s",num);
        while(getchar() != '\n');

        if(strNumCmp(num,"2147483647") <= 0 && strNumCmp(num,"-2147483648") >= 0 && validateIsNum(num) == 1)
        {
            number = atol(num);
            valid++;
        }
    }
    return number;
}


//XG2-8
/** \brief Solicita un numero flotante al usuario y lo devuelve si y solo si es validado
 *  \brief y no contiene puntos invalidos o letras.
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
    int valid = -1;
    char num[11];
    float number;

    printf("%s",message);
    scanf("%10s",num);
    while(getchar() != '\n');

    if(validateIsRealNum(num) == 1 && strNumCmp(num,"10000000") <= 0 && strNumCmp(num,"-10000000") >= 0)
    {
        valid++;
        number = atof(num);
    }

    while(valid == -1 || number < minimum || number > maximum )
    {
        valid = -1;

        printf("%s",errorMessage);
        scanf("%10s",num);
        while(getchar() != '\n');

        if(validateIsRealNum(num) == 1 && strNumCmp(num,"10000000") <= 0 && strNumCmp(num,"-10000000") >= 0)
        {
            valid++;
            number = atof(num);
        }
    }
    return number;
}



//2da Serie


//XG2-9
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
    int number;
    int valid = -1;
    char num[8];
    printf("%s",message);

    scanf("%7s",num);
    while(getchar() != '\n');

    if(strNumCmp(num,"32767") <= 0 && strNumCmp(num,"-32768") >= 0 && validateIsNum(num) == 1)
    {
        number = atoi(num);
        valid++;
    }


    if(condition > 0)
    {
        while( valid < 0 || number < refNumber)
        {
            valid = -1;
            printf("%s",errorMessage);
            scanf("%7s",num);
            while(getchar() != '\n');

            if(strNumCmp(num,"32767") <= 0 && strNumCmp(num,"-32768") >= 0 && validateIsNum(num) == 1)
            {
                number = atoi(num);
                valid++;
            }
        }

    }
    else if(condition == 0)
    {
        while(valid < 0 || number != refNumber )
        {
            valid = -1;
            printf("%s",errorMessage);
            scanf("%7s",num);
            while(getchar() != '\n');

            if(strNumCmp(num,"32767") <= 0 && strNumCmp(num,"-32768") >= 0 && validateIsNum(num) == 1)
            {
                number = atoi(num);
                valid++;
            }
        }

    }
    else if(condition < 0)
    {
        while( valid < 0 || number > refNumber)
        {
            valid = -1;
            printf("%s",errorMessage);
            scanf("%7s",num);
            while(getchar() != '\n');

            if(strNumCmp(num,"32767") <= 0 && strNumCmp(num,"-32768") >= 0 && validateIsNum(num) == 1)
            {
                number = atoi(num);
                valid++;
            }
        }

    }
    return number;
}


//XG3-1
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
    float number;
    char num[11];
    int valid = -1;

    printf("%s",message);
    scanf("%10s",num);
    while(getchar() != '\n');

    if(validateIsRealNum(num) == 1 && strNumCmp(num,"10000000") <= 0 && strNumCmp(num,"-10000000") >= 0)
    {
        number = atof(num);
        valid++;
    }

    if(condition > 0)
    {
        while(valid == -1 || number < refNumber)
        {
            valid = -1;

            printf("%s",errorMessage);

            scanf("%10s", num);
            while(getchar() != '\n');

            if(validateIsRealNum(num) == 1 && strNumCmp(num,"10000000") <= 0 && strNumCmp(num,"-10000000") >= 0)
            {
                valid++;
                number = atof(num);
            }
        }

    }
    else if(condition == 0)
    {
        while(valid == -1 || number != refNumber)
        {
            valid = -1;

            printf("%s",errorMessage);

            scanf("%10s", num);
            while(getchar() != '\n');

            if(validateIsRealNum(num) == 1 && strNumCmp(num,"10000000") <= 0 && strNumCmp(num,"-10000000") >= 0)
            {
                valid++;
                number = atof(num);
            }
        }

    }
    else if(condition < 0)
    {
        while(valid == -1 || number > refNumber)
        {
            valid = -1;

            printf("%s",errorMessage);

            scanf("%10s", num);
            while(getchar() != '\n');

            if(validateIsRealNum(num) == 1 && strNumCmp(num,"10000000") <= 0 && strNumCmp(num,"-10000000") >= 0)
            {
                valid++;
                number = atof(num);
            }
        }
    }
    return number;
}


//XG3-2
/** \brief Solicita un numero long al usuario mayor, menor o igual a un numero y lo devuelve si y solo si es validado.
 * \brief Se validara ademas que el numero no tenga punto ni letras.
 *
 * \param refNumber: numero que se tomara como referencia para condicionar los numeros que podra ingresar el usuario.
 * \param condition 0: el usuario solo podra ingresar un numero igual al numero de referencia (refNumber).
 * \param condition menor a 0: el numero ingresado solo sera valido si es igual o menor al numero de referencia.
 * \param condition mayor a 0: el numero ingresado solo sera valido si es igual o mayor al numero de referencia.
 * \param message: mensaje mostrado al solicitar el numero al usuario.
 * \param errorMessage: mensaje mostrado en caso de error.
 *\return Devuelve el numero long validado.
 *
 */

long getConditionedLong(long refNumber,int condition,char message[],char errorMessage[])
{
    long number;
    int valid = -1;
    char num[13];
    printf("%s",message);

    scanf("%12s",num);
    while(getchar() != '\n');

    if(strNumCmp(num,"2147483647") <= 0 && strNumCmp(num,"-2147483648") >= 0 && validateIsNum(num) == 1)
    {
        number = atol(num);
        valid++;
    }


    if(condition > 0)
    {
        while( valid < 0 || number < refNumber)
        {
            valid = -1;
            printf("%s",errorMessage);
            scanf("%12s",num);
            while(getchar() != '\n');

            if(strNumCmp(num,"2147483647") <= 0 && strNumCmp(num,"-2147483648") >= 0  && validateIsNum(num) == 1)
            {
                number = atol(num);
                valid++;
            }
        }

    }
    else if(condition == 0)
    {
        while(valid < 0 || number != refNumber )
        {
            valid = -1;
            printf("%s",errorMessage);
            scanf("%12s",num);
            while(getchar() != '\n');

            if(strNumCmp(num,"2147483647") <= 0 && strNumCmp(num,"-2147483648") >= 0 && validateIsNum(num) == 1)
            {
                number = atol(num);
                valid++;
            }
        }

    }
    else if(condition < 0)
    {
        while( valid < 0 || number > refNumber)
        {
            valid = -1;
            printf("%s",errorMessage);
            scanf("%12s",num);
            while(getchar() != '\n');

            if(strNumCmp(num,"2147483647") <= 0 && strNumCmp(num,"-2147483648") >= 0 && validateIsNum(num) == 1)
            {
                number = atol(num);
                valid++;
            }
        }

    }
    return number;
}



//Otras:


//XG3-3
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
    letra = getche();
    while(letra != 'm' && letra != 'f')
    {
        printf("\n%s",errorText);
        letra = getche();
    }
    return letra;
}



//Biblioteca input:


//XG3-4
/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [1] si no [0]
*
*/

int inputGetInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int validation = 1;
    int num;

    printf("%s",message);
    scanf("%d",&num);
    setbuf(stdin,NULL);

    if(num < lowLimit || num > hiLimit)
    {
        printf("%s", eMessage);
        validation = 0;
    }
    else
    {
        *input = num;
    }

    return validation;
}


//XG3-5
/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [1] si no [0]
*
*/

int inputGetFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    int validation = 1;
    float num;

    printf("%s",message);
    scanf("%f",&num);
    setbuf(stdin,NULL);

    if(num < lowLimit || num > hiLimit)
    {
        printf("%s",eMessage);
        validation = 0;
    }
    else
    {
        *input = num;
    }
    return validation;
}


//XG3-6
/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [1] si no [0]
*
*/

int inputGetChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    lowLimit = tolower(lowLimit);
    hiLimit = tolower(hiLimit);
    int validation = 1;
    char character;
    printf("%s",message);
    character = getche();
    character = tolower(character);

    if(character < lowLimit || character > hiLimit)
    {
        validation = 0;
        printf("%s",eMessage);
    }
    else
    {
        *input = character;
    }

    return validation;
}


//XG3-7
/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [1] si no [0]
*
*/

int inputGetString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int validation = 1;

    char palabra[1000];
    printf("%s", message);
    scanf("%999[^\n]",palabra);
    setbuf(stdin,NULL);

    if(strlen(palabra) > hiLimit || strlen(palabra) < lowLimit)
    {
        printf("%s",eMessage);
        validation = 0;
    }
    else
    {
        strlwr(palabra);
        palabra[0] = toupper(palabra[0]);
        strcpy(input, palabra);
    }

    return validation;
}



//XG3-8
/**
* \brief Solicita un número LONG al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [1] si no [0]
*
*/

int inputGetLong(long* input,char message[],char eMessage[], long lowLimit, long hiLimit)
{
    int validation = 0;
    char num[13];
    long number;

    printf("%s",message);
    scanf("%12s",num);
    while(getchar() != '\n');

    if( validateIsNum(num) == 0 || strNumCmp(num ,"2147483647") > 0 || strNumCmp(num,"-2147483648") < 0)
    {
        printf("%s", eMessage);
    }
    else
    {
        number = atol(num);
        if(number >= lowLimit && number <= hiLimit)
        {
            validation = 1;
            *input = number;
        }
    }

    return validation;
}
