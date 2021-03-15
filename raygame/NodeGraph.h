#pragma once
#include <Vector2.h>
#include <deque>

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

		std::deque<Edge> connections;
	};

	std::deque<Node*> findPath(Node* start, Node* end);
	void drawGraph(Node* start);

	void drawNode(Node* node, int color = 0x00000000);
	void drawConnectedNodes(Node* node, std::deque<Node*>* drawnList = nullptr);
};

