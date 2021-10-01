/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//we will use Floyd's algorithm(also known as tortoise and hare algorithm) for solving this problem.
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow=head;//this will be the slow pointer which will move one node at a time
        ListNode *fast=head;//this will be the fast pointer which will move two nodes at a time
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        //when the above loop terminates, the slow pointer will be at the desired middle node of the linked list. Hence we simply return the slow pointer.
        return slow;
    }
};
