#include <stdio.h>
#include <stdlib.h>
#include "xvalidate.h"
#include <string.h>
#define TAM 2

/*
1) Realizar una función para cargar los datos de una persona en una struct, para ello se debe definir una estructura
con los campos nombre, edad, dni.
A) La función tendrá el siguiente prototipo:
int loadPerson(struct S_Person* pPerson);
B) La función deberá devolver un 1 si los datos ingresados son correctos, y un 0 si no lo son.
C) Hacer otra función que reciba un puntero a la estructura e imprima por pantalla los datos, el prototipo es:
void printPerson(struct S_Person* pPerson);
D) Escribir un programa para probar las funciones.
*/

typedef struct
{
    int edad ;
    long dni ;
    char nombre[50] ;

} S_Person ;

int loadPerson(S_Person *pPerson , int tam);
void printPerson(S_Person* pPerson , int tam);

int main()
{

    S_Person people[TAM] ;
    S_Person *ptrPeople ;
    ptrPeople = people ;
    int valid;

    valid = loadPerson( ptrPeople , TAM ) ;
    while(valid == 0)
    {
        printf("Datos cargados invalidos...\n\n");
        loadPerson(ptrPeople , TAM);
    }
    printPerson(ptrPeople , TAM);
    printf("\nValidacion es %d",valid);
    return 0;
}

int loadPerson(S_Person* pPerson , int tam)
{
    char aux[500];
    int i;
    int validation = 1;
    for( i = 0 ; i < tam ; i++)
    {
        printf("Ingrese dni: ");
        scanf("%ld", &(*(pPerson + i )).dni );
        setbuf(stdin , NULL);
        if( (*(pPerson + i)).dni > 50000000 || (*(pPerson + i )).dni < 10000000)
        {
            validation = 0;
        }
        printf("\nIngrese edad: ");
        scanf("%d", &(*(pPerson + i )).edad );
        setbuf(stdin , NULL);
        if( (*(pPerson + i)).edad > 150 || (*(pPerson + i )).edad < 0)
        {
            validation = 0;
        }
        printf("Ingrese nombre: ");
        scanf("%s", aux);
        setbuf(stdin , NULL);
        if( strlen( aux ) > 49)
        {
            validation = 0;
            printf("valor");
        }
        else
        {
            strcpy( (*(pPerson + i)).nombre , aux );
        }
    }
    return validation ;
}

void printPerson(S_Person* pPerson , int tam)
{
    int i;
    for( i = 0 ; i < tam ; i++)
    {
        printf("\nPerson %d DNI: %ld", i+1 , (*(pPerson + i)).dni );
        printf("\nPerson %d EDAD: %d", i+1 , (*(pPerson + i)).edad );
        printf("\nPerson %d NOMBRE: %s", i+1 , (*(pPerson + i )).nombre );
    }
}
