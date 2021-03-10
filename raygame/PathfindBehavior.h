#pragma once
#include "Behavior.h"
#include "Maze.h"
#include <Vector2.h>
#include <vector>

class PathfindBehavior : public Behavior
{
public:
	PathfindBehavior() {}

	virtual void update(Agent* owner, float deltaTime) override;
	virtual void draw(Agent* owner) override;
};

