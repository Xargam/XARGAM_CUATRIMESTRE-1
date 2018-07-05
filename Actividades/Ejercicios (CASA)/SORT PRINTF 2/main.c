#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "xlook.h"

int main()
{
    xlkSortPrintf("%lli,%f,%lf,%c,%s",2,245LL,2.0,456456.456,'f',"TRIVAGO");
    return 0;
}
