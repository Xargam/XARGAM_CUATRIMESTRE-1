#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ESC 27
#define CANT 50

int main()
{
    char letra, opcion;
    int vector[CANT], posicion;

    for(int i = 0; i < CANT; i++)
    {
        vector[i] = 0;
    }

    while(letra != ESC)
    {
        system("cls");
        printf("VECTOR TOOL V1.0\n\n");
        printf("a-Cargar el vector \n");
        printf("b-Ordenar el vector\n");
        printf("c-Mostrar el vector \n");
        printf("d-Salir\n");

        printf("\nINGRESE OPCION: ");
        opcion = getch();
        switch(opcion)
        {
        case 'a':
            system("cls");
            printf("MENU CARGA: \n\n");
            printf("a- Carga aleatoria\n");
            printf("b- carga secuencial\n\n");
            printf("INGRESE OPCION: ");
            opcion = getch();
            if(opcion == 'a')
            {
                while(letra != ESC)
                {
                    do
                    {
                        printf("\n\nIngrese una posicion del vector (0 a 49): ");
                        scanf("%d",&posicion);
                        setbuf(stdin, NULL);
                    }
                    while(posicion > 49 || posicion < 0);
                    printf("\nIngrese un numero a guardar en la posicion: ");
                    scanf("%d",&vector[posicion]);
                    setbuf(stdin, NULL);
                    printf("\n\nPara volver al menu principal presione ESC. Presione cualquier tecla para continuar...");
                    letra = getch();
                }

            }
            else if(opcion == 'b')
            {
                for(int i = 0; i < CANT; i++)
                {
                    printf("\n\nIngrese un numero para la posicion %d ",i);
                    scanf("%d",&vector[i]);
                    setbuf(stdin, NULL);
                }
            }
            letra = 'a';
            break;
        case 'b':
            system("cls");
            printf("MENU ORDENAR: \n\n");
            printf("a- Mayor a menor\n");
            printf("b- Menor a mayor\n\n");
            printf("INGRESE OPCION: ");
            opcion = getch();
            if(opcion == 'a')
            {
                for( int i = 0; i < CANT-1; i++)
                {
                    for(int j = i+1; j < CANT; j++)
                    {
                        if(vector[i] < vector[j])
                        {
                            int aux;
                            aux = vector[i];
                            vector[i] = vector[j];
                            vector[j] = aux;
                        }
                    }
                }
            }
            else if(opcion == 'b')
            {
                for( int i = 0; i < CANT-1; i++)
                {
                    for(int j = i+1; j < CANT; j++)
                    {
                        if(vector[i] > vector[j])
                        {
                            int aux;
                            aux = vector[i];
                            vector[i] = vector[j];
                            vector[j] = aux;
                        }
                    }
                }
            }
            break;
        case 'c':

            printf("\n\nElementos del vector:\n");
            for(int i = 0; i < CANT; i++)
            {
                if(vector[i] != 0)
                {
                    printf("%d",vector[i]);
                }
            }
            printf("\n");
            system("pause");
            break;
        case 'd':
            printf("\n\nPara salir presione ESC. Presione cualquier tecla para continuar...");
            letra = getch();
            break;
        }

    }
    return 0;
}
