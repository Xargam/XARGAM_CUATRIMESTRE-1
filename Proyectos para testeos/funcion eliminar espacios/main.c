#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "xget.h"
#include "xstring.h"
#include "xvector.h"



int main()
{
    float vector[] = {489, -155};
    xvecFSwap(&vector[0],&vector[1]);
    xvecFShow(vector,2,"Aqui estan:\n");

    return 0;
}




