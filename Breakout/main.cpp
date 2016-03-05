#include <Windows.h>
#include <GL/freeglut.h>

#include "Ball.h"
#include "Bat.h"
#include "Environment.h"
#include "Globals.h"

void initialiseGL(int argc, char** argv);
void display(void);
void draw();
void garbageCollection();

bool isDone = false;

Bat* bat = new Bat(0.1f, 0.1f, 0.1f, 0.1f);

int main(int argc, char** argv) {
	initialiseGL(argc, argv);
	glutDisplayFunc(display);
	glutMainLoop();

	/*while (!isDone) {
		//check input
		//update
		//draw
	}*/

	garbageCollection();
	return 0;
}

void initialiseGL(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(Globals::SCREEN_WIDTH, Globals::SCREEN_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(Globals::TITLE);
	glClearColor(1, 1, 1, 1);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	draw();
	glutSwapBuffers();
}

void draw() {
	bat->drawBat();
}

void garbageCollection() {
	delete(bat);
}