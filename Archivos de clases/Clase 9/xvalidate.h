#ifndef XVALITADE_H_INCLUDED
#define XVALIDATE_H_INCLUDED

int validateESCExit(void);
int validateExit(char text[],char Char);
int validateDualExit(char text[],char errorText[],char continueChar, char exitChar);
int validateDate(int day, int month,int year, int minYear,int maxYear);
int validateLeapYear(int year);
int validateHasDecimals(float num);
void getValidDate(char text[], char errorText[],int maxYear,int MinYear,int* daySave,int* monthSave,int* yearSave);


#endif // XVALITADE_H_INCLUDED
