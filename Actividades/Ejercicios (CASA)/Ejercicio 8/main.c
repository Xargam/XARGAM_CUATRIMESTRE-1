#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int contadorNegativos = 0;
    int contadorPositivos = 0;

    for(int i = 10 ; i > 0; i--)
    {
        printf("Ingrese un numero.\n");
        scanf("%d", &numero);
        setbuf(stdin, NULL);

        if(numero < 0)
        {
            contadorNegativos++;
        }
        else if(numero > 0)
        {
            contadorPositivos++;
        }

    }
    printf("Usted ingreso %d numeros positivos y %d numeros negativos.",contadorPositivos,contadorNegativos);

    return 0;
}
