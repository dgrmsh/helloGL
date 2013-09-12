#ifndef __SERVICE__
#define __SERVICE__

#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <GL/glew.h>
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>
#include "hero.h"

extern float fps;
void calcFPS();

void drawFPS();

void keyPressed (unsigned char key, int x, int y);

void rotateVec2d(float x[2],float angle);
void translateVec2d(float x[2], float Tx[2]);

#endif
