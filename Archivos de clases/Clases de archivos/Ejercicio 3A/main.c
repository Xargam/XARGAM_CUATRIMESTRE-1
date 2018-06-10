#include <stdio.h>
#include <stdlib.h>
#define ARCHIVO ".\\autos.csv"

typedef struct
{
    int id ;
    char marca[100];
    char modelo[100];
    char color[100];
    int anio;
    int estado;

} eAutos ;
int main()
{
    int memReg = 2;
    int quantity = 20;
    eAutos* autos = (eAutos*) malloc(sizeof(eAutos)*quantity);
    char auxAnio[100];
    char auxId[100];
    int cant;
    FILE* file;
    file = fopen(ARCHIVO,"r");

    if(file == NULL)
    {
        printf("ERROR.");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while( !feof(file) )
    {

        cant = fscanf(file,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId , (autos + i)->marca , (autos + i)->modelo , (autos + i)->color , auxAnio  );
        (autos +i)->id = atoi(auxId);
        (autos + i)->anio = atoi(auxAnio);
        if( cant != 5)
        {
            if( feof(file) )
            {
                break;
            }
            else
            {
                printf("ERROR AL LEER");
                exit(EXIT_FAILURE);
            }
        }

        if( i >= (quantity-1) )
        {
            eAutos* auxAutos = (eAutos*) realloc(autos,sizeof(eAutos)*(quantity*memReg ));
            if(auxAutos == NULL)
            {
                printf("ERROR MEMORIA.");
                exit(EXIT_FAILURE);
            }
            autos = auxAutos;
            quantity = quantity*memReg;
            memReg++;
        }
        i++;
    }
    printf("QUANTITY ES %d\n\n",quantity);
    printf("ID:  MARCA:   MODELO: COLOR:  ANIO:\n\n");
    for( i = 0 ; i < 100 ; i++)
    {
        printf("%4d %16s %16s %16s %4d\n\n", (autos + i)->id , (autos + i)->marca , (autos + i)->modelo , (autos + i)->color , (autos + i)->anio);
    }

    free(autos);
    fclose(file);

    return 0;
}
