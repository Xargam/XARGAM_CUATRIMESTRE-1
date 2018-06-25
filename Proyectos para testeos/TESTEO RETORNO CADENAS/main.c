#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamicManage.h"

typedef struct
{
    int legajo;
    char* nombre;
} eEmp;
int main()
{
    char vec[200];
    dynamicManager* dynamic = dyma_New();

    eEmp* dym = (eEmp*)malloc(sizeof(eEmp));

    dynamic->add(dynamic,dym); //GUARDO PUNTEROS DINAMICOS PARA SU POSTERIOR LIBERACION INSTANTANEA


    for( int i = 1 ; i <= 10 ; i++)
    {
        if(dym != NULL)
        {
            puts("Ingrese un legajo:");
            scanf("%d",&dym[i-1].legajo );
            setbuf(stdin,NULL);
            puts("Ingrese nombre:");
            scanf("%s", vec);
            dym[i-1].nombre = vec;
            dym=(eEmp*) realloc(dym,sizeof(eEmp)*(i+1) );

            printf("DIR DE EMP: %d\n",dym);
        }

    }
    for( int i = 0 ; i < 200 ; i++)
    {
        printf("%s char* %d int\n",dym[i].nombre, dym[i].legajo );
    }
    return 0;
}

/*
char* getString(void* cadRef , int size)
{
    char vec[size];
    printf("DIR VEC 1: %d\n",vec);
    puts("INGRESE UNA CADENA:\n");
    scanf("%s",vec);
    void* vec2;
    printf("DIR VEC 2: %d\n",vec2);
    printf("DIR VEC3 : %d", (char*)memcpy(vec2,vec,size));
    return vec;
}*/
