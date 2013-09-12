#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <GL/glew.h>
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>
#include <algorithm>

#define TIMERMSECS 30

#include "draw.h"
#include "service.h"
#include "bezier.h"
#include "hero.h"
#include "ground.h"

int main(int argc, char **argv) {
 srand(time(NULL));
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
 glutInitWindowSize(800, 600);
 glutCreateWindow("Hello from Bezier curves to OpenGL");

 glewExperimental=true; 
 glewInit();
 if (!GL_VERSION_2_1) {
     fprintf(stderr, "OpenGL 2.1 not available\n");
     return 1;
 } 

 glutKeyboardFunc(keyPressed);
 glutReshapeFunc(reshape);
 glutDisplayFunc(display);
 glutTimerFunc(TIMERMSECS, idle, 0);

 glutMainLoop();

 return 0;
}
