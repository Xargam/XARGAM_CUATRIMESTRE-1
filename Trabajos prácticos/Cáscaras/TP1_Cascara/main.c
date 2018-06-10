#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float resultado;
    float A,B;

    while(seguir=='s')
    {

        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese el valor de A: \n");
                scanf("%f", &A);
                printf("A = %.2f\n",A);
                system("pause");
                break;

            case 2:
                printf("Ingrese el valor de B: \n");
                scanf("%f", &B);
                printf("B = %.2f\n",B);
                system("pause");
                break;

            case 3:
                resultado = suma(A,B);
                printf("El resultado de la suma es: %.2f\n",resultado);
                system("pause");
                system("cls");
                break;

            case 4:
                resultado = resta(A,B);
                printf("El resultado de la resta es: %.2f\n",resultado);
                system("pause");
                system("cls");
                break;

            case 5:
                resultado = division(A,B);
                printf("El resultado de la division es: %.2f\n",resultado);
                system("pause");
                system("cls");
                break;

            case 6:
                resultado = multiplicacion(A,B);
                printf("El resultado de la multiplicacion es: %.2f\n",resultado);
                system("pause");
                system("cls");
                break;

            case 7:
                resultado = factorial(A);
                printf("el resultado es: %.2f\n",resultado);
                system("pause");
                system("cls");
                break;

            case 8:

                system("pause");
                system("cls");
                break;

            case 9:
                printf("ingrese cualquier letra para salir.\n");
                seguir = 'n';
                break;
        }
    }

    return 0;
}
