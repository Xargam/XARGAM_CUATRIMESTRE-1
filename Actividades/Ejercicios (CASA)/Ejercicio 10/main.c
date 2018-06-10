#include <stdio.h>
#include <stdlib.h>

int main()
{
    int base;
    int altura;
    float superficie;

    printf("Ingrese la base de su triangulo:\n");
    scanf("%d",&base);
    setbuf(stdin, NULL);

    printf("Ingrese la altura de su triangulo:\n");
    scanf("%d",&altura);

    superficie = (float) base * altura / 2;
    printf("La superficie de su triangulo es: %.2f",superficie);

    return 0;
}
