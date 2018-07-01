#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>



//FUNCIONES COMPLEMENTO:



/** \brief Revisa si en el principio de una cadena se encuentra alguna de las cadenas pasadas por parametro y devuelve el numero de argumento de la cadena coincidente.
 *
 * \param stringToLook: Cadena la cual se revisara para ver si su comienzo coincide con alguna cadena de parametros.
 * \param totalArguments: Cantidad de cadenas que se pasaran a la funcion para comparar con stringToLook.
 * \param ... : Cada cadena se compara con stringToLook para ver si coincide.
 * \return Devuelve el [numero] de argumento de la cadena que se encuentra al comienzo de stringToLook.
 * \return Los argumentos son contados de izquierda a derecha. Si no hay coincidencias devuelve [-1].
 */

int xfilStartStringChecker(char* stringToLook,int totalArguments,...)
{
    int match = -1;
    if(stringToLook != NULL)
    {
        va_list arguments;
        va_start(arguments, totalArguments);

        int i;
        int j;

        for(i = 1 ; i <= totalArguments && match== -1 ; i++)
        {
            char* stringArgument = va_arg(arguments,char*);

            for(j = 0 ; stringArgument[j] != '\0'  ; j++)
            {
                match = i;
                if( stringToLook[j] != stringArgument[j] )
                {
                    match = -1;
                    break;
                }
            }
        }

        va_end(arguments);
    }
    return match;
}



/** \brief Corta una cadena desde el indice especificado.
 *
 * \param stringToCut:
 * \param index: Indice de corte. El caracter del mismo e indices a la izquierda son eliminados.
 * \return
 *
 */

void xfilStringCutter(char* stringToCut, int index )
{
    if( index > -1 && index <= strlen(stringToCut) && stringToCut != NULL)
    {
        int cutIndex = strlen(stringToCut) - index;
        strrev(stringToCut);
        stringToCut[cutIndex-1] = '\0';
        strrev(stringToCut);
    }
}



//FUNCIONES BASICAS:



/** \brief Abre un archivo binario o de texto o lo crea en caso de no existir y devuelve un valor segun accion realizada o errores.
 *
 * \param filename : nombre o ruta del archivo a sincronizar.
 * \param fileType : [0]--> Archivos de texto. [distinto de 0]-->Archivo binario.
 * \return Devuelve [1] si el archivo se pudo leer , [0] si el archivo se creo o [-1] si se produjo algun error.
 *
 */

int xfilFileSync(char* filePath, int fileType)
{
    int verify = 1;
    if(filePath != NULL)
    {
        FILE* file;
        if( fileType )
        {
            file = fopen(filePath, "rb");
            if( file == NULL)
            {
                verify = 0;
                file = fopen(filePath, "wb" );
                if( file == NULL )
                {
                    verify = -1;
                }
                else
                {
                    if( fclose(file) )
                    {
                        verify = -1;
                    }
                }
            }
            else
            {
                if( fclose(file) )
                {
                    verify = -1;
                }
            }
        }
        else
        {
            file = fopen(filePath, "r");
            if( file == NULL)
            {
                verify = 0;
                file = fopen(filePath, "w" );
                if( file == NULL )
                {
                    verify = -1;
                }
                else
                {
                    if( fclose(file) )
                    {
                        verify = -1;
                    }
                }
            }
            else
            {
                if( fclose(file) )
                {
                    verify = -1;
                }
            }
        }

    }
    return verify;

}





/** \brief Intenta abrir un archivo binario o de texto e informa del resultado.
 *
 * \param filePath : Nombre o ruta del archivo a abrir.
 * \param fileType : [0]--> Archivos de texto. [distinto de 0]-->Archivo binario.
 * \return Devuelve [1] si el archivo puedo ser abierto o [0] en caso contrario.
 *
 */

int xfilFileReader(char* filePath, int fileType)
{
    int verify = 0;
    if( filePath != NULL)
    {
        FILE* file;
        if( fileType )
        {
            file = fopen(filePath,"rb");
        }
        else
        {
            file = fopen(filePath,"r");
        }
        if( file != NULL)
        {
            verify = 1;
            if( fclose(file) )
            {
                verify = 0;
            }
        }
    }
    return verify;
}

