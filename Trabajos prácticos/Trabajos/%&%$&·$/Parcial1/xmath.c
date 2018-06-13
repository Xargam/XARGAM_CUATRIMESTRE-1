#include <stdio.h>
#include <stdlib.h>


//Operaciones basicas:


//XM1-1
/** \brief Realiza una suma de dos flotantes.
*
* \param A es el primer numero (flotante) que ingresa en la función.
* \param B es el segundo numero (flotante) que ingresa en la función.
* \return Devuelve el resultado de la suma entre A y B en tipo de dato flotante.
*
*/
float xmAdd(float A, float B)
{
    float result;
    result =  A + B;
    return result;
}


//XM1-2
/** \brief Realiza una resta de dos flotantes.
*
* \param A es el primer numero (flotante) que ingresa en la función.
* \param B es el segundo numero (flotante) que ingresa en la función.
* \return Devuelve el resultado de la resta entre A y B respectivamente en tipo de dato flotante.
*
*/
float xmSubtract(float A, float B)
{
    float result;
    result = A - B;
    return result;
}


//XM1-3
/** \brief Realiza una multiplicacion entre dos flotantes.
*
* \param A es el primer numero (flotante) que ingresa en la función.
* \param B es el segundo numero (flotante) que ingresa en la función.
* \return Devuelve el resultado de la multiplicación entre A y B en tipo de dato flotante.
*
*/
float xmMultiply(float A, float B)
{
    float result;
    result = A * B;
    return result;
}


//XM1-4
/** \brief Realiza una división entre dos flotantes.
*
* \param A es el dividendo (flotante).
* \param B es el divisor (flotante).
* \return Devuelve el cociente de la division entre A y B respectivamente en tipo de dato flotante.
*
*/
float xmDivide(float A, float B)
{
    float result;
    result = A / B;
    return result;
}



//Calculos medios:


//XM1-5
/** \brief Calcula el factorial de un numero entero.
*
* \param A: es el numero entero que ingresa en la funcion.
* \return Devuelve el factorial de A en tipo de dato long long int.
*
*/
int xmFactorial(int A)
{
    int accumulator = 1;
    int i;

    for(i = 1; i <= A; i++)
    {
        accumulator *= i;
    }

    return accumulator;
}




//Resolucion de problemas:


//XM1-6
/** \brief Calcula la superficie de un rectangulo mediante su base y su altura.
 *
 * \param base: numero flotante correspondiente a la base del rectangulo.
 * \param height: numero flotante correspondiente a la altura del rectangulo.
 * \return surface: devuelve la superfie del rectangulo segun los parametros.
 *
 */

float xmRectangleSurface(float base, float height)
{
    float surface = base * height;
    return surface;
}
