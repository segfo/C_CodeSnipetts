#ifndef _X_INCGUARD_X_FIFO_ALLOCATOR_H_
#define _X_INCGUARD_X_FIFO_ALLOCATOR_H_

#include "fifo.h"
#include <stdbool.h>

typedef struct FIFOAllocator{
	FIFO_MGR fifomgr;
	FIFO *array;
	FIFO *free;
}FIFOAllocator;

bool FIFOAllocator_Initialize(FIFOAllocator *falloc,FIFO *fifoPool,size_t poolLength);
FIFO *FIFO_Alloc(FIFOAllocator *falloc);
void FIFO_Dealloc(FIFOAllocator *falloc,FIFO *notifier);

#endif // _X_INCGUARD_X_FIFO_ALLOCATOR_H_