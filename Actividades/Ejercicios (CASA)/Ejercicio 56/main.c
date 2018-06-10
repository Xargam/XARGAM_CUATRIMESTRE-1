#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int seleccionador;
    int numero1;
    int numero2;
    float resultado;
    char respuesta;

    while(respuesta != 'f')
    {
        system("cls");
        setbuf(stdin, NULL);
        printf("Seleccionar:\n\n");
        printf("Ingresar 1: Suma\n");
        printf("Ingresar 2: Resta\n");
        printf("Ingresar 3: Multiplicacion\n");
        printf("Ingresar 4: Division\n\n");

        scanf("%d",&seleccionador);
        setbuf(stdin, NULL);

        switch(seleccionador)
        {
            case 1 :
            {
                printf("\nSeleccionada suma.\n\n");
                printf("Ingrese primer numero:\n");
                scanf("%d",&numero1);
                setbuf(stdin, NULL);

                printf("\nIngrese segundo numero:\n");
                scanf("%d",&numero2);

                resultado = numero1 + numero2;
                printf("La suma da: %.2f.\n",resultado);

                printf("Continuar? Ingrese 'f' para finalizar.\n");
                respuesta = getche();
                break;
            }
            case 2 :
            {
                printf("\nSeleccionada resta.\n\n");
                printf("Ingrese primer numero:\n");
                scanf("%d",&numero1);
                setbuf(stdin, NULL);

                printf("\nIngrese segundo numero:\n");
                scanf("%d",&numero2);

                resultado = numero1 - numero2;
                printf("La resta da: %.2f.\n",resultado);

                printf("Continuar? Ingrese 'f' para finalizar.\n");
                respuesta = getche();
                break;
            }
            case 3:
            {
                printf("\nSeleccionada multiplicacion.\n\n");
                printf("Ingrese primer numero:\n");
                scanf("%d",&numero1);
                setbuf(stdin, NULL);

                printf("\nIngrese segundo numero:\n");
                scanf("%d",&numero2);

                resultado = numero1 * numero2;
                printf("La multiplicacion da: %.2f.\n",resultado);

                printf("Continuar? Ingrese 'f' para finalizar.\n");
                respuesta = getche();
                break;
            }
            case 4:
            {
                printf("\nSeleccionada division.\n\n");
                printf("Ingrese primer numero:\n");
                scanf("%d",&numero1);
                setbuf(stdin, NULL);

                printf("\nIngrese segundo numero:\n");
                scanf("%d",&numero2);

                resultado = (float) numero1 / numero2;

                if(numero2 == 0)
                {
                    printf("Indeterminado.\n");
                }
                else
                {
                    printf("\nLa division da: %.2f.\n",resultado);
                }

                printf("Continuar? Ingrese 'f' para finalizar.\n");
                respuesta = getche();
                break;
            }
            default :
            {
                continue;
            }
        }
    }
    system("cls");
    printf("Programa finalizado.");
    return 0;
}