//FUNCIONES DE PARSEO DE ARCHIVOS DE TEXTO:



/** \brief Recibe 2 cadenas y las compara, en caso de ser iguales devuelve un puntero especifico.
 *
 * \param inputString : Cadena a comparar con stringCompare.
 * \param stringCompare: Se debe comparar con inputString.
 * \param output: Puntero que se devolvera en caso de que sean iguales las cadenas.
 * \return devuelve NULL si las cadenas son distintas o el output si son iguales.
 *
 */

void* xfilStringConditionalConversor(char* inputString, char* stringCompare, void* output )
{
    void* returnPointer = NULL;
    if( stricmp(inputString, stringCompare ) == 0 )
    {
        returnPointer = output;
    }
    return returnPointer;
}



//FUNCION MADRE:



/* -------->EXPLICACION  DETALLADA ACERCA DEL USO DE LA FUNCION DE PARSEO GENERICO:

BASICO: Esta funcion debera ser utilizada en un bucle while debido a que solo parsea una linea
del archivo especificado y no mueve el puntero  a FILE. NO CERRAR EL ARCHIVO DURANTE EL PARSEO,
LA FUNCION NO MODIFICA LA POSICION DEL PUNTERO.

CADENA DE FORMATO SINTAXIS (PARAMETRO FORMAT):

Se debe pasar una cadena que especifique el tipo de dato al que se desea convertir el texto parseado.
El tipo de dato se especifica con mascaras de formato separadas por punto y coma ejemplo:

---------------
"%d;%f;%s;"
---------------

CUIDADO CON EL ORDEN:

La funcion lee el archivo desde el primer dato a parsear al ultimo.
Con el ejemplo anterior se esta diciendo que hay 3 datos a parsear y el primero se guardara EN UN PUNTERO
A ENTERO QUE DEBERA ESTAR PASADO POR PARAMETRO, el segundo se convertira a un flotante y se guardara
en un PUNTERO A FLOTANTE PASADO COMO SEGUNDO PARAMETRO. El tercer dato se conservara como string
y como parametro se debera pasar una cadena donde guardar el dato parseado.

CUIDADO CON LOS PUNTOS Y COMA!!!!:

Cada vez que se escriba una mascara de formato se debe colocar un punto y coma despues SIN EXEPCION.
La funcion utiliza guias para parsear los archivos y no respetarlas podria generar fallos
potenciales en un programa.

CUIDADO NO COLOCAR ESPACIOS EN EL FORMATO!!!!


USO DEL ESPECIFICADOR FLECHA Y CONVERSIONES ESPECIFICAS A CUALQUIER TIPO DE DATO ( --> <-- ):

¿Para que sirve el especificador flecha?
El espcificador flecha debe abrirse y cerrarse en la cadena de formato.
ejemplo:

"%d;%s;-->%s;%d;%s;%d<--%s"

Todas las mascaras encerradas por la flecha indican comparaciones y posibilidades. La flecha
que abre ( --> ) indica un argumento mas, que sera comparado con cadenas y se convertiran a un
elemento especifico en caso de ser igual a esas cadenas.

Si tenemos que parsear un archivo que tiene un dato estado que puede ser TRUE o FALSE , eso
podriamos necesitar transformarlo a un 1 o un 0. Para hacerlo usamos el especificador flecha.
La posicion de la flecha indica el puntero donde guardar el dato parseado.
EL PRIMER ARGUMENTO ES UNA CADENA CON LA QUE COMPARAR EL DATO LEIDO DEL ARCHIVO EN LA POSICION
DE LA FLECHA, EN EL EJEMPLO ANTERIOR LA CADENA SE COMPARA CON EL TERCER DATO A LEER.
TENER EN CUENTA QUE LA FUNCION SOLO UTILIZA UN PUNTERO, POR LO TANTO LAS CONVERSIONES Y LOS
CASOS QUE USES DEBERAN CONVERTIR EL DATO A UN MISMO TIPO. SIEMPRE EL ARGUMENTO ENTRE FLECHAS
QUE SEA PAR SERA EL QUE COMPARARA Y EL QUE SEA IMPAR SERA UN DATO NO PUNTERO!!!! QUE SE GUARDARA
EN EL PUNTERO DE LA FLECHA EN CASO DE QUE LA COMPARACION SEA EXITOSA.

EJEMPLOS DE USO DEL ESPECIFICADOR FLECHA Y LA FUNCION:

llamo a la funcion y parseo un archivo.

#define ARCH "empleados.csv"

El archivo tiene este estilo:

LEGAJO,SUELDO,NOMBRE,ESTADO
4589,45800.45,LEANDRO,TRUE

typedef struct
{

int legajo;
float sueldo;
char nombre[100];
int estado;

} eEmpleados;

DECLARO UNA ESTRUCTURA QUE ALBERGUE LOS DATOS QUE VOY A PARSEAR.

int main()
{


-------UTILIZO UN BUCLE WHILE QUE MIENTRAS EL PARSER DEVUELVA TRUE, la funcion
devolvera 0 cuando llegue al final del archivo. -------------------------------
//HAY QUE PASARSELO AL PARSER PARA QUE COMIENZE A LEER

eEmpleados emps[1500];
int i;

FILE* file = fopen(ARCH,"r"); //ABRO EN MODO LECTURA Y CAPTURO EL PUNTERO AL ARCHIVO.


while( csvGenericParser(file,4, "%d;%f;%s;-->%s;%d;%s;%d<--" ,8, &emps[i].legajo , &emps[i].sueldo , emps[i].nombre , &emps[i].estado , "TRUE" , 1 , "FALSE" , 0 ) )
{
i++;
}

fcolse(ARCH);

filePointer : puntero a FILE.
dataToParse: Debido a que el archivo tiene 4 datos en cada linea coloco 4 como cantidad de datos a parsear.
format:
coloco %d; para indicar que el primer dato del archivo se guarda como entero. Es el legajo.
coloco %f; para indicar que el segundo dato del archivo se guarda como flotante. Es el sueldo.
coloco %s; para indicar que el tercer dato se guarda como cadena. Es el nombre.
coloco --> para indicar que el cuarto dato se convertira en otro dato si es posible.

RECORDAR QUE LOS DATOS LEIDOS DEL ARCHIVO PRIMERO SON GUARDADOS COMO CADENA Y LUEGO TRANSFORMADOS
SEGUN LO QUE SE LE PIDA A LA FUNCION. EN EL CASO DE LA FLECHA SE DICE QUE EL ARGUMENTO CORRESPONDIENTE
A LA FLECHA NO SERA CONVERTIDO A OTRO DATO SINO QUE SE COMPARARA CON CADENAS PARA REALIZAR UNA
CONVERSION  Y EL DATO SE MOFICARA. LOS POSIBLES DATOS A LOS QUE CONVERTIR DEBEN SER DEL MISMO
TIPO.

coloco %s; para indicar el argumento 1 entre flechas ( 1 es impar) y este sera una cadena con la
que comparar el cuarto dato,
coloco %d; para indicar el argumento 2 entre flechas (2 es par), en caso de que el cuarto argumento
en forma de cadena sea igual al ARGUMENTO 1 entre flechas el cuarto dato sera igual al elemento
especificado en este argumento 2 entre flechas.
coloco %s; para indicar que si el cuarto dato llega a ser igual a esta cadena se convierta lo
que se indique en %d; mas adelante.
<-- EL CIERRE DE FLECHA INDICA QUE TERMINAN LAS ESPECIFICACIONES DE CONVERSION, luego se pueden
colocar mas mascaras o terminar el formato.

totalArguments sera 8...

tenemos 3 punteros donde guardamos los primeros 3 datos:

&emps[i].legajo , &emps[i].sueldo , emps[i].nombre

Un puntero que puede ser modificado por la flecha:

&emps[i].estado

4 argumentos entre flechas:
"TRUE" , 1 , "FALSE" , 0

Si el cuarto dato leido del archivo ( 1- lee legajo, 2 lee sueldo, 3 nombre , 4- lee estado TRUE O FALSE como cadena)
es igual a TRUE entonces el puntero &emps[i].estado recibira un 1. cON FALSE un 0.


return 0;
}


CUIDADO:

-dataToParse: No confundir este parametro con totalArguments, la funcion necesita saber cuantos
datos va a leer en una linea del archivo de texto. Si tu archivo tiene el siguiente formato:

-------------------------------
LEGAJO,NOMBRE,APELLIDO,EDAD
34,NAHUEL,MARIÑO,22
22,LEONARDO,MANASSALI,22
-------------------------------

AUNQUE PASES MAS ARGUMENTOS POR MOTIVOS DE CONVERSION DE DATOS dataToParse debe valer 4 porque
en cada linea de tu archivo hay 4 datos.

-totalArguments: PUEDE VALER MAS QUE DATATOPARSE PERO NUNCA MENOS. En caso de no realizar
conversiones con el especificador flecha debe tener el mismo numero que DATATOPARSE. Este
parametro le dice a la funcion cuantos argumentos en total vas a pasar a la funcion
INCLUYENDO los de dataToParse.
*/

