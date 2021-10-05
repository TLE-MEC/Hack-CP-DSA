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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *head = new ListNode(); // creating dummy node for returning result
        ListNode *temp = head;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry)
        {
            int sum = 0;
            if (l1 != NULL) //checking if one linked list is fully traversed
            {
                sum = sum + l1->val; //adding each place one at a time to sum
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum = sum + l2->val; //adding the same place as before to sum
                l2 = l2->next;
            }
            sum = sum + carry; //adding if there was any carry left behing
            carry = sum / 10;  //initialising new carry
            ListNode *node = new ListNode(sum % 10);
            temp->next = node;

            temp = temp->next;
        }
        return head->next;
    }
};