#ifndef XGET_H_INCLUDED
#define XGET_H_INCLUDED


//¡IMPORTANTE! Para buscar una funcion en xget.c buscar por ID de la funcion. EJEMPLO XG1-1 .

/*
#---------------DATOS DE INTERES---------------------------------------------------------------------------------------------------------#

*MINIMO NUMERO FLOTANTE:

0.000000000000000000000000000000000000011754943508222875079687365372222456778186655567720875215087517062784172594547271728515625

Contiene 126 numeros decimales.

#----------------------------------------------------------------------------------------------------------------------------------------#

*MAXIMO NUMERO FLOTANTE:

340282346638528859811704183484516925440.000000

Contiene 46 numeros enteros.

#----------------------------------------------------------------------------------------------------------------------------------------#
*/

//Funciones complemento: validar correcta escritura de un numero:

int validateIsNum(char number[]);               //XG1-1
int validateIsRealNum(char* number);            //XG1-2
void zeroFixer(char* vec);                      //XG1-3
int strNumCmp(char vec1[], char vec2[]);        //XG1-4

//Pedir string:

void getRangedStr(int minChars,int maxChars,char message[],char eMessage[],char* vec );          //XG1-5
void getRangedSimStr(int minChars, int maxChars, char message[],char eMessage[],char* vec);      //XG1-6

//Pedir numeros o caracteres sin validar:

int getInt(char texto[]);              //XG1-7
long getLong(char texto[]);            //XG1-8
float getFloat(char texto[]);          //XG1-9
char getChar(char texto[]);            //XG2-1

//Pedir numeros y validarlos:

int getValidInt(char message[], char errorMessage[]);                  //XG2-2
long getValidLong(char message[], char errorMessage[]);                //XG2-3
float getValidFloat(char message[], char errorMessage[]);              //XG2-4
long long getValidLongLong(char message[], char errorMessage[]);       //XG2-5

//Pedir numeros condicionados:

int getRangedInt(int minimum,int maximum,char message[],char errorMessage[]);                  //XG2-6
long getRangedLong(long minimum,long maximum,char message[],char errorMessage[]);              //XG2-7
float getRangedFloat(float minimum,float maximum,char message[],char errorMessage[]);          //XG2-8

int getConditionedInt(int refNumber,int condition,char message[],char errorMessage[]);         //XG2-9
float getConditionedFloat(float refNumber,int condition,char message[],char errorMessage[]);   //XG3-1
long getConditionedLong(long refNumber,int condition,char message[],char errorMessage[]);      //XG3-2

// Otras:

char getGenre(char text[],char errorText[]);       //XG3-3

//Biblioteca input:

int inputGetInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);            //XG3-4
int inputGetFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit);    //XG3-5
int inputGetChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit);        //XG3-6
int inputGetString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);        //XG3-7

#endif // XGET_H_INCLUDED
