#include "fifo.h"
#include "fifoAllocator.h"

bool FIFOAllocator_Initialize(FIFOAllocator *falloc,FIFO *fifoPool,size_t poolLength){
	void *extFifo = fifoPool;
    FIFO_MGR *mgr = (FIFO_MGR*) &falloc->fifomgr;
    if (poolLength == 0)
    {
        return false;
    }
    size_t i=0;
	for(;i<poolLength-1;i++){
		((FIFO*)extFifo)->next = (FIFO*)(extFifo + mgr->fifoEntitySize);
        ((FIFO *)extFifo)->mgr = mgr;
        extFifo += mgr->fifoEntitySize;
	}
	((FIFO*)extFifo)->next = NULL;
    ((FIFO *)extFifo)->mgr = mgr;

	// ここからちょいややこしい。（意味が微妙に違う）
	falloc->array = fifoPool; // これは純粋に静的配列を指す。tna->array[n]でアクセス可能。
	falloc->free = fifoPool; // これは空き領域リスト（動的配列）を指す。
    return true;
}

FIFO *FIFO_Alloc(FIFOAllocator *falloc){
	FIFO *q = falloc->free;
	if(q){
		falloc->free = q->next;
		q->next = NULL;
	}
	return q;
}

void FIFO_Dealloc(FIFOAllocator *falloc,FIFO *notifier){
	FIFO *e = (FIFO*) notifier;
	e->next = (FIFO*)falloc->free;
	falloc->free = (FIFO*)e;
	return;
}
