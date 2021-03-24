#pragma once
#include "Actor.h"
class Maze;
class Collectable :
    public Actor
{
public:
    Collectable(float x, float y, Maze* maze);

    virtual void onCollision(Actor* other) override;
private:
    Maze* m_maze;
};

