#pragma once
#include "Ghost.h"
class AdvanceGhost :
    public Ghost
{
public:
    AdvanceGhost(float x, float y, float speed, int color, Maze* maze);
    ~AdvanceGhost();


    virtual void onCollision(Actor* other) override;

private:

    float m_speedBoost = 0.0f;
    Actor* m_collectable = nullptr;
};

