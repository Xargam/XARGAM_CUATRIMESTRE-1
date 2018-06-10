#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int contador = 0;
    int i;

    printf("Ingrese un numero:\n");
    scanf("%d",&numero);

    for(i = 1; i <= numero; i++)
    {
        if(i % 3 == 0)
        {
            contador++;
        }
    }

    printf("Se hallaron %d multiplos de 3 desde 1 al numero ingresado.",contador);
    return 0;
}
