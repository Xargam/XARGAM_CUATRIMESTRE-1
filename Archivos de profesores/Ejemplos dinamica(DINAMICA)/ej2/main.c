#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main()
{
    int* vec;
    int i;

    vec = (int*) malloc (TAM * sizeof(int));

    if(vec == NULL)
    {
        printf("\nNo se puedo conseguir memoria.\n\n");
        system("pause");
        exit(1);
    }

    for(i=0;i<TAM;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",vec+i);
    }

    for(i=0;i<TAM;i++)
    {
        printf("%d\n",*(vec+i));
    }

    free(vec);

    return 0;
}
