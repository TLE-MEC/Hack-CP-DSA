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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       // first of all, count the number of elements present in the Linked List 

       // for that, we create a pointer "tmp" that we will use to traverse the linked list
        ListNode* tmp=head;
        // let, n will store the number of elements in the linked list (start with count of elements as 0 i.e. n=0)
        int n=0;
        // keep updating your pointer till you encounter "NULL(as NULL marks the end of linked-list)"
        while(tmp!=NULL){
            n++;
            tmp=tmp->next;
        }
        
        // now, create a vector that we will return finally as output
        vector<ListNode*> ans;
        // again point that temporary pointer to head of the linked list
        tmp=head;
        // if number of elements in the linked list are less than or equal to the number of partitions,
         // then , we will insert "n" linked lists of single elements in our output vector and remaining "k-n" linked lists will be "NULL"
        if(n<=k){
            for(int i=0;i<n;i++){
                ans.push_back(tmp);
                tmp=tmp->next;  
                ans.back()->next=NULL;
            }
            for(int i=n;i<k;i++)ans.push_back(NULL);
        }
        // otherwise, if number of elements in the linked list are greater than the number of partitions,
        // then we will first get maximum size of equal sets, that we can partition our linked list into (here, we are storing that in variable "s")
        // and, we will also keep record of remaining elements that will not form a complete set of that maximum size(here, we are storing that in variable "r")
        else{
            int s=n/k;
            int r=n%k;
            // now, we need a pointer to the previous element, so that, we can make tail->next of a linked list as NULL
            ListNode* pr;
            // also, first r linked lists will have one extra element than the remaining
            for(int j=0;j<r;j++){
                ans.push_back(tmp);
                for(int i=0;i<=s;i++){
                    pr=tmp;
                    tmp=tmp->next;
                }
                pr->next=NULL;
            }
            // remaining linked lists will have exactly s elements
            for(int i=r;i<k;i++){
                ans.push_back(tmp);
                for(int i=0;i<s;i++){
                    pr=tmp;
                    tmp=tmp->next;
                }
                pr->next=NULL;
            }
        }
        // finally, return the "ans" vector (that contains the desired output)
        return ans;
    }
};