#ifndef __BEZIER__
#define __BEZIER__

#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <GL/glew.h>
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>
#include "service.h"
#include "ground.h"
#include "hero.h"

void drawBezier(GLfloat cp[][2],int angle=0);

#endif
