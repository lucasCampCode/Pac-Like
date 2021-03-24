#include "AdvanceGhost.h"
#include "Maze.h"
#include "Wall.h"
#include "Collectable.h"
AdvanceGhost::AdvanceGhost(float x, float y, float speed, int color, Maze* maze)
	: Ghost(x, y, speed, color, maze)
{

}

AdvanceGhost::~AdvanceGhost()
{
	Ghost::~Ghost();

}

void AdvanceGhost::onCollision(Actor* other)
{
	if (Wall* wall = dynamic_cast<Wall*>(other)) {
		MathLibrary::Vector2 halfTile = { Maze::TILE_SIZE / 2.0f, Maze::TILE_SIZE / 2.0f };
		MathLibrary::Vector2 position = getWorldPosition();
		position = position + halfTile;
		MathLibrary::Vector2 tilePosition = {
			roundf(position.x / Maze::TILE_SIZE) * Maze::TILE_SIZE,
			roundf(position.y / Maze::TILE_SIZE) * Maze::TILE_SIZE
		};
		tilePosition = tilePosition - halfTile;
		setWorldPostion(tilePosition);

		setVelocity({ 0, 0 });
	}
	else if (Collectable* collectable = dynamic_cast<Collectable*>(other))//change position of the collectable to a new node
	{
		//gets a close random position for the next position
		float x = (rand() % Maze::WIDTH) * Maze::TILE_SIZE;
		float y = (rand() % Maze::HEIGHT) * Maze::TILE_SIZE;
		//get the new tile teh collectable will go to;
		Maze::Tile tile = m_maze->getTile(MathLibrary::Vector2(x, y));
		//set the collectable position to the new tiles position;
		collectable->setWorldPostion(m_maze->getPosition(tile));
	}
}
