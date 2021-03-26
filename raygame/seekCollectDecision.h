#pragma once
#include "Decision.h"
class seekCollectDecision :
    public Decision
{
public:
    void makeDecision(Agent* owner ,float deltaTime)override;
};

