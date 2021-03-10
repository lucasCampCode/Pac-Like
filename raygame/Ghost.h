#pragma once
#include "Agent.h"
#include "SeekBehavior.h"

class Ghost : public Agent
{
public:
	Ghost(float x, float y, float speed, int color);

	virtual void update(float deltaTime) override;
	virtual void draw() override;

	virtual void onCollision(Actor* other) override;

	void setTarget(Actor* target) { m_target = target; }
	Actor* getTarget() { return m_target; }

private:
	SeekBehavior* m_behavior = nullptr;
	Actor* m_target = nullptr;
};

