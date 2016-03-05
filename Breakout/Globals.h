#pragma once
class Globals {
public:
	static const int SCREEN_HEIGHT = 600;
	static const int SCREEN_WIDTH = 800;
	static const char* TITLE;

	static const float BAT_WIDTH;
	static const float BAT_HEIGHT;
	static const float DX;

	static const float START_X;
	static const float START_Y;

	Globals();
	~Globals();
};

