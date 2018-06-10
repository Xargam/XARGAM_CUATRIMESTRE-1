#include <stdio.h>
#include <stdlib.h>

#define CANT 20
#define CHARS 50

int main()
{
    char matriz[CANT][CHARS] = {"Leo","Ezequiel","Nahuel","Nehuen","Sofia","Juan","Leticia","Jhonny","Pablo","Anibal","Pedro","Alberto","Brian","Valentina","Antonella","Florencia","Tomas","Agustin","Francisco","Martin"};
    for(int i = 0; i < CANT; i++)
    {
        printf("%s\n",matriz[i]);
    }
    return 0;
}
