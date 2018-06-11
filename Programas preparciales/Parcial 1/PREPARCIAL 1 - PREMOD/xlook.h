#ifndef XLOOK_H_INCLUDED
#define XLOOK_H_INCLUDED

//Generadores de menus completos:

void xlkIndexGenerator(char head[],int totalOptions,...); //XL1-1

//Generadores de fragmentos de menu:

void xlkHeadGenerator(int mode , char* text);  //XL1-2
void xlkIndexBodyGenerator(int mode , int totalOptions,...); //XL1-3

//Funciones para mostrar mensajes:

void xlkShowMessage(char* message , int mode); //XL1-4
void stringSeparator(int splitterCharacter, char* string1, char* string2 ); //XL1-5
void xlkSortPrintf(int mode,char* dataType, int totalArguments,...); //XL1-6
void xlkCenterPrintf(char* word, int mode);  //XL1-7


#endif // XLOOK_H_INCLUDED
