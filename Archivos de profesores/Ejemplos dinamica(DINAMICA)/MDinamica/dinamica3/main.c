#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main()
{
    int* vec;
    int* aux;

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

   aux = (int*) realloc(vec, (TAM + 5) * sizeof(int));

   if( aux == NULL){
    printf("\nNo se pudo conseguir memoria\n\n");
    system("pause");
    exit(1);
   }
   else{
    vec = aux;

      for(int i=5; i < (TAM +5); i++){
    printf("Ingrese un numero: ");
    scanf("%d", vec + i);
   }

    for(int i=0; i < (TAM + 5); i++){
    printf(" %d",  *(vec + i)   );

   }
   printf("\n\n");

   }

   vec = (int*) realloc(vec, TAM * sizeof(int));

    for(int i=0; i < 10; i++){
    printf(" %d",  *(vec + i)   );

   }
   printf("\n\n");


   free(vec);

    return 0;
}
