CC=g++
CFLAGS=-framework glut -framework opengl -framework cocoa -lGLEW
CODEFILES=main.cpp draw.cpp bezier.cpp hero.cpp service.cpp ground.cpp

go: ${CODEFILES}
	${CC} ${CFLAGS} -o go ${CODEFILES}
