#include "Pac.h"
#include "Maze.h"
#include "Wall.h"
#include "raylib.h"

Pac::Pac(float x, float y, float maxSpeed)
	: Agent(x, y, Maze::TILE_SIZE / 2.5, maxSpeed, maxSpeed, (int)0xFFFF33FF)
{
	m_keyboardBehavior = new KeyboardBehavior(maxSpeed * 100);
	addBehavior(m_keyboardBehavior);
}

Pac::~Pac()
{
	delete m_keyboardBehavior;
}

void Pac::draw()
{
	//Actor::draw();
	MathLibrary::Vector2 position = getWorldPosition();
	position.x += Maze::TILE_SIZE / 2;
	position.y += Maze::TILE_SIZE / 2;
	DrawCircle(position.x, position.y, Maze::TILE_SIZE / 2, GetColor(getColor()));
}

void Pac::onCollision(Actor* other)
{
	if (Wall* wall = dynamic_cast<Wall*>(other)) {
		MathLibrary::Vector2 position = getWorldPosition();
		MathLibrary::Vector2 tilePosition = {
			roundf(position.x  / Maze::TILE_SIZE) * Maze::TILE_SIZE,
			roundf(position.y / Maze::TILE_SIZE) * Maze::TILE_SIZE
		};
		setWorldPostion(tilePosition);

		setVelocity({ 0, 0 });
	}
}
