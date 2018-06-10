#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    char n;
    printf("Ingrese numero\n"),

    n = getchar();
    printf("la variable n vale %c\n",n);

    if(n == '9')
    {
        printf("Hotel? trivago");
    }
    return 0;
}
