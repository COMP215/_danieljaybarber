// Daniel Barber
//  Graph.cpp
//

#include "Graph.hpp"
#include <string>
#include <algorithm>

Node::Node()
{
}

Edge::Edge()
{
}

Edge::Edge( Node* A, Node* B )
{
	weight = 0;
	vertA_loc = A;
	vertB_loc = B;
	vertA = vertA_loc->vertex;
	vertB = vertB_loc->vertex;
	
}	

Edge::Edge( Node* A, Node* B, int weight_value_passed )
{
	weight = weight_value_passed;
	vertA_loc = A;
	vertB_loc = B;
	vertA = vertA_loc->vertex;
	vertB = vertB_loc->vertex;	
}	

Graph::Graph()
{

}

void Graph::AddVertex(char vertex)
// Adds a vertex to a graph
// Takes in a char for the vertex as an argument
// Does not return anything, the graph object has a new vertex added to its graph_vertex vector
{
	Node* new_node = new Node();

	// Eventually need a way to check if vertex already exists
	new_node->vertex = vertex;

	graph_vector.push_back(new_node);

}

void Graph::LinkNodes(char target_node_a, char target_node_b)
// Links two nodes toegther on the graph
// Takes in two chars, each representing Nodes
// Does not return anything, it adds two new entries the the graphs node vector
{
	
	Node* loc_a;			// A Node pointer to hold location of target node a
	Node* loc_b;			// A Node pointer to hold location of target node b
	Node* temp_node;		// A Node pointer to use in the first for loop
	Node* temp_node2;		// A Node pointer to use in the second for loop
	
	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{
		temp_node = *i;
		if (temp_node->vertex == target_node_a){
			loc_a = temp_node;
		}
	}
	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{
		temp_node2 = *i;
		if (temp_node2->vertex == target_node_b){
			loc_b = temp_node2;
		}
	}
	loc_a->node_vector.push_back(loc_b);	//adds location of b to a's node_vector
	loc_b->node_vector.push_back(loc_a);	//adds location of a to b's node_vector
}

void Graph::isLinkedWith(char base_node_vertex)
// Checks to see what a Node is linked
// Takes in a char as an argument, the char is the Node you are checking to see what is linked to it
// Does not return anything back to the user
{
	Node* base_node = NULL;
	Node* temp_node = new Node();
	
	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{
		temp_node = *i; // here, i represents the value stored at location i in the vector
		if (temp_node->vertex == base_node_vertex){
			base_node = temp_node;
			cout << "found the node you wanted! Was it " << base_node->vertex << "?" << endl;
		}
	}
	cout << base_node->vertex << " is connected to: ";

	for (vector<Node*>::iterator i = base_node->node_vector.begin(); i != base_node->node_vector.end(); ++i)
	{
		temp_node = *i;
		cout << temp_node->vertex << " ";
	}
	cout << endl;
}

void Graph::AddEdge(char source, char target)
// Adds an edge to the graph without a weight
// Takes in two chars.  The two chars are for the source node and the target node
// Does not return anything back to the user
{
	Node* loc_a;			// A Node pointer to hold location of target node a
	Node* loc_b;			// A Node pointer to hold location of target node b
	Node* temp_node;		// A Node pointer to use in the first for loop
	Node* temp_node2;		// A Node pointer to use in the second for loop
	Edge* new_edge_loc;		// An Edge pointer used to create a new edge to push to the master list

	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{
		temp_node = *i;
		if (temp_node->vertex == source){
			loc_a = temp_node;
		}
	}
	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{
		temp_node2 = *i;
		if (temp_node2->vertex == target){
			loc_b = temp_node2;
		}
	}
	new_edge_loc = new Edge(loc_a, loc_b);
	master_edge_list.push_back(new_edge_loc);
}

void Graph::AddEdge(char source, char target, int weight)
// Adds a new edge to the graph with a weight
// Takes in two chars, and an int.  The two chars are for the source node and the target node and the int is for their weight
// Does not return anything back to the user
{
	Node* loc_a;			// A Node pointer to hold location of target node a
	Node* loc_b;			// A Node pointer to hold location of target node b
	Node* temp_node;		// A Node pointer to use in the first for loop
	Node* temp_node2;		// A Node pointer to use in the second for loop
	Edge* new_edge_loc;		// An Edge pointer used to create a new edge to push to the master list

	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{
		temp_node = *i;
		if (temp_node->vertex == source){
			loc_a = temp_node;
		}
	}
	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{
		temp_node2 = *i;
		if (temp_node2->vertex == target){
			loc_b = temp_node2;
		}
	}
	new_edge_loc = new Edge(loc_a, loc_b, weight);
	master_edge_list.push_back(new_edge_loc);

}

