#pragma once
#include "Behavior.h"
#include "NodeGraph.h"

class Maze;

class PathfindBehavior : public Behavior
{
public:
	PathfindBehavior(Maze* maze) :m_maze(maze) {}

	/// <summary>
	/// Update the Behavior, affecting its owning Agent where necessary.
	/// </summary>
	/// <param name="owner">The Agent to which this Behavior belongs</param>
	/// <param name="deltaTime"></param>
	virtual void update(Agent* owner, float deltaTime) override;

	/// <summary>
	/// Draw the Behavior, primarily for debugging purposes. Agent calls
	/// this by default.
	/// </summary>
	/// <param name="owner">The Agent to which this Behavior belongs</param>
	virtual void draw(Agent* owner) override;

	/// <summary>
	/// Update the current path to the target.
	/// This is called by update(Agent*,float).
	/// </summary>
	/// <param name="owner">The Agent to which this Behavior belongs</param>
	void updatePath(Agent* owner);
	/// <summary>
	/// Update the current path to the given destination.
	/// This is called by update(Agent*,float).
	/// </summary>
	/// <param name="owner">The Agent to which this Behavior belongs</param>
	/// <param name="destination">The new destination</param>
	void updatePath(Agent* owner, MathLibrary::Vector2 destination);

	/// <returns>The current target to use in pathfinding</returns>
	Actor* getTarget() { return m_target; }
	/// <summary>
	/// Set the target to a new actor.
	/// </summary>
	/// <param name="target">The actor to use in pathfinding</param>
	void setTarget(Actor* target) { m_target = target; }

	int getColor() { return m_color; }
	void setColor(int color) { m_color = color; }
	std::deque<NodeGraph::Node*> getPath() { return m_path; }
	bool getNeedPath() { return m_needPath; }
	void setNeedPath(bool value) { m_needPath = value; }
protected:
	virtual MathLibrary::Vector2 findDestination(Agent* owner) = 0;

	Maze* m_maze;
private:
	std::deque<NodeGraph::Node*> m_path;

	Actor* m_target = nullptr;
	bool m_needPath = true;
	int m_color = 0xFFFFFFFF;
};

