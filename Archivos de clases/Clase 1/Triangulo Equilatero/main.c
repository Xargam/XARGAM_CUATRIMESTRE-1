#include <stdio.h>
#include <stdlib.h>

int main()
{
    int altura;
    int base;
    int perimetro;
    float superficie;

    printf("Ingrese la base de su triangulo.\n");
    scanf("%d",&base);

    perimetro = base * 3;
    printf("Ingrese la altura de su triangulo.\n");

    scanf("%d",&altura);
    superficie = base * altura / 2.;

    printf("El perimetro de su triangulo es : %d\n",perimetro);
    printf("La superficie de su triangulo es : %.2f",superficie);

    return 0;
}
