#include "WanderDecision.h"
#include "CollectPathBehavior.h"
#include "SeekPathBehavior.h"
#include "WanderPathBehavior.h"
#include "Ghost.h"
void WanderDecision::makeDecision(Agent* owner, float deltaTime)
{
	Ghost* ghost = dynamic_cast<Ghost*>(owner);
	if (ghost) {
		ghost->getcollectPathFind()->setEnabled(false);
		ghost->getTargetPathFind()->setEnabled(false);
		ghost->getWander()->setEnabled(true);

		if (ghost->getWander()->getNeedPath()) {
			MathLibrary::Vector2 destination = ghost->getWander()->destination * 32;
			ghost->getWander()->updatePath(owner, destination);
		}
		else if (ghost->getWander()->getPath().empty())
			ghost->getWander()->setNeedPath(true);
	}
}
