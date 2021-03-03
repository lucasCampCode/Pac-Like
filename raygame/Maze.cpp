#include "Maze.h"
#include "Pac.h"
#include "Ghost.h"
#include "KeyboardBehavior.h"

Maze::Maze()
{
	generate();

	Pac* player = new Pac(WIDTH / 2 * TILE_SIZE, HEIGHT / 2 * TILE_SIZE, 200);
	addActor(player);

	Ghost* ghost = new Ghost(WIDTH / 4 * TILE_SIZE, HEIGHT / 4 * TILE_SIZE, 200, 0xFF99FFFF);
	addActor(ghost);

	ghost->setTarget(player);
}

Maze::Tile Maze::getTile(MathLibrary::Vector2 position)
{
	return m_grid[(int)(position.x / TILE_SIZE)][(int)(position.y / TILE_SIZE)];
}

MathLibrary::Vector2 Maze::getPosition(Tile tile)
{
	return MathLibrary::Vector2{ (float)(tile.x * TILE_SIZE), (float)(tile.y * TILE_SIZE) };
}

void Maze::generate()
{
	for (int y = 0; y < m_size.y; y++) {
		for (int x = 0; x < m_size.x; x++) {
			if (x == 0 || x == m_size.x - 1 || y == 0 || y == m_size.y - 1) {
				m_grid[x][y] = Tile{ x, y, 1 };
				addActor(new Wall(x * TILE_SIZE, y * TILE_SIZE));
			} else {
				m_grid[x][y] = Tile{ x, y, 0 };
			}

		}
	}
}
