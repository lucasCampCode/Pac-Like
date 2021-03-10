#include "NodeGraph.h"

std::vector<NodeGraph::Node*> NodeGraph::findPath(Node* start, Node* end)
{
	std::vector<Node*> path;
	path.push_back(start);
	path.push_back(end);
	return path;
}

void NodeGraph::drawNode()
{
}

void NodeGraph::drawGraph()
{
}
