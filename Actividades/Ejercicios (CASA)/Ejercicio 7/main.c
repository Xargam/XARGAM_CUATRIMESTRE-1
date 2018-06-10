#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int cuadrado;

    printf("Ingrese un numero:\n");
    scanf("%d",&numero);
    setbuf(stdin, NULL);

    while(numero < 1)
    {
        system("cls");
        printf("ERROR, el numero debe ser mayor que cero\n");
        printf("Ingrese un numero:\n");
        scanf("%d",&numero);
        setbuf(stdin, NULL);

    }

    cuadrado = numero * numero;
    printf("El cuadrado de: %d es %d",numero,cuadrado);

    return 0;
}
