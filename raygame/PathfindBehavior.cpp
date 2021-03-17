#include "PathfindBehavior.h"
#include "Maze.h"

void PathfindBehavior::update(Agent* owner, float deltaTime)
{
	//Don't update if disabled or no target
	if (!getEnabled() || !m_target)
		return;

	//Find the positions and tiles of the owner and target
	MathLibrary::Vector2 ownerPosition = owner->getWorldPosition();
	MathLibrary::Vector2 destinationPosition = findDestination();
	Maze::Tile ownerTile = m_maze->getTile(ownerPosition);
	Maze::Tile destinationTile = m_maze->getTile(destinationPosition);

	//Update the path if needed
	if (m_needPath)
		updatePath(owner, destinationPosition);

	//Stop if there are no more nodes
	if (m_path.empty())
		return;

	//Find the position and tile of the next node
	MathLibrary::Vector2 nextPosition = m_path.front()->position;
	Maze::Tile nextTile = m_maze->getTile(nextPosition);

	//If owner is at the front node, go to the following node
	if (ownerTile.position == nextTile.position) {
		m_path.pop_front();
		m_needPath = true;
	}

	//Find the direction
	MathLibrary::Vector2 direction = MathLibrary::Vector2::normalize(m_path.front()->position - ownerPosition);

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

MathLibrary::Vector2 PathfindBehavior::findDestination()
{
	MathLibrary::Vector2 targetPosition = getTarget()->getWorldPosition();
	MathLibrary::Vector2 targetVelocity = getTarget()->getVelocity();

	return targetPosition + targetVelocity;
}
