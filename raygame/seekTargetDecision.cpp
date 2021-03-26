#include "seekTargetDecision.h"
#include "Ghost.h"
void seekTargetDecision::makeDecision(Agent* owner, float deltaTime)
{
	Ghost* ghost = dynamic_cast<Ghost*>(owner);
	if (ghost) {
		ghost->getcollectPathFind()->setEnabled(false);
		ghost->getTargetPathFind()->setEnabled(true);
		ghost->getWander()->setEnabled(false);

		if (ghost->getTargetPathFind()->getNeedPath()) {
			ghost->getTargetPathFind()->updatePath(owner);
		}
		else if(ghost->getTargetPathFind()->getPath().empty())
			ghost->getTargetPathFind()->setNeedPath(true);
	}

}
