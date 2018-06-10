#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    char letra;
    int contadorA = 0;
    int contadorE = 0;
    int contadorI = 0;
    int contadorO = 0;
    int contadorU = 0;
    int i;

    for(i = 1 ; i < 21;i++)
    {
        printf("Ingrese la letra numero %d\n",i);
        letra = getche();
        printf("\n");

        if(letra == 'a')
        {
            contadorA++;
        }
        else if(letra == 'e')
        {
            contadorE++;
        }
        else if(letra == 'i')
        {
            contadorI++;
        }
        else if(letra == 'o')
        {
            contadorO++;
        }
        else if(letra == 'u')
        {
            contadorU++;
        }
    }
    printf("\nSe ingresaron %d letras a, %d letras e, %d letras i, %d letras o y %d letras u.",contadorA, contadorE, contadorI, contadorO, contadorU);



    return 0;
}
