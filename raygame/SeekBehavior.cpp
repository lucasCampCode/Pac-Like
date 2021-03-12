#include "SeekBehavior.h"
#include "Maze.h"
#include "raylib.h"

void SeekBehavior::update(Agent* owner, float deltaTime)
{
	//Don't update if disabled
	if (!getEnabled())
		return;

	MathLibrary::Vector2 position = owner->getWorldPosition();
	MathLibrary::Vector2 destination = getDestination();

	//If owner is at the destination, exit
	if (position == destination)
		return;

	//Find the direction
	MathLibrary::Vector2 direction = MathLibrary::Vector2::normalize(destination - position);

	//Calculate the force
	MathLibrary::Vector2 desiredVelocity = direction * owner->getMaxSpeed();
	MathLibrary::Vector2 steeringForce = desiredVelocity - owner->getVelocity();

	//Apply the force
	owner->applyForce(steeringForce);
}

void SeekBehavior::draw(Agent* owner)
{
	MathLibrary::Vector2 position = owner->getWorldPosition();
	position.x += Maze::TILE_SIZE / 2;
	position.y += Maze::TILE_SIZE / 2;
	DrawCircle(position.x, position.y, Maze::TILE_SIZE / 2, GetColor((int)this));
}

