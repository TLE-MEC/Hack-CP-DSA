
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        
        ListNode *prev = nullptr;
        while(head!=nullptr){
            ListNode *next_node = head->next;
            head->next = prev;
            prev = head;
            head = next_node;
        }
        
        return prev;
    }
};