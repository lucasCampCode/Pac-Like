#pragma once
#include "Decision.h"
class CompareDesicion :
    public Decision
{
public:
    CompareDesicion(Decision* left = nullptr, Decision* right = nullptr, int offset = 0);
    ~CompareDesicion();
    
    void makeDecision(Agent* owner, float deltaTime) override;
private:
    int m_offset;
    Decision* m_left;
    Decision* m_right;
};

