typedef struct
{
    int intNumber;
    char character;

} eGeneric;

//Funciones

//BASICA

eGeneric* generic_newGeneric(int size);
eGeneric** generic_newGenericDblPointer(int size);

//Destructores

int generic1_PointerDestroyer( void* pointer );
int generic2_PointerDestroyer( void** pointer, int size);

//Funciones SET

int generic_setInt( eGeneric* gen , int num );

//FUNCIONES GET

int generic_getInt( eGeneric* gen );

//FUNCIONES ABM

eGeneric* generic_requester(void);
int generic_show(eGeneric* gen );
int generic_showAll(eGeneric* gen , int quantity);
int generic_modify(eGeneric* gen);

//MODIFY

int eGeneric_ModifyInt(eGeneric* gen, char message[], char eMessage[]);

//BUSCAR DATOS

int eGeneric_checkInt(eGeneric* gen , int data);

//COMPARAR ESTRUCTURAS

int generic_compare(void* generic1 ,void* generic2);