void Graph::ToGraphviz()
// Reads in a graph and prints out the graph into a DOT file used to visualize the graph
// Needs a graph object for this method to be called, does not take anything in as an argument
// Creates a new DOT file in the same directory as this program is in.
{
	Edge* temp_edge;		// An Edge pointer used in the for loop
	ofstream file_write;	// A file stream used to write to a new file

	file_write.open("newGraph.dot");
	
	for (vector<Edge*>::iterator i = master_edge_list.begin(); i != master_edge_list.end(); ++i)
	{
		temp_edge = *i;

		file_write << temp_edge->vertA << " -> " << temp_edge->vertB << " -- " << temp_edge->weight << endl;

	}
	file_write.close();

	cout << "Just made a new DOT file named: newGraph.dot" << endl;
}

Graph* Graph::PrimMST(void)
// Runs Prims' algoritm on a graph. 
// A graph object is needed to be able to call this method
// Returns the new graph (based off of Prims' algorithm) back to the user in main.
{
	Graph* newGraph;						// A new graph pointer to return a graph back to main
	Node* startPos = graph_vector.at(0);	// A Node pointer containing the first node in the start of the graph vector
	vector<Edge*> official_moves;			// A new vector of type Edge pointers used to store offical moves availible
	vector<Edge*> potential_moves;			// A new vector of type Edge pointers used to store potential moves availible
	vector<Node*> visited_vertices;			// A new vector of type Edge pointers used to store visted vertices
	Edge* temp_edge;						// An Edge pointer used in a for loop to store the curernt edge your on
	Edge* temp_edge2;						// An Edge pointer used in a for loop to store the curernt edge your on
	Node* temp_node;						// A Node pointer used in a for loop to store the curernt edge your on
	Node* temp_node2;						// A Node pointer used in a for loop to store the curernt edge your on
	int temp_counter = 0;					// A counter needed to erase potentional moves for duplicates
	
	visited_vertices.push_back(startPos);
	
	for (vector<Edge*>::iterator i = master_edge_list.begin(); i != master_edge_list.end(); ++i)
	{
		temp_edge = *i;
		//If the node you wanted was in A position of an edge
		if (temp_edge->vertA_loc == startPos) { 
			potential_moves.push_back(temp_edge);
		}
		//If the node you wanted was in B position of an edge
		else if (temp_edge->vertB_loc == startPos) { 
			potential_moves.push_back(temp_edge);
		}
	}
	
	Edge* smallest_edge;
	if (!potential_moves.empty()){
		smallest_edge = potential_moves.at(0);
		for (vector<Edge*>::iterator i = potential_moves.begin(); i != potential_moves.end(); ++i)
		{
			temp_edge = *i;
			if (temp_edge->weight < smallest_edge->weight) { 
				smallest_edge = temp_edge; 
			}
		}
		official_moves.push_back(smallest_edge);
		
		if (find(visited_vertices.begin(), visited_vertices.end(), smallest_edge->vertA_loc) != visited_vertices.end()) 
			visited_vertices.push_back(smallest_edge->vertB_loc); 
		else 
			visited_vertices.push_back(smallest_edge->vertA_loc); 

		while (visited_vertices.size() < graph_vector.size())
		{
			potential_moves.clear();

			//Update Potential Moves
			for (vector<Node*>::iterator i = visited_vertices.begin(); i != visited_vertices.end(); ++i)
			{ 
				temp_node = *i;
				for (vector<Edge*>::iterator j = master_edge_list.begin(); j != master_edge_list.end(); ++j)
				{
					temp_edge = *j;
					if (temp_edge->vertA_loc == temp_node) {
						if (find(visited_vertices.begin(), visited_vertices.end(), temp_edge->vertB_loc) != visited_vertices.end()) {
						}
						else
							potential_moves.push_back(temp_edge);
					}
					else if (temp_edge->vertB_loc == temp_node) {
						if (find(visited_vertices.begin(), visited_vertices.end(), temp_edge->vertA_loc) != visited_vertices.end()) {
						}
						else
							potential_moves.push_back(temp_edge);
					}
				}
			}
						
			//Remove redundancies from Potential Moves
			for (vector<Edge*>::iterator i = official_moves.begin(); i != official_moves.end(); ++i)
			{
				temp_edge = *i;

				for (vector<Edge*>::iterator j = potential_moves.begin(); j != potential_moves.end(); ++j)
				{
					temp_edge2 = *j;

					if (temp_edge == temp_edge2){
						potential_moves.erase(potential_moves.begin() + temp_counter);
					}
					temp_counter++;
				}

				temp_counter=0;
			}


			for (vector<Edge*>::iterator i = potential_moves.begin(); i != potential_moves.end(); ++i)
			{
				temp_edge = *i;
			}


			smallest_edge = potential_moves.at(0);
			for (vector<Edge*>::iterator i = potential_moves.begin(); i != potential_moves.end(); ++i)
			{
				temp_edge = *i;
				if (temp_edge->weight < smallest_edge->weight) { 
					smallest_edge = temp_edge; 
				}
			}

			official_moves.push_back(smallest_edge);

			if (find(visited_vertices.begin(), visited_vertices.end(), smallest_edge->vertA_loc) != visited_vertices.end()) { 
				visited_vertices.push_back(smallest_edge->vertB_loc); 
			}
			else {
				visited_vertices.push_back(smallest_edge->vertA_loc); 
			}
		}	
	}
	
	newGraph = new Graph();
	for (vector<Node*>::iterator i = visited_vertices.begin(); i != visited_vertices.end(); ++i)
	{
		temp_node = *i;
		newGraph->AddVertex(temp_node->vertex);
	}

	for (vector<Edge*>::iterator i = official_moves.begin(); i != official_moves.end(); ++i)
	{
		temp_edge = *i;
		newGraph->AddEdge(temp_edge->vertA, temp_edge->vertB, temp_edge->weight);
	}

	return newGraph;
}

Graph* Graph::KruskalMST(void)
// !!! ==== NOT WORKING ==== !!!
// Runs Kruskal's algoritm on a graph. 
// A graph object is needed to be able to call this method
// Returns the new graph (based off of Kruskal's algorithm) back to the user in main.
{
	Graph* newGraph;						// A new graph pointer to return a graph back to main
	Node* startPos = graph_vector.at(0);	// A Node pointer containing the first node in the start of the graph vector
	vector<Edge*> official_moves;			// A new vector of type Edge pointers used to store offical moves availible
	vector<Edge*> sorted_edges;				// A new vector of type Edge pointers used to store the sorted edges
	Edge* temp_edge;						// An Edge pointer used in the for loop to iterate through a vector of edges
	Edge* temp_edge2;
	Edge* smallest_edge;					// An Edge pointer used for comparing edges to find the smallest, for sorting
	int counter = 0;

	// Sorting the vector by weight size and storing into a new vector
	for (vector<Edge*>::iterator i = master_edge_list.begin(); i != master_edge_list.end(); ++i)
	{
		temp_edge = *i;
		official_moves.push_back(temp_edge);
	}
	if (!official_moves.empty()){
		while (!official_moves.empty())
		{
			smallest_edge = official_moves.at(0);
			for (vector<Edge*>::iterator i = official_moves.begin(); i != official_moves.end(); ++i)
			{
				temp_edge = *i;
				if (temp_edge->weight < smallest_edge->weight) { 
					smallest_edge = temp_edge; 
				}
			}
			//cout << "OM Size: " << official_moves.size() << endl;
			sorted_edges.push_back(smallest_edge);
			official_moves.erase(find(official_moves.begin(),official_moves.end(),smallest_edge));
			//cout << "PuSHED: " << smallest_edge->vertA << " - " << smallest_edge->vertB << " - " << smallest_edge->weight << endl;	
		} 
	}
	// End of sorting the vector by weight size and pushing to a new vector

	
	while (sorted_edges.size() != 0)
	{
		smallest_edge = sorted_edges.at(0);
		cout << smallest_edge->weight << endl;
		sorted_edges.erase(find(sorted_edges.begin(), sorted_edges.end(), smallest_edge));

	}
	newGraph = new Graph();
	return newGraph;
	

}


void Graph::DisplayEdges(void)
// A method that displays all the edges in the graph with their weights
// It does not take anything in as a input, needs an graph object to be able to be called
// Returns nothing, it prints out the results to the console.
{
	Edge* temp_edge;	// An Edge pointer used in the for loop

	for (vector<Edge*>::iterator i = master_edge_list.begin(); i != master_edge_list.end(); ++i)
	{
		temp_edge = *i;
		cout << "Found Edge: Between " << temp_edge->vertA << " and " << temp_edge->vertB << " --> Weight = " << temp_edge->weight << endl;
	}
}