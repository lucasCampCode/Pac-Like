#include "Maze.h"

Maze::Maze()
{
	generate();

	Pac* player = new Pac(
		WIDTH / 2 * TILE_SIZE + (TILE_SIZE / 2),
		HEIGHT / 2 * TILE_SIZE + (TILE_SIZE / 2),
		200
	);
	addActor(player);

	Ghost* ghost = new Ghost(
		WIDTH / 4 * TILE_SIZE + (TILE_SIZE / 2),
		HEIGHT / 4 * TILE_SIZE + (TILE_SIZE / 2),
		200,
		0xFF99FFFF,
		this
	);
	addActor(ghost);

	ghost->setTarget(player);
}

void Maze::draw()
{
	//NodeGraph::drawGraph(m_grid[0][0].node);
	Scene::draw();
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
			// Create the tile
			Tile current{ x, y };
			current.node = new NodeGraph::Node();
			current.node->position = { x * TILE_SIZE + (TILE_SIZE / 2.0f), y * TILE_SIZE + (TILE_SIZE / 2.0f) };
			// Designate walls and open spaces
			if (x == 0 || x == m_size.x - 1 || y == 0 || y == m_size.y - 1) {
				addActor(new Wall(current.node->position.x, current.node->position.y));
				current.cost = 1.0f;
			}
			else {
				current.cost = 0.0f;
			}
			// Add node to graph
			if (x > 0) { // west connection
				Tile other = m_grid[x - 1][y];
				current.node->connections.push_back(NodeGraph::Edge{ other.node, other.cost });
				other.node->connections.push_back(NodeGraph::Edge{ current.node, current.cost });
			}
			if (y > 0) { // north connection
				Tile other = m_grid[x][y - 1];
				current.node->connections.push_back(NodeGraph::Edge{ other.node, other.cost });
				other.node->connections.push_back(NodeGraph::Edge{ current.node, current.cost });
			}
			// Set the tile on the grid
			m_grid[x][y] = current;
		}
	}
}
