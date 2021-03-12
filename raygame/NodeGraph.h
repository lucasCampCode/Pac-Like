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
	void drawGraph(Node* start);

private:

	void drawNode(Node* node, int color = 0x00000000);
	void drawConnectedNodes(Node* node, std::vector<Node*>* drawnList = nullptr);
};

