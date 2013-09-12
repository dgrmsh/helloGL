#include "hero.h"
#define EPS 0.0001

GLfloat legpts[4][2] = { 
  {300.0f,100.0f},{340.0f,300.0f},
  {360.0f,300.0f},{400.0f,100.0f}
};
GLfloat handpts[4][2] = { 
  {300,280},{340,400},
  {360,400},{400,280}
};
GLfloat defaulthandpts[4][2] = {
  {350,280},{340,400},
  {360,400},{350,280}
};
GLfloat headpts[4][2] = { 
  {340,400},{300,500},
  {450,500},{360,450}
};

GLfloat st=2;

bool isWaving=false;
bool isWavingUp=false;
bool isWavingTop=false;
int numWav=0;
bool handsInSync=true;
int angleWave=0;

void movepts(GLfloat cp[][2],int left,int right) {
        if(cp[0][0]<left | cp[0][0]>right) st*=-1;
        cp[0][0]+=st;
        cp[3][0]-=st;
}
void movehands() {
  if(isWaving) {
    if(angleWave==150) {
      isWavingUp=false;
      isWavingTop=true;
    } else if(angleWave==0 && !isWavingUp){
      isWaving=false;
    } else if(angleWave==90 && !isWavingUp) {
      isWavingTop=false;
    }
    if(isWavingUp) angleWave+=3;
    else if(isWaving) angleWave-=3;
  } else {
    if(handsInSync || fabs(legpts[0][0]-350)<0.00001) { 
     if(!handsInSync) {
        memcpy(handpts,defaulthandpts,sizeof(defaulthandpts));
        handsInSync=true;
     }
     movepts(handpts,300,400);
    }
  }
}

void goupdown() {
  float x1=groundpts[1][0];
  float y1=groundpts[1][1];
  float x2=groundpts[2][0];
  float y2=groundpts[2][1];
  float xh1=legpts[0][0];
  float yh1=legpts[0][1];
  float xh2=legpts[3][0];  
  float yh2=legpts[3][1];
  float d1=((y1-y2)*xh1+(x2-x1)*yh1+(x1*y2-x2*y1))/sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
  float d2=((y1-y2)*xh2+(x2-x1)*yh2+(x1*y2-x2*y1))/sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
  int addallY=0;
  if(d1<0+EPS || d2<0+EPS) {
    addallY=2; //10+fabs(std::min(d1,d2));
  }
  if(d1>2+EPS && d2>2+EPS) {
    addallY=-2; //-std::min(d1,d2)+11;
  }
  if(addallY!=0) {
    for(int i=0;i<4;++i) {
      headpts[i][1]+=addallY;
      handpts[i][1]+=addallY;
      legpts[i][1]+=addallY;
      defaulthandpts[i][1]+=addallY;
    }
  }

}
