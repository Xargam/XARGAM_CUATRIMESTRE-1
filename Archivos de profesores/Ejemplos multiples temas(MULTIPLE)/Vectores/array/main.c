#include <stdio.h>
#include <ctype.h>

#define CANT 5

void main(void){
    int v[CANT], pos, i;
    char seguir;

    for(i=0;i<CANT;i++)
        v[i]=0; // inicializamos vector

    do{
        printf("Ingrese posici¢n");
        scanf("%d",&pos);

        printf("Ingrese valor a cargar en el vector");
        scanf("%d",&v[pos]);

        printf("Desea ingresar otro dato S/N?");
        setbuf(stdin, NULL);
        scanf("%c",&seguir);
        seguir = tolower(seguir);
    }while(seguir == 's');

    for(i=0; i<CANT; i++){
        printf("\n%d", v[i]);
    }
}
