#include "Wall.h"
#include "Maze.h"
#include "raylib.h"
#include <Vector2.h>

void Wall::draw()
{
	//Actor::draw();
	MathLibrary::Vector2 position = getWorldPosition();
	position.x += Maze::TILE_SIZE / 2;
	position.y += Maze::TILE_SIZE / 2;
	DrawCircle(position.x, position.y, Maze::TILE_SIZE / 2, GetColor(getColor()));
}
