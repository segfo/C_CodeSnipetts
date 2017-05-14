#ifndef _X_INCGUARD_X_FIFO_H_
#define _X_INCGUARD_X_FIFO_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#if defined(WINVER) || defined(__linux__)
#define PROGMEM static
#endif

#define FIFO_MGR_Initializer {NULL}

typedef struct FIFO
{
    struct FIFO *next;
    struct FIFO *prev;
    struct FIFO_MGR *mgr;
} FIFO;

typedef struct FIFO_MGR
{
    FIFO top;
    FIFO last;
    size_t fifoEntitySize;
    uint64_t registeredEntityCnt;
} FIFO_MGR;

void FIFO_Initialize(FIFO_MGR *mgr, size_t fifoEntitySize);
FIFO *FIFO_Get(FIFO_MGR *mgr);
bool FIFO_Put(FIFO *data);
uint64_t FIFO_RegisteredEntityCount(FIFO_MGR *mgr);

#endif // _X_INCGUARD_X_FIFO_H_