#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED


//____________________________________________

//Parsers:

int xPar_parseLog( arrayList* lista , char* filePath );
int xPar_parseServices( arrayList* lista, char* filePath );

//Unparsers:

int xPar_unParseErrors( arrayList* services , arrayList* log , char* filePath );

#endif // PARSER_H_INCLUDED
