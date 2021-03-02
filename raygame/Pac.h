#pragma once
#include "Agent.h"
#include "KeyboardBehavior.h"

class Pac : public Agent
{
public:
	Pac(float x, float y, float speed);
	~Pac();

	virtual void draw() override;

	virtual void onCollision(Actor* other) override;

private:
	KeyboardBehavior* m_keyboardBehavior;
};

