#include <iostream>
#include <stdlib.h>
using namespace std;

class Node
{
public:
	Node();
	int data;		// Holds the data for a node object
	Node* left;		// Pointer for left side (less then)
	Node* right;	// Poniter for right side (greater then)

};

class Tree
{
public:
	Tree();
	void AddToTree(Node*, Node*);
	void FakeAddToTree(int);
	void PrintTree(Node*);
	void FakePrintTree();
private:
	Node* head;		// The top of the tree pointer


};

Node::Node()
{
	data = 0;		// ================================
	left = NULL;	// Sets all the values to 0 or null
	right = NULL; 	// ================================
}

Tree::Tree()
{
	head = NULL;	// Sets the head pointer to null 

}

void Tree::AddToTree(Node* new_value, Node *curr)
// Adds a new node to the tree in its respected area
// Using recursion to iterate its way downt the tree
//
{
	if(head == NULL)
	{
		head = new_value;
	}else
	{
		if(new_value->data < curr->data)
			if(curr->left == NULL)
			{
				curr->left = new_value;
			}
			else 
			{
				AddToTree(new_value,curr->left);
			}
		else if( new_value->data > curr ->data)
		{
			if(curr->right == NULL)
			{
				
				curr->right = new_value;
			}
			else
			{
				AddToTree(new_value,curr->right);
			}
		}
	}
}


void Tree::FakeAddToTree(int new_value)
// Needed for recursive
// Gets curr pointer so we don't
// lose our place
{
	Node *new_node= new Node();
	new_node->data = new_value;
	Node *curr= new Node();
	curr = head;
	AddToTree(new_node,curr);


}


void Tree::PrintTree( Node *curr)
// Prints the tree out to 
// the console
//
{	
	if (head == NULL)
		cout << "The tree is empty" << endl;
	else if((curr->left == NULL) and (curr->right == NULL))
		cout << curr->data << endl;
	else
	{
		if (curr->left != NULL)
		{
			PrintTree(curr->left);
			cout << curr->data << endl;
		}else
		{
			cout << curr->data <<endl;
		}
		if(curr->right != NULL)
		{
			PrintTree(curr->right);
		}
	}
}
void Tree::FakePrintTree()
// Needed for recursive
// Gets curr pointer so we don't
// lose our place
{
	Node *curr= new Node();
	curr = head;
	PrintTree(curr);


}

int main()
{
	Tree t;
	t.FakeAddToTree(77);
	t.FakeAddToTree(3);
	t.FakeAddToTree(4);
	t.FakeAddToTree(50);
	t.FakePrintTree();

	return 0;
}


