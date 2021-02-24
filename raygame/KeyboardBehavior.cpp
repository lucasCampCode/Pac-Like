#include "KeyboardBehavior.h"
#include "raylib.h"
#include <Vector2.h>

void KeyboardBehavior::update(Agent* owner, float deltaTime)
{
    MathLibrary::Vector2 force = { 0.0f, 0.0f };

    if (IsKeyDown(KEY_W))
        force.y = -m_speedIncrement;
    if (IsKeyDown(KEY_S))
        force.y = m_speedIncrement;
    if (IsKeyDown(KEY_A))
        force.x = -m_speedIncrement;
    if (IsKeyDown(KEY_D))
        force.x = m_speedIncrement;

    owner->applyForce(force);
}
