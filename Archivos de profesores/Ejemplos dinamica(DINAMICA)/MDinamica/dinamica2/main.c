#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main()
{


   int* vec;

   vec = (int*) malloc( TAM * sizeof(int));

   if(vec == NULL){
    printf("\nNo se pudo conseguir memoria\n\n");
    system("pause");
    exit(1);
   }

   for(int i=0; i < TAM; i++){
    printf("Ingrese un numero: ");
    scanf("%d", vec + i);
   }

    for(int i=0; i < TAM; i++){
    printf(" %d",  *(vec + i)   );

   }

   printf("\n\n");


    free(vec);
    return 0;
}
