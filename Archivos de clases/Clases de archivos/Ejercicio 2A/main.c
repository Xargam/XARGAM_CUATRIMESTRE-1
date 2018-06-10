#include <stdio.h>
#include <stdlib.h>
#define ARCH "text.txt"

int main()
{
    FILE* file;
    int cant;
    int n1, n2, n3, n4;
    n1 = 1;
    n2 = 2;
    n3 = 3;
    n4 = 4;


    file = fopen(ARCH, "r");
    if( file == NULL)
    {
        fclose(file);
        file = fopen(ARCH,"w");
        if( file == NULL)
        {
            printf("Hubo un error al abrir un archivo.");
            exit(EXIT_FAILURE);
        }

    }
    else
    {
        if ( (file = fopen(ARCH, "w")) == NULL)
        {
            printf("Hubo un error al abrir un archivo.");
            exit(EXIT_FAILURE);
        }
    }

    for( int i = 0 ; i < 3 ; i++)
    {
        fprintf(file," %d , %d , %d , %d\n",n1,n2,n3,n4 );
        n1+=100;
        n2 += 100;
        n3 += 100;
        n4 += 100;
    }
    fclose(file);

    if(  (file = fopen(ARCH, "r")) == NULL)
    {
        printf("Hubo un error al abrir un archivo.");
        exit(EXIT_FAILURE);
    }
    else
    {
        while ( !feof(file) )
        {
            cant = fscanf(file," %d , %d                                                                                                      , %d , %d\n", &n1, &n2, &n3, &n4);
            if( cant != 4)
            {
                if( feof(file))
                {
                    break;
                }
                else
                {
                    printf("Hubo un error al abrir un archivo.");
                    exit(EXIT_FAILURE);
                }
            }
            printf("%d %d %d %d\n", n1 , n2 , n3 ,n4 );
        }
    }

    return 0;
}
