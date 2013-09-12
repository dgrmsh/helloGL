#ifndef __HERO__
#define __HERO__
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <GL/glew.h>
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>
#include <algorithm>
#include "ground.h"

extern GLfloat legpts[4][2];
extern GLfloat handpts[4][2];
extern GLfloat defaulthandpts[4][2];
extern GLfloat headpts[4][2];

extern GLfloat st;

extern bool isWaving;
extern bool isWavingUp;
extern bool isWavingTop;
extern int numWav;
extern int angleWave;
extern bool handsInSync;

void movepts(GLfloat cp[][2],int left,int right);

void movehands();

void goupdown();

#endif
