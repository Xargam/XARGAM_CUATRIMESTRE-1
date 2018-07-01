#include <stdio.h>
#include <stdlib.h>

void insertion(int data[],int len);


int main()
{
    int vec[7]= {9,8,47,456,-123,465,456456};
    insertion(vec,7);
    for(int i = 0 ; i< 7 ; i++)
    {
        printf("VEC: %d\n",vec[i]);
    }


    return 0;
}






void insertion(int data[],int len)
{temp            45
moves   45   9 47 456
        j        i
    //8,9,47,456,45,465,456456
    int i,j;
    int temp;
    for(i=1; i<len; i++)
    {
        printf("I ES %d ,DATA DE I ES %d\n",i,data[i]);
        temp = data[i];
        printf("TEMP ES %d\n",temp);
        j=i-1;
        printf("J ES %d\n",j);
        system("pause");
        while(j>=0 && temp<data[j]) // temp<data[j] o temp>data[j]
        {
            system("cls");

            data[j+1] = data[j];
            printf("J ES %d Y J + 1 %d\n",j,j+1);
            printf("DATA DE J +1 ES %d RECIBE DATOS DE DATA DE J ES %d\n",data[j+1],data[j]);
            system("pause");
            j--;
        }

        data[j+1]=temp; // inserción
        printf("TEMP ES %d\n",temp);
        system("pause");
        printf("\n\n\n");
    }
}

