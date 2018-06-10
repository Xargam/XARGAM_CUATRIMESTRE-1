#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main()
{
    int* vec;
    int i;
    int* aux;

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

    printf("\n\n");

    aux=(int*) realloc(vec,10*sizeof(int));

    if(aux==NULL)
    {
        printf("No se pudo conseguir memoria.\n\n");
        system("pause");
        exit(1);
    }
    else
    {
        vec=aux;

        for(i=5;i<(TAM+5);i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d",vec+i);
        }

        for(i=0;i<(TAM+5);i++)
        {
            printf("%d\n",*(vec+i));
        }
    }

    printf("\n\n realloc\n\n");
    vec = (int*) realloc(vec,TAM * sizeof(int));

    for(i=0;i<10;i++)
    {
        printf("%d\n",*(vec+i));
    }

    free(vec);

    return 0;
}
