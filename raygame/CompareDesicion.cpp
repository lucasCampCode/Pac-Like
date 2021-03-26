#include "CompareDesicion.h"
#include "Ghost.h"
#include "Pac.h"
CompareDesicion::CompareDesicion(Decision* left, Decision* right, int offset)
{
	m_left = left;
	m_right = right;
	m_offset = offset;
}

CompareDesicion::~CompareDesicion()
{
	delete m_left;
	delete m_right;
}

void CompareDesicion::makeDecision(Agent* owner, float deltaTime)
{
	Ghost* ghost = dynamic_cast<Ghost*>(owner);
	Pac* pac = dynamic_cast<Pac*>(ghost->getTarget());

	if (ghost) {
		if (ghost->collected < pac->collected + m_offset)
			m_left->makeDecision(owner, deltaTime);
		else
			m_right->makeDecision(owner, deltaTime);
	}
}
