#pragma once
#include "Behavior.h"

class KeyboardBehavior : public Behavior
{
public:
	KeyboardBehavior(float speed):m_speedIncrement(speed) {};
	virtual ~KeyboardBehavior() {};

	virtual void update(Agent* owner, float deltaTime) override;

private:
	float m_speedIncrement = 50.0f;
};

