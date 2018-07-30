#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "xArrayList.h"

/*

Información de utilidad:

Entero:

--->TAMAÑO DE UNA CADENA QUE GUARDE UN INT : 8 caracteres o [7 en caso justo].
--->TAMAÑO DE UNA CADENA QUE GUARDE UN LONG : 13 caracteres o [12 en caso justo].
--->TAMAÑO DE UNA CADENA QUE GUARDE UN LONG LONG: 22 caracteres o [21 en caso justo].
*/

//Estructura generica:

typedef struct
{
    int campo1;
    long campo15;
    float campo2;
    char campo3[50];
    char campo4[30];
    char campo5[20];

} eGenerica;

//Setters , getters y constructor genericos:

eGenerica* generica_newGenerica(void);
int generica_setCampo1(eGenerica* gen , int entero );
int generica_setCampo15( eGenerica* gen, long largo);
int generica_setCampo3( eGenerica* gen, char* palabra);

int generica_getCampo1( eGenerica* gen );
char* generica_getCampo3( eGenerica* gen );
long generica_getCampo15( eGenerica* gen );

//____________________________________________

// Parsers para modificar:

int xpar_parseGenerica( arrayList* lista , char* filePath );
int xpar_unparseGenerica( arrayList* lista , char* filePath );


#endif // PARSER_H_INCLUDED
