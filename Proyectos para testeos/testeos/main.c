#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
    int legajo;
    char nombre[50];
    int edad;
} eEmpleado;



int main()
{
    eEmpleado empleados[5]= {{111,"tomas",18},{222,"leo",22},{333,"belen",13},{444,"briza",14},{555,"ana",23}};
    int salir=0;
    int opcion=0;
    do
    {
        system("cls");
        printf("1)---modificacion---\n");
        printf("2)---salir---\n");

        printf("ingrese una opcion\n");
        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
        case 1:
            printf("---modificacion---\n");
            break;
        case 2:
            printf("---salir---\n");
            printf("si quiere salir presione esc\n");
            salir = getch();
            break;
        default:
            printf("opcion incorrecta\n");
            break;
        }
        system("pause");
    }
    while(salir!=27);

    return 0;

}
