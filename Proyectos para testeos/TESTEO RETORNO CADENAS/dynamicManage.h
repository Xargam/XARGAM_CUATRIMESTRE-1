#ifndef DYNAMICMANAGE_H_INCLUDED
#define DYNAMICMANAGE_H_INCLUDED

#define INITIAL_VALUE 10
#define INCREMENT_VALUE 5

typedef struct
{
    void** dynamicPointers;
    int size;
    int reservedSize;
    int (*add)();
    int (*totalFree)();
    int (*freeAll)();
    int (*len)();
    int (*freeLast)();

} dynamicManager;

dynamicManager* dyma_New(void);
int dyma_Add(dynamicManager* this , void* dynamicPointer );
int dyma_TotalFree(dynamicManager* this );
int dyma_FreeAll(dynamicManager* this );
int dyma_FreeLast(dynamicManager* this);
int dyma_resizeUp(dynamicManager* this);
int dyma_len(dynamicManager* this);
#endif // DYNAMICMANAGE_H_INCLUDED


