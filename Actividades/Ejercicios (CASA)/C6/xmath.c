#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>



/** \brief Genera un menu con la cantidad de opciones y texto que el usuario quiera.
 *
 * \param totalOptions: se coloca un entero que indica la cantidad de opciones a generar
 * \param Se agregan parametros con string para las opciones, segun la cantidad elegida.
 *
 */
void indexGenerator(char head[],int totalOptions,...)
{
    int i;
    va_list arguments;
    va_start(arguments,totalOptions);
    printf("#*---*---*---*---*---*---*---*---*---*----*---*---*---*---*---*---*---*---*---*#\n");
    printf("*%s\n                                                                           ",head);
    printf("#*---*---*---*---*---*---*---*---*---*----*---*---*---*---*---*---*---*---*---*#");
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
