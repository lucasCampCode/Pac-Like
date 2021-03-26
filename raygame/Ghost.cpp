#include "Ghost.h"
#include "Maze.h"
#include "Wall.h"
#include "raylib.h"
#include "DecisionBehavior.h"
Ghost::Ghost(float x, float y, float maxSpeed, int color, Maze* maze)
	: Agent(x, y, Maze::TILE_SIZE / 2.5f, maxSpeed, maxSpeed, color)
{
	m_maze = maze;
	//make the decision tree
	seekTargetDecision* seekTarget = new seekTargetDecision();
	seekCollectDecision* collect = new seekCollectDecision();
	WanderDecision* wander = new WanderDecision();
	CompareDesicion* compareColleted = new CompareDesicion(collect,wander,-3);
	InRangeDecision* targetInRange = new InRangeDecision(seekTarget, compareColleted,8);
	//set the desicion into a behavior
	m_decision = new DecisionBehavior(targetInRange);
	//set behaviors
	m_pathfindBehavior = new SeekPathBehavior(maze);
	m_collectBehavior = new SeekPathBehavior(maze);
	m_wander = new WanderPathBehavior(maze);

	m_pathfindBehavior->setColor(color);
	//add behaviors
	addBehavior(m_decision);
	addBehavior(m_collectBehavior);
	addBehavior(m_pathfindBehavior);
	addBehavior(m_wander);
}

Ghost::~Ghost()
{
	delete m_pathfindBehavior;
	delete m_collectBehavior;
	delete m_wander;
	delete m_decision;
}

void Ghost::update(float deltaTime)
{
	Agent::update(deltaTime);
}

void Ghost::draw()
{
	m_pathfindBehavior->draw(this);
	m_collectBehavior->draw(this);
	m_wander->draw(this);
	Agent::draw();
}

void Ghost::onCollision(Actor* other)
{
	if (Wall* wall = dynamic_cast<Wall*>(other)) {
		MathLibrary::Vector2 halfTile = { Maze::TILE_SIZE / 2.0f, Maze::TILE_SIZE / 2.0f };
		MathLibrary::Vector2 position = getWorldPosition();
		position = position + halfTile;
		MathLibrary::Vector2 tilePosition = {
			roundf(position.x / Maze::TILE_SIZE) * Maze::TILE_SIZE,
			roundf(position.y / Maze::TILE_SIZE) * Maze::TILE_SIZE
		};
		tilePosition = tilePosition - halfTile;
		setWorldPostion(tilePosition);

		setVelocity({ 0, 0 });
	}
	else if (Collectable* collectable = dynamic_cast<Collectable*>(other))//change position of the collectable to a new node
	{
		//gets a close random position for the next position
		float x = (rand() % Maze::WIDTH) * Maze::TILE_SIZE;
		float y = (rand() % Maze::HEIGHT) * Maze::TILE_SIZE;
		//get the new tile teh collectable will go to;
		Maze::Tile tile = m_maze->getTile(MathLibrary::Vector2(x, y));
		//set the collectable position to the new tiles position;
		collectable->setWorldPostion(m_maze->getPosition(tile));
		//addes a speed boost;
		setMaxSpeed(getMaxSpeed() + m_speedBoost);
		collected += 1;
	}
}

void Ghost::setCollectable(Actor* collectable)
{
	m_collectable = collectable;
	m_collectBehavior->setTarget(collectable);
}

void Ghost::setTarget(Actor* target)
{
	m_target = target;
	m_pathfindBehavior->setTarget(target);
}

Actor* Ghost::getTarget()
{
	return m_target;
}
