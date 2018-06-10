#include <stdio.h>
#include <stdlib.h>

int main()
{
    float peso;
    char respuesta;
    int numEmpleado = 1;
    int contador80 = 0;
    int contadorMas80 = 0;

    while(respuesta != 'F')
    {
        printf("Ingrese el peso del empleado %d.\n", numEmpleado);

        scanf("%f",&peso);
        setbuf(stdin, NULL);

        if(peso < 81)
        {
            contador80++;
        }
        else
        {
            contadorMas80++;
        }

        printf("Escriba 'F' si desea dejar de ingresar datos.\n");

        respuesta = getchar();
        setbuf(stdin, NULL);

        numEmpleado++;
        system("cls");
    }

    printf("Hay %d empleados que pesan 80kg o menos.\n",contador80);
    printf("hay %d empleados que pesan mas de 80kg",contadorMas80);



    return 0;
}
