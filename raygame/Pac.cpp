#include "Pac.h"
#include "Wall.h"
#include "raylib.h"

Pac::Pac(float x, float y, float maxSpeed):Agent(x, y, 16, '@', maxSpeed, maxSpeed)
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
	MathLibrary::Vector2 position = getWorldPosition();
	DrawCircle(position.x + 16, position.y + 16, 16, GetColor(0xCCCC33FF));
	Actor::draw();
}

void Pac::onCollision(Actor* other)
{
	if (Wall* wall = dynamic_cast<Wall*>(other)) {
		MathLibrary::Vector2 offset = getVelocity().getNormalized() * -33;
		setWorldPostion(wall->getWorldPosition() + offset);
		setVelocity({ 0, 0 });
	}
}
