/** Approach:First find the center, reverse the second half and combine two lists by apppending one from each. **/


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
class Solution {
public:
    void reorderList(ListNode* head) {
        // finding center
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // reversing of second half
        ListNode* secondlist = slow;
        ListNode* reversed_list = NULL;
        while(secondlist){
            ListNode* temp = secondlist->next;
            secondlist->next = reversed_list;
            reversed_list = secondlist;
            secondlist= temp;
        }
        // combining two lists
        ListNode* second  = reversed_list;
        ListNode* first = head;
        ListNode dummy;
        ListNode* output_tail = &dummy, * output_head = &dummy;
        while(second && first != second){
            // appending one elements from each
             output_tail->next = first;

            ListNode *temp = first->next;

            first->next = NULL;

            first = temp;

            output_tail = output_tail->next;
            
            // append from reverse
            output_tail->next = second;

             temp = second->next;

            second->next = NULL;

            second = temp;

            output_tail = output_tail->next;
            
        }
        if(second){
            
             output_tail->next = second;
             second->next = NULL;
            output_tail = output_tail->next;
        }
        head = output_head->next; 
    }
       
};