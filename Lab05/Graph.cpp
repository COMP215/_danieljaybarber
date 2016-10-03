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

void Graph::AddToGraph(std:: string data_)
{
	Node* new_node = new Node();

	new_node->data_ = data_;

	new_node->vect_num = array_counter;

	graph_vector.push_back(new_node);

	array_counter++;

	//cout << "Node: " << data_ << " added." << endl;

}

void Graph::LinkNodes(string target_node_a, string target_node_b)
{
	Node* loc_a = new Node();
	Node* loc_b = new Node();
	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{
		Node* temp_node = new Node();

		

		if (temp_node->data_ == target_node_a){
			loc_a = temp_node;
		}
	}
	
	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{
		Node* temp_node2 = new Node();

		temp_node2 = *i;

		if (temp_node2->data_ == target_node_b){
			loc_b = temp_node2;

		}
	}
	
	loc_a->node_vector.push_back(loc_b);	//adds location of b to a's node_vector
	loc_b->node_vector.push_back(loc_a);	//adds location of a to b's node_vector

}

bool Graph::BipartiteCheck()
{

	int counter = 0;
	vector<Node*> temp_vector;

	// Iterating through all nodes in graph
	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{

		// Assigning first node in vector to run tests on it
		if (counter <= 0)
		{
			Node* temp_node0 = new Node();
			temp_node0 = *i;
			temp_vector.push_back(temp_node0);
		}
		else
		{	



			return false
		}


	return true;
}

/*  OLD ONE
bool Graph::BipartiteCheck()
{
	int counter = 0;
	vector<Node*> temp_vector;

	// Iterating through all nodes in graph
	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{
		cout << "Here 0" << endl;
		// Assigning first node in vector
		if (counter <= 0)
		{
			Node* temp_node0 = new Node();
			temp_node0 = *i;
			temp_vector.push_back(temp_node0);
			//cout << "Here 1" << endl;
		}
		else
		{
			Node* temp_node1 = new Node();
			temp_node1 = *i;
			//cout << "Here 2" << endl;
			
			// Iterating through all nodes that 'i' points to
			for (vector<Node*>::iterator i = temp_node1->node_vector.begin(); i != temp_node1->node_vector.end(); ++i)
			{
				Node* temp_node2 = new Node();
				temp_node2 = *i;

				// Iterate through all nodes in temp vect to compare
				for (vector<Node*>::iterator i = temp_vector.begin(); i != temp_vector.end(); ++i)
				{
					Node* temp_vect_node = new Node();
					temp_vect_node = *i;

					if (temp_node2 != temp_vect_node)
					{
						temp_vector.push_back(temp_node2);
					}
					else
					{
						return false;
					}
				}
			}
		}
		
		counter++;
	}

	return true;

}
*/

