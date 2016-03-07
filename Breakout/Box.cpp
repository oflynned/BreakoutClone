#include "Box.h"
#include "GL\freeglut.h"

Box::Box(){}

Box::Box(int id, float x, float y, float width, float height) {
	this->id = id;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

Box::~Box(){}

void Box::drawBox(Box::Colour colour) {
	glBegin(GL_QUADS);
	setColour(colour);
	glVertex2f(x, y);
	glVertex2f(x, y + height);
	glVertex2f(x + width, y + height);
	glVertex2f(x + width, y);
	glEnd();
	glFlush();
}

void Box::setColour(Box::Colour colour) {
	switch (colour) {
	case Box::BLUE:
		glColor3f(0.0f, 0.0f, 1.0f);
		break;
	case Box::GREEN:
		glColor3f(0.0f, 1.0f, 0.0f);
		break;
	case Box::RED:
		glColor3f(1.0f, 0.0f, 0.0f);
		break;
	default:
		glColor3f(0.0f, 0.0f, 0.0f);
		break;
	}
}

void Box::setHit(bool hit) { this->hit = hit; }
bool Box::isHit() { return hit; }
void Box::setDestroyed(bool destroyed) { this->destroyed = destroyed; }
bool Box::isDestroyed() { return destroyed; }
