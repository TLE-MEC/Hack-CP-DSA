/*
For detecting cycles we can use the fast-slow pointer approach

Fast ptr will be one step faster than slow ptr
So, if at any point they are equal that means there is a cycle

Think of it as 2 athletes continuously running on a track until it ends and one is faster than the other

If the track is a circle then the faster one is sure to meet and 
take over the slower one as there is no end

If the track is straight the faster one will simply complete the race and never meet the slower one
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // NULL check
        if (!head)
            return false;

        ListNode *slow = head, *fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next; // moves faster

            // cycle condition
            if (fast == slow)
                return true;
        }

        return false;
    }
};