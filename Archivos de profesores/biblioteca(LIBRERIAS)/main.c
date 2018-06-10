#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    unsigned int valor;

    valor = verifica();

    if(valor == 1){
        printf("\nEl valor es S");
    }
    else{
        printf("\nEl valor es N");
    }

    return 0;
}
