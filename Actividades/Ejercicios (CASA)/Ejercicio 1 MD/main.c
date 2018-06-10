#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1) Construir una función llamada "getDynamicString" que permita al usuario ingresar un texto
y devuelva un puntero a un espacio de memoria donde esta almacenado el texto ingresado. Se requiere el uso de memoria dinámica.
*/

char* getDynamicString ( char* msg );

int main()
{
    char* ptr ;
    ptr = getDynamicString("Manda un nombre: ") ;
    printf("\nstrlen es %d\n\n",strlen(ptr));

    printf("%s",ptr);

    free(ptr);


    return 0;
}


char* getDynamicString ( char* msg )
{
    char* pointer ;
    int longitud ;

    printf("%s" , msg);

    pointer = (char*)malloc(sizeof(char)*1024) ;
    if(pointer == NULL)
    {
        exit(1);
    }
    scanf("%1023s",pointer);
    setbuf(stdin , NULL);
    longitud = strlen(pointer);
    pointer =(char*)realloc(pointer , longitud + 1);
    if(pointer == NULL)
    {
        exit(1);
    }
    return pointer ;
}
