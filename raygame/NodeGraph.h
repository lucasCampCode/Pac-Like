#pragma once
#include <Vector2.h>
#include <vector>

class NodeGraph
{
public:
	struct Node;

	struct Edge
	{
		Node* target;
		float cost;
	};

	struct Node
	{
		MathLibrary::Vector2 position;

		float gScore;
		Node* previous;

		std::vector<Edge> connections;
	};

public:
	NodeGraph() {}

	std::vector<Node*> findPath(Node* start, Node* end);

	void drawNode();
	void drawGraph();
};

