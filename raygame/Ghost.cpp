#include "Ghost.h"
#include "Wall.h"
#include "raylib.h"

Ghost::Ghost(float x, float y, float maxSpeed, int color):Agent(x, y, 16, 'G', maxSpeed, maxSpeed)
{
	m_color = color;
}

void Ghost::draw()
{
	MathLibrary::Vector2 position = getWorldPosition();
	DrawCircle(position.x + 16, position.y + 16, 16, GetColor(m_color));
	Actor::draw();
}

void Ghost::onCollision(Actor* other)
{
	if (Wall* wall = dynamic_cast<Wall*>(other)) {
		MathLibrary::Vector2 offset = getVelocity().getNormalized() * -33;
		setWorldPostion(wall->getWorldPosition() + offset);
		setVelocity({ 0, 0 });
	}
}
