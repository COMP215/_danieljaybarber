#include <iostream>
#include <stdlib.h>
using namespace std;

class Node
{
public:
	Node();
	string data;	// Holds the data for the node as a string
	Node* next;		// Pointer for the node to find next in list

};

class LinkedList
{
public:
	void Delete_Last();
	void Add_Last(string);
	void PrintOut();
	LinkedList();
private:
	Node* header;	// Head of the linked list
	Node* tail;		// The tail of the linked list

};



LinkedList::LinkedList()
// Constructor for the linked list
// Sets all values to NULL
//
{
	header = NULL;
	tail = NULL;

}
void LinkedList::Add_Last(string new_data)
// Adds a node to the linked list
// Adds the value to the end
//

{
	if(tail != NULL) {
		Node* new_node = new Node();

		new_node->data = new_data;

		tail->next = new_node;
		tail = new_node;

	}else{

		Node* new_node = new Node();
		new_node->data = new_data;
		tail = new_node;
		header = new_node;
	}
}

void LinkedList::PrintOut()
// Prints out the linked list
//
//

{	
	Node *cur;

	cur = header;

	while(cur)
	{
		cout << cur->data << endl;
		cur = cur->next;
	}


}


Node::Node()
// Constructor for the node class
// Sets all values to "" or NULL
//
{
	data = "";
	next = NULL;

}

int main() 
{
	LinkedList l;
	//Node node1;

	l.Add_Last("obj 1");
	l.Add_Last("obj 2");
	l.Add_Last("obj 3");
	l.PrintOut();

	return 0;
}