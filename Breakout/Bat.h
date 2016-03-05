#pragma once
class Bat
{
private:
	float width, height;
	float x, y;

public:
	Bat();
	Bat(float width, float height, float x, float y);
	~Bat();

	void drawBat();
	void move();

	float getX();
	float getY();

	void setX(float x);
	void setY(float y);
};

