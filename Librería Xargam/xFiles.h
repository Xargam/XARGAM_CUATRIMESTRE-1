#ifndef XFILES_H_INCLUDED
#define XFILES_H_INCLUDED

//FUNCIONES COMPLEMENTO:

int xfilStartStringChecker(char* stringToLook,int totalArguments,...);
void xfilStringCutter(char* stringToCut, int index );

//FUNCIONES BASICAS:

int xfilFileSync(char* filename);

//FUNCIONES DE PARSEO DE ARCHIVOS DE TEXTO:

void* xfilStringConditionalConversor(char* inputString, char* stringCompare, void* output );

//FUNCION MADRE:

int xfilCSVGenericParser(FILE* filePointer, int dataToParse,char* format, int totalArguments,...);

//FUNCIONES DE ARCHIVOS BINARIOS:



#endif // XFILES_H_INCLUDED
