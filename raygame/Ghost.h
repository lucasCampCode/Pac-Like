#pragma once
#include "Agent.h"
#include "SeekPathBehavior.h"
#include "WanderPathBehavior.h"
#include "InRangeDecision.h"
#include "WanderDecision.h"
#include "seekCollectDecision.h"
#include "seekTargetDecision.h"
#include "CompareDesicion.h"

class Maze;
class DecisionBehavior;

class Ghost : public Agent
{
public:
	/// <param name="x">The x-position</param>
	/// <param name="y">The y-position</param>
	/// <param name="speed">The maximum movement speed (magnitude)</param>
	/// <param name="color">The color in 0xRRGGBBAA</param>
	/// <param name="maze">The maze used for pathfinding</param>
	Ghost(float x, float y, float speed, int color, Maze* maze);
	~Ghost();

	virtual void update(float deltaTime) override;
	virtual void draw() override;

	virtual void onCollision(Actor* other) override;

	void setCollectable(Actor* collectable);
	Actor* getCollectable() { return m_collectable; }

	/// <returns>The current target</returns>
	Actor* getTarget();
	/// <summary>
	/// Set the target of the ghost
	/// </summary>
	/// <param name="target">The new target</param>
	void setTarget(Actor* target);

	SeekPathBehavior* getTargetPathFind() { return m_pathfindBehavior; }
	SeekPathBehavior* getcollectPathFind() { return m_collectBehavior; }
	WanderPathBehavior* getWander() { return m_wander; }
	int collected = 0;
private:

	Maze* m_maze;

	float m_speedBoost = 50.0f;

	SeekPathBehavior* m_pathfindBehavior;
	SeekPathBehavior* m_collectBehavior;
	WanderPathBehavior* m_wander;
	
	DecisionBehavior* m_decision;

	Actor* m_collectable = nullptr;
	Actor* m_target = nullptr;
};

