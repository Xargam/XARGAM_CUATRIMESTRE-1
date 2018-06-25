#include <stdio.h>
#include <stdlib.h>

int* getPointer(void);



int main()
{
    int* jhaja =getPointer();
    for(int i ; i < 11; i++)
    {
        printf("EL NUM es %d\n",jhaja[i]);
    }
    return 0;
}



int* getPointer(void)
{
    int vector[50]= {0,1,2,3,4,5,67,7,8,9,10};
    int* vec = vector;
    return vec;

}
