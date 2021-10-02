/* C++ program to merge Two Sorted Lists */
#include <bits/stdc++.h>
using namespace std;

/* Link List Node */
class Node
{
public:
	int data;
	Node* next;
};

/* Draw off the fore node of the source and put it in dRef */
void goNode(Node** dRef, Node** sourceRef);

/* Grabs Two Lists Sorted in increasing order, and joins the nodes in conjunction to make a sorted list which is returned. */
Node* sortMerge(Node* a, Node* b)
{
	/* a sample first node to swing the result on */
	Node sample;

	/* end points to the end result node */
	Node* end = &sample;

	/* so end->next is the location to add new nodes to the result. */
	sample.next = NULL;
	while (1)
	{
		if (a == NULL)
		{
			/* if either list runs, use the other list */
			end->next = b;
			break;
		}
		else if (b == NULL)
		{
			end->next = a;
			break;
		}
		if (a->data <= b->data)
			goNode(&(end->next), &a);
		else
			goNode(&(end->next), &b);

		end = end->next;
	}
	return (sample.next);
}

/* Useful Functions */
/* goNode() function takes the node from the anterior of the source,and move it to the anterior of the dRef.It is an fault to call this with the source list null.

Before calling goNode():
source == {1, 2, 3}
dRef == {1, 2, 3}

After calling MoveNode():
source == {2, 3}
dRef == {1, 1, 2, 3} */
void goNode(Node** dRef, Node** sourceRef)
{
	/* the front source node */
	Node* newNode = *sourceRef;
	assert(newNode != NULL);

	/* Move the source pointer */
	*sourceRef = newNode->next;

	/* join the old dRef off the new node */
	newNode->next = *dRef;

	/* Move dRef to point to the new node */
	*dRef = newNode;
}


/* Function to inject a node at the start of the linked list */
void push(Node** head_ref, int new_data)
{
	/* assign node */
	Node* new_node = new Node();

	/* position in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a linked list */
void printList(Node *node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node* res = NULL;
	Node* a = NULL;
	Node* b = NULL;

	/* Let us generate Two Sorted linked lists to examine the functions
	Created lists, a: 2->3->9, b: 1->5->70 */
	push(&a, 2);
	push(&a, 9);
	push(&a, 3);

	push(&b, 70);
	push(&b, 5);
	push(&b, 1);

	/* Remove duplicates from linked list */
	res = sortMerge(a, b);

	cout << "Merged Linked List is: ";
	printList(res);

	return 0;
}
