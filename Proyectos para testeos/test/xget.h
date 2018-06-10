#ifndef XGET_H_INCLUDED
#define XGET_H_INCLUDED


/*
_________IMPORTANTE: Para buscar una funcion en xget.c buscar por ID de la funcion. EJEMPLO XG1-1.______________________

#---------------DATOS DE INTERES---------------------------------------------------------------------------------------#

*MINIMO NUMERO FLOTANTE:

0.00000000000000000000000000000000000001175494350822287507968736537222245677818665556772087521508751706278417259454
7271728515625

Contiene 126 numeros decimales.

#----------------------------------------------------------------------------------------------------------------------#

*MAXIMO NUMERO FLOTANTE:

340282346638528859811704183484516925440.000000

Contiene 39 numeros enteros.

#--------------TABLAS--------------------------------------------------------------------------------------------------#

TIPOS DE DATOS Y SU PESO:
--------------------------------------------------
TIPO               BITS   BYTES  RANGO DECIMAL
--------------------------------------------------
char	            8	   1     -128 a 127
unsigned char	    8	   1      0 a 255
signed char 	    8	   1     -128 a 127
short       	    16	   2     -32768 a 32767
int 	            32	   4     -32768 a 32767
unsigned int 	    32	   4      0 a 65535
signed int       	32	   4     -32768 a 32767
short int	        16	   2     -32768 a 32767
unsigned short int	16	   2      0 a 65535
signed short int	16	   2     -32768 a 32767
long int	        32	   4     -2147483648 a 2147483647
signed long int	    32	   4     -2147483648 a 2147483647
unsigned long int	32	   4      0 a 4294967295
long	            32	   4     -2147483648 a 2147483647
unsigned long	    32	   4      0 a 4294967295
float	            32	   4      3.4E-38 a 3.4E+38
double	            64	   8      1.7E-308 a 1.7E+308
long double	        80     10     1.7E-308 a 1.7E+308 o 3.4E-4932 a 1.1E+4932

#----------------------------------------------------------------------------------------------------------------------#
*/

//Funciones complemento - validaciones requeridas por otras funciones:

int validateIsNum(char* number);               //XG1-1
int validateIsRealNum(char* number);           //XG1-2
int validateIsAlphabetic(char* word);          //XG1-2.1
void zeroFixer(char* number);                       //XG1-3
int strNumCmp(char* number1, char* number2);        //XG1-4

//Pedir string:

int getRangedStr(char* word ,int minChars,int maxChars,char *message,char *eMessage, int mode);           //XG1-5
int getRangedAlphaStr(char *word,int minChars, int maxChars, char *message,char *eMessage,int mode);      //XG1-6

//Pedir numeros o caracteres sin validar:

int getInt(char* texto);              //XG1-7
long getLong(char* texto);            //XG1-8
float getFloat(char* texto);          //XG1-9
char getChar(char* texto);            //XG2-1

//Pedir numeros o caracteres y validarlos:

int getValidInt(int* number,char* message, char* errorMessage);                  //XG2-2
int getValidLong(long* number,char* message, char* errorMessage);                //XG2-3
int getValidFloat(float* number,char* message, char* errorMessage);              //XG2-4
int getValidLongLong(long long* number,char* message, char* errorMessage);       //XG2-5

//Pedir numeros condicionados:

int getRangedInt(int* number, int minimum,int maximum,char* message,char* errorMessage);                 //XG2-6
int getRangedLong(long* number,long minimum,long maximum,char* message,char* errorMessage);              //XG2-7
int getRangedFloat(float* number,float minimum,float maximum,char* message,char* errorMessage);          //XG2-8
int getRangedChar(char* character,char minimum, char maximum ,char* message,char* eMessage, int mode );            //XG2-8.1

int getConditionedInt(int* number,int refNumber,int condition,char* message,char* errorMessage);         //XG2-9
int getConditionedFloat(float* number,float refNumber,int condition,char* message,char* errorMessage);   //XG3-1
int getConditionedLong(long* number,long refNumber,int condition,char* message,char* errorMessage);      //XG3-2

// Otras:

int getGenre(char* character,char* text,char* errorText);       //XG3-3

#endif // XGET_H_INCLUDED
