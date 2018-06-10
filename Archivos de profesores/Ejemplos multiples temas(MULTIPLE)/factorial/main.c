#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, valor, resultado=1;

    printf("Ingrese: ");
    scanf("%d", &valor);

    for(i=valor; i>0; i--){
        resultado = resultado * i;
    }

    printf("Valor es: %d\nResultado es: %d", valor, resultado);

    return 0;
}
