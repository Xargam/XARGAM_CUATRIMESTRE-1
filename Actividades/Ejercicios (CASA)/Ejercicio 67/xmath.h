#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

int pedirEntero(char []);
int getMax(int [],int);
int intVsort(int[], int,int);
float add(float A, float B);
float divide(float A, float B);
float subtract(float A, float B);
float multiply(float A, float B);
int factorial(int A);
void indexGenerator(int totalOptions,...);
void rangedGetInt(int* number,int minimum,int maximum,char message[],char errorMessage[]);

#endif // MATH_H_INCLUDED

