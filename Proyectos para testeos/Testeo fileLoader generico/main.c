#include <stdio.h>
#include <stdlib.h>
#include "xFile.h"
#include "xget.h"

#define FILENAME "archivo.bin"

typedef struct
{
    char nombre[150];
    char descripcion[150];
    int edad;
    float sueldo;
    int estado;

} ePersona;

int main()
{
    int quantity = 0;
    int reading = xfiFileSync(FILENAME);
    if( reading == -1 )
    {
        printf("Holy shit archivo error");
        exit(1);
    }
    else if( reading == 0)
    {
        printf("Generado");
    }
    else
    {
        printf("leido\n");
        ePersona** persona =(ePersona**) xfiFileLoader(FILENAME,&quantity,sizeof(ePersona));
        if(persona == NULL)
        {
            printf("Error.");
            exit(1);
        }
        else
        {
            printf("\n\nDESC: %s NOMB: %s  EDAD %d SUELDO %.2f",persona[0]->descripcion,persona[0]->nombre,persona[0]->edad,persona[0]->sueldo);
            system("pause");
        }
        /*
        char nombre[150];
        char descripcion[150];
        int edad;
        float sueldo;
        int estado;
        */
        /*
        ePersona* pointer = malloc(sizeof(ePersona));
        getRangedStr(pointer->nombre,1,10,"Ingrese NOM,BRE: ","NAHH",1);
        getRangedStr(pointer->descripcion,1,10,"\n\nIngrese desc: ","NAHH",1);
        getRangedInt(&pointer->edad, 1,50,"\n\nINGRESE EDAD: ","nahhh");
        getRangedFloat(&pointer->sueldo, 1,50,"\n\nINGRESE SUELDO: ","nahhh");
        persona[quantity] = pointer;
        FILE* file;
        file=fopen(FILENAME,"wb");
        if( fwrite(persona[quantity],sizeof(persona),1,file) )
        {
            printf("cargado con exito");
        }

        fclose(file);*/

    }



    return 0;
}
