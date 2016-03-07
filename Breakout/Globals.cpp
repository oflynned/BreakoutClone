#include "Globals.h"

const char* Globals::TITLE = "Breakout!";

const float Globals::BAT_WIDTH = 0.1f;
const float Globals::BAT_HEIGHT = 0.025f;
const float Globals::BALL_WIDTH = 0.025f;
const float Globals::BALL_HEIGHT = 0.025f;
const float Globals::DELTA = 0.025f;
const float Globals::BALL_SPEED = 0.0001f;

const float Globals::START_X = -BAT_WIDTH / 2;
const float Globals::START_Y = -0.9f;
const float Globals::START_X_BALL = -BALL_WIDTH / 2;
const float Globals::START_Y_BALL = -BALL_HEIGHT / 2;

const float Globals::UPDATE_INTERVAL = 30.0f;
const float Globals::PI = 3.14f;

const float Globals::BOX_HEIGHT = 0.15f;
const float Globals::BOX_WIDTH = 0.15f;

Globals::Globals()
{
}


Globals::~Globals()
{
}
