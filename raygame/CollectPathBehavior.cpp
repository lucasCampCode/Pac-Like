#include "CollectPathBehavior.h"
#include "Ghost.h"
MathLibrary::Vector2 CollectPathBehavior::findDestination(Agent* owner)
{
    Ghost* ghost = dynamic_cast<Ghost*>(owner);
    if (owner)
        return ghost->getCollectable()->getWorldPosition();
}
