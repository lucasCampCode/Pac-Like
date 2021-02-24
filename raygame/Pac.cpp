#include "Pac.h"
#include "KeyboardBehavior.h"
#include "Wall.h"
#include "raylib.h"

Pac::Pac(float x, float y, float speed):Agent(x, x, 16, speed)
{
	KeyboardBehavior* keyboardBehavior = new KeyboardBehavior(speed * 100);
	addBehavior(keyboardBehavior);
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
