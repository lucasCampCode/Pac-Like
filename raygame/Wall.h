#pragma once
#include "Actor.h"

class Wall : public Actor
{
public:
	Wall(float x, float y) : Actor(x, y, 16, 0, 0x3333CCFF) {}

	void draw() override;
};

