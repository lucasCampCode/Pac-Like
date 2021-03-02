#pragma once
#include "Scene.h"
#include "Wall.h"
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
		int x, y;
	};

public:
	Maze();

	/// <summary>
	/// Get the size of the maze.
	/// </summary>
	/// <returns>a Vector2 storing the maze's width and height</returns>
	MathLibrary::Vector2 getSize() { return m_size; }

	/// <summary>
	/// Generate a new grid of Walls.
	/// </summary>
	void generate();

public:
	static const int WIDTH = 28;
	static const int HEIGHT = 31;
	static const int TILE_SIZE = 32;

private:
	MathLibrary::Vector2 m_size = { WIDTH, HEIGHT };
	Tile grid[WIDTH][HEIGHT];
};
