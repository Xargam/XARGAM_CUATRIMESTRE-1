#ifndef XVECTOR_H_INCLUDED
#define XVECTOR_H_INCLUDED


//Funciones de busqueda de numero maximo o minimo:

int xvecIGetMaxMin(int vec[], int elements, int criterio);  //XV1-1
float xvecFGetMaxMin(float vec[], int elements, int criterio); //XV1-2

//Funciones de ordenamiento:

void xvecISort(int vec[], int elements, int criterio);  //XV1-3
void xvecFSort(float vec[], int elements, int criterio);  //XV1-4

//Funciones de muestra:

void xvecIShow(int vec[],int elements,char message[]);   //XV1-5
void xvecFShow(float vec[],int elements,char message[]);  //XV1-6

//Funciones de swapeo:

void xvecISwap(int* var1,int* var2);   //XV1-7
void xvecFSwap(float* var1,float* var2);  //XV1-8
void xvecSSwap(char cad1[],char cad2[]);  //XV1-9

//Funciones de busqueda de espacio (Elemento 0):

int xvecISpaceF(int vec[],int elements);  //XV2-1
int xvecFSpaceF(float vec[],int elements); //XV2-2

#endif // XVECTOR_H_INCLUDED
