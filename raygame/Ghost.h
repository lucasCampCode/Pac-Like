#pragma once
#include "Agent.h"
#include "SeekBehavior.h"
#include "PathfindBehavior.h"

class Maze;

class Ghost : public Agent
{
public:
	Ghost(float x, float y, float speed, int color, Maze* maze);
	~Ghost();

	virtual void update(float deltaTime) override;
	virtual void draw() override;

	virtual void onCollision(Actor* other) override;

	void setTarget(Actor* target);
	Actor* getTarget();

private:
	SeekBehavior* m_seekBehavior;
	PathfindBehavior* m_pathfindBehavior;
	Maze* m_maze;

	Actor* m_target = nullptr;
};

