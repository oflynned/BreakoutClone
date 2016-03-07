#pragma once
class Box
{
private:
	int id;
	float x, y;
	float width, height;
	bool hit, destroyed;
public:
	Box();
	Box(int id, float x, float y, float width, float height);
	~Box();

	enum Colour
	{
		RED, GREEN, BLUE, YELLOW, ORANGE
	};

	void drawBox(Colour colour);
	void setColour(Colour colour);

	void setHit(bool hit);
	bool isHit();
	void setDestroyed(bool destroyed);
	bool isDestroyed();
};

