#include <stdio.h>
#include <stdlib.h>
#include "inc/input.h"


int main()
{
    int edad;
    float precio;
    char continuar;
    char nombre[50];
    int r; // Respuesta


    // EJEMPLO DE USO DE getInt
    r = inputGetInt(&edad,"Cual es tu edad? 1 a 10\n","Error - fuera de rango\n",1,10);
    if(r == 0)
        printf("\nLa edad es: %d\n",edad);


    // EJEMPLO DE USO DE getFloat
    r = inputGetFloat(&precio,"Cual es el precio? 0 a 10\n","Error - fuera de rango\n",0,10);
    if(r == 0)
        printf("\nEl precio es: %0.2f\n",precio);


    // EJEMPLO DE USO DE getChar

    r = inputGetChar(&continuar,"Ingrese Opcion entre 'A' y 'Y'\n","\nLa 'Z' no se permite",'A','Y');
    if(r == 0)
        printf("\nContinuar: %c\n",continuar);


    // EJEMPLO DE USO DE getChar
    r = inputGetString(nombre,"Nombre: ","El largo debe ser entre 2 y 50", 2, 50);
    if(r == 0)
        printf("\nNombre: %s\n",nombre);

    system("pause");

    return 0;
}
