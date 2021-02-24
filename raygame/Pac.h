#pragma once
#include "Agent.h"

class Pac : public Agent
{
public:
	Pac(float x, float y, float speed):Agent(x, x, 16, speed) {}

	virtual void draw() override;
};

