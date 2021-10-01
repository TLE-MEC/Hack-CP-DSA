class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode *res=nullptr;
        
        if(l1==nullptr)
            return l2;
        
        else if(l2==nullptr)
            return l1;
        
        else
        {
            if(l1->val<=l2->val)
            {
                res=l1;
                res->next=mergeTwoLists(l1->next,l2);
            }
            else
            {
                res=l2;
                res->next=mergeTwoLists(l2->next,l1);
            }
        }
        
        return res;
    }
};