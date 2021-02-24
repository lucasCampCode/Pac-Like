#pragma once
#include "Agent.h"

class Ghost : public Agent
{
public:
	Ghost(float x, float y, float speed, int color);

	virtual void draw() override;

	virtual void onCollision(Actor* other) override;

private:
	int m_color = 0xFFFFFFFF;
};

