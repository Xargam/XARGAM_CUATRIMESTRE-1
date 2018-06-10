#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "xlook.h"



int main()
{
    xlkHeadGenerator("Modificar producto: ");
    printf("Producto x\n");
    xlkIndexBodyGenerator(2,"1-cambiar id","2-cambiar nombre");
    return 0;


}





