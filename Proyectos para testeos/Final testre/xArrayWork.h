#ifndef XARRAYWORK_H_INCLUDED
#define XARRAYWORK_H_INCLUDED



/*

----------------------------ETIQUETAS DE BUSQUEDA Y SUSTITUCION------------------------------------------------->

Sustitucion automatica de campo en documentaciones:

*---->   %campo%

Sustitucion automatica de tipo de dato en documentaciones:

*---->   %tipoDeDato%

------------------------------>
* Buscar setter y getter:
------------------------------>

Enteros:       $INT$
Longs:         $LONG$
Long longs     $LONGLONG$

Flotantes:     $FLOAT$
Doubles        $DOUBLE$

Caracteres:    $CHAR$
String         $CHAR*$

------------------------------>
*Buscar constructor:
------------------------------>

Constructor:   $BUILDER$

------------------------------>
*Buscar comparadores:
------------------------------>

Comparador:               $COMP$
Buscador de igualdad:     $SAME$

---------------------------------------------------------------------------------------------------------------->

*/

//Estructura generica:


typedef struct
{
    int intNumber;
    long longNumber;
    long long longLongNumber;
    float floatNumber;
    double doubleNumber;
    char character;
    char word[100];

} eGeneric;


//Funciones para un rapida generacion de metodos constructor , set y get:

//Constructor

eGeneric* generic_newGeneric(void);

//Destructores

int generic1_PointerDestroyer( void* pointer );
int generic2_PointerDestroyer( void** pointer, int size);

//Metodos set y get:
//Entero:

int generic_setInt( eGeneric* gen , int num );
int generic_getInt( eGeneric* gen );

//Long:


//LongLong:
//Float:
//Double:
//Char:
//Char*:

//FUNCIONES ABM

eGeneric* generic_requester(void);
int generic_show(eGeneric* gen );
int generic_modify(eGeneric* gen);

//MODIFY

int eGeneric_ModifyInt(eGeneric* gen, char message[], char eMessage[]);

//COMPARADOR PARA SORT DEL ARRAY LIST

int generic_compare(void* generic1 ,void* generic2);

#endif // XARRAYWORK_H_INCLUDED
