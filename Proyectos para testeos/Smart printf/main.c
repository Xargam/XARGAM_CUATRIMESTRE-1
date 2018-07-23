#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "xlook.h"


int main()
{
    xlkSortPrintf(-74,"%s",2,"PAR");
    for(int i = 0 ; i < 50 ; i++)
    {
        xlkSortPrintf(0,"%d",1,50*i);
    }
    return 0;
}



