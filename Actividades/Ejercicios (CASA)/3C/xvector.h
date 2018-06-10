#ifndef XVECTOR_H_INCLUDED
#define XVECTOR_H_INCLUDED

void xvecFShow(float vec[],int elements,char message[]);
void xvecIShow(int vec[],int elements,char message[]);
void xvecSShow(char* vec,int elements,char message[]);
void xvecFSwap(float* var1,float* var2);
void xvecISwap(int* var1,int* var2);
void xvecISort(int vec[], int elements, int criterio);
void xvecFSort(float vec[], int elements, int criterio);
int xvecIGetMaxMin(int* maxMin,int vec[], int elements, int criterio);
int xvecFGetMaxMin(float* maxMin,float vec[], int elements, int criterio);
int xvecFSpaceF(float vec[],int elements);
int xvecISpaceF(int vec[],int elements);

#endif // XVECTOR_H_INCLUDED


