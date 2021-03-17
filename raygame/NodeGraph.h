#pragma once
#include <Vector2.h>
#include <deque>
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

	std::deque<Node*> findPath(Node* start, Node* end);
	void drawGraph(Node* start);

	void drawNode(Node* node, int color = 0xFFFFFFFF);
	void drawConnectedNodes(Node* node, std::deque<Node*>* drawnList = nullptr);
};

