#pragma once
#include "Actor.h"

class Wall : public Actor
{
public:
	Wall(float x, float y) : Actor(x, y, 16, 'X', 0) {}

	void draw() override;
};

