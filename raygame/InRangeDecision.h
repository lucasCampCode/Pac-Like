#pragma once
#include "Decision.h"
class InRangeDecision :
    public Decision
{
public:
    InRangeDecision(Decision* left, Decision* right, float radius);
    ~InRangeDecision();
    void makeDecision(Agent* agent, float deltaTime) override;
private:
    float m_radius;
    Decision* m_left;
    Decision* m_right;
};

