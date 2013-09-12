#include "draw.h"

void idle(int value) {
        glutTimerFunc(TIMERMSECS, idle, 0); 
        calcFPS();
        if(!isWaving || fabs(legpts[0][0]-350)>10) {
          moveground();
          movepts(legpts,290,410);
          goupdown();
        }
        movehands();
        glutPostRedisplay();
}

void reshape(int w, int h)
{
        glViewport(0, 0, w, h); 
            
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, w, 0, h); 
            
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
}

void display()
{
        glClear(GL_COLOR_BUFFER_BIT);
        glPointSize(5.0);
        
        drawBezier(groundpts,0);
        drawBezier(handpts,angleWave);
        drawBezier(legpts,0);
        drawBezier(headpts,0);
        
        glFlush();
        drawFPS();
        glutSwapBuffers();
}
