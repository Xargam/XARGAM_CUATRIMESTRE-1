#include <stdio.h>
#include <stdlib.h>

int sumar(int A, int B)
{
    int resultado;
    resultado =  A + B;
    return resultado;
}

int restar(int A, int B)
{
    int resultado;
    resultado = A - B;
    return resultado;
}

float dividir(int A, int B)
{
    float resultado;
    resultado =(float) A / B;
    return resultado;

}

long int multiplicar(int A, int B)
{
    int resultado;
    resultado = A * B;
    return resultado;
}

int factorial(int A)
{
    int acumulador = 1;

    if(A == 0)
    {
        return 1;
    }

    for(int i = 1; i <= A; i++)
    {
        acumulador *= i;
    }

    return acumulador;
}

int pedirValidarI(char mensaje[],char mensajeError[], int numeroMinimo, int numeroMaximo)
{
    int numero;
    printf(mensaje);
    scanf("%d",&numero);
    setbuf(stdin, NULL);

    while(numero < numeroMinimo || numero > numeroMaximo)
    {
        printf(mensajeError);
        scanf("%d",&numero);
        setbuf(stdin,NULL);
    }
    return numero;
}

