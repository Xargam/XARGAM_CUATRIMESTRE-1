#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "xget.h"

#define CANT 5
#define CHARS 30

void funcion(char names[][30],char surnames[][30],char mat3[][120], int filas);

int main()
{
    char nombres[CANT][CHARS] = {"nahuel         e","francisco cabalo","nehuen","leonardo","liliana"};
    char apellidos[CANT][CHARS] = {"ortiz","cuenca","landaverde del cabo","illnois","nani"};
    char nombreA[CANT][CHARS*4];
    funcion(nombres,apellidos,nombreA,5);
    return 0;
}

void funcion(char names[][30],char surnames[][30],char mat3[][120], int filas)
{
    for(int i = 0; i < filas; i++)
    {
        strlwr(names[i]);
        strlwr(surnames[i]);
        names[i][0] = toupper(names[i][0]);
        surnames[i][0] = toupper(surnames[i][0]);
        for(int k = 0; k < 30; k++)
        {
            if(names[i][k] == ' ' && names[i][k+1] != ' ')
            {
                names[i][k+1] = toupper(names[i][k+1]);
            }
            if(surnames[i][k] == ' '&& surnames[i][k+1] != ' ')
            {
                surnames[i][k+1] = toupper(surnames[i][k+1]);

            }

        }
        strcpy(mat3[i],names[i]);
        strcat(mat3[i]," ");
        strcat(mat3[i],surnames[i]);
        printf("%s\n",mat3[i]);
    }
}
