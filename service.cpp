#include "service.h"
float fps;

void calcFPS() {
    static float framesPerSecond = 0.0f;
    static float lastTime = 0.0f;
    float currentTime = glutGet(GLUT_ELAPSED_TIME) * 0.001f;

    ++framesPerSecond;

    if(currentTime - lastTime > 1.0f){
        lastTime = currentTime;
        fps=framesPerSecond;
        framesPerSecond = 0;
    }   
}
void drawFPS() {
    glRasterPos2f(700,550);
    char buf[32];
    sprintf(buf,"FPS: %.2f A:%d",fps,angleWave);
    int len = (int) strlen(buf);

    for (int i = 0; i < len; i++) {
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,buf[i]);
    }   
}

void keyPressed (unsigned char key, int x, int y) {
        if(key==' ' && !isWaving) {
          isWaving=true;
          isWavingUp=true;
          numWav=60;
          angleWave=3;
          handsInSync=false;
          memcpy(handpts,defaulthandpts,sizeof(defaulthandpts));
        }       
}

#define PI 3.14159265
void rotateVec2d(float *x,float angle) {
   float newx,newy;
   angle=angle/180.0*PI;
   newx=x[0]*cos(angle)-x[1]*sin(angle);
   newy=x[0]*sin(angle)+x[1]*cos(angle);
   x[0]=newx;
   x[1]=newy;
}
void translateVec2d(float *x, float *Tx) {
  x[0]+=Tx[0];
  x[1]+=Tx[1];
}
