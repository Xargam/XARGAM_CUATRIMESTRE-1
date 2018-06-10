#ifndef XVALITADE_H_INCLUDED
#define XVALIDATE_H_INCLUDED

int validateESCExit(void);
int validateExit(char text[],char Char);
int validateDualExit(char text[],char errorText[],char continueChar, char exitChar);

int validateHasDecimals(float num);


#endif // XVALITADE_H_INCLUDED
