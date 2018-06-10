#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <conio.h>

/*
TIPOS DE DATOS Y SU PESO:
--------------------------------------------------
TIPO               BITS   BYTES  RANGO DECIMAL
--------------------------------------------------
char	            8	   1     -128 a 127
unsigned char	    8	   1      0 a 255
signed char 	    8	   1     -128 a 127
short       	    16	         -32768 a 32767
int 	            32	         -32768 a 32767
unsigned int 	    32	         0 a 65535
signed int       	32	         -32768 a 32767
short int	        16	         -32768 a 32767
unsigned short int	16	         0 a 65535
signed short int	16	         -32768 a 32767
long int	        32	         -2147483648 a 2147483647
signed long int	    32	         -2147483648 a 2147483647
unsigned long int	32	          0 a 4294967295
long	            32	         -2147483648 a 2147483647
unsigned long	    32	          0 a 4294967295
float	            32	          3.4E-38 a 3.4E+38
double	            64	          1.7E-308 a 1.7E+308
long double	        80            1.7E-308 a 1.7E+308 o 3.4E-4932 a 1.1E+4932
*/



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
    printf("\n#*---*---*---*---*---*---*---*---*---*----*---*---*---*---*---*---*---*---*---*#\n");
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
float xmAdd(float A, float B)
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
float xmSubtract(float A, float B)
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
float xmDivide(float A, float B)
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
float xmMultiply(float A, float B)
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


