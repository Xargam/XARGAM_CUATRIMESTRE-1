#include <stdio.h>
#include <stdlib.h>

/*
2-	Idem 1 teniendo en cuenta un máximo de 15 datos. Los datos se cargan en un vector apropiado,
finalizado el ingreso, se pasa el vector al archivo. Utilice este ejercicio para ver los distintos
valores que se le pueden colocar a Fwrite para escribir el vector al archivo.
*/

typedef struct
{
    int empl
}

int main()
{
    FILE* arch;
    int* numero;
    int desplazamientos = 0;
    int lectura;
    if( (numero = malloc(sizeof(int))) == NULL )
    {
        printf("Error de reserva de memoria escencial.");
        system("pause");
        exit(1);
    }

    if( (arch = fopen("data.bin","rb")) == NULL)
    {
        if( (arch = fopen("data.bin","wb")) == NULL)
        {
            printf("Se produjo un error al abrir un archivo vital.");
            system("pause");
            exit(1);
        }
    }
    else
    {
        while(!feof(arch))
        {
            lectura = fread(numero,sizeof(int),1,arch);
            if(feof(arch))
            {
                break;
            }
            else if(lectura != 1)
            {
                printf("Se produjo un error a leer datos.");
                exit(1);
                system("pause");
            }

            desplazamientos++;
            if( (realloc(numero,(sizeof(int)*(desplazamientos+1) ))) == NULL )
            {
                printf("Se produjo un error al reservar memoria.");
                exit(1);
            }
        }
    }



    fopen()
    return 0;
}


reservaDinamicaEmp(eEmp)
