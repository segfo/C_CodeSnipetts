#include<stdio.h>
#include "fifo.h"
#include "fifoAllocator.h"

typedef struct FIFO_DATA{
	FIFO fifo;
	uint64_t msec;
}FIFO_DATA;

int main(int argc, char *argv[])
{
    FIFOAllocator fifo;
    FIFO_DATA tn[4];
    
    FIFO_Initialize((FIFO_MGR*)&fifo,sizeof(FIFO_DATA));
    FIFOAllocator_Initialize(&fifo,(FIFO*)&tn,4);
    FIFO_DATA *t0;
    t0 = (FIFO_DATA*)FIFO_Alloc(&fifo);
    t0->msec = 200;
    FIFO_DATA *t;
    t = (FIFO_DATA*)FIFO_Alloc(&fifo);
    t->msec = 100;
    FIFO_Put((FIFO*)t);
    (FIFO_DATA*)FIFO_Get((FIFO_MGR*)&fifo);
    return 0;
}
