
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        
        //intialise previous node pointing to null
        ListNode *prev = nullptr; 

        //run while loop till end of list
        while(head!=nullptr){
            //initialise next node pointing to the node after the current node
            ListNode *next_node = head->next;

            //eg: null->1->2
            
            head->next = prev;
            prev = head;
            head = next_node;

            //2->1->null
        }
        
        return prev;
    }
};