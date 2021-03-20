#pragma once
#include "Scene.h"
#include "NodeGraph.h"
#include "Wall.h"
#include "Pac.h"
#include "Ghost.h"
#include <Vector2.h>

/// <summary>
/// A Scene that generates a grid of Walls.
/// </summary>
class Maze : public Scene
{
public:
	/// <summary>
	/// A single space in a Maze.
	/// </summary>
	struct Tile {
		int x;
		int y;
		float cost = 1.0f;
		Actor* actor = nullptr;
		NodeGraph::Node* node = nullptr;
	};

	static const int WIDTH = 28;
	static const int HEIGHT = 31;
	static const int TILE_SIZE = 32;

public:
	Maze(float map[Maze::WIDTH][Maze::HEIGHT]);
	~Maze();

	virtual void draw() override;

	/// <summary>
	/// Get the size of the maze.
	/// </summary>
	/// <returns>a Vector2 storing the maze's width and height</returns>
	MathLibrary::Vector2 getSize() { return m_size; }

	/// <summary>
	/// Get the tile data at the given position.
	/// </summary>
	/// <param name="position">The position to check</param>
	/// <returns>A Tile with the data at the position</returns>
	Tile getTile(MathLibrary::Vector2 position);

	/// <summary>
	/// Get the position of the given tile.
	/// </summary>
	/// <param name="tile">The tile to check</param>
	/// <returns>A Vector2 with the position of the tile</returns>
	MathLibrary::Vector2 getPosition(Tile tile);

private:
	/// <summary>
	/// Generate a new grid of Walls.
	/// </summary>
	void generate(float grid[Maze::WIDTH][Maze::HEIGHT]);

private:
	MathLibrary::Vector2 m_size = { WIDTH, HEIGHT };
	Tile m_grid[WIDTH][HEIGHT];

	Pac* m_player;
	Ghost* m_red;
	Ghost* m_green;
	Ghost* m_blue;
	Ghost* m_magenta;
};
