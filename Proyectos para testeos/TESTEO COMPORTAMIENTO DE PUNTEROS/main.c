#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{

    int num;
    char vec[50];
    float flotante;

} empleado ;

int main()
{

/*
a* es un puntero;
a* tiene basura, su contenido es una direccion de memoria.
a* recibe datos de la direccion de memoria de int 4
a* contiene en su interior la direccion 0x45 que es la direccion de un entero
el elemento de a* es una direccion de memoria, el elemento de *a (la direccion que contiene es 4)

d** = variable doble puntero guarda una direccion doble puntero(dos referencias hasta un dato no puntero, si se accede al elemento del doble puntero se llega a un puntero, si accede al elemento del puntero recien se llega al dato). ( es decir la direccion de memoria de una variable puntero)
d** tiene basura
d** recibe la direccion de memoria de una variable puntero &a es la zona en memoria donde se guarda a, que es 0x100 en
0x100 esta la variable a -> su valor, lo que guarda a es 0x45 que es la direccion de un entero, 4
 d** tiene 0x456

d** esta en 0x988, El valor de d es 0x100 (direccion de memoria de un puntero)
a esta en 0x100. El valor de a es 0x45 (direccion de memoria de un entero)
entero esta en 0x45. entero tiene el valor 4.
*/
    /*---ANALISIS 1:

    SI SE LIBERA UNA DIRECCION DE MEMORIA LA MISMA QUEDA INABILITADA. CRASH.
    YA NO SE PUEDE ACCEDER A SU CONTENIDO. ESTA QUEDA  EN NULL.

    ---ANALISIS 2:

    EL TIPO DE DATO DEL PUNTERO MARCA LA ARITMETICA DEL MISMO...
    QUIERE DECIR QUE SI ES DE TIPO ENTERO Y SE LE SUMA UNO A LA DIR. LA MAQUINA SABE QUE DEBE
    MOVERSE ENTRE DIRECCIONES SALTANDO DE A 4 BYTES. SE SUPONE QUE EL PROGRAMADOR GUARDARA ENTEROS
    EN ESAS DIRECCIONES....

    ---ANALISIS 3:

    EL NOMBRE DEL PUNTERO ES UNA FORMA FANTASIOSA DE LLAMAR A SU DIREECCION DE MEMORIA...
    TAL COMO CUALQUIER VARIABLE. CUANDO HACEMOS UNA ASIGNACION GUARDAMOS UN ELEMENTO QUE QUEPA
    EN LA VARIABLE. EN CUALQUIER PUNTERO SOLO CABE UNA DIRECCION DE MEMORIA DE 4 BYTES.

    ---ANALISIS 4:

    UN PUNTERO ES UNA VARIABLE QUE GUARDA UNA DIRECCION  DE MEMORIA , SOLO UNA. NO HACE MAS QUE ESO....
    CUANDO HACEMOS MALLOC O REALLOC Y DECIMOS SIZEOF(ESTRUCTURA20BYTES)*50, EL PUNTERO GUARDA LA PRIMER
    DIRECCION Y NADA MAS. LAS OTRAS SOLO QUEDAN RESERVADAS Y ACCESIBLES... CON LA PRIMER DIRECCION
    PODEMOS LLEGAR A LAS OTRAS. PERO EL PUNTERO SOLO TIENE LA PRIMERA Y SIEMPRE SERA ASI.

    ---ANALISIS 5:

    punt+1 = (punt+2) NO SE PUEDE HACER PORQUE NOSOSTROS DECLARAMOS UNA VARIABLE PUNTERO QUE ALAMACENA
    UNA DIRECCION DE 4 BYTES Y REALIZA ARITMETICA DE A 4 BYTES(SIZE DE UN INT)
    PUNT + 1 , NO ES NINGUNA VARIABLE, ES UNA DIRECCION QUE EXISTE EN LA COMPUTADORA, PERO NO
    LA TENEMOS GUARDADA EN NINGUNA VARIABLE PUNTERO POR ELLO NO PODEMOS ASIGNARLE OTRA DIRECCION.
    SI PODEMOS MODIFICAR EL CONTENIDO DE ALGUNA DIRECCION DE MEMEORIA CUALQUIERA. AHORA PARA
    PODER HACER ASIGNACIONES TENEMOS QUE TENER DONDE HACERLAS Y PUNT + 1 NO ES UNA VARIABLE
    ES UNA DIRECCION DE MEMORIA QUE NO TENEMOS GUARDADA EN VARIABLES... ¿COMO LE ASIGNAMOS ALGO?

    ---ANALISIS 6:

    UN PUNTERO NO ES UN ARRAY... ES UNA VARIABLE QUE GUARDA UNA DIRECCION DE MEMORIA. NOSOSTROS
    PODEMOS USARLO COMO ARRAY POR QUE PODEMOS MOVERNOS ENTRE DIRECCIONES GRACIAS A LA ARITMETICA.
    Y A LA CAPACIDAD DE MOFICAR CONTENIDOS DE DIRECCIONES CON EL OPERADOR DE INDIRECCION...

    ---ANALISIS 7:

    UN ARRAY DE PUNTEROS ES UN DOBLE PUNTERO ** QUE PUEDE DECLARARSE ASI ESTATICAMENTE
    CHAR* VEC[50];  VEC[0] GUARDA UN PUNTERO. VEC[1] OTRO. ES UN ARRAY QUE PUEDE GUARDAR
    DIRECCIONES DE MEMORIA. NO UNA VARIABLE COMO LO ES UN PUNTERO. LA VENTAJA ES QUE A PARTIR
    DE CADA PUNTERO QUE GUARDA EL DOBLE PUNTERO PODEMOS RESERVAR MAS DIRECCIONES DEL MISMO
    TIPO Y MOVERNOS A TRAVES DE ELLAS. POR ELLO  TIENE DOBLE DIMENSION COMO UNA MATRIZ.

    ---ANALISIS 8:

    PUNTEROS DOBLES: EL CONTENIDO DEL NOMBRE ES UN PUNTERO. SI AL NOMBRE SE LE HACE ARITMETICA
    SE ESTARIA UNO MOVIENDO ENTRE DOBLES PUNTEROS. DOBLEPUNTERO+1 ,ES LOGICO QUE SI EL NOMBRE
    ES UN DOBLE PUNTERO, ESO REPRESENTE OTRO DOBLE PUNTERO POR ARITMETICA DE TIPO DE DATO (**)

    ---ANALISIS 9:

    */
    //empleado* doblePuntero = malloc(sizeof(empleado*)*5 );
    int** punt = malloc(sizeof(int*)*5);
    //ASIGNO UN DIRECCION DE MEMORIA QUE TIENE CONTIGUAS OTRAS 4.
    //TRABAJAR MATRICES CON PUNTEROS PARA COMPRENDERLOS:

    char** matriz = (char**)malloc(sizeof(char*) * 10000); //ERROR RESERVO 5 VARIABLES DE TIPO PUNTERO DOBLE... Y GUARDO LA DIR DE LA PRIMERA.
    char* palabra1 = malloc(sizeof(char)*50); //50 CHARS DIRECCIONES
*(*punt)= 65;
int* rescue = &(*(*punt));
free(punt);
printf("%d",*rescue);
system("pause");

int* ele = malloc(sizeof(int)*5);
*(ele+1) = 55;
*(ele+2) = 54;
*(ele+3) = 53;
*(ele+4) = 52;

printf("ELE 1: %d\n ",ele+1);
    printf("ELE 1: %d\n",*(ele+1) );
    printf("ELE 2: %d\n",ele+2 );
    printf("ELE 2: %d\n",*(ele+2) );
    printf("ELE 3: %d\n",ele+3 );
    printf("ELE 3: %d\n",*(ele+3) );
    printf("ELE 4: %d\n",ele+4);
    printf("ELE 4: %d\n",*(ele+4));
    system("pause");
*matriz = malloc(sizeof(char)*50);
free(*matriz);
strcpy( *(matriz) , "hola");


printf("EL MAT 1: %s\n ",*matriz ) ;
printf("EL MAT 1: %s\n ",*matriz ) ;
printf("EL MAT 2: %d\n ",matriz+2 );
printf("EL MAT 2: %d\n ", &matriz[2]);


    system("pause");
// matriz + 0 es un doble puntero que guarda un puntero
//matriz + 1 es una sub

    printf("PUNT 0 %d\n\n",*punt);

    //punt + 2 = ele; ES UNA DIR QUE NO ESTA ALMACENADA. PERO ES UN PUNTERO A ENTERO.
    *(punt + 2) = malloc(sizeof(int*)*5);

    *(*(punt + 2)) = 45;

    //NO punt+1 = (punt+2) ;

    printf("PUNT 2 %d\n\n",*(punt+2) );
    printf("PUNT 2 %d\n\n",*(*(punt+2)) );
    system("pause");

    free(punt);
    /*
    f*or(int i = 0 ; i < 5 ; i++)
    {
            printf("DIR EMP: %d",emp+ i);
        printf("\n\nINGRESE ENTERO: ");
        scanf("%d",&emp->num+i);
        punt = &(emp+i)->num;
        free(emp + i);
    }
    for(int i = 0 ; i < 5 ; i++)
    {
        printf("\nDIR DE EMP: %d", punt->num );
        system("pause");
    }
    */

    return 0;
}