/** \brief Parsea una linea de un archivo de texto (hasta 20 datos) y los guarda en punteros.
 *
 * \param filePointer: Puntero al archivo de texto que se desea parsear.
 * \param dataToParse: Cantidad de datos que se parsearan. (Max 20).
 * \param format: Se especifica tipo de datos a transformar y/o conversiones.
 * \param totalArguments: Cantidad de argumentos a pasar a la funcion. (Tener en cuenta especificador flecha)!!.
 * \param ... : La funcion soporta hasta 200 argumentos de cualquier tipo de dato.
 * \return Devuelve [1] si leyo correctamente, [0] si llego al final del archivo o [-1] en caso de un error.
 *
 */

int xfilCSVGenericParser( FILE* filePointer, int dataToParse,char* format, int totalArguments,...)
{
    int verify = -1;
    int reading;
    if( dataToParse < 21 && dataToParse > -1 && totalArguments < 201 && totalArguments > -1 && filePointer != NULL && format != NULL && strlen(format) < 1000  )
    {
        verify = 0;
        if( !feof(filePointer) )
        {
            verify = 1;
            char format2[1000];
            strcpy(format2, format);

            char matrizDatos[20][1000]; //Matriz que guarda strings con los datos leidos de una linea del archivo que se debe parsear. El parser soporta archivos de 20 datos.
            char conversionArgument[1000]; //Cuando el usuario quiere convertir un dato leido del archivo en otro string o en otro tipo de dato, se guarda en esta cadena "especial".
            char argumentToCompare[1000];  //Recibe parametros con los que se debe comparar un dato leido del archivo para transformarlo.

            //Punteros utilizados para guardar parametros:

            char* stringPointer;
            int* integerPointer;
            long* longPointer;
            long long* longLongPointer;
            float* doublePointer;
            void* pointer;

            //Numero para guardar parametros de posible conversion:

            int integerNumber; //Entero utilizado para leer argumentos que indican comparaciones de un dato del archivo.
            double doubleNumber;
            long longNumber;
            long long longLongNumber;

            int i; // Variable de iteraciones relacionada con los argumentos que se van leyendo.
            int j; // Variable de iteraciones relacionada con la matriz de datos leidos del archivo.

            int flagConversion = 0; //Bandera que indica que se estan leyendo parametros relacionados a un dato que se debe convertir.
            int flag2Conversion = 0; //Bandera que dice al programa si se esta leyendo un string a comparar o un dato que que se podria asignar a un parametro de conversion.
            int flag3 = 0; // Si se convirtio un parametro esta bandera indica que se detengan las comparaciones con los sigguientes parametros y que se dejen pasar.
            int formatReader; //Lee la cadena de formato.
            int lastFormat; // Guarda el ultimo dato de format reader.

            switch(dataToParse)
            {
            case 1:
                reading = fscanf(filePointer,"%[^\n]\n",matrizDatos[0]);
                break;
            case 2:
                reading = fscanf(filePointer,"%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1]);
                break;
            case 3:
                reading = fscanf(filePointer,"%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2]);
                break;
            case 4:
                reading = fscanf(filePointer,"%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3]);
                break;
            case 5:
                reading = fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4]);
                break;
            case 6:
                reading = fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5]);
                break;
            case 7:
                reading = fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5], matrizDatos[6]);
                break;
            case 8:
                reading = fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7]);
                break;
            case 9:
                reading = fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8]);
                break;
            case 10:
                reading = fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9]);
                break;
            case 11:
                reading = fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9],matrizDatos[10]);
                break;
            case 12:
                reading = fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9],matrizDatos[10],matrizDatos[11]);
                break;
            case 13:
                reading = fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9],matrizDatos[10],matrizDatos[11],matrizDatos[12]);
                break;
            case 14:
                reading = fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9],matrizDatos[10],matrizDatos[11],matrizDatos[12],matrizDatos[13]);
                break;
            case 15:
                reading = fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9],matrizDatos[10],matrizDatos[11],matrizDatos[12],matrizDatos[13],matrizDatos[14]);
                break;
            case 16:
                reading = fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9],matrizDatos[10],matrizDatos[11],matrizDatos[12],matrizDatos[13],matrizDatos[14],matrizDatos[15]);
                break;
            case 17:
                reading = fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9],matrizDatos[10],matrizDatos[11],matrizDatos[12],matrizDatos[13],matrizDatos[14],matrizDatos[15],matrizDatos[16]);
                break;
            case 18:
                reading = fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9],matrizDatos[10],matrizDatos[11],matrizDatos[12],matrizDatos[13],matrizDatos[14],matrizDatos[15],matrizDatos[16],matrizDatos[17]);
                break;
            case 19:
                reading = fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9],matrizDatos[10],matrizDatos[11],matrizDatos[12],matrizDatos[13],matrizDatos[14],matrizDatos[15],matrizDatos[16],matrizDatos[17],matrizDatos[18]);
                break;
            case 20:
                reading = fscanf(filePointer,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizDatos[0],matrizDatos[1],matrizDatos[2],matrizDatos[3],matrizDatos[4],matrizDatos[5],matrizDatos[6],matrizDatos[7],matrizDatos[8],matrizDatos[9],matrizDatos[10],matrizDatos[11],matrizDatos[12],matrizDatos[13],matrizDatos[14],matrizDatos[15],matrizDatos[16],matrizDatos[17],matrizDatos[18],matrizDatos[19]);
                break;
            }
            if( reading != dataToParse)
            {
                verify = -1;
            }

            va_list arguments;
            va_start(arguments, totalArguments );
            for( i = 0, j = 0; i < totalArguments && verify == 1 ; i++)
            {
                if( flagConversion )
                {
                    flag2Conversion = 1 - flag2Conversion; // si flag2 es 1 se lee argumento de comparacion , 0 se realiza comparacion y/o asignacion .
                }
                formatReader = xfilStartStringChecker(format2,11,"%s;","%c;","%d;","%i;","%ld;","%li;","%lld;","%lli;","%f;","-->","<--"); // Leo la cadena de fomato.
                if( formatReader == -1)
                {
                    verify = -1;
                    break;
                }
                xfilStringCutter(format2,2); //Corto la cadena de formato para poder leer el siguiente.
                switch(formatReader)
                {
                case 1:
                case 2:

                    if(flagConversion && flag2Conversion == 1 )
                    {
                        strcpy(argumentToCompare,va_arg(arguments,char*)); //Leo un argumento que deberia ser un string para comparar con un dato del archivo que debe convertirse.
                    }
                    else if( flagConversion && flag2Conversion == 0 )
                    {
                        lastFormat = formatReader; //Guardo el ultimo formato leido.
                        stringPointer = xfilStringConditionalConversor(conversionArgument,argumentToCompare, va_arg(arguments,char*)); //Comparo argumento a convertir con string de parametro.
                        if( stringPointer != NULL && !flag3)
                        {
                            strcpy( ((char*)pointer),stringPointer); //Si no devuelve null el conversor y flag3 es 0 (no se realizo asignacion) asigno el dato convertido.
                            flag3 = 1;
                        }
                    }
                    else if( !flagConversion)
                    {
                        stringPointer = va_arg(arguments,char*);
                        if( stringPointer != NULL)
                        {
                            strcpy(stringPointer, matrizDatos[j]);
                            j++;
                        }
                    }
                    break;
                case 3:
                case 4:
                    if( flagConversion && flag2Conversion == 0 )
                    {
                        lastFormat = formatReader;
                        integerNumber = va_arg(arguments,int);
                        integerPointer = xfilStringConditionalConversor(conversionArgument,argumentToCompare, &integerNumber );
                        if( integerPointer != NULL && !flag3)
                        {
                            *((int*)pointer) = *integerPointer;
                            flag3 = 1;
                        }
                    }
                    else if( !flagConversion )
                    {
                        integerPointer = va_arg(arguments,int*);
                        *integerPointer = atoi(matrizDatos[j]);
                        j++;
                    }
                    break;
                case 5:
                case 6:
                    if( flagConversion && flag2Conversion == 0 )
                    {
                        lastFormat = formatReader;
                        longNumber = va_arg(arguments,long);
                        longPointer = xfilStringConditionalConversor(conversionArgument,argumentToCompare, &longNumber );
                        if( longPointer != NULL  && !flag3)
                        {
                            *((long*)pointer) = *longPointer;
                            flag3 = 1;
                        }
                    }
                    else if( !flagConversion )
                    {
                        longPointer = va_arg(arguments,long*);
                        *longPointer = atol(matrizDatos[j]);
                        j++;
                    }
                    break;
                case 7:
                case 8:
                    if( flagConversion && flag2Conversion == 0  )
                    {
                        lastFormat = formatReader;
                        longLongNumber = va_arg(arguments,long long);
                        longLongPointer = xfilStringConditionalConversor(conversionArgument,argumentToCompare, &longLongNumber );
                        if( longLongPointer != NULL && !flag3)
                        {
                            *((long long*)pointer) = *longLongPointer;
                            flag3 = 1;
                        }
                    }
                    else if( !flagConversion)
                    {
                        longLongPointer = va_arg(arguments,long long*);
                        *longLongPointer = atoll(matrizDatos[j]);
                        j++;
                    }
                    break;
                case 9:
                    if( flagConversion && flag2Conversion == 0  )
                    {
                        lastFormat = formatReader;
                        doubleNumber = va_arg(arguments,double);
                        doublePointer = xfilStringConditionalConversor(conversionArgument,argumentToCompare, &doubleNumber);
                        if( doublePointer != NULL && !flag3)
                        {
                            *((double*)pointer) = *doublePointer;
                            flag3 = 1;
                        }
                    }
                    else if(!flagConversion)
                    {
                        doublePointer =(float*) va_arg(arguments,double*);
                        *doublePointer = atof(matrizDatos[j]);
                        j++;
                    }
                    break;
                case 10:
                    pointer = va_arg(arguments,void*); //Si es el caso 10 lei una flechita, que indica un puntero que debe ser cargado con el dato del archivo convertido si es posible.
                    strcpy( conversionArgument,matrizDatos[j]); //El dato de esta posicion lo guardo en el string conversionArgument para comparalo.
                    j++; //Cada vez que leo un dato de la matriz incremento el indice de iteraciones relacionado a la matriz.
                    flagConversion = 1; //Indico que lei un argumento que es de comparacion para su analisis.
                    break;
                case 11:
                    //Si es el caso 11 lei la flechita de final de parametros de conversion.
                    if(flag3 == 0) //Si la bandera es 0, el dato de conversion no se convirtio nunca, le asigno el dato que vino del archivo segun ultimo formato leido.
                    {
                        switch(lastFormat)
                        {
                        case 1:
                        case 2:
                            strcpy( ((char*)pointer), conversionArgument );
                            break;
                        case 3:
                        case 4:
                            integerNumber = atoi(conversionArgument);
                            *((int*)pointer) = integerNumber;
                            break;
                        case 5:
                        case 6:
                            longNumber = atol(conversionArgument);
                            *((long*)pointer) = longNumber;
                            break;
                        case 7:
                        case 8:
                            longLongNumber = atoll(conversionArgument);
                            *((long long*)pointer) = longLongNumber;
                            break;
                        case 9:
                            doubleNumber = atof(conversionArgument);
                            *((float*)pointer) = (float)doubleNumber;
                            break;
                        }
                    }
                    i--; //Como no se lee ningun parametro bajo la variable de iteraciones para evitar colapsos.
                    flag3 = 0; //Resstablezco todas las banderas relacionadas con argumentos de conversion.
                    flagConversion = 0;
                    flag2Conversion = 0;
                    break;
                }
            }
            va_end(arguments);
        }

    }
    return verify;
}
