#include "PathfindBehavior.h"
#include "Maze.h"

void PathfindBehavior::update(Agent* owner, float deltaTime)
{
}

void PathfindBehavior::draw(Agent* owner)
{
	NodeGraph::drawNode(m_path.back(), m_color);
}

void PathfindBehavior::updatePath(Agent* owner)
{
	updatePath(owner, m_target->getWorldPosition());
}

void PathfindBehavior::updatePath(Agent* owner, MathLibrary::Vector2 destination)
{
	NodeGraph::Node* ownerNode = m_maze->getTile(owner->getWorldPosition()).node;
	NodeGraph::Node* targetNode = m_maze->getTile(destination).node;
	m_path = NodeGraph::findPath(ownerNode, targetNode);
}
