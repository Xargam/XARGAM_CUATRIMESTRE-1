#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");

    int numero1 = 7;
    int numero2 = 5;

    if(numero1 - numero2 < 0)
    {
        printf("Resultado negativo");
    }
    else if(numero1 - numero2 > 0)
    {
        printf("Resultado positivo");
    }

    return 0;
}
