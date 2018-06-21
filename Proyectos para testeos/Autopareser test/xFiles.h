#ifndef XFILES_H_INCLUDED
#define XFILES_H_INCLUDED


//FUNCIONES COMPLEMENTO:

int startStringChecker(char* stringToLook,int totalArguments,...);
void stringCutter(char* stringToCut, int index );

//FUNCIONES BASICAS:

int fileSync(char* filename);

//FUNCIONES DE PARSEO DE ARCHIVOS DE TEXTO:

void* stringConditionalConversor(char* inputString, char* stringCompare, void* output );

//FUNCION MADRE:

int csvGenericParser(FILE* filePointer, int dataToParse,char* format, int totalArguments,...);

#endif // XFILES_H_INCLUDED
