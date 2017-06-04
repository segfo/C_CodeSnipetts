#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>
#include"canvas.h"

/////////////////////////

void drawTriangleFill(Canvas *cv){
    int c = cv->w/2;
    cv->canvas[0][c]='+';
    for(int i=1;i<cv->h;i++){
        for(int j=0;j<1+2*i;j++){
            cv->canvas[i][c-i+j]='+';
        }
    }
}

void drawTriangle(Canvas *cv){
    int c = cv->w/2;
    cv->canvas[0][c]='+';
    for(int i=1;i<cv->h-1;i++){
        cv->canvas[i][c-i]='+';
        cv->canvas[i][c-i+(2*i)]='+';
    }
    for(int i=0;i<cv->w;i++){
        cv->canvas[cv->h-1][i]='+';
    }
}
//////////////////////////
int main(int argc,char *argv[]){
    Canvas cv;
    int n=5;

    if(argc>1){
        n = atoi(argv[1]);
    }

    n = (n<2)?2:n;
    bool initialized = Canvas_Create(&cv,(n-1)+n,n);
    if(!initialized){
        printf("memory allocation fail.\n");
        exit(1);
    }
    drawTriangleFill(&cv);
    Canvas_Show(&cv);
    Canvas_Clear(&cv);
    printf("\n");
    drawTriangle(&cv);
    Canvas_Show(&cv);
    Canvas_Destroy(&cv);
    return 0;
}