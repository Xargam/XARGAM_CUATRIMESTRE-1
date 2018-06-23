#ifndef XLOOK_H_INCLUDED
#define XLOOK_H_INCLUDED

//DEFINES PARA MENSAJES COMUNES:

#define XLK_TRUE 1
#define XLK_FALSE 0
#define XLK_FOPEN_ERROR "ERROR DURANTE APERTURA DE ARCHIVO"
#define XLK_FREAD_OK "Lectura del archivo exitosa."
#define XLK_PARSER_ERROR "ERROR DURANTE LECTURA DE ARCHIVO"
#define XLK_FSAVE_ERROR "ERROR DURANTE ESCRITURA DE ARCHIVO"
#define XLK_FFIND_ERROR "NO SE ENCUENTRA EL ARCHIVO"
#define XLK_INVALID "Se produjo un error durante la validacion de los datos."
#define XLK_EXITMSG "Esta seguro que desea salir? s/n: "

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
void xlkEnterPrinter(int number);
void xlkMessageAutoSwitch(int switchNumber , int arguments, ...);
#endif // XLOOK_H_INCLUDED
