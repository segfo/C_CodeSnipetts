typedef struct Canvas{
    char *canvBuf;
    char **canvas;
    size_t w;
    size_t h;
}Canvas;

bool Canvas_Create(Canvas *cv,size_t w,size_t y);
bool Canvas_Destroy(Canvas *cv);
void Canvas_Clear(Canvas *cv);
void Canvas_Show(Canvas *cv);
#define CanvasInitializer {NULL,NULL,0,0}
