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
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        for (int i = 0; i < n; i++)
        {
            if (fast->next == NULL) //checking if size of linked list is less than the given value of n
                return head->next;
            fast = fast->next; //traversing nth node from the front
        }
        if (fast == NULL)
            return head->next; //checking if size of linked list is less than the given value of n
        while (fast->next != NULL)
        {
            fast = fast->next; //After reaching kth node from front, incrementing both slow and fast until fast pointer reaches end of list.
            slow = slow->next;
        }

        slow->next = slow->next->next; //slow will be pointing at kth node from the end.

        return head;
    }
};