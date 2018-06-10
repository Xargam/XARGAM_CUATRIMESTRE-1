#ifndef XLOOK_H_INCLUDED
#define XLOOK_H_INCLUDED

//Generadores de menus completos:

void xlkIndexGenerator(char head[],int totalOptions,...); //XL1-1

//Generadores de fragmentos de menu:

void xlkHeadGenerator(char text[]);  //XL1-2
void xlkIndexBodyGenerator(int totalOptions,...); //XL1-3


#endif // XLOOK_H_INCLUDED
