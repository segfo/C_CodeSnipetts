#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>
#include"memory.h"
#include"canvas.h"

static const Canvas InitializedCanvas = CanvasInitializer;

static void mallocFail(void *ctx){
    Canvas_Destroy((Canvas*)ctx);
}

void Canvas_Clear(Canvas *cv){
    for(size_t i=0;i<cv->w*cv->h;i++){
        cv->canvBuf[i]=' ';
    }
}

bool Canvas_Create(Canvas *cv,size_t w,size_t h){
    *cv = InitializedCanvas;
    cv->w = w;
    cv->h = h;
    cv->canvBuf = heapAlloc(sizeof(char)*(w*h),cv,mallocFail);
    cv->canvas = heapAlloc(sizeof(char*)*h,cv,mallocFail);
    if(!cv->canvBuf ||!cv->canvas){
        Canvas_Destroy(cv);
        return false;
    }
    Canvas_Clear(cv);
    for(int i=0;i<h;i++){
        cv->canvas[i] = &cv->canvBuf[i*w];
    }
    return true;
}

void Canvas_Show(Canvas *cv){
    for(int i=0;i<cv->h;i++){
        for(int j=0;j<cv->w;j++){
            putc(cv->canvas[i][j],stdout);
        }
        putc('\n',stdout);
    }
}

bool Canvas_Destroy(Canvas *cv){
    free(cv->canvBuf);
    free(cv->canvas);
    return true;
}
