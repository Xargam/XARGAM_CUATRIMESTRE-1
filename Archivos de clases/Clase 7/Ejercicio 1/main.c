#include <stdio.h>
#include <stdlib.h>

#define CARACTERES 50
#define CANT 2

int main()
{
    int legajo[CANT];
    float salario[CANT];
    char cadenas[CANT][CARACTERES];
    char auxNombre[310];

    for(int i = 0; i < CANT; i++)
    {
        printf("Ingrese legajo: \n");
        scanf("%d",&legajo[i]);
        setbuf(stdin,NULL);

        printf("Ingrese salario: \n");
        scanf("%f",&salario[i]);
        setbuf(stdin, NULL);

        printf("Ingrese nombre: ");
        scanf("%[^\n]",nombre);
        setbuf(stdin, NULL);

        printf("Legajo %d, salario $%.2f,nombre %s.\n",legajo[i],salario[i],cadenas[i])
    }

    return 0;
}
