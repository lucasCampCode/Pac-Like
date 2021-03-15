#include "PathfindBehavior.h"
#include "Maze.h"

void PathfindBehavior::update(Agent* owner, float deltaTime)
{
	//Don't update if disabled or no target
	if (!getEnabled() || !m_target)
		return;

	MathLibrary::Vector2 ownerPosition = owner->getWorldPosition();
	MathLibrary::Vector2 targetPosition = m_target->getWorldPosition();
	Maze::Tile ownerTile = m_maze->getTile(ownerPosition);
	Maze::Tile targetTile = m_maze->getTile(targetPosition);

	//If owner is at the destination tile, go to the next node
	if (ownerTile.position == targetTile.position) {
		m_path.pop_front();
		m_needPath = true;
	}

	//Update the path if needed
	if (m_needPath) {
		updatePath(owner, targetPosition);
	}

	//Find the direction
	MathLibrary::Vector2 direction = MathLibrary::Vector2::normalize(targetTile.position - m_path.front()->position);

	//Calculate the force
	MathLibrary::Vector2 desiredVelocity = direction * owner->getMaxSpeed();
	MathLibrary::Vector2 steeringForce = desiredVelocity - owner->getVelocity();

	//Apply the force
	owner->applyForce(steeringForce);
}

void PathfindBehavior::draw(Agent* owner)
{
	for (NodeGraph::Node* node : m_path)
	{
		NodeGraph::drawNode(node, m_color);
	}
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
	m_needPath = false;
}
