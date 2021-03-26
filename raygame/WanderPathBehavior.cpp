#include "wanderPathBehavior.h"
#include "Maze.h"
#include "Wall.h"
MathLibrary::Vector2 WanderPathBehavior::findDestination(Agent* owner)
{
    float x = (rand() % Maze::WIDTH) * Maze::TILE_SIZE;
    float y = (rand() % Maze::HEIGHT) * Maze::TILE_SIZE;
    Maze::Tile tile = m_maze->getTile({ x, y});
    Wall* wall = dynamic_cast<Wall*>(tile.actor);
    while (!wall) {
        x = (rand() % Maze::WIDTH) * Maze::TILE_SIZE;
        y = (rand() % Maze::HEIGHT) * Maze::TILE_SIZE;
        tile = m_maze->getTile({x, y});
        wall = dynamic_cast<Wall*>(tile.actor);
    }
    destination = m_maze->getPosition(tile);
    return m_maze->getPosition(tile);
}
