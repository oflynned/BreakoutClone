#include <GL\freeglut.h>
#include <iostream>
#include <Windows.h>
#include <vector>

#include "Ball.h"
#include "Bat.h"
#include "Box.h"
#include "Environment.h"
#include "Globals.h"

void initialiseGL(int argc, char** argv);
void display();
void handleInputs(unsigned char key, int x, int y);
void update(int value);
void draw();
void garbageCollection();

bool isDone = false;
bool* keyStates = new bool[256];

Bat* bat = new Bat(Globals::BAT_WIDTH, Globals::BAT_HEIGHT, Globals::START_X, Globals::START_Y);
Ball* ball = new Ball(Globals::BALL_WIDTH, Globals::BALL_HEIGHT, Globals::START_X_BALL, Globals::START_Y_BALL, Globals::BALL_SPEED);
std::vector<Box*> boxHolder;

int main(int argc, char** argv) {
	for (int i = 0; i < 12; i++) {
		boxHolder.push_back(new Box(i, -1.0f + i * 0.15 + 0.0181 * i, 1 - Globals::BOX_HEIGHT, Globals::BOX_HEIGHT, Globals::BOX_WIDTH));
	}

	initialiseGL(argc, argv);
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutTimerFunc(Globals::UPDATE_INTERVAL, update, 0);
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
		if (bat->getX() > -1 + Globals::DELTA * 3) {
			bat->move(Globals::LEFT);
		}
		else if (bat->getX() == -1 + Globals::DELTA * 3) {
			bat->move(Globals::STOP);
		}
	} else if (key == 'd') {
		if (bat->getX() + Globals::BAT_WIDTH < 1 - Globals::DELTA * 3) {
			bat->move(Globals::RIGHT);
		}
		else if (bat->getX() + Globals::BAT_WIDTH == 1 - Globals::DELTA * 3) {
			bat->move(Globals::STOP);
		}
	} else if(key == VK_ESCAPE) {
		exit(0);
	}
}

void update(int value) {
	//ball->move(bat->getX(), bat->getY());
	glutPostRedisplay();
	glutTimerFunc(Globals::UPDATE_INTERVAL, update, 0);
}

void draw() {
	bat->drawBat();
	ball->drawBall();
	for each (Box* box in boxHolder)
	{
		box->drawBox(Box::Colour::RED);
	}
}

void garbageCollection() {
	delete(bat);
	delete(ball);
}