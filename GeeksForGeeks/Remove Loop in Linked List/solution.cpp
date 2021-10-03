/*
    Intuition:-

    - For this problem, we'll use the Floyd's Tortoise and Hare Algorithm to detect a loop in the linked list
    - After detecting the loop, we'll find the point of intersection of the loop.
    - We'll remove the loop by eliminating the point of intersection and making it NULL.

    Tortoise and Hare Algorithm:-
    - We'll have a slow pointer ie. tortoise and a fast pointer ie. hare
    - The slow pointer will traverse a single node at a time, while the fast pointer traverses two nodes at a time.
    - If a there is no loop in the linked-list, the fast pointer will reach the end of the list
    - If there is a loop in the linked-list, the fast pointer will loop back and reach the slow pointer
        If it reaches the tortoise, we'll simply find the intersection point by traversing the linked-list from the start and current point
        one step at a time until we reach the intersection 
*/

class Solution
{
    public:
    void removeLoop(Node* head)
    {
        // some corner cases to avoid segmentation fault
        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return;
            
        Node* tortoise = head->next;    // slow pointer
        Node* hare = head->next->next;  // fast pointer
        
        bool detected = false;  // it will become true when tortoise and hare meet
        
        // we will run the loop, both for tortoise and hare meeting as well as intersection point detection
        while(hare!=NULL && hare->next!=NULL)
        {
            if(tortoise == hare && !detected)   // tortoise and hare FIRST meet
                hare = head, detected = true;
            if(tortoise == hare && detected)    // tortoise and hare SECOND meet at intersection point
                break;
                
            tortoise = tortoise->next;
            if(!detected)
                hare = hare->next->next;    // hare will moves two steps till FIRST meet
            else
                hare = hare->next;  // hare will move only one step after FIRST meet until SECOND meet
        }
        
        // if no loop is present
        if(hare==NULL || hare->next==NULL)
            return;
        
        Node* mark = hare;  // marking the intersection point

        // eliminating the loop
        Node* p = mark;
        while(p->next != mark)
            p = p->next;
        p->next = NULL;
        
        return;
        
    }
};