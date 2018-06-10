#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xget.h"


int main()
{
    char num[1001];
    char num2[1001];
    int verif;

    while(1)
    {
        getRangedSimStr(0,1000,"ingresa un numerin: ","nono: ",num);
        if(validateIsRealNum(num) == 1)
        {
            zeroFixer(num);
            printf("El numero es %s\n",num);
        }
        else
        {
            printf("Eso no es un numero.");
        }
        system("pause");
        system("cls");
    }

    while(1)
    {
        getRangedSimStr(0,1000,"ingresa un numerin: ","nono: ",num);
        getRangedSimStr(0,1000,"\ningresa otro numerin: ","nono: ",num2);
        verif = strNumCmp(num,num2);
        if(verif == -1)
        {
            printf("\n\n%s es menor que %s\n",num,num2);
        }
        else if(verif == 0)
        {
            printf("\n\n%s es igual a %s\n",num,num2);
        }
        else
        {
            printf("\n\n%s es mayor que %s\n",num,num2);

        }
        system("pause");
        system("cls");
    }
    return 0;
}





