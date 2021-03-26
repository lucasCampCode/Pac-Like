#pragma once
#include "Agent.h"
#include "KeyboardBehavior.h"
class Maze;
class Pac : public Agent
{
public:
	/// <param name="x">The x-position</param>
	/// <param name="y">The y-position</param>
	/// <param name="speed">The maximum movement speed (magnitude)</param>
	Pac(float x, float y, float speed, Maze* maze);
	~Pac();

	virtual void draw() override;

	virtual void onCollision(Actor* other) override;

	int collected = 0;
private:

	float m_speedBoost = 25.0f;

	KeyboardBehavior* m_keyboardBehavior;
	Maze* m_maze = nullptr;
};

