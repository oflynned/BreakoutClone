#pragma once
#include "Globals.h"
class Ball
{
private:
	float width, height;
	float x, y, velocity;
	int direction;
	bool collision;

public:
	Ball();
	Ball(float width, float height, float x, float y, float velocity);
	~Ball();

	void drawBall();
	void move(float batX, float batY);
	void collide(Globals::Collision collision);

	float getX();
	float getY();
};

