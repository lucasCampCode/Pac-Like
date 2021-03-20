#pragma once
#include "Behavior.h"
#include "NodeGraph.h"

class Maze;

class PathfindBehavior : public Behavior
{
public:
	PathfindBehavior(Maze* maze) :m_maze(maze) {}

	virtual void update(Agent* owner, float deltaTime) override;
	virtual void draw(Agent* owner) override;

	void updatePath(Agent* owner);
	void updatePath(Agent* owner, MathLibrary::Vector2 destination);

	void setTarget(Actor* target) { m_target = target; }
	Actor* getTarget() { return m_target; }

	void setColor(int color) { m_color = color; }
	int getColor() { return m_color; }

protected:
	virtual MathLibrary::Vector2 findDestination(Agent* owner) = 0;

private:
	Maze* m_maze;
	std::deque<NodeGraph::Node*> m_path;

	Actor* m_target = nullptr;
	bool m_needPath = true;
	int m_color = 0xFFFFFFFF;
};

