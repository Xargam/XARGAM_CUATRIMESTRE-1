#ifndef XFILES_H_INCLUDED
#define XFILES_H_INCLUDED

//FUNCIONES COMPLEMENTO:

int xfilStartStringChecker(char* stringToLook,int totalArguments,...);
void xfilStringCutter(char* stringToCut, int index );

//FUNCIONES BASICAS:

int xfilFileSync(char* filePath, char* fileType);
int xfilFileReader(char* filePath, char* fileType);

//FUNCIONES DE PARSEO DE ARCHIVOS DE TEXTO(Prohibida):

//void* xfilStringConditionalConversor(char* inputString, char* stringCompare, void* output );

/*FUNCION MADRE(PROHIBIDAS):

int xfilCSVGenericParser(FILE* filePointer, int dataToParse,char* format, int totalArguments,...);
int xfilTextFileSaver(char* path , void* pointer);

*/



#endif // XFILES_H_INCLUDED
