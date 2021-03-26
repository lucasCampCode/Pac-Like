#pragma once
#include "Decision.h"
class seekTargetDecision :
    public Decision
{
public:
    void makeDecision(Agent* owner, float deltaTime)override;
};

