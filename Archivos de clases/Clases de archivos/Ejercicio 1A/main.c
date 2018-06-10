#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ESC 27

/*1-	Crear un archivo binario llamado BIN.DAT el cuál contendrá estructuras con los siguientes campos:

	char nombre[10]
	int edad
Terminar el ingreso de datos cuando se presione la tecla ESC. Una vez terminado el ingreso de los datos,
abrir el archivo con un editor de texto y analizar su contenido. */

typedef struct
{
    char nombre[10] ;
    int edad ;
} ePersona;

int main()
{
    FILE* pArchivo ;

    int cantidad;
    int salir;

    int desplazamientos = 0;

    ePersona *pPersona ;
    ePersona *auxPersona ;

    pPersona = malloc(sizeof(ePersona));

    if(pPersona == NULL )
    {
        printf("FALTAL ERROR");
        exit(1);
    }



    if( ((pArchivo = fopen("BIN.DAT","wb")) == NULL) )
    {
        printf("ERROR: A FILE CANT BE OPENED\n");
        system("pause");
        exit(1);
    }

    do
    {
        printf("Ingrese edad: ");
        scanf("%d", &(*(pPersona +  desplazamientos)).edad );
        setbuf(stdin, NULL);

        printf("\nIngrese nombre: ");
        scanf("%s", (*(pPersona + desplazamientos )).nombre );
        setbuf(stdin, NULL);

        printf("\nPresione la tecla ESC para salir u otra tecla para continuar: ");
        salir = getch();

        printf("\n");

        desplazamientos++;
        if(salir != ESC)
        {
            auxPersona = (ePersona*)realloc(pPersona, sizeof(ePersona)*(desplazamientos+1));
            if(auxPersona == NULL)
            {
                printf("\nFATAL ERROR\n");
                system("pause");
                exit(1);
            }
            pPersona = auxPersona ;
        }


    }
    while(salir != ESC);


    //escribo el puntero en la memoria segun los datos guardados

    cantidad = fwrite(pPersona, sizeof(ePersona), desplazamientos,pArchivo );


    if(cantidad < desplazamientos)
    {
        printf("\nFATAL ERROR WRITE\n");
        system("pause");
        exit(1);
    }


    //Cierro el archivo y libero la memoria reservada
    if (fclose(pArchivo) == -1)
    {
        printf("ERROR: A FILE CANT BE CLOSED");
        system("pause");
    }


    if ( (pArchivo = fopen("BIN.DAT","rb")) == NULL )
    {
        printf("FAILED TO OPEN FILE...");
        system("pause");
        exit(1);
    }


    while(!feof(pArchivo))
    {
        cantidad = fread(pPersona, sizeof(ePersona),desplazamientos, pArchivo) ;
        if(cantidad != desplazamientos)
        {
            if(feof(pArchivo) != 0)
            {
                break;
            }
            else
            {
                printf("FATAL ERROR: WRITE ERROR\n\n");
                system("pause");
                exit(1);
            }
        }
        else
        {
            for(int i = 0 ; i < desplazamientos ; i++)
            {
                printf("EDAD: %d , NOMBRE %s\n", (*(pPersona + i)).edad, (*(pPersona + i)).nombre );
                system("pause");
            }
        }

    }

    free(pPersona);
    fclose(pArchivo);

    return 0;
}
