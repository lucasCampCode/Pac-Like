#include "Ghost.h"
#include "Maze.h"
#include "Wall.h"
#include "raylib.h"

Ghost::Ghost(float x, float y, float maxSpeed, int color)
	: Agent(x, y, Maze::TILE_SIZE / 2.5, maxSpeed, maxSpeed, color)
{
	m_behavior = new SeekBehavior();
	addBehavior(m_behavior);
}

void Ghost::update(float deltaTime)
{
	if (m_target != nullptr)
		m_behavior->setDestination(m_target->getWorldPosition());

	Agent::update(deltaTime);
}

void Ghost::draw()
{
	//Agent::draw();
	MathLibrary::Vector2 position = getWorldPosition();
	position.x += Maze::TILE_SIZE / 2;
	position.y += Maze::TILE_SIZE / 2;
	DrawCircle(position.x, position.y, Maze::TILE_SIZE / 2, GetColor(getColor()));
}

void Ghost::onCollision(Actor* other)
{
	if (Wall* wall = dynamic_cast<Wall*>(other)) {
		MathLibrary::Vector2 position = getWorldPosition();
		MathLibrary::Vector2 tilePosition = {
			roundf(position.x / Maze::TILE_SIZE) * Maze::TILE_SIZE,
			roundf(position.y / Maze::TILE_SIZE) * Maze::TILE_SIZE
		};
		setWorldPostion(tilePosition);

		setVelocity({ 0, 0 });
	}
}
