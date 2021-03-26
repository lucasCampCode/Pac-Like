#pragma once
#include "PathfindBehavior.h"
class CollectPathBehavior :
    public PathfindBehavior
{
public:
    CollectPathBehavior(Maze* maze) : PathfindBehavior(maze) {}

protected:
    virtual MathLibrary::Vector2 findDestination(Agent* owner) override;
};

