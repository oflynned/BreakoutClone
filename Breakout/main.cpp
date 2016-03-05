#include <GL\freeglut.h>
#include <iostream>
#include <Windows.h>

#include "Ball.h"
#include "Bat.h"
#include "Environment.h"
#include "Globals.h"

void initialiseGL(int argc, char** argv);
void display();
void handleInputs(unsigned char key, int x, int y);
void draw();
void garbageCollection();

bool isDone = false;
bool* keyStates = new bool[256];

Bat* bat = new Bat(Globals::BAT_WIDTH, Globals::BAT_HEIGHT, Globals::START_X, Globals::START_Y);
Ball* ball = new Ball();

int main(int argc, char** argv) {
	initialiseGL(argc, argv);
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop();
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

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutKeyboardFunc(handleInputs);
	draw();
	glutSwapBuffers();
	glFlush();
}

void handleInputs(unsigned char key, int x, int y) {
	printf("bat x: %f\n", bat->getX());
	if(key == 'a') {
		if (bat->getX() > -1 + Globals::DELTA * 3 && bat->getX() + Globals::BAT_WIDTH < 1 - Globals::DELTA * 3) {
			printf("'a' pressed\n");
			bat->move(Globals::LEFT);
		}
	} else if (key == 'd') {
		if (bat->getX() > -1 + Globals::DELTA * 3 && bat->getX() + Globals::BAT_WIDTH < 1 - Globals::DELTA * 3) {
			printf("'d' pressed\n");
			bat->move(Globals::RIGHT);
		}
	} else if(key == 27) {
		printf("ESC pressed\n");
		exit(0);
	}
}

void draw() {
	bat->drawBat();
}

void garbageCollection() {
	delete(bat);
	delete(ball);
}