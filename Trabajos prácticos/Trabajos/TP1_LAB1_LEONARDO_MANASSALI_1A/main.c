#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "matematica.h"

int main()
{
    char respuesta = '0';
    int seleccion;
    int A;
    int B;
    int interruptor1 = 0, interruptor2 = 0;
    float resultado;

    int numero;

    numero = pedirValidarI("ingrese un numero\n", "error\n", -88 , 0);

    printf("numero validado %d", numero);
    system("pause");

    while(respuesta != '9')
    {
        system("cls"); // Limpio operaciones realizadas por el usuario.

        // Menu de inicio.

        printf("C--*---*---*---*---*---CALCULADORA LEONARDO MANASSALI V1.0---*---*---*---*---*--\n");
        printf("        Ingrese el numero correspondiente a una opcion para seleccionarla\n\n");
        printf("###########____________________________________________________________________#\n");
        printf("   MENU:\n");
        printf("\n###########____________________________________________________________________#\n\n");

        if(interruptor1 == 1)
        {
            printf("  1- Ingresar 1er operando. (A=%d)",A);
        }
        else
        {
            printf("  1- Ingresar 1er operando. (A=x)");
        }

        if(interruptor2 == 1)
        {
            printf("\n  2- Ingresar 2do operando. (B=%d)",B);
        }
        else
        {
            printf("\n  2- Ingresar 2do operando. (B=y)");
        }


        printf("\n  3- Calcular la suma. (A+B)                       ##        ####       #### \n");
        printf("  4- Calcular la resta. (A-B)                       #   #       #  ###  #  #\n");
        printf("  5- Calcular la division. (A/B)                    #  ###     #        ####\n");
        printf("  6- Calcular la multiplicacion. (A*B)              #   #     #    ###  #  # \n");
        printf("  7- Calcular el factorial. (A!)                    #        #          #### \n");
        printf("  8- Calcular todas las operaciones.\n");
        printf("  9- Salir.\n\n");
        printf("############___________________________________________________________________#\n");

        printf("\n  SELECCIONAR OPCION: ");
        scanf("%d",&seleccion);
        setbuf(stdin, NULL);
        printf("\n");

        // Fin  menu de inicio

        while(seleccion > 9 || seleccion < 1)
        {
            printf("ERROR - opcion inexistente, REINGRESAR: ");
            scanf("%d",&seleccion);
            setbuf(stdin, NULL);
        }

        switch(seleccion)
        {
        case 1:
            printf("\nIngrese el primer operando: ");
            scanf("%d",&A);
            setbuf(stdin, NULL);
            interruptor1 = 1;
            break;
        case 2:
            printf("\nIngrese el segundo operando: ");
            scanf("%d",&B);
            setbuf(stdin, NULL);
            interruptor2 = 1;
            break;
        case 3:
            if(interruptor1 == 0 || interruptor2 == 0)
            {
                printf("Necesita elegir dos operandos para realizar esta operacion.\n\n");
                system("pause");
                break;
            }
            resultado = sumar(A,B);
            printf("%d + %d = %.f\n\n",A,B,resultado);
            interruptor1 = 0;
            interruptor2 = 0;
            system("pause");
            break;
        case 4:
            if(interruptor1 == 0 || interruptor2 == 0)
            {
                printf("Necesita elegir dos operandos para realizar esta operacion.\n\n");
                system("pause");
                break;
            }
            resultado = restar(A,B);
            printf("%d - %d = %.f\n\n",A,B,resultado);
            interruptor1 = 0;
            interruptor2 = 0;
            system("pause");
            break;
        case 5:
            if(interruptor1 == 0 || interruptor2 == 0)
            {
                printf("Necesita elegir dos operandos para realizar esta operacion.\n\n");
                system("pause");
                break;
            }
            if(B == 0)
            {
                printf("ERROR: division por 0.\n\n");
                system("pause");
                interruptor1 = 0;
                interruptor2 = 0;
                break;
            }
            resultado = dividir(A,B);
            printf("%d / %d = %.2f\n\n",A,B,resultado);
            interruptor1 = 0;
            interruptor2 = 0;
            system("pause");
            break;
        case 6:
            if(interruptor1 == 0 || interruptor2 == 0)
            {
                printf("Necesita elegir dos operandos para realizar esta operacion.\n\n");
                system("pause");
                break;
            }
            resultado = multiplicar(A,B);
            printf("%d * %d = %.f\n\n",A,B,resultado);
            interruptor1 = 0;
            interruptor2 = 0;
            system("pause");
            break;
        case 7:
            if(interruptor1 == 0)
            {
                printf("Necesita elegir el primer operando para realizar esta operacion.\n\n");
                system("pause");
                break;
            }
            if(A > 20)
            {
                printf("ERROR: Operando muy grande. Debe ser menor a 21.\n\n");
                interruptor1 = 0;
                system("pause");
                break;
            }

            if(A < 0)
            {
                printf("ERROR: factorial de un numero negativo.\n\n");
                system("pause");
                interruptor1 = 0;
                break;
            }
            resultado = factorial(A);
            printf("%d! = %.f\n\n",A,resultado);
            interruptor1 = 0;
            system("pause");
            break;
        case 8:

            if(interruptor1 == 0 || interruptor2 == 0)
            {
                printf("Necesita elegir dos operandos para realizar esta operacion.\n\n");
                system("pause");
                break;
            }
            interruptor1 = 0;
            interruptor2 = 0;
            resultado = sumar(A,B);
            printf("  %d + %d = %.f\n",A,B,resultado);

            resultado = restar(A,B);
            printf("  %d - %d = %.f\n",A,B,resultado);

            if(B == 0)
            {
                printf("  %d / %d = ERROR: division por 0.\n",A,B);
            }
            else
            {
                resultado = dividir(A,B);
                printf("  %d / %d = %.2f\n",A,B,resultado);
            }

            resultado = multiplicar(A,B);
            printf("  %d * %d = %.f\n",A,B,resultado);

            if(A < 0)
            {
                printf("  %d! = ERROR: factorial de un numero negativo.\n\n",A);
            }
            else if(A > 20)
            {
                printf("  %d! = ERROR: operando muy grande. Debe ser menor a 21.\n\n",A);
            }
            else
            {
                resultado = factorial(A);
                printf("  %d! = %.f\n\n",A,resultado);
            }

            system("pause");
            break;
        case 9:
            printf("\nSeguro? Confirmar con 9. Para volver presione otra tecla.\n");
            respuesta = getch();
        }

    }
    system("cls");
    printf("Calculadora apagada.\n\n");
    return 0;
}

