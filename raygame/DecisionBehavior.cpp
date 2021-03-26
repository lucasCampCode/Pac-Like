#include "DecisionBehavior.h"
#include "Decision.h"
DecisionBehavior::~DecisionBehavior()
{
	delete m_root;
}
void DecisionBehavior::update(Agent* agent, float deltaTime)
{
	if (agent)
		m_root->makeDecision(agent, deltaTime);
}
