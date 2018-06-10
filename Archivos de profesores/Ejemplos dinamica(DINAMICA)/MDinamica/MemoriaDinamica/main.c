#include <stdio.h>
#include <stdlib.h>

int main()
{
   int* pNum;

   pNum = (int*) malloc(sizeof(int));

   if(pNum == NULL){
    printf("\nNo se pudo conseguir memoria. El programa finaliza\n\n");
    exit(1);
   }
    printf("Ingrese un numero: ");
    scanf("%d", pNum);
   //*pNum = 5;

   printf(" %d\n\n", *pNum);

   free(pNum);
    return 0;
}
