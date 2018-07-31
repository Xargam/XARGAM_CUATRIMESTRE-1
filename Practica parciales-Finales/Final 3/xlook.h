#ifndef XLOOK_H_INCLUDED
#define XLOOK_H_INCLUDED

//DEFINES BOOLEANOS:

#define XLK_TRUE 1
#define XLK_FALSE 0

/*
DEFINES PARA MENSAJES COMUNES:
DEFINES MAS UTILIZADOS :
*/

#define XLK_COMMON_ERROR "SE PRODUJO UN ERROR EN LA APLICACION"
#define XLK_EXITMSG "Esta seguro que desea salir? s/n: "

//DEFINES DE ERRORES Y ACIERTOS

#define XLK_FOPEN_ERROR "ERROR DURANTE APERTURA DE ARCHIVO"
#define XLK_FOPEN_OK "Apertura de archivo correcta."

#define XLK_VALID_FILE "El archivo es valido."
#define XLK_INVALID_FILE "EL ARCHIVO NO ES VALIDO"

#define XLK_FREAD_OK "Lectura del archivo exitosa."
#define XLK_FREAD_ERROR "LA LECTURA DE UN ARCHIVO FUE ERRONEA"

#define XLK_PARSER_OK "Datos leidos correctamente."
#define XLK_PARSER_ERROR "ERROR DURANTE LECTURA DE DATOS"

#define XLK_FSAVE_OK "Los datos se guardaron con exito."
#define XLK_FSAVE_ERROR "SE PRODUJO UN ERROR AL GUARDAR LOS DATOS"

#define XLK_FFIND_OK "El archivo ha sido localizado correctamente."
#define XLK_FFIND_ERROR "NO SE ENCUENTRA EL ARCHIVO"

#define XLK_MEM_OK "Reserva de memoria exitosa."
#define XLK_MEM_ERROR "ERROR AL RESERVAR MEMORIA"

#define XLK_DATALOAD_OK "Carga de datos exitosa."
#define XLK_DATALOAD_ERROR "LA CARGA DE DATOS FUE ERRONEA"

#define XLK_SYNC_OK "Sincronizacion correcta."
#define XLK_SYNC_ERROR "SINCRONIZACION INCORRECTA."

#define XLK_INVALID_DATA "Se produjo un error durante la validacion de datos."
#define XLK_VALID_DATA "Validacion exitosa."

#define XLK_VALID_ANSWER "Respuesta reconocida."
#define XLK_INVALID_ANSWER "No se reconoce su respuesta."

#define XLK_VALID_OPTION "Opcion valida."
#define XLK_INVALID_OPTION "Opcion invalida."


//FUNCIONES:

//Funciones complemento - TRABAJO CON CADENAS DE CARACTERES

void xlkStrLimitedCpy(char string[], char remainChars[] );
void xlkStringSeparator(int splitterCharacter, char* string1, char* string2 );
void xlkStringCutter(char* stringToCut, int index );
int xlkStartStringChecker(char* stringToLook,int totalArguments,...);

//Generadores de menus completos:

void xlkIndexGenerator(char head[],int totalOptions,...); //XL1-1

//Generadores de fragmentos de menu:

void xlkHeadGenerator(int mode , char* text);  //XL1-2
void xlkIndexBodyGenerator(int mode , int totalOptions,...); //XL1-3

//Funciones para mostrar mensajes:

void xlkShowMessage(char* message, int startEnters ,int endEnters, int adds ); //XL1-4
void xlkSortPrintf(int acotado,int dataLength,char* dataType,int lines,...); //XL1-6
void xlkCenterPrintf( char* word, int lines );  //XL1-7
void xlkEnterPrinter(int number);
void xlkLinePrinter(int recta);

#endif // XLOOK_H_INCLUDED
