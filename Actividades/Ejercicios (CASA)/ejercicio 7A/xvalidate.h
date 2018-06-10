#ifndef XVALITADE_H_INCLUDED
#define XVALIDATE_H_INCLUDED


//Validacion de salida:

int validateESCExit(char* text);  //XV1-1
int validateExit(char text[],char Char);   //XV1-2
int validateDualExit(char text[],char errorText[],char continueChar, char exitChar); //XV1-3

//Dependencias validacion de fechas:

int validateLeapYear(int year);  //XV1-4
int validateDate(int day, int month,int year, int minYear,int maxYear);  //XV1-5

//Validacion de fechas:

void getValidDate(char text[], char errorText[],int maxYear,int MinYear,int* daySave,int* monthSave,int* yearSave); //XV1-6

//Validacion numeros:

int validateHasDecimals(float num);  //XV1-7

#endif // XVALITADE_H_INCLUDED
