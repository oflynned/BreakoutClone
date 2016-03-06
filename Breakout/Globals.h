#pragma once
class Globals {
public:
	static const int SCREEN_HEIGHT = 600;
	static const int SCREEN_WIDTH = 800;
	static const char* TITLE;

	static const float BAT_WIDTH;
	static const float BAT_HEIGHT;
	static const float BALL_WIDTH;
	static const float BALL_HEIGHT;
	static const float DELTA;
	static const float BALL_SPEED;

	static const float START_X;
	static const float START_Y;
	static const float START_X_BALL;
	static const float START_Y_BALL;

	static const int LEFT = -1;
	static const int RIGHT = 1;

	static const float UPDATE_INTERVAL;
	static const float PI;

	enum Collision
	{
		horizontal,
		vertical,
		bat
	};

	Globals();
	~Globals();
};

