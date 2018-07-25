#include <stdio.h>
#include <stdlib.h>

#include "xArrayList.h"

typedef struct
{
    int numero;
    char nombre[50];
    int caca;
    int pure;

} eNumeros;

int enumeros_ordenar( void* enumero, void* enumero2);
int enumeros_repeticion( void* enumero, void* enumero2);


int main()
{
    arrayList* lista = al_newArrayList();
    arrayList* depurados = al_newArrayList();
    arrayList* repetidos = al_newArrayList();

    int flag = 0;

    eNumeros* nums = (eNumeros*) malloc(sizeof(eNumeros));
    nums->numero = 100;
    lista->add(lista,nums);


    eNumeros* nums2 = (eNumeros*) malloc(sizeof(eNumeros));
    nums2->numero = -1;
    lista->add(lista,nums2);

    eNumeros* nums3 = (eNumeros*) malloc(sizeof(eNumeros));
    nums3->numero = -1;
    lista->add(lista,nums3);

    eNumeros* nums4 = (eNumeros*) malloc(sizeof(eNumeros));
    nums4->numero = -1;
    lista->add(lista,nums4);

    eNumeros* nums5 = (eNumeros*) malloc(sizeof(eNumeros));
    nums5->numero = 1;
    lista->add(lista,nums5);

    eNumeros* nums6 = (eNumeros*) malloc(sizeof(eNumeros));
    nums6->numero = 1;
    lista->add(lista,nums6);

    eNumeros* nums7 = (eNumeros*) malloc(sizeof(eNumeros));
    nums7->numero = 2;
    lista->add(lista,nums7);

    eNumeros* nums8 = (eNumeros*) malloc(sizeof(eNumeros));
    nums8->numero = 2;
    lista->add(lista,nums8);

    eNumeros* nums9 = (eNumeros*) malloc(sizeof(eNumeros));
    nums9->numero = -1;
    lista->add(lista,nums9);

    eNumeros* nums10 = (eNumeros*) malloc(sizeof(eNumeros));
    nums10->numero = 10;
    lista->add(lista,nums10);

    int counter;

    for( int i = 0 ; i < lista->len(lista) ; i++)
    {
        counter = 0;
        repetidos->add(repetidos, lista->get(lista,i));
        for( int j = 0 ; j < lista->len(lista) ; j++)
        {
            if( enumeros_repeticion(lista->get(lista,i),lista->get(lista,j)) == 1  )
            {
                if( counter > 1 && repetidos->contains(repetidos,lista->get(lista,i)) == 0 )
                {
                    repetidos->add(repetidos,lista->get(lista,i));
                }
                counter++;

            }
        }
        if( counter == 1 )
        {
            repetidos->remove(repetidos, repetidos->indexOf(repetidos, lista->get(lista,i)) );
            depurados->add(depurados,lista->get(lista,i));
        }
    }

    //lista->sort(lista,&enumeros_ordenar,1);

    for(int i = 0 ; i < depurados->len(depurados) ; i++ )
    {
        printf("%d\n", ((eNumeros*)depurados->get(depurados,i))->numero );
    }
    printf("\n\n");
    for(int i = 0 ; i < repetidos->len(repetidos) ; i++ )
    {
        printf("%d\n", ((eNumeros*)repetidos->get(repetidos,i))->numero );
    }
    return 0;
}


int enumeros_ordenar( void* enumero, void* enumero2)
{
    int condition = 0;
    if( ((eNumeros*)enumero)->numero > ((eNumeros*)enumero2)->numero  )
    {
        condition = 1;
    }
    else if( ((eNumeros*)enumero)->numero < ((eNumeros*)enumero2)->numero )
    {
        condition = -1;
    }
    return condition;
}

int enumeros_repeticion( void* enumero, void* enumero2)
{
    int repeticion = 0;
    if( ((eNumeros*)enumero)->numero == ((eNumeros*)enumero2)->numero )
    {
        repeticion = 1;
    }
    return repeticion;
}

