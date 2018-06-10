#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int acumuladorNegativos = 1;
    int acumuladorPositivos = 0;
    int i;

    for(i = 0; i < 10; i++)
    {
        printf("Ingrese un numero que no sea 0:\n");
        scanf("%d",&numero);
        setbuf(stdin, NULL);

        while(numero == 0)
        {
            printf("Error, ha ingresado 0. Reingrese el numero:\n");
            scanf("%d",&numero);
            setbuf(stdin, NULL);
        }

        if(numero > 0)
        {
            acumuladorPositivos += numero;
        }
        else
        {
            acumuladorNegativos *= numero;
        }
    }
    system("cls");
    printf("La suma de los numeros postivos que ingreso es %d y el producto de los negativos da %d",acumuladorPositivos,acumuladorNegativos);

    return 0;
}
