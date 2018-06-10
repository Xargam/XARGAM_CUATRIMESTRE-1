#include <stdio.h>
#include <stdlib.h>
#include "xget.h"
#include <math.h>

/*
1-	Realizar un programa que por medio de una función calcule la intersección
 con el eje x de la parábola  a x²+b x+c. Utilice estructuras para solucionar el
 problema de los 2 valores devueltos.
 */
typedef struct
{
    float resultado1;
    float resultado2;

} Resultado;

Resultado xmIntersec(float a, float b, float c);

int main()
{

    Resultado resultado;
    float A, B, C;
    printf("A continuacion se buscara la interseccion con el eje x de la parabola ax^2+bx+c\n");
    A = getFloat("Ingrese un valor para a: ");
    B = getFloat("Ingrese un valor para b: ");
    C = getFloat("Ingrese un valor para c: ");
    resultado = xmIntersec(A,B,C);
    printf("%.2f , %.2f",resultado.resultado1,resultado.resultado2);

    return 0;
}


Resultado xmIntersec(float a, float b, float c)
{
    Resultado res;
    res.resultado1 = (-b+(sqrt(b*b-4*a*c)))/2*a;
    res.resultado2 = (-b-(sqrt(b*b-4*a*c)))/2*a;
    return res;
}
