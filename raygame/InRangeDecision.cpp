#include "InRangeDecision.h"
#include "Decision.h"
#include "Ghost.h"
#include "Maze.h"
InRangeDecision::InRangeDecision(Decision* left, Decision* right, float radius)
{
	m_left = left;
	m_right = right;
	m_radius = radius;
}

InRangeDecision::~InRangeDecision()
{
	delete m_left;
	delete m_right;
}

void InRangeDecision::makeDecision(Agent* agent, float deltaTime)
{
	Ghost* ghost = dynamic_cast<Ghost*>(agent);

	if (ghost) {
		float distance = (ghost->getWorldPosition() - ghost->getTarget()->getWorldPosition()).getMagnitude();
		if (distance < m_radius * Maze::TILE_SIZE)
			m_left->makeDecision(agent, deltaTime);
		else
			m_right->makeDecision(agent, deltaTime);
	}
}

