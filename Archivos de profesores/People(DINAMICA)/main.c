#include <stdio.h>
#include <stdlib.h>
#include "Person.h"


int main()
{
    int i;
    Person* personArray[10];


    for(i = 0; i < 10; i++)
    {
        personArray[i] = person_new(i,i);
    }

    for(i = 0; i < 10; i++)
    {
        person_setAge(personArray[i],i-4);
    }
    for(i = 0; i < 10; i++)
    {
        printf("\nAge: %2d",person_getAge(personArray[i]));
    }
    scanf(" ");
    return 0;
}

