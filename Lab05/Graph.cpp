//
//  Graph.cpp
//
//

#include "Graph.hpp"
#include <string>

Node::Node()
{
	data_ = "";
	vect_counter = 0;
	pointer_one = NULL;		
    pointer_two = NULL;
}

Graph::Graph()
{
	array_counter = 0;
}

void Graph::AddToGraph(std::string vector_data, std::string edge_data)
{

	Node* new_vector = new Node();
	Node* new_edge = new Node();

	new_vector->data_ = vector_data;
	new_edge->data_ = edge_data;

	cout << "added new edge: " << new_edge->data_ << endl;
	new_vector->node_vector.push_back(new_edge);

	new_vector->vect_num++;

	cout << "added new vector: " << new_vector->data_ << endl;
	graph_vector.push_back(new_vector);

	array_counter++;

}

bool Graph::BipartiteCheck()
{
	Node *vec_beg;
	vec_beg = graph_vector.begin();
	while(vec_beg != graph_vector.end())
	{
		cout << "here" << endl;
	}


	/*
	for (int i = 0; i < graph_vector.size(); ++i)
	{
		Node* temp_node1 = new Node();
		temp_node1 = graph_vector[i];

		cout << "temp_node1 = " << temp_node1->data_ << endl;		

		for (int j = 0; j < temp_node1->node_vector.size(); ++j)
		{
			Node* temp_node2 = new Node();
			temp_node2 = temp_node1->node_vector[j];

			cout << "temp_node2 = " << temp_node2->data_ << endl;
			
			if (BFS(temp_node2->data_))
				return true;
		}
	}

	return false;
	*/
}

bool Graph::BFS(string x)
{
	for (int i = 0; i < graph_vector.size(); ++i)
	{ 
		Node* temp_node1 = new Node();
		temp_node1 = graph_vector[i];

		cout << temp_node1->data_ << " comparing " << x << endl;
		if (temp_node1->data_ == x)
		{
			cout << "Returning false in BFS" << endl;
			return false;
		}
	}

	cout << "Returning true from BFS" << endl;
	return true;

}
