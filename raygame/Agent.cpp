#include "Agent.h"
#include "Behavior.h"
#include "raymath.h"

Agent::Agent(float x, float y, float collisionRadius, float maxSpeed):Actor(x, y, collisionRadius, 'O', maxSpeed)
{
}

void Agent::update(float deltaTime)
{
	// Reset force to zero
	m_force = { 0,0 };

	// For each Behavior in Behavior list...
	for (int i = 0; i < m_behaviorList.size(); i++) {
		// Update that behavior
		m_behaviorList[i]->update(this, deltaTime);
	}

	// Add force times delta time to velocity
	setVelocity(getVelocity() + m_force * deltaTime);

	Actor::update(deltaTime);
}

void Agent::addBehavior(Behavior* behavior)
{
	m_behaviorList.push_back(behavior);
}
