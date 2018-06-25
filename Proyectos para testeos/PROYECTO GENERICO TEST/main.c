#include <stdio.h>
#include <stdlib.h>

int* get(void);

int main()
{
    int* punterin = get();
    for( int i = 0 ; i < 10 ;  i++)
    {
        printf("PUNTERIN  ES %d\n\n",punterin[i]);
    }
    return 0;
}

int* get(void)
{
    int vec[]={1,2,3,4,5,154,7,8,9,10};
    int* ini= vec;
    return ini;
}
