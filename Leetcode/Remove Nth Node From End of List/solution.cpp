
// The function takes the head of a linkedlist and a position n
// The task is to remove the nth node from the end of the list
// We have to return the head of the modified linked list

// Solution logic - O(n) complexity, without previously calculating the length of the list
// 1. Take a dummy node and assign 2 pointers to it
// 2. Take the first pointer to nth position from the beginning
// 3. Now, starting iterating the first pointer till it reaches null and the second pointer from the dummy node
// 4. When the first pointer reaches null, it has traversed (length-n) nodes
// 5. and hence the second pointer reaches the desired node, delete the next node to it
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *d = new ListNode(0, nullptr);
    d->next = head;
    ListNode *p1 = d, *p2 = d;

    while (n--)
    {
        p1 = p1->next;
    }

    if (p1->next == nullptr)
    {
        head = head->next;
        return head;
    }

    while (p1->next != nullptr)
    {
        p2 = p2->next;
        p1 = p1->next;
    }

    ListNode *temp = p2->next;
    p2->next = temp->next;
    delete temp;

    return head;
}
>>>>>>> dfe044e49988d1e51160dbf7aafcf5cf0617b041
