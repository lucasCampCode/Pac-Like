#include "Agent.h"
#include "Behavior.h"
#include "raymath.h"

Agent::Agent()
	: Actor()
{
	m_maxForce = 1;
}

Agent::Agent(float x, float y, float collisionRadius, char icon, float maxSpeed, float maxForce)
	: Actor(x, y, collisionRadius, icon, maxSpeed)
{
	m_maxForce = maxForce;
}

Agent::Agent(float x, float y, float collisionRadius, Sprite* sprite, float maxSpeed, float maxForce)
	: Actor(x, y, collisionRadius, sprite, maxSpeed)
{
	m_maxForce = maxForce;
}

Agent::Agent(float x, float y, float collisionRadius, const char* spriteFilePath, float maxSpeed, float maxForce)
	: Actor(x, y, collisionRadius, spriteFilePath, maxSpeed)
{
	m_maxForce = maxForce;
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
	updateFacing();

	Actor::update(deltaTime);
}

void Agent::applyForce(MathLibrary::Vector2 force)
{
	m_force = force + m_force;

	if (m_force.getMagnitude() > m_maxForce)
		m_force = m_force.getNormalized() * m_maxForce;
}

void Agent::addBehavior(Behavior* behavior)
{
	m_behaviorList.push_back(behavior);
}
