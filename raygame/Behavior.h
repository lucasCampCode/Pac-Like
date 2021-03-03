#pragma once
#include "Agent.h"

class Behavior
{
public:
	Behavior() {}

	/// <summary>
	/// Update the Behavior, affecting its owning Agent where necessary.
	/// </summary>
	/// <param name="owner">The Agent to which this Behavior belongs</param>
	/// <param name="deltaTime"></param>
	virtual void update(Agent* owner, float deltaTime) = 0;
};

