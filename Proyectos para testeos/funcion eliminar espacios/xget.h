#ifndef XGET_H_INCLUDED
#define XGET_H_INCLUDED

int getInt(char texto[]);
float getFloat(char texto[]);
char getChar(char texto[]);
int validateIIsNum(char number[]);
int validateFIsNum(char number[]);
int getRangedInt(int minimum,int maximum,char message[],char errorMessage[]);
float getRangedFloat(float minimum,float maximum,char message[],char errorMessage[] );
void getRangedStr(int minChars,int maxChars,char message[],char eMessage[],char* vec );
void getRangedSimStr(int minChars, int maxChars, char message[],char eMessage[],char* vec);
float getValidFloat(char message[], char errorMessage[]);
int getValidInt(char message[], char errorMessage[]);


#endif // XGET_H_INCLUDED

