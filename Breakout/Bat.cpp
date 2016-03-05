#include "Bat.h"
#include <GL\freeglut.h>

Bat::Bat() {

}

Bat::Bat(float width, float height) {
	this->width = width;
	this->height = height;
}

Bat::~Bat(){

}

void Bat::drawBat() {
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glEnd();
	glFlush();
}

void Bat::move() {

}

float Bat::getX() {
	return this->x;
}

float Bat::getY() {
	return this->y;
}

void Bat::setX(float x) {
	this->x = x;
}

void Bat::setY(float y) {
	this->y = y;
}
