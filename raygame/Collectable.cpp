#include "Collectable.h"
#include "Maze.h"
#include "Wall.h"
Collectable::Collectable(float x, float y, Maze* maze)
	: Actor(x, y, Maze::TILE_SIZE / 3.0f, 0, 0x37FFFFFF)
{
	m_maze = maze;
}

void Collectable::onCollision(Actor* other)
{
	if (Wall* wall = dynamic_cast<Wall*>(other))
	{
		//gets a close random position for the next position
		float x = (rand() % Maze::WIDTH) * Maze::TILE_SIZE;
		float y = (rand() % Maze::HEIGHT) * Maze::TILE_SIZE;
		//get the new tile teh collectable will go to;
		Maze::Tile tile = m_maze->getTile(MathLibrary::Vector2(x, y));
		//set the collectable position to the new tiles position;
		setWorldPostion(m_maze->getPosition(tile));
	}
}
