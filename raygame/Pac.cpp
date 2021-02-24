#include "Pac.h"
#include "raylib.h"

void Pac::draw()
{
	MathLibrary::Vector2 position = getWorldPosition();
	DrawCircle(position.x + 16, position.y + 16, 16, GetColor(0xCCCC33FF));
	Actor::draw();
}
