
#include <fstream>
#include "Graph.hpp"
#include <iostream>
#include <string>

int main()
{

	Graph g;
	
	g.AddToGraph("1", "7");
	g.AddToGraph("2", "1");
	g.AddToGraph("3", "9");

	if (g.BipartiteCheck())
		cout << "The graph is bipartite" << endl;
	else
		cout << "The graph is not bipartite" << endl;
	return 0;
}