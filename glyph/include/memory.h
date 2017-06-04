#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

void *heapAlloc(size_t size,void *ctx,void(*mallocFail)(void*ctx));