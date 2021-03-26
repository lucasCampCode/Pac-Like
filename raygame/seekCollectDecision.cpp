#include "seekCollectDecision.h"
#include "Ghost.h"
void seekCollectDecision::makeDecision(Agent* owner, float deltaTime)
{
	Ghost* ghost = dynamic_cast<Ghost*>(owner);
	if (ghost && ghost->getCollectable()) {
		ghost->getcollectPathFind()->setEnabled(true);
		ghost->getTargetPathFind()->setEnabled(false);
		ghost->getWander()->setEnabled(false);

		if (ghost->getcollectPathFind()->getNeedPath()) {
			ghost->getcollectPathFind()->updatePath(owner);
		}
		else if(ghost->getcollectPathFind()->getPath().empty())
			ghost->getcollectPathFind()->setNeedPath(true);
	}
}
