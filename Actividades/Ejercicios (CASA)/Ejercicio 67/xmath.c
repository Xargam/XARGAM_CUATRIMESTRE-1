#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


int pedirEntero(char texto[])
{
    int entero;
    printf("%s",texto);
    scanf("%d",&entero);
    setbuf(stdin, NULL);
    return entero;
}

int getMax(int vec[], int cantidadElementos,int* indice)
{
    int mayor = vec[0];
    int ind = 0;

    for(int i = 0; i < cantidadElementos; i++)
    {
        if(vec[i] > mayor)
        {
            mayor = vec[i];
            ind = i;
        }
    }
    *indice = ind;
    return mayor;
}

void intVsort(int vec[], int cantidadElementos, int criterio)
{
    for(int i = 0; i < cantidadElementos - 1; i++)
    {
        for(int j = i+1; j < cantidadElementos; j++)
        {
            if(criterio == 0)
            {
                if(vec[j] > vec[i])
                {
                    int aux;
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }

            }
            else if(criterio == -1)
            {
                if(vec[j] < vec[i])
                {
                    int aux;
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }

        }
    }
}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int num;
    printf("%s",message);
    scanf("%d",&num);
    setbuf(stdin,NULL);
    *input = num;

    if(num < lowLimit || num > hiLimit)
    {
        printf("%s", eMessage);
        return -1;
    }
    return 0;
}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    float num;
    printf("%s",message);
    scanf("%f",&num);
    setbuf(stdin,NULL);
    *input = num;

    if(num < lowLimit || num > hiLimit)
    {
        printf("%s",eMessage);
        return -1;
    }
    return 0;
}


/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    char caracter;
    printf("%s",message);
    caracter = getche();
    *input = caracter;

    if(caracter < lowLimit || caracter > hiLimit)
    {
        printf("%s",eMessage);
        return -1;
    }
    return 0;
}

/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/


/** \brief Solicita un numero al usuario y lo devuelve si y solo si es validado.
 *
 * \param number: direccion de memoria donde se guardara el numero validado
 * \param minimum: valor minimo que puede tener el numero que elige el usuario
 * \param maximum: valor maximo que puede tener el numero que elige el usuario
 * \param message: mensaje mostrado al solicitar el numero al usuario
 * \param errorMessage: mensaje mostrado si el usuario escribio un numero fuera de rango
 *
 */
void rangedGetInt(int* number,int minimum,int maximum,char message[],char errorMessage[] )
{
    int num;
    printf("%s",message);
    scanf("%d",&num);
    setbuf(stdin, NULL);
    while(num < minimum || num > maximum)
    {
        printf("%s",errorMessage);
        scanf("%d", &num);
        setbuf(stdin, NULL);
    }
    *number = num;
}

/** \brief Genera un menu con la cantidad de opciones y texto que el usuario quiera.
 *
 * \param totalOptions: se coloca un entero que indica la cantidad de opciones a generar
 * \param Se agregan parametros con string para las opciones, segun la cantidad elegida.
 *
 */
void indexGenerator(int totalOptions,...)
{
    int i;
    va_list arguments;
    va_start(arguments,totalOptions);
    printf("###########____________________________________________________________________#\n"    );
    printf("   MENU:\n\n"                                                                          );
    printf("###########____________________________________________________________________#\n"  );
    for(i = 0; i < totalOptions; i++)
    {
        printf("  %s\n",va_arg(arguments,int));
    }
    printf("\n############___________________________________________________________________#\n");
    va_end(arguments);
}

/** \brief Realiza una suma de dos flotantes.
*
* \param A es el primer numero (flotante) que ingresa en la función.
* \param B es el segundo numero (flotante) que ingresa en la función.
* \return Devuelve el resultado de la suma entre A y B en tipo de dato flotante.
*
*/
float add(float A, float B)
{
    float result;
    result =  A + B;
    return result;
}

/** \brief Realiza una resta de dos flotantes.
*
* \param A es el primer numero (flotante) que ingresa en la función.
* \param B es el segundo numero (flotante) que ingresa en la función.
* \return Devuelve el resultado de la resta entre A y B respectivamente en tipo de dato flotante.
*
*/
float subtract(float A, float B)
{
    float result;
    result = A - B;
    return result;
}

/** \brief Realiza una división entre dos flotantes.
*
* \param A es el dividendo (flotante).
* \param B es el divisor (flotante).
* \return Devuelve el cociente de la division entre A y B respectivamente en tipo de dato flotante.
*
*/
float divide(float A, float B)
{
    float result;
    result = A / B;
    return result;

}

/** \brief Realiza una multiplicacion entre dos flotantes.
*
* \param A es el primer numero (flotante) que ingresa en la función.
* \param B es el segundo numero (flotante) que ingresa en la función.
* \return Devuelve el resultado de la multiplicación entre A y B en tipo de dato flotante.
*
*/
float multiply(float A, float B)
{
    float result;
    result = A * B;
    return result;
}

/** \brief Calcula el factorial de un numero entero.
*
* \param A: es el numero entero que ingresa en la funcion.
* \return Devuelve el factorial de A en tipo de dato long long int.
*
*/
int factorial(int A)
{
    int accumulator = 1;
    int i;

    for(i = 1; i <= A; i++)
    {
        accumulator *= i;
    }

    return accumulator;
}
