#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xParser.h"



//Setters  y getters genericos:



eGenerica* generica_newGenerica(void)
{
    eGenerica* gen = (eGenerica*) malloc(sizeof(eGenerica));
    return gen;
}
int generica_setCampo1(eGenerica* gen , int entero )
{
    int verify = 0;
    if( gen != NULL )
    {
        verify = 1;
        gen->campo1 = entero;
    }
    return verify;
}
int generica_setCampo15( eGenerica* gen, long largo)
{
    int verify = 0;
    if( gen != NULL )
    {
        verify = 1;
        gen->campo15 = largo;
    }
    return verify;
}
int generica_setCampo3( eGenerica* gen, char* palabra)
{
    int verify = 0;
    if( gen != NULL )
    {
        verify = 1;
        strcpy( gen->campo3 , palabra);
    }
    return verify;
}
int generica_getCampo1( eGenerica* gen )
{
    return gen->campo1;
}
char* generica_getCampo3( eGenerica* gen )
{
    return gen->campo3;
}
long generica_getCampo15( eGenerica* gen )
{
    return gen->campo15;
}

//____________________________________________________________________________


int xpar_parseGenerica( arrayList* lista, char* filePath )
{
    int verify = 0;

    if( lista != NULL && filePath != NULL)
    {
        FILE* file = fopen(filePath,"r");
        if( file != NULL)
        {
            char campo1[10];
            char campo15[15];
            char campo3[50];

            verify = 1;

            while( !feof(file) )
            {
                if( fscanf(file,"%[^;];%[^;];%[^\n]\n",campo1,campo15,campo3) != 3)
                {
                    if( feof(file))
                    {
                        break;
                    }
                    else
                    {
                        verify = 0;
                        break;
                    }
                }

                eGenerica* gen = generica_newGenerica();

                if( gen == NULL)
                {
                    verify = 0;
                    break;
                }
                generica_setCampo1(gen,atoi(campo1));
                generica_setCampo15(gen,atol(campo15));
                generica_setCampo3(gen,campo3);
                lista->add(lista,gen);
            }
            if( fclose(file) )
            {
                verify = 0;
            }
        }
    }
    return verify ;
}



int xpar_unparseGenerica( arrayList* lista, char* filePath )
{
    int verify = 0;
    if( lista != NULL && filePath != NULL )
    {
        FILE* file = fopen(filePath,"w");
        if( file != NULL )
        {
            verify = 1;
            int i;
            for( i = 0 ; i < lista->len(lista) ; i++)
            {
                if( fprintf(file,"%d;%ld;%s\n", generica_getCampo1( lista->get(lista,i) ), generica_getCampo15( lista->get(lista,i) ), generica_getCampo3( lista->get(lista,i)) ) < 0 )
                {
                    verify = 0;
                    break;
                }
            }
            if( fclose(file))
            {
                verify = 0;
            }
        }
    }
    return verify ;
}
