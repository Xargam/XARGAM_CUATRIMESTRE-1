typedef struct
{
    int intNumber;
    long longNumber;
    long long longLongNumber;
    float floatNumber;
    double doubleNumber;
    char character;
    char vec[100];

} eGeneric;

//Funciones

//BASICA

eGeneric* generic_newGeneric(int size);
eGeneric** generic_newGenericDblPointer(int size);

//Destructores

int generic1_PointerDestroyer( void* pointer );
int generic2_PointerDestroyer( void** pointer, int size);
int generic3_PointerDestroyer( void*** pointer, int size);
int generic4_PointerDestroyer( void**** pointer, int size);
int generic5_PointerDestroyer( void***** pointer, int size);

//Funciones SET

int generic_setInt( eGeneric* gen , int num, char* eMessage );
int generic_setLong( eGeneric* gen , long num, char* eMessage );
int generic_setLongLong( eGeneric* gen , long long num, char* eMessage );
int generic_setFloat( eGeneric* gen , float num, char* eMessage );
int generic_setDouble( eGeneric* gen , double num, char* eMessage );
int generic_setChar( eGeneric* gen , char character, char* eMessage );
int generic_setString( eGeneric* gen , char* string, char* eMessage  );

//FUNCIONES GET

int generic_getInt( eGeneric* gen );
long generic_getLong( eGeneric* gen );
long long generic_getLongLong( eGeneric* gen );
float generic_getFloat( eGeneric* gen );
double generic_getDouble( eGeneric* gen );
char generic_getChar( eGeneric* gen );
char* generic_getString( eGeneric* gen );

//FUNCIONES ABM

eGeneric* generic_requester(void);
int generic_show(eGeneric* gen );
int generic_showAll(eGeneric* gen , int quantity);
