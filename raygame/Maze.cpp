#include "Maze.h"
#include "Pac.h"
#include "KeyboardBehavior.h"

Maze::Maze()
{
	generate();

	Pac* player = new Pac(320, 320, 200);

	addActor(player);
}

void Maze::generate()
{
	for (int x = 0; x < m_size.x * 32; x += 32) {
		addActor(new Wall(x, 0));
		addActor(new Wall(x, m_size.y * 31));
	}
	for (int y = 32; y < m_size.y * 31; y += 32) {
		addActor(new Wall(0, y));
		addActor(new Wall(m_size.x * 31, y));
	}
}
