#ifndef XGET_H_INCLUDED
#define XGET_H_INCLUDED

int getInt(char texto[]);
float getFloat(char texto[]);
char getChar(char texto[]);
int getRangedInt(int minimum,int maximum,char message[],char errorMessage[]);
float getRangedFloat(float minimum,float maximum,char message[],char errorMessage[] );
void getRangedStr(char* vec,char message[],char eMessage[],int minChars, int maxChars);
void getRangedSimStr(char* vec,char message[],char eMessage[],int minChars, int maxChars);



#endif // XGET_H_INCLUDED

