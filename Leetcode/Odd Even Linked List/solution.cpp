// The idea is to create two lists, one even and one odd using the original list's nodes. Head remains the same at the end.
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even;
        // Adding even index to even and odd index to odd list
        while (even != nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }
        // Combining the odd and even linked lists.
        odd->next = evenHead;
        return head;
    }
};