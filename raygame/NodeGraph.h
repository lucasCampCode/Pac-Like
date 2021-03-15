#pragma once
#include <Vector2.h>
#include <vector>

namespace NodeGraph
{
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

	std::vector<Node*> findPath(Node* start, Node* end);
	void drawGraph(Node* start);

	void drawNode(Node* node, int color = 0x00000000);
	void drawConnectedNodes(Node* node, std::vector<Node*>* drawnList = nullptr);
};

