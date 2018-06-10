#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

#define CANT 3
#define ESC 27

int main()
{
    EEmpleado empleado[CANT];
    ESector sectores[5];

    //ESector sectores[]={ {1, "RRHH", 1}, {2, "Sistemas", 1}, {3, "Administracion", 1}, {4, "Compras", 1}, {5, "Deposito", 1} };
    //ESector sectores[]={ 1, "RRHH", 1, 2, "Sistemas", 1, 3, "Administracion", 1, 4, "Compras", 1, 5, "Deposito", 1 };

    int i;
    char opcion;

    inicializar(empleado, CANT);

    hardCode(sectores);

    for(i=0; i<5; i++){
        printf("%d - %s - %d\n", sectores[i].id, sectores[i].descripcion, sectores[i].isEmpty);
    }
    system("pause");

    do{
        system("cls");
        printf("1- Agregar empleado\n");
        printf("2- Borrar empleado\n");
        printf("3- Modificar empleado\n");
        printf("4- Imprimir lista\n");
        printf("ESC- Salir\n");

        opcion = getch();

        switch(opcion)
        {
            case '1':
                alta(empleado, CANT);
                break;
            case '2':
                printf("Baja...");
                break;
            case '3':
                printf("Modificar...");
                break;
            case '4':
                listar(empleado, CANT);
                system("pause");
                break;
            case 'ESC':
                break;
        }

    }while(opcion != ESC);

    return 0;
}
