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
{
    int i,j;
    int temp;
    for(i=1; i<len; i++)
    {
        temp = data[i];
        j = i - 1 ;

        while(j>=0 && temp<data[j]) // temp<data[j] o temp>data[j]
        {

            data[j+1] = data[j];
            j--;
        }

        data[j+1] = temp; // inserción

    }
}



