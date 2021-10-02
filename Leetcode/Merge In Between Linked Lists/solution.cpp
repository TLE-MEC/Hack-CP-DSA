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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int i=0;
        ListNode *start, *end, *temp=list1;
        while(i<a-1 && temp){ //traverse through the list1 till it reaches a-1
            temp=temp->next;
            i++;
        }
        //now temp is at a-1
        start=temp;
        while(i<b+1 && temp->next!=NULL){ //traverse through the list1 till it reaches b+1
            temp=temp->next;
            i++;
        }
        end=temp;
        start->next=list2;
        while(list2->next != NULL){ //traverse to the end of list2
            list2=list2->next;
        }
        //list2 at last node;
        list2->next=end;
        return list1;
    }
};