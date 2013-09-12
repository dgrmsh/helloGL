#include "bezier.h"
void drawBezier(GLfloat cp[][2],int angle) {
       GLfloat x,y,t,tt,ttt,tm,tmm,tmmm;
       glBegin(GL_POINTS);
       //draw control points for easier debug =)
       glColor3f(1.0, 1.0, 0.0);
       for(int i=0;i<4;++i) {
         glVertex2f(cp[i][0],cp[i][1]);
       }

       glColor3f(1.0, 1.0, 1.0);
       if(angle>0 && !isWavingTop) {
         if(angle==90 && isWavingUp) {
           angleWave+=3;
         }
         if(angle>=90 && isWavingUp) {
           //cp[2][0]+=3;
           //cp[2][1]-=1;
           cp[1][0]+=6;
           cp[1][1]-=2;
         } if(angle>90 && !isWavingUp) {
           //cp[2][0]-=3;
           //cp[2][1]+=1;
           cp[1][0]-=7;
           cp[1][1]+=3;
         }
         float mincp2[2]={-cp[1][0],-cp[1][1]};
         float plucp2[2]={+cp[1][0],+cp[1][1]};
         translateVec2d(cp[0],mincp2);
         if(isWavingUp) { 
            rotateVec2d(cp[0],3);
         } else {
            rotateVec2d(cp[0],-3);
         }
         translateVec2d(cp[0],plucp2);
       }//} else 
       if(angle>0 && isWavingTop) {
         angleWave+=3;
         if(numWav>40) {
           cp[0][0]+=3;
           --numWav;
         } else if(numWav>20) {
           cp[0][0]-=3;
           --numWav;
         } else if(numWav>0) {
           cp[0][0]+=3;
           --numWav;
         //} else if(numWav>-50) {
         //  cp[0][0]-=3;
         //  --numWav;
         } else {
           isWavingTop=false;
           angleWave-=12;
         }
       }
       int maxsteps=1000;
       for(int i=1;i<maxsteps;++i) {
         t=i*1.0/maxsteps;
         tt=t*t;
         ttt=tt*t;
         tm=1-t;
         tmm=tm*tm;
         tmmm=tmm*tm;
         x=tmmm*cp[0][0]+3*tmm*t*cp[1][0]+3*tm*tt*cp[2][0]+ttt*cp[3][0];
         y=tmmm*cp[0][1]+3*tmm*t*cp[1][1]+3*tm*tt*cp[2][1]+ttt*cp[3][1];
         glVertex2f(x,y);
       }
       glEnd();
}
