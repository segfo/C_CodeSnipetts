#include"memory.h"

void *heapAlloc(size_t size,void *ctx,void(*mallocFail)(void*ctx)){
    void *p = malloc((int)size);
    if(!p){
        mallocFail(ctx);
    }
    return p;
}
