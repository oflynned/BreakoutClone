#include "Bat.h"
#include <GL\freeglut.h>

Bat::Bat() {

}

Bat::Bat(float width, float height, float x, float y) {
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;
}

Bat::~Bat(){

}

void Bat::drawBat() {
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(x, y);
	glVertex2f(x, y+height);
	glVertex2f(x+width, y+height);
	glVertex2f(x+width, y);
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
