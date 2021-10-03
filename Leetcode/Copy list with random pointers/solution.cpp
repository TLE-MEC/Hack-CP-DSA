/** Approach: Copy the list without the random pointers, Populate the random pointers**/


/*

// Definition for a Node.

class Node {

public:

    int val;

    Node* next;

    Node* random;

    

    Node(int _val) {

        val = _val;

        next = NULL;

        random = NULL;

    }

};

*/

class Solution {

public:

    Node* copyRandomList(Node* head) {

        // Also, populate the history

        unordered_map<Node*, Node*> history;

        Node* curr_old = head;

        Node dummy(-1);

        Node* new_list = &dummy, *prev = &dummy;

        

        while(curr_old) {

            // Allocate memory for the new node

            Node* temp = new Node(curr_old->val);

            // Change the prev node's next pointer to point to this node.

            prev->next = temp;

            // Insert in the map

            history[curr_old] = temp;

            // Update prev

            prev = prev->next;

            // Update curr

            curr_old = curr_old->next;

        }


        curr_old = head;

        Node* curr_new = new_list->next;

        

        while(curr_old) {

            curr_new->random = history[curr_old->random];

            curr_old = curr_old->next;

            curr_new = curr_new->next;

        }

        

        return new_list->next;

    }

};

