
#include <fstream>
#include "Graph.hpp"
#include <iostream>
#include <string>

int main()
{

	Graph g;
	
	g.AddToGraph("Node1");
	g.AddToGraph("Node2");
	g.AddToGraph("Node3");
	g.AddToGraph("Node4");
	g.AddToGraph("Node5");
	g.AddToGraph("Node6");
	g.AddToGraph("Node7");
	g.AddToGraph("Node8");

	// Bipartite graph
	g.LinkNodes("Node1", "Node6");
	g.LinkNodes("Node1", "Node7");
	g.LinkNodes("Node1", "Node8");
	g.LinkNodes("Node2", "Node6");
	g.LinkNodes("Node2", "Node7");
	g.LinkNodes("Node2", "Node8");
	g.LinkNodes("Node3", "Node6");
	g.LinkNodes("Node3", "Node7");
	g.LinkNodes("Node3", "Node8");

	if (g.BipartiteCheck())
		cout << "Yes here" << endl;

	return 0;
}