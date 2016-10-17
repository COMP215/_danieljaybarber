//
//  Graph.hpp
//
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    std::string data_;
    int vect_num;
    std::vector<Node*> node_vector;
    int vect_counter;
    Node* pointer_one;		
    Node* pointer_two;		
    
public:
    Node();

};

class Graph {

public:
	Graph();
	std::vector<Node*> graph_vector;
	int array_counter;
	void AddToGraph(string vector_data, string edge_data);
	void LinkNodes(string target_node_a, string target_node_b);
	bool BipartiteCheck();
	bool BFS(string data);
	
};

#endif /* graph_hpp */
