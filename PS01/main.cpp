// Daniel Barber
//	main.cpp
//
#include <fstream>
#include "Graph.hpp"
#include <iostream>
#include <string>

int main()
{


	Graph N;	
	Graph* newN;

	N.AddVertex('A');
	N.AddVertex('B');
	N.AddVertex('C');
	N.AddVertex('D');
	N.AddVertex('E');
	N.AddVertex('F');
	N.AddVertex('G');


	N.AddEdge('A', 'B', 2);
	N.AddEdge('A', 'C', 3);
	N.AddEdge('A', 'D', 3);
	N.AddEdge('B', 'C', 4);
	N.AddEdge('B', 'E', 3);
	N.AddEdge('C', 'D', 5);
	N.AddEdge('C', 'E', 1);
	N.AddEdge('D', 'F', 7);
	N.AddEdge('E', 'F', 8);
	N.AddEdge('F', 'G', 9);

	cout << "Displaying Graph N's Edges " << endl;
	N.DisplayEdges();

	cout << " -------- - --------- " << endl;

	newN = N.PrimMST();

	cout << "Displaying Graph newN's Edges " << endl;
	newN->DisplayEdges();
	
	newN->ToGraphviz();
	

	return 0;
}
