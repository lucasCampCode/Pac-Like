#include "Maze.h"
#include "Pac.h"
#include "KeyboardBehavior.h"

Maze::Maze()
{
	generate();

	Pac* player = new Pac(WIDTH / 2 * TILE_SIZE, HEIGHT / 2 * TILE_SIZE, 200);

	addActor(player);
}

void Maze::generate()
{
	for (int x = 0; x < m_size.x * TILE_SIZE; x += TILE_SIZE) {
		addActor(new Wall(x, 0));
		addActor(new Wall(x, m_size.y * (TILE_SIZE-1)));
	}
	for (int y = TILE_SIZE; y < m_size.y * (TILE_SIZE - 1); y += TILE_SIZE) {
		addActor(new Wall(0, y));
		addActor(new Wall(m_size.x * (TILE_SIZE - 1), y));
	}
}
