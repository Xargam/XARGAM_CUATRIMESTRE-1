#ifndef XFILE_H_INCLUDED
#define XFILE_H_INCLUDED

int xfiFileSync(char* filePath);
void** xfiFileLoader(char* filePath, int* quantity, int dataSize);
void* xfiNewDynamicArray(int arraySize, int dataSize );
void** xfiNewDynamicArray2(int arraySize, int dataSize );
void** xfiArrayResizer2(void** arrayToResize, int newSize);

#endif // XFILE_H_INCLUDED
