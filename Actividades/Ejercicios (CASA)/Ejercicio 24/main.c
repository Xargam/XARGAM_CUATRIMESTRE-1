#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1 = 11;
    int num2 = 21;
    int mediadora;

    mediadora = num1;
    num1 = num2;
    num2 = mediadora;

    printf("num1 es %d y num2 es %d",num1,num2);

    return 0;
}
