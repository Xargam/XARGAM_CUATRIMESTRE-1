#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    int numero2;
    float resultado;

    printf("Ingrese el primer numero:\n");
    scanf("%d",&numero1);
    setbuf(stdin, NULL);

    printf("Ingrese el segundo numero:\n");
    scanf("%d",&numero2);

    if(numero1 == numero2)
    {
        printf("%d y %d",numero1, numero2);
    }
    else if(numero1 > numero2)
    {
        resultado = (float) numero1 / numero2;
        printf("%.2f",resultado);
    }
    else
    {
        resultado = numero1 + numero2;
        if(resultado < 50)
        {
            printf("La suma es %.2f y es menor a 50.",resultado);
        }
        else
        {
            printf("%.2f",resultado);
        }
    }


    return 0;
}
