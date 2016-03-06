#include "Ball.h"
#include "Globals.h"

#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "GL\freeglut.h"

Ball::Ball() {

}

Ball::Ball(float width, float height, float x, float y, float velocity) {
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;
	this->velocity = velocity;
	collision = false;

	srand(time(NULL));
	this->direction = rand() % 360 + 1;
}

Ball::~Ball() {

}

void Ball::drawBall() {
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(x, y);
	glVertex2f(x, y + height);
	glVertex2f(x + width, y + height);
	glVertex2f(x + width, y);
	glEnd();
	glFlush();
}

void Ball::move(float batX, float batY) {
	if (getX() > batX  && getX() < batX + Globals::BAT_WIDTH) {
		if (getY() <= batY + Globals::BAT_HEIGHT) {
			collide(Globals::Collision::bat);
		}
	}

	if (getX() <= -1 || getX() >= 1) {
		collide(Globals::Collision::vertical);
	}

	if (getY() <= -1 || getY() >= 1) {
		collide(Globals::Collision::horizontal);
	}

	x += std::cos(direction * Globals::PI / 180) * Globals::DELTA;
	y += std::sin(direction * Globals::PI / 180) * Globals::DELTA;

	//printf("ball angle: %i\n", direction);
	//printf("ball x: %f\n", getX());
	//printf("ball y: %f\n", getY());
}

void Ball::collide(Globals::Collision collision) {
	switch (collision) {
	case Globals::Collision::bat:
	case Globals::Collision::horizontal:
		direction = 360 - direction;
		break;
	case Globals::Collision::vertical:
		direction = 180 - direction;
		break;
	}
}

float Ball::getX() {
	return this->x;
}

float Ball::getY() {
	return this->y;
}
