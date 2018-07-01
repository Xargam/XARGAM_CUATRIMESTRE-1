#include <stdio.h>
#include <stdlib.h>

int main()
{
    float vec[] = {5,6,7,8,9,10};
    float matriz[2][6];
    matriz[0][0] = vec[0];
    matriz[0][1] = vec[1];
    matriz[0][2] = vec[2];
    matriz[0][3] = vec[3];
    matriz[0][4] = vec[4];
    matriz[0][5] = vec[5];
    for(int i = 0 ; i < 6 ; i++)
    {
        printf("ES %lf\n",matriz[0][i]);
        printf("ES %lf\n",matriz[1][i]);
    }
    return 0;
}
