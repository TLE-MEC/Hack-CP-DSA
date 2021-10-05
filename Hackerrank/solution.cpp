// C++ program to merge two sorted linked lists 
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node
{
	public:
	int data;
	Node* next;
};

void MoveNode(Node** destRef, Node** sourceRef);

Node* SortedMerge(Node* a, Node* b)
{

	Node dummy;

	// tail points to the last result node 
	Node* tail = &dummy;

	// so tail->next is the place to add new nodes to results.
	dummy.next = NULL;
	while (1)
	{
		if (a == NULL)
		{
			/* if either list runs out, use the
			other list */
			tail->next = b;
			break;
		}
		else if (b == NULL)
		{
			tail->next = a;
			break;
		}
		if (a->data <= b->data)
			MoveNode(&(tail->next), &a);
		else
			MoveNode(&(tail->next), &b);

		tail = tail->next;
	}
	return(dummy.next);
}

// UTILITY FUNCTIONS

void MoveNode(Node** destRef, Node** sourceRef)
{
	/* the front source node */
	Node* newNode = *sourceRef;
	assert(newNode != NULL);

	/* Advance the source pointer */
	*sourceRef = newNode->next;

	/* Link the old dest off the new node */
	newNode->next = *destRef;

	/* Move dest to point to the new node */
	*destRef = newNode;
}
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
	while (node!=NULL)
	{
		cout<<node->data<<" ";
		node = node->next;
	}
}

//Driven Code
int main()
{
	//empty list(NULL)
	Node* res = NULL;
	Node* a = NULL;
	Node* b = NULL;

//create two linked list
	//Created lists, a: 5->10->15, b: 2->3->20 
	push(&a, 15);
	push(&a, 10);
	push(&a, 5);

	push(&b, 20);
	push(&b, 3);
	push(&b, 2);

	// Remove duplicates from linked list
	res = SortedMerge(a, b);

	cout << "Merged Linked List is: \n";
	printList(res);

	return 0;
}
