#include "fifo.h"

const PROGMEM FIFO_MGR defFifoMgr = FIFO_MGR_Initializer;

void FIFO_Initialize(FIFO_MGR *mgr, size_t fifoEntitySize)
{
    *mgr = defFifoMgr;
    mgr->fifoEntitySize = fifoEntitySize;
    mgr->top.next = &mgr->last;
    mgr->last.prev = &mgr->top;
}

FIFO *FIFO_Get(FIFO_MGR *mgr)
{
    FIFO *data = NULL;
    if (&mgr->top != mgr->last.prev)
    {
        data = mgr->last.prev;
        mgr->last.prev = data->prev;
        data->prev->next = &mgr->last;
        data->next = NULL;
        data->prev = NULL;
        FIFO_MGR *mgr = data->mgr;
        mgr->registeredEntityCnt--;
    }
    return data;
}

bool FIFO_Put(FIFO *data)
{
    if(data == NULL){
        return false;
    }
    FIFO_MGR *mgr = data->mgr;
    // 繋ぎ変え
    data->next = mgr->top.next;
    data->next->prev = data;
    data->prev = &mgr->top;
    mgr->top.next = data;
    mgr->registeredEntityCnt++;
    return true;
}

uint64_t FIFO_RegisteredEntityCount(FIFO_MGR *mgr){
	return mgr->registeredEntityCnt;
}
