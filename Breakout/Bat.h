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
	void move(int direction);

	float getX();
	float getY();
};

