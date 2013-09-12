#ifndef __DRAW__
#define __DRAW__
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <GL/glew.h>
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>
#include "service.h"
#include "bezier.h"
#include "hero.h"
#include "ground.h"

#define TIMERMSECS 30

void idle(int value);

void reshape(int w, int h);

void display();

#endif
