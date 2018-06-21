#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xlook.h"
#include "xFiles.h"
#include "xArrayList.h"
#include "xMovies.h"
#include "conio.h"

#define ARCHIVO "movies.bin"


int main()
{
  //  arrayList* movies;
    //arrayList* auxArrayList;
    //int num;
  //  char string[50];

    int chaaa;
    char ns;
    do
    {
        ns = getch();
        chaaa = ns;
        if(chaaa != 27 && chaaa != 13)
        {
            printf("NS e %c\n",ns);
            system("pause");





            fflush(stdout);
        }
    }
    while( chaaa != 27 && chaaa != 13);
    system("pause");
    return 0;
}



