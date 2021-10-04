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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // as we have to merge all the list to make a final sorted list
        // so, let initially we have our ans list as NULL
        ListNode* ans=NULL;
        // we will also maintain a current pointer that will point to the tail of our current ans list
        ListNode* cp=ans;
        
        // now, create a priority-queue (min-heap) to store first values of each list, and pointer to that node
        // so that we can get node with current shortest value efficiently
        priority_queue< pair<int,ListNode*>, vector< pair<int,ListNode*> >, greater<pair<int,ListNode*> > >pq;
        // initially, push front values of each linked list (that are not NULL) to the priority queue
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
                pq.push({lists[i]->val, lists[i]});
            }
        }
        // now, create a temporary pair of <int,ListNode*> to work with the priority queue 
        pair<int,ListNode*> tmp_p;
        while(!pq.empty()){
            // now, take the top of priority queue in this temporary pair and pop() from priority queue
            tmp_p=pq.top();
            pq.pop();
            // if this node is not the last node of that list, then, push next node of that list to priority queue
            if(tmp_p.second->next!=NULL){
                pq.push({tmp_p.second->next->val,tmp_p.second->next});
            }
            // if current pointer cp==NULL, it means that this is the first value going to be inserted in our final ans list
            // so, make the node that came from top of priority queue as head of our ans list
            if(cp==NULL){
                ans=tmp_p.second;
                cp=ans;
            }
            // otherwise, assign this node to the next of current pointer and update current pointer
            else{
                cp->next=tmp_p.second;
                cp=cp->next;
            }
        }
        // finally, return the head of our "ans" list 
        return ans;
    }
};