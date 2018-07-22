#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

//LIBRERIAS CON ESTRUCTURAS DE DATOS DEFINIDAS

#include "xArrayList.h"

//____________________________________________

int xPar_parseLog( arrayList* lista , char* filePath );
int xPar_parseServices( arrayList* lista, char* filePath );


#endif // PARSER_H_INCLUDED
