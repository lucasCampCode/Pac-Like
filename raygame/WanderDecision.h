#pragma once
#include "Decision.h"
class WanderDecision :
    public Decision
{
public:
    void makeDecision(Agent* owner, float deltaTime)override;

};

