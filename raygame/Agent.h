#pragma once
#include "Actor.h"
#include <Vector2.h>
#include <vector>

class Behavior;
class Agent : public Actor
{
public:
	/// <param name="x">Position on the x axis</param>
	/// <param name="y">Position on the y axis</param>
	/// <param name="collisionRadius">The size of the circle surrounding the actor that will be used to detect collisions.</param>
	/// <param name="maxSpeed">The largest the magnitude of the actors velocity can be.</param>
	Agent(float x, float y, float collisionRadius, float maxSpeed);

	/// <summary>
	/// Update the agent and its behaviours.
	/// </summary>
	/// <param name="deltaTime"></param>
	virtual void update(float deltaTime) override;

	/// <summary>
	/// Add a behaviour to the agent.
	/// </summary>
	/// <param name="behavior"></param>
	void addBehavior(Behavior* behavior);

	/// <summary>
	/// Apply a force to the agent, affect its velocity
	/// </summary>
	/// <param name="force"></param>
	void applyForce(MathLibrary::Vector2 force) { m_force = force + m_force; }

private:
	std::vector<Behavior*> m_behaviorList;

	MathLibrary::Vector2 m_force = { 0, 0 };
};

