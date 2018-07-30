#include <stdio.h>
#include <stdlib.h>

#include "xstring.h"


int main()
{
    char vector[]={"     g     f   "};

    printf("LETRA %c", xstrStringToChar(vector) );
    return 0;
}
