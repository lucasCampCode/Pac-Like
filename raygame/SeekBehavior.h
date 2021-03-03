#pragma once
#include "Behavior.h"
class SeekBehavior : public Behavior
{
public:
	SeekBehavior() {}

	/// <summary>
	/// Update the Behavior, affecting its owning Agent where necessary.
	/// </summary>
	/// <param name="owner">The Agent to which this Behavior belongs</param>
	/// <param name="deltaTime"></param>
	virtual void update(Agent* owner, float deltaTime) override;

	void setDestination(MathLibrary::Vector2 destination) { m_destination = destination; }
	MathLibrary::Vector2 getDestination() { return m_destination; }

private:
	MathLibrary::Vector2 m_destination;
};

