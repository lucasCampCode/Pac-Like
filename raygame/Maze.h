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

private:
	MathLibrary::Vector2 m_size = { 28, 31 };
};
