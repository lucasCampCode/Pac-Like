#include "Wall.h"
#include "raylib.h"
#include <Vector2.h>

void Wall::draw()
{
	MathLibrary::Vector2 position = getWorldPosition();
	DrawCircle(position.x + 16, position.y + 16, 16, GetColor(0x3333CCFF));
}
