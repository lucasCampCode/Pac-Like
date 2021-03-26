#pragma once
#include "PathfindBehavior.h"
class WanderPathBehavior :
    public PathfindBehavior
{
public:
    WanderPathBehavior(Maze* maze) : PathfindBehavior(maze) {}
    MathLibrary::Vector2 destination;
protected:
    virtual MathLibrary::Vector2 findDestination(Agent* owner) override;
private:
};

