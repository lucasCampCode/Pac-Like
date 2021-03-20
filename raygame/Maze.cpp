#include "Maze.h"

Maze::Maze(float grid[Maze::WIDTH][Maze::HEIGHT])
{
	generate(grid);

	m_player = new Pac(
		WIDTH / 2 * TILE_SIZE + (TILE_SIZE / 2),
		HEIGHT / 2 * TILE_SIZE + (TILE_SIZE / 2),
		200
	);
	m_red = new Ghost(
		WIDTH / 4 * TILE_SIZE + (TILE_SIZE / 2),
		HEIGHT / 4 * TILE_SIZE + (TILE_SIZE / 2),
		200,
		0xFF6666FF,
		this
	);
	m_red->setTarget(m_player);

	addActor(m_red);
	addActor(m_player);
}

Maze::~Maze()
{
	delete m_player;
	delete m_red;
	delete m_green;
	delete m_blue;
	delete m_magenta;
	for (int y = 0; y < m_size.y; y++) {
		for (int x = 0; x < m_size.x; x++) {
			delete m_grid[x][y].actor;
			delete m_grid[x][y].node;
		}
	}
}

void Maze::draw()
{
	//NodeGraph::drawGraph(m_grid[0][0].node);
	Scene::draw();
}

Maze::Tile Maze::getTile(MathLibrary::Vector2 position)
{
	int x = (int)(position.x / TILE_SIZE);
	int y = (int)(position.y / TILE_SIZE);
	if (x >= 0 && x < Maze::WIDTH && y >= 0 && y < Maze::HEIGHT)
		return m_grid[x][y];
	else
		return m_grid[0][0];
}

MathLibrary::Vector2 Maze::getPosition(Tile tile)
{
	return MathLibrary::Vector2{ (float)(tile.x * TILE_SIZE), (float)(tile.y * TILE_SIZE) };
}

void Maze::generate(float grid[Maze::WIDTH][Maze::HEIGHT])
{
	for (int y = 0; y < m_size.y; y++) {
		for (int x = 0; x < m_size.x; x++) {
			// Create the tile
			Tile currentTile{ x, y };
			currentTile.cost = grid[x][y];
			currentTile.node = new NodeGraph::Node();
			currentTile.node->position = { x * TILE_SIZE + (TILE_SIZE / 2.0f), y * TILE_SIZE + (TILE_SIZE / 2.0f) };
			// Designate walls and open spaces
			if (currentTile.cost == 1.0f) {
				currentTile.actor = new Wall(currentTile.node->position.x, currentTile.node->position.y);
				addActor(currentTile.actor);
			}
			// Add node to graph
			if (x > 0) { // west connection
				Tile other = m_grid[x - 1][y];
				currentTile.node->connections.push_back(NodeGraph::Edge{ other.node, other.cost });
				other.node->connections.push_back(NodeGraph::Edge{ currentTile.node, currentTile.cost });
			}
			if (y > 0) { // north connection
				Tile other = m_grid[x][y - 1];
				currentTile.node->connections.push_back(NodeGraph::Edge{ other.node, other.cost });
				other.node->connections.push_back(NodeGraph::Edge{ currentTile.node, currentTile.cost });
			}
			// Set the tile on the grid
			m_grid[x][y] = currentTile;
		}
	}
}
