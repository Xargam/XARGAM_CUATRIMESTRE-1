#include <stdio.h>
#include <stdlib.h>

float suma(float A,float B)
{
    float resultado;
    resultado = A + B;
    return resultado;
}
float resta(float A,float B)
{
    float resultado;
    resultado = A - B;
    return resultado;
}
float division(float A,float B)
{
    if(B==0)
    {
        printf("error, no se puede dividir por 0\n");
    }
    else
    {
        float resultado;
        resultado = A / B;
        return resultado;
    }
    return 0;
}
float multiplicacion(float A,float B)
{
    float resultado;
    resultado = A * B;
    return resultado;
}
float factorial(float A)
{
    if(A<0)
    {
        printf("error, no se puede factorizar con numeros negativos.\n");
    }
    else
    {
        float resultado=1;
        for(float i=A; i>0; i--)
        {
            resultado = resultado * i;
        }
        return resultado;
    }
    return 0;
}
