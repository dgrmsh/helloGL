#include "hero.h"
#define EPS 0.001

GLfloat groundpts[4][2] = { 
  {0.0f,50.0f},{200.0f,50.0f},
  {600.0f,50.0f},{800.0f,50.0f}
};

int h1=50;
int h2=50;

void moveground() {
 if(fabs(h1-groundpts[1][1])<EPS && fabs(h2-groundpts[2][1])<EPS) {
   h1=rand()%150;
   h2=rand()%150;
 }
 if(groundpts[1][1]-h1>EPS) {
   groundpts[1][1]-=1;
   groundpts[0][1]-=0.5;
 } else if(groundpts[1][1]-h1<-EPS) {
   groundpts[1][1]+=1;
   groundpts[0][1]+=0.5;
 }
  if(groundpts[2][1]-h2>EPS) {
   groundpts[2][1]-=1;
   groundpts[3][1]-=0.5;
 } else if(groundpts[2][1]-h2<-EPS) {
   groundpts[2][1]+=1;
   groundpts[3][1]+=0.5;
 }

}
