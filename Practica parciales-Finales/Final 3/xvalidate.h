#ifndef XVALITADE_H_INCLUDED
#define XVALIDATE_H_INCLUDED


//Validacion de salida:

int validateESCExit(char* text);  //XV1-1
int validateExit(char text[],char Char);   //XV1-2
int validateDualExit(char text[],char errorText[],char continueChar, char exitChar); //XV1-3

//Dependencias validacion de fecha y hora:

int validateLeapYear(int year);  //XV1-4
int validateDate(int day, int month,int year, int minYear,int maxYear);  //XV1-5
int validateIsNumericStr(char* cad);

//Validacion de fecha y hora:

void validate_getValidDate(char text[], char errorText[],int maxYear,int MinYear,int* daySave,int* monthSave,int* yearSave); //XV1-6
int validateIsCorrectTime(char* time,int better );

//Validacion de numeros:

int validateHasDecimals(float num);  //XV1-7
int validateIntRange(int number ,int minNumber, int maxNumber);    //XV1-8
int validateLongRange(long number ,long minNumber, long maxNumber);    //XV1-9
int validateFloatRange(float number ,float minNumber, float maxNumber);    //XV2-1

int validateIntCondition(int number ,int refNumber, int condition);    //XV2-2
int validateLongCondition(long number ,long refNumber, int condition);    //XV2-3
int validateFloatCondition(float number ,float refNumber, int condition);    //XV2-4

//Validacion de string:

int validateStringRange(char* cad , int minChars , int maxChars);  //XV2-5
int validateIsAlphanumericStr(char* word);
int validateIsAlphabeticStr(char* word);
int validateIsGraphicStr(char* word);

int validateIsNum(char* number);
int validateIsRealNum(char* number);


#endif // XVALITADE_H_INCLUDED
